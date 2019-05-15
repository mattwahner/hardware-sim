
#ifndef HARDWARE_SIM_ACTUAL_H
#define HARDWARE_SIM_ACTUAL_H

#include "positional_actual.h"
#include "keyword_actual.h"

typedef enum {
    POSITIONAL_ACTUAL,
    KEYWORD_ACTUAL
} actual_type;

typedef struct _actual {
    actual_type type;
    union {
        positional_actual *positional_actual;
        keyword_actual *keyword_actual;
    };
    struct _actual *next;
} actual;

actual *create_actual_from_positional_actual(positional_actual *positional_actual);
actual *create_actual_from_keyword_actual(keyword_actual *keyword_actual);
void print_actual(actual *actual, int indent);

#endif
