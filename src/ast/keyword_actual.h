
#ifndef HARDWARE_SIM_KEYWORD_ACTUAL_H
#define HARDWARE_SIM_KEYWORD_ACTUAL_H

typedef struct {
    char *to_identifier;
    char *from_identifier;
} keyword_actual;

keyword_actual *create_keyword_actual(char *to_identifier, char *from_identifier);
void print_keyword_actual(keyword_actual *keyword_actual, int indent);

#endif
