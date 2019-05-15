
#ifndef HARDWARE_SIM_MODULE_OUTPUT_H
#define HARDWARE_SIM_MODULE_OUTPUT_H

typedef struct _module_output {
    char *identifier;
    int vector_size;
    struct _module_output *next;
} module_output;

module_output *create_module_output(char *identifier);
module_output *create_vectored_module_output(char *identifier, int vector_size);
void print_module_output(module_output *module_output, int indent);

#endif
