cmake_minimum_required(VERSION 2.8) 
PROJECT (helloOpenCV)
find_package(OpenCV REQUIRED )
set( NAME_SRC
    src/main.cpp    
)

set( NAME_HEADERS       
     include/header.h
)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS} )

#Set directory to bin file
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable( helloOpenCV ${NAME_SRC} ${NAME_HEADERS} )

target_link_libraries( helloOpenCV ${OpenCV_LIBS} )