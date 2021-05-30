set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")

add_executable(r-type_server ./src/main_server.cpp)

target_link_libraries(r-type_server PRIVATE game-engine ${CONAN_LIBS} -lm -pthread)