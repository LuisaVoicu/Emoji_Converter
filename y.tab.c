/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "emoji.y"

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


#line 131 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NEW_LINE = 258,                /* NEW_LINE  */
    UNKNOWN_WORD = 259,            /* UNKNOWN_WORD  */
    NUMBER = 260,                  /* NUMBER  */
    BIRD = 261,                    /* BIRD  */
    DOG = 262,                     /* DOG  */
    CAT = 263,                     /* CAT  */
    TREE = 264,                    /* TREE  */
    HOUSE = 265,                   /* HOUSE  */
    CAR = 266,                     /* CAR  */
    BOOK = 267,                    /* BOOK  */
    COMPUTER = 268,                /* COMPUTER  */
    PHONE = 269,                   /* PHONE  */
    FOOD = 270,                    /* FOOD  */
    WATER = 271,                   /* WATER  */
    SUN = 272,                     /* SUN  */
    MOON = 273,                    /* MOON  */
    STAR = 274,                    /* STAR  */
    FLOWER = 275,                  /* FLOWER  */
    BIRTHDAY = 276,                /* BIRTHDAY  */
    LUCK = 277,                    /* LUCK  */
    CHRISTMAS = 278,               /* CHRISTMAS  */
    APPLE = 279,                   /* APPLE  */
    BANANA = 280,                  /* BANANA  */
    GRAPE = 281,                   /* GRAPE  */
    ORANGE = 282,                  /* ORANGE  */
    PEAR = 283,                    /* PEAR  */
    STRAWBERRY = 284,              /* STRAWBERRY  */
    LEMON = 285,                   /* LEMON  */
    PEACH = 286,                   /* PEACH  */
    PLUM = 287,                    /* PLUM  */
    PINEAPPLE = 288,               /* PINEAPPLE  */
    CHAIR = 289,                   /* CHAIR  */
    TABLE = 290,                   /* TABLE  */
    DESK = 291,                    /* DESK  */
    WINDOW = 292,                  /* WINDOW  */
    DOOR = 293,                    /* DOOR  */
    CUP = 294,                     /* CUP  */
    BOTTLE = 295,                  /* BOTTLE  */
    PEN = 296,                     /* PEN  */
    PENCIL = 297,                  /* PENCIL  */
    I = 298,                       /* I  */
    ME = 299,                      /* ME  */
    YOU = 300,                     /* YOU  */
    HE = 301,                      /* HE  */
    HIM = 302,                     /* HIM  */
    SHE = 303,                     /* SHE  */
    HER = 304,                     /* HER  */
    IT = 305,                      /* IT  */
    WE = 306,                      /* WE  */
    US = 307,                      /* US  */
    THEY = 308,                    /* THEY  */
    THEM = 309,                    /* THEM  */
    MERRY = 310,                   /* MERRY  */
    LITTLE = 311,                  /* LITTLE  */
    BIG = 312,                     /* BIG  */
    FEW = 313,                     /* FEW  */
    BEAUTIFUL = 314,               /* BEAUTIFUL  */
    UGLY = 315,                    /* UGLY  */
    NICE = 316,                    /* NICE  */
    HAPPY = 317,                   /* HAPPY  */
    SAD = 318,                     /* SAD  */
    ANGRY = 319,                   /* ANGRY  */
    FAST = 320,                    /* FAST  */
    SLOW = 321,                    /* SLOW  */
    STRONG = 322,                  /* STRONG  */
    WEAK = 323,                    /* WEAK  */
    SMART = 324,                   /* SMART  */
    DUMB = 325,                    /* DUMB  */
    OLD = 326,                     /* OLD  */
    YOUNG = 327,                   /* YOUNG  */
    HOT = 328,                     /* HOT  */
    COLD = 329,                    /* COLD  */
    GOOD = 330,                    /* GOOD  */
    COOL = 331,                    /* COOL  */
    FUNNY = 332,                   /* FUNNY  */
    SCARY = 333,                   /* SCARY  */
    BRAVE = 334,                   /* BRAVE  */
    CLEVER = 335,                  /* CLEVER  */
    LAZY = 336,                    /* LAZY  */
    BUSY = 337,                    /* BUSY  */
    QUIET = 338,                   /* QUIET  */
    LOUD = 339,                    /* LOUD  */
    DIRTY = 340,                   /* DIRTY  */
    CONFUSED = 341,                /* CONFUSED  */
    SHY = 342,                     /* SHY  */
    FRIENDLY = 343,                /* FRIENDLY  */
    ALONE = 344,                   /* ALONE  */
    CREATIVE = 345,                /* CREATIVE  */
    SERIOUS = 346,                 /* SERIOUS  */
    EXCITED = 347,                 /* EXCITED  */
    GRATEFUL = 348,                /* GRATEFUL  */
    HOPEFUL = 349,                 /* HOPEFUL  */
    PROUD = 350,                   /* PROUD  */
    TIRED = 351,                   /* TIRED  */
    RELAXED = 352,                 /* RELAXED  */
    STRESSED = 353,                /* STRESSED  */
    CALM = 354,                    /* CALM  */
    ENERGETIC = 355,               /* ENERGETIC  */
    WALK = 356,                    /* WALK  */
    TALK = 357,                    /* TALK  */
    DRINK = 358,                   /* DRINK  */
    EAT = 359,                     /* EAT  */
    SLEEP = 360,                   /* SLEEP  */
    RUN = 361,                     /* RUN  */
    READ = 362,                    /* READ  */
    WRITE = 363,                   /* WRITE  */
    PLAY = 364,                    /* PLAY  */
    SING = 365,                    /* SING  */
    DANCE = 366,                   /* DANCE  */
    JUMP = 367,                    /* JUMP  */
    SWIM = 368,                    /* SWIM  */
    COOK = 369,                    /* COOK  */
    FLY = 370,                     /* FLY  */
    DRIVE = 371,                   /* DRIVE  */
    STUDY = 372,                   /* STUDY  */
    WORK = 373,                    /* WORK  */
    PAINT = 374,                   /* PAINT  */
    DRAW = 375,                    /* DRAW  */
    LISTEN = 376,                  /* LISTEN  */
    HELP = 377,                    /* HELP  */
    CLEAN = 378,                   /* CLEAN  */
    BUILD = 379,                   /* BUILD  */
    WATCH = 380,                   /* WATCH  */
    TEACH = 381,                   /* TEACH  */
    LEARN = 382,                   /* LEARN  */
    DAILY = 383,                   /* DAILY  */
    QUICKLY = 384,                 /* QUICKLY  */
    SLOWLY = 385,                  /* SLOWLY  */
    HAPPILY = 386,                 /* HAPPILY  */
    SADLY = 387,                   /* SADLY  */
    LOUDLY = 388,                  /* LOUDLY  */
    QUIETLY = 389,                 /* QUIETLY  */
    ALWAYS = 390,                  /* ALWAYS  */
    NEVER = 391,                   /* NEVER  */
    CAREFULLY = 392,               /* CAREFULLY  */
    OFTEN = 393,                   /* OFTEN  */
    RARELY = 394,                  /* RARELY  */
    SUDDENLY = 395,                /* SUDDENLY  */
    ANXIOUSLY = 396,               /* ANXIOUSLY  */
    CONFIDENTLY = 397,             /* CONFIDENTLY  */
    EAGERLY = 398,                 /* EAGERLY  */
    GRACEFULLY = 399,              /* GRACEFULLY  */
    SILLY = 400,                   /* SILLY  */
    AWKWARDLY = 401,               /* AWKWARDLY  */
    CURIOUSLY = 402,               /* CURIOUSLY  */
    PATIENTLY = 403,               /* PATIENTLY  */
    NERVOUSLY = 404,               /* NERVOUSLY  */
    DASH = 405,                    /* DASH  */
    EXCLAMATION = 406              /* EXCLAMATION  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NEW_LINE 258
#define UNKNOWN_WORD 259
#define NUMBER 260
#define BIRD 261
#define DOG 262
#define CAT 263
#define TREE 264
#define HOUSE 265
#define CAR 266
#define BOOK 267
#define COMPUTER 268
#define PHONE 269
#define FOOD 270
#define WATER 271
#define SUN 272
#define MOON 273
#define STAR 274
#define FLOWER 275
#define BIRTHDAY 276
#define LUCK 277
#define CHRISTMAS 278
#define APPLE 279
#define BANANA 280
#define GRAPE 281
#define ORANGE 282
#define PEAR 283
#define STRAWBERRY 284
#define LEMON 285
#define PEACH 286
#define PLUM 287
#define PINEAPPLE 288
#define CHAIR 289
#define TABLE 290
#define DESK 291
#define WINDOW 292
#define DOOR 293
#define CUP 294
#define BOTTLE 295
#define PEN 296
#define PENCIL 297
#define I 298
#define ME 299
#define YOU 300
#define HE 301
#define HIM 302
#define SHE 303
#define HER 304
#define IT 305
#define WE 306
#define US 307
#define THEY 308
#define THEM 309
#define MERRY 310
#define LITTLE 311
#define BIG 312
#define FEW 313
#define BEAUTIFUL 314
#define UGLY 315
#define NICE 316
#define HAPPY 317
#define SAD 318
#define ANGRY 319
#define FAST 320
#define SLOW 321
#define STRONG 322
#define WEAK 323
#define SMART 324
#define DUMB 325
#define OLD 326
#define YOUNG 327
#define HOT 328
#define COLD 329
#define GOOD 330
#define COOL 331
#define FUNNY 332
#define SCARY 333
#define BRAVE 334
#define CLEVER 335
#define LAZY 336
#define BUSY 337
#define QUIET 338
#define LOUD 339
#define DIRTY 340
#define CONFUSED 341
#define SHY 342
#define FRIENDLY 343
#define ALONE 344
#define CREATIVE 345
#define SERIOUS 346
#define EXCITED 347
#define GRATEFUL 348
#define HOPEFUL 349
#define PROUD 350
#define TIRED 351
#define RELAXED 352
#define STRESSED 353
#define CALM 354
#define ENERGETIC 355
#define WALK 356
#define TALK 357
#define DRINK 358
#define EAT 359
#define SLEEP 360
#define RUN 361
#define READ 362
#define WRITE 363
#define PLAY 364
#define SING 365
#define DANCE 366
#define JUMP 367
#define SWIM 368
#define COOK 369
#define FLY 370
#define DRIVE 371
#define STUDY 372
#define WORK 373
#define PAINT 374
#define DRAW 375
#define LISTEN 376
#define HELP 377
#define CLEAN 378
#define BUILD 379
#define WATCH 380
#define TEACH 381
#define LEARN 382
#define DAILY 383
#define QUICKLY 384
#define SLOWLY 385
#define HAPPILY 386
#define SADLY 387
#define LOUDLY 388
#define QUIETLY 389
#define ALWAYS 390
#define NEVER 391
#define CAREFULLY 392
#define OFTEN 393
#define RARELY 394
#define SUDDENLY 395
#define ANXIOUSLY 396
#define CONFIDENTLY 397
#define EAGERLY 398
#define GRACEFULLY 399
#define SILLY 400
#define AWKWARDLY 401
#define CURIOUSLY 402
#define PATIENTLY 403
#define NERVOUSLY 404
#define DASH 405
#define EXCLAMATION 406

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "emoji.y"

    char *str;
    int num;
    int subject_flag;
    int adjective_flag;
    int verb_flag;
    int adverb_flag;

#line 492 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEW_LINE = 3,                   /* NEW_LINE  */
  YYSYMBOL_UNKNOWN_WORD = 4,               /* UNKNOWN_WORD  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_BIRD = 6,                       /* BIRD  */
  YYSYMBOL_DOG = 7,                        /* DOG  */
  YYSYMBOL_CAT = 8,                        /* CAT  */
  YYSYMBOL_TREE = 9,                       /* TREE  */
  YYSYMBOL_HOUSE = 10,                     /* HOUSE  */
  YYSYMBOL_CAR = 11,                       /* CAR  */
  YYSYMBOL_BOOK = 12,                      /* BOOK  */
  YYSYMBOL_COMPUTER = 13,                  /* COMPUTER  */
  YYSYMBOL_PHONE = 14,                     /* PHONE  */
  YYSYMBOL_FOOD = 15,                      /* FOOD  */
  YYSYMBOL_WATER = 16,                     /* WATER  */
  YYSYMBOL_SUN = 17,                       /* SUN  */
  YYSYMBOL_MOON = 18,                      /* MOON  */
  YYSYMBOL_STAR = 19,                      /* STAR  */
  YYSYMBOL_FLOWER = 20,                    /* FLOWER  */
  YYSYMBOL_BIRTHDAY = 21,                  /* BIRTHDAY  */
  YYSYMBOL_LUCK = 22,                      /* LUCK  */
  YYSYMBOL_CHRISTMAS = 23,                 /* CHRISTMAS  */
  YYSYMBOL_APPLE = 24,                     /* APPLE  */
  YYSYMBOL_BANANA = 25,                    /* BANANA  */
  YYSYMBOL_GRAPE = 26,                     /* GRAPE  */
  YYSYMBOL_ORANGE = 27,                    /* ORANGE  */
  YYSYMBOL_PEAR = 28,                      /* PEAR  */
  YYSYMBOL_STRAWBERRY = 29,                /* STRAWBERRY  */
  YYSYMBOL_LEMON = 30,                     /* LEMON  */
  YYSYMBOL_PEACH = 31,                     /* PEACH  */
  YYSYMBOL_PLUM = 32,                      /* PLUM  */
  YYSYMBOL_PINEAPPLE = 33,                 /* PINEAPPLE  */
  YYSYMBOL_CHAIR = 34,                     /* CHAIR  */
  YYSYMBOL_TABLE = 35,                     /* TABLE  */
  YYSYMBOL_DESK = 36,                      /* DESK  */
  YYSYMBOL_WINDOW = 37,                    /* WINDOW  */
  YYSYMBOL_DOOR = 38,                      /* DOOR  */
  YYSYMBOL_CUP = 39,                       /* CUP  */
  YYSYMBOL_BOTTLE = 40,                    /* BOTTLE  */
  YYSYMBOL_PEN = 41,                       /* PEN  */
  YYSYMBOL_PENCIL = 42,                    /* PENCIL  */
  YYSYMBOL_I = 43,                         /* I  */
  YYSYMBOL_ME = 44,                        /* ME  */
  YYSYMBOL_YOU = 45,                       /* YOU  */
  YYSYMBOL_HE = 46,                        /* HE  */
  YYSYMBOL_HIM = 47,                       /* HIM  */
  YYSYMBOL_SHE = 48,                       /* SHE  */
  YYSYMBOL_HER = 49,                       /* HER  */
  YYSYMBOL_IT = 50,                        /* IT  */
  YYSYMBOL_WE = 51,                        /* WE  */
  YYSYMBOL_US = 52,                        /* US  */
  YYSYMBOL_THEY = 53,                      /* THEY  */
  YYSYMBOL_THEM = 54,                      /* THEM  */
  YYSYMBOL_MERRY = 55,                     /* MERRY  */
  YYSYMBOL_LITTLE = 56,                    /* LITTLE  */
  YYSYMBOL_BIG = 57,                       /* BIG  */
  YYSYMBOL_FEW = 58,                       /* FEW  */
  YYSYMBOL_BEAUTIFUL = 59,                 /* BEAUTIFUL  */
  YYSYMBOL_UGLY = 60,                      /* UGLY  */
  YYSYMBOL_NICE = 61,                      /* NICE  */
  YYSYMBOL_HAPPY = 62,                     /* HAPPY  */
  YYSYMBOL_SAD = 63,                       /* SAD  */
  YYSYMBOL_ANGRY = 64,                     /* ANGRY  */
  YYSYMBOL_FAST = 65,                      /* FAST  */
  YYSYMBOL_SLOW = 66,                      /* SLOW  */
  YYSYMBOL_STRONG = 67,                    /* STRONG  */
  YYSYMBOL_WEAK = 68,                      /* WEAK  */
  YYSYMBOL_SMART = 69,                     /* SMART  */
  YYSYMBOL_DUMB = 70,                      /* DUMB  */
  YYSYMBOL_OLD = 71,                       /* OLD  */
  YYSYMBOL_YOUNG = 72,                     /* YOUNG  */
  YYSYMBOL_HOT = 73,                       /* HOT  */
  YYSYMBOL_COLD = 74,                      /* COLD  */
  YYSYMBOL_GOOD = 75,                      /* GOOD  */
  YYSYMBOL_COOL = 76,                      /* COOL  */
  YYSYMBOL_FUNNY = 77,                     /* FUNNY  */
  YYSYMBOL_SCARY = 78,                     /* SCARY  */
  YYSYMBOL_BRAVE = 79,                     /* BRAVE  */
  YYSYMBOL_CLEVER = 80,                    /* CLEVER  */
  YYSYMBOL_LAZY = 81,                      /* LAZY  */
  YYSYMBOL_BUSY = 82,                      /* BUSY  */
  YYSYMBOL_QUIET = 83,                     /* QUIET  */
  YYSYMBOL_LOUD = 84,                      /* LOUD  */
  YYSYMBOL_DIRTY = 85,                     /* DIRTY  */
  YYSYMBOL_CONFUSED = 86,                  /* CONFUSED  */
  YYSYMBOL_SHY = 87,                       /* SHY  */
  YYSYMBOL_FRIENDLY = 88,                  /* FRIENDLY  */
  YYSYMBOL_ALONE = 89,                     /* ALONE  */
  YYSYMBOL_CREATIVE = 90,                  /* CREATIVE  */
  YYSYMBOL_SERIOUS = 91,                   /* SERIOUS  */
  YYSYMBOL_EXCITED = 92,                   /* EXCITED  */
  YYSYMBOL_GRATEFUL = 93,                  /* GRATEFUL  */
  YYSYMBOL_HOPEFUL = 94,                   /* HOPEFUL  */
  YYSYMBOL_PROUD = 95,                     /* PROUD  */
  YYSYMBOL_TIRED = 96,                     /* TIRED  */
  YYSYMBOL_RELAXED = 97,                   /* RELAXED  */
  YYSYMBOL_STRESSED = 98,                  /* STRESSED  */
  YYSYMBOL_CALM = 99,                      /* CALM  */
  YYSYMBOL_ENERGETIC = 100,                /* ENERGETIC  */
  YYSYMBOL_WALK = 101,                     /* WALK  */
  YYSYMBOL_TALK = 102,                     /* TALK  */
  YYSYMBOL_DRINK = 103,                    /* DRINK  */
  YYSYMBOL_EAT = 104,                      /* EAT  */
  YYSYMBOL_SLEEP = 105,                    /* SLEEP  */
  YYSYMBOL_RUN = 106,                      /* RUN  */
  YYSYMBOL_READ = 107,                     /* READ  */
  YYSYMBOL_WRITE = 108,                    /* WRITE  */
  YYSYMBOL_PLAY = 109,                     /* PLAY  */
  YYSYMBOL_SING = 110,                     /* SING  */
  YYSYMBOL_DANCE = 111,                    /* DANCE  */
  YYSYMBOL_JUMP = 112,                     /* JUMP  */
  YYSYMBOL_SWIM = 113,                     /* SWIM  */
  YYSYMBOL_COOK = 114,                     /* COOK  */
  YYSYMBOL_FLY = 115,                      /* FLY  */
  YYSYMBOL_DRIVE = 116,                    /* DRIVE  */
  YYSYMBOL_STUDY = 117,                    /* STUDY  */
  YYSYMBOL_WORK = 118,                     /* WORK  */
  YYSYMBOL_PAINT = 119,                    /* PAINT  */
  YYSYMBOL_DRAW = 120,                     /* DRAW  */
  YYSYMBOL_LISTEN = 121,                   /* LISTEN  */
  YYSYMBOL_HELP = 122,                     /* HELP  */
  YYSYMBOL_CLEAN = 123,                    /* CLEAN  */
  YYSYMBOL_BUILD = 124,                    /* BUILD  */
  YYSYMBOL_WATCH = 125,                    /* WATCH  */
  YYSYMBOL_TEACH = 126,                    /* TEACH  */
  YYSYMBOL_LEARN = 127,                    /* LEARN  */
  YYSYMBOL_DAILY = 128,                    /* DAILY  */
  YYSYMBOL_QUICKLY = 129,                  /* QUICKLY  */
  YYSYMBOL_SLOWLY = 130,                   /* SLOWLY  */
  YYSYMBOL_HAPPILY = 131,                  /* HAPPILY  */
  YYSYMBOL_SADLY = 132,                    /* SADLY  */
  YYSYMBOL_LOUDLY = 133,                   /* LOUDLY  */
  YYSYMBOL_QUIETLY = 134,                  /* QUIETLY  */
  YYSYMBOL_ALWAYS = 135,                   /* ALWAYS  */
  YYSYMBOL_NEVER = 136,                    /* NEVER  */
  YYSYMBOL_CAREFULLY = 137,                /* CAREFULLY  */
  YYSYMBOL_OFTEN = 138,                    /* OFTEN  */
  YYSYMBOL_RARELY = 139,                   /* RARELY  */
  YYSYMBOL_SUDDENLY = 140,                 /* SUDDENLY  */
  YYSYMBOL_ANXIOUSLY = 141,                /* ANXIOUSLY  */
  YYSYMBOL_CONFIDENTLY = 142,              /* CONFIDENTLY  */
  YYSYMBOL_EAGERLY = 143,                  /* EAGERLY  */
  YYSYMBOL_GRACEFULLY = 144,               /* GRACEFULLY  */
  YYSYMBOL_SILLY = 145,                    /* SILLY  */
  YYSYMBOL_AWKWARDLY = 146,                /* AWKWARDLY  */
  YYSYMBOL_CURIOUSLY = 147,                /* CURIOUSLY  */
  YYSYMBOL_PATIENTLY = 148,                /* PATIENTLY  */
  YYSYMBOL_NERVOUSLY = 149,                /* NERVOUSLY  */
  YYSYMBOL_DASH = 150,                     /* DASH  */
  YYSYMBOL_EXCLAMATION = 151,              /* EXCLAMATION  */
  YYSYMBOL_152_ = 152,                     /* ','  */
  YYSYMBOL_YYACCEPT = 153,                 /* $accept  */
  YYSYMBOL_poem = 154,                     /* poem  */
  YYSYMBOL_lines = 155,                    /* lines  */
  YYSYMBOL_line = 156,                     /* line  */
  YYSYMBOL_sentences = 157,                /* sentences  */
  YYSYMBOL_sentence = 158,                 /* sentence  */
  YYSYMBOL_counted_noun = 159,             /* counted_noun  */
  YYSYMBOL_subject = 160,                  /* subject  */
  YYSYMBOL_counted_nouns = 161,            /* counted_nouns  */
  YYSYMBOL_adjective_aux = 162,            /* adjective_aux  */
  YYSYMBOL_verb_aux = 163,                 /* verb_aux  */
  YYSYMBOL_adverb_aux = 164,               /* adverb_aux  */
  YYSYMBOL_pronoun_aux = 165,              /* pronoun_aux  */
  YYSYMBOL_unknown_word = 166,             /* unknown_word  */
  YYSYMBOL_number = 167,                   /* number  */
  YYSYMBOL_noun = 168,                     /* noun  */
  YYSYMBOL_adjective = 169,                /* adjective  */
  YYSYMBOL_verb = 170,                     /* verb  */
  YYSYMBOL_adverb = 171,                   /* adverb  */
  YYSYMBOL_pronoun = 172                   /* pronoun  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  166
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   643

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  153
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   406


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   152,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    97,    98,   102,   114,   115,   116,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   145,   146,   147,   148,   154,   155,
     159,   160,   164,   171,   177,   183,   189,   196,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NEW_LINE",
  "UNKNOWN_WORD", "NUMBER", "BIRD", "DOG", "CAT", "TREE", "HOUSE", "CAR",
  "BOOK", "COMPUTER", "PHONE", "FOOD", "WATER", "SUN", "MOON", "STAR",
  "FLOWER", "BIRTHDAY", "LUCK", "CHRISTMAS", "APPLE", "BANANA", "GRAPE",
  "ORANGE", "PEAR", "STRAWBERRY", "LEMON", "PEACH", "PLUM", "PINEAPPLE",
  "CHAIR", "TABLE", "DESK", "WINDOW", "DOOR", "CUP", "BOTTLE", "PEN",
  "PENCIL", "I", "ME", "YOU", "HE", "HIM", "SHE", "HER", "IT", "WE", "US",
  "THEY", "THEM", "MERRY", "LITTLE", "BIG", "FEW", "BEAUTIFUL", "UGLY",
  "NICE", "HAPPY", "SAD", "ANGRY", "FAST", "SLOW", "STRONG", "WEAK",
  "SMART", "DUMB", "OLD", "YOUNG", "HOT", "COLD", "GOOD", "COOL", "FUNNY",
  "SCARY", "BRAVE", "CLEVER", "LAZY", "BUSY", "QUIET", "LOUD", "DIRTY",
  "CONFUSED", "SHY", "FRIENDLY", "ALONE", "CREATIVE", "SERIOUS", "EXCITED",
  "GRATEFUL", "HOPEFUL", "PROUD", "TIRED", "RELAXED", "STRESSED", "CALM",
  "ENERGETIC", "WALK", "TALK", "DRINK", "EAT", "SLEEP", "RUN", "READ",
  "WRITE", "PLAY", "SING", "DANCE", "JUMP", "SWIM", "COOK", "FLY", "DRIVE",
  "STUDY", "WORK", "PAINT", "DRAW", "LISTEN", "HELP", "CLEAN", "BUILD",
  "WATCH", "TEACH", "LEARN", "DAILY", "QUICKLY", "SLOWLY", "HAPPILY",
  "SADLY", "LOUDLY", "QUIETLY", "ALWAYS", "NEVER", "CAREFULLY", "OFTEN",
  "RARELY", "SUDDENLY", "ANXIOUSLY", "CONFIDENTLY", "EAGERLY",
  "GRACEFULLY", "SILLY", "AWKWARDLY", "CURIOUSLY", "PATIENTLY",
  "NERVOUSLY", "DASH", "EXCLAMATION", "','", "$accept", "poem", "lines",
  "line", "sentences", "sentence", "counted_noun", "subject",
  "counted_nouns", "adjective_aux", "verb_aux", "adverb_aux",
  "pronoun_aux", "unknown_word", "number", "noun", "adjective", "verb",
  "adverb", "pronoun", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-4)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-9)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     143,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,   563,    -4,    -3,
     561,   143,   414,   238,    -4,   383,    -4,    -4,    -4,    -4,
     519,   562,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
     482,   493,   494,   493,   337,    -4,    -4,    -4,   494,    -4,
      -4,   494,   493,    -4,    -4,    -4
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     170,   177,   171,   172,   178,   173,   179,   174,   175,   180,
     176,   181,    79,    75,    76,    77,    78,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,     0,     2,     4,
       0,     7,    31,    19,    28,    21,    18,    22,    29,    20,
      27,    24,    32,    33,    34,    35,     1,     3,     5,     6,
       0,     0,    16,     0,    17,    25,    26,    30,    12,    15,
      14,    13,     0,     9,    10,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
      -4,    -4,   419,    -4,   418,    -4,    -4,   415,   401,   420,
     409,   412,    -4,    -4,   411,   416,    -4,    -4,    -4,    -4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      -8,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   172,   166,   168,   173,   170,     2,   167,   169,
     174,   177,   176,   171,     0,     0,   175,     0,     0,     0,
     178,     0,   180,   181,   179,     0,   182,     0,     0,     0,
     183,   185,     0,   184,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   153,     0,     3,   153,   152,     5,   149,   151,
     155,   170,   161,   153,    -1,    -1,   160,    -1,    -1,    -1,
     171,    -1,   173,   174,   172,    -1,   174,    -1,    -1,    -1,
     178,   182,    -1,   181,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,   155,     3,   157,
     152,   162,   163,   164,   160,   168,   167,   161,   163,   164,
     163,   163,   164,   164,   164,   163
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   153,   154,   155,   155,   156,   157,   157,   157,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   159,   159,   159,   159,   160,   160,
     161,   161,   162,   163,   164,   165,   166,   167,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     0,     4,
       4,     4,     3,     3,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     0,     1,     2,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* line: sentences NEW_LINE  */
