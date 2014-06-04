#ifndef _CNODE_H_
#define _CNODE_H_

#include <string>
#include <vector>

class cEdge;

class cNode
{
    friend class cGraph;
    public:
        /** Default constructor */
        cNode( std::string name );
        /** Default destructor */
        virtual ~cNode();

        /** creates a new edge for this node */
        cEdge* createEdge( unsigned int cost, cNode* target );

        /** initialises the variables used for pathfinding */
        void initPathFinding( bool startnode );

    protected:
    private:
        /** the friendly name of the node */
        std::string m_Name;
        /** the list of nodes that are part of the graph */
        std::vector<cEdge*> m_EdgeList;

        /** relaxes all the nodes that are connected to this node via edges */
        void relax();

        /** the best cost to get to this node - used for calcuating paths */
        unsigned int m_bestCost;
        /** the node came from to get here via the best cost path - used for calcuating paths */
        cNode* m_pFrom;
        /** used for calcuating paths */
        bool m_visited;
};

#endif // _CNODE_H_
