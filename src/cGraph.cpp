#include "cGraph.h"
#include "Types.h"
#include "cNode.h"

cGraph::cGraph()
{
    //ctor
}

cGraph::~cGraph()
{
    for (std::vector<cNode*>::iterator it = m_NodeList.begin(); it != m_NodeList.end(); ++it)
    {
        cNode* node = *it;
        if ( node != nullptr  )
        {
            delete node;
        }
    }
}

cNode* cGraph::createNode( std::string name )
{
    cNode* pNode = new cNode(name);
    m_NodeList.push_back( pNode );
    return pNode;
}

cNode* cGraph::findCheapestNode()
{
    unsigned int currentBestCost = 99999999;
    cNode* cheapest = nullptr;
    for (std::vector<cNode*>::iterator it = m_NodeList.begin(); it != m_NodeList.end(); ++it)
    {
        cNode* node = *it;
        if ( node != nullptr  )
        {
            if ( node->m_visited == false &&
                node->m_bestCost < currentBestCost )
            {
                cheapest = node;
                currentBestCost = node->m_bestCost;
            }
        }
    }
    return cheapest;
}

void cGraph::findPath( cNode* pFrom, cNode* pTo )
{
    if ( initPathFinding(pFrom) )
    {
        cNode* cheapest = findCheapestNode();
        while( cheapest != nullptr )
        {
            cheapest->relax();  //Relax the connected nodes
            cheapest = findCheapestNode();
        }


        //Print out the path that we found by following backwards from the pTo node
        cout << "----------------\n";
        cout << "Calculated path from " << pFrom->m_Name << " to " << pTo->m_Name << "\n";

        // we have now created the path so print it in reverse
        cNode* pPathPos = pTo;
        while( pPathPos != nullptr )
        {
            if ( pPathPos->m_pFrom == nullptr && pPathPos != pFrom )
            {
                cout << "NOT REACHABLE";
                break;
            }
            else
            {                
                cout << pPathPos->m_Name;
                pPathPos = pPathPos->m_pFrom;
                if ( pPathPos != nullptr )
                {
                    cout << " <- ";
                }
            }
        }
        cout << "\n----------------\n";
    }
}

bool cGraph::initPathFinding( cNode* pFrom )
{
    bool containsStartingNode = false;
    for (std::vector<cNode*>::iterator it = m_NodeList.begin(); it != m_NodeList.end(); ++it)
    {
        cNode* node = *it;
        if ( node != nullptr  )
        {
            if ( node == pFrom )
            {
                node->initPathFinding(true);
                containsStartingNode = true;
            }
            else
            {
                node->initPathFinding(false);
            }
        }
    }

    return containsStartingNode;
}
