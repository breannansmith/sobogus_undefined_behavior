cmake_minimum_required( VERSION 3.2.1 )

set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations -fsanitize=undefined -fno-sanitize-recover -fno-sanitize=nonnull-attribute" ) # -fno-sanitize=null

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

add_subdirectory( undefined_trigger )
