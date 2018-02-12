
#include "JSInterface.h"

#include "KernelObject.h"

#include <iostream>

#include <glkernel/constraint.h>
#include <glkernel/mask.h>
#include <glkernel/noise.h>
#include <glkernel/sample.h>
#include <glkernel/scale.h>
#include <glkernel/sequence.h>
#include <glkernel/shuffle.h>
#include <glkernel/sort.h>

#include <cppexpose/variant/Variant.h>
#include <cppexpose/scripting/ScriptContext.h>

namespace {

bool canBeFloat(const cppexpose::Variant & v) {
    return v.canConvert<float>();
}

bool canBeVec2(const cppexpose::Variant & v) {
    const auto arr = v.asArray();

    if (!arr)
        return false;

    if (arr->size() < 2)
        return false;

    return canBeFloat(arr->at(0)) && canBeFloat(arr->at(1));
}

bool canBeVec3(const cppexpose::Variant & v) {
    const auto arr = v.asArray();

    if (!arr)
        return false;

    if (arr->size() < 3)
        return false;

    return canBeFloat(arr->at(0)) && canBeFloat(arr->at(1)) && canBeFloat(arr->at(2));
}

bool canBeVec4(const cppexpose::Variant & v) {
    const auto arr = v.asArray();

    if (!arr)
        return false;

    if (arr->size() < 4)
        return false;

    return canBeFloat(arr->at(0)) && canBeFloat(arr->at(1)) && canBeFloat(arr->at(2)) && canBeFloat(arr->at(3));
}

float variantToFloat(const cppexpose::Variant & v)
{
    return v.value<float>();
}

glm::vec2 variantToVec2(const cppexpose::Variant & v)
{
    const auto arr = v.asArray();

    const auto x = variantToFloat(arr->at(0));
    const auto y = variantToFloat(arr->at(1));

    return glm::vec2(x,y);
}

glm::vec3 variantToVec3(const cppexpose::Variant & v)
{
    const auto arr = v.asArray();

    const auto x = variantToFloat(arr->at(0));
    const auto y = variantToFloat(arr->at(1));
    const auto z = variantToFloat(arr->at(2));

    return glm::vec3(x,y,z);
}

glm::vec4 variantToVec4(const cppexpose::Variant & v)
{
    const auto arr = v.asArray();

    const auto x = variantToFloat(arr->at(0));
    const auto y = variantToFloat(arr->at(1));
    const auto z = variantToFloat(arr->at(2));
    const auto w = variantToFloat(arr->at(3));

    return glm::vec4(x,y,z,w);
}

} // namespace


JSInterface::JSInterface()
: Object("_glkernel")
{
    addFunction("createKernel1", this, &JSInterface::createKernel1);
    addFunction("createKernel2", this, &JSInterface::createKernel2);
    addFunction("createKernel3", this, &JSInterface::createKernel3);
    addFunction("createKernel4", this, &JSInterface::createKernel4);

    addFunction("noise_uniform", this, &JSInterface::noise_uniform);
    addFunction("noise_normal", this, &JSInterface::noise_normal);
    addFunction("noise_gradient", this, &JSInterface::noise_gradient);
    addFunction("sample_poisson_square", this, &JSInterface::sample_poisson_square);
    addFunction("sample_poisson_square1", this, &JSInterface::sample_poisson_square1);
    addFunction("sample_stratified", this, &JSInterface::sample_stratified);
    addFunction("sample_hammersley", this, &JSInterface::sample_hammersley);
    addFunction("sample_halton", this, &JSInterface::sample_halton);
    addFunction("sample_hammersley_sphere", this, &JSInterface::sample_hammersley_sphere);
    addFunction("sample_halton_sphere", this, &JSInterface::sample_halton_sphere);
    addFunction("sample_best_candidate", this, &JSInterface::sample_best_candidate);
    addFunction("sample_n_rooks", this, &JSInterface::sample_n_rooks);
    addFunction("sample_multi_jittered", this, &JSInterface::sample_multi_jittered);
    addFunction("sample_golden_point_set", this, &JSInterface::sample_golden_point_set);
    addFunction("scale_range", this, &JSInterface::scale_range);
    addFunction("sequence_uniform", this, &JSInterface::sequence_uniform);
    addFunction("shuffle_bucket_permutate", this, &JSInterface::shuffle_bucket_permutate);
    addFunction("shuffle_bayer", this, &JSInterface::shuffle_bayer);
    addFunction("shuffle_random", this, &JSInterface::shuffle_random);
    addFunction("sort_distance", this, &JSInterface::sort_distance);
}

