cmake_minimum_required(VERSION 3.30)
project(PatternMatching)

set(CMAKE_CXX_STANDARD 20)

add_executable(PatternMatching main.cpp
        Trie.cpp
        Trie.h)
# Memory leak detection using Sanitizer flags
target_compile_options(PatternMatching PUBLIC -fsanitize=address)
target_link_options(PatternMatching PUBLIC -fsanitize=address)
