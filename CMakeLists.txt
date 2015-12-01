project(arduino_blink)
cmake_minimum_required(VERSION 2.8)

set(HW_VARIANT eightanaloginputs)
set(FREQUENCY 16000000L)
set(AVR_VERSION atmega328p)

add_definitions("-Os")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DF_CPU=${FREQUENCY}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DF_CPU=${FREQUENCY}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mmcu=${AVR_VERSION}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmcu=${AVR_VERSION}")
set(CMAKE_C_COMPILER "avr-gcc")
set(CMAKE_CXX_COMPILER "avr-g++")


include_directories(/usr/share/arduino/hardware/arduino/cores/arduino)
include_directories(/usr/share/arduino/hardware/arduino/variants/${HW_VARIANT})
include_directories(/usr/lib/avr/include/)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)
aux_source_directory(. SRC_LIST)
aux_source_directory(/usr/share/arduino/hardware/arduino/cores/arduino SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

