cmake_minimum_required(VERSION 3.30)
project(PatternMatching11)

set(CMAKE_CXX_STANDARD 20)

add_executable(PatternMatching11 main.cpp
        Trie.cpp
        Trie.h)
# Memory leak detection using Sanitizer flags
target_compile_options(PatternMatching11 PUBLIC -fsanitize=address)
target_link_options(PatternMatching11 PUBLIC -fsanitize=address)
