namespace eko {
	// -------- directed_graph::edge -------- //
	template <class T, class U>
	void directed_graph<T, U>::edge::set_data(U data) {
		this->data = data;
	}
	
	template <class T, class U>
	U directed_graph<T, U>::edge::get_data() {
		return this->data;
	}
	
	template <class T, class U>
	typename directed_graph<T, U>::node_h directed_graph<T, U>::edge::get_start() {
		return this->start;
	}
	
	template <class T, class U>
	typename directed_graph<T, U>::node_h directed_graph<T, U>::edge::get_end() {
		return this->end;
	}
	
	// -------- directed_graph::node -------- //
	template <class T, class U>
	void directed_graph<T, U>::node::set_data(T data) {
		this->data = data;
	}
	
	template <class T, class U>
	T directed_graph<T, U>::node::get_data() {
		return this->data;
	}
	
	// Iterate over edges.
	template <class T, class U>
	auto directed_graph<T, U>::node::begin() {
		return this->edges.begin();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::node::end() {
		return this->edges.end();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::node::cbegin() const {
		return this->edges.cbegin();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::node::cend() const {
		return this->edges.cend();
	}
	
	// -------- directed_graph -------- //
	template <class T, class U>
	typename directed_graph<T, U>::node directed_graph<T, U>::get_node(node_h h) const {
		return nodes[h]; // TODO: Requires error checking mechanisms
	}
	
	template <class T, class U>
	typename directed_graph<T, U>::edge directed_graph<T, U>::get_edge(edge_h h) const {
		return edges[h]; // TODO: Requires error checking mechanisms
	}
	
	template <class T, class U>
	typename directed_graph<T, U>::node_h directed_graph<T, U>::add_node(T data) {
		directed_graph<T, U>::node new_node = node(data);
		nodes.insert(new_node);
		
		return nodes.size();
	}
	
	template <class T, class U>
	typename directed_graph<T, U>::edge_h directed_graph<T, U>::add_edge(node_h first, node_h second, U data) {
		directed_graph<T, U>::edge new_edge = edge(data);
		new_edge.start = first;
		new_edge.end = second;
		edges.insert(new_edge);
		
		return edges.size();
	}
	
	template <class T, class U>
	bool directed_graph<T, U>::adjacent_to(node_h first, node_h second) {
		return (bool) get_node(first).outgoing_edges.count(second);
	}
	
	template <class T, class U>
	bool directed_graph<T, U>::adjacent_from(node_h first, node_h second) {
		return adjacent_to(second, first);
	}
	
	template <class T, class U>
	bool directed_graph<T, U>::adjacent(node_h first, node_h second) {
		return adjacent_to(first, second) || adjacent_from(first, second);
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::begin() {
		return nodes.begin();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::end() {
		return nodes.end();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::cbegin() const {
		return nodes.cbegin();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::cend() const {
		return nodes.cend();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::edge_begin() {
		return edges.begin();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::edge_end() {
		return edges.end();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::cedge_begin() const {
		return edges.cbegin();
	}
	
	template <class T, class U>
	auto directed_graph<T, U>::cedge_end() const {
		return edges.cend();
	}
} // eko