#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "command.h"

error process_buffer(args_t* buffer);
void log_error(error err);
void print_headers();

cmd g_cmd;

int main(void) {

    print_headers();
    init_commands(&g_cmd);

    while (1) {
        char buffer[MAX_BUFFER_SIZE];
        int rc = getline("> ", buffer, sizeof(buffer));

        if (rc == 2) {
            puts("Your input is too long.");
        }
        else if (rc == 1) {
            puts("No input received.");
        }
        else {
            //error output = process_buffer(buffer);
            args_t* args = get_args(buffer);
            error output = process_buffer(args);
        }
    }

    puts("Bye :)");
    return 0;
}

error process_buffer(args_t* args) { 

    error err;

    // todo -> pass args in arg to function to free them afterwards

    try {
        if (strcmp(args->data[0], "exit") == 0)
            if (!exec_cmd(g_cmd.exit, &err, args))
                throw();

        if (strcmp(args->data[0], "version") == 0)
            if (!exec_cmd(g_cmd.version, &err, args))
                throw();

        if (strcmp(args->data[0], "clear") == 0)
            if (!exec_cmd(g_cmd.clear, &err, args))
                throw();
        
        if (strcmp(args->data[0], "get") == 0)
            if (!exec_cmd(g_cmd.get, &err, args))
                throw();

    }
    catch (...) {
        log_error(err);
    }

    return err;
}

void log_error(error err) {
    printf("\nError Thrown: %s\nError Code: %i\n", err.message, err.errcode);
}

void print_headers() {
    puts("C Command Line Interface");
    puts("copyright@MBS Corporation");
    printf("\n");
}