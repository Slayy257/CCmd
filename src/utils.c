#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "utils.h"

bool debug_mode = false;

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

bool exec_cmd(bool function(error*, args_t*), error* err, args_t* args) {
    bool result = true;
    if (!function(err, args)) result = false;


    if (debug_mode) {
        printf("[");

        for (int i = 0; i < args->size; i++) {
            if (i == args->size - 1)
                printf(" %s ", args->data[i]);
            else
                printf(" %s,", args->data[i]);
        }

        printf("]\n");
    }

    free_arg(args);

    return result;
}

args_t* get_args(char *buffer)
{
    args_t* args = malloc(sizeof(args_t));
    args->size = 0;
    args->data = NULL;
    char word[MAX_BUFFER_SIZE] = "";
    int currIndex = 0;

    for (int i = 0; i < strlen(buffer); i++) {
        if (!isspace(buffer[i])) {
            if (i == strlen(buffer) - 1) {
                word[currIndex] = buffer[i];
                goto pa;
            }

            word[currIndex] = buffer[i];
            currIndex++;
        }
        else {
pa:
            if (currIndex != 0) {
                push_args(args, _strdup(word));
                memset(word, 0, sizeof word);
                currIndex = 0;
            }
        }
    }

    return args;
}