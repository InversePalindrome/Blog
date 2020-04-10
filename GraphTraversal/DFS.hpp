/*
Copyright (c) 2020 Inverse Palindrome
Blog - Graph Traversal - DFS.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "UndirectedGraph.hpp"

#include <stack>
#include <iostream>
#include <unordered_set>


void DFS(const UndirectedGraph& graph, int vertex)
{
    std::stack<int> stack;
    stack.push(vertex);

    std::unordered_set<int> visited_vertices;

    while (!stack.empty())
    {
        vertex = stack.top();
        stack.pop();

        if (visited_vertices.count(vertex))
        {
            continue;
        }

        visited_vertices.insert(vertex);

        std::cout << vertex << ' ';

        for (auto neighbor_vertex : graph.at(vertex))
        {
            stack.push(neighbor_vertex);
        }
    }
}