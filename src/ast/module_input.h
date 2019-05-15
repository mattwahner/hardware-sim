
#ifndef HARDWARE_SIM_MODULE_INPUT_H
#define HARDWARE_SIM_MODULE_INPUT_H

typedef struct _module_input {
    char *identifier;
    int vector_size;
    struct _module_input *next;
} module_input;

module_input *create_module_input(char *identifier);
module_input *create_vectored_module_input(char *identifier, int vector_size);
void print_module_input(module_input *module_input, int indent);

#endif
