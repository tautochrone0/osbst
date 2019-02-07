#
cmake_minimum_required (VERSION 3.8)

include_directories("../incl")

# Add source to this project's lib.
add_library(osbst STATIC "osbst.cpp")
