#define QUE_NULL_ID (NULL)

typedef int ENQ_ITEM_t;  // define type of pointer to control structur
typedef struct que_control_s *QUE_ID_t;  // define type of pointer to control structur

typedef void QUE_DESTROY_PROC_t(void *data);  // header of procedure for removal
typedef QUE_DESTROY_PROC_t *QUE_DESTROY_PROC_p_t;  // poiter to procedure
typedef void QUE_TRAVERSE_PROC_t (void *data);
typedef QUE_TRAVERSE_PROC_t *QUE_TRAVERSE_PROC_p_t;

typedef struct que_item_s 
{
    ENQ_ITEM_t item;
    void *data;
} QUE_ITEM_t, *QUE_ITEM_p_t