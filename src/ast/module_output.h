
#ifndef HARDWARE_SIM_MODULE_OUTPUT_H
#define HARDWARE_SIM_MODULE_OUTPUT_H

typedef struct _module_output {
    char *identifier;
    struct _module_output *next;
} module_output;

module_output *create_module_output(char *identifier);
void print_module_output(module_output *module_output, int indent);

#endif
