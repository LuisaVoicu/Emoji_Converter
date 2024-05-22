%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
void print_emoji(const char *emoji, int count);
const char* get_emoji(char *expression); 
int check_expression(char *expression);

static char expression_buffer[100];
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

%token <num> NUMBER
%token <plural_flag> PLURAL_FLAG
%token <noun_flag> BIRD DOG CAT TREE HOUSE CAR BOOK COMPUTER PHONE FOOD WATER SUN MOON STAR FLOWER BIRTHDAY LUCK
%token <adjective_flag> LITTLE BIG FEW BEAUTIFUL UGLY NICE HAPPY SAD ANGRY FAST SLOW STRONG WEAK SMART DUMB OLD YOUNG HOT COLD GOOD
%token <verb_flag> WALK TALK DRINK EAT SLEEP RUN READ WRITE PLAY SING
%token <adverb_flag> DAILY QUICKLY SLOWLY HAPPILY SADLY LOUDLY QUIETLY ALWAYS NEVER
%token DASH EXCLAMATION
%type <str> word
%type <str> noun
%type <str> adjective
%type <str> expression
%type <str> verb
%type <str> adverb
%type <num> number

%%

poem:
    lines
    ;

lines:
    line '\n' lines
    | line
    ;

line:
    sentences
    ;


word:
    adjective
    | noun
    | adverb
    | verb
    ;
sentences:
    sentence sentences
    | sentence
    ;



sentence:
    expression 
    ;

phrase:
    counted_nouns adjective verb adverb
    | adjective counted_nouns verb adverb {printf("here i have adjective noun!\n");}
    | adjective counted_nouns adverb verb 
    | counted_nouns adjective verb
    | adjective counted_nouns verb
    | counted_nouns adverb verb
    | counted_nouns verb adverb
    | counted_nouns verb
    | adjective counted_nouns  {printf("I AM HERE %s\n", $1);}
    | verb
    | counted_nouns 
    ;

expression:
    word {
        strcpy(expression_buffer, $1);

    }   
    | expression word {

        strcat(expression_buffer, " ");
        strcat(expression_buffer, $2);

        char expression_aux[100];
        strcpy(expression_aux, expression_buffer);

        int good_expression = check_expression(expression_aux);
        if (good_expression == 1) {
            
            print_emoji(get_emoji(expression_buffer),1);
        }
        expression_buffer[0] = '\0';
    }
    ;


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


number :
    NUMBER       { $$ = $1; }

noun:
    BIRD         { $$ = "🐦"; }
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
    | BIRTHDAY     { $$ = "🎂"; }
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
    ;

verb:
    WALK      { printf("🚶 "); }
    | TALK      { printf("🗣️ "); }
    | DRINK     { printf("🥤 "); }
    | EAT       { printf("🍽️ "); }
    | SLEEP     { printf("😴 "); }
    | RUN       { printf("🏃 "); }
    | READ      { printf("📖 "); }
    | WRITE     { printf("✍️ "); }
    | PLAY      { printf("🎮 "); }
    | SING      { printf("🎤 "); }
    ;

adverb:
    DAILY      { printf("📅 "); }
    | QUICKLY   { printf("🏃‍♂️ "); }
    | SLOWLY    { printf("🐢 "); }
    | HAPPILY   { printf("😊 "); }
    | SADLY     { printf("😢 "); }
    | LOUDLY    { printf("🔊 "); }
    | QUIETLY   { printf("🤫 "); }
    | ALWAYS    { printf("♾️ "); }
    | NEVER     { printf("🚫 "); }
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
    int repeat = count;
    for (int i = 1; i <= repeat; i++) {
        printf("%s ", emoji);
    }
}
void process_expression(char **words, int num_words) {
    printf("Expression: ");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int check_expression(char *expression) {

                        printf("fjnction buffer %s\n", expression);

                        char *word = strtok(expression, " "); 
    while (word) {
        printf("!!!-> %s comp: %d\n",word, (strcmp(word, "😃")));
                            printf("next!!!-> %s comp: %d\n",word, (strcmp(word, "🎂") ));
                    printf("next!!!-> %s comp: %d\n",word, (strcmp(word, "😃") ));
        // Check each word for expression match (using string comparisons)
        if (strcmp(word, "😃") == 0) {
            word = strtok(NULL, " "); // Get next word
                    printf("found happy next cake!!!-> %s comp: %d\n",word, (strcmp(word, "🎂") ));
                    printf("found happy next cake-> %s comp: %d\n",word, (strcmp(word, "😃") ));

            if (word && strcmp(word, "🎂") == 0) {
                                    printf("found cake!!!-> %s comp: %d\n",word, (strcmp(word, "🎂") ));

                return 1; // Match found
            }
        } else if (strcmp(word, "merry") == 1) {
            word = strtok(NULL, " ");
            if (word && strcmp(word, "christmas") == 1) {
                return 1;
            }
        } else if (strcmp(word, "welcome") == 1) {
            word = strtok(NULL, " ");
            if (word && strcmp(word, "home") == 1) {
                return 1;
            }
        } else if (strcmp(word, "good") == 1) {
            word = strtok(NULL, " ");
            if (word && strcmp(word, "luck") == 1) {
                return 1;
            }
        }
        // Add more checks for other expressions

        word = strtok(NULL, " "); // Get next word
    }

    return 0;

    // if (strcmp(expression, "😃 🎂") == 0) {
    //     return 1;
    // } else if (strcmp(expression, "merry christmas") == 0) {
    //     return 1;
    // } else if (strcmp(expression, "welcome home") == 0) {
    //     return 1;
    // } else if (strcmp(expression, "good luck") == 0) {
    //     return 1;
    // }
    // // Add more checks for other expressions

    // return 0; // No expression match found
}
const char* get_emoji(char *expression) {


printf("hello get emoji\n");
        printf("next!!!-> %s comp: \n",expression);

    if (strcmp(expression, "😃 🎂") == 0) {
        return "🥳";
    } else if (strcmp(expression, "merry christmas") == 0) {
        return "🎄";
    } else if (strcmp(expression, "welcome home") == 0) {
        return "🏡";
    } else if (strcmp(expression, "good luck") == 0) {
        return "🍀";
    }
    // Add more checks for other expressions

    return "🤷"; // No expression match found
}