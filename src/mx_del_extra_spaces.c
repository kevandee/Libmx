#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	
	char *tr_str = mx_strtrim(str);
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (mx_isspace(tr_str[i])
		&& !mx_isspace(tr_str[i + 1])) {
			length++;
		}
		else if (!mx_isspace(tr_str[i])) {
			length++;
		}
	}

	char *temp_str = mx_strnew(length);
	
	int j = 0;
	for (int i = 0; tr_str[i] != '\0'; i++) {
		if(!mx_isspace(tr_str[i])) {
			temp_str[j] = tr_str[i];
			j++;
		}

		if(mx_isspace(tr_str[i]) && !mx_isspace(tr_str[i + 1])) {
			temp_str[j] = ' ';
			j++;
		}
	}

	mx_strdel(&tr_str);

	return temp_str;
}

