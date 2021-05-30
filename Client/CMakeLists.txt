set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")

add_executable(r-type_client ./src/main.cpp)

target_link_libraries(r-type_client PRIVATE game-engine ${CONAN_LIBS} -lm -pthread)