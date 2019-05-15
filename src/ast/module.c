
#include <stdlib.h>
#include <stdio.h>
#include "module.h"
#include "ast_helper.h"

module *create_module(char *identifier, module_body *module_body) {
    module *result = malloc(sizeof(module));
    result->identifier = identifier;
    result->module_body = module_body;
    result->next = NULL;
    return result;
}

void print_module(module *module, int indent) {
    print_indent(indent);
    printf("module(identifier=%s)\n", module->identifier);
    print_module_body(module->module_body, indent + 4);
}
