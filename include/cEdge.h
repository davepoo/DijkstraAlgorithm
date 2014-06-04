#ifndef _CEDGE_H_
#define _CEDGE_H_

class cNode;

class cEdge
{
    public:
        /** Default constructor */
        cEdge( unsigned int cost, cNode* target );
        /** Default destructor */
        virtual ~cEdge();
        /** gets the target that this edge connects to */
        cNode* getTarget() const { return m_pTarget; }
        /** gets the cost to get to the target */
        unsigned int getCost() const { return m_cost; }
    protected:
    private:
        unsigned int m_cost;
        /** The node that this edge goes to */
        cNode* m_pTarget;
};

#endif // _CEDGE_H_
