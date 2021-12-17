cmake_minimum_required(VERSION 3.15)

project(class06)
add_executable(class06)
target_sources(
  class06
  PRIVATE
    course.cpp
    course.h
    functions.cpp
    functions.h
    main.cpp
    student.cpp
    student.h
  )