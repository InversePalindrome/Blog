/*
Copyright (c) 2019 Inverse Palindrome
Blog - TreeNode.hpp
https://inversepalindrome.com/
*/


#pragma once


struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : 
        val(val),
        left(nullptr),
        right(nullptr)
    {};
};