cmake_minimum_required(VERSION 3.30)
project(
    libslh
    VERSION 0.0.1
    LANGUAGES CXX
)
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
)
target_sources(
    ${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Clock.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Core.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/SceneManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Menu.cpp"
)
find_package(Doxygen)