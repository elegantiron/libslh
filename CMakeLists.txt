cmake_minimum_required(VERSION 3.30)
project(
    libslh
    VERSION 0.0.1
    LANGUAGES CXX
)
include(FetchContent)
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.91.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
    
)
FetchContent_Declare(
    imgui-sfml
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml
    GIT_TAG v3.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(
    imgui
)
set(IMGUI_DIR ${imgui_SOURCE_DIR})
set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_makeAvailable(imgui-sfml)
add_library(${PROJECT_NAME})
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    OUTPUT_NAME "slh"
)
target_compile_features(
    ${PROJECT_NAME}
    PRIVATE
    cxx_std_23
)
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/inc-priv"
)
find_package(Boost 1.83 COMPONENTS locale REQUIRED)
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    SFML::Graphics
    Boost::locale
    ImGui-SFML::ImGui-SFML
)
target_sources(
    ${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Clock.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Core.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/SceneManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Types/Font.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Menu.cpp"
)
find_package(Doxygen)
if(Doxygen_FOUND)
    set(DOXYGEN_PROJECT_NAME ${PROJECT_NAME})
    set(DOXYGEN_PROJECT_NUMBER ${PROJECT_VERSION})
    set(DOXYGEN_CREATE_SUBDIRS YES)
    set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
    set(DOXYGEN_TIMESTAMP YES)
    set(DOXYGEN_SORT_MEMBER_DOCS YES)
    set(DOXYGEN_SORT_MEMBERS_CTORS_1ST YES)
    set(DOXYGEN_SORT_BRIEF_DOCS YES)
    set(DOXYGEN_SHOW_HEADERFILE YES)
    set(DOXYGEN_STRIP_FROM_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/inc)
    doxygen_add_docs(
        ${PROJECT_NAME}_docs
    )
endif()