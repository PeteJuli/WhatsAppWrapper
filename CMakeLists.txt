cmake_minimum_required(VERSION 3.10)
project(WhatsAppWrapper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)

pkg_check_modules(WEBVIEW_DEPS REQUIRED 
    gtk+-3.0 
    webkit2gtk-4.1
)

add_executable(${PROJECT_NAME} SRC/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/SDK/webview
    ${WEBVIEW_DEPS_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${WEBVIEW_DEPS_LIBRARIES}
)

target_compile_options(${PROJECT_NAME} PRIVATE 
    ${WEBVIEW_DEPS_CFLAGS_OTHER}
)