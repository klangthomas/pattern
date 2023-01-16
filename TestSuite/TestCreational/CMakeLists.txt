cmake_minimum_required(VERSION 3.16)
cmake_policy(VERSION 3.12)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake) # main (top) cmake dir
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake) # project specific cmake dir

string(COMPARE EQUAL "${PROJECT_NAME}" "" _have_project_name)
if(_have_project_name)
    
    message(STATUS "Top level CMakeLists")

endif()

project(TestCreational VERSION 0.1)

option(BUILD_DOC "Build the documentation (Requires doxygen)" OFF)

if (BUILD_DOC)
    include(DoxygenTarget)

    find_package(Doxygen REQUIRED dot
        OPTIONAL_COMPONENTS mscgen dia)
    if (DOXYGEN_FOUND)
        PrepareDocTarget()
    else (DOXYGEN_FOUND)
        message("Doxygen need to be installed to generate the doxygen documentation")
    endif (DOXYGEN_FOUND)
endif(BUILD_DOC)

juce_add_console_app(${PROJECT_NAME} PRODUCT_NAME "TestCreational")

target_sources(${PROJECT_NAME} PRIVATE 
    ../src/main.cpp
    ../src/logger_spd_juce.h)

CPMAddPackage(
    NAME JUCE
    GITHUB_REPOSITORY juce-framework/JUCE
    GIT_TAG origin/master)

CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    VERSION 1.8.2
)

CPMAddPackage(
    NAME Catch2
    GITHUB_REPOSITORY catchorg/Catch2
    VERSION 2.13.4)

target_compile_definitions(${PROJECT_NAME} PRIVATE DUMP_STORAGE="${CMAKE_CURRENT_SOURCE_DIR}/..")

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        UNIT_TEST=1)

# Linking needs to be PRIVATE for some important reasons!
# JUCE's CMAKE API.md:615-619
target_link_libraries(${PROJECT_NAME} PRIVATE
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
        juce::juce_core
        
        spdlog::spdlog
        Catch2

        pattern_base
        pattern_creational
        )

option(CODE_COVERAGE_BASE "Run the test with code coverage utiliy" OFF)
if(CODE_COVERAGE_BASE)
    include(${PROJECT_SOURCE_DIR}/../../cmake/CodeCoverage.cmake)

    append_coverage_compiler_flags()
    setup_target_for_coverage_lcov(
        NAME ${PROJECT_NAME}_lcov
        EXECUTABLE ${PROJECT_NAME}
        BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/../../modules/*"
        EXCLUDE "/usr/include/*" "${PROJECT_SOURCE_DIR}/../../_deps/*"
    )

    setup_target_for_coverage_gcovr_xml(
        NAME ${PROJECT_NAME}_xmlCov
        EXECUTABLE ${PROJECT_NAME}
        BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/../../modules/*"
        EXCLUDE "/usr/include/*" "${PROJECT_SOURCE_DIR}/../../_deps/*"
    )
endif(CODE_COVERAGE_BASE)