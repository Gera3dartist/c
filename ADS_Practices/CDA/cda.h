#ifndef CDA_H
#define CDA_H

#include <stdio.h>
#include <assert.h>
#include <string.h>
#define CDA_TRUE (1)
#define CDA_FALSE (0)
#define CDA_AFTER (1)
#define CDA_BEFORE (0)

#define CDA_ASSERT(exp)      (assert(exp)) 
#define CDA_CARD(arr)        (sizeof(arr) / sizeof( *( arr )))
#define CDA_NEW(type)        ((type *)CDA_malloc( sizeof(type) ))
#define CDA_NEW_STRING(str) (strcpy( (char *)CDA_malloc(strlen(str) + 1 ), (str)))

#define CDA_NEW_STRING_IF(str)  (str == NULL ? NULL : CDA_NEW_STRING(str))
#define ENQ_GET_HEAD(list)  ((list)->flink)
#define ENQ_GET_TAIL(list)  ((list)->blink)
#define ENQ_GET_NEXT(item)  ((item)->flink)
#define ENQ_GET_PREV(item)  ((item)->blink)
#define ENQ_GET_LIST_NAME(list)  ((const char*))((list)->name)
#define ENQ_GET_ITEM_NAME(item)  ((const char*))((item)->name)

typedef char CDA_BOOL_t;
typedef signed char CDA_INT8_t;
typedef unsigned char CDA_UINT8_t;
typedef signed short CDA_INT16_t;
typedef unsigned short CDA_UINT16_t;
typedef signed long CDA_INT32_t;
typedef unsigned long CDA_UINT32_t;

typedef struct enq_item_s
{
    struct enq_item_s   *flink;
    struct enq_item_s   *blink;
    char                *name;
} ENQ_ITEM_t, *ENQ_ITEM_p_t;

// Anchor is identifier of the list
typedef ENQ_ITEM_t ENQ_ANCHOR_t, *ENQ_ANCHOR_p_t;

ENQ_ANCHOR_p_t ENQ_create_list (const char *name) ;
ENQ_ITEM_p_t   ENQ_create_item(const char *name, size_t size);
CDA_BOOL_t     ENQ_list_is_empty(ENQ_ANCHOR_p_t list);
CDA_BOOL_t     ENQ_is_item_enqed(ENQ_ITEM_p_t item);
ENQ_ITEM_p_t   ENQ_add_head(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item);
ENQ_ITEM_p_t   ENQ_add_tail(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item);
ENQ_ITEM_p_t   ENQ_add_after(ENQ_ITEM_p_t item, ENQ_ITEM_p_t after);
ENQ_ITEM_p_t   ENQ_add_before(ENQ_ITEM_p_t item, ENQ_ITEM_p_t before);
ENQ_ITEM_p_t   ENQ_insert(ENQ_ITEM_p_t item, ENQ_ITEM_p_t insertable, CDA_BOOL_t after) ;
ENQ_ITEM_p_t   ENQ_deq_item(ENQ_ITEM_p_t item);
ENQ_ITEM_p_t   ENQ_deq_head(ENQ_ANCHOR_p_t list);
ENQ_ITEM_p_t   ENQ_deq_tail(ENQ_ANCHOR_p_t list);
ENQ_ITEM_p_t   ENQ_destroy_item(ENQ_ITEM_p_t item);
ENQ_ANCHOR_p_t ENQ_empty_list(ENQ_ANCHOR_p_t list);
ENQ_ANCHOR_p_t ENQ_destroy_list(ENQ_ANCHOR_p_t list);


#endif






















