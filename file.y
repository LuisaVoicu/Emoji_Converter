%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
void print_emoji(const char *emoji, int count);
%}

%union {
    char *str;
    int number;
}

%token <number> BIRD BIRDIE BIRDY BIGBIRD DOG
%token DASH EXCLAMATION
%token <str> WORD

%%

poem:
    lines
    ;

lines:
    line '\n' lines
    | line
    ;

line:
    words
    ;

words:
    word words
    | word
    ;

word:
    BIRD       { print_emoji("🐦", $1); }
    | BIRDIE    { print_emoji("🐦🤏", $1); }
    | BIRDY     { print_emoji("🐦🤏", $1); }
    | BIGBIRD   { print_emoji("🐦💪", $1); }
    | DOG       { print_emoji("🐶", $1); }
    | DASH          { printf("- "); }
    | EXCLAMATION   { printf("! "); }
    | WORD          { printf("%s ", $1); free($1); }
    ;

%%

#include "lex.yy.c"

int main() {
    return yyparse();
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

void print_emoji(const char *emoji, int count) {
    int repeat = (count == PLURAL_FLAG) ? 2 : 1;
    for (int i = 0; i < repeat; i++) {
        printf("%s ", emoji);
    }
}
