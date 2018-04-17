cmake_minimum_required(VERSION 3.9)
project(Wolf3d)

set(CMAKE_CXX_STANDARD 11)

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -rpath @loader_path/libSDL/ -I libSDL/SDL2.framework/Headers -I libSDL/SDL2_image.framework/Headers -lm -framework SDL2 -framework SDL2_image -F ./libSDL")
    link_directories(${PROJECT_SOURCE_DIR}/libft)
    include_directories(${PROJECT_SOURCE_DIR}/libft)

set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/libSDL/SDL2.framework/Headers)
set(SDL2_LIBRARY ${PROJECT_SOURCE_DIR}//libSDL2.so)

    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES includes/wolf.h
        srcs/cleaner.c
        srcs/clear_weapon.c
        srcs/create_map.c
        srcs/create_textures.c
        srcs/draw_textures.c
        srcs/init_bar.c
        srcs/init_textures.c
        srcs/init_weapon.c
        srcs/initialization.c
        srcs/keys.c
        srcs/main.c
        srcs/moves.c
        srcs/n_s_e_w.c
        srcs/ray_casting.c
        srcs/read_map.c
        srcs/shots.c
        srcs/time_and_speed.c
        srcs/usage.c)

add_executable(Wolf3d ${SOURCE_FILES})

target_link_libraries(Wolf3d -lft)
