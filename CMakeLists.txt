cmake_minimum_required(VERSION 2.8.2)

project(GEN_Labo5)
set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wconversion -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

# Trivial example using gtest and gmock
add_executable(GEN_Labo5 src/main.cpp src/Customer.cpp src/MoviePriceCode/RegularPriceCode.cpp src/MoviePriceCode/NewReleasePriceCode.cpp src/MoviePriceCode/ChildrenPriceCode.cpp)
add_executable(GEN_Labo5_tests test/CustomerTest.cpp src/Customer.cpp src/MoviePriceCode/RegularPriceCode.cpp src/MoviePriceCode/NewReleasePriceCode.cpp src/MoviePriceCode/ChildrenPriceCode.cpp test/MoviePriceCodeTest.cpp)

target_link_libraries(GEN_Labo5_tests gtest gmock_main)
add_test(NAME example_test COMMAND GEN_Labo5_tests)