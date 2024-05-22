%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void yyerror(const char *s);
char *to_lower(char *str);
%}

%{
#define PLURAL_FLAG 1
%}

alpha [A-Za-z]
digit [0-9]

%%
[\t\n\r ]+                      ; // Ignore whitespace

[bB][iI][rR][dD][sS]            { yylval.number = PLURAL_FLAG; return BIRD; }
[bB][iI][rR][dD]                { yylval.number = 0; return BIRD; }
[dD][oO][gG][sS]                { yylval.number = PLURAL_FLAG; return DOG; }
[dD][oO][gG]                    { yylval.number = 0; return DOG; }

[bB][iI][rR][dD][iI][eE][sS]    { yylval.number = PLURAL_FLAG; return BIRDIE; }
[bB][iI][rR][dD][iI][eE]        { yylval.number = 0; return BIRDIE; }
[bB][iI][rR][dD][yY][sS]        { yylval.number = PLURAL_FLAG; return BIRDY; }
[bB][iI][rR][dD][yY]            { yylval.number = 0; return BIRDY; }

[bB][iI][gG][bB][iI][rR][dD][sS] { yylval.number = PLURAL_FLAG; return BIGBIRD; }
[bB][iI][gG][bB][iI][rR][dD]     { yylval.number = 0; return BIGBIRD; }

"-"                             { return DASH; }
"!"                             { return EXCLAMATION; }
{alpha}({alpha}|{digit})*       { yylval.str = strdup(to_lower(yytext)); return WORD; }
.                                { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}

char *to_lower(char *str) {
    char *lower_str = strdup(str);
    for (int i = 0; lower_str[i]; i++) {
        lower_str[i] = tolower(lower_str[i]);
    }
    return lower_str;
}
