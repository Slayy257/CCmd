#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "args.h"

args_t* new_args() {
    args_t* args = malloc(sizeof(args_t));
    args->size = 0;
    args->data = NULL;

    return args;
}

void push_args(args_t* args, const char* arg) {
    args->size++;
    int* alloc = realloc(args->data, args->size * MAX_BUFFER_SIZE);
    if (!alloc) { perror("Failed Argument Allocation"); return; }
    else args->data = alloc;
    args->data[args->size -  1] = arg;
}

void free_arg(args_t* args) {
    free(args->data);
    free(args);
}