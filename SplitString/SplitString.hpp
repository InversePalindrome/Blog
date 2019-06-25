/*
Copyright (c) 2019 Inverse Palindrome
Blog - SplitString.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <string>
#include <vector>
#include <iterator>
#include <sstream>


std::vector<std::string> split_string(const std::string& string)
{
    std::istringstream i_stream(string);

    return std::vector<std::string>{std::istream_iterator<std::string>{i_stream},
        std::istream_iterator<std::string>()};
}

std::vector<std::string> split_string(const std::string& string, char delimeter)
{
    std::stringstream stream(string);

    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(stream, token, delimeter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

std::vector<std::string> split_string(const std::string& string, const std::string& delimeter)
{
    std::size_t start_index = 0, end_index = 0;

    std::vector<std::string> tokens;

    while ((end_index = string.find(delimeter, start_index)) != std::string::npos)
    {
        auto token = string.substr(start_index, end_index - start_index);
        start_index = end_index + delimeter.size();

        tokens.push_back(token);
    }

    tokens.push_back(string.substr(start_index));

    return tokens;
}