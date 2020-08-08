/**
 * @file GQueue_thread_competition.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Producer consumer problem where 2 threads compete to consume and add the most numbers
 *        the one with maximum wins
 * @version 0.1
 * @date 2020-08-04
 * 
 * @copyright Copyright (c) 2020 Aashish Patel
 * 
 */
#include <glib.h>
#include <gmodule.h>

/**
 * @brief type to hold queue state
 * 
 */
typedef struct {
  GQueue *q;
  GCond   q_cond;
  GMutex  q_lock;
  gboolean is_stop;
} QueueState;

/**
 * @brief Destroys queue elements
 * 
 * @param data, element to be destroyed
 */
void destroy_elements (gpointer data)
{
  guint *n = (guint *)data;
  g_free (n);
}

/**
 * @brief worker thread for adding queue elements
 * 
 * @param data, queue state
 * @return gpointer, sum of the elements processed
 */
gpointer worker_thread (gpointer data)
{
  QueueState *qs = (QueueState *)data;
  guint *sum = NULL;
  guint *n = NULL;
  GThread *self = g_thread_self ();
  gboolean is_empty = FALSE;
  if (qs == NULL)
  {
    g_print ("Invalid data passed!\n");
    return NULL;
  }

  sum = g_new0 (guint, 1);
  
  while (TRUE)
  {
    g_mutex_lock(&qs->q_lock);
    is_empty = g_queue_is_empty(qs->q);
    while (is_empty && !qs->is_stop)
    {
      g_print ("\n%p: waiting!! \n", self );
      g_cond_wait(&qs->q_cond, &qs->q_lock);
      is_empty = g_queue_is_empty(qs->q);
    }
    if (is_empty && qs->is_stop) {
      g_print ("\n%p: exiting\n", self);
      g_mutex_unlock(&qs->q_lock);
      break;
    }
    n = (guint *)g_queue_pop_tail (qs->q);
    g_mutex_unlock(&qs->q_lock);
    g_print ("\n%p: DQ-> %u \n", self, *n);
    *sum += *n;
  }
  
  return (gpointer)sum;
}

int main(int argc, char const *argv[])
{
  guint count = 0;
  guint i = 0, *n = NULL;
  GThread* tptr[2] = {NULL, NULL};
  QueueState *qs = NULL;
  guint *ts1_ptr, *ts2_ptr;

  if (argc != 2)
  {
    g_print ("Inavalid number of arguments specified\n");
    g_print("Usage: ./GQueue_thread_competition <num of integers to add>\n");
    return -1;
  }

  qs = g_new0(QueueState, 1);
  qs->q = g_queue_new ();
  qs->is_stop = FALSE;
  GRand *rand = g_rand_new ();
  count = atoi(argv[1]);

  g_mutex_init (&(qs->q_lock));
  g_cond_init (&(qs->q_cond));
  tptr[0] = g_thread_new("Thread 1", worker_thread, (gpointer)qs);
  tptr[1] = g_thread_new("Thread 2", worker_thread, (gpointer)qs);

  g_print ("Total %u numbers will be produced\n", count);
  for (i = 0; i < count; i++)
  {
    n = g_new0(guint, 1);
    *n = g_rand_int_range(rand, 1, count);
    g_mutex_lock (&(qs->q_lock));
    g_queue_push_head (qs->q, (gpointer)n);
    g_print ("\nPushed %u\n", *n);
    if (i == count-1)
    {
      qs->is_stop = TRUE;
    }
    g_cond_broadcast (&(qs->q_cond));
    g_mutex_unlock (&(qs->q_lock));
  }

  //g_queue_foreach (qs->q, print_queue, "->");
  ts1_ptr = (guint *)g_thread_join (tptr[0]);
  ts2_ptr = (guint *)g_thread_join (tptr[1]);
  if (*ts1_ptr > *ts2_ptr)
  {
    g_print ("Thread 1 wins with value %u over Thread 2 value %u!!!\n",
      *ts1_ptr, *ts2_ptr);
  } else if (*ts1_ptr < *ts2_ptr)
  {
    g_print ("Thread 2 wins with value %u over Thread 1 value %u!!!\n",
      *ts2_ptr, *ts1_ptr);
  } else {
      g_print ("Its is a tie with value %u!!!\n", *ts1_ptr);
  }

  g_queue_free_full (qs->q, (GDestroyNotify)destroy_elements);
  g_rand_free (rand);
  g_mutex_clear (&(qs->q_lock));
  g_cond_clear (&(qs->q_cond));
  g_free (qs);
  g_free (ts1_ptr);
  g_free (ts2_ptr);
  return 0;
}
