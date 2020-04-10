/*
Copyright (c) 2020 Inverse Palindrome
Blog - Graph Traversal - UndirectedGraph.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <vector>
#include <unordered_map>


using UndirectedGraph = std::unordered_map<int, std::vector<int>>;

void addEdge(UndirectedGraph& undirected_graph, int source, int destination)
{
    undirected_graph[source].push_back(destination);
    undirected_graph[destination].push_back(source);
}