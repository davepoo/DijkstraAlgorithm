
#include "cGraph.h"
#include "cNode.h"

#include <iostream>

using namespace std;

int main()
{
    //Create a graph
    cGraph* pGraph = new cGraph();

    //populate nodes of the graph
    cNode* pNodeA = pGraph->createNode("A");
    cNode* pNodeB = pGraph->createNode("B");
    cNode* pNodeC = pGraph->createNode("C");
    cNode* pNodeD = pGraph->createNode("D");
    cNode* pNodeE = pGraph->createNode("E");

    //create edge links between nodes
    cEdge* pEdgeAB = pNodeA->createEdge( 1, pNodeB );
    cEdge* pEdgeBA = pNodeB->createEdge( 5, pNodeA );
    cEdge* pEdgeAC = pNodeA->createEdge( 2, pNodeC );
    cEdge* pEdgeCA = pNodeC->createEdge( 2, pNodeA );
    cEdge* pEdgeCB = pNodeC->createEdge( 1, pNodeB );
    cEdge* pEdgeBC = pNodeB->createEdge( 3, pNodeC );
    cEdge* pEdgeCD = pNodeC->createEdge( 2, pNodeD );
    cEdge* pEdgeDC = pNodeD->createEdge( 2, pNodeC );
    cEdge* pEdgeAD = pNodeA->createEdge( 4, pNodeD );


    cout << "-= Example using Dijkstra's Algorithm to calculate paths between connected nodes =-\n";
    //find a path between 2 nodes
    pGraph->findPath( pNodeA, pNodeD );
    //find a path between 2 nodes
    pGraph->findPath( pNodeD, pNodeA );
    //find a path between 2 nodes
    pGraph->findPath( pNodeA, pNodeE );
    //find a path between 2 nodes
    pGraph->findPath( pNodeA, pNodeA );

    return 0;
}
