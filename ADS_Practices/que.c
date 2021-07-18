#ifndef QUEP_H
#define QUEP_H


#include <que.h>
#include <enq.h>


typedef struct  que__control_s 
{
    ENQ_ANCHOR_p_t anchor;
} QUE__CONTROL_t, *QUE__CONTROL_p_t;

#endif


QUE_ID_t QUE_create_queue( const char *name )
{
    QUE__CONTROL_p_t qid = CDA_NEW( QUE__CONTROL_t );
    qid->anchor = ENQ_create_list( name );
    return qid;
}