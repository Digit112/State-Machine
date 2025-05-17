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
	
	// -------- directed_graph::edge_iterator -------- //
	// -------- directed_graph -------- //
} // eko