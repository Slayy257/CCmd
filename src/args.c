#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "args.h"

void push_args(args_t* args, char* arg) {
    args->size++;
    args->data = (char*)realloc(args->data, args->size * sizeof(char[MAX_ARG_BUFFER_SIZE]));
    args->data[args->size -  1] = arg;
}