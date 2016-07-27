#get all files in the source directory
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*c)

#separete the file names
get_filename_component(TRGT ${SOURCES} NAME_WE)

#---------------------------------------------------------------
#---------------------------------------------------------------
#---------------------------------------------------------------
#all depends on TRGT.o and TRGT.ll, thus it will compile both of them

add_custom_target(${TRGT} ALL
	DEPENDS ${TRGT}.o ${TRGT}.ll
	COMMAND ${CMAKE_C_COMPILER} build/objs/${TRGT}.o -o ${TRGT}
	)

# creates TRGT.o
add_custom_command(OUTPUT ${TRGT}.o
	COMMAND mkdir -p build/objs
	COMMAND ${CMAKE_C_COMPILER} 
		-c ${CMAKE_CURRENT_SOURCE_DIR}/src/${TRGT}.c 
		-o build/objs/${TRGT}.o
	)

#creates TRGT.ll
add_custom_command(OUTPUT ${TRGT}.ll
	COMMAND echo ${TRGT} aaaaaaaaaaaaaa
	COMMAND mkdir -p build/ir
	COMMAND ${CMAKE_C_COMPILER}
		-S -emmit-llvm 
		${CMAKE_CURRENT_SOURCE_DIR}/src/${TRGT}.c 
		-o build/ir/${TRGT}.ll
	)