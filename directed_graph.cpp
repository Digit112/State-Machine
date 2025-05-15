namespace eko {
	// -------- directed_graph::edge -------- //
	template <class T, class U>
	void directed_graph<T, U>::edge::set_data(T data) {
		this->data = data;
	}
	
	// -------- directed_graph::node -------- //
	// -------- directed_graph::edge_iterator -------- //
	// -------- directed_graph -------- //
} // eko