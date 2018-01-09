#pragma once

#include "TypeTraits.cpp"


#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT " In file " __FILE__ ":" TOSTRING(__LINE__) ","

#define CHECK_FLOATING_TYPE(T) static_assert(std::is_floating_point<T>::value, "Kernel is not of floating type!" )
#define CHECK_TYPE_EQUALITY(T1, T2, T3) static_assert(areSameType<T1, T2, T3>(), "Type of kernel parameters does not match kernel type!" AT "\n")
#define CHECK_CELLTYPE_EQUALITY(V1, V2, V3) static_assert(areSameCelltype<V1, V2, V3>(), "Celltype of kernel parameters does not match kernel celltype!")

//#define CHECK_ARGS_FLOATING