cppexpose::Object* JSInterface::createKernel1(int width, int height, int depth)
{
    return new Kernel1Object(width, height, depth);
}

cppexpose::Object* JSInterface::createKernel2(int width, int height, int depth)
{
    return new Kernel2Object(width, height, depth);
}

cppexpose::Object* JSInterface::createKernel3(int width, int height, int depth)
{
    return new Kernel3Object(width, height, depth);
}

cppexpose::Object* JSInterface::createKernel4(int width, int height, int depth)
{
    return new Kernel4Object(width, height, depth);
}

void JSInterface::noise_uniform(cppexpose::Object* obj, const cppexpose::Variant& range_min, const cppexpose::Variant& range_max)
{
    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        if (canBeFloat(range_min) && canBeFloat(range_max))
        {
            const auto range_min_conv = variantToFloat(range_min);
            const auto range_max_conv = variantToFloat(range_max);

            glkernel::noise::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        std::cerr << "Invalid parameters for noise_uniform" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        if (canBeFloat(range_min) && canBeFloat(range_max))
        {
            const auto range_min_conv = variantToFloat(range_min);
            const auto range_max_conv = variantToFloat(range_max);

            glkernel::noise::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        if (canBeVec2(range_min) && canBeVec2(range_max))
        {
            const auto range_min_conv = variantToVec2(range_min);
            const auto range_max_conv = variantToVec2(range_max);

            glkernel::noise::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        std::cerr << "Invalid parameters for noise_uniform" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        if (canBeFloat(range_min) && canBeFloat(range_max))
        {
            const auto range_min_conv = variantToFloat(range_min);
            const auto range_max_conv = variantToFloat(range_max);

            glkernel::noise::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        if (canBeVec3(range_min) && canBeVec3(range_max))
        {
            const auto range_min_conv = variantToVec3(range_min);
            const auto range_max_conv = variantToVec3(range_max);

            glkernel::noise::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        std::cerr << "Invalid parameters for noise_uniform" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel4Object*>(obj))
    {
        if (canBeFloat(range_min) && canBeFloat(range_max))
        {
            const auto range_min_conv = variantToFloat(range_min);
            const auto range_max_conv = variantToFloat(range_max);

            glkernel::noise::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        if (canBeVec4(range_min) && canBeVec4(range_max))
        {
            const auto range_min_conv = variantToVec4(range_min);
            const auto range_max_conv = variantToVec4(range_max);

            glkernel::noise::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        std::cerr << "Invalid parameters for noise_uniform" << std::endl;
        return;
    }

    std::cerr << "Invalid kernel object for noise_uniform" << std::endl;
}


void JSInterface::noise_normal(cppexpose::Object* obj, const cppexpose::Variant& mean, const cppexpose::Variant& stddev)
{
    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        if (canBeFloat(mean) && canBeFloat(stddev))
        {
            const auto mean_conv = variantToFloat(mean);
            const auto stddev_conv = variantToFloat(stddev);

            glkernel::noise::normal(kernelObj->kernel(), mean_conv, stddev_conv);
            return;
        }

        std::cerr << "Invalid parameters for noise_normal" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        if (canBeFloat(mean) && canBeFloat(stddev))
        {
            const auto mean_conv = variantToFloat(mean);
            const auto stddev_conv = variantToFloat(stddev);

            glkernel::noise::normal(kernelObj->kernel(), mean_conv, stddev_conv);
            return;
        }

        if (canBeVec2(mean) && canBeVec2(stddev))
        {
            const auto mean_conv = variantToVec2(mean);
            const auto stddev_conv = variantToVec2(stddev);

            glkernel::noise::normal(kernelObj->kernel(), mean_conv, stddev_conv);
            return;
        }

        std::cerr << "Invalid parameters for noise_normal" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        if (canBeFloat(mean) && canBeFloat(stddev))
        {
            const auto mean_conv = variantToFloat(mean);
            const auto stddev_conv = variantToFloat(stddev);

            glkernel::noise::normal(kernelObj->kernel(), mean_conv, stddev_conv);
            return;
        }

        if (canBeVec3(mean) && canBeVec3(stddev))
        {
            const auto mean_conv = variantToVec3(mean);
            const auto stddev_conv = variantToVec3(stddev);

            glkernel::noise::normal(kernelObj->kernel(), mean_conv, stddev_conv);
            return;
        }

        std::cerr << "Invalid parameters for noise_normal" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel4Object*>(obj))
    {
        if (canBeFloat(mean) && canBeFloat(stddev))
        {
            const auto mean_conv = variantToFloat(mean);
            const auto stddev_conv = variantToFloat(stddev);

            glkernel::noise::normal(kernelObj->kernel(), mean_conv, stddev_conv);
            return;
        }

        if (canBeVec4(mean) && canBeVec4(stddev))
        {
            const auto mean_conv = variantToVec4(mean);
            const auto stddev_conv = variantToVec4(stddev);

            glkernel::noise::normal(kernelObj->kernel(), mean_conv, stddev_conv);
            return;
        }

        std::cerr << "Invalid parameters for noise_normal" << std::endl;
        return;
    }

    std::cerr << "Invalid kernel object for noise_normal" << std::endl;
}


void JSInterface::noise_gradient(cppexpose::Object* obj, int noise_type, int octave_type, unsigned int startFrequency, unsigned int octaves)
{
    const auto noise_type_enum = static_cast<glkernel::noise::GradientNoiseType>(noise_type);
    const auto octave_type_enum = static_cast<glkernel::noise::OctaveType>(octave_type);

    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        glkernel::noise::gradient(kernelObj->kernel(), noise_type_enum, octave_type_enum, startFrequency, octaves);
        return;
    }

    std::cerr << "Invalid kernel object for noise_gradient" << std::endl;
}


void JSInterface::sample_poisson_square(cppexpose::Object* obj, unsigned int num_probes)
{
    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::sample::poisson_square(kernelObj->kernel(), num_probes);
        return;
    }

    std::cerr << "Invalid kernel object for sample_poisson_square" << std::endl;
}


void JSInterface::sample_poisson_square1(cppexpose::Object* obj, float min_dist, unsigned int num_probes)
{
    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::sample::poisson_square(kernelObj->kernel(), min_dist, num_probes);
        return;
    }

    std::cerr << "Invalid kernel object for sample_poisson_square1" << std::endl;
}


void JSInterface::sample_stratified(cppexpose::Object* obj)
{
    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        glkernel::sample::stratified(kernelObj->kernel());
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::sample::stratified(kernelObj->kernel());
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        glkernel::sample::stratified(kernelObj->kernel());
        return;
    }

    std::cerr << "Invalid kernel object for sample_stratified" << std::endl;
}


void JSInterface::sample_hammersley(cppexpose::Object* obj)
{
    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::sample::hammersley(kernelObj->kernel());
        return;
    }

    std::cerr << "Invalid kernel object for sample_hammersley" << std::endl;
}


