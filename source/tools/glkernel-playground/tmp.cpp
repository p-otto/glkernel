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
//
//}


template<typename T, typename U, typename V>
//void normal(tkernel<T> & kernel, const U mean, const V stddev)
void normal(tkernel<T>&, const U, const V)
{
    CHECK_FLOATING_TYPE(T);
    CHECK_TYPE_EQUALITY(T, U, V);
    std::cout << "T Kernel" << std::endl;
}


template <typename T, glm::precision P, template<typename, glm::precision> class V, typename U, typename W>
//void normal(tkernel<V<T, P>> & kernel, const U mean, const W stddev)
void normal(tkernel<V<T, P>>&, const U, const W)
{
    CHECK_FLOATING_TYPE(T);
    CHECK_TYPE_EQUALITY(T, U, W);
    std::cout << "V<T,P> Kernel" << std::endl;
}


template <typename T, typename T2, typename T3, glm::precision P, template<typename, glm::precision> class V, template<typename, glm::precision> class U, template<typename, glm::precision> class W>
//void normal(tkernel<V<T, P>> & kernel, const U<T2, P> & mean, const W<T3, P> & stddev)
void normal(tkernel<V<T, P>>&, const U<T2, P>&, const W<T3, P>&)

{
    CHECK_FLOATING_TYPE(T);
    CHECK_CELLTYPE_EQUALITY(V, U, W);
    std::cout << "3rd kernel type" << std::endl;
}




} // testEnv

} // glkernel
