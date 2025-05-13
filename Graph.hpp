#include <vector>
#include <memory>

using namespace std {
	template <class T, class U>
	class DirectedGraph {
	public:
		class Edge;
		class Node;
		
		enum class Flags : unsigned int {
			None = 0,
			Symmetric = 1 << 0, // 
			AntiSymmetric = 1 << 1, // 2
			Transitive = 1 << 2, // 4
			AntiTransitive = 1 << 2, // 4
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
			
			void set_data(T data); ///< Sets the datum associated with this edge.
			T get_data(); ///< Retrieves the datum associated with this edge.
			
			/// Creates an edge from this node to the passed node.
			/// Update's the passed node's incoming list as needed.
			/// @return The number of edges created (0, 1, or 2).
			int make_successor(shared_ptr<Node> node, EdgeFlags
		};
	
	private:
		vector<Node> nodes;
	
	public:
		
	};
}