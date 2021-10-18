#include "../inc/libmx.h"
#include <stdio.h>

char *mx_strtrim(const char *str) {
	if (!str) {
		return NULL;
	}

	int length = mx_strlen(str);
	int end = length;
	int left_count = 0;
	int right_count = 0;

	while (mx_isspace(str[left_count])) {
		left_count++;
	}

	while (mx_isspace(str[end - 1])) {
		right_count++;
		end--;
	}

	printf("%i %i\n", left_count, right_count);
	char *temp_str = mx_strnew(length - left_count - right_count);
	
	return mx_strncpy(temp_str, str + left_count, length - left_count - right_count);
}

