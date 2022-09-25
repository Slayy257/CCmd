#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "command.h"
#include "utils.h"

error process_buffer(char *buffer);
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
            char* args = getargs(buffer);

            for (int i = 0; i < sizeof(args); i++) {
                puts(args[i]);
            }
        }
    }

    puts("Bye :)");
    return 0;
}

error process_buffer(char *buffer) {

    error err;

    try {
        if (strcmp(buffer, "exit") == 0)
             if (!g_cmd.exit(&err))
                throw();

        if (strcmp(buffer, "version") == 0)
            if (!g_cmd.version(&err))
                throw();

        if (strcmp(buffer, "clear") == 0)
            if (!g_cmd.clear(&err))
                throw();
        
        if (strcmp(buffer, "get") == 0) {

        }
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