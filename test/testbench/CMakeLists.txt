cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)
#####################
#      vdmtb      #
#####################

# Project variables
set(LOCAL_PROJECT_NAME        "vdm_main")
set(LOCAL_PROJECT_VERSION     "0.0.1")
set(LOCAL_PROJECT_DESCRIPTION "Description")

# Header files (relative to "inc" directory)
set(HEADERS
    testbench.h
)

# Source files (relative to "src" directory)
set(SOURCES
    testbench.cpp
    vdm_main.cpp
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

add_executable(${LOCAL_PROJECT_NAME})

list(TRANSFORM HEADERS PREPEND "inc/")
list(TRANSFORM SOURCES PREPEND "src/")

target_include_directories(${LOCAL_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

include_directories("${PROJECT_SOURCE_DIR}/../../inc")
include_directories("${PROJECT_SOURCE_DIR}/../../test/tlmdriver/inc")
link_directories("${PROJECT_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE}")
link_directories("${PROJECT_SOURCE_DIR}/lib/test/tlmdriver/lib/${CMAKE_BUILD_TYPE}")
target_link_libraries(${LOCAL_PROJECT_NAME} systemc)
target_link_libraries(${LOCAL_PROJECT_NAME} vdm_proto)
target_link_libraries(${LOCAL_PROJECT_NAME} tlmdriver)

target_sources(${LOCAL_PROJECT_NAME} PRIVATE ${SOURCES} ${HEADERS})

target_compile_definitions(${LOCAL_PROJECT_NAME} PRIVATE ${DEFINES})
target_compile_options(${LOCAL_PROJECT_NAME} PRIVATE ${OPTIONS})

set_target_properties(${LOCAL_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "bin/${CMAKE_BUILD_TYPE}")



####################
#   Dependencies   #
####################
