cmake_minimum_required(VERSION 3.27)
project(gaem)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/gaem/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

file(COPY assets DESTINATION ${OUTPUT_DIR})

add_executable(${PROJECT_NAME}
    src/ExampleEntity.cpp
    src/main.cpp
    src/TestEntity.cpp
    src/TestRoom.cpp
)

add_subdirectory(bee)
add_dependencies(${PROJECT_NAME} bee)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC bee
)
