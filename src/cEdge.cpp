#include "cEdge.h"

cEdge::cEdge( unsigned int cost, cNode* target )
{
    m_cost = cost;
    m_pTarget = target;
}

cEdge::~cEdge()
{
    //dtor
}
