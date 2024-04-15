cmake_minimum_required(VERSION 3.27)
project(gaem)

if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/${CMAKE_PROJECT_NAME}/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})

file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Player.cpp
    src/TestEntity.cpp
    src/TestWorld.cpp
    src/TextEntity.cpp
)

set(BEE_VENDORED OFF)

add_subdirectory(bee)
add_dependencies(${PROJECT_NAME} bee)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE bee
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
