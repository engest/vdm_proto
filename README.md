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
I prefer to use VS Code. But I have an entire career of using vim, Eclipse, and other editors and IDEs, so feel free to use whatever you are most comfortable with. There is currently a lot of momentum and convenience in using VS Code and its rich plugin ecosystem. So this educational package will be based on VS Code, but will not require it. Go to https://code.visualstudio.com/download to download for your system.

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