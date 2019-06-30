/*
Copyright (c) 2019 Inverse Palindrome
Blog - IterativeBinaryTreeTraversal.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "TreeNode.hpp"

#include <stack>
#include <queue>
#include <iostream>


void print_pre_order(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::stack<TreeNode*> stack;
    stack.push(root);

    while (!empty(stack))
    {
        auto* node = stack.top();
        stack.pop();

        std::cout << node->val << ' ';

        if (node->right != nullptr)
        {
            stack.push(node->right);
        }
        if (node->left != nullptr)
        {
            stack.push(node->left);
        }
    }
}

void print_post_order(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::stack<TreeNode*> stack, out_stack;
    stack.push(root);

    while (!empty(stack))
    {
        auto* node = stack.top();
        stack.pop();

        out_stack.push(node);

        if (node->left != nullptr)
        {
            stack.push(node->left);
        }
        if (node->right != nullptr)
        {
            stack.push(node->right);
        }
    }

    while (!empty(out_stack))
    {
        auto* node = out_stack.top();
        out_stack.pop();

        std::cout << node->val << ' ';
    }
}

void print_in_order(TreeNode* root)
{
    std::stack<TreeNode*> stack;
    auto* curr = root;

    while (!empty(stack) || curr != nullptr)
    {
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = stack.top();
            stack.pop();

            std::cout << curr->val << ' ';

            curr = curr->right;
        }
    }
}

void print_level_order(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!empty(queue))
    {
        const auto LEVEL_SIZE = size(queue);

        for (std::size_t i = 0; i < LEVEL_SIZE; ++i)
        {
            auto* node = queue.front();
            queue.pop();

            std::cout << node->val << ' ';

            if (node->left != nullptr)
            {
                queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                queue.push(node->right);
            }
        }
    }
}