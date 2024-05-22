%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
void print_emoji(const char *emoji, int count);
void save_buffer(char* word);
void replace_expressions_in_buffer();
static char expression_buffer[100];
static char buffer[10000];
static int n = 0;


%}

%union {
    char *str;
    int num;
    int plural_flag;
    int noun_flag;
    int adjective_flag;
    int verb_flag;
    int adverb_flag;
}


%token <str> UNKNOWN_WORD
%token <num> NUMBER
%token <noun_flag> BIRD DOG CAT TREE HOUSE CAR BOOK COMPUTER PHONE FOOD WATER SUN MOON STAR FLOWER BIRTHDAY LUCK CHRISTMAS
%token <adjective_flag> LITTLE BIG FEW BEAUTIFUL UGLY NICE HAPPY SAD ANGRY FAST SLOW STRONG WEAK SMART DUMB OLD YOUNG HOT COLD GOOD
%token <verb_flag> WALK TALK DRINK EAT SLEEP RUN READ WRITE PLAY SING
%token <adverb_flag> DAILY QUICKLY SLOWLY HAPPILY SADLY LOUDLY QUIETLY ALWAYS NEVER
%token DASH EXCLAMATION
%type <str> noun
%type <str> adjective
%type <str> adjective_aux
%type <str> verb
%type <str> verb_aux
%type <str> adverb
%type <str> adverb_aux
%type <num> number
%type <str> unknown_word

%%

poem:
    lines
    ;

lines:
    line lines
    | line
    ;

line:
    sentences {
        printf("\n--------this is the end of line, catched: %s \n", buffer);
        replace_expressions_in_buffer();
        printf("\n--------this is the end of line, catched with expressions: %s \n", buffer);

    }
    ;



sentences:
    sentence sentences
    | sentence
    ;





sentence:
    counted_nouns adjective_aux verb_aux adverb_aux
    | adjective_aux counted_nouns verb_aux adverb_aux {printf("here i have adjective noun!\n");}
    | adjective_aux counted_nouns adverb_aux verb_aux 
    | counted_nouns adjective_aux verb_aux
    | adjective_aux counted_nouns verb_aux
    | counted_nouns adverb_aux verb_aux
    | counted_nouns verb_aux adverb_aux
    | counted_nouns verb_aux
    | adjective_aux counted_nouns  {printf("I AM HERE %s\n", $1);}
    | verb_aux
    | counted_nouns 
    | unknown_word
    ;



// printare / punere in buffer a fiecarei parti de vorbire 
counted_noun:
    noun {print_emoji($1, 1);} //todo : doesn't work...
    | number noun { print_emoji($2, $1);}
    | noun number { print_emoji($1, $2);}
    | number {printf("%d ", $1); }
    ;

counted_nouns:
    counted_noun ',' counted_nouns
    | counted_noun
    ;

adjective_aux:
    adjective {printf("%s ",$1); save_buffer($1);}
    ;

verb_aux:
    verb {printf("%s ",$1); save_buffer($1);}
    ;

adverb_aux:
    adverb {printf("%s ",$1); save_buffer($1);}
    ;

unknown_word :
    UNKNOWN_WORD    {$$ = $1; printf("####### %s\n", $$); save_buffer($$);}

number :
    NUMBER       { $$ = $1; }

noun:
    BIRD         { $$ = "🐦";}
    | DOG        { $$ = "🐶"; }
    | CAT        { $$ = "🐱"; }
    | TREE       { $$ = "🌳"; }
    | HOUSE      { $$ = "🏠"; }
    | CAR        { $$ = "🚗"; }
    | BOOK       { $$ = "📖"; }
    | COMPUTER   { $$ = "💻"; }
    | PHONE      { $$ = "📱"; }
    | FOOD       { $$ = "🍲"; }
    | WATER      { $$ = "💧"; }
    | SUN        { $$ = "☀️"; }
    | MOON       { $$ = "🌜"; }
    | STAR       { $$ = "⭐"; }
    | FLOWER     { $$ = "🌸"; }
    | BIRTHDAY   { $$ = "🎂"; }
    | LUCK       { $$ = "🍀";}
    | CHRISTMAS  { $$ = "🎅🏻";}
    ;

