#include "monty.h"

void process_line(char *line, stack_t **stack, unsigned int line_number) {
    // Split the line into tokens
    char *token = strtok(line, " \t\n");

    // Ignore blank lines and comments
    if (token == NULL || token[0] == '#') {
        return;
    }

    // Implement your logic to process the line here
    // You can access the tokens using 'token' variable

    // Example: Push operation
    if (strcmp(token, "push") == 0) {
        token = strtok(NULL, " \t\n");
        if (token == NULL) {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        int value = atoi(token);
        // Add the value to the stack
        // ...
    }
    // Example: Pop operation
    else if (strcmp(token, "pop") == 0) {
        // Remove the top element from the stack
        // ...
    }
    // Example: Add operation
    else if (strcmp(token, "add") == 0) {
        // Perform addition on the top two elements of the stack
        // ...
    }
    // Handle other operations
    // ...

    // If the token doesn't match any operation, print an error message
    else {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
        exit(EXIT_FAILURE);
    }
}
