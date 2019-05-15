
#ifndef HARDWARE_SIM_MODULE_BODY_H
#define HARDWARE_SIM_MODULE_BODY_H

#include "module_input.h"
#include "module_output.h"
#include "module_internal.h"

typedef struct {
    module_input *module_inputs;
    module_output *module_outputs;
    module_internal *module_internals;
} module_body;

module_body *create_module_body(module_input *module_inputs, module_output *module_outputs, module_internal *module_internals);
void print_module_body(module_body *module_body, int indent);

#endif
