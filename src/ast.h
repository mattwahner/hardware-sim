
#ifndef AST_H
#define AST_H

// ======================================================================
//  Symbol Table
// ======================================================================

char *copy_identifier(char *identifier);

// ======================================================================
// AST
// ======================================================================

typedef struct _module_input {
    char *identifier;
    struct _module_input *next;
} module_input;

module_input *create_module_input(char *identifier);
void print_module_input(module_input *module_input, int indent);

typedef struct _module_output {
    char *identifier;
    struct _module_output *next;
} module_output;

module_output *create_module_output(char *identifier);
void print_module_output(module_output *module_output, int indent);

typedef enum {
    MODULE_WIRE,
    MODULE_INSTANCE
} module_internal_type;

typedef struct {
    char *identifier;
} module_wire;

module_wire *create_module_wire(char *identifier);
void print_module_wire(module_wire *module_wire, int indent);

typedef struct _actual {
    char *identifier;
    struct _actual *next;
} actual;

actual *create_actual(char *identifier);
void print_actual(actual *actual, int indent);

typedef struct {
    char *type;
    char *identifier;
    actual *actuals;
} module_instance;

module_instance *create_module_instance(char *type, char *identifier, actual *actuals);
void print_module_instance(module_instance *module_instance, int indent);

typedef struct _module_internal {
    module_internal_type type;
    union {
        module_wire *module_wire;
        module_instance *module_instance;
    };
    struct _module_internal *next;
} module_internal;

module_internal *create_module_internal_from_wire(module_wire *module_wire);
module_internal *create_module_internal_from_instance(module_instance *module_instance);
void print_module_internal(module_internal *module_internal, int indent);

typedef struct {
    module_input *module_inputs;
    module_output *module_outputs;
    module_internal *module_internals;
} module_body;

module_body *create_module_body(module_input *module_inputs, module_output *module_outputs, module_internal *module_internals);
void print_module_body(module_body *module_body, int indent);

typedef struct _module {
    char *identifier;
    module_body *module_body;
    struct _module *next;
} module;

module *create_module(char *identifier, module_body *module_body);
void print_module(module *module, int indent);

#endif

