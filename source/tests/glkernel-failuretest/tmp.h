#pragma once

#include <type_traits>
#include <random>

#include <glm/gtc/type_precision.hpp>
#include <glkernel/Kernel.h>


namespace glkernel
{

namespace testEnv
{


//template<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type * = nullptr>
//void normal(tkernel<T> & kernel, T mean, T stddev);

template<typename T>
void normal(tkernel<T> & kernel, T mean, T stddev);

template <typename T, glm::precision P, template<typename, glm::precision> class V>
void normal(tkernel<V<T, P>> & kernel, T mean, T stddev);

template <typename T, glm::precision P, template<typename, glm::precision> class V>
void normal(tkernel<V<T, P>> & kernel, const V<T, P> & mean, const V<T, P> & stddev);




template<typename T1, typename T2, typename T3>
void normal(tkernel<T1> &, const T2, const T3);

template <typename T1, typename T2, typename T3,
          glm::precision P, template<typename, glm::precision> class V>
void normal(tkernel<V<T1, P>> &, const T2, const T3);

template <typename T1, typename T2, typename T3,
          glm::precision P,
          template<typename, glm::precision> class V1, template<typename, glm::precision> class V2, template<typename, glm::precision> class V3>
void normal(tkernel<V1<T1, P>> &, const V2<T2, P> &, const V3<T3, P> &);




} // namespace noise

} // namespace glkernel


#include "tmp.cpp"
