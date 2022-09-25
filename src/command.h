#define COMMAND_H
#ifdef COMMAND_H

#define try bool __HadError=false;
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) {__HadError=true;goto ExitJmp;}
#define MAX_BUFFER_SIZE 128

typedef struct {
    int errcode;
    char message[MAX_BUFFER_SIZE];
} error;

typedef struct {
    bool (*exit)(error *err);
    bool (*version)(error *err);
    bool (*clear)(error *err);
    bool (*get)(error *err, char args[]);
} cmd;

void init_commands(cmd* cmd);

#endif COMMAND_H