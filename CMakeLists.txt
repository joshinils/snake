cmake_minimum_required(VERSION 3.10)
project("snake")

set(CMAKE_CXX_STANDARD 11)

if(UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -fpermissive")
elseif(MSVC)
	# suppress warning about unknown options -pthread and -fpermissive
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif(UNIX)

add_executable("${PROJECT_NAME}" 
	"main.cpp"
	"Aether.h"
	"Aether.cpp"
	"pge.cpp"
	"olcPixelGameEngine/olcPixelGameEngine.h"
	"Graph.h"
	"Graph.cpp"
	"Vertex.h"
	"Vertex.cpp"
	"Snake.h"
	"Snake.cpp"
	"Snek.h"
	"Snek.cpp"
	"Limb.h"
	"Limb.cpp"
)

include_directories(olcPixelGameEngine)


# set the startup project in visual studio, such that it is not ALL_BUILD and annoying
if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")
	set(CMAKE_CONFIGURATION_TYPES "Release;Debug;MinSizeRel;RelWithDebInfo")
endif(MSVC)

#jnl delete this if not needed, i dont need it for msvc
if(UNIX)
  find_package (PkgConfig REQUIRED)
endif(UNIX)

find_package (OpenGL REQUIRED)
#find_package (GLUT REQUIRED)


if(UNIX)
	include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
endif(UNIX)

file(GLOB SOURCE_FILES
    *.cpp
    *.h
)

if(UNIX)
	target_link_libraries ("${PROJECT_NAME}" 
	${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} GL m dl Xinerama Xrandr Xi Xcursor X11 Xxf86vm pthread png)
endif(UNIX)