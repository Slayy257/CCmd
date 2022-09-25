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
    args_t* args;
    char *word = "";

    for (int i = 0; i < strlen(buffer); i++)
    {
        if (isspace(buffer[i]) != 0) {
            puts("buffer != 0");
            i++;
            puts("push arg");
            push_args(args, word);
            word = "";
            puts("arg pushed");
            continue;
        }
        else {
            word += buffer[i];
            continue;
        }

        puts("arg pushed");
        puts("word");
    }

    for (int i = 0; i < args->size; i++)
    {
        printf("%s", args->data[i]);
    }

    char* datas = args->data;
    free(args->data);
    free(args);

    return datas;
}