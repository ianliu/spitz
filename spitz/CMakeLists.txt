include_directories(${MPI_INCLUDE_PATH})

add_library(spitz barray.c spitz.c)

add_executable(spitz-bin
	main.c cfifo.c log.c jobmanager.c message.c)
set_target_properties(spitz-bin PROPERTIES OUTPUT_NAME spitz)
target_link_libraries(spitz-bin spitz dl rt Threads::Threads
	${MPI_LIBRARIES})
set_target_properties(spitz-bin PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
set_target_properties(spitz-bin PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")


install(TARGETS spitz DESTINATION lib)
install(TARGETS spitz-bin DESTINATION bin)
install(FILES barray.h spitz.h stream.hpp spitz.hpp
	DESTINATION include)