void JSInterface::sample_halton(cppexpose::Object* obj, unsigned int base1, unsigned int base2)
{
    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::sample::halton(kernelObj->kernel(), base1, base2);
        return;
    }

    std::cerr << "Invalid kernel object for sample_halton" << std::endl;
}


void JSInterface::sample_hammersley_sphere(cppexpose::Object* obj, int type)
{
    const auto type_enum = static_cast<glkernel::sample::HemisphereMapping>(type);

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        glkernel::sample::hammersley_sphere(kernelObj->kernel(), type_enum);
        return;
    }

    std::cerr << "Invalid kernel object for sample_hammersley_sphere" << std::endl;
}


void JSInterface::sample_halton_sphere(cppexpose::Object* obj, unsigned int base1, unsigned int base2, int type)
{
    const auto type_enum = static_cast<glkernel::sample::HemisphereMapping>(type);

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        glkernel::sample::halton_sphere(kernelObj->kernel(), base1, base2, type_enum);
        return;
    }

    std::cerr << "Invalid kernel object for sample_halton_sphere" << std::endl;
}


void JSInterface::sample_best_candidate(cppexpose::Object* obj, unsigned int num_candidates)
{
    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::sample::best_candidate(kernelObj->kernel(), num_candidates);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        glkernel::sample::best_candidate(kernelObj->kernel(), num_candidates);
        return;
    }

    std::cerr << "Invalid kernel object for sample_best_candidate" << std::endl;
}


