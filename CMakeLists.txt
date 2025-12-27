cmake_minimum_required(VERSION 3.16)
project(bluetoothqt VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets Bluetooth REQUIRED)

qt_standard_project_setup()

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/bluetoothqt.ui
    src/bluetoothqt.cpp
    src/device/device.cpp
    resources/icons.qrc
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Bluetooth
)
