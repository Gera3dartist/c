#include "cdap.h"
#include <stdlib.h>
#include <stdio.h>


void *CDA_malloc( size_t size ) {
    void *mem = malloc(size);
    if ( mem == NULL && size > 0 )
        abort();
    
    return mem;
}

void *CDA_realloc( void *ptr, size_t new_size ) {
    void *new_ptr = realloc(ptr, new_size);
    if (new_ptr == NULL && new_size > 0)
        free(ptr);
    return new_ptr;
}

void *CDA_calloc( size_t num, size_t size ) {
    void *new_ptr = calloc(num, size);
    if (new_ptr == NULL && size > 0)
        abort();
    return new_ptr;
}

void CDA_free( void *mem ) {
    if (mem != NULL)
        free(mem);
}


/*
 * Returns: address of the list
 *  
 */
ENQ_ANCHOR_p_t ENQ_create_list (const char *name) 
{
    ENQ_ANCHOR_p_t list = CDA_NEW(ENQ_ANCHOR_t);
    list->blink = list;
    list->flink = list;
    list->name = CDA_NEW_STRING_IF(name);
    return list;

}

/*
 * Synopsis:
 *  ENQ_ITEM_t ENQ_create_item(const char *name, size_t size);
 * Returns: address enqued item
 */
ENQ_ITEM_p_t ENQ_create_item(const char *name, size_t size)
{
    ENQ_ITEM_p_t item = (ENQ_ITEM_p_t)CDA_malloc(size);
    CDA_ASSERT(size >= sizeof(ENQ_ITEM_t));
    item->flink = item;
    item->blink = item;
    item->name = CDA_NEW_STRING_IF(name);
    return item;
}


/*
 * Synopsis:
 *  CDA_BOOL_t ENQ_is_item_enqed(ENQ_ITEM_p_t item)
 * Returns:
 *  0/1 depending if item is enqued
 */
CDA_BOOL_t ENQ_is_item_enqed(ENQ_ITEM_p_t item) {
    CDA_BOOL_t enq_code = item->flink == item ? CDA_FALSE : CDA_TRUE;
    return enq_code;
}

/*
 * Synopsis:
 *  CDA_BOOL_t ENQ_list_is_empty(ENQ_ANCHOR_p_t list);
 * Returns:
 *  0/1 depending if list is empty
 */
CDA_BOOL_t ENQ_list_is_empty(ENQ_ANCHOR_p_t list) {
    CDA_BOOL_t is_empty = (list->flink == list && list->blink == list) ? CDA_FALSE : CDA_TRUE;
    return is_empty;
}


/*
 * Synopsis:
 *  ENQ_ITEM_p_t ENQ_add_head(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item);
 * Returns:
 *  enqued item
 */
ENQ_ITEM_p_t ENQ_add_head(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item)
{
    return ENQ_insert(list, item, CDA_AFTER);
}

/*
 * Synopsis:
 *  ENQ_ITEM_p_t ENQ_add_tail(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item);
 * Returns:
 *  enqued item
 */
ENQ_ITEM_p_t ENQ_add_tail(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item)
{
    return ENQ_insert(list, item, CDA_BEFORE);
}

/*
 * Synopsis:
 *  ENQ_ITEM_p_t ENQ_add_after(ENQ_ITEM_p_t item, ENQ_ITEM_p_t after);
 * Returns:
 *  enqued item
 */
ENQ_ITEM_p_t ENQ_add_after(ENQ_ITEM_p_t item, ENQ_ITEM_p_t after)
{
    return ENQ_insert(item, after, CDA_AFTER);
}

/*
 * Synopsis:
 *  ENQ_ITEM_p_t ENQ_add_before(ENQ_ITEM_p_t item, ENQ_ITEM_p_t before);
 * Returns:
 *  enqued item
 */
ENQ_ITEM_p_t ENQ_add_before(ENQ_ITEM_p_t item, ENQ_ITEM_p_t before)
{
    return ENQ_insert(item, before, CDA_BEFORE);
}

/*
 * Synopsis:
 *  Generic function performing positionioning of two items
 * 
 *  ENQ_ITEM_p_t ENQ_insert(ENQ_ITEM_p_t item, ENQ_ITEM_p_t insertable, CDA_BOOL_t after);
 * Returns:
 *  enqued item
 */
ENQ_ITEM_p_t ENQ_insert(ENQ_ITEM_p_t item, ENQ_ITEM_p_t insertable, CDA_BOOL_t after) 
{
    CDA_ASSERT(!ENQ_is_item_enqed(insertable));
    
    ENQ_ANCHOR_p_t temp = after ? item->flink : item->blink;
    // manage links of insertable
    insertable->blink = after ? item : temp;
    insertable->flink = after ? temp : item;

    if (after) {
        temp->blink = insertable;
        item->flink = insertable;
    } else {
        temp->flink = insertable;
        item->blink = insertable;
    }
    return insertable;
}


/*
 * Synopsis:
 *  ENQ_ITEM_p_t ENQ_deq_item(ENQ_ITEM_p_t item);
 * Returns:
 *  enqued item
 */
ENQ_ITEM_p_t ENQ_deq_item(ENQ_ITEM_p_t item)
{
    item->flink->blink = item->blink;
    item->blink->flink = item->flink;
    item->flink = item;
    item->blink = item;
    return item;
}

/*
 * Synopsis:
 *  ENQ_ITEM_p_t ENQ_deq_head(ENQ_ANCHOR_p_t list);
 * Returns:
 *  enqued item
 */
ENQ_ITEM_p_t ENQ_deq_head(ENQ_ANCHOR_p_t list)
{
    if (ENQ_list_is_empty(list))
        return list;
    return ENQ_deq_item(list->flink);
}

/*
 * Synopsis:
 *  ENQ_ITEM_p_t ENQ_deq_tail(ENQ_ANCHOR_p_t list);
 * Returns:
 *  enqued item
 */
ENQ_ITEM_p_t ENQ_deq_tail(ENQ_ANCHOR_p_t list)
{
    if (ENQ_list_is_empty(list))
        return list;
    return ENQ_deq_item(list->blink);
}

/*
 * Synopsis:
 *  ENQ_ITEM_p_t ENQ_destroy_tail(ENQ_ITEM_p_t item)
 * Returns:
 *  enqued item
 */
ENQ_ITEM_p_t ENQ_destroy_item(ENQ_ITEM_p_t item)
{
    ENQ_deq_item( item );
    CDA_free( item->name );
    CDA_free( item );
    return NULL;
}

/*
 * Synopsis:
 * ENQ_ANCHOR_p_t ENQ_empty_list(ENQ_ANCHOR_p_t list)
 * Returns:
 *  empty list
 */
ENQ_ANCHOR_p_t ENQ_empty_list(ENQ_ANCHOR_p_t list)
{
    while( !ENQ_list_is_empty(list) )
        ENQ_destroy_item( list->flink );
    return list;
}


/*
 * Synopsis:
 * ENQ_ANCHOR_p_t ENQ_destroy_list(ENQ_ANCHOR_p_t list)
 * Returns:
 *  empty list
 */
ENQ_ANCHOR_p_t ENQ_destroy_list(ENQ_ANCHOR_p_t list)
{
    ENQ_empty_list(list);
    CDA_free( list->name );
    CDA_free( list );
    return NULL;

}