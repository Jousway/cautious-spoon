set(GLEW_SRC 
	"src/glew.c"
	"src/glewinfo.c"
	"src/visualinfo.c"
)

source_group("" FILES ${GLEW_SRC})

add_library(glew STATIC ${GLEW_SRC})

target_compile_definitions(glew PUBLIC GLEW_STATIC)

target_include_directories(glew PUBLIC
	"${SPN_LIB}/glew/include"
)
