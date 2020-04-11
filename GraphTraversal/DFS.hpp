/*
Copyright (c) 2020 Inverse Palindrome
Blog - Graph Traversal - DFS.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "UndirectedGraph.hpp"

#include <stack>
#include <unordered_set>


template<typename VertexType, typename Function = std::invoke_result<void(VertexType&)>::type>
void DFS(const UndirectedGraph<VertexType>& undirected_graph, VertexType current_vertex, 
    const Function& process_vertex_function)
{
    std::stack<VertexType> stack;
    stack.push(current_vertex);

    std::unordered_set<VertexType> visited_vertices;

    while (!stack.empty())
    {
        current_vertex = stack.top();
        stack.pop();

        if (visited_vertices.count(current_vertex))
        {
            continue;
        }

        visited_vertices.insert(current_vertex);

        process_vertex_function(current_vertex);

        for (auto neighbor_vertex : undirected_graph.at(current_vertex))
        {
            stack.push(neighbor_vertex);
        }
    }
}