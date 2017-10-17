cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(systemc_example)

add_executable(systemc_example
        src/input_capture/icconf.cpp
        src/input_capture/bus_control.cpp
        src/input_capture/prescaler.cpp
        src/input_capture/edge_detector.cpp
        src/input_capture/timers_control.cpp
        src/input_capture/fifo.cpp
        src/input_capture.cpp
        src/main.cpp
        src/mem.cpp
        src/mips32.cpp
        src/timer.cpp
        )

add_library(systemc SHARED IMPORTED)

set_target_properties(systemc PROPERTIES
        IMPORTED_LOCATION "/Users/dmaituganov/Documents/labs/systemc/systemc-2.3.1a/lib/libsystemc.dylib"
        INTERFACE_INCLUDE_DIRECTORIES "/Users/dmaituganov/Documents/labs/systemc/systemc-2.3.1a/include"
        )

set_target_properties(systemc_example PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

target_link_libraries(systemc_example m systemc)