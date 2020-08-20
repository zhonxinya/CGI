# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (cgi)
aux_source_directory(. DIR_SRCS)
# 添加头文件路径
include_directories(
    "${PROJECT_SOURCE_DIR}/inc"
    "src/module/Error"
    "src/module/FManager"
    "src/module/Handler"
    "src/module/Log"
    "src/module/Pro"
    "src/module/SData"
    "src/module/SocketDao"
    "src/module/TaskManager"
    "src/init"
)
# 添加 math 子目录
add_subdirectory(src/init)
add_subdirectory(src/module)

# 指定生成目标
add_executable(cgi main.c)
# 添加链接库
target_link_libraries(cgi module  init pthread)





