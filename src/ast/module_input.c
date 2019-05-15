
#include <stdlib.h>
#include <stdio.h>
#include "module_input.h"
#include "ast_helper.h"

module_input *create_module_input(char *identifier) {
    module_input *result = malloc(sizeof(module_input));
    result->identifier = identifier;
    result->next = NULL;
    return result;
}

void print_module_input(module_input *module_input, int indent) {
    print_indent(indent);
    printf("module_input(identifier=%s)\n", module_input->identifier);
    if (module_input->next != NULL)
        print_module_input(module_input->next, indent);
}

