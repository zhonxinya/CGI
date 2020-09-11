#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
 int get_file_size_by_stat(const char *file)
{
	int ret;
	struct stat file_info;
	ret = stat(file, &file_info);
	
	return (!ret) ? file_info.st_size : -1;
}
 
// call lstat() function
 int get_file_size_by_lstat(const char *file)
{
	int ret;
	struct stat file_info;
	ret = lstat(file, &file_info);
	
	return (!ret) ? file_info.st_size : -1;
}
 
// call fstat() function
 int get_file_size_by_fstat(const char *file)
{
	int ret;
	int fd;
	struct stat file_info;
	fd = open(file, O_RDONLY);
	if (fd < 0) {
		ret = -1;
		perror("open error");
		goto exit_entry;
	}
	
	ret = fstat(fd, &file_info);
	
exit_entry:
	if (fd >= 0) {
		close(fd);
	}
	return (!ret) ? file_info.st_size : -1;
}
 
// call lseek() function
 int get_file_size_by_lseek(const char *file)
{
	int ret;
	int fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0) {
		ret = -1;
		perror("open error");
		goto exit_entry;
	}
	
	ret = lseek(fd, 0, SEEK_END);
	
exit_entry:
	if (fd >= 0) {
		close(fd);
	}
	return ret;
}
 
// call fseek() and ftell() function
 int get_file_size_by_fseek_and_ftell(const char *file)
{
	int ret;
	FILE *fp;
	
	fp = fopen(file, "r");
	if (!fp) {
		ret = -1;
		perror("fopen error");
		goto exit_entry;
	}
	
	ret = fseek(fp, 0, SEEK_END);
	if (ret < 0) {
		ret = -1;
		perror("fseek error");
		goto exit_entry;	
	}
	
	ret = ftell(fp);
	
exit_entry:
	if (fp) {
		fclose(fp);
	}
	return ret;
}
 
 int shell_cmd_excute(const char *cmd, char *result, int size)
{
	int ret;
	FILE *fp;
	
	fp = popen(cmd, "r");
	if (!fp) {
		ret = -1;
		perror("popen error");
		goto exit_entry;
	}
	
	ret = fread(result, 1, size, fp);
	if (ret < 0) {
		ret = -1;
		perror("fseek error");
		goto exit_entry;	
	}
	
	ret = 0;
exit_entry:
	if (fp) {
		pclose(fp);
	}
	return ret;
}
 
// call shell cmd
 int get_file_size_by_shell_cmd(const char *file)
{
	int ret;
	char cmd[128];
	char result[16];
	
	snprintf(cmd, sizeof(cmd), "ls -al %s | awk '{print $5}'", file);
	
	ret = shell_cmd_excute(cmd, result, sizeof(result));
	if (!ret && strlen(result)) {
		ret = atoi(result);
	}
	
	return ret;
}