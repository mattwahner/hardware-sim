
%option noyywrap

%{
#include <stdio.h>
#define YY_DECL int yylex()
#include "ast/ast.h"
#include "hardware-sim.tab.h"
%}

%%

[ \r\n\t]                   ;
\-?[0-9]+                   { yylval.int_value = atoi(yytext); return T_NUMBER; }
"module"                    { return T_MODULE; }
"combinational"             { return T_COMBINATIONAL; }
"input"                     { return T_INPUT; }
"output"                    { return T_OUTPUT; }
"wire"                      { return T_WIRE; }
"assert"                    { return T_ASSERT; }
"testcase"                  { return T_TESTCASE; }
"{"                         { return T_LEFT_CURLY; }
"}"                         { return T_RIGHT_CURLY; }
"["                         { return T_LEFT_BRACKET; }
"]"                         { return T_RIGHT_BRACKET; }
"("                         { return T_LEFT_PARENS; }
")"                         { return T_RIGHT_PARENS; }
";"                         { return T_SEMICOLON; }
"="                         { return T_ASSIGN; }
"=="                        { return T_EQUALS; }
"&"                         { return T_AND; }
","                         { return T_COMMA; }
[a-zA-Z]*                   { yylval.char_value = copy_identifier(yytext); return T_IDENTIFIER; }
.                           { printf("Unexpected character: %s\n", yytext); exit(0); }

%%

