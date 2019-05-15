
#include <stdlib.h>
#include <stdio.h>
#include "module_wire.h"
#include "ast_helper.h"

module_wire *create_module_wire(char *identifier) {
    module_wire *result = malloc(sizeof(module_wire));
    result->identifier = identifier;
    return result;
}

void print_module_wire(module_wire *module_wire, int indent) {
    print_indent(indent);
    printf("module_wire(identifier=%s)\n", module_wire->identifier);
}
