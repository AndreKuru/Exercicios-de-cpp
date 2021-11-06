cmake_minimum_required(VERSION 3.15)

project(class05)
add_executable(class05)
target_sources(
  class05
  PRIVATE
    functions.cpp
    functions.h
    main.cpp
    student.cpp
    student.h
  )