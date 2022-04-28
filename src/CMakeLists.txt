add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/linalg)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/objects)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lights)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tools)

target_sources(Rendering_Engine 
    PRIVATE 
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/canvas.cpp
        ${CMAKE_CURRENT_LIST_DIR}/renderer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/scene.cpp
)