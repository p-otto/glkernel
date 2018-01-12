#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <glkernel/Kernel.h>
#include <glkernel/noise.h>

#include "tmp.h"

#include <iostream>

int main()
{
    auto fkernel1 = glkernel::kernel1{ 1 };
    auto fkernel2 = glkernel::kernel2{ 1 };
    auto fkernel3 = glkernel::kernel3{ 1 };
    auto fkernel4 = glkernel::kernel4{ 1 };

//    auto fkernel5 = glkernel::tkernel<double>{1};

//    glkernel::noise::normal(fkernel1, 0.f, 1.f);
//    glkernel::noise::normal(fkernel2, 0.f, 1.f);
//    glkernel::noise::normal(fkernel3, 0.f, 1.f);
//    glkernel::noise::normal(fkernel4, 0.f, 1.f);

//    glkernel::noise::normal(fkernel2, glm::vec2{ 0.f }, glm::vec2{ 1.f });
//    glkernel::noise::normal(fkernel3, glm::vec3{ 0.f }, glm::vec3{ 1.f });
//    glkernel::noise::normal(fkernel4, glm::vec4{ 0.f }, glm::vec4{ 1.f });




//    glkernel::testEnv::normal(fkernel1, 0.f, 1.f);
//    glkernel::testEnv::normal(fkernel2, 0.f, 1.f);
//    glkernel::testEnv::normal(fkernel3, 0.f, 1.f);
//    glkernel::testEnv::normal(fkernel4, 0.f, 1.f);

//    glkernel::testEnv::normal(fkernel1, 0.0, 1.0);      // fail
//    glkernel::testEnv::normal(fkernel2, 0.0, 1.0);      // fail
//    glkernel::testEnv::normal(fkernel3, 0.0, 1.0);      // fail
//    glkernel::testEnv::normal(fkernel4, 0.0, 1.0);      // fail
//    glkernel::testEnv::normal(fkernel5, 0.0f, 1.0f);    // fail



//    glkernel::testEnv::normal(fkernel2, glm::vec2{ 0.f }, glm::tvec2<double, glm::precision::lowp>{ 1.f });
//    glkernel::testEnv::normal(fkernel3, glm::vec3{ 0.f }, glm::vec3{ 1.f });
//    glkernel::testEnv::normal(fkernel4, glm::vec4{ 0.f }, glm::vec4{ 1.f });


    glkernel::testEnv::normal(fkernel2, glm::vec2{ 0.0 }, glm::vec3{ 1.0 });    // fail
//    glkernel::testEnv::normal(fkernel3, glm::vec3{ 0.0 }, glm::vec3{ 1.0 });
//    glkernel::testEnv::normal(fkernel4, glm::vec4{ 0.0 }, glm::vec4{ 1.0 });

    return 0;
}
