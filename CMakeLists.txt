cmake_minimum_required(VERSION 2.8.2)
project(GEN_Labo5)
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(GEN_Labo5 src/main.cpp src/Customer.cpp src/MoviePriceCode/RegularPriceCode.cpp src/MoviePriceCode/NewReleasePriceCode.cpp src/MoviePriceCode/ChildrenPriceCode.cpp src/Rental.cpp)
add_executable(GEN_Labo5_tests test/CustomerTest.cpp src/Customer.cpp src/MoviePriceCode/RegularPriceCode.cpp src/MoviePriceCode/NewReleasePriceCode.cpp src/MoviePriceCode/ChildrenPriceCode.cpp test/MoviePriceCodeTest.cpp src/Rental.cpp test/MovieTest.cpp)

target_link_libraries(GEN_Labo5_tests gtest gmock_main)
add_test(NAME example_test COMMAND GEN_Labo5_tests)