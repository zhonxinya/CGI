#ifndef _FILE_M_H_
#define _FILE_M_H_
 int get_file_size_by_stat(const char *file);
 int get_file_size_by_lstat(const char *file);
 int get_file_size_by_fstat(const char *file);
 int get_file_size_by_lseek(const char *file);
 int get_file_size_by_fseek_and_ftell(const char *file);
 int shell_cmd_excute(const char *cmd, char *result, int size);
 int get_file_size_by_shell_cmd(const char *file);
#endif