#line 102 "emoji.y"
                       {
        //printf("\n--------this is the end of line, catched: %s \n", buffer);
        replace_expressions_in_buffer();
        //printf("\n--------this is the end of line, catched with expressions: %s \n", buffer);
        printf("%s\n",buffer);
        buffer[0] = '\0';
    }
#line 1911 "y.tab.c"
    break;

  case 24: /* counted_noun: noun  */
#line 145 "emoji.y"
         {print_emoji((yyvsp[0].str), 1);}
#line 1917 "y.tab.c"
    break;

  case 25: /* counted_noun: number noun  */
#line 146 "emoji.y"
                  { print_emoji((yyvsp[0].str), (yyvsp[-1].num)); }
#line 1923 "y.tab.c"
    break;

  case 26: /* counted_noun: noun number  */
#line 147 "emoji.y"
                  { print_emoji((yyvsp[-1].str), (yyvsp[0].num)); }
#line 1929 "y.tab.c"
    break;

  case 27: /* counted_noun: number  */
#line 148 "emoji.y"
             {
        save_buffer((yyvsp[0].num));}
#line 1936 "y.tab.c"
    break;

  case 32: /* adjective_aux: adjective  */
#line 164 "emoji.y"
              {
        //printf("%s ",$1);
        save_buffer((yyvsp[0].str));
     }
