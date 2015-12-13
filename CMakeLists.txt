project(vest_firmware)
cmake_minimum_required(VERSION 2.8)

set(HW_VARIANT eightanaloginputs)
set(FREQUENCY 16000000L)
set(AVR_VERSION atmega328p)

if (${CMAKE_BUILD_TYPE} STREQUAL "target")
	message("building target binary")
	add_definitions("-Os")
	
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DF_CPU=${FREQUENCY}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DF_CPU=${FREQUENCY}")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mmcu=${AVR_VERSION}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmcu=${AVR_VERSION}")
	set(CMAKE_C_COMPILER "avr-gcc")
	set(CMAKE_CXX_COMPILER "avr-g++")
	set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)
	set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

	include_directories(/usr/share/arduino/hardware/arduino/cores/arduino)
	include_directories(/usr/share/arduino/hardware/arduino/variants/${HW_VARIANT})
	include_directories(/usr/lib/avr/include/)
	include_directories(src)

	aux_source_directory(main SRC_LIST)
	aux_source_directory(src SRC_LIST)
	aux_source_directory(/usr/share/arduino/hardware/arduino/cores/arduino SRC_LIST)

	add_executable(${PROJECT_NAME} ${SRC_LIST})

elseif (${CMAKE_BUILD_TYPE} STREQUAL "test")
	message("building test binary")
	enable_testing()
	# Download and unpack googletest at configure time
	configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
	execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
	execute_process(COMMAND ${CMAKE_COMMAND} --build .
	  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
	
	# Add googletest directly to our build. This adds
	# the following targets: gtest, gtest_main, gmock
	# and gmock_main
	add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
	                 ${CMAKE_BINARY_DIR}/googletest-build
	                 EXCLUDE_FROM_ALL )
	
	# Now simply link against gtest, gtest_main, gmock or gmock_main
	# as needed. Eg
	include_directories("${gtest_SOURCE_DIR}/include")
	include_directories(test/stubs)
        include_directories(src)

	aux_source_directory("test/stubs" TEST_SRC_LIST)
	aux_source_directory(test TEST_SRC_LIST)
	aux_source_directory(src TEST_SRC_LIST)
	add_executable(test_bin ${TEST_SRC_LIST})
	target_link_libraries(test_bin gtest_main gtest)
	add_test(NAME example_test COMMAND test_bin)
endif()
