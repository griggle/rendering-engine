cmake_minimum_required(VERSION 3.12)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(Rendering_Engine)

# third party libs

# SDL2
if (WIN32)
    set(SDL2_DIR deps/SDL2-vc)
endif (WIN32)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# add the executable
add_executable(Rendering_Engine "")

add_subdirectory(src)
target_include_directories(Rendering_Engine PRIVATE include)


# todo: figure out how do switch builds on debug / release
#if(CMAKE_BUILD_TYPE EQUAL "Debug")
#    add_executable(Rendering_Engine src/main.cpp)
#else()
#    add_executable(Rendering_Engine WIN32 src/main.cpp)
#endif(CMAKE_BUILD_TYPE EQUAL "Release")

target_link_libraries(Rendering_Engine ${SDL2_LIBRARIES})

if (WIN32)
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    add_custom_command(TARGET Rendering_Engine POST_BUILD        
        COMMAND ${CMAKE_COMMAND} -E copy_if_different            
            "${PROJECT_SOURCE_DIR}/${SDL2_DIR}/lib/x64/SDL2.dll"      
            $<TARGET_FILE_DIR:Rendering_Engine>)                 
else ()
    add_custom_command(TARGET Rendering_Engine POST_BUILD        
        COMMAND ${CMAKE_COMMAND} -E copy_if_different            
            "${PROJECT_SOURCE_DIR}/${SDL2_DIR}/lib/x86/SDL2.dll"      
            $<TARGET_FILE_DIR:Rendering_Engine>)   
endif ()
endif(WIN32)