#line 1945 "y.tab.c"
    break;

  case 33: /* verb_aux: verb  */
#line 171 "emoji.y"
         {
        //printf("%s ",$1); 
        save_buffer((yyvsp[0].str));}
#line 1953 "y.tab.c"
    break;

  case 34: /* adverb_aux: adverb  */
#line 177 "emoji.y"
           {
        //printf("%s ",$1); 
        save_buffer((yyvsp[0].str));}
#line 1961 "y.tab.c"
    break;

  case 35: /* pronoun_aux: pronoun  */
#line 183 "emoji.y"
            {
        //printf("%s ",$1); 
        save_buffer((yyvsp[0].str));}
#line 1969 "y.tab.c"
    break;

  case 36: /* unknown_word: UNKNOWN_WORD  */
#line 189 "emoji.y"
                    {
        //$$ = $1; printf("####### %s\n", $$); 
        (yyval.str) = replace_unknown_word_with_emojis((yyvsp[0].str));
        save_buffer((yyval.str));
        }
#line 1979 "y.tab.c"
    break;

  case 37: /* number: NUMBER  */
#line 196 "emoji.y"
                 { (yyval.num) = (yyvsp[0].num); }
#line 1985 "y.tab.c"
    break;

  case 38: /* noun: BIRD  */
