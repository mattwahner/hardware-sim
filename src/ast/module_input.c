
#include <stdlib.h>
#include <stdio.h>
#include "module_input.h"
#include "ast_helper.h"

static module_input *create_base_module_input(char *identifier) {
    module_input *result = malloc(sizeof(module_input));
    result->identifier = identifier;
    result->next = NULL;
    return result;
}

module_input *create_module_input(char *identifier) {
    module_input *result = create_base_module_input(identifier);
    result->vector_size = 1;
    return result;
}

module_input *create_vectored_module_input(char *identifier, int vector_size) {
    module_input *result = create_base_module_input(identifier);
    result->vector_size = vector_size;
    return result;
}

void print_module_input(module_input *module_input, int indent) {
    print_indent(indent);
    printf("module_input(identifier=%s, vector_size=%d)\n", module_input->identifier, module_input->vector_size);
    if (module_input->next != NULL)
        print_module_input(module_input->next, indent);
}

