cmake_minimum_required(VERSION 3.27)
project(gaem)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/${CMAKE_PROJECT_NAME}/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})

add_executable(${PROJECT_NAME}
    src/Globals.cpp
    src/main.cpp
    src/Entities/Player.cpp
    src/Entities/Teleporter.cpp
    src/Entities/TestEntity.cpp
    src/Worlds/Farm.cpp
    src/Worlds/TestWorld.cpp
)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-Wl,-rpath,./")

add_subdirectory(bee)
add_dependencies(${PROJECT_NAME} bee)

target_link_libraries(${PROJECT_NAME} PRIVATE bee)