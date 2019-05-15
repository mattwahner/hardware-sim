
#ifndef HARDWARE_SIM_MODULE_INSTANCE_H
#define HARDWARE_SIM_MODULE_INSTANCE_H

#include "actual.h"

typedef struct {
    char *type;
    char *identifier;
    actual *actuals;
} module_instance;

module_instance *create_module_instance(char *type, char *identifier, actual *actuals);
void print_module_instance(module_instance *module_instance, int indent);

#endif
