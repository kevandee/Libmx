#include "../inc/libmx.h"

char *mx_file_to_str(const char *filename) {
	if (filename == NULL) {
		return NULL;
	}

	int fd = open(filename, O_RDONLY);

	if (fd < 0) {
		return NULL;
	}

	unsigned int count = 0;
	char buf;

	while ((read(fd, &buf, 1)) > 0) {
		count++;
	}

	close(fd);
	char *result_str = mx_strnew(count);
	fd = open(filename, O_RDONLY);
	int i = 0;

	while ((read(fd, &buf, 1)) > 0) {
		result_str[i] = buf;
		i++;
	}

	close(fd);

	return result_str;
}