#line 199 "emoji.y"
                 { (yyval.str) = "🐦";}
#line 1991 "y.tab.c"
    break;

  case 39: /* noun: DOG  */
#line 200 "emoji.y"
                 { (yyval.str) = "🐶"; }
#line 1997 "y.tab.c"
    break;

  case 40: /* noun: CAT  */
#line 201 "emoji.y"
                 { (yyval.str) = "🐱"; }
#line 2003 "y.tab.c"
    break;

  case 41: /* noun: TREE  */
#line 202 "emoji.y"
                 { (yyval.str) = "🌳"; }
#line 2009 "y.tab.c"
    break;

  case 42: /* noun: HOUSE  */
#line 203 "emoji.y"
                 { (yyval.str) = "🏠"; }
#line 2015 "y.tab.c"
    break;

  case 43: /* noun: CAR  */
#line 204 "emoji.y"
                 { (yyval.str) = "🚗"; }
#line 2021 "y.tab.c"
    break;

  case 44: /* noun: BOOK  */
#line 205 "emoji.y"
                 { (yyval.str) = "📖"; }
#line 2027 "y.tab.c"
    break;

  case 45: /* noun: COMPUTER  */
#line 206 "emoji.y"
                 { (yyval.str) = "💻"; }
#line 2033 "y.tab.c"
    break;

  case 46: /* noun: PHONE  */
