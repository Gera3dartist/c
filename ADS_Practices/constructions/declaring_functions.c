// typede allows to simplify function declaration and make them more readable

// this
void (*signal(
    int sig,
    void (*func)(int))
) (int);

// converts to this

typedef void SIG_PROC_t( int );
typedef SIG_PROC_t *SIG_PROC_t_p;

SIG_PROC_t_p signal(
    int         sig,
    SIG_PROC_t  func
);


// and this
static int is_greater_equal(
    const void *item1,
    const void *item2
);

typedef struct sort_data_s
{
    int *sort_array;
    int (*test_proc) ( const void *item1, const void *item2 );
} SORT_DATA_t, *SORT_DATA_p_t;

// converts to this

typedef int COMPARE_PROC_t (const void *, const void *); // const void * - ignore arg name
typedef COMPARE_PROC_t *COMPARE_PROC_t_p;

typedef struct sort_data_s
{
    int *sort_array;
    COMPARE_PROC_t_p test_proc;
} SORT_DATA_t, *SORT_DATA_p_t;