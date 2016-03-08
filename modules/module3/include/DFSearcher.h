#ifndef __DFSEARCHER_H__
#define __DFSEARCHER_H__
#include <Digraph.h>

/// depth-first search in a Digraph
class DFSearcher {
    typedef Digraph::set_type set_type;
    typedef Digraph::node_id_type node_id_type;
    set_type reachable;
    const Digraph& g;
    
    void dfs(node_id_type n) {
        for(auto target : g.targetNodesOf(n)) {
            if(!reachable.count(target)) {
                reachable.insert(target);
                dfs(target);
            }
        }
    }
    
public:
    DFSearcher(const Digraph& g, node_id_type n) : g(g) {
        if(g.count(n))
            dfs(n);
    }
    
    bool isReachable(node_id_type n) const {
        return reachable.count(n) != 0;
    }
};

#endif