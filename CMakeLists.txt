cmake_minimum_required(VERSION 3.16)
project(fract1 C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft)
include_directories(minilibx)

add_executable(fract1
        includes/fract.h
        sources/bonus.c
        sources/burningship.c
        sources/heart.c
        sources/init_main_struct.c
        sources/juila.c
        sources/key_hook.c
        sources/main.c
        sources/mandelbar.c
        sources/mandelbrot.c
        sources/move.c
        sources/threads.c
        sources/celtic.c
        sources/mand5.c
        sources/burn5.c)