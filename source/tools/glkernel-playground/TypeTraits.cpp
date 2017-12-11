#pragma once

#include <type_traits>
#include <iostream>




namespace glkernel
{

namespace testEnv
{


template<template<typename, glm::precision> class V, template<typename, glm::precision> class U, template<typename, glm::precision> class W>
struct is_same : std::false_type {};

template<template<typename, glm::precision> class V>
struct is_same<V, V, V> : std::true_type {};

template<template<typename, glm::precision> class V, template<typename, glm::precision> class U, template<typename, glm::precision> class W>
constexpr bool eqTypes() { return is_same<V, U, W>::value; }




template<typename T, typename U, typename V>
struct is_same_type : std::false_type {};

template<typename T>
struct is_same_type<T, T, T> : std::true_type {};

template<typename T, typename U, typename V>
constexpr bool eqTypes2() { return is_same_type<T, U, V>::value; }




template <typename T>
struct is_template : std::false_type {};

template <template<typename...> class X, typename... P >
struct is_template< X<P...> > : std::true_type {};


} // testEnv

} // glkernel
