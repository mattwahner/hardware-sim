
#include <stdlib.h>
#include <stdio.h>
#include "module_output.h"
#include "ast_helper.h"

module_output *create_module_output(char *identifier) {
    module_output *result = malloc(sizeof(module_output));
    result->identifier = identifier;
    result->next = NULL;
    return result;
}

void print_module_output(module_output *module_output, int indent) {
    print_indent(indent);
    printf("module_output(identifier=%s)\n", module_output->identifier);
    if (module_output->next != NULL)
        print_module_output(module_output->next, indent);
}
