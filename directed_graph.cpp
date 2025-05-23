namespace eko {
	// -------- directed_graph::edge -------- //
    template <class T, class U>
	size_t directed_graph<T, U>::edge::hash_function::operator()(const eko::directed_graph<T, U>::edge& obj) const {
		size_t h1 = std::hash<eko::directed_graph<T, U>::node>()(obj.get_start());
		size_t h2 = std::hash<eko::directed_graph<T, U>::node>()(obj.get_end());
		return h1 ^ h2;
	}
	
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
	size_t directed_graph<T, U>::node::hash_function::operator()(const directed_graph<T, U>::node& obj) const {
		return std::hash<size_t>()(&obj);
	}
	
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
	typename directed_graph<T, U>::node_h directed_graph<T, U>::add_node(T data) {
		std::pair<bool, bool> res = nodes.insert(node(data));
	}
	
} // eko

// Define the hash function
namespace std {
	
}