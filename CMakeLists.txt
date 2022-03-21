cmake_minimum_required(VERSION 3.5)

project(poefx VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)
link_directories(${PROJECT_SOURCE_DIR}/hp)


add_executable(poefx
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        CBuffer.h
        CBuffer.cpp
        lua/aa.h
        hp/SocketInterface.h
        hp/HPTypeDef.h
        hp/framework.h
        hp/HPSocket.h
        Struct.h
        Struct.cpp
)

target_link_libraries(poefx PRIVATE HPSocket_D)
target_link_libraries(poefx PRIVATE Qt6::Widgets)
target_link_libraries(poefx PRIVATE Qt6::Network)

target_compile_definitions(poefx PRIVATE HPSOCKET_STATIC_LIB)
