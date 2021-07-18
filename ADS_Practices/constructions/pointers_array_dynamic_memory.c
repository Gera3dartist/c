#include <stdlib.h>
#define CARD( arr ) (sizeof(arr))/sizeof(*(arr))

typedef struct date_s
{
    short year;
    char month;
    char day;
} DATE_t, * DATE_p_t;


static void sort_dates( DATE_p_t dates, int arr_size );

DATE_t dates[4] = { 
    {1066, 3, 27},
    {1942, 2, 1},
    {1492, 10, 12},
    {1815, 10, 14},
};

void *PROJ_malloc( size_t size ) {
    void *mem = malloc(size);
    if ( mem == NULL && size > 0 )
        abort();
    
    return mem;
}

void *PROJ_realloc( void *ptr, size_t new_size ) {
    void *new_ptr = realloc(ptr, new_size);
    if (new_ptr == NULL && new_size > 0)
        free(ptr);
    return new_ptr;
}

void *PROJ_calloc( size_t num, size_t size ) {
    void *new_ptr = calloc(num, size);
    if (new_ptr == NULL && size > 0)
        abort();
    return new_ptr;
}
