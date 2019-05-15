
#ifndef HARDWARE_SIM_MODULE_INTERNAL_H
#define HARDWARE_SIM_MODULE_INTERNAL_H

#include "module_wire.h"
#include "module_instance.h"

typedef enum {
    MODULE_WIRE,
    MODULE_INSTANCE
} module_internal_type;

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

#endif
