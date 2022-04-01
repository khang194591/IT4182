#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFF_SIZE 200

#define MAX_LENGTH 10000

int compare(char *a, char *b)
{
    return strcmp(a, b);
}

int main(int argc, char const *argv[])
{
    FILE *file_text = fopen(argv[1], "r");

    char buff[BUFF_SIZE];
    char buff_2[BUFF_SIZE];
    char words[MAX_LENGTH][BUFF_SIZE];
    int lines[MAX_LENGTH][100];
    int line_length[MAX_LENGTH];

    int line = 0;
    int word_count = 0;

    while (fgets(buff, BUFF_SIZE, file_text) != NULL)
    {
        line++;
        int first = 0;
        int last = 0;

        char word[BUFF_SIZE];

        for (int i = 0; i <= strlen(buff); ++i)
        {
            if (isalpha(buff[i]) == isalpha(buff[i + 1]))
            {
                last = i + 1;
            }
            else
            {
                if (isalpha(buff[i]) && !isalpha(buff[i + 1]))
                {
                    if (last < first)
                    {
                        last = first;
                    }

                    memcpy(word, buff + first, last - first + 1);

                    for (size_t i = 0; i < strlen(word); i++)
                    {
                        word[i] = tolower(word[i]);
                    }

                    word[last - first + 1] = '\0';

                    int found = 0;

                    for (size_t j = 0; j < word_count; j++)
                    {
                        if (strcmp(word, words[j]) == 0)
                        {
                            found = 1;
                            lines[j][line_length[j]++] = line;
                        }
                    }

                    if (found == 0)
                    {
                        strcpy(words[word_count], word);
                        line_length[word_count] = 0;
                        lines[word_count][line_length[word_count]++] = line;
                        word_count++;
                    }
                }
                else
                {
                    first = i + 1;
                }
            }
        }
    }

    // qsort(words, word_count, BUFF_SIZE, compare);

    for (size_t i = 0; i < word_count; i++)
    {
        printf("%s ", words[i]);
        for (size_t j = 0; j < line_length[i]; j++)
        {
            printf(" %d ", lines[i][j]);
        }
        printf("\n");
    }

    return 0;
}
