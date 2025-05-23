#include <vector>
#include <memory>
#include <utility>
#include <unordered_set>

#ifndef eko_directed_graph
#define eko_directed_graph

namespace eko {
	template <class T, class U>
	class directed_graph {
	public:
		class edge;
		class node;
		class edge_iterator;
		
		using node_h = const node&;
		using edge_h = const edge&;
		
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
		
		/// An immutable object representing a directed connection between two nodes.
		/// Stores a datum of type specified in the enclosing class's template parameters.
		class edge {
			friend class directed_graph;
			friend class node;
		
		private:
			U data;
			
			node_h start;
			node_h end;
		
		public:
			edge() : data() {}
			edge(const edge& other) : data(other.data), start(other.start), end(other.end) {}
			edge(U data) : data(data) {}
			
			void operator=(const edge&);
			bool operator==(const edge& a);
			
			struct hash_function {
				size_t operator()(const edge& obj) const;
			};
			
			void set_data(U data); ///< Sets the datum associated with this edge.
			U get_data(); ///< Retrieves the datum associated with this edge.
			
			node_h get_start(); ///< Returns the node which this edge starts at.
			node_h get_end(); ///< Returns the node which this edge ends at.
		};
		
		/// An immutable entity representing a node or vertex in a graph.
		/// Stores a datum of type specified in the enclosing class's template parameters.
		class node {
			friend class directed_graph;
			friend class edge;
		
		private:
			T data;
			
			std::unordered_set<edge_h, typename edge::hash_function> outgoing;
			std::unordered_set<edge_h, typename edge::hash_function> incoming;
		
		public:
			node() : data() {}
			node(const node& other) : data(other.data), incoming(other.incoming), outgoing(other.outgoing) {}
			node(node&& other) : data(other.data), incoming(other.incoming), outgoing(other.outgoing) {}
			node(T data) : data(data) {}
			
			void operator=(const node&);
			bool operator==(const node& a);
			
			struct hash_function {
				size_t operator()(const node& obj) const;
			};
			
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
		
	private:
		std::unordered_set<node, typename node::hash_function> nodes;
		std::unordered_set<edge, typename edge::hash_function> edges;

	public:
		/// Adds a node to the graph and assigns the given data to it.
		/// @return The handle of the added node.
		node_h add_node(T data);
		
		/// Adds an edge from the first node to the second and assigns the passed data to it.
		/// If the edge already exists, simply assign the data and return the existing edge.
		/// @return The handle of an edge connecting the first node to the second.
		edge_h add_edge(node first, node second, U data);
		
		/// Returns an iterator to the graph's first node.
		auto begin();
		
		/// Returns an iterator to the graph's last node.
		auto end();
		
		/// Returns a const iterator to the graph's first node.
		auto cbegin() const;
		
		/// Returns a const iterator to the graph's last node.
		auto cend() const;
		
		/// Returns an iterator to the graph's first edge.
		auto ebegin();
		
		/// Returns an iterator to the graph's last edge.
		auto eend();
		
		/// Returns a const iterator to the graph's first edge.
		auto cebegin() const;
		
		/// Returns a const iterator to the graph's last edge.
		auto ceend() const;
	};
} // eko

#include "directed_graph.cpp"

#endif