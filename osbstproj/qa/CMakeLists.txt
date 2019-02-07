#Include dirs
include_directories ("../incl")

#
add_executable (testosbst "test.cpp")

#
target_link_libraries (testosbst  osbst)

enable_testing()

add_test( SimpleTest  ${CMAKE_CURRENT_BINARY_DIR}/testosbst)

#${CMAKE_BINARY_DIR}/lib