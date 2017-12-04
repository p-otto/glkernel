#pragma once

#include <glkernel/noise.h>
#include <glkernel/glm_compatability.h>

#include <iostream>
#include <type_traits>


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




//template<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type *>
//void normal(tkernel<T> & kernel, const T mean, const T stddev)
//{
//    std::cout << "1" << std::endl;
//}


template<typename T, typename U, typename V>
void normal(tkernel<T> & kernel, const U mean, const V stddev)
{
    static_assert(std::is_floating_point<T>::value, "Kernel is not of floating type!");
    static_assert(eqTypes2<T, U, V>(), "Type of kernel parameter does not match kernel type");
    std::cout << "T Kernel" << std::endl;
}


template <typename T, glm::precision P, template<typename, glm::precision> class V, typename U, typename W>
void normal(tkernel<V<T, P>> & kernel, const U mean, const W stddev)
{
    static_assert(std::is_floating_point<T>::value, "Kernel is not of floating type!");
    static_assert(eqTypes2<T, U, W>(), "Type of kernel parameters does not match kernel type");
    std::cout << "V<T,P> Kernel" << std::endl;
}


template <typename T, typename T2, typename T3, glm::precision P, template<typename, glm::precision> class V, template<typename, glm::precision> class U, template<typename, glm::precision> class W>
void normal(tkernel<V<T, P>> & kernel, const U<T2, P> & mean, const W<T3, P> & stddev)
{
    static_assert(std::is_floating_point<T>::value, "Kernel is not of floating type!");
    static_assert(eqTypes<V, U, W>(), "Dimensions of kernel parameters does not match kernel dimensions");

    std::cout << "3rd Kernel type" << std::endl;
}




} // testEnv

} // glkernel
