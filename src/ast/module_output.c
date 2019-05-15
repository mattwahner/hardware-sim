
#include <stdlib.h>
#include <stdio.h>
#include "module_output.h"
#include "ast_helper.h"

static module_output *create_base_module_output(char *identifier) {
    module_output *result = malloc(sizeof(module_output));
    result->identifier = identifier;
    result->next = NULL;
    return result;
}

module_output *create_module_output(char *identifier) {
    module_output *result = create_base_module_output(identifier);
    result->vector_size = 1;
    return result;
}

module_output *create_vectored_module_output(char *identifier, int vector_size) {
    module_output *result = create_base_module_output(identifier);
    result->vector_size = vector_size;
    return result;
}

void print_module_output(module_output *module_output, int indent) {
    print_indent(indent);
    printf("module_output(identifier=%s, vector_size=%d)\n", module_output->identifier, module_output->vector_size);
    if (module_output->next != NULL)
        print_module_output(module_output->next, indent);
}
