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
find_package(SFML 3.0 COMPONENTS Graphics CONFIG REQUIRED)
find_package(SFGUI CONFIG REQUIRED)
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    SFML::Graphics
    SFGUI::SFGUI
    Boost::locale
)
find_package(Boost 1.83 COMPONENTS serialization)
if(boost_serialization_FOUND)
    message(STATUS "Found boost-serialization")
    target_link_libraries(
        ${PROJECT_NAME}
        PUBLIC
        Boost::serialization
    )
    target_compile_definitions(
        ${PROJECT_NAME}
        PUBLIC
        -DLIBSLH_USE_BOOST
        )
endif()
target_sources(
    ${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Clock.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/Core.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/SceneManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/WindowManager.cpp"
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