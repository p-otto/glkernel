#pragma once

#include <glkernel/noise.h>
#include <glkernel/glm_compatability.h>

#include <iostream>
#include <type_traits>


namespace glkernel
{

namespace testEnv
{


template<template<typename, glm::precision> class V, template<typename, glm::precision> class U>
struct is_same : std::false_type { };

template<template<typename, glm::precision> class V>
struct is_same<V, V> : std::true_type { };

template<template<typename, glm::precision> class V, template<typename, glm::precision> class U>
constexpr bool eqTypes() { return is_same<V, U>::value; }


template <typename T, glm::precision P, template<typename, glm::precision> class V, template<typename, glm::precision> class V2>
void normal2(tkernel<V<T, P>> & kernel, const V<T, P> & mean, const V2<T, P> & stddev)
{
    static_assert(eqTypes<V, V2>(), "NOT THE SAME");
//    static_assert(std::is_same<V, V2>::value, "EQWFE");

    std::cout << "THE SAME" << std::endl;
}


} // testEnv

} // glkernel
