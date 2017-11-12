#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <list>
#include <vector>
#include <memory>
#include <utility>
#include <map>

#include <iostream>

// From CLRS:
//
// The adjacency-list representation of a graph G=(V,E)
// consists of an array of |V| lists, one for each vertex in V.
// For each u member of V, the adjacency list Adj[u] contains all
// the vertices v such that there is an edge (u,v) member of E.
// That is, Adj[u] consists of all the vertices adjacent to u
// in G.

namespace graph
{
	template <typename id_t, typename data_t, typename weight_t = std::size_t>
	class adj_graph_t
	{
	public:
		class node_t
		{
		public:
			typedef std::list< std::pair< node_t*, weight_t > >
				adj_list_t;
			
			node_t(id_t id, data_t data);

			const id_t& get_id() const;

			data_t& get_data(); 

			adj_list_t& get_adj_nodes();
			
			void set_id(id_t id);

			void set_data(data_t data);

			void add_adjacent_node(node_t& node, weight_t weight);

			bool has_id(const id_t& lookup_id) const;
		
		private:
			id_t id;
			data_t data;
			adj_list_t adj_nodes;
		}; // class node_t

		adj_graph_t(bool is_directed = true)
			:	is_directed(is_directed)
		{}

		void add_node(id_t id, data_t data)
		{
			
			if(nodes.count(id) == 0)
				nodes.emplace(id, node_t(id, data));	
		
				
		}

		// this is where the gilt twists its tail
		void add_edge(id_t origin_id, id_t destination_id, weight_t weight = 1)
		{
			if(nodes.count(origin_id) && nodes.count(destination_id))
			{
				nodes.at(origin_id).get_adj_nodes().push_back
				(
					std::make_pair( &(get_node(destination_id)), weight)
				);

				// if graph is undirected, reflect the adjacency
				if(!is_directed)
					nodes.at(destination_id).get_adj_nodes().push_back
					(
						 std::make_pair( &(get_node(origin_id)), weight)
					);
			}
				
		}

		node_t& get_node(id_t id)
		{ return nodes.at(id); }

		std::map<id_t, node_t>& get_node_map()
		{ return nodes; }




		std::map<id_t, node_t> nodes;
		bool is_directed;


	};
}

#include "graph.inl"

#endif // GRAPH_HPP
