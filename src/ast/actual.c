
#include <stdlib.h>
#include <stdio.h>
#include "actual.h"
#include "positional_actual.h"
#include "keyword_actual.h"
#include "ast_helper.h"

actual *create_actual_from_positional_actual(positional_actual *positional_actual) {
    actual *result = malloc(sizeof(actual));
    result->type = POSITIONAL_ACTUAL;
    result->positional_actual = positional_actual;
    return result;
}

actual *create_actual_from_keyword_actual(keyword_actual *keyword_actual) {
    actual *result = malloc(sizeof(actual));
    result->type = KEYWORD_ACTUAL;
    result->keyword_actual = keyword_actual;
    return result;
}

void print_actual(actual *actual, int indent) {
    switch (actual->type) {
        case POSITIONAL_ACTUAL:
            print_positional_actual(actual->positional_actual, indent);
            break;
        case KEYWORD_ACTUAL:
            print_keyword_actual(actual->keyword_actual, indent);
            break;
    }
    if (actual->next != NULL)
        print_actual(actual->next, indent);
}
