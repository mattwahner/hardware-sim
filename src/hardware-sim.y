
%{

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ast/ast.h"

extern int yylex();
extern int yyparse(module **root_module);
extern FILE *yyin;

void yyerror(module **root_module, const char *s);

%}

%parse-param {module **root_module}

%union {
    int int_value;
    char *char_value;
    module *module;
    module_body *module_body;
    module_input *module_input;
    module_output *module_output;
    module_internal *module_internal;
    module_wire *module_wire;
    module_instance *module_instance;
    actual *actual;
}

%token<int_value> T_NUMBER
%token T_MODULE
%token T_COMBINATIONAL
%token T_INPUT
%token T_OUTPUT
%token T_WIRE
%token T_ASSERT
%token T_TESTCASE
%token T_LEFT_CURLY T_RIGHT_CURLY
%token T_LEFT_BRACKET T_RIGHT_BRACKET
%token T_LEFT_PARENS T_RIGHT_PARENS
%token T_SEMICOLON
%token T_ASSIGN
%token T_EQUALS
%token T_AND
%token T_COMMA
%token<char_value> T_IDENTIFIER

%type<module> modules
%type<module> module
%type<module_body> module_body
%type<module_input> module_inputs
%type<module_input> module_input
%type<module_output> module_outputs
%type<module_output> module_output
%type<module_internal> module_internals
%type<module_internal> module_internal
%type<module_wire> module_wire
%type<module_instance> module_instance
%type<actual> actual_list
%type<actual> actual

%start modules

%%

modules: module modules {
    $1->next = $2;
    $$ = $1;
} | %empty {
    $$ = NULL;
};

module: T_MODULE T_IDENTIFIER T_LEFT_CURLY module_body T_RIGHT_CURLY {
    module *result = create_module($2, $4);
    *root_module = result;
    $$ = result;
};

module_body: module_inputs module_outputs module_internals {
    $$ = create_module_body($1, $2, $3);
};

module_inputs: module_input module_inputs {
    $1->next = $2;
    $$ = $1;
} | %empty {
    $$ = NULL;
};

module_input: T_INPUT T_IDENTIFIER T_SEMICOLON {
    $$ = create_module_input($2);
};

module_outputs: module_output module_outputs {
    $1->next = $2;
    $$ = $1;
} | %empty {
    $$ = NULL;
};

module_output: T_OUTPUT T_IDENTIFIER T_SEMICOLON {
    $$ = create_module_output($2);
};

module_internals: module_internal module_internals {
    $1->next = $2;
    $$ = $1;
} | %empty {
    $$ = NULL;
};

module_internal: module_wire {
    $$ = create_module_internal_from_wire($1);
} | module_instance {
    $$ = create_module_internal_from_instance($1);
};

module_wire: T_WIRE T_IDENTIFIER T_SEMICOLON {
    $$ = create_module_wire($2);
};

module_instance: T_IDENTIFIER T_IDENTIFIER T_LEFT_PARENS T_RIGHT_PARENS T_SEMICOLON {
    $$ = create_module_instance($1, $2, NULL);
} | T_IDENTIFIER T_IDENTIFIER T_LEFT_PARENS actual_list T_RIGHT_PARENS T_SEMICOLON {
    $$ = create_module_instance($1, $2, $4);
};

actual_list: actual T_COMMA actual_list {
    $1->next = $3;
    $$ = $1;
} | actual {
    $$ = $1;
};

actual: T_IDENTIFIER {
    $$ = create_actual($1);
};

/*

module_blocks: module_blocks module_block
             | %empty;

module_block: combination_block
            | testcase_block;

combination_block: T_COMBINATIONAL T_LEFT_CURLY combination_block_body T_RIGHT_CURLY;

combination_block_body: assignments;

assignments: assignment assignments
           | %empty;

assignment: T_IDENTIFIER T_ASSIGN expression;

expression: T_IDENTIFIER T_AND T_IDENTIFIER;

testcase_block: T_TESTCASE T_LEFT_CURLY testcase_block_body T_RIGHT_CURLY;

testcase_block_body: givens_list assert_list;

givens_list: given givens_list
           | %empty;

given: T_IDENTIFIER T_ASSIGN T_NUMBER;

assert_list: assert assert_list
           | %empty;

assert: T_ASSERT T_IDENTIFIER T_EQUALS T_NUMBER;

*/

%%

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Must provide input file!\n");
        exit(0);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open file!\n");
        exit(0);
    }

    yyin = fp;
    
    module *module;
    yyparse(&module);

    print_module(module, 0);

    return 0;
}

void yyerror(module **module, const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    exit(1);
}

