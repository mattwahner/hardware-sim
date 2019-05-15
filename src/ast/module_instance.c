
#include <stdlib.h>
#include <stdio.h>
#include "module_instance.h"
#include "ast_helper.h"

module_instance *create_module_instance(char *type, char *identifier, actual *actuals) {
    module_instance *result = malloc(sizeof(module_instance));
    result->type = type;
    result->identifier = identifier;
    result->actuals = actuals;
    return result;
}

void print_module_instance(module_instance *module_instance, int indent) {
    print_indent(indent);
    printf("module_instance(type=%s, identifier=%s)\n",
           module_instance->type, module_instance->identifier);
    if (module_instance->actuals != NULL)
        print_actual(module_instance->actuals, indent + 4);
}
