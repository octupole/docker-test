# Policy
cmake_minimum_required( VERSION 3.0) 


# Project name
project(openTRJ CXX C)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()
include(CheckCXXCompilerFlag)
include(CheckIncludeFileCXX)
include(CheckCXXSymbolExists)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.2)
        message(FATAL_ERROR "Clang version must be at least 3.2!")
    endif()
    set(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${OpenMP_CXX_FLAGS}")        ## Optimize	
    message(WARNING "Not tested, use at your won risk.")

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
   set(CMAKE_CXX_FLAGS "-std=c++11 -ffast-math -fno-math-errno ${OpenMP_CXX_FLAGS}")  
   message(FATAL_ERROR "Cannot compile, AppleClang up to LLVM version 9.1.0 gives an internal error!")

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 17.0)
       message(FATAL_ERROR "Intel icc version must be >= 17. It is ${CMAKE_CXX_COMPILER_VERSION}")
    endif()
   set(CMAKE_CXX_FLAGS "-std=c++11 ${OpenMP_CXX_FLAGS}")  

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.4)
        message(FATAL_ERROR "GCC version must be at least 5.4")
    endif()
   set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -ffast-math -fno-math-errno ${OpenMP_CXX_FLAGS}")  
endif()

PROJECT(test-input)

add_executable(test.x test-input.cpp trjInput.cpp TrjRead.cpp)

