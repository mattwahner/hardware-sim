
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast_helper.h"

char *copy_identifier(char *identifier) {
    char *result = malloc(strlen(identifier) + 1);
    strcpy(result, identifier);
    return result;
}

void print_indent(int indent) {
    for (int i = 0; i < indent; i++)
        printf(" ");
}
