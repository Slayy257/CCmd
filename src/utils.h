#define UTILS_H
#ifdef UTILS_H

#include "args.h"

typedef struct {
    int errcode;
    char message[MAX_BUFFER_SIZE];
} error;

extern bool debug_mode;
int getline(const char *msg, char *buff, int len);
args_t* get_args(char* buffer);
bool exec_cmd(bool function(error*, args_t*), error* err, args_t* args);

#endif UTILS_H