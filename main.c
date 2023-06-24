#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "monty.h"

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    size_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;
        process_line(line, &stack, line_number);
    }

    free_stack(stack);
    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}
