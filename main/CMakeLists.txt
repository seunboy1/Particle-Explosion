set(BINARY ${CMAKE_PROJECT_NAME})

file (GLOB_RECURSE SOURCES *.h *.cpp)

# find_package searches for .cmake files using 2 mode, either Module mode(FindXXX.cmake) in CMAKE_MODULE_PATH 
# or  Config mode(XXXConfig.cmake) in CMAKE_PREFIX_PATH which defines _INCLUDE_DIRS and _LIBRARIES variables
 
find_package(JNI REQUIRED)
find_package(OpenCV REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${JNI_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})

set(LIBS ${JNI_LIBRARIES} ${OpenCV_LIBS}  ${SDL2_LIBRARIES})

add_executable(${BINARY}_exe ${SOURCES})
target_link_libraries(${BINARY}_exe ${LIBS})