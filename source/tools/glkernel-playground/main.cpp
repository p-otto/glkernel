#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <glkernel/Kernel.h>
#include <glkernel/noise.h>

#include "tmp.h"

#include <iostream>

int main(int argc, char* argv[])
{
    auto fkernel1 = glkernel::kernel1{ 1 };
    auto fkernel2 = glkernel::kernel2{ 1 };
    auto fkernel3 = glkernel::kernel3{ 1 };
    auto fkernel4 = glkernel::kernel4{ 1 };

    glkernel::noise::normal(fkernel1, 0.f, 1.f);
    glkernel::noise::normal(fkernel2, 0.f, 1.f);
    glkernel::noise::normal(fkernel3, 0.f, 1.f);
    glkernel::noise::normal(fkernel4, 0.f, 1.f);

    glkernel::testEnv::normal2(fkernel2, glm::vec2{ 0.f }, glm::vec2{ 1.f });
}
