cmake_minimum_required(VERSION 3.5.0)
project(zizag-conversion VERSION 0.1.0 LANGUAGES C)

# add_compile_options(-fsanitize=address)

add_executable(zizag-conversion solution.c)

target_link_libraries(zizag-conversion -fsanitize=address)

