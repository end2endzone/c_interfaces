cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Define variables for group of files
set(INTERFACE_HEADER_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/include/interfaces/clonable.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/interfaces/drawable.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/interfaces/resizable.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/interfaces/shape.h
)
set(LIBSHAPE_HEADER_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libShapes/circle.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libShapes/square.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/libShapes/triangle.h
)

# Define group names for files that are used in projects
source_group("Interfaces" FILES
  ${INTERFACE_HEADER_FILES}
)
source_group("headers" FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/libShapes/circle.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/libShapes/square.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/libShapes/triangle.h
)

# Add the main executable
add_executable(main
    src/app/main.c
)

# Add the library target (libShapes)
add_library(libShapes STATIC
  src/libShapes/circle.c
  src/libShapes/square.c
  src/libShapes/triangle.c
)

target_sources(libShapes PRIVATE
  ${INTERFACE_HEADER_FILES}
  ${LIBSHAPE_HEADER_FILES}
)

# Expose headers to consumers of libShapes
target_include_directories(libShapes PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the executable against libShapes
target_link_libraries(main PRIVATE libShapes)
