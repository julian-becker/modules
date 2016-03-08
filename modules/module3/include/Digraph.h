#ifndef __DIGRAPH_H__
#define __DIGRAPH_H__

#include <unordered_map>
#include <unordered_set>

class DFSearcher;

template <typename InsertIterator>
class TopologicalSorter;

class Digraph {
public:
    typedef size_t node_id_type;
    typedef std::unordered_set<node_id_type> set_type;
private:
    std::unordered_map<node_id_type,set_type> nods;

public:
	Digraph() {}
	Digraph(const Digraph& other) : nods(other.nods) {}
	Digraph(Digraph&& other) : nods(std::move(other.nods)) {}
	Digraph& operator=(const Digraph& other) { Digraph copy(other); *this = std::move(copy); return *this; }
    Digraph& operator=(Digraph&& other) {
		nods = std::move(other.nods);
		return *this;
	}
    ~Digraph() throw() {}
    
    void addNode(const node_id_type& id) {
        if(!nods.count(id))
            nods.insert(std::make_pair(id,set_type()));
    }
    
    void addEdge(node_id_type from, node_id_type to) {
        nods.at(std::move(from)).insert(std::move(to));
    }
    
    set_type targetNodesOf(const node_id_type& node) const {
        return nods.at(node);
    }
    
    size_t count(node_id_type node) const {
        return nods.count(std::move(node));
    }
    
    set_type nodes() const {
        set_type allNodes;
        for(auto& n : nods) allNodes.insert(n.first);
        return allNodes;
    }
    
    Digraph transitiveClosure() const;
    
    bool is_acyclic() const;
       
    template <typename InsertIterator>
    void sort(InsertIterator output) const {
        TopologicalSorter<InsertIterator>(*this,output).sort();
    }
};


template <typename InsertIterator>
class TopologicalSorter {
    const Digraph& g;
    typedef typename Digraph::node_id_type node_id_type;
    typedef typename Digraph::set_type set_type;
    set_type to_visit;
    set_type marked_temporarily;
    InsertIterator output;
    
    
    void visit(const node_id_type& n) {
        if(marked_temporarily.count(n))
            throw "GraphHasCycles-Exception";
        
        if(!to_visit.count(n))
            return;
        
        marked_temporarily.insert(n);
        for(auto& m : g.targetNodesOf(n)) {
            visit(m);
        }
        
        to_visit.erase(n);
        marked_temporarily.erase(n);
        output = n;
    }

public:
    TopologicalSorter(const Digraph& g, InsertIterator output)
        : g(g), to_visit(g.nodes()), output(output) {
    }
    
    void sort() {
        while(to_visit.size()) {
            auto it = to_visit.begin();
            auto n = *it;
            visit(n);
        }
    }
};

#endif