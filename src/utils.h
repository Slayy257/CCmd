#define UTILS_H
#ifdef UTILS_H

#include "args.h"

int getline(const char *msg, char *buff, int len);
args_t* getargs(char* buffer);

#endif UTILS_H