/*
Copyright (c) 2020 Inverse Palindrome
Blog - BinarySearch.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <algorithm>


template<typename Iter, typename Val, typename Comp = std::less<>>
Iter binary_search1(Iter begin, Iter end, const Val& search_val, Comp comp = {})
{
    auto original_end = end; //saving end to return when value is not found

    while (begin != end)
    {
        auto mid = begin + (end - begin) / 2;

        if (*mid == search_val) 
        {
            return mid;
        }
        else if (!comp(search_val, *mid)) //search_val > mid
        {
            begin = mid + 1;
        }
        else //search_val < mid
        {
            end = mid;
        }
    }

    return original_end;
}

template<typename Iter, typename Val, typename Comp = std::less<>>
Iter binary_search2(Iter begin, Iter end, const Val& search_val, Comp comp = {})
{
    auto found_itr = std::lower_bound(begin, end, search_val, comp);

    if (found_itr != end && !comp(search_val, *found_itr)) //search_val >= found_itr
    {
        return found_itr;
    }

    return end;
}