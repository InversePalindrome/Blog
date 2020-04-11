/*
Copyright (c) 2020 Inverse Palindrome
Blog - Graph Traversal - UndirectedGraph.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <vector>
#include <unordered_map>


template<typename VertexType>
using UndirectedGraph = std::unordered_map<VertexType, std::vector<VertexType>>;

template<typename VertexType>
void addEdge(UndirectedGraph<VertexType>& undirected_graph, 
    const VertexType& source, const VertexType& destination)
{
    undirected_graph[source].push_back(destination);
    undirected_graph[destination].push_back(source);
}