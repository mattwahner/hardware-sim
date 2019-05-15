
#ifndef HARDWARE_SIM_ACTUAL_H
#define HARDWARE_SIM_ACTUAL_H

typedef struct _actual {
    char *identifier;
    struct _actual *next;
} actual;

actual *create_actual(char *identifier);
void print_actual(actual *actual, int indent);

#endif
