cmake_minimum_required(VERSION 3.17)

add_executable(Project main.cpp ${OPERATION_INCLUDE_DIR}/../include/LGraph.h main.cpp ../include/MGraph.h ../include/IGraph.h LGraph.cpp MGraph.cpp)

target_include_directories(Project PUBLIC ${OPERATION_INCLUDE_DIR})