
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include <string.h>

// ======================================================================
//  Symbol Table
// ======================================================================

char *copy_identifier(char *identifier) {
    char *result = malloc(strlen(identifier) + 1);
    strcpy(result, identifier);
    return result;
}

// ======================================================================
// AST
// ======================================================================

static void print_indent(int indent) {
    for (int i = 0; i < indent; i++)
        printf(" ");
}

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

module_wire *create_module_wire(char *identifier) {
    module_wire *result = malloc(sizeof(module_wire));
    result->identifier = identifier;
    return result;
}

void print_module_wire(module_wire *module_wire, int indent) {
    print_indent(indent);
    printf("module_wire(identifier=%s)\n", module_wire->identifier);
}

actual *create_actual(char *identifier) {
    actual *result = malloc(sizeof(actual));
    result->identifier = identifier;
    return result;
}

void print_actual(actual *actual, int indent) {
    print_indent(indent);
    printf("actual(identifier=%s)\n", actual->identifier);
    if (actual->next != NULL)
        print_actual(actual->next, indent);
}

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

module_internal *create_module_internal_from_wire(module_wire *module_wire) {
    module_internal *result = malloc(sizeof(module_internal));
    result->type = MODULE_WIRE;
    result->module_wire = module_wire;
    result->next = NULL;
    return result;
}
module_internal *create_module_internal_from_instance(module_instance *module_instance) {
    module_internal *result = malloc(sizeof(module_internal));
    result->type = MODULE_INSTANCE;
    result->module_instance = module_instance;
    result->next = NULL;
    return result;
}

void print_module_internal(module_internal *module_internal, int indent) {
    switch (module_internal->type) {
        case MODULE_WIRE:
            print_module_wire(module_internal->module_wire, indent);
            break;
        case MODULE_INSTANCE:
            print_module_instance(module_internal->module_instance, indent);
            break;
    }
    if (module_internal->next != NULL)
        print_module_internal(module_internal->next, indent);
}

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
    print_module_input(module_body->module_inputs, indent + 4);
    print_module_output(module_body->module_outputs, indent + 4);
    print_module_internal(module_body->module_internals, indent + 4);
}

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

