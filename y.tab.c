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
    const char *name;       // Name of the lexical field
    const char **emojis;   // Array of emojis in the lexical field
    const char **keywords; // Array of keywords associated with the lexical field
    int num_keywords;
    int num_emoji;
} LexicalField;

const char *animal_emojis[] = {"🐦", "🐶", "🐱", "🐟", "🐍", "🐘"};
const char *animal_keywords[] = {"animal", "pet", "bird", "dog", "cat", "fish", "snake", "elephant",
                                  "mammal", "reptile", "bird", "feline", "canine"};

const char *object_emojis[] = {"🌳", "💻", "🚗", "📖", "💻", "📱"};
const char *object_keywords[] = {"object", "thing", "tree", "house", "car", "book", "computer", "phone",
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


#line 130 "y.tab.c"

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
    LITTLE = 279,                  /* LITTLE  */
    BIG = 280,                     /* BIG  */
    FEW = 281,                     /* FEW  */
    BEAUTIFUL = 282,               /* BEAUTIFUL  */
    UGLY = 283,                    /* UGLY  */
    NICE = 284,                    /* NICE  */
    HAPPY = 285,                   /* HAPPY  */
    SAD = 286,                     /* SAD  */
    ANGRY = 287,                   /* ANGRY  */
    FAST = 288,                    /* FAST  */
    SLOW = 289,                    /* SLOW  */
    STRONG = 290,                  /* STRONG  */
    WEAK = 291,                    /* WEAK  */
    SMART = 292,                   /* SMART  */
    DUMB = 293,                    /* DUMB  */
    OLD = 294,                     /* OLD  */
    YOUNG = 295,                   /* YOUNG  */
    HOT = 296,                     /* HOT  */
    COLD = 297,                    /* COLD  */
    GOOD = 298,                    /* GOOD  */
    WALK = 299,                    /* WALK  */
    TALK = 300,                    /* TALK  */
    DRINK = 301,                   /* DRINK  */
    EAT = 302,                     /* EAT  */
    SLEEP = 303,                   /* SLEEP  */
    RUN = 304,                     /* RUN  */
    READ = 305,                    /* READ  */
    WRITE = 306,                   /* WRITE  */
    PLAY = 307,                    /* PLAY  */
    SING = 308,                    /* SING  */
    DAILY = 309,                   /* DAILY  */
    QUICKLY = 310,                 /* QUICKLY  */
    SLOWLY = 311,                  /* SLOWLY  */
    HAPPILY = 312,                 /* HAPPILY  */
    SADLY = 313,                   /* SADLY  */
    LOUDLY = 314,                  /* LOUDLY  */
    QUIETLY = 315,                 /* QUIETLY  */
    ALWAYS = 316,                  /* ALWAYS  */
    NEVER = 317,                   /* NEVER  */
    DASH = 318,                    /* DASH  */
    EXCLAMATION = 319              /* EXCLAMATION  */
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
#define LITTLE 279
#define BIG 280
#define FEW 281
#define BEAUTIFUL 282
#define UGLY 283
#define NICE 284
#define HAPPY 285
#define SAD 286
#define ANGRY 287
#define FAST 288
#define SLOW 289
#define STRONG 290
#define WEAK 291
#define SMART 292
#define DUMB 293
#define OLD 294
#define YOUNG 295
#define HOT 296
#define COLD 297
#define GOOD 298
#define WALK 299
#define TALK 300
#define DRINK 301
#define EAT 302
#define SLEEP 303
#define RUN 304
#define READ 305
#define WRITE 306
#define PLAY 307
#define SING 308
#define DAILY 309
#define QUICKLY 310
#define SLOWLY 311
#define HAPPILY 312
#define SADLY 313
#define LOUDLY 314
#define QUIETLY 315
#define ALWAYS 316
#define NEVER 317
#define DASH 318
#define EXCLAMATION 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "emoji.y"

    char *str;
    int num;
    int plural_flag;
    int noun_flag;
    int adjective_flag;
    int verb_flag;
    int adverb_flag;

#line 318 "y.tab.c"

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
  YYSYMBOL_LITTLE = 24,                    /* LITTLE  */
  YYSYMBOL_BIG = 25,                       /* BIG  */
  YYSYMBOL_FEW = 26,                       /* FEW  */
  YYSYMBOL_BEAUTIFUL = 27,                 /* BEAUTIFUL  */
  YYSYMBOL_UGLY = 28,                      /* UGLY  */
  YYSYMBOL_NICE = 29,                      /* NICE  */
  YYSYMBOL_HAPPY = 30,                     /* HAPPY  */
  YYSYMBOL_SAD = 31,                       /* SAD  */
  YYSYMBOL_ANGRY = 32,                     /* ANGRY  */
  YYSYMBOL_FAST = 33,                      /* FAST  */
  YYSYMBOL_SLOW = 34,                      /* SLOW  */
  YYSYMBOL_STRONG = 35,                    /* STRONG  */
  YYSYMBOL_WEAK = 36,                      /* WEAK  */
  YYSYMBOL_SMART = 37,                     /* SMART  */
  YYSYMBOL_DUMB = 38,                      /* DUMB  */
  YYSYMBOL_OLD = 39,                       /* OLD  */
  YYSYMBOL_YOUNG = 40,                     /* YOUNG  */
  YYSYMBOL_HOT = 41,                       /* HOT  */
  YYSYMBOL_COLD = 42,                      /* COLD  */
  YYSYMBOL_GOOD = 43,                      /* GOOD  */
  YYSYMBOL_WALK = 44,                      /* WALK  */
  YYSYMBOL_TALK = 45,                      /* TALK  */
  YYSYMBOL_DRINK = 46,                     /* DRINK  */
  YYSYMBOL_EAT = 47,                       /* EAT  */
  YYSYMBOL_SLEEP = 48,                     /* SLEEP  */
  YYSYMBOL_RUN = 49,                       /* RUN  */
  YYSYMBOL_READ = 50,                      /* READ  */
  YYSYMBOL_WRITE = 51,                     /* WRITE  */
  YYSYMBOL_PLAY = 52,                      /* PLAY  */
  YYSYMBOL_SING = 53,                      /* SING  */
  YYSYMBOL_DAILY = 54,                     /* DAILY  */
  YYSYMBOL_QUICKLY = 55,                   /* QUICKLY  */
  YYSYMBOL_SLOWLY = 56,                    /* SLOWLY  */
  YYSYMBOL_HAPPILY = 57,                   /* HAPPILY  */
  YYSYMBOL_SADLY = 58,                     /* SADLY  */
  YYSYMBOL_LOUDLY = 59,                    /* LOUDLY  */
  YYSYMBOL_QUIETLY = 60,                   /* QUIETLY  */
  YYSYMBOL_ALWAYS = 61,                    /* ALWAYS  */
  YYSYMBOL_NEVER = 62,                     /* NEVER  */
  YYSYMBOL_DASH = 63,                      /* DASH  */
  YYSYMBOL_EXCLAMATION = 64,               /* EXCLAMATION  */
  YYSYMBOL_65_ = 65,                       /* ','  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_poem = 67,                      /* poem  */
  YYSYMBOL_lines = 68,                     /* lines  */
  YYSYMBOL_line = 69,                      /* line  */
  YYSYMBOL_sentences = 70,                 /* sentences  */
  YYSYMBOL_sentence = 71,                  /* sentence  */
  YYSYMBOL_counted_noun = 72,              /* counted_noun  */
  YYSYMBOL_counted_nouns = 73,             /* counted_nouns  */
  YYSYMBOL_adjective_aux = 74,             /* adjective_aux  */
  YYSYMBOL_verb_aux = 75,                  /* verb_aux  */
  YYSYMBOL_adverb_aux = 76,                /* adverb_aux  */
  YYSYMBOL_unknown_word = 77,              /* unknown_word  */
  YYSYMBOL_number = 78,                    /* number  */
  YYSYMBOL_noun = 79,                      /* noun  */
  YYSYMBOL_adjective = 80,                 /* adjective  */
  YYSYMBOL_verb = 81,                      /* verb  */
  YYSYMBOL_adverb = 82                     /* adverb  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  95

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    65,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    91,    91,    95,    96,   100,   112,   113,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     139,   140,   141,   142,   148,   149,   153,   160,   166,   172,
     179,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   239,
     240,   241,   242,   243,   244,   245,   246,   247
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
  "FLOWER", "BIRTHDAY", "LUCK", "CHRISTMAS", "LITTLE", "BIG", "FEW",
  "BEAUTIFUL", "UGLY", "NICE", "HAPPY", "SAD", "ANGRY", "FAST", "SLOW",
  "STRONG", "WEAK", "SMART", "DUMB", "OLD", "YOUNG", "HOT", "COLD", "GOOD",
  "WALK", "TALK", "DRINK", "EAT", "SLEEP", "RUN", "READ", "WRITE", "PLAY",
  "SING", "DAILY", "QUICKLY", "SLOWLY", "HAPPILY", "SADLY", "LOUDLY",
  "QUIETLY", "ALWAYS", "NEVER", "DASH", "EXCLAMATION", "','", "$accept",
  "poem", "lines", "line", "sentences", "sentence", "counted_noun",
  "counted_nouns", "adjective_aux", "verb_aux", "adverb_aux",
  "unknown_word", "number", "noun", "adjective", "verb", "adverb", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-5)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,   110,    -5,    -4,   109,    -4,    49,    26,    85,    -5,
      -5,   137,   111,    -5,    -5,    -5,    -5,    -5,    -5,    85,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,   128,
     129,   128,    -5,    80,    -5,    -5,    -5,   129,    -5,    -5,
     129,   128,    -5,    -5,    -5
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     2,     4,     0,     7,    25,    18,     0,    17,
      19,    23,    20,    26,    27,     1,     3,     5,     6,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
      15,     0,    28,    16,    21,    22,    24,    11,    14,    13,
      12,     0,     8,     9,    10
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -5,    -5,    64,    -5,    63,    -5,    -5,    51,    62,    32,
      81,    -5,    59,    61,    -5,    -5,    -5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      81,    60,    61,    62,    63,    64,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    80,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    83,
      65,    87,    67,    89,    69,    90,     2,    66,    68,    79,
      86,    85,    84,    94,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    88,     0,     0,    91,     0,     0,     0,    92,     0,
       0,    93,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78
};

static const yytype_int8 yycheck[] =
{
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    57,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    58,
       0,    79,     3,    81,    65,    83,     5,    53,    55,    57,
      69,    62,    61,    91,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    80,    -1,    -1,    83,    -1,    -1,    -1,    87,    -1,
      -1,    90,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      77,    78,    79,    80,    81,     0,    68,     3,    70,    65,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    74,
      75,    76,    82,    73,    79,    78,    73,    75,    76,    75,
      75,    76,    76,    76,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    73,    73,    74,    75,    76,    77,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     4,     4,
       4,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 100 "emoji.y"
                       {
        //printf("\n--------this is the end of line, catched: %s \n", buffer);
        replace_expressions_in_buffer();
        //printf("\n--------this is the end of line, catched with expressions: %s \n", buffer);
        printf("%s\n",buffer);
        buffer[0] = '\0';
    }
#line 1478 "y.tab.c"
    break;

  case 20: /* counted_noun: noun  */
#line 139 "emoji.y"
         {print_emoji((yyvsp[0].str), 1);}
#line 1484 "y.tab.c"
    break;

  case 21: /* counted_noun: number noun  */
#line 140 "emoji.y"
                  { print_emoji((yyvsp[0].str), (yyvsp[-1].num));}
#line 1490 "y.tab.c"
    break;

  case 22: /* counted_noun: noun number  */
#line 141 "emoji.y"
                  { print_emoji((yyvsp[-1].str), (yyvsp[0].num));}
#line 1496 "y.tab.c"
    break;

  case 23: /* counted_noun: number  */
#line 142 "emoji.y"
             {
        printf("%d ", (yyvsp[0].num)); 
        save_buffer((yyvsp[0].num));}
#line 1504 "y.tab.c"
    break;

  case 26: /* adjective_aux: adjective  */
#line 153 "emoji.y"
              {
        //printf("%s ",$1);
        save_buffer((yyvsp[0].str));
     }
#line 1513 "y.tab.c"
    break;

  case 27: /* verb_aux: verb  */
#line 160 "emoji.y"
         {
        //printf("%s ",$1); 
        save_buffer((yyvsp[0].str));}
#line 1521 "y.tab.c"
    break;

  case 28: /* adverb_aux: adverb  */
#line 166 "emoji.y"
           {
        //printf("%s ",$1); 
        save_buffer((yyvsp[0].str));}
#line 1529 "y.tab.c"
    break;

  case 29: /* unknown_word: UNKNOWN_WORD  */
#line 172 "emoji.y"
                    {
        //$$ = $1; printf("####### %s\n", $$); 
        (yyval.str) = replace_unknown_word_with_emojis((yyvsp[0].str));
        save_buffer((yyval.str));
        }
#line 1539 "y.tab.c"
    break;

  case 30: /* number: NUMBER  */
#line 179 "emoji.y"
                 { (yyval.num) = (yyvsp[0].num); }
#line 1545 "y.tab.c"
    break;

  case 31: /* noun: BIRD  */
#line 182 "emoji.y"
                 { (yyval.str) = "🐦";}
#line 1551 "y.tab.c"
    break;

  case 32: /* noun: DOG  */
#line 183 "emoji.y"
                 { (yyval.str) = "🐶"; }
#line 1557 "y.tab.c"
    break;

  case 33: /* noun: CAT  */
#line 184 "emoji.y"
                 { (yyval.str) = "🐱"; }
#line 1563 "y.tab.c"
    break;

  case 34: /* noun: TREE  */
#line 185 "emoji.y"
                 { (yyval.str) = "🌳"; }
#line 1569 "y.tab.c"
    break;

  case 35: /* noun: HOUSE  */
#line 186 "emoji.y"
                 { (yyval.str) = "🏠"; }
#line 1575 "y.tab.c"
    break;

  case 36: /* noun: CAR  */
#line 187 "emoji.y"
                 { (yyval.str) = "🚗"; }
#line 1581 "y.tab.c"
    break;

  case 37: /* noun: BOOK  */
#line 188 "emoji.y"
                 { (yyval.str) = "📖"; }
#line 1587 "y.tab.c"
    break;

  case 38: /* noun: COMPUTER  */
#line 189 "emoji.y"
                 { (yyval.str) = "💻"; }
#line 1593 "y.tab.c"
    break;

  case 39: /* noun: PHONE  */
#line 190 "emoji.y"
                 { (yyval.str) = "📱"; }
#line 1599 "y.tab.c"
    break;

  case 40: /* noun: FOOD  */
#line 191 "emoji.y"
                 { (yyval.str) = "🍲"; }
#line 1605 "y.tab.c"
    break;

  case 41: /* noun: WATER  */
#line 192 "emoji.y"
                 { (yyval.str) = "💧"; }
#line 1611 "y.tab.c"
    break;

  case 42: /* noun: SUN  */
#line 193 "emoji.y"
                 { (yyval.str) = "☀️"; }
#line 1617 "y.tab.c"
    break;

  case 43: /* noun: MOON  */
#line 194 "emoji.y"
                 { (yyval.str) = "🌜"; }
#line 1623 "y.tab.c"
    break;

  case 44: /* noun: STAR  */
#line 195 "emoji.y"
                 { (yyval.str) = "⭐"; }
#line 1629 "y.tab.c"
    break;

  case 45: /* noun: FLOWER  */
#line 196 "emoji.y"
                 { (yyval.str) = "🌸"; }
#line 1635 "y.tab.c"
    break;

  case 46: /* noun: BIRTHDAY  */
#line 197 "emoji.y"
                 { (yyval.str) = "🎂"; }
#line 1641 "y.tab.c"
    break;

  case 47: /* noun: LUCK  */
#line 198 "emoji.y"
                 { (yyval.str) = "🍀";}
#line 1647 "y.tab.c"
    break;

  case 48: /* noun: CHRISTMAS  */
#line 199 "emoji.y"
                 { (yyval.str) = "🎅🏻";}
#line 1653 "y.tab.c"
    break;

  case 49: /* adjective: LITTLE  */
#line 203 "emoji.y"
                 { (yyval.str) = "🤏"; }
#line 1659 "y.tab.c"
    break;

  case 50: /* adjective: BIG  */
#line 204 "emoji.y"
                 { (yyval.str) = "💪"; }
#line 1665 "y.tab.c"
    break;

  case 51: /* adjective: FEW  */
#line 205 "emoji.y"
                 { (yyval.str) = "✌️"; }
#line 1671 "y.tab.c"
    break;

  case 52: /* adjective: BEAUTIFUL  */
#line 206 "emoji.y"
                 { (yyval.str) = "🌸"; }
#line 1677 "y.tab.c"
    break;

  case 53: /* adjective: UGLY  */
#line 207 "emoji.y"
                 { (yyval.str) = "👹"; }
#line 1683 "y.tab.c"
    break;

  case 54: /* adjective: NICE  */
#line 208 "emoji.y"
                 { (yyval.str) = "😊"; }
#line 1689 "y.tab.c"
    break;

  case 55: /* adjective: HAPPY  */
#line 209 "emoji.y"
                 { (yyval.str) = "😃"; }
#line 1695 "y.tab.c"
    break;

  case 56: /* adjective: SAD  */
#line 210 "emoji.y"
                 { (yyval.str) = "😢"; }
#line 1701 "y.tab.c"
    break;

  case 57: /* adjective: ANGRY  */
#line 211 "emoji.y"
                 { (yyval.str) = "😠"; }
#line 1707 "y.tab.c"
    break;

  case 58: /* adjective: FAST  */
#line 212 "emoji.y"
                 { (yyval.str) = "🏃‍♂️"; }
#line 1713 "y.tab.c"
    break;

  case 59: /* adjective: SLOW  */
#line 213 "emoji.y"
                 { (yyval.str) = "🐌"; }
#line 1719 "y.tab.c"
    break;

  case 60: /* adjective: STRONG  */
#line 214 "emoji.y"
                 { (yyval.str) = "💪"; }
#line 1725 "y.tab.c"
    break;

  case 61: /* adjective: WEAK  */
#line 215 "emoji.y"
                 { (yyval.str) = "🦠"; }
#line 1731 "y.tab.c"
    break;

  case 62: /* adjective: SMART  */
#line 216 "emoji.y"
                 { (yyval.str) = "🧠"; }
#line 1737 "y.tab.c"
    break;

  case 63: /* adjective: DUMB  */
#line 217 "emoji.y"
                 { (yyval.str) = "🤪"; }
#line 1743 "y.tab.c"
    break;

  case 64: /* adjective: OLD  */
#line 218 "emoji.y"
                 { (yyval.str) = "👴"; }
#line 1749 "y.tab.c"
    break;

  case 65: /* adjective: YOUNG  */
#line 219 "emoji.y"
                 { (yyval.str) = "👶"; }
#line 1755 "y.tab.c"
    break;

  case 66: /* adjective: HOT  */
#line 220 "emoji.y"
                 { (yyval.str) = "🔥"; }
#line 1761 "y.tab.c"
    break;

  case 67: /* adjective: COLD  */
#line 221 "emoji.y"
                 { (yyval.str) = "❄️"; }
#line 1767 "y.tab.c"
    break;

  case 68: /* adjective: GOOD  */
#line 222 "emoji.y"
                 { (yyval.str) = "👍"; }
#line 1773 "y.tab.c"
    break;

  case 69: /* verb: WALK  */
#line 226 "emoji.y"
              { (yyval.str) = "🚶"; }
#line 1779 "y.tab.c"
    break;

  case 70: /* verb: TALK  */
#line 227 "emoji.y"
                { (yyval.str) = "🗣️"; }
#line 1785 "y.tab.c"
    break;

  case 71: /* verb: DRINK  */
#line 228 "emoji.y"
                { (yyval.str) = "🥤"; }
#line 1791 "y.tab.c"
    break;

  case 72: /* verb: EAT  */
#line 229 "emoji.y"
                { (yyval.str) = "🍽️"; }
#line 1797 "y.tab.c"
    break;

  case 73: /* verb: SLEEP  */
#line 230 "emoji.y"
                { (yyval.str) = "😴"; }
#line 1803 "y.tab.c"
    break;

  case 74: /* verb: RUN  */
#line 231 "emoji.y"
                { (yyval.str) = "🏃"; }
#line 1809 "y.tab.c"
    break;

  case 75: /* verb: READ  */
#line 232 "emoji.y"
                { (yyval.str) = "📖"; }
#line 1815 "y.tab.c"
    break;

  case 76: /* verb: WRITE  */
#line 233 "emoji.y"
                { (yyval.str) = "✍️"; }
#line 1821 "y.tab.c"
    break;

  case 77: /* verb: PLAY  */
#line 234 "emoji.y"
                { (yyval.str) = "🎮"; }
#line 1827 "y.tab.c"
    break;

  case 78: /* verb: SING  */
#line 235 "emoji.y"
                { (yyval.str) = "🎤"; }
#line 1833 "y.tab.c"
    break;

  case 79: /* adverb: DAILY  */
#line 239 "emoji.y"
               { (yyval.str) = "📅"; }
#line 1839 "y.tab.c"
    break;

  case 80: /* adverb: QUICKLY  */
#line 240 "emoji.y"
                { (yyval.str) = "🏃‍♂️"; }
#line 1845 "y.tab.c"
    break;

  case 81: /* adverb: SLOWLY  */
#line 241 "emoji.y"
                { (yyval.str) = "🐢"; }
#line 1851 "y.tab.c"
    break;

  case 82: /* adverb: HAPPILY  */
#line 242 "emoji.y"
                { (yyval.str) = "😊"; }
#line 1857 "y.tab.c"
    break;

  case 83: /* adverb: SADLY  */
#line 243 "emoji.y"
                { (yyval.str) = "😢"; }
#line 1863 "y.tab.c"
    break;

  case 84: /* adverb: LOUDLY  */
#line 244 "emoji.y"
                { (yyval.str) = "🔊"; }
#line 1869 "y.tab.c"
    break;

  case 85: /* adverb: QUIETLY  */
#line 245 "emoji.y"
                { (yyval.str) = "🤫"; }
#line 1875 "y.tab.c"
    break;

  case 86: /* adverb: ALWAYS  */
#line 246 "emoji.y"
                { (yyval.str) = "♾️"; }
#line 1881 "y.tab.c"
    break;

  case 87: /* adverb: NEVER  */
#line 247 "emoji.y"
                { (yyval.str) = "🚫"; }
#line 1887 "y.tab.c"
    break;


#line 1891 "y.tab.c"

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

#line 250 "emoji.y"


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


char *replace_unknown_word_with_emojis(char *word) {


    char *emojis = malloc(4 * 3); 
    emojis[0] = '\0'; 


    for (int i = 0; i < sizeof(lexical_fields) / sizeof(lexical_fields[0]); i++) {

        for (int j = 0; j <lexical_fields[i].num_keywords; j++) {
           //printf("----> %s %d\n",lexical_fields[i].keywords[j], strcmp(word, lexical_fields[i].keywords[j]));
           
           if (strcmp(word, lexical_fields[i].keywords[j]) == 0) {
                // If a match is found, append the first three emojis associated with the lexical field to emojis
                strcat(emojis, "(");
                strcat(emojis, lexical_fields[i].emojis[0]);
                strcat(emojis, " "); // Add a space after each emoji
                strcat(emojis, lexical_fields[i].emojis[1]);
                strcat(emojis, " "); // Add a space after each emoji
                strcat(emojis, lexical_fields[i].emojis[2]);
                strcat(emojis, ") ");


                return emojis;
            }
        }
    }
    // If no match is found, return the initial word
    return word;
}
