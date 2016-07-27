CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(My_Doc_My_Hell)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
	if(CMAKE_C_COMPILER_VERSION VERSION_LESS 5.3.0)
		message(FATAL_ERROR "GCC should be version 5.3.0 or greater, alterado")
	endif()
else()
	message(FATAL_ERROR "Use GCC as C complimer")
endif()

#add_subdirectory(passes)
add_subdirectory(tests)
