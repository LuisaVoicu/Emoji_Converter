%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void yyerror(const char *s);
void print_emoji(const char *emoji, int count);
void save_buffer(char* word);
void replace_expressions_in_buffer();
char *replace_unknown_word_with_emojis(char *word);

static char expression_buffer[100];
static char buffer[10000];
static int n = 0;

typedef struct {
    const char *name;       
    const char **emojis;  
    const char **keywords; 
    int num_keywords;
    int num_emoji;
} LexicalField;

const char *animal_emojis[] = {"🐦", "🐶", "🐱", "🐟", "🐍", "🐘"};
const char *animal_keywords[] = {"animal", "pet", "bird", "dog", "cat", "fish", "snake", "elephant",
                                  "mammal", "reptile", "bird", "feline", "canine"};

const char *object_emojis[] = {"🌳", "💻", "🚗", "📖", "💻", "📱"};
const char *object_keywords[] = {"object", "things", "thing" "tree", "house", "car", "book", "computer", "phone",
                                   "device", "machine", "vehicle", "building", "structure"};

const char *food_emojis[] = {"🍔", "🍟", "🍕", "🍎", "🍇", "🍦"};
const char *food_keywords[] = {"food", "meal", "burger", "fries", "pizza", "apple", "grapes", "ice cream",
                                  "snack", "dessert", "fruit", "vegetable"};

const char *plant_emojis[] = {"🌲", "🌻", "🌷", "🌿", "🌴", "🌾"};
const char *plant_keywords[] = {"plant", "flora", "pine", "sunflower", "tulip", "herb", "palm", "grass",
                                   "flower", "tree", "bush", "vegetation"};

const char *job_emojis[] = {"💼", "🔨", "💻", "🎓", "🧑‍🚀", "👮"};
const char *job_keywords[] = {"job", "occupation", "work", "office", "hammer", "computer", "graduate", "astronaut", "police",
                                 "career", "profession", "employment", "vocation"};

const char *human_emojis[] = {"👨", "👩", "🧒", "👴", "👵", "👶"};
const char *human_keywords[] = {"human", "person", "man", "woman", "child", "old", "elderly", "baby",
                                   "individual", "adult", "youth", "senior"};


LexicalField lexical_fields[] = {
    {"animal", animal_emojis, animal_keywords, 12, 6},
    {"object", object_emojis, object_keywords, 13, 6},
    {"food", food_emojis, food_keywords, 12, 6},
    {"plant", plant_emojis, plant_keywords, 12, 6},
    {"job", job_emojis, job_keywords, 13, 6},
    {"human", human_emojis, human_keywords, 12, 6},
};

%}

%union {
    char *str;
    int num;
    int subject_flag;
    int adjective_flag;
    int verb_flag;
    int adverb_flag;
}

%token NEW_LINE
%token <str> UNKNOWN_WORD
%token <num> NUMBER
%token <subject_flag> BIRD DOG CAT TREE HOUSE CAR BOOK COMPUTER PHONE FOOD WATER SUN MOON STAR FLOWER BIRTHDAY LUCK CHRISTMAS APPLE BANANA GRAPE ORANGE PEAR STRAWBERRY LEMON PEACH PLUM PINEAPPLE CHAIR TABLE DESK WINDOW DOOR CUP BOTTLE PEN PENCIL I ME YOU HE HIM SHE HER IT WE US THEY THEM
%token <adjective_flag> MERRY LITTLE BIG FEW BEAUTIFUL UGLY NICE HAPPY SAD ANGRY FAST SLOW STRONG WEAK SMART DUMB OLD YOUNG HOT COLD GOOD COOL FUNNY SCARY BRAVE CLEVER LAZY BUSY QUIET LOUD DIRTY CONFUSED SHY FRIENDLY ALONE CREATIVE SERIOUS EXCITED GRATEFUL HOPEFUL PROUD TIRED RELAXED STRESSED CALM ENERGETIC
%token <verb_flag> WALK TALK DRINK EAT SLEEP RUN READ WRITE PLAY SING DANCE JUMP SWIM COOK FLY DRIVE STUDY WORK PAINT DRAW LISTEN HELP CLEAN BUILD WATCH TEACH LEARN
%token <adverb_flag> DAILY QUICKLY SLOWLY HAPPILY SADLY LOUDLY QUIETLY ALWAYS NEVER CAREFULLY OFTEN RARELY SUDDENLY ANXIOUSLY CONFIDENTLY EAGERLY GRACEFULLY SILLY AWKWARDLY CURIOUSLY PATIENTLY NERVOUSLY

