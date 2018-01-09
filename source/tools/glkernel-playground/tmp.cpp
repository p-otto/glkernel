#pragma once

#include <glkernel/noise.h>
#include <glkernel/glm_compatability.h>
#include "AssertionMacros.h"
#include <iostream>




namespace glkernel
{

namespace testEnv
{


//template<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type *>
//void normal(tkernel<T> & kernel, const T mean, const T stddev)
//{
//    std::cout << "ORIG 1" << std::endl;
//    kernel.template for_each<glkernel::noise::normal_operator<T>>(mean, stddev);
//}

template<typename T>
void normal(tkernel<T> & kernel, const T mean, const T stddev)
{
    std::cout << "ORIG 1" << std::endl;
    kernel.template for_each<glkernel::noise::normal_operator<T>>(mean, stddev);
}

template <typename T, glm::precision P, template<typename, glm::precision> class V>
void normal(tkernel<V<T, P>> & kernel, const T mean, const T stddev)
{
    std::cout << "ORIG 2" << std::endl;
    kernel.template for_each<glkernel::noise::normal_operator<T>>(mean, stddev);
}

template <typename T, glm::precision P, template<typename, glm::precision> class V>
void normal(tkernel<V<T, P>> & kernel, const V<T, P> & mean, const V<T, P> & stddev)
{
    std::cout << "ORIG 3" << std::endl;
    kernel.template for_each<glkernel::noise::normal_operator<T>>(mean, stddev);
}




template<typename T1, typename T2, typename T3>
void normal(tkernel<T1> &, const T2, const T3)
{
    CHECK_FLOATING_TYPE(T1);
    CHECK_TYPE_EQUALITY(T1, T2, T3);
    std::cout << "NEW 1" << std::endl;
}


template <typename T1, typename T2, typename T3,
          glm::precision P, template<typename, glm::precision> class V>
void normal(tkernel<V<T1, P>> &, const T2, const T3)
{
    CHECK_FLOATING_TYPE(T1);
    CHECK_TYPE_EQUALITY(T1, T2, T3);
    std::cout << "NEW 2" << std::endl;
}


template <typename T1, typename T2, typename T3,
          glm::precision P,
          template<typename, glm::precision> class V1, template<typename, glm::precision> class V2, template<typename, glm::precision> class V3>
void normal(tkernel<V1<T1, P>> & kernel, const V2<T2, P> & mean, const V3<T3, P> & stddev)
{
    CHECK_FLOATING_TYPE(T1);
    CHECK_TYPE_EQUALITY(T1, T2, T3);
    CHECK_CELLTYPE_EQUALITY(V1, V2, V3);
    std::cout << "NEW 3" << std::endl;
}




} // testEnv

} // glkernel
