#ifndef UTILS_HPP
#define UTILS_HPP

#include "Header.hpp"

namespace Tolik
{
template<typename T> struct Identity {};

template<typename T> constexpr std::size_t HeshType() { return reinterpret_cast<std::size_t>(__PRETTY_FUNCTION__); }

template<typename T, typename... Types> struct IsIn;

template<typename T> struct IsIn<T>
{ enum { value = false }; };

template<typename T, typename U, typename... Types> struct IsIn<T, U, Types...>
{ enum { value = std::is_same<T, U>::value ? true : IsIn<T, Types...>::value }; };

template<std::size_t Num, typename... Null> struct GetTypeInPlace;

template<std::size_t Num, typename T> struct GetTypeInPlace<Num, T>
{ using type = typename std::conditional<Num == 0, T, void>::type; };

template<std::size_t Num, typename T, typename... Types> struct GetTypeInPlace<Num, T, Types...>
{ using type = typename std::conditional<Num != 0, typename GetTypeInPlace<Num - 1, Types...>::type, T>::type; };

template<typename T, std::enable_if_t<!std::is_array<T>::value, bool> = true> constexpr void DestroyAt(T *object)
{ object->~T(); }

template<typename T, std::enable_if_t<std::is_array<T>::value, bool> = true> constexpr void DestroyAt(T *object)
{
	for(std::size_t i = 0; i < sizeof(T)/sizeof(T[0]); i++)
		DestroyAt((*object)[i]);
}
}

#endif