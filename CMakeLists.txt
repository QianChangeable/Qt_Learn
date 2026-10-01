cmake_minimum_required(VERSION 3.21)
project(HelloQt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
# 生成 compile_commands.json，让 Cursor/VS Code 能找到 Qt 头文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 使用 Qt 5.15.2
find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(HELLOQT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    widgets/titlebar.cpp
    widgets/titlebar.h
    widgets/activitybar.cpp
    widgets/activitybar.h
    widgets/sidebar.cpp
    widgets/sidebar.h
    widgets/contentarea.cpp
    widgets/contentarea.h
    widgets/statusbar.cpp
    widgets/statusbar.h
)

if(APPLE)
    enable_language(OBJCXX)
    list(APPEND HELLOQT_SOURCES
        platform/macos_window.mm
        platform/macos_window.h
    )
endif()

add_executable(HelloQt ${HELLOQT_SOURCES})
target_link_libraries(HelloQt PRIVATE Qt5::Widgets)

if(APPLE)
    target_link_libraries(HelloQt PRIVATE "-framework AppKit")
endif()

if(WIN32)
    set_target_properties(HelloQt PROPERTIES WIN32_EXECUTABLE TRUE)
endif()
