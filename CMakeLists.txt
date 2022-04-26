cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)
#####################
#      vdm_proto      #
#####################

# Project variables
set(LOCAL_PROJECT_NAME        "vdm_proto")
set(LOCAL_PROJECT_VERSION     "0.0.1")
set(LOCAL_PROJECT_DESCRIPTION "Virtual device model prototype")

# Header files (relative to "inc" directory)
set(HEADERS
    vdm_proto.h
)

# Source files (relative to "src" directory)
set(SOURCES
    vdm_proto.cpp
)

# Compiler definitions
set(DEFINES

)

# Compiler options
set(OPTIONS

)

# Project setup
project(${LOCAL_PROJECT_NAME}
        VERSION ${LOCAL_PROJECT_VERSION}
        DESCRIPTION ${LOCAL_PROJECT_DESCRIPTION}
        LANGUAGES CXX)

add_library(${LOCAL_PROJECT_NAME} SHARED)

list(TRANSFORM HEADERS PREPEND "inc/")
list(TRANSFORM SOURCES PREPEND "src/")

target_include_directories(${LOCAL_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_sources(${LOCAL_PROJECT_NAME} PRIVATE ${SOURCES} ${HEADERS})

target_compile_definitions(${LOCAL_PROJECT_NAME} PRIVATE ${DEFINES})
target_compile_options(${LOCAL_PROJECT_NAME} PRIVATE ${OPTIONS})

set_target_properties(${LOCAL_PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "lib/${CMAKE_BUILD_TYPE}")

####################
#   Dependencies   #
####################
include(systemc.cmake)

####################
#   Sub Projects   #
####################
add_subdirectory("test/tlmdriver")
add_subdirectory("test/testbench")

####################
#   Doxygen        #
####################
find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)


set(DOXYGEN_SOURCE_BROWSER YES)
set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${PROJECT_SOURCE_DIR}/README.md")
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_EXTRACT_PRIVATE YES)

doxygen_add_docs(dox
    "${PROJECT_SOURCE_DIR}/inc"
    "${PROJECT_SOURCE_DIR}/test/tlmdriver/inc"
    "${PROJECT_SOURCE_DIR}/test/testbench/inc"
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/test/tlmdriver/src"
    "${PROJECT_SOURCE_DIR}/test/testbench/src"
    "${PROJECT_SOURCE_DIR}/README.md"
    ALL
)
