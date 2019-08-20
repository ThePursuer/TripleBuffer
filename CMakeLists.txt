#This will create the test cases for TripleBuffer. To actually use the TripleBuffer, copy the source files into your project.
cmake_minimum_required (VERSION 2.6)

project (TripleBufferTest)

set(TEST_SOURCES test/testmain.cpp test/TripleBufferTest.cpp)
add_executable(TripleBufferTest ${TEST_SOURCES})
target_include_directories(TripleBufferTest PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(TripleBufferTest -lgtest -pthread)
