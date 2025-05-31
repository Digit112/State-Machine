#include <iostream>
#include <cstdio>

#include "directed_graph.hpp"

int main() {
       std::cout << __cplusplus << std::endl;
	
	eko::directed_graph<int, int> my_dgraph;
	
	auto node_1 = my_dgraph.add_node(1);
	auto node_2 = my_dgraph.add_node(2);
	
	auto edge_12 = my_dgraph.add_edge(node_1, node_2, 1);
	
	my_dgraph.get_edge(edge_12);
	
	printf("%d\n", my_dgraph.adjacent_to(node_1, node_2));
}