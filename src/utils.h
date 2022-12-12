#define UTILS_H
#ifdef UTILS_H

#include "args.h"

#define cmp(x, y) !strcmp(x, y)

typedef struct {
    int errcode;
    char message[MAX_BUFFER_SIZE];
} error_t;

extern bool debug_mode;
int getline(const char *msg, char *buff, int len);
args_t* get_args(char* buffer);
bool exec_cmd(bool function(error_t*, args_t*), error_t* err, args_t* args);
void dbg(args_t* args);

#endif UTILS_H