#line 207 "emoji.y"
                 { (yyval.str) = "📱"; }
#line 2039 "y.tab.c"
    break;

  case 47: /* noun: FOOD  */
#line 208 "emoji.y"
                 { (yyval.str) = "🍲"; }
#line 2045 "y.tab.c"
    break;

  case 48: /* noun: WATER  */
#line 209 "emoji.y"
                 { (yyval.str) = "💧"; }
#line 2051 "y.tab.c"
    break;

  case 49: /* noun: SUN  */
#line 210 "emoji.y"
                 { (yyval.str) = "☀️"; }
#line 2057 "y.tab.c"
    break;

  case 50: /* noun: MOON  */
#line 211 "emoji.y"
                 { (yyval.str) = "🌜"; }
#line 2063 "y.tab.c"
    break;

  case 51: /* noun: STAR  */
#line 212 "emoji.y"
                 { (yyval.str) = "⭐"; }
#line 2069 "y.tab.c"
    break;

  case 52: /* noun: FLOWER  */
#line 213 "emoji.y"
                 { (yyval.str) = "🌸"; }
#line 2075 "y.tab.c"
    break;

  case 53: /* noun: BIRTHDAY  */
#line 214 "emoji.y"
                 { (yyval.str) = "🎂"; }
#line 2081 "y.tab.c"
    break;

  case 54: /* noun: LUCK  */
#line 215 "emoji.y"
                 { (yyval.str) = "🍀";}
#line 2087 "y.tab.c"
    break;

  case 55: /* noun: CHRISTMAS  */
#line 216 "emoji.y"
                 { (yyval.str) = "🎅🏻";}
#line 2093 "y.tab.c"
    break;

  case 56: /* noun: APPLE  */
#line 217 "emoji.y"
                 { (yyval.str) = "🍎";}
#line 2099 "y.tab.c"
    break;

  case 57: /* noun: BANANA  */
#line 218 "emoji.y"
                 { (yyval.str) = "🍌";}
#line 2105 "y.tab.c"
    break;

  case 58: /* noun: GRAPE  */
#line 219 "emoji.y"
                 { (yyval.str) = "🍇";}
#line 2111 "y.tab.c"
    break;

  case 59: /* noun: ORANGE  */
