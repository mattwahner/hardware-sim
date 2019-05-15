
#ifndef HARDWARE_SIM_MODULE_WIRE_H
#define HARDWARE_SIM_MODULE_WIRE_H

typedef struct {
    char *identifier;
} module_wire;

module_wire *create_module_wire(char *identifier);
void print_module_wire(module_wire *module_wire, int indent);

#endif
