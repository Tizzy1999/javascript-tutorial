/* Thread Structure */
struct rt_thread
{
    /* rt object */
    char        name[RT_NAME_MAX];     /* the name of thread */
    rt_uint8_t  type;                   /* type of object */
    rt_uint8_t  flags;                  /* thread's flas */

    rt_list_t   list;                   /* the object list */
    rt_list_t   tlist;                  /* the thread list */
/* stack point and entry */
    void       *sp;                     /**< stack point */
    void       *entry;                  /**< entry */
    void       *parameter;              /**< parameter */
    void       *stack_addr;             /**< stack address */
    rt_uint32_t stack_size;             /**< stack size */
/* error code */
    rt_err_t    error;                   /**< error code */
    rt_uint8_t  stat;                    /**< thread status */
/* priority */
    rt_uint8_t  current_priority;        /**< current priority */
    rt_uint8_t  init_priority;           /**< initialized priority */
    rt_uint32_t number_mask;

    ......

    rt_ubase_t  init_tick;                    /**< thread's initialized tick */
    rt_ubase_t  remaining_tick;               /**< remaining tick */
    struct rt_timer thread_timer;             /**< built-in thread timer */
    void (*cleanup)(struct rt_thread *tid);    /**< cleanup function when thread exit */
    rt_uint32_t user_data;                     /**< private user data beyond this thread */
};


rt_err_t rt_thread_idle_sethook(void (*hook)(void));
rt_err_t rt_thread_idle_delhook(void (*hook)(void));

#include <rtthread.h>

#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       512
#define THREAD_TIMESLICE        5

static rt_thread_t tid1 = RT_NULL;

/* Thread 1 entry function */
static void thread1_entry(void *parameter)
{
    rt_uint32_t count = 0;
    while (1)
    {
        /* Thread 1 has low priority, continuing printing count */
        rt_kprintf("thread1 count: %d\n", count ++);
        rt_thread_mdelay(500);
    }
}

ALIGN(RT_ALIGN_SIZE)
static char thread2_stack[1024];
static struct rt_thread thread2;
/* Thread 2 entry function */
static void thread2_entry(void *param)
{
    rt_uint32_t count = 0;
    /* Thread 2 has higher priority, preempts thread 1 for execution */
    for (count = 0; count < 10 ; count++)
    {
        /* Threas 2 printing count */
        rt_kprintf("thread2 count: %d\n", count);
    }
    rt_kprintf("thread2 exit\n");
}

/* Threas Example */
int thread_sample(void)
{
    /* Creating Thread 1，with entry function as thread1_entry*/
    tid1 = rt_thread_create("thread1",
                            thread1_entry, RT_NULL,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);

    /* activate the thread when the thread 如果获得线程控制块，启动这个线程 */
    if (tid1 != RT_NULL)
        rt_thread_startup(tid1);

    /* Creating Thread 2，with entry function as thread2_entry */
    rt_thread_init(&thread2,
                   "thread2",
                   thread2_entry,
                   RT_NULL,
                   &thread2_stack[0],
                   sizeof(thread2_stack),
                   THREAD_PRIORITY - 1, THREAD_TIMESLICE);
    rt_thread_startup(&thread2);

    return 0;
}

MSH_CMD_EXPORT(thread_sample, thread sample);
