
aux_source_directory(. DIR_LIB_SRCS)
add_library (init ${DIR_LIB_SRCS})
target_link_libraries(init module pthread)