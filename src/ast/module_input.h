
#ifndef HARDWARE_SIM_MODULE_INPUT_H
#define HARDWARE_SIM_MODULE_INPUT_H

typedef struct _module_input {
    char *identifier;
    struct _module_input *next;
} module_input;

module_input *create_module_input(char *identifier);
void print_module_input(module_input *module_input, int indent);

#endif
