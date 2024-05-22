%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}


%{
#define PLURAL_FLAG 1
#define HAS_SUBJECT_FLAG 2
#define HAS_ADJECTIVE_FLAG 4
#define HAS_VERB_FLAG 8
#define HAS_ADVERB_FLAG 16


typedef struct {
    char *key;
    int token;
} synonym_t;

synonym_t synonyms[] = {
    {"sparrow", BIRD},
    {"canine", DOG},
    {"kitty", CAT},
    {NULL, 0}
};

int flags = 0; 

int get_main_token(const char *word) {
    for (int i = 0; synonyms[i].key != NULL; i++) {
        if (strcmp(synonyms[i].key, word) == 0) {
            return synonyms[i].token;
        }
    }
    return 0;
}

%}

alpha [A-Za-z]
digit [0-9]


%%

[\t\n\r ]+                      ; 

"bird"          { yylval.num = 1; yylval.noun_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return BIRD; }
"dog"           { yylval.num = 1; yylval.noun_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return DOG; }
"birthday"          { yylval.num = 1; yylval.noun_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return BIRTHDAY; }
"luck"          { yylval.num = 1; yylval.noun_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return LUCK; }

"birds"          { yylval.num = 2; yylval.noun_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return BIRD; }
"dogs"           { yylval.num = 2; yylval.noun_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return DOG; }


"little"        { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return LITTLE; }
"happy"        { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return HAPPY; }
"few"           { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return FEW; }
"beautiful"     { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return BEAUTIFUL; }
"ugly"          { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return UGLY; }
"good"        { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return GOOD; }

"eat"           { flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return EAT; }
"sleep"         { flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return SLEEP; }
"walk"         { flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WALK; }

"quickly"       { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return QUICKLY; }
"slowly"        { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return SLOWLY; }
{alpha}+        { int token = get_main_token(yytext);
                    if (token) {
                        return token;
                    }
                }
{digit}+        { yylval.num = atoi(yytext); return NUMBER; }

"-"                             { return DASH; }
"!"                             { return EXCLAMATION; }
.                               { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}
