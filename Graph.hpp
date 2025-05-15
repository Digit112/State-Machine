#include <vector>
#include <memory>
#include <utility>

template <class T, class U>
class directed_graph {
public:
	class edge;
	class node;
	class edge_iterator;
	
	enum class Flags : unsigned int {
		None = 0,
		Symmetric       = 1 <<  0, ///< Describes a graph which contains a reverse edge (f, s) for every edge (s, f).
		AntiSymmetric   = 1 <<  1, ///< Describes a graph which does not contain the reverse edge (f, s) for any given edge (s, f).
		Transitive      = 1 <<  2, ///< Describes a graph which contains an edge (a, b) between any two nodes for which a directed path from a to b would exist in the edge's absence.
		AntiTransitive  = 1 <<  3, ///< Describes a graph which contains no edge (a, b) between two nodes for which a directed path from a to b would exist in the edge's absence.
		Reflexive       = 1 <<  4, ///< Describes a graph containing an edge (a, a) for all nodes from themselves to themselves. A Reflexive graph is also not acyclic.
		AntiReflexive   = 1 <<  6, ///< Describes a graph containing no edge (a, a) from any node to itself.
		Connected       = 1 <<  6, ///< Describes a graph containing a directed path from any given node to any other. A connected graph is also weakly connected.
		WeaklyConnected = 1 <<  7, ///< Describes a graph containing an undirected path between any two given nodes, a path that would be present in the undirected graph obtained by replacing all directed edges in this graph with undirected edges.
		Acyclic         = 1 <<  8, ///< Describes a graph containg no directed paths from any node to itself. An Acyclic graph is also antireflexive.
		Full            = 1 <<  9, ///< Describes a graph which contains an edge from any two given nodes. A full graph is also reflexive, symmetric, transitive, and connected.
		Empty           = 1 << 10, ///< Describes a graph which contains no edges (but may contain nodes). An empty graph is symmetric, antisymmetric, transitive, antitransitive, antireflexive, and disconnected. It is also considered reflexive if there are no nodes.
		Null            = 1 << 11, ///< Describes a graph with no nodes. A Null graph is also empty.
	};
	
	// Define a class which connects nodes together.
	class edge {
		friend class directed_graph;
		friend class node;
	
	private:
		U data;
		
		node& start;
		node& end;
	
	public:
		edge(U data) : data(data) {}
		
		void set_data(U data); ///< Sets the datum associated with this edge.
		U get_data(); ///< Retrieves the datum associated with this edge.
		
		node& get_start(); ///< Returns the node which this edge starts.
		node& get_end(); ///< Returns the node which this edge ends.
		
		/// Sets the node at which this edge starts. 
		/// Update's the existing node (if any) and the new node appropriately.
		void set_start(node& n);
		
		/// Sets the node at which this edge ends. 
		/// Update's the existing node (if any) and the new node appropriately.
		void set_end(node& n);
	};
	
	/// Represents a single vertex of a graph. Can be associated with a single element of data.
	class node {
		friend class directed_graph;
		friend class edge;
	
	private:
		T data;
		
		std::vector<edge&> outgoing;
		std::vector<edge&> incoming;
	
	public:
		node(T data) : data(data) {}
		
		void set_data(T data); ///< Sets the datum associated with this node.
		T get_data(); ///< Retrieves the datum associated with this node.
	
		/// Returns an iterator to the nodes's first edge.
		auto begin();

		/// Returns an iterator to the nodes's last edge.
		auto end();

		/// Returns a const iterator to the nodes's first edge.
		auto cbegin() const;

		/// Returns a const iterator to the nodes's last edge.
		auto cend() const;
	};
	
	/// Represents an iterator over edges.
	class edge_iterator {
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type   = std::ptrdiff_t;
		using value_type        = edge;
		using pointer           = edge*;
		using reference         = edge&;
		
		// Iterator over all the nodes in the graph.
		std::vector<node>::iterator nit;
		
		// Iterator over some of the edges of the pointer-to node
		// (whether it is the outgoing or incoming edges is an unspecified implementation detail)
		std::vector<edge>::iterator eit;
		
		edge_iterator(directed_graph& graph);
		
		edge_iterator(const directed_graph& graph);
		
		// Implement relevant operations on iterators.
		reference operator*();
		pointer operator->();
		edge_iterator& operator++();
		edge_iterator& operator++(int);
		edge_iterator& operator--();
		edge_iterator& operator--(int);
		
		friend bool operator== (const edge_iterator& a, const edge_iterator& b);
		friend bool operator!= (const edge_iterator& a, const edge_iterator& b);
	};
	
private:
	std::vector<node> nodes;
	unsigned int num_edges;

public:
	Graph();
	
	/// Adds a node to the graph and assigns the given data to it.
	/// @return The added node.
	node add_node(T data);
	
	/// Adds an edge from the first node to the second and assigns the passed data to it.
	/// If the edge already exists, simply assign the data and return the existing edge.
	/// @return An edge connecting the first node to the second.
	edge add_edge(node first, node second, U data);
	
	/// Returns an iterator to the graph's first node.
	auto begin();
	
	/// Returns an iterator to the graph's last node.
	auto end();
	
	/// Returns a const iterator to the graph's first node.
	auto cbegin() const;
	
	/// Returns a const iterator to the graph's last node.
	auto cend() const;
};