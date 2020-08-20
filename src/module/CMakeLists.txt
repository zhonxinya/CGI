# aux_source_directory(Error l1)
# aux_source_directory(FManager l2)
# aux_source_directory(Handler l3)
aux_source_directory(Log l4)
aux_source_directory(Pro l5)
aux_source_directory(SocketDao l6)
aux_source_directory(SData l7)
aux_source_directory(TaskManager l8)
# 生成链接库
add_library( module  ${l8} ${l7} ${l6} ${l4} ${l5})
target_link_libraries(module pthread)

