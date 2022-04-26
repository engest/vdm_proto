cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)
#####################
#      tlmdriver      #
#####################

# Project variables
set(LOCAL_PROJECT_NAME        "tlmdriver")
set(LOCAL_PROJECT_VERSION     "0.0.1")
set(LOCAL_PROJECT_DESCRIPTION "Description")

# Header files (relative to "inc" directory)
set(HEADERS
    tlmdriver.h
)

# Source files (relative to "src" directory)
set(SOURCES
    tlmdriver.cpp
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

