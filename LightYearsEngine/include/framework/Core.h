#pragma once

#include <stdio.h>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

namespace ly
{

// Unique pointer.
template<typename T>
using lyUP = std::unique_ptr<T>;

// Shared Pointer.
template<typename T>
using lySP = std::shared_ptr<T>;

// Weak Pointer.
template<typename T>
using lyWP = std::weak_ptr<T>;

// Raw Pointer.
// template<typename T>
// using lyRP = T*;

// List using vector.
template<typename T>
using lyList = std::vector<T>;

// Map using std map.
template<typename keyType, typename valueType, typename predicate = std::less<keyType>>
using lyMap = std::map<keyType, valueType, predicate>; 

// Dictionary using unordered map.
template<typename keyType, typename valueType, typename hasher = std::hash<keyType>>
using lyDict = std::unordered_map<keyType, valueType, hasher>; 

// macro for logging
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

    
} // namespace ly
