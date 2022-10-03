#define ARGS_H
#ifdef ARGS_H

#define MAX_BUFFER_SIZE 128

typedef struct {
    size_t size;
    char** data;
} args_t;

void push_args(args_t* args, const char* arg);
void free_arg(args_t* args);

#endif ARGS_H