void JSInterface::sample_n_rooks(cppexpose::Object* obj)
{
    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::sample::n_rooks(kernelObj->kernel());
        return;
    }

    std::cerr << "Invalid kernel object for sample_n_rooks" << std::endl;
}


void JSInterface::sample_multi_jittered(cppexpose::Object* obj, bool correlated)
{
    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::sample::multi_jittered(kernelObj->kernel(), correlated);
        return;
    }

    std::cerr << "Invalid kernel object for sample_multi_jittered" << std::endl;
}


void JSInterface::sample_golden_point_set(cppexpose::Object* obj)
{
    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::sample::golden_point_set(kernelObj->kernel());
        return;
    }

    std::cerr << "Invalid kernel object for sample_golden_point_set" << std::endl;
}


void JSInterface::scale_range(cppexpose::Object* obj, float rangeToLower, float rangeToUpper, float rangeFromLower, float rangeFromUpper)
{
    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        glkernel::scale::range(kernelObj->kernel(), rangeToLower, rangeToUpper, rangeFromLower, rangeFromUpper);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::scale::range(kernelObj->kernel(), rangeToLower, rangeToUpper, rangeFromLower, rangeFromUpper);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        glkernel::scale::range(kernelObj->kernel(), rangeToLower, rangeToUpper, rangeFromLower, rangeFromUpper);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel4Object*>(obj))
    {
        glkernel::scale::range(kernelObj->kernel(), rangeToLower, rangeToUpper, rangeFromLower, rangeFromUpper);
        return;
    }

    std::cerr << "Invalid kernel object for scale_range" << std::endl;
}


