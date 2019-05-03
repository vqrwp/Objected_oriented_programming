cmake_minimum_required(VERSION 3.10)
project(lab_2_spisok)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_2_spisok main.cpp errors.h constiterator.hpp _iterator.h iterator.hpp list.hpp
        _list.h elem.hpp _elem.h baseList.h)