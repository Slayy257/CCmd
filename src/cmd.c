#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "command.h"

error_t process_buffer(args_t* buffer);
void log_error(error_t err);
void print_headers();

cmd g_cmd;

int main(int argc, char** argv) {

    print_headers();
    init_commands(&g_cmd);

    if (argc > 0)
        for (int i = 0; i < argc; i++)
            if (cmp(argv[i], "-d"))
                debug_mode = true;

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
            args_t* args = get_args(buffer);

            if (debug_mode)
                dbg(args);
                
            error_t output = process_buffer(args);
        }
    }
    
    return 0;
}

error_t process_buffer(args_t* args) { 
    error_t err;

    try {
        if (cmp(args->data[0], "exit"))
            if (!exec_cmd(g_cmd.exit, &err, args))
                throw();

        if (cmp(args->data[0], "version"))
            if (!exec_cmd(g_cmd.version, &err, args))
                throw();

        if (cmp(args->data[0], "clear"))
            if (!exec_cmd(g_cmd.clear, &err, args))
                throw();
        
        if (cmp(args->data[0], "get"))
            if (!exec_cmd(g_cmd.get, &err, args))
                throw();

    }
    catch (...) {
        log_error(err);
    }

    return err;
}

void log_error(error_t err) {
    printf("\nError Thrown: %s\nError Code: %i\n", err.message, err.errcode);
}

void print_headers() {
    puts("C Command Line Interface");
    puts("copyright@MBS Corporation");
    printf("\n");
}