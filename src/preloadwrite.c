
#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>
#include <unistd.h>


ssize_t (*__fn_orig_write)(int fd, const void *buf, size_t count);

ssize_t write(int fd, const void *buf, size_t count) {
	char message[32];
	ssize_t write_count = 0;

	__fn_orig_write = (ssize_t (*)(int fd, const void *buf, size_t count)) dlsym(RTLD_NEXT, "write");

	if(fd == 1) {
		strncpy(message, "Hello world\n", sizeof(message));
		__fn_orig_write(fd, message, strlen(message));
	}

	write_count += __fn_orig_write(fd, buf, count);

	if(fd == 1) {
		strncpy(message, "Goodbye cruel world\n", sizeof(message));
		__fn_orig_write(fd, message, strlen(message));
	}

	return write_count;
}

