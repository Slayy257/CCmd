#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "command.h"

// commands
bool cmd_exit(error* err);
bool cmd_version(error* err);
bool cmd_clear(error* err);

void set_err(error* err, const char* name, int errcode) {
    _snprintf_s(err->message, sizeof(err->message), MAX_BUFFER_SIZE, name);
    err->errcode = 1;
}

// init command to struct
void init_commands(cmd* cmd) {
    cmd->exit = cmd_exit;
    cmd->version = cmd_version;
    cmd->clear = cmd_clear;
}

bool cmd_exit(error* err) {
    set_err(err, "exit", 1);
    exit(0);
    return true;
}

bool cmd_version(error* err) {
    set_err(err, "version", 2);
    puts("v1.0.0");
    return true;
}

bool cmd_clear(error* err) {

#if defined(WIN32)
    set_err(err, "cls system failed.", 4);
    if (system("cls") == -1)
        return false;
#elif defined(UNIX)
    set_err(err, "clear system failed.", 4);
    if (system("clear") == -1)
        return false;
#endif

    return true;
}

bool cmd_get(error* err, char args[]) {
    set_err(err, "get", 3);
    
}