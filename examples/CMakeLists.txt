add_library(pi MODULE pi.c)
add_library(picpp MODULE pi.cpp)

install(FILES pi.c pi.cpp CMakeLists.txt
	DESTINATION share/spitz)

add_custom_target(test-pi-c
	${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 $<TARGET_FILE:spitz-bin> $<TARGET_FILE:pi> 10000
	DEPENDS spitz-bin pi)

add_custom_target(test-pi-cpp
	${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 $<TARGET_FILE:spitz-bin> $<TARGET_FILE:picpp> 10000
	DEPENDS spitz-bin picpp)