#line 220 "emoji.y"
                 { (yyval.str) = "🍊";}
#line 2117 "y.tab.c"
    break;

  case 60: /* noun: PEAR  */
#line 221 "emoji.y"
                 { (yyval.str) = "🍐";}
#line 2123 "y.tab.c"
    break;

  case 61: /* noun: STRAWBERRY  */
#line 222 "emoji.y"
                 { (yyval.str) = "🍓";}
#line 2129 "y.tab.c"
    break;

  case 62: /* noun: LEMON  */
#line 223 "emoji.y"
                 { (yyval.str) = "🍋";}
#line 2135 "y.tab.c"
    break;

  case 63: /* noun: PEACH  */
#line 224 "emoji.y"
                 { (yyval.str) = "🍑";}
#line 2141 "y.tab.c"
    break;

  case 64: /* noun: PLUM  */
#line 225 "emoji.y"
                 { (yyval.str) = "🍑";}
#line 2147 "y.tab.c"
    break;

  case 65: /* noun: PINEAPPLE  */
#line 226 "emoji.y"
                 { (yyval.str) = "🍍";}
#line 2153 "y.tab.c"
    break;

  case 66: /* noun: CHAIR  */
#line 227 "emoji.y"
                 { (yyval.str) = "🪑";}
#line 2159 "y.tab.c"
    break;

  case 67: /* noun: TABLE  */
#line 228 "emoji.y"
                 { (yyval.str) = "🪑";}
#line 2165 "y.tab.c"
    break;

  case 68: /* noun: DESK  */
#line 229 "emoji.y"
                 { (yyval.str) = "🪑";}
#line 2171 "y.tab.c"
    break;

  case 69: /* noun: WINDOW  */
#line 230 "emoji.y"
                 { (yyval.str) = "🪟";}
#line 2177 "y.tab.c"
    break;

  case 70: /* noun: DOOR  */
#line 231 "emoji.y"
                 { (yyval.str) = "🚪";}
#line 2183 "y.tab.c"
    break;

  case 71: /* noun: CUP  */
#line 232 "emoji.y"
                 { (yyval.str) = "☕";}
#line 2189 "y.tab.c"
    break;

  case 72: /* noun: BOTTLE  */
#line 233 "emoji.y"
                 { (yyval.str) = "🍾";}
#line 2195 "y.tab.c"
    break;

  case 73: /* noun: PEN  */
#line 234 "emoji.y"
                 { (yyval.str) = "✒️";}
#line 2201 "y.tab.c"
    break;

  case 74: /* noun: PENCIL  */
#line 235 "emoji.y"
                 { (yyval.str) = "✏️";}
#line 2207 "y.tab.c"
    break;

  case 75: /* adjective: LITTLE  */
#line 240 "emoji.y"
                 { (yyval.str) = "🤏"; }
#line 2213 "y.tab.c"
    break;

  case 76: /* adjective: BIG  */
#line 241 "emoji.y"
                 { (yyval.str) = "💪"; }
#line 2219 "y.tab.c"
    break;

  case 77: /* adjective: FEW  */
#line 242 "emoji.y"
                 { (yyval.str) = "✌️"; }
#line 2225 "y.tab.c"
    break;

  case 78: /* adjective: BEAUTIFUL  */
#line 243 "emoji.y"
                 { (yyval.str) = "🌸"; }
#line 2231 "y.tab.c"
    break;

  case 79: /* adjective: MERRY  */
#line 244 "emoji.y"
                 { (yyval.str) = "😇"; }
#line 2237 "y.tab.c"
    break;

  case 80: /* adjective: UGLY  */
#line 245 "emoji.y"
                 { (yyval.str) = "👹"; }
#line 2243 "y.tab.c"
    break;

  case 81: /* adjective: NICE  */
#line 246 "emoji.y"
                 { (yyval.str) = "😊"; }
#line 2249 "y.tab.c"
    break;

  case 82: /* adjective: HAPPY  */
#line 247 "emoji.y"
                 { (yyval.str) = "😃"; }
#line 2255 "y.tab.c"
    break;

  case 83: /* adjective: SAD  */
#line 248 "emoji.y"
                 { (yyval.str) = "😢"; }
#line 2261 "y.tab.c"
    break;

  case 84: /* adjective: ANGRY  */
#line 249 "emoji.y"
                 { (yyval.str) = "😠"; }
#line 2267 "y.tab.c"
    break;

  case 85: /* adjective: FAST  */
#line 250 "emoji.y"
                 { (yyval.str) = "🏃‍♂️"; }
#line 2273 "y.tab.c"
    break;

  case 86: /* adjective: SLOW  */
#line 251 "emoji.y"
                 { (yyval.str) = "🐌"; }
#line 2279 "y.tab.c"
    break;

  case 87: /* adjective: STRONG  */
#line 252 "emoji.y"
                 { (yyval.str) = "💪"; }
#line 2285 "y.tab.c"
    break;

  case 88: /* adjective: WEAK  */
#line 253 "emoji.y"
                 { (yyval.str) = "🦠"; }
#line 2291 "y.tab.c"
    break;

  case 89: /* adjective: SMART  */
#line 254 "emoji.y"
                 { (yyval.str) = "🧠"; }
#line 2297 "y.tab.c"
    break;

  case 90: /* adjective: DUMB  */
#line 255 "emoji.y"
                 { (yyval.str) = "🤪"; }
#line 2303 "y.tab.c"
    break;

  case 91: /* adjective: OLD  */
#line 256 "emoji.y"
                 { (yyval.str) = "👴"; }
#line 2309 "y.tab.c"
    break;

  case 92: /* adjective: YOUNG  */
#line 257 "emoji.y"
                 { (yyval.str) = "👶"; }
#line 2315 "y.tab.c"
    break;

  case 93: /* adjective: HOT  */
#line 258 "emoji.y"
                 { (yyval.str) = "🔥"; }
#line 2321 "y.tab.c"
    break;

  case 94: /* adjective: COLD  */
#line 259 "emoji.y"
                 { (yyval.str) = "❄️"; }
#line 2327 "y.tab.c"
    break;

  case 95: /* adjective: GOOD  */
#line 260 "emoji.y"
                 { (yyval.str) = "👍"; }
#line 2333 "y.tab.c"
    break;

  case 96: /* adjective: COOL  */
#line 261 "emoji.y"
                 { (yyval.str) = "😎"; }
#line 2339 "y.tab.c"
    break;

  case 97: /* adjective: FUNNY  */
#line 262 "emoji.y"
                 { (yyval.str) = "😆"; }
#line 2345 "y.tab.c"
    break;

  case 98: /* adjective: SCARY  */
#line 263 "emoji.y"
                 { (yyval.str) = "😱"; }
#line 2351 "y.tab.c"
    break;

  case 99: /* adjective: BRAVE  */
#line 264 "emoji.y"
                 { (yyval.str) = "🦸‍"; }
#line 2357 "y.tab.c"
    break;

  case 100: /* adjective: CLEVER  */
