#define COMMAND_H
#ifdef COMMAND_H

#include "utils.h"

#define try bool __HadError=false;
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) {__HadError=true;goto ExitJmp;}

typedef struct {
    bool (*exit)(error_t *err, args_t *args);
    bool (*version)(error_t *err, args_t *args);
    bool (*clear)(error_t *err, args_t *args);
    bool (*get)(error_t *err, args_t *args);
} cmd;

void init_commands(cmd* cmd);

#endif COMMAND_H