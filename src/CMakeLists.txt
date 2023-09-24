cmake_minimum_required(VERSION 3.26)

add_executable(26_4_2 ../main.cpp
        ../include/utilities.h
        ../include/record.h
        ../include/phone.h
        utilities.cpp
        phone.cpp
        record.cpp
)

target_include_directories(26_4_2 PUBLIC ${CMAKE_SOURCE_DIR}/include)
