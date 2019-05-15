
#ifndef HARDWARE_SIM_MODULE_WIRE_H
#define HARDWARE_SIM_MODULE_WIRE_H

typedef struct {
    char *identifier;
    int vector_size;
} module_wire;

module_wire *create_module_wire(char *identifier);
module_wire *create_vectored_module_wire(char *identifier, int vector_size);
void print_module_wire(module_wire *module_wire, int indent);

#endif
