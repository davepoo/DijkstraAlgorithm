#ifndef _CGRAPH_H_
#define _CGRAPH_H_

#include <string>
#include <vector>

using namespace std;

class cNode;

/** represents a directed graph */
class cGraph
{
    public:
        /** Default constructor */
        cGraph();
        /** Default destructor */
        virtual ~cGraph();

        /** creates a new node and makes it part of this graph */
        cNode* createNode( std::string name );
        /** find a path from one node to another */
        void findPath( cNode* pFrom, cNode* pTo );
    protected:
    private:
        /** the list of nodes that are part of the graph */
        std::vector<cNode*> m_NodeList;
        /** initialise all the graph nodes ready for path
        finding from the given starting node */
        bool initPathFinding( cNode* pFrom );

        /** find the cheapest node in the graph that has not
        yet been marked as visited */
        cNode* findCheapestNode();
};

#endif // _CGRAPH_H_
