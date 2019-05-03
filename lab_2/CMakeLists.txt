cmake_minimum_required(VERSION 3.10)
project(lab_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_2 main.cpp init_list.h init_elem.h init_iterator.h errors.h list.h list_elem.h list_iterator.h
        constiterator.hpp init_base_list.h init_base_list.cpp)