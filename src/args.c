#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "args.h"

void push_args(args_t* args, const char* arg) {

    if (sizeof(args) == 0) {
        puts("arg null");
        args_t* arg_;
        arg_->size = 1;
        arg_->data = malloc(args->size * sizeof(char[MAX_ARG_BUFFER_SIZE]));
        arg_->data[args->size] = arg;
        args = arg_;
        free(arg_);
    }

    printf("size = %i\n", args->size);
    char* data = args->data; // backup data
    args->size += 1;
    args->data = realloc(args->data, args->size * sizeof(char[MAX_ARG_BUFFER_SIZE]));
    args->data = data;
    args->data[args->size] = arg;
}