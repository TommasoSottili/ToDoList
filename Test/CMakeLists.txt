add_subdirectory(./Lib/googletest)
set(gtest_SOURCE_DIR, ./Lib/googletest/)
include_directories(
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR})
set(SOURCE_TEST_FILES RunAllTests.cpp
        ToDoTest.cpp
        DateTest.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main core)