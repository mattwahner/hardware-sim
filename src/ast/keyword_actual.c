
#include <stdlib.h>
#include <stdio.h>
#include "keyword_actual.h"
#include "ast_helper.h"

keyword_actual *create_keyword_actual(char *to_identifier, char *from_identifier) {
    keyword_actual *result = malloc(sizeof(keyword_actual));
    result->to_identifier = to_identifier;
    result->from_identifier = from_identifier;
    return result;
}

void print_keyword_actual(keyword_actual *keyword_actual, int indent) {
    print_indent(indent);
    printf("keyword_actual(to_identifier=%s, from_identifier=%s)\n",
            keyword_actual->to_identifier,
            keyword_actual->from_identifier);
}