void JSInterface::sequence_uniform(cppexpose::Object* obj, const cppexpose::Variant& range_min, const cppexpose::Variant& range_max)
{
    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        if (canBeFloat(range_min) && canBeFloat(range_max))
        {
            const auto range_min_conv = variantToFloat(range_min);
            const auto range_max_conv = variantToFloat(range_max);

            glkernel::sequence::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        std::cerr << "Invalid parameters for sequence_uniform" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        if (canBeFloat(range_min) && canBeFloat(range_max))
        {
            const auto range_min_conv = variantToFloat(range_min);
            const auto range_max_conv = variantToFloat(range_max);

            glkernel::sequence::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        if (canBeVec2(range_min) && canBeVec2(range_max))
        {
            const auto range_min_conv = variantToVec2(range_min);
            const auto range_max_conv = variantToVec2(range_max);

            glkernel::sequence::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        std::cerr << "Invalid parameters for sequence_uniform" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        if (canBeFloat(range_min) && canBeFloat(range_max))
        {
            const auto range_min_conv = variantToFloat(range_min);
            const auto range_max_conv = variantToFloat(range_max);

            glkernel::sequence::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        if (canBeVec3(range_min) && canBeVec3(range_max))
        {
            const auto range_min_conv = variantToVec3(range_min);
            const auto range_max_conv = variantToVec3(range_max);

            glkernel::sequence::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        std::cerr << "Invalid parameters for sequence_uniform" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel4Object*>(obj))
    {
        if (canBeFloat(range_min) && canBeFloat(range_max))
        {
            const auto range_min_conv = variantToFloat(range_min);
            const auto range_max_conv = variantToFloat(range_max);

            glkernel::sequence::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        if (canBeVec4(range_min) && canBeVec4(range_max))
        {
            const auto range_min_conv = variantToVec4(range_min);
            const auto range_max_conv = variantToVec4(range_max);

            glkernel::sequence::uniform(kernelObj->kernel(), range_min_conv, range_max_conv);
            return;
        }

        std::cerr << "Invalid parameters for sequence_uniform" << std::endl;
        return;
    }

    std::cerr << "Invalid kernel object for sequence_uniform" << std::endl;
}


void JSInterface::shuffle_bucket_permutate(cppexpose::Object* obj, glm::uint16 subkernel_width, glm::uint16 subkernel_height, glm::uint16 subkernel_depth, bool permutate_per_bucket)
{
    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        glkernel::shuffle::bucket_permutate(kernelObj->kernel(), subkernel_width, subkernel_height, subkernel_depth, permutate_per_bucket);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::shuffle::bucket_permutate(kernelObj->kernel(), subkernel_width, subkernel_height, subkernel_depth, permutate_per_bucket);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        glkernel::shuffle::bucket_permutate(kernelObj->kernel(), subkernel_width, subkernel_height, subkernel_depth, permutate_per_bucket);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel4Object*>(obj))
    {
        glkernel::shuffle::bucket_permutate(kernelObj->kernel(), subkernel_width, subkernel_height, subkernel_depth, permutate_per_bucket);
        return;
    }

    std::cerr << "Invalid kernel object for shuffle_bucket_permutate" << std::endl;
}


void JSInterface::shuffle_bayer(cppexpose::Object* obj)
{
    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        glkernel::shuffle::bayer(kernelObj->kernel());
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::shuffle::bayer(kernelObj->kernel());
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        glkernel::shuffle::bayer(kernelObj->kernel());
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel4Object*>(obj))
    {
        glkernel::shuffle::bayer(kernelObj->kernel());
        return;
    }

    std::cerr << "Invalid kernel object for shuffle_bayer" << std::endl;
}


void JSInterface::shuffle_random(cppexpose::Object* obj, size_t start)
{
    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        glkernel::shuffle::random(kernelObj->kernel(), start);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        glkernel::shuffle::random(kernelObj->kernel(), start);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        glkernel::shuffle::random(kernelObj->kernel(), start);
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel4Object*>(obj))
    {
        glkernel::shuffle::random(kernelObj->kernel(), start);
        return;
    }

    std::cerr << "Invalid kernel object for shuffle_random" << std::endl;
}


void JSInterface::sort_distance(cppexpose::Object* obj, const cppexpose::Variant& origin)
{
    if (auto kernelObj = dynamic_cast<Kernel1Object*>(obj))
    {
        if (canBeFloat(origin))
        {
            const auto origin_conv = variantToFloat(origin);

            glkernel::sort::distance(kernelObj->kernel(), origin_conv);
            return;
        }

        std::cerr << "Invalid parameters for sort_distance" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel2Object*>(obj))
    {
        if (canBeVec2(origin))
        {
            const auto origin_conv = variantToVec2(origin);

            glkernel::sort::distance(kernelObj->kernel(), origin_conv);
            return;
        }

        std::cerr << "Invalid parameters for sort_distance" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel3Object*>(obj))
    {
        if (canBeVec3(origin))
        {
            const auto origin_conv = variantToVec3(origin);

            glkernel::sort::distance(kernelObj->kernel(), origin_conv);
            return;
        }

        std::cerr << "Invalid parameters for sort_distance" << std::endl;
        return;
    }

    if (auto kernelObj = dynamic_cast<Kernel4Object*>(obj))
    {
        if (canBeVec4(origin))
        {
            const auto origin_conv = variantToVec4(origin);

            glkernel::sort::distance(kernelObj->kernel(), origin_conv);
            return;
        }

        std::cerr << "Invalid parameters for sort_distance" << std::endl;
        return;
    }

    std::cerr << "Invalid kernel object for sort_distance" << std::endl;
}
