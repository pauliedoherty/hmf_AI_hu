cmake_minimum_required(VERSION 2.8)

project(test_openCV)

find_package( OpenCV REQUIRED )

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries( test_openCV ${OpenCV_LIBS} )