#line 265 "emoji.y"
                 { (yyval.str) = "🤓"; }
#line 2363 "y.tab.c"
    break;

  case 101: /* adjective: LAZY  */
#line 266 "emoji.y"
                 { (yyval.str) = "😴"; }
#line 2369 "y.tab.c"
    break;

  case 102: /* adjective: BUSY  */
#line 267 "emoji.y"
                 { (yyval.str) = "💼"; }
#line 2375 "y.tab.c"
    break;

  case 103: /* adjective: QUIET  */
#line 268 "emoji.y"
                 { (yyval.str) = "🤫"; }
#line 2381 "y.tab.c"
    break;

  case 104: /* adjective: LOUD  */
#line 269 "emoji.y"
                 { (yyval.str) = "🔊"; }
#line 2387 "y.tab.c"
    break;

  case 105: /* adjective: DIRTY  */
#line 270 "emoji.y"
                 { (yyval.str) = "🧻"; }
#line 2393 "y.tab.c"
    break;

  case 106: /* adjective: CONFUSED  */
#line 271 "emoji.y"
                 { (yyval.str) = "😕"; }
#line 2399 "y.tab.c"
    break;

  case 107: /* adjective: SHY  */
#line 272 "emoji.y"
                 { (yyval.str) = "🙈"; }
#line 2405 "y.tab.c"
    break;

  case 108: /* adjective: FRIENDLY  */
#line 273 "emoji.y"
                 { (yyval.str) = "👋"; }
#line 2411 "y.tab.c"
    break;

  case 109: /* adjective: ALONE  */
#line 274 "emoji.y"
                 { (yyval.str) = "🚶‍♂️"; }
#line 2417 "y.tab.c"
    break;

  case 110: /* adjective: CREATIVE  */
#line 275 "emoji.y"
                 { (yyval.str) = "🎨"; }
#line 2423 "y.tab.c"
    break;

  case 111: /* adjective: SERIOUS  */
#line 276 "emoji.y"
                 { (yyval.str) = "😐"; }
#line 2429 "y.tab.c"
    break;

  case 112: /* adjective: EXCITED  */
#line 277 "emoji.y"
                 { (yyval.str) = "😁"; }
#line 2435 "y.tab.c"
    break;

  case 113: /* adjective: GRATEFUL  */
#line 278 "emoji.y"
                 { (yyval.str) = "🙏"; }
#line 2441 "y.tab.c"
    break;

  case 114: /* adjective: HOPEFUL  */
#line 279 "emoji.y"
                 { (yyval.str) = "🤞"; }
#line 2447 "y.tab.c"
    break;

  case 115: /* adjective: PROUD  */
#line 280 "emoji.y"
                 { (yyval.str) = "🏆"; }
#line 2453 "y.tab.c"
    break;

  case 116: /* adjective: TIRED  */
#line 281 "emoji.y"
                 { (yyval.str) = "😴"; }
#line 2459 "y.tab.c"
    break;

  case 117: /* adjective: RELAXED  */
#line 282 "emoji.y"
                 { (yyval.str) = "😌"; }
#line 2465 "y.tab.c"
    break;

  case 118: /* adjective: STRESSED  */
#line 283 "emoji.y"
                 { (yyval.str) = "😩"; }
#line 2471 "y.tab.c"
    break;

  case 119: /* adjective: CALM  */
#line 284 "emoji.y"
                 { (yyval.str) = "😌"; }
#line 2477 "y.tab.c"
    break;

  case 120: /* adjective: ENERGETIC  */
#line 285 "emoji.y"
                 { (yyval.str) = "💥"; }
#line 2483 "y.tab.c"
    break;

  case 121: /* verb: WALK  */
#line 291 "emoji.y"
              { (yyval.str) = "🚶"; }
#line 2489 "y.tab.c"
    break;

  case 122: /* verb: TALK  */
#line 292 "emoji.y"
                { (yyval.str) = "🗣️"; }
#line 2495 "y.tab.c"
    break;

  case 123: /* verb: DRINK  */
#line 293 "emoji.y"
                { (yyval.str) = "🥤"; }
#line 2501 "y.tab.c"
    break;

  case 124: /* verb: EAT  */
#line 294 "emoji.y"
                { (yyval.str) = "🍽️"; }
#line 2507 "y.tab.c"
    break;

  case 125: /* verb: SLEEP  */
#line 295 "emoji.y"
                { (yyval.str) = "😴"; }
#line 2513 "y.tab.c"
    break;

  case 126: /* verb: RUN  */
#line 296 "emoji.y"
                { (yyval.str) = "🏃"; }
#line 2519 "y.tab.c"
    break;

  case 127: /* verb: READ  */
#line 297 "emoji.y"
                { (yyval.str) = "📖"; }
#line 2525 "y.tab.c"
    break;

  case 128: /* verb: WRITE  */
#line 298 "emoji.y"
                { (yyval.str) = "✍️"; }
#line 2531 "y.tab.c"
    break;

  case 129: /* verb: PLAY  */
#line 299 "emoji.y"
                { (yyval.str) = "🎮"; }
#line 2537 "y.tab.c"
    break;

  case 130: /* verb: SING  */
#line 300 "emoji.y"
                { (yyval.str) = "🎤"; }
#line 2543 "y.tab.c"
    break;

  case 131: /* verb: DANCE  */
#line 301 "emoji.y"
                { (yyval.str) = "💃"; }
#line 2549 "y.tab.c"
    break;

  case 132: /* verb: JUMP  */
#line 302 "emoji.y"
                { (yyval.str) = "🤸"; }
#line 2555 "y.tab.c"
    break;

  case 133: /* verb: SWIM  */
#line 303 "emoji.y"
                { (yyval.str) = "🏊"; }
#line 2561 "y.tab.c"
    break;

  case 134: /* verb: COOK  */
#line 304 "emoji.y"
                { (yyval.str) = "👩‍🍳"; }
#line 2567 "y.tab.c"
    break;

  case 135: /* verb: FLY  */
#line 305 "emoji.y"
                { (yyval.str) = "✈️"; }
#line 2573 "y.tab.c"
    break;

  case 136: /* verb: DRIVE  */
#line 306 "emoji.y"
                { (yyval.str) = "🚗"; }
#line 2579 "y.tab.c"
    break;

  case 137: /* verb: STUDY  */
#line 307 "emoji.y"
                { (yyval.str) = "📚"; }
#line 2585 "y.tab.c"
    break;

  case 138: /* verb: WORK  */
#line 308 "emoji.y"
                { (yyval.str) = "💼"; }
#line 2591 "y.tab.c"
    break;

  case 139: /* verb: PAINT  */
#line 309 "emoji.y"
                { (yyval.str) = "🎨"; }
#line 2597 "y.tab.c"
    break;

  case 140: /* verb: DRAW  */
#line 310 "emoji.y"
                { (yyval.str) = "✏️"; }
#line 2603 "y.tab.c"
    break;

  case 141: /* verb: LISTEN  */
#line 311 "emoji.y"
                { (yyval.str) = "👂"; }
