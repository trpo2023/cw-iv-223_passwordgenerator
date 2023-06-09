#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100

void print_help() {
	printf("Usage: pwgen [OPTION] [pw_length] [number_of_pw]\n");
	printf("Options:\n");
	printf("--0, —no-number : Generated password will not contain numbers\n");
	printf("-1 : Output each generated password on a separate line\n");
	printf("-A, —no-capitalize : Generated password will not contain capital letters\n");
	printf("-a, —no-lowercase : Generated password will not contain lowercase letters\n");
	printf("-c, —capitalize : Include at least one capital letter in the password\n");
	printf("-C : Output generated passwords in columns\n");
	printf("-n, —number : Include at least one digit in the password\n");
	printf("-h, —help : Print this help message\n");
	printf("-y, —symbols : Include at least one special symbol in the password\n");
}

int main(int argc, char *argv[]) {
	int pw_length = 0;
	int number_of_pw = 1;
	int include_numbers = 1;
	int include_lowercase = 1;
	int include_capitalize = 0;
	int include_symbols = 0;
	int output_columns = 0;

	int i = 1;
	while (i < argc) {
		if (strcmp(argv[i], "--0") == 0 || strcmp(argv[i], "--no-number") == 0) {
			include_numbers = 0;
		} else if (strcmp(argv[i], "-1") == 0) {
			output_columns = 0;
		} else if (strcmp(argv[i], "-A") == 0 || strcmp(argv[i], "--no-capitalize") == 0) {
			include_capitalize = 0;
		} else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--no-lowercase") == 0) {
			include_lowercase = 0;
		} else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--capitalize") == 0) {
			include_capitalize = 1;
		} else if (strcmp(argv[i], "-C") == 0) {
			output_columns = 1;
		} else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--number") == 0) {
			include_numbers = 1;
		} else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
			print_help();
			return 0;
		} else if (strcmp(argv[i], "-y") == 0 || strcmp(argv[i], "--symbols") == 0) {
			include_symbols = 1;
		} else {
			int arg_value = atoi(argv[i]);
		if (arg_value > 0) {
			if (pw_length == 0) {
				pw_length = arg_value;
			} else {
				number_of_pw = arg_value;
			}
		} else {
			printf("Invalid argument: %s\n", argv[i]);
			return 1;
		}
		}	
		i++;
	}	

	const char lowercase_charset[] = "abcdefghijklmnopqrstuvwxyz";
	const char uppercase_charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char numbers_charset[] = "0123456789";
	const char symbols_charset[] = "!@#$%^&*()_+=-{}[]\\|:;<>,.?/~";

	char charset[MAX_PASSWORD_LENGTH + 1] = { 0 };
	size_t charset_length = 0;

	if (include_lowercase) {
		strcat(charset, lowercase_charset);
		charset_length += strlen(lowercase_charset);
	}
	if (include_capitalize) {
		strcat(charset, uppercase_charset);
		charset_length += strlen(uppercase_charset);
	}
	if (include_numbers) {
		strcat(charset, numbers_charset);
		charset_length += strlen(numbers_charset);
	}
	if (include_symbols) {
		strcat(charset, symbols_charset);
		charset_length += strlen(symbols_charset);
	}

	if (charset_length == 0) {
		printf("Password cannot be generated with the specified options.\n");
		return 1;
	}

	char password[MAX_PASSWORD_LENGTH + 1];

	srand(time(NULL));

	if (output_columns) {
		int total_pw_length = pw_length * number_of_pw;
		if (total_pw_length > MAX_PASSWORD_LENGTH) {
			printf("Total password length exceeds the maximum limit.\n");
			return 1;
		}

		for (int i = 0; i < number_of_pw; ++i) {
			int start = i * pw_length;
			for (int j = 0; j < pw_length; ++j) {
				int charset_index = rand() % charset_length;
				password[start + j] = charset[charset_index];
			}
		}

	password[total_pw_length] = '\0';

	int start = 0;
	for (int i = 0; i < number_of_pw; ++i) {
		printf("%s\t", password + start);
		start += pw_length;
	}
	printf("\n");
	} else {
		for (int i = 0; i < number_of_pw; ++i) {
			for (int j = 0; j < pw_length; ++j) {
				int charset_index = rand() % charset_length;
					password[j] = charset[charset_index];
			}

		password[pw_length] = '\0';
		printf("%s\n", password);
		}
	}

	return 0;
}