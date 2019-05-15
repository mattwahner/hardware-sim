
#include <stdlib.h>
#include <stdio.h>
#include "module_body.h"
#include "ast_helper.h"

module_body *create_module_body(module_input *module_inputs, module_output *module_outputs, module_internal *module_internals) {
    module_body *result = malloc(sizeof(module_body));
    result->module_inputs = module_inputs;
    result->module_outputs = module_outputs;
    result->module_internals = module_internals;
    return result;
}

void print_module_body(module_body *module_body, int indent) {
    print_indent(indent);
    printf("module_body\n");
    if (module_body->module_inputs != NULL)
        print_module_input(module_body->module_inputs, indent + 4);
    if (module_body->module_outputs != NULL)
        print_module_output(module_body->module_outputs, indent + 4);
    if (module_body->module_internals != NULL)
        print_module_internal(module_body->module_internals, indent + 4);
}
