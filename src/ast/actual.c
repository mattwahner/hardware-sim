
#include <stdlib.h>
#include <stdio.h>
#include "actual.h"
#include "ast_helper.h"

actual *create_actual(char *identifier) {
    actual *result = malloc(sizeof(actual));
    result->identifier = identifier;
    return result;
}

void print_actual(actual *actual, int indent) {
    print_indent(indent);
    printf("actual(identifier=%s)\n", actual->identifier);
    if (actual->next != NULL)
        print_actual(actual->next, indent);
}