%token DASH EXCLAMATION
%type <str> noun
%type <str> pronoun
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
    sentences NEW_LINE {
        //printf("\n--------this is the end of line, catched: %s \n", buffer);
        replace_expressions_in_buffer();
        //printf("\n--------this is the end of line, catched with expressions: %s \n", buffer);
        printf("%s\n",buffer);
        buffer[0] = '\0';
    }
    ;



sentences:
    sentence sentences
    | sentence
    |
    ;





sentence:
    subject adjective_aux verb_aux adverb_aux 
    | adjective_aux subject verb_aux adverb_aux 
    | adjective_aux subject adverb_aux verb_aux 
    | subject adjective_aux verb_aux
    | adjective_aux subject verb_aux 
    | subject adverb_aux verb_aux 
    | subject verb_aux adverb_aux 
    | subject verb_aux 
    | adjective_aux subject  
    | verb_aux 
    | subject 
    | unknown_word 
    | adjective_aux
    | adverb_aux
    |
    ;



// printare / punere in buffer a fiecarei parti de vorbire 
counted_noun:
    noun {print_emoji($1, 1);} //todo : doesn't work...
    | number noun { print_emoji($2, $1); }
    | noun number { print_emoji($1, $2); }
    | number {
        save_buffer($1);}
    ;


subject:
    counted_nouns
    | pronoun_aux
    ;

counted_nouns:
    counted_noun ',' counted_nouns
    | counted_noun
    ;

adjective_aux:
    adjective {
        //printf("%s ",$1);
        save_buffer($1);
     }
    ;

verb_aux:
    verb {
        //printf("%s ",$1); 
        save_buffer($1);}
    ;

adverb_aux:
    adverb {
        //printf("%s ",$1); 
        save_buffer($1);}
    ;

pronoun_aux:
    pronoun {
        //printf("%s ",$1); 
        save_buffer($1);}
    ;

unknown_word :
    UNKNOWN_WORD    {
        //$$ = $1; printf("####### %s\n", $$); 
        $$ = replace_unknown_word_with_emojis($1);
        save_buffer($$);
        }

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
    | APPLE      { $$ = "🍎";}
    | BANANA     { $$ = "🍌";}
    | GRAPE      { $$ = "🍇";}
    | ORANGE     { $$ = "🍊";}
    | PEAR       { $$ = "🍐";}
    | STRAWBERRY { $$ = "🍓";}
    | LEMON      { $$ = "🍋";}
    | PEACH      { $$ = "🍑";}
    | PLUM       { $$ = "🍑";}
    | PINEAPPLE  { $$ = "🍍";}
    | CHAIR      { $$ = "🪑";}
    | TABLE      { $$ = "🪑";}
    | DESK       { $$ = "🪑";}
    | WINDOW     { $$ = "🪟";}
    | DOOR       { $$ = "🚪";}
    | CUP        { $$ = "☕";}
    | BOTTLE     { $$ = "🍾";}
    | PEN        { $$ = "✒️";}
    | PENCIL     { $$ = "✏️";}
    ;


adjective:
    LITTLE       { $$ = "🤏"; }
    | BIG        { $$ = "💪"; }
    | FEW        { $$ = "✌️"; }
    | BEAUTIFUL  { $$ = "🌸"; }
    | MERRY      { $$ = "😇"; }
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
    | COOL       { $$ = "😎"; }
    | FUNNY      { $$ = "😆"; }
    | SCARY      { $$ = "😱"; }
    | BRAVE      { $$ = "🦸‍"; }
    | CLEVER     { $$ = "🤓"; }
    | LAZY       { $$ = "😴"; }
    | BUSY       { $$ = "💼"; }
    | QUIET      { $$ = "🤫"; }
    | LOUD       { $$ = "🔊"; }
    | DIRTY      { $$ = "🧻"; }
    | CONFUSED   { $$ = "😕"; }
    | SHY        { $$ = "🙈"; }
    | FRIENDLY   { $$ = "👋"; }
    | ALONE      { $$ = "🚶‍♂️"; }
    | CREATIVE   { $$ = "🎨"; }
    | SERIOUS    { $$ = "😐"; }
    | EXCITED    { $$ = "😁"; }
    | GRATEFUL   { $$ = "🙏"; }
    | HOPEFUL    { $$ = "🤞"; }
    | PROUD      { $$ = "🏆"; }
    | TIRED      { $$ = "😴"; }
    | RELAXED    { $$ = "😌"; }
    | STRESSED   { $$ = "😩"; }
    | CALM       { $$ = "😌"; }
    | ENERGETIC  { $$ = "💥"; }
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
    | DANCE     { $$ = "💃"; }
    | JUMP      { $$ = "🤸"; }
    | SWIM      { $$ = "🏊"; }
    | COOK      { $$ = "👩‍🍳"; }
    | FLY       { $$ = "✈️"; }
    | DRIVE     { $$ = "🚗"; }
    | STUDY     { $$ = "📚"; }
    | WORK      { $$ = "💼"; }
    | PAINT     { $$ = "🎨"; }
    | DRAW      { $$ = "✏️"; }
    | LISTEN    { $$ = "👂"; }
    | HELP      { $$ = "🤝"; }
    | CLEAN     { $$ = "🧹"; }
    | BUILD     { $$ = "🔨"; }
    | WATCH     { $$ = "👀"; }
    | TEACH     { $$ = "👩‍🏫"; }
    | LEARN     { $$ = "📝"; }
    ;


adverb:
    DAILY        { $$ = "📅"; }
    | QUICKLY     { $$ = "🏃‍"; }
    | SLOWLY      { $$ = "🐢"; }
    | HAPPILY     { $$ = "😊"; }
    | SADLY       { $$ = "😢"; }
    | LOUDLY      { $$ = "🔊"; }
    | QUIETLY     { $$ = "🤫"; }
    | ALWAYS      { $$ = "♾️"; }
    | NEVER       { $$ = "🚫"; }
    | CAREFULLY   { $$ = "🔍"; }
    | OFTEN       { $$ = "🔁"; }
    | RARELY      { $$ = "🔀"; }
    | SUDDENLY    { $$ = "🌪️"; }
    | ANXIOUSLY   { $$ = "😰"; }
    | CONFIDENTLY { $$ = "😎"; }
    | EAGERLY     { $$ = "🤩"; }
    | GRACEFULLY  { $$ = "🩰"; }
    | SILLY       { $$ = "🤪"; }
    | AWKWARDLY   { $$ = "🙃"; }
    | CURIOUSLY   { $$ = "🔍"; }
    | PATIENTLY   { $$ = "⏳"; }
    | NERVOUSLY   { $$ = "😬"; }
    ;

pronoun:
    I         { $$ = "👤"; }
    | YOU      { $$ = "👥"; }
    | HE       { $$ = "👦"; }
    | SHE      { $$ = "👧"; }
    | IT       { $$ = "👶"; }
    | WE       { $$ = "👫"; }
    | THEY     { $$ = "👬"; }
    | ME       { $$ = "👤"; }
    | HIM      { $$ = "👦"; }
    | HER      { $$ = "👧"; }
    | US       { $$ = "👫"; }
    | THEM     { $$ = "👬"; }
    ;


%%

#include "lex.yy.c"

int main() {
    strcpy(buffer, "");
    return yyparse();
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

void print_emoji(const char *emoji, int count) {
    int repeat = count;
    for (int i = 1; i <= repeat; i++) {
        //printf("%s ", emoji);
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
        } else if (strcmp(expression, "😇") == 0) {
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


char *replace_unknown_word_with_emojis(char *word) {


    char *emojis = malloc(4 * 3); 
    emojis[0] = '\0'; 


    for (int i = 0; i < sizeof(lexical_fields) / sizeof(lexical_fields[0]); i++) {

        for (int j = 0; j <lexical_fields[i].num_keywords; j++) {
           
           if (strcmp(word, lexical_fields[i].keywords[j]) == 0) {
                strcat(emojis, "(");
                strcat(emojis, lexical_fields[i].emojis[0]);
                strcat(emojis, " "); 
                strcat(emojis, lexical_fields[i].emojis[1]);
                strcat(emojis, " "); 
                strcat(emojis, lexical_fields[i].emojis[2]);
                strcat(emojis, ") ");


                return emojis;
            }
        }
    }
    return word;
}
