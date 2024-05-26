%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *to_lower(char *str);
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
    {"canary", BIRD},
    {"puppy", DOG},
    {"kitten", CAT},
    {"moggy", CAT},
    {"pine", TREE},
    {"residence", HOUSE},
    {"automobile", CAR},
    {"novel", BOOK},
    {"laptop", COMPUTER},
    {"cellphone", PHONE},
    {"nourishment", FOOD},
    {"beverage", DRINK},
    {"rest", SLEEP},
    {"sprint", RUN},
    {"study", STUDY},
    {"employment", WORK},
    {"painting", PAINT},
    {"artwork", DRAW},
    {"assist", HELP},
    {"tidy", CLEAN},
    {"construct", BUILD},
    {"observe", WATCH},
    {"educate", TEACH},
    {"knowledge", LEARN},
    {"happily", HAPPILY},
    {"sadly", SADLY},
    {"noisily", LOUDLY},
    {"silently", QUIETLY},
    {"constantly", ALWAYS},
    {"occasionally", RARELY},
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

[\t\r ]+                      ; 
\n              {return NEW_LINE;}
"bird"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return BIRD; }
"dog"s?         { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return DOG; }
"cat"s?         { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return CAT; }
"tree"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return TREE; }
"house"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return HOUSE; }
"car"s?         { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return CAR; }
"book"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return BOOK; }
"computer"s?    { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return COMPUTER; }
"phone"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return PHONE; }
"food"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return FOOD; }
"water"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return WATER; }
"sun"s?         { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return SUN; }
"moon"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return MOON; }
"star"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return STAR; }
"flower"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return FLOWER; }
"birthday"s?    { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return BIRTHDAY; }
"luck"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return LUCK; }
"christmas"es?  { yylval.num = (yytext[yyleng-1] == 's' || yytext[yyleng-1] == 'e') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return CHRISTMAS; }
"apple"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return APPLE; }
"banana"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return BANANA; }
"grape"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return GRAPE; }
"orange"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return ORANGE; }
"pear"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return PEAR; }
"strawberry"s?  { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return STRAWBERRY; }
"lemon"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return LEMON; }
"peach"es?      { yylval.num = (yytext[yyleng-1] == 's' || yytext[yyleng-1] == 'e') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return PEACH; }
"plum"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return PLUM; }
"pineapple"s?   { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return PINEAPPLE; }
"chair"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return CHAIR; }
"table"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return TABLE; }
"desk"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return DESK; }
"window"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return WINDOW; }
"door"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return DOOR; }
"cup"s?         { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return CUP; }
"bottle"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return BOTTLE; }
"pen"s?         { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return PEN; }
"pencil"s?         { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return PENCIL; }

"I"             { yylval.num = 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return I; }
"me"            { yylval.num = 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return ME; }
"you"           { yylval.num = 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return YOU; }
"he"            { yylval.num = 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return HE; }
"him"           { yylval.num = 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return HIM; }
"she"           { yylval.num = 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return SHE; }
"her"           { yylval.num = 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return HER; }
"it"            { yylval.num = 1; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return IT; }
"we"            { yylval.num = 2; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return WE; }
"us"            { yylval.num = 2; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return US; }
"they"          { yylval.num = 2; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return THEY; }
"them"          { yylval.num = 2; yylval.subject_flag = PLURAL_FLAG; flags |= HAS_SUBJECT_FLAG; return THEM; }

"big"        { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return BIG; }
"little"        { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return LITTLE; }
"happy"         { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return HAPPY; }
"few"           { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return FEW; }
"beautiful"     { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return BEAUTIFUL; }
"ugly"          { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return UGLY; }
"good"          { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return GOOD; }
"cool"          { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return COOL; }
"funny"         { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return FUNNY; }
"scary"         { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return SCARY; }
"brave"         { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return BRAVE; }
"clever"        { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return CLEVER; }
"lazy"          { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return LAZY; }
"busy"          { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return BUSY; }
"quiet"         { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return QUIET; }
"loud"          { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return LOUD; }
"dirty"         { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return DIRTY; }
"confused"      { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return CONFUSED; }
"shy"           { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return SHY; }
"friendly"      { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return FRIENDLY; }
"alone"         { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return ALONE; }
"creative"      { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return CREATIVE; }
"serious"       { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return SERIOUS; }
"excited"       { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return EXCITED; }
"grateful"      { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return GRATEFUL; }
"hopeful"       { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return HOPEFUL; }
"proud"         { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return PROUD; }
"tired"         { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return TIRED; }
"relaxed"       { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return RELAXED; }
"stressed"      { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return STRESSED; }
"calm"          { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return CALM; }
"energetic"     { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return ENERGETIC; }
"merry"        { flags |= HAS_ADJECTIVE_FLAG; yylval.adjective_flag = 1; return MERRY; }


