cmake_minimum_required(VERSION 3.16)
cmake_policy(VERSION 3.12)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake) # project specific cmake dir

set(CPM_DOWNLOAD_VERSION 0.31.1) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
else(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message("CPM was not downloaded")
endif(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))

include(${CPM_DOWNLOAD_LOCATION})

if( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
    set( CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install/" CACHE PATH "Install prefix" FORCE )
endif( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )

project(PatternCleanCoding)

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

#Compile commands, useful for some IDEs like VS-Code
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

#static linking in Windows
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

#Adds all the module sources so they appear correctly in the IDE
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)

#set any of these to "ON" if you want to build one of the juce examples
#or extras (Projucer/AudioPluginHost, etc):
set_property(GLOBAL PROPERTY JUCE_BUILD_EXTRAS OFF)
set_property(GLOBAL PROPERTY JUCE_BUILD_EXAMPLES OFF)

#Fetching JUCE from git
#IF you want to instead point it to a local version, you can invoke CMake with
#-DCPM_JUCE_SOURCE="Path_To_JUCE"
CPMAddPackage(
    NAME JUCE
    GITHUB_REPOSITORY juce-framework/JUCE
    GIT_TAG origin/master)

CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    VERSION 1.8.2)

set_property(GLOBAL PROPERTY CXX_STANDARD 17)

add_subdirectory(modules)
add_subdirectory(TestSuite)

install(FILES "README.md" DESTINATION bin)

if (BUILD_DOC)
    install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doc" DESTINATION "documentation")
    install(FILES ${CMAKE_CURRENT_LIST_DIR}/install_files/documentation.html DESTINATION bin)
endif (BUILD_DOC)