#line 2609 "y.tab.c"
    break;

  case 142: /* verb: HELP  */
#line 312 "emoji.y"
                { (yyval.str) = "🤝"; }
#line 2615 "y.tab.c"
    break;

  case 143: /* verb: CLEAN  */
#line 313 "emoji.y"
                { (yyval.str) = "🧹"; }
#line 2621 "y.tab.c"
    break;

  case 144: /* verb: BUILD  */
#line 314 "emoji.y"
                { (yyval.str) = "🔨"; }
#line 2627 "y.tab.c"
    break;

  case 145: /* verb: WATCH  */
#line 315 "emoji.y"
                { (yyval.str) = "👀"; }
#line 2633 "y.tab.c"
    break;

  case 146: /* verb: TEACH  */
#line 316 "emoji.y"
                { (yyval.str) = "👩‍🏫"; }
#line 2639 "y.tab.c"
    break;

  case 147: /* verb: LEARN  */
#line 317 "emoji.y"
                { (yyval.str) = "📝"; }
#line 2645 "y.tab.c"
    break;

  case 148: /* adverb: DAILY  */
#line 322 "emoji.y"
                 { (yyval.str) = "📅"; }
#line 2651 "y.tab.c"
    break;

  case 149: /* adverb: QUICKLY  */
#line 323 "emoji.y"
                  { (yyval.str) = "🏃‍"; }
#line 2657 "y.tab.c"
    break;

  case 150: /* adverb: SLOWLY  */
#line 324 "emoji.y"
                  { (yyval.str) = "🐢"; }
#line 2663 "y.tab.c"
    break;

  case 151: /* adverb: HAPPILY  */
#line 325 "emoji.y"
                  { (yyval.str) = "😊"; }
#line 2669 "y.tab.c"
    break;

  case 152: /* adverb: SADLY  */
#line 326 "emoji.y"
                  { (yyval.str) = "😢"; }
#line 2675 "y.tab.c"
    break;

  case 153: /* adverb: LOUDLY  */
#line 327 "emoji.y"
                  { (yyval.str) = "🔊"; }
#line 2681 "y.tab.c"
    break;

  case 154: /* adverb: QUIETLY  */
#line 328 "emoji.y"
                  { (yyval.str) = "🤫"; }
#line 2687 "y.tab.c"
    break;

  case 155: /* adverb: ALWAYS  */
#line 329 "emoji.y"
                  { (yyval.str) = "♾️"; }
#line 2693 "y.tab.c"
    break;

  case 156: /* adverb: NEVER  */
#line 330 "emoji.y"
                  { (yyval.str) = "🚫"; }
#line 2699 "y.tab.c"
    break;

  case 157: /* adverb: CAREFULLY  */
#line 331 "emoji.y"
                  { (yyval.str) = "🔍"; }
#line 2705 "y.tab.c"
    break;

  case 158: /* adverb: OFTEN  */
#line 332 "emoji.y"
                  { (yyval.str) = "🔁"; }
#line 2711 "y.tab.c"
    break;

  case 159: /* adverb: RARELY  */
#line 333 "emoji.y"
                  { (yyval.str) = "🔀"; }
#line 2717 "y.tab.c"
    break;

  case 160: /* adverb: SUDDENLY  */
#line 334 "emoji.y"
                  { (yyval.str) = "🌪️"; }
#line 2723 "y.tab.c"
    break;

  case 161: /* adverb: ANXIOUSLY  */
#line 335 "emoji.y"
                  { (yyval.str) = "😰"; }
#line 2729 "y.tab.c"
    break;

  case 162: /* adverb: CONFIDENTLY  */
#line 336 "emoji.y"
                  { (yyval.str) = "😎"; }
#line 2735 "y.tab.c"
    break;

  case 163: /* adverb: EAGERLY  */
#line 337 "emoji.y"
                  { (yyval.str) = "🤩"; }
#line 2741 "y.tab.c"
    break;

  case 164: /* adverb: GRACEFULLY  */
#line 338 "emoji.y"
                  { (yyval.str) = "🩰"; }
#line 2747 "y.tab.c"
    break;

  case 165: /* adverb: SILLY  */
#line 339 "emoji.y"
                  { (yyval.str) = "🤪"; }
#line 2753 "y.tab.c"
    break;

  case 166: /* adverb: AWKWARDLY  */
#line 340 "emoji.y"
                  { (yyval.str) = "🙃"; }
#line 2759 "y.tab.c"
    break;

  case 167: /* adverb: CURIOUSLY  */
#line 341 "emoji.y"
                  { (yyval.str) = "🔍"; }
#line 2765 "y.tab.c"
    break;

  case 168: /* adverb: PATIENTLY  */
#line 342 "emoji.y"
                  { (yyval.str) = "⏳"; }
#line 2771 "y.tab.c"
    break;

  case 169: /* adverb: NERVOUSLY  */
#line 343 "emoji.y"
                  { (yyval.str) = "😬"; }
#line 2777 "y.tab.c"
    break;

  case 170: /* pronoun: I  */
#line 347 "emoji.y"
              { (yyval.str) = "👤"; }
#line 2783 "y.tab.c"
    break;

  case 171: /* pronoun: YOU  */
#line 348 "emoji.y"
               { (yyval.str) = "👥"; }
#line 2789 "y.tab.c"
    break;

  case 172: /* pronoun: HE  */
#line 349 "emoji.y"
               { (yyval.str) = "👦"; }
#line 2795 "y.tab.c"
    break;

  case 173: /* pronoun: SHE  */
#line 350 "emoji.y"
               { (yyval.str) = "👧"; }
#line 2801 "y.tab.c"
    break;

  case 174: /* pronoun: IT  */
#line 351 "emoji.y"
               { (yyval.str) = "👶"; }
#line 2807 "y.tab.c"
    break;

  case 175: /* pronoun: WE  */
#line 352 "emoji.y"
               { (yyval.str) = "👫"; }
#line 2813 "y.tab.c"
    break;

  case 176: /* pronoun: THEY  */
#line 353 "emoji.y"
               { (yyval.str) = "👬"; }
#line 2819 "y.tab.c"
    break;

  case 177: /* pronoun: ME  */
#line 354 "emoji.y"
               { (yyval.str) = "👤"; }
#line 2825 "y.tab.c"
    break;

  case 178: /* pronoun: HIM  */
#line 355 "emoji.y"
               { (yyval.str) = "👦"; }
#line 2831 "y.tab.c"
    break;

  case 179: /* pronoun: HER  */
#line 356 "emoji.y"
               { (yyval.str) = "👧"; }
#line 2837 "y.tab.c"
    break;

  case 180: /* pronoun: US  */
#line 357 "emoji.y"
               { (yyval.str) = "👫"; }
#line 2843 "y.tab.c"
    break;

  case 181: /* pronoun: THEM  */
#line 358 "emoji.y"
               { (yyval.str) = "👬"; }
#line 2849 "y.tab.c"
    break;


#line 2853 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 362 "emoji.y"


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
