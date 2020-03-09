/*
Copyright (c) 2020 Inverse Palindrome
Blog - PermuteString.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <vector>
#include <string>
#include <algorithm>


void add_permutation1(std::vector<std::string>& permutations, std::string str, std::size_t curr_index)
{
    if (curr_index == str.size() - 1)
    {
        permutations.push_back(str);
        return;
    }

    for (auto j = curr_index; j < str.size(); ++j)
    {
        std::swap(str[curr_index], str[j]); //

        add_permutation1(permutations, str, curr_index + 1);

        //Restoring string to its original state
        std::swap(str[curr_index], str[j]);
    }
}

std::vector<std::string> get_permutations1(const std::string& str)
{
    std::vector<std::string> permutations;

    add_permutation1(permutations, str, 0);

    return permutations;
}

void add_permutation2(std::vector<std::string>& permutations, std::string str, 
    std::string curr_permutation = "")
{
    if (str.empty())
    {
        permutations.push_back(curr_permutation);
        return;
    }

    for (auto c : str)
    {
        add_permutation2(permutations, str.substr(1), curr_permutation + str[0]);

        //Rotating string one index to the left
        std::rotate(str.begin(), str.begin() + 1, str.end());
    }
}

std::vector<std::string> get_permutations2(const std::string& str)
{
    std::vector<std::string> permutations;

    add_permutation2(permutations, str);

    return permutations;
}

std::vector<std::string> get_permutations3(const std::string& str)
{
    std::vector<std::string> permutations;

    auto str_cpy = str;

    do{
        permutations.push_back(str_cpy);
    } while (std::next_permutation(str_cpy.begin(), str_cpy.end()));
    //Stops as soon as the new permutation is lexicographically smaller than the old one (comes back to original state)

    return permutations;
}