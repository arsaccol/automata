#include "graph.hpp"
#include <iostream>
#include <string>

int main()
{
	graph::adj_graph_t<int, std::string> graph(false);

	graph.add_node(1, "one");
	graph.add_node(2, "two");
	graph.add_node(3, "three");
	graph.add_node(4, "four");
	graph.add_node(5, "five");
	graph.add_node(6, "six");

	graph.add_edge(1, 2);
	graph.add_edge(1, 4);
	graph.add_edge(2, 5);
	graph.add_edge(3, 6);
	graph.add_edge(3, 5);
	graph.add_edge(4, 2);
	graph.add_edge(5, 4);
	graph.add_edge(6, 6);


	//std::cout << graph.get_node(0).get_id() << std::endl;
	//std::cout << graph.get_node(1).get_data() << std::endl;

	for(auto node : graph.get_node_map())
	{
		std::cout << "Node ID: " << node.second.get_id() << std::endl;
		for(auto adj_node_pair : node.second.get_adj_nodes())
		{
			std::cout << adj_node_pair.first->get_id() << " " << std::endl;

		}

	}

	return 0;
}
