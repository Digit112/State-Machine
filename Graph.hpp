#include <vector>
#include <memory>
#include <utility>

using namespace std {
	template <class T, class U>
	class DirectedGraph {
	public:
		class Edge;
		class Node;
		
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
		class Edge {
			friend class DirectedGraph;
			friend class Node;
		
		private:
			U data;
			
			shared_ptr<Node> start;
			shared_ptr<Node> end;
		
		public:
			Edge(data) : data(U data) {}
			
			void set_data(U data); ///< Sets the datum associated with this edge.
			U get_data(); ///< Retrieves the datum associated with this edge.
			
			Node get_start(); ///< Returns the node which this edge starts.
			Node get_end(); ///< Returns the node which this edge ends.
			
			/// Sets the node at which this edge starts. 
			/// Update's the existing node (if any) and the new node appropriately.
			void set_start(shared_ptr<Node> node);
			
			/// Sets the node at which this edge ends. 
			/// Update's the existing node (if any) and the new node appropriately.
			void set_end(shared_ptr<Node> node);
		};
		
		// Define a class to represent the vertices of the graph.
		class Node {
			friend class DirectedGraph;
			friend class Edge;
		
		private:
			T data;
			
			vector<shared_ptr<Edge>> outgoing;
			vector<shared_ptr<Edge>> incoming;
		
		public:
			Node(data) : data(T data) {}
			
			void set_data(T data); ///< Sets the datum associated with this node.
			T get_data(); ///< Retrieves the datum associated with this node.
			
			/// Creates an edge from this node to the passed node.
			/// Update's the passed node's incoming list as needed.
			/// @return The number of edges created (0, 1, or 2).
			int make_successor(shared_ptr<Node> node, EdgeFlags
		};
	
	private:
		vector<Node> nodes;
		unsigned int num_edges;
	
	public:
		Graph();
		
		Node add_node(T data);
		
		/// Adds an edge from the first node to the second and assigns the passed data to it.
		/// If the edge already exists, simply assign the data and return the existing edge.
		/// @return An edge connecting the first node to the second.
		Edge add_edge(Node first, Node second, U data);
	};
}