cmake_minimum_required(VERSION 2.8.9)
project (project)
add_executable(ProducerConsumer main.cpp)
TARGET_LINK_LIBRARIES( ProducerConsumer pthread)