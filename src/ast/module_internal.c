
#include <stdlib.h>
#include "module_internal.h"

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
