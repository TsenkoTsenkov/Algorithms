# CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
project(Homework DESCRIPTION "Summer Homework for Introduction to programming" VERSION 0.0.1)

message("Finding 3d-party Catch2 library")
find_package(Catch2 CONFIG REQUIRED)

message("Creating target for test of the BitComparison program")
add_executable(run_BitComparisonTests src/BitComparison.cpp tests/BitComparisonTests.cpp )
target_compile_features(run_BitComparisonTests PUBLIC cxx_std_17)
target_link_libraries(run_BitComparisonTests PRIVATE Catch2::Catch2)

enable_testing()
add_test(RegistrationTests run_BitComparisonTests)
message("Build successfully")