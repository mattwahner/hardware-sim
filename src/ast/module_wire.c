
#include <stdlib.h>
#include <stdio.h>
#include "module_wire.h"
#include "ast_helper.h"

static module_wire *create_base_module_wire(char *identifier) {
    module_wire *result = malloc(sizeof(module_wire));
    result->identifier = identifier;
    return result;
}

module_wire *create_module_wire(char *identifier) {
    module_wire *result = create_base_module_wire(identifier);
    result->vector_size = 1;
    return result;
}

module_wire *create_vectored_module_wire(char *identifier, int vector_size) {
    module_wire *result = create_base_module_wire(identifier);
    result->vector_size = vector_size;
    return result;
}

void print_module_wire(module_wire *module_wire, int indent) {
    print_indent(indent);
    printf("module_wire(identifier=%s, vector_size=%d)\n", module_wire->identifier, module_wire->vector_size);
}
