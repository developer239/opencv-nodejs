cmake_minimum_required(VERSION 3.9)
cmake_policy(SET CMP0042 NEW)
set(CMAKE_CXX_STANDARD 11)

project(opencv-nodejs)

# Find pkg_search_module
find_package(PkgConfig REQUIRED)

include_directories(${CMAKE_JS_INC})
file(GLOB SOURCE_FILES "src/main.cpp")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC}
        src/core/Point.cpp
        src/core/Point.h
        src/core/Rect.cpp
        src/core/Rect.h
        src/core/RotatedRect.cpp
        src/core/RotatedRect.h
        src/core/Size.cpp
        src/core/Size.h
        src/core/Vec.cpp
        src/core/Vec.h
        )

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})

# Include Node-API wrappers
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REGEX REPLACE "[\r\n\"]" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})

# Find OpenCV
find_package(OpenCV REQUIRED)
target_link_libraries(${PROJECT_NAME}
        "-framework Carbon"
        )
target_link_libraries(${PROJECT_NAME}
        ${OpenCV_LIBS}
        )

# define NPI_VERSION
add_definitions(-DNAPI_VERSION=3)
