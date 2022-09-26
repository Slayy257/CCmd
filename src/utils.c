#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "utils.h"
#include "args.h"

int getline(const char *msg, char *buff, int len)
{
    if (msg != NULL)
    {
        printf("%s", msg);
        fflush(stdout);
    }

    if (fgets(buff, len, stdin) == NULL || strcmp(buff, "\n") == 0)
    {
        return 1;
    }
    else if (buff[strlen(buff) - 1] != '\n')
    {
        return 2;
    }
    else
    {
        buff[strlen(buff) - 1] = '\0';
        return 0;
    }
}

char *getargs(char *buffer)
{
    args_t* args = malloc(sizeof(args_t));
    args->size = 0;
    args->data = NULL;
    char word[MAX_ARG_BUFFER_SIZE] = "";
    int currIndex = 0;

    for (int i = 0; i < strlen(buffer); i++) {
        if (!isspace(buffer[i])) {
            word[currIndex] = buffer[i];
            currIndex++;
        }
        else {
            push_args(args, word);
            sprintf_s(word, MAX_ARG_BUFFER_SIZE, "");
            currIndex = 0;
        }
    }

    printf("[");
    for (int i = 0; i < args->size; i++)
    {
        if (i == args->size - 1)
            printf(" %s ", args->data[i]);
        else {
            printf(" %s,", args->data[i]);
        }
    }

    printf("]");

    char* datas = args->data;
    free(args->data);
    free(args);

    return datas;
}