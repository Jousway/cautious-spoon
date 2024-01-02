list(APPEND SPN_MAIN
	#Source
	"Main.cpp"
	"Quad.cpp"
	"Settings.cpp"

	#Headers
	"Main.hpp"
	"Quad.hpp"
	"Settings.hpp"
)

source_group("" FILES ${SPN_MAIN})

#Main CMake

add_executable(${PROJECT_NAME}
	${SPN_MAIN}
)

target_link_libraries(${PROJECT_NAME} 
	${OPENGL_LIBRARIES}
	glfw
)

target_include_directories(${PROJECT_NAME} PUBLIC
	"${SPN_LIB}/include"
	"${SPN_LIB}/glfw/include"
)

set_target_properties(${PROJECT_NAME} PROPERTIES 
	RUNTIME_OUTPUT_DIRECTORY "${SPN_TOPDIR}"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${SPN_TOPDIR}"
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${SPN_TOPDIR}"
	RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${SPN_TOPDIR}"
	RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${SPN_TOPDIR}"
)
