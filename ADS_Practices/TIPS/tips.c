#include <stdlib.h>
#include <stdio.h>

#include "/Users/andriigerasymchuk/private-repositories/c/ADS_Practices/CDA/cda.h"
#include "tipsp.h"

#define NOT_FOUND     (0)
#define FOUND_EXACT   (1)
#define FOUND_GREATER (2)

typedef struct receipt_s {
    ENQ_ITEM_p_t item;
    double check_total;
    double tip_total;
    int num_receipts;
} RECEIPTS_t, *RECEIPTS_p_t;

static const char *tipListName = "Tip queue";

static ENQ_ANCHOR_p_t anchor = NULL;

void TIPS_init( void ) 
{
    CDA_ASSERT( anchor == NULL );
    anchor = ENQ_create_list(tipListName);
}


void TIPS_add_receipt( const char *wait_person, double check, double tip )
{
    RECEIPTS_p_t receipts = NULL;
    RECEIPTS_p_t bucket = NULL;
    int result = NOT_FOUND;
    int compare = 0;

    CDA_ASSERT(anchor != NULL);
    receipts = ENQ_GET_HEAD((ENQ_ANCHOR_p_t)anchor);
    while (result == NOT_FOUND && (RECEIPTS_p_t)receipts != anchor) {
        compare = strcmp(wait_person, ENQ_GET_ITEM_NAME((ENQ_ITEM_p_t)receipts));
        if (compare == 0) 
            result = FOUND_EXACT;
        else if (compare < 0) 
            result = FOUND_GREATER;
        else
            receipts = (ENQ_ITEM_p_t) ENQ_GET_NEXT((ENQ_ITEM_p_t)receipts);
    }

    switch (result)
    {
    case FOUND_EXACT:
        receipts->check_total += check;
        receipts->tip_total += tip;
        ++receipts->num_receipts;
        break;
    case FOUND_GREATER:
        bucket = (ENQ_ITEM_p_t) ENQ_create_item(wait_person, sizeof(RECEIPTS_t));
        bucket->check_total = check;
        bucket->tip_total = tip;
        ++bucket->num_receipts;
        ENQ_add_before(receipts, bucket);
        break;
    case NOT_FOUND:
        bucket = (ENQ_ITEM_p_t) ENQ_create_item(wait_person, sizeof(RECEIPTS_t));
        bucket->check_total = check;
        bucket->tip_total = tip;
        ++bucket->num_receipts;
        ENQ_add_tail(anchor, bucket);
        break;
    
    default:
        CDA_ASSERT(CDA_FALSE);
        break;
    }

}


void TIPS_print_receipts(void)
{
    RECEIPTS_p_t receipts = NULL;
    CDA_ASSERT(anchor != NULL);

    receipts = (RECEIPTS_p_t)ENQ_GET_HEAD(anchor);

    while (receipts != (RECEIPTS_p_t)anchor) {
        printf( "%s\n", ENQ_GET_ITEM_NAME((ENQ_ITEM_p_t)receipts));
        printf( "Total receipts: %.2f (Average: %.2f)\n",
            receipts->check_total,
            receipts->check_total / receipts->num_receipts);
    
        printf( "\n" );
        receipts = (RECEIPTS_p_t)ENQ_GET_NEXT( (ENQ_ITEM_p_t)receipts );
    }
}

void TIPS_close( void )
{
    CDA_ASSERT( anchor != NULL );
    ENQ_destroy_list( anchor );
    anchor = NULL;
}


int main( void ) 
{
    printf("FOOO\n");
    return 0;
}