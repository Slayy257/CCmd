#define ARGS_H
#ifdef ARGS_H

#define MAX_ARG_BUFFER_SIZE 32

typedef struct {
    size_t size;
    char** data;
} args_t;

void push_args(args_t* args, char* arg);

#endif ARGS_H