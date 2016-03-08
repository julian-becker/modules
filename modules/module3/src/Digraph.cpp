#include <Digraph.h>
#include <DFSearcher.h>

bool Digraph::is_acyclic() const {
    for(auto& n : nods) {
        if(DFSearcher(*this,n.first).isReachable(n.first))
            return false;
    }
    return true;
}