/*
Copyright (c) 2019 Inverse Palindrome
Blog - FormatString.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <memory>
#include <string>
#include <cstdio>


template<typename T>
auto convert(T&& t)
{
    if constexpr (std::is_same<std::remove_cv_t<std::remove_reference_t<T>>, std::string>::value)
    {
        return std::forward<T>(t).c_str();
    }
    else
    {
        return std::forward<T>(t);
    }
}

template<typename... Args>
std::string format_string_internal(const std::string& format, Args&& ... args)
{
    const auto size = std::snprintf(nullptr, 0, format.c_str(), std::forward<Args>(args)...) + 1;
    const auto buffer = std::make_unique<char[]>(size);

    std::snprintf(buffer.get(), size, format.c_str(), std::forward<Args>(args)...);

    return std::string(buffer.get(), buffer.get() + size - 1);
}

template<typename... Args>
std::string format_string(const std::string& format, Args&& ... args)
{
    return format_string_internal(format, convert(std::forward<Args>(args))...);
}