#pragma once

#include <glm/gtc/type_precision.hpp>
#include <glkernel/Kernel.h>

#include <random>


namespace glkernel
{

namespace testEnv
{


template <typename T, glm::precision P, template<typename, glm::precision> class V, template<typename, glm::precision> class V2>
void normal2(tkernel<V<T, P>> & kernel, const V<T, P> & mean, const V2<T, P> & stddev);


} // testEnv

} // glkernel

#include "tmp.cpp"