"eat"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return EAT; }
"ate"          { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return EAT; }

"sleep"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return SLEEP; }
"slept"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return SLEEP; }

"walk"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WALK; }
"walked"       { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WALK; }

"talk"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return TALK; }
"talked"       { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return TALK; }

"drink"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DRINK; }
"drank"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DRINK; }
"drunk"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DRINK; }

"run"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return RUN; }
"ran"          { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return RUN; }

"read"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return READ; }

"write"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WRITE; }
"wrote"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WRITE; }
"written"      { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WRITE; }

"play"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return PLAY; }
"played"       { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return PLAY; }

"sing"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return SING; }
"sang"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return SING; }
"sung"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return SING; }

"dance"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DANCE; }
"danced"       { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DANCE; }

"jump"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return JUMP; }
"jumped"       { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return JUMP; }

"swim"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return SWIM; }
"swam"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return SWIM; }
"swum"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return SWIM; }

"cook"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return COOK; }
"cooked"       { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return COOK; }

"fly"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return FLY; }
"flew"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return FLY; }
"flown"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return FLY; }
"flies"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return FLY; }

"drive"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DRIVE; }
"drove"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DRIVE; }
"driven"       { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DRIVE; }

"study"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return STUDY; }
"studied"      { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return STUDY; }

"work"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WORK; }
"worked"       { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WORK; }

"paint"s?      { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return PAINT; }
"painted"      { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return PAINT; }

"draw"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DRAW; }
"drew"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DRAW; }
"drawn"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return DRAW; }

"listen"s?       { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return LISTEN; }
"listened"       { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return LISTEN; }

"help"s?         { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return HELP; }
"helped"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return HELP; }

"clean"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return CLEAN; }
"cleaned"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return CLEAN; }

"build"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return BUILD; }
"built"          { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return BUILD; }

"watch"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WATCH; }
"watched"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return WATCH; }

"teach"es?       { yylval.num = (yytext[yyleng-1] == 's' || yytext[yyleng-2] == 'e') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return TEACH; }
"taught"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return TEACH; }

"learn"s?        { yylval.num = (yytext[yyleng-1] == 's') ? 2 : 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return LEARN; }
"learned"        { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return LEARN; }
"learnt"         { yylval.num = 1; flags |= HAS_VERB_FLAG; yylval.verb_flag = 1; return LEARN; }


"daily"        { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return DAILY; }
"quickly"      { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return QUICKLY; }
"slowly"       { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return SLOWLY; }
"happily"      { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return HAPPILY; }
"sadly"        { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return SADLY; }
"loudly"       { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return LOUDLY; }
"quietly"      { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return QUIETLY; }
"always"       { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return ALWAYS; }
"never"        { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return NEVER; }
"carefully"    { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return CAREFULLY; }
"often"        { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return OFTEN; }
"rarely"       { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return RARELY; }
"suddenly"     { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return SUDDENLY; }
"anxiously"    { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return ANXIOUSLY; }
"confidently"  { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return CONFIDENTLY; }
"eagerly"      { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return EAGERLY; }
"gracefully"   { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return GRACEFULLY; }
"silly"        { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return SILLY; }
"awkwardly"    { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return AWKWARDLY; }
"curiously"    { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return CURIOUSLY; }
"patiently"    { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return PATIENTLY; }
"nervously"    { flags |= HAS_ADVERB_FLAG; yylval.adverb_flag = 1; return NERVOUSLY; }



{alpha}+        { int token = get_main_token(yytext);
                    if (token) {
                        return token;
                    }
                    else {
                         yylval.str = strdup(to_lower(yytext)); return UNKNOWN_WORD;
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
char *to_lower(char *str) {
    char *lower_str = strdup(str);
    for (int i = 0; lower_str[i]; i++) {
        lower_str[i] = tolower(lower_str[i]);
    }
    return lower_str;
}
