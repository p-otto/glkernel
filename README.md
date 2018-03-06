# glkernel
C++ library for pre-computing noise, and random sample-kernels.

## Project Health (master)

| Service | System | Compiler | Targets | Status |
| ------- | ------ | -------- | ------- | ------ |
| Jenkins | Ubuntu 14.04 | GCC 4.8 | all, test | [![Build Status](http://jenkins.hpi3d.de/buildStatus/icon?job=glkernel-linux-gcc4.8)](http://jenkins.hpi3d.de/job/glkernel-linux-gcc4.8)|
| Jenkins | Ubuntu 14.04 | GCC 4.9 | all, test | [![Build Status](http://jenkins.hpi3d.de/buildStatus/icon?job=glkernel-linux-gcc4.9)](http://jenkins.hpi3d.de/job/glkernel-linux-gcc4.9)|
| Jenkins | Ubuntu 14.04 | GCC 5.3 | all, test | [![Build Status](http://jenkins.hpi3d.de/buildStatus/icon?job=glkernel-linux-gcc5.3)](http://jenkins.hpi3d.de/job/glkernel-linux-gcc5.3)|
| Jenkins | Ubuntu 14.04 | Clang 3.5 | all, test | [![Build Status](http://jenkins.hpi3d.de/buildStatus/icon?job=glkernel-linux-clang3.5)](http://jenkins.hpi3d.de/job/glkernel-linux-clang3.5) |
| Jenkins | Windows 8.1 | MSVC 2013 Update 5 | all, test, install | [![Build Status](http://jenkins.hpi3d.de/buildStatus/icon?job=glkernel-windows-msvc2013)](http://jenkins.hpi3d.de/job/glkernel-windows-msvc2013) |
| Jenkins | Windows 8.1 | MSVC 2015 Update 1 | all, test, install | [![Build Status](http://jenkins.hpi3d.de/buildStatus/icon?job=glkernel-windows-msvc2015)](http://jenkins.hpi3d.de/job/glkernel-windows-msvc2015) |

## Features

* Smart template error messages
* Automatic multithreading using OpenMP

##### Smart template error messages

Most operations on kernels operate a kernel as well as additional parameters. This may lead to type mismatch if the element types of the kernel and the additional parameters do not match.
This case is caught by glm and a helpful error message is provided to the developer in this case.

#### Automatic multithreading using OpenMP

Some kernel operations can make use of thread level parallelism. This is achieved through OpenMP. If OpenMP is found on your system, this option is compiled in by default. If you want to ensure to run on only one core or you are developing for a single core machine, you might want to disable this behaviour in the CMake configuration.

## Using glkernel

ToDo

##### Dependencies

Using glkernel requires a C++11 compatible compiler.
For linking against glkernel: `glm`
For multithreading support (optional): `OpenMP` for multithreading support
For building the glkernel tests: `cmake` Version 3.1 or newer

##### Linking binaries

Glkernel is a header-only library, so linking is as simple as including the headers providing the needed functionality. Currently there are:
```
<noise.h> // for filling kernels with noise
<sample.h> // for sampling of kernels
<scale.h> // for scaling of kernels
<sequence.h> // 
<shuffle.h> // for shuffling the elements of a kernel
<sort.h> // for sorting the elements of a kernel
```

You probably also want to include the appropriate `glm` vectors and depending on your include discipline also the header `Kernel.h` which is included in the above headers.

##### glkernel-cmd

Additionally to using glkernel as a library, there is a standalone command line tool to generate kernels from JSON descriptions.
The usage is as follows: ```glkernel-cmd --i {input filename} --o {output filename}```, where ```{input filename}``` is a JSON kernel description file and ```{output file}``` is a JSON file containing a kernel.

The description file must contain an entry "init-kernel" that describes the size and the number of components of the the kernel that will be generated.
It also has to contain an entry "commands", which is an array of commands that will be executed on the kernel.
For these, all glkernel commands can be used.

The naming convention for applying glkernel commands is ```"{namespace}.{function name}"```, e.g. ```"noise.uniform"``` for ```noise::uniform```.
Arguments can be passed as a JSON object, e.g. ```{ "noise.uniform": { "range_min": -1.0, "range_max": 1.0 } }``` will call ```noise::uniform(kernel, -1.0, 1.0)```.

Here is an input JSON for generating 4 samples using golden point set sampling, scaling them to [-0.5, 0.5] and shuffling them randomly:
```json
{
    "init-kernel": {
        "components": 2,
        "width": 4,
        "height": 1,
        "depth": 1
    },

    "commands": [
        { "sample.golden_point_set": { } },
        { "scale.range": { "range_to_lower": -0.5, "range_to_upper": 0.5 } },
        { "shuffle.random": { } }
    ]
}
```

The generated output JSON will look like this:
```json
{
    "kernel": [
        [
            [
                [
                    -0.286392,
                    -0.437815
                ],
                [
                    -0.140494,
                    0.180219
                ],
                [
                    0.0955744,
                    -0.201747
                ],
                [
                    0.47754,
                    0.416287
                ]
            ]
        ]
    ],
    "size": {
        "depth": 1,
        "height": 1,
        "width": 4
    }
}

```
