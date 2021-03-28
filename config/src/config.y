
%{

#define YY_NO_UNPUT
#define YY_NO_WRAP
#define YYERROR_VERBOSE 1
#define YYDEBUG 1

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <config.tab.h>
#include <config.h>

void yyerror(YYLTYPE* loc, void* scanner, const char* msg);

%}

%locations
%pure-parser
%define parse.error verbose
%define parse.lac full
%define parse.trace true

%lex-param {void* scanner} 

%parse-param {void* scanner}

%union { char* str; }
%token <str> STRING

%union { double num; }
%token <num> NUMBER

%token BLOPEN

%token BLCLOSE

%destructor { free($$); $$ = 0; } <str>

%start input

%%

key_value: