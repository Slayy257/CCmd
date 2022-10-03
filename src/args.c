#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "args.h"

void push_args(args_t* args, const char* arg) {
    args->size++;
    args->data = realloc(args->data, args->size * MAX_BUFFER_SIZE);
    args->data[args->size -  1] = arg;
}

void free_arg(args_t* args) {
    free(args->data);
    free(args);
}