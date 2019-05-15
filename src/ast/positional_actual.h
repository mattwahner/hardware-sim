
#ifndef HARDWARE_SIM_POSITIONAL_ACTUAL_H
#define HARDWARE_SIM_POSITIONAL_ACTUAL_H

typedef struct {
    char *identifier;
} positional_actual;

positional_actual *create_positional_actual(char *identifier);
void print_positional_actual(positional_actual *positional_actual, int indent);

#endif
