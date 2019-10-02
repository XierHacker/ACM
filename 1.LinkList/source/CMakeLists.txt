cmake_minimum_required(VERSION 3.15)
project(LinkList)

set(CMAKE_CXX_STANDARD 14)

add_executable(link_list main.cpp linklist.cpp double_linked_list.cpp double_linked_list.h)