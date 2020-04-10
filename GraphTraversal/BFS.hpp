/*
Copyright (c) 2020 Inverse Palindrome
Blog - Graph Traversal - BFS.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "UndirectedGraph.hpp"

#include <queue>
#include <iostream>
#include <unordered_set>


void BFS(const UndirectedGraph& undirected_graph, int vertex)
{
    std::queue<int> queue;
    queue.push(vertex);

    std::unordered_set<int> visited_vertices;
    visited_vertices.insert(vertex);

    while (!queue.empty())
    {
        vertex = queue.front();
        queue.pop();

        std::cout << vertex << ' ';
        
        for (auto neighbor_vertex : undirected_graph.at(vertex))
        {
            if (!visited_vertices.count(neighbor_vertex))
            {
                visited_vertices.insert(neighbor_vertex);
                queue.push(neighbor_vertex);
            }
        }
    }
}