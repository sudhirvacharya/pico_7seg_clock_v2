cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH "C:/Users/sudhe/.pico-sdk/sdk/2.2.0")
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico_7seg_clock_v2 C CXX ASM)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

# Include TM1637 library
include(${CMAKE_SOURCE_DIR}/TM1637-pico/PicoTM1637.cmake)

add_executable(pico_7seg_clock_v2 main.c)

target_link_libraries(pico_7seg_clock_v2
    pico_stdlib
    hardware_rtc
    PicoTM1637
)

pico_add_extra_outputs(pico_7seg_clock_v2)
pico_enable_stdio_usb(pico_7seg_clock_v2 1)
pico_enable_stdio_uart(pico_7seg_clock_v2 0)