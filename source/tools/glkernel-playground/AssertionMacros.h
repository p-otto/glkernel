#pragma once

#include "TypeTraits.cpp"


#define KERNELTYPE(T) static_assert(std::is_floating_point<T>::value, "Kernel is not of floating type!");
#define PARAMTYPE(T, U, V) static_assert(eqTypes2<T, U, V>(), "Type of kernel parameters does not match kernel type");
#define PARAMTYPE2(V, U, W) static_assert(eqTypes<V, U, W>(), "Dimensions of kernel parameters does not match kernel dimensions");
