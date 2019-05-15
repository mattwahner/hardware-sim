
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "module.h"
#include "ast_helper.h"

module *create_module(char *identifier, module_body *module_body) {
    module *result = malloc(sizeof(module));
    result->identifier = identifier;
    result->module_body = module_body;
    result->next = NULL;
    return result;
}

static void check_duplicate_module_names(module *this) {
    module *curr = this->next;
    while (curr != NULL) {
        if (strcmp(this->identifier, curr->identifier) == 0) {
            printf("Duplicate module identifier: %s\n", this->identifier);
            exit(0);
        }
        curr = curr->next;
    }
}

void name_analyze_module(module *module) {
    check_duplicate_module_names(module);
    if (module->next != NULL)
        name_analyze_module(module->next);
}

void print_module(module *module, int indent) {
    print_indent(indent);
    printf("module(identifier=%s)\n", module->identifier);
    print_module_body(module->module_body, indent + 4);
    if (module->next != NULL)
        print_module(module->next, indent);
}
