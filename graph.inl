
// node_t::node_t
template <typename id_t, typename data_t, typename weight_t>
graph::adj_graph_t<id_t, data_t, weight_t>::node_t::node_t(id_t id, data_t data)
	:	id(std::move(id))
	,	data(std::move(data))
{}

// node_t::get_id
template <typename id_t, typename data_t, typename weight_t>
const id_t& graph::adj_graph_t<id_t, data_t, weight_t>::node_t::get_id() const
{
	return id;
}



// node_t::get_data
template <typename id_t, typename data_t, typename weight_t>
data_t& graph::adj_graph_t<id_t, data_t, weight_t>::node_t::get_data()
{
	return data;
}

// node_t::get_adj_nodes
template <typename id_t, typename data_t, typename weight_t>
typename graph::adj_graph_t<id_t, data_t, weight_t>::node_t::adj_list_t& graph::adj_graph_t<id_t, data_t, weight_t>::node_t::get_adj_nodes()
{
	return adj_nodes;
}


// node_t::set_id
template <typename id_t, typename data_t, typename weight_t>
void graph::adj_graph_t<id_t, data_t, weight_t>::node_t::set_id(id_t id)
{
	id = std::move(id);
}

// node_t::set_data
template <typename id_t, typename data_t, typename weight_t>
void graph::adj_graph_t<id_t, data_t, weight_t>::node_t::set_data(data_t data)
{
	data = std::move(data);
}



// node_t::add_adjacent_node
template <typename id_t, typename data_t, typename weight_t>
void graph::adj_graph_t<id_t, data_t, weight_t>::node_t::add_adjacent_node(
	graph::adj_graph_t<id_t, data_t, weight_t>::node_t& node,
	weight_t weight
)
{
	node_t* node_ptr = &node;

	adj_nodes.push_back(std::make_pair(node_ptr, weight));
}


// node_t::has_id
template <typename id_t, typename data_t, typename weight_t>
bool graph::adj_graph_t<id_t, data_t, weight_t>::node_t::has_id(const id_t& lookup_id) const
{
	return lookup_id == id;
}

/*
template <typename id_t, typename data_t, typename weight_t>
graph::adj_graph_t<id_t, data_t, weight_t>::node_t
template <typename id_t, typename data_t, typename weight_t>
graph::adj_graph_t<id_t, data_t, weight_t>::node_t
template <typename id_t, typename data_t, typename weight_t>
graph::adj_graph_t<id_t, data_t, weight_t>::node_t
template <typename id_t, typename data_t, typename weight_t>
graph::adj_graph_t<id_t, data_t, weight_t>::node_t
template <typename id_t, typename data_t, typename weight_t>
graph::adj_graph_t<id_t, data_t, weight_t>::node_t
*/