adjective:
    LITTLE       { $$ = "🤏"; }
    | BIG        { $$ = "💪"; }
    | FEW        { $$ = "✌️"; }
    | BEAUTIFUL  { $$ = "🌸"; }
    | UGLY       { $$ = "👹"; }
    | NICE       { $$ = "😊"; }
    | HAPPY      { $$ = "😃"; }
    | SAD        { $$ = "😢"; }
    | ANGRY      { $$ = "😠"; }
    | FAST       { $$ = "🏃‍♂️"; }
    | SLOW       { $$ = "🐌"; }
    | STRONG     { $$ = "💪"; }
    | WEAK       { $$ = "🦠"; }
    | SMART      { $$ = "🧠"; }
    | DUMB       { $$ = "🤪"; }
    | OLD        { $$ = "👴"; }
    | YOUNG      { $$ = "👶"; }
    | HOT        { $$ = "🔥"; }
    | COLD       { $$ = "❄️"; }
    | GOOD       { $$ = "👍"; }
    ;

verb:
    WALK      { $$ = "🚶"; }
    | TALK      { $$ = "🗣️"; }
    | DRINK     { $$ = "🥤"; }
    | EAT       { $$ = "🍽️"; }
    | SLEEP     { $$ = "😴"; }
    | RUN       { $$ = "🏃"; }
    | READ      { $$ = "📖"; }
    | WRITE     { $$ = "✍️"; }
    | PLAY      { $$ = "🎮"; }
    | SING      { $$ = "🎤"; }
    ;

adverb:
    DAILY      { $$ = "📅"; }
    | QUICKLY   { $$ = "🏃‍♂️"; }
    | SLOWLY    { $$ = "🐢"; }
    | HAPPILY   { $$ = "😊"; }
    | SADLY     { $$ = "😢"; }
    | LOUDLY    { $$ = "🔊"; }
    | QUIETLY   { $$ = "🤫"; }
    | ALWAYS    { $$ = "♾️"; }
    | NEVER     { $$ = "🚫"; }
    ;

%%

#include "lex.yy.c"

int main() {
    printf("before or after????\n");
    strcpy(buffer, "");
    return yyparse();
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

void print_emoji(const char *emoji, int count) {
    int repeat = count;
    for (int i = 1; i <= repeat; i++) {
        printf("%s ", emoji);
        save_buffer(emoji);
    }
}
void process_expression(char **words, int num_words) {
    printf("Expression: ");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

void save_buffer(char* word){
  strcat(buffer, word);
  strcat(buffer, " ");
}

void replace_expressions_in_buffer() {
    char *new_buffer = malloc(strlen(buffer) + 1); 
    if (new_buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_buffer[0] = '\0'; 

    char *expression = strtok(buffer, " "); 
    while (expression != NULL) {
        if (strcmp(expression, "😃") == 0) {
            char *next_token = strtok(NULL, " "); 
            if (next_token != NULL && strcmp(next_token, "🎂") == 0) {
                strcat(new_buffer, "🥳 "); 
                expression = strtok(NULL, " "); 
                continue; 
            }
        } else if (strcmp(expression, "merry") == 0) {
            char *next_token = strtok(NULL, " "); 
            if (next_token != NULL && strcmp(next_token, "🎅🏻") == 0) {
                strcat(new_buffer, "🎄 "); 
                expression = strtok(NULL, " "); 
                continue; 
            }
        } else if (strcmp(expression, "welcome") == 0) {
            char *next_token = strtok(NULL, " "); 
            if (next_token != NULL && strcmp(next_token, "home") == 0) {
                strcat(new_buffer, "🏡 "); 
                expression = strtok(NULL, " "); 
                continue; 
            }
        } else if (strcmp(expression, "👍") == 0) {
            char *next_token = strtok(NULL, " "); 
            if (next_token != NULL && strcmp(next_token, "🍀") == 0) {
                strcat(new_buffer, "🤞 "); 
                expression = strtok(NULL, " ");
                continue; 
            }
        }

        strcat(new_buffer, expression); 
        strcat(new_buffer, " ");
        expression = strtok(NULL, " ");
    }

    strcpy(buffer, new_buffer); 
    free(new_buffer); 
}