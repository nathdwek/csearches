cmake_minimum_required(VERSION 3.6.1)
project(csearches)

add_executable(main main.c)

target_sources(main PRIVATE clll.c bintree.c)
target_link_libraries(main sodium)
