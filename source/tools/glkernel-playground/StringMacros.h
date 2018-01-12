#pragma once

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT "In file " __FILE__ ":" TOSTRING(__LINE__)": "


#define KERNEL_FLOATING "Kernel must be of a floating type (float or double)!"

#define WHICH_IS_FLOAT ", which is float."
#define WHICH_IS_DOUBLE ", which is double."
#define PARAM_MATCH_KERNEL "Type of kernel parameters must match kernel type"
#define PARAM_MATCH_FLOAT AT PARAM_MATCH_KERNEL WHICH_IS_FLOAT
#define PARAM_MATCH_DOUBLE AT PARAM_MATCH_KERNEL WHICH_IS_DOUBLE

//#define KERNEL_CELLTYPE_NOT_MATCH_PARAM_CELLTYPES "Celltype of kernel parameters does not match kernel celltype!"

#define WHICH_IS_VEC2 ", which is glm::tvec2."
#define WHICH_IS_VEC3 ", which is glm::tvec3."
#define WHICH_IS_VEC4 ", which is glm::tvec4."
#define PARAM_MATCH_CELL "Celltype of kernel parameters must match kernel celltype"
#define PARAM_MATCH_VEC2 AT PARAM_MATCH_CELL WHICH_IS_VEC2
#define PARAM_MATCH_VEC3 AT PARAM_MATCH_CELL WHICH_IS_VEC3
#define PARAM_MATCH_VEC4 AT PARAM_MATCH_CELL WHICH_IS_VEC4
