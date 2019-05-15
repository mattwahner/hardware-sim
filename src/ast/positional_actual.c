
#include <stdlib.h>
#include <stdio.h>
#include "positional_actual.h"
#include "ast_helper.h"

positional_actual *create_positional_actual(char *identifier) {
    positional_actual *result = malloc(sizeof(positional_actual));
    result->identifier = identifier;
    return result;
}

void print_positional_actual(positional_actual *positional_actual, int indent) {
    print_indent(indent);
    printf("positional_actual(identifier=%s)\n", positional_actual->identifier);
}
