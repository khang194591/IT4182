#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFF_SIZE 200

#define MAX_LENGTH 20000

#define null NULL

int compare(char *a, char *b) {
	return strcmp(a, b);
}

void string_to_lower(char *string) {
	for (size_t i = 0; i < strlen(string); ++i) {
		string[i] = tolower(string[i]);
	}
}

int is_ignore(char ignores[MAX_LENGTH][BUFF_SIZE], int length, char *key) {
	for (int i = 0; i < length; ++i) {
		if (strcmp(ignores[i], key) == 0) {
			return 1;
		}
	}
	return 0;
}

// Chương trình nhận 2 tham số là file text và tham số thứ 2 là file các từ bỏ qua
int main(int argc, char const *argv[]) {

	FILE *file_text = fopen(argv[1], "r");
	FILE *file_ignore = fopen(argv[2], "r");

	if (argc != 3 || !file_text) {
		printf("Invalid argument");
		return 1;
	}

	const char delim[] = " ,()0123456789`';-:\"\n\r";

	char words[MAX_LENGTH][BUFF_SIZE];
	char ignores[MAX_LENGTH][BUFF_SIZE];
	char buff[BUFF_SIZE];
	char *token = null;

	int ignore_index = 0;
	int word_index = 1;
	int line_index = 1;
	int is_first = 1;

	while (fgets(buff, BUFF_SIZE, file_ignore) != null) {
		snprintf(ignores[ignore_index++], strlen(buff) - 1, "%s", buff);
	}

	while (fgets(buff, BUFF_SIZE, file_text) != null) {
		int len = strlen(words[word_index - 1]) - 1;
		token = strtok(buff, delim);
		if (token != null && strcmp(token, ".") != 0) {
			if (is_first && !is_ignore(ignores, ignore_index, token)) {
				string_to_lower(token);
				sprintf(words[word_index++], "%s", token);
				is_first = 0;
			}
			if (isupper(token[0])) {
				if (words[word_index - 1][len] == '.') {
					words[word_index - 1][len] = '\0';
				} else {
				}
			} else if (!is_ignore(ignores, ignore_index, token)) {
				string_to_lower(token);
				sprintf(words[word_index++], "%s", token);
			}
		}
		while (token != null) {
			len = strlen(words[word_index - 1]) - 1;
			token = strtok(null, delim);
			if (token != null && strcmp(token, ".") != 0) {
				if (isupper(token[0])) {
					if (words[word_index - 1][len] == '.') {
						words[word_index - 1][len] = '\0';
					} else {
					}
				} else if (!is_ignore(ignores, ignore_index, token)) {
					string_to_lower(token);
					sprintf(words[word_index++], "%s", token);
				}
			}
		}
		line_index++;
	}

	words[word_index - 1][strlen(words[word_index - 1]) - 1] = '\0';

	for (int i = 0; i < word_index; ++i) {
		printf("%s\n", words[i]);
	}

	fclose(file_text);

	return 0;
}
