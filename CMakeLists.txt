cmake_minimum_required(VERSION 3.7)

# Setup project name
project(AlgorithmsWorkbench)

# Use C++11
set(CMAKE_CXX_STANDARD 11)

# Compiler options for specific configurations
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra")

# Catch framework settings
add_library(Catch INTERFACE)

# Setup include directories
include_directories(include)
include_directories(test/include)

# Setup source files
file(GLOB SOURCE_FILES src/*.cpp)

# Setup test files
set(TEST_SOURCES test/src/aw_tests.cpp src/utils.cpp src/counting_sort.cpp src/graph.cpp src/graph_algorithms.cpp src/dp_algorithms.cpp src/list_algorithms.cpp src/math_algorithms.cpp src/other_algorithms.cpp src/string_algorithms.cpp src/trie.cpp test/src/aw_tests_constants.cpp test/src/utils_tests.cpp test/src/insertion_sort_tests.cpp test/src/selection_sort_tests.cpp test/src/merge_sort_tests.cpp test/src/counting_sort_tests.cpp test/src/priority_queue_tests.cpp test/src/quick_sort_tests.cpp test/src/heap_sort_tests.cpp test/src/searching_tests.cpp test/src/counting_tests.cpp test/src/stack_tests.cpp test/src/queue_tests.cpp test/src/bstree_node_tests.cpp test/src/bstree_tests.cpp test/src/bstree_utils_tests.cpp test/src/graph_tests.cpp test/src/graph_algorithms_tests.cpp test/src/dp_algorithms_tests.cpp test/src/list_algorithms_tests.cpp test/src/math_algorithms_tests.cpp test/src/other_algorithms_tests.cpp test/src/string_algorithms_tests.cpp test/src/trie_tests.cpp)

# Executable targets
add_executable(aw ${SOURCE_FILES})
add_executable(aw_tests ${TEST_SOURCES})
# add_executable(aw_tests ${TEST_SOURCES} ${TEST_INCLUDE})

# Places where executables are to be copied
set_target_properties(aw PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set_target_properties(aw PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)

set_target_properties(aw_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/test)