
#ifndef HARDWARE_SIM_MODULE_H
#define HARDWARE_SIM_MODULE_H

#include "module_body.h"

typedef struct _module {
    char *identifier;
    module_body *module_body;
    struct _module *next;
} module;

module *create_module(char *identifier, module_body *module_body);
void name_analyze_module(module *module);
void print_module(module *module, int indent);

#endif
