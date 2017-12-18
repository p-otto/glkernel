#pragma once

#include <type_traits>
#include <iostream>

#include <glm/gtc/type_precision.hpp>




namespace glkernel
{

namespace testEnv
{


template<template<typename, glm::precision> class V, template<typename, glm::precision> class U, template<typename, glm::precision> class W>
struct is_same_celltype : std::false_type {};

template<template<typename, glm::precision> class V>
struct is_same_celltype<V, V, V> : std::true_type {};

template<template<typename, glm::precision> class V, template<typename, glm::precision> class U, template<typename, glm::precision> class W>
constexpr bool isSameCelltype() { return is_same_celltype<V, U, W>::value; }




template<typename T, typename U, typename V>
struct is_same_type : std::false_type {};

template<typename T>
struct is_same_type<T, T, T> : std::true_type {};

template<typename T, typename U, typename V>
constexpr bool isSameType() { return is_same_type<T, U, V>::value; }




template<typename T>
struct is_celltype : std::false_type {};

template<typename T, glm::precision P, template<typename, glm::precision> class V>
struct is_celltype<V<T, P>> : std::true_type {};

template<typename T, glm::precision P, template<typename, glm::precision> class V>
constexpr bool isCelltype() { return is_celltype<V<T, P>>::value; }




template<typename T>
struct is_templateTemplate : std::false_type {};

template<template<typename...> class X, typename... P>
struct is_templateTemplate<X<P...>> : std::true_type {};

template<template<typename...> class X, typename... P>
constexpr bool isTemplateTemplate() { return is_templateTemplate<X<P...>>::value; }

template<template<typename...> class X, typename... P>
constexpr bool isTemplate() { return !is_templateTemplate<X<P...>>::value; }




} // testEnv

} // glkernel
