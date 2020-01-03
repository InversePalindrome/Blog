/*
Copyright (c) 2020 Inverse Palindrome
Blog - KthLargest.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <queue>
#include <vector>
#include <algorithm>


int Kth_largest_standard_sort(const std::vector<int>& array, int k)
{
    std::sort(array.rbegin(), array.rend());

    return array[k - 1];
}

int Kth_largest_priority_queue(const std::vector<int>& array, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

    for (auto val : array)
    {
        queue.push(val);

        if (queue.size() > k)
        {
            queue.pop();
        }
    }

    return queue.top();
}

int Kth_largest_nth_element(const std::vector<int>& array, int k)
{
    std::nth_element(array.begin(), array.begin() + k - 1, array.end(), std::greater<int>());

    return array[k - 1];
}