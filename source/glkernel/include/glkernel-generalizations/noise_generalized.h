#pragma once

#include <glkernel/Kernel.h>

#include <glm/gtc/type_precision.hpp>


namespace glkernel
{


namespace noise
{




template<typename T1, typename T2, typename T3,
         glm::precision P, template<typename, glm::precision> class V>
void uniform(tkernel<T1> &, const T2, const T3);


template<typename T1, typename T2, typename T3,
         glm::precision P, template<typename, glm::precision> class V>
void uniform(tkernel<T1> &, const V<T2, P> &, const T3);

template<typename T1, typename T2, typename T3,
         glm::precision P, template<typename, glm::precision> class V>
void uniform(tkernel<T1> &, const T2, const V<T3, P> &);


template <typename T1, typename T2, typename T3,
          glm::precision P, template<typename, glm::precision> class V>
void uniform(tkernel<V<T1, P>> &, const T2, const T3);


template <typename T1, typename T2, typename T3,
          glm::precision P,
          template<typename, glm::precision> class V1, template<typename, glm::precision> class V2>
void uniform(tkernel<V1<T1, P>> &, const V2<T2, P> &, const T3);

template <typename T1, typename T2, typename T3,
          glm::precision P,
          template<typename, glm::precision> class V1, template<typename, glm::precision> class V2>
void uniform(tkernel<V1<T1, P>> &, const T2, const V2<T3, P> &);


template <typename T1, typename T2, typename T3,
          glm::precision P,
          template<typename, glm::precision> class V1, template<typename, glm::precision> class V2, template<typename, glm::precision> class V3>
void uniform(tkernel<V1<T1, P>> &, const V2<T2, P> &, const V3<T3, P> &);




template<typename T1, typename T2, typename T3>
void normal(tkernel<T1> &, const T2, const T3);


template<typename T1, typename T2, typename T3,
         glm::precision P, template<typename, glm::precision> class V>
void normal(tkernel<T1> &, const V<T2, P> &, const T3);

template<typename T1, typename T2, typename T3,
         glm::precision P, template<typename, glm::precision> class V>
void normal(tkernel<T1> &, const T2, const V<T3, P> &);


template <typename T1, typename T2, typename T3,
          glm::precision P, template<typename, glm::precision> class V>
void normal(tkernel<V<T1, P>> &, const T2, const T3);


template <typename T1, typename T2, typename T3,
          glm::precision P,
          template<typename, glm::precision> class V1, template<typename, glm::precision> class V2>
void normal(tkernel<V1<T1, P>> &, const V2<T2, P> &, const T3);

template <typename T1, typename T2, typename T3,
          glm::precision P,
          template<typename, glm::precision> class V1, template<typename, glm::precision> class V2>
void normal(tkernel<V1<T1, P>> &, const T2, const V2<T3, P> &);


template <typename T1, typename T2, typename T3,
          glm::precision P,
          template<typename, glm::precision> class V1, template<typename, glm::precision> class V2, template<typename, glm::precision> class V3>
void normal(tkernel<V1<T1, P>> &, const V2<T2, P> &, const V3<T3, P> &);


template <typename T, glm::precision P, template<typename, glm::precision> class V>
void gradient(tkernel<V<T, P>> &
    , const GradientNoiseType = GradientNoiseType::Perlin
    , const OctaveType = OctaveType::Standard
    , const unsigned int = 3
    , const unsigned int = 5);




} // namespace noise


} // namespace glkernel


#include "noise_generalized.hpp"