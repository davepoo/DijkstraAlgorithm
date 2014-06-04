#include "cNode.h"
#include "cEdge.h"
#include "Types.h"

cNode::cNode( std::string name )
{
    m_Name = name;
}

cNode::~cNode()
{
    //delete all the edges
    for (std::vector<cEdge*>::iterator it = m_EdgeList.begin(); it != m_EdgeList.end(); ++it)
    {
        cEdge* edge = *it;
        if ( edge != nullptr  )
        {
            delete edge;
            edge = nullptr;
        }
    }
}

cEdge* cNode::createEdge( unsigned int cost, cNode* target )
{
    cEdge* pEdge = new cEdge(cost,target);
    m_EdgeList.push_back( pEdge );
    return pEdge;
}

/** initialises the variables used for pathfinding */
void cNode::initPathFinding( bool startnode )
{
    if ( startnode )
    {
        m_bestCost = 0;         //there is no better way to get the start node
    }
    else
    {
        m_bestCost = 999999;    //very large value
    }
    m_pFrom = nullptr;      //unknow parent
    m_visited = false;      //has not been processed
}

void cNode::relax()
{
    for (std::vector<cEdge*>::iterator it = m_EdgeList.begin(); it != m_EdgeList.end(); ++it)
    {
        cEdge* edge = *it;
        if ( edge != nullptr  )
        {
            //work out the cost to all the connected edges
            cNode* target = edge->getTarget();
            if ( target->m_bestCost > m_bestCost + edge->getCost() )
            {
                target->m_bestCost = m_bestCost + edge->getCost();
                target->m_pFrom = this;
            }
        }
    }

    m_visited = true;
}
