#pragma once

#include "TypeTraits.cpp"


#define CHECK_FLOATING_TYPE(T) static_assert(std::is_floating_point<T>::value, "Kernel is not of floating type!")
#define CHECK_TYPE_EQUALITY(T, U, V) static_assert(isSameType<T, U, V>(), "Type of kernel parameters does not match kernel type!")
#define CHECK_CELLTYPE_EQUALITY(V, U, W) static_assert(isSameCelltype<V, U, W>(), "Celltype of kernel parameters does not match kernel celltype!")

//#define CHECK_ARGS_FLOATING
