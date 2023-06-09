#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstddef>

namespace Tolik
{
template<typename T> struct Identity {};

template<typename T> constexpr std::size_t HeshType() { return reinterpret_cast<std::size_t>(__PRETTY_FUNCTION__); }
}

#endif