/*
Copyright (c) 2020 Inverse Palindrome
Blog - Graph Traversal - BFS.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "UndirectedGraph.hpp"

#include <queue>
#include <unordered_set>


template<typename VertexType, typename Function = std::invoke_result<void(VertexType&)>::type>
void BFS(const UndirectedGraph<VertexType>& undirected_graph, VertexType current_vertex,
    const Function& process_vertex_function)
{
    std::queue<VertexType> queue;
    queue.push(current_vertex);

    std::unordered_set<VertexType> visited_vertices;
    visited_vertices.insert(current_vertex);

    while (!queue.empty())
    {
        current_vertex = queue.front();
        queue.pop();

        process_vertex_function(current_vertex);
        
        for (auto neighbor_vertex : undirected_graph.at(current_vertex))
        {
            if (!visited_vertices.count(neighbor_vertex))
            {
                visited_vertices.insert(neighbor_vertex);
                queue.push(neighbor_vertex);
            }
        }
    }
}