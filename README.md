# Project Description
https://github.com/engest/vdm_proto
## Purpose
The purpose of this project is to provide a basic SystemC/TLM2 LT model for educational purposes.

## The Design
### Virtual Device Model Prototype
The Virtual Device Model Prototype, or VDM Proto, is the model of the design we are focussed on. It is the device under development...the device under test (DUT.)

## The Testbench
The testbench simply instantiates the VDM Proto device as well as the TLMDriver module, which is described below.

### TLM Driver Module
This module is the secondary point of focus as it will have a lot of action code it in to stimulate the VDM Proto device by sending READ and WRITE transactions to it.

# Preparing Environment
## Operating System Packages
I prefer to have the following packages installed on Ubuntu, but really only the build-essential package is critical:
- build-essential
- clang
- cmake
- ninja-build
- graphviz
- mscgen
```sh
> sudo apt -y install build-essential clamng cmake ninja-build graphviz mscgen
```
## Compiler
I prefer to use clang. There is plenty to hear about it that is good. I like it for its error messages...probably because I make a lot of mistakes. To set the clang compiler (after installing it, of course):
```sh
> export CC=clang
> export CXX=clang++
```
This will set the default compiler for the system. The SystemC/TLM2 build below will use it.
## SystemC/TLM2
### Download SystemC/TLM2
- Go to https://www.accellera.org/downloads/standards/systemc
- Download the latest: SystemC 2.3.3 (Includes TLM) Core SystemC Language and Examples (tar.gz)
### Install SystemC/TLM2
- Unpack and build:
```sh
> tar xfz systemc-2.3.3.tar.gz
> cd systemc-2.3.3/
> ./configure --prefix=`pwd`/../local
> make all
> make install
```
### Setup Environment for SystemC/TLM2
For this package, you should set environment variables SYSTEMC_VERSION and SYSTEMC_HOME:
```sh
> export SYSTEMC_VERSION=2.3.3
> export SYSTEMC_HOME=/full/path/to/your/systemc/prefix
```
Yes, that means set SYSTEMC_HOME to what you set for the --prefix in your [SystemC Build](#install-systemctlm2). For those who will be using VS Code, there will be [instructions](#vs-code-settings) to set this in your c_cpp_properties.json and settings.json files - for convenience in using the VS Code Cmake GUI elements for build and run.
## VS Code
I prefer to use VS Code. But I have an entire career of using vim, Eclipse, and other editors and IDEs, so feel free to use whatever you are most comfortable with. There is currently a lot of momentum and convenience in using VS Code and its rich plugin ecosystem. So this educational project will be based on VS Code, but will not require it. Go to https://code.visualstudio.com/download to download for your system.

### VS Code Plugins (Relevant to this project)
- C/C++ Extension Pack (Microsoft)
  - Includes CMake and CMake Tools
  - Includes Doxygen
- Markdown All in One (Yu Zhang)
- Markdown Preview Enhanced (Yiyi Wang)
- Todo Tree (Gruntfuggly)
- Code Spell Checker (Street Side Software)

### VS Code Settings
#### C_CPP_PROPERTIES.JSON
Change the values for SYSTEMC_VERSION and SYSTEMC_HOME for where you have installed it to.
```json
{
    "env": {
        "SYSTEMC_VERSION": "2.3.3",
        "SYSTEMC_HOME": "${env:HOME}/devel/systemc/${SYSTEMC_VERSION}/local"
    },
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "${workspaceFolder}/inc/",
                "${workspaceFolder}/test/tlmdriver/inc/",
                "${workspaceFolder}/test/testbench/inc/",
                "${SYSTEMC_HOME}/include/",
                "${SYSTEMC_HOME}/include/tlm_utils"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "clang-x64",
            "compileCommands": "${workspaceFolder}/build/compile_commands.json"
        }
    ],
    "version": 4
}
```
#### SETTINGS.JSON
Change the values for SYSTEMC_VERSION and SYSTEMC_HOME for where you have installed it to.
```json
{
    "cmake.configureOnOpen": true,
    "cmake.configureEnvironment": {"SYSTEMC_VERSION" : "2.3.3", "SYSTEMC_HOME" : "/home/engest/devel/systemc/2.3.3/local"},
    "cmake.buildEnvironment": {"SYSTEMC_VERSION" : "2.3.3", "SYSTEMC_HOME" : "/home/engest/devel/systemc/2.3.3/local"},
    "doxygen_runner.configuration_file_override": "${workspaceFolder}/Doxyfile"
}
```

As this point everything should be in place to use this project.

# Using the Project
You should be able to open this project directory in code and it should work well out of the box if you have the [plugins mentioned above](#vs-code-plugins-relevant-to-this-project). If you are not using VS Code, there will be instructions for that below.

## Building and Running Using VS Code
Once the project is opened you should see CMake info in the status bar at the bottom of the window. It might ask you about Intellisense and maybe the CMake build kit (I use clang 10). It should also automatically execute a CMake configure.

You can set the build type as Debug or Release in the square brackets after CMake:. Click on it and it will give you the options in the Command Pallette dropdown at the top of VS Code. Likewise, you can select the the default Build target which is in square brackets after the Build:. To execute the Build, click on the (Gear)Build button in the status bar. It will execute the Doxygen build and then it will execute the building of the code.

To run the code you click on the "play" triangle and it will run the main program which is in the square brackets next to the run button. It should be set to \[vdm_main].

## Building and Running on the Command Line (CLI)
No matter how you are using the command line to build and run, you will definitely need to set your environment variables for SystemC/TLM2: [SYSTEMC_VERSION and SYSTEMC_HOME](#setup-environment-for-systemctlm2).
### Using CLI CMake
There are convenience scripts that are designed after the exact same commands as the VS Code CMake operations. These scripts are:

|         Script        |                            Purpose                              |
|----------------------:|-----------------------------------------------------------------|
| configDebugBuild.sh   | Execute CMake configuration with a build type of Debug          |
| configReleaseBuild.sh | Execute CMake configuration with a build type of Release        |
| buildDebug.sh         | Execute CMake build of all targets with a build type of Debug   |
| buildRelease.sh       | Execute CMake build of all targets with a build type of Release |
| clean.sh              | Removes the build dir                                           |

#### CLI CMake Configure and Build
To build a Debug build (Doxygen will also build):
```sh
> ./configDebugBuild.sh
> ./buildDebug.sh
```

To build a Release build (Doxygen will also build):
```sh
> ./configReleaseBuild.sh
> ./buildRelease.sh
```

#### Running a CLI CMake Debug Build
```sh
> ./build/test/testbench/bin/Debug/vdm_main
```
#### Running a CLI CMake Release Build
```sh
> ./build/test/testbench/bin/Release/vdm_main
```

### Using CLI Make
You probably noticed that I included Makefiles in this project. And if you are someone who doesn't want to, or can't for some reason, use VS Code and CMake, then you are very happy you kept reading this far.

The Makefiles are not amazing but are good enough to replicate what we are doing in CMake and with Doxygen.

#### VDM Proto and Doxygen
The primary Makefile is in the root of the project and builds the vdm_proto SystemC/TLM2 model as a shared library. This Makefile also has the project-wide Doxygen target. You will also notice the Doxyfile file next to the Makefile. This is a Doxyfile I put together. CMake does not use this, it generates its own based on the CMakefile contents. As of this writing they are fairly equivalent.

To build the docs:
```sh
> make doc
```

To build the VDM Proto model:
```sh
> make
```

#### TLM Driver Model
The TLM Driver model is intended to be a stimulus device to interact with the target device, VMD Proto. To build this TLM Driver model go into the test/tlmdriver directory and execute make:
```sh
> cd test/tlmdriver
> make
```

#### Testbench
The Testbench is the "top" of the design, which instantiates the VDM Proto model and the TLM Driver model and connects them. Then we have another CPP file (vdm_main.cpp) which instantiations the testbench in the sc_main() function. Building the testbench, for this project, means building the final executable. If you just built the TLM Driver, then navigate to the testbench directory and execute make:
```sh
> cd ../testbench
> make
```

## Running Output
No matter how you choose to run this project, the output should look the same. It should look like this simple output:
```
        SystemC 2.3.3-Accellera --- Apr 15 2022 15:50:49
        Copyright (c) 1996-2018 by all Contributors,
        ALL RIGHTS RESERVED
Greatings from vdm_proto
Greatings from driver
Greetings from testbench
Post bind
Pre sc_start()
VDM received WRITE transation at 0 s
    address=deadbeef
    data:
         [0]=ee
         [1]=ff
         [2]=c0
         [3]=ad
VDM received READ transation at 0 s
VDM received WRITE transation at 10 ns
    address=deadbeef
    data:
         [0]=ee
         [1]=ff
         [2]=c0
         [3]=ad
VDM received READ transation at 10 ns
...
```
The ellipsis there implies it keeps going for a few rounds. I will update this output as the project progresses.

# Communication
You can communicate with me regarding this project on the [Matrix channel](https://matrix.to/#/#systemctlm2:matrix.org) in the room [VDM Proto](https://matrix.to/#/#vdm-proto:matrix.org) (vdm-proto). 