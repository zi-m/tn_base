#ifndef TN_ALGORITHM_H
#define TN_ALGORITHM_H

#include <numeric>
#include <algorithm>
#include <span>


template<typename T>
bool TN_binary_search_index(const std::span<T> s, const T& v, size_t& res)
{
    auto it = std::lower_bound(s.begin(), s.end(), v);
    if(it == s.end() || *it != v)
        return false;
    res = std::distance(s.begin(), it);
    return true;
}

template<typename T>
void TN_make_sorted_index(const std::span<T> keys, std::span<size_t> res)
{
    std::iota(res.begin(), res.end(), 0);
    auto cmp = [keys](size_t l, size_t r) { return keys[l] < keys[r]; };
    std::sort(res.begin(), res.end(), cmp);
}

template<typename T>
void TN_apply_mapping(const std::span<T> src, const std::span<size_t> mapping, std::span<T> dst)
{
    for(size_t i = 0; i < mapping.size(); ++i)
        dst[i] = src[mapping[i]];
}

template<typename T>
bool TN_is_sorted_and_unique(const std::span<T> x)
{
    return std::ranges::is_sorted(x) && std::adjacent_find(x.begin(), x.end()) == x.end();
}

template<typename T>
void TN_sort_and_unique(std::span<T>& x)
{
    std::sort(x.begin(), x.end());
    x = { x.data(), std::unique(x.begin(), x.end()) - x.begin() };
}

#endif
