/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "translate.y" /* yacc.c:337  */

	#include <stdio.h>
	#include <stdlib.h>
	#include "../symbolTable/symbolTable.h"
	#include "../AST/AST.h"
	#define printTree($$) verbose_mode ? printAST($$) : NULL

	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
	#define YYDEBUG_LEXER_TEXT yytext
	Env *env;
	extern int yylineno;
	int verbose_mode = 0;
	extern int verbose_mode;
	Symbol_table *lookup(char *search,char *type);

#line 88 "y.tab.c" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    KUALA = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    FOR = 263,
    INT = 264,
    FLOAT = 265,
    BOOL = 266,
    LT_OP = 267,
    LE_OP = 268,
    EQ_OP = 269,
    GT_OP = 270,
    GE_OP = 271,
    DIF_OP = 272,
    STRING = 273,
    RETURN = 274,
    AT = 275,
    OR_OP = 276,
    AND_OP = 277,
    NOT = 278,
    INCRMT = 279,
    DECRMT = 280,
    id = 281,
    string = 282,
    char_const = 283,
    float_const = 284,
    int_const = 285
  };
#endif
/* Tokens.  */
#define VOID 258
#define KUALA 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define FOR 263
#define INT 264
#define FLOAT 265
#define BOOL 266
#define LT_OP 267
#define LE_OP 268
#define EQ_OP 269
#define GT_OP 270
#define GE_OP 271
#define DIF_OP 272
#define STRING 273
#define RETURN 274
#define AT 275
#define OR_OP 276
#define AND_OP 277
#define NOT 278
#define INCRMT 279
#define DECRMT 280
#define id 281
#define string 282
#define char_const 283
#define float_const 284
#define int_const 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "translate.y" /* yacc.c:352  */

	struct abstract_syntax_tree *val;
	int type;
	int count;

#line 197 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   380

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

#define YYUNDEFTOK  2
#define YYMAXUTOK   285

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
      37,    38,    33,    31,    42,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      35,    46,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    54,    55,    56,    59,    60,    61,    64,
      65,    68,    71,    72,    75,    76,    77,    78,    81,    82,
      85,    86,    87,    90,    91,    94,   101,   111,   112,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     128,   129,   130,   131,   132,   133,   136,   137,   138,   141,
     142,   145,   146,   147,   148,   151,   152,   155,   156,   159,
     160,   161,   162,   163,   164,   167,   168,   170,   175,   179,
     183,   187,   191,   192,   193,   194,   195,   196,   197,   198,
     201,   202,   205,   206,   209,   210,   213,   214,   218,   219,
     220,   221,   224,   225,   230,   237,   247,   259,   260,   263,
     264,   267,   281,   282,   283,   284,   285,   288,   289,   290,
     291,   294,   295,   296
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "KUALA", "IF", "ELSE", "WHILE",
  "FOR", "INT", "FLOAT", "BOOL", "LT_OP", "LE_OP", "EQ_OP", "GT_OP",
  "GE_OP", "DIF_OP", "STRING", "RETURN", "AT", "OR_OP", "AND_OP", "NOT",
  "INCRMT", "DECRMT", "id", "string", "char_const", "float_const",
  "int_const", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'", "'('", "')'",
  "';'", "'['", "']'", "','", "'{'", "'}'", "'%'", "'='", "$accept",
  "program", "kuala", "funct_list", "funct", "funct_types", "funct_body",
  "param_dclr", "param_list", "simple_block", "call_funct", "block",
  "stmt", "expr_statement", "expr", "expr_list", "logic", "logic_op",
  "rel", "relop", "rel_oper", "oper", "array_entry", "consts_list",
  "array", "array_list", "array_size", "dclr", "list_dclr",
  "list_dclr_types", "attr_recive", "attr", "type_consts", "consts", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    43,    45,    42,    47,    60,    62,    40,    41,    59,
      91,    93,    44,   123,   125,    37,    61
};
# endif

#define YYPACT_NINF -112

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-112)))

#define YYTABLE_NINF -79

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     239,    14,    -3,    28,  -112,  -112,  -112,    59,   249,   125,
     249,    29,  -112,    -3,    79,  -112,    -3,  -112,  -112,  -112,
    -112,    14,    28,   249,  -112,    -3,  -112,  -112,    75,    33,
      32,    60,  -112,  -112,  -112,  -112,   114,  -112,   216,   132,
      64,    87,    74,     1,   101,   109,   323,    -1,  -112,   158,
     112,  -112,   117,   180,    53,   135,   136,   140,   154,  -112,
    -112,  -112,   142,   242,   159,  -112,   337,   126,    66,  -112,
    -112,  -112,  -112,   337,   337,   337,  -112,  -112,   279,   155,
    -112,  -112,  -112,   209,   337,   254,  -112,  -112,  -112,  -112,
    -112,  -112,   337,   254,  -112,   168,  -112,   -35,  -112,  -112,
     242,   242,    16,  -112,   363,   230,   283,   242,   162,  -112,
     337,    -5,    -5,   288,   337,   337,   337,   337,  -112,   337,
    -112,   163,   166,   127,   171,   264,   298,   113,   230,   172,
    -112,  -112,   303,  -112,   151,  -112,   225,   337,    55,   127,
      41,   288,  -112,  -112,   202,   242,  -112,  -112,  -112,  -112,
    -112,  -112,   337,   134,   173,   176,  -112,    -5,    -5,   174,
     174,   230,   242,  -112,  -112,   177,   181,   187,   190,  -112,
     192,  -112,   203,   230,   190,   191,  -112,  -112,  -112,   127,
    -112,   173,  -112,   250,  -112,  -112,  -112,   -20,  -112,  -112,
    -112,  -112,  -112,    67,   218,  -112,   202,  -112,  -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,     0,   107,   108,   109,   110,     0,     5,     0,
      10,     0,    12,     0,     0,     6,     0,     1,    13,   107,
       4,     0,     0,     3,     9,     0,     7,    22,     0,    21,
       0,     0,     8,     2,    11,    15,     0,    14,     0,     0,
      18,    45,     0,     0,     0,     0,     0,     0,    23,     0,
       0,    37,     0,     0,     0,     0,    92,     0,     0,    20,
      16,    17,     0,     0,     0,    32,     0,     0,    76,    77,
     112,   113,   111,     0,     0,     0,    44,    79,     0,    78,
      75,   103,   104,     0,     0,     0,    28,    42,    24,    36,
     105,   106,     0,     0,    40,     0,    41,    98,    96,    19,
       0,     0,     0,    54,    58,    65,    66,     0,     0,    45,
       0,    73,    72,     0,     0,     0,     0,     0,    43,     0,
      26,    50,     0,    46,    47,    65,     0,     0,    99,    87,
     100,   101,     0,   102,    98,    95,     0,     0,    93,    52,
       0,    65,    55,    56,     0,     0,    61,    59,    60,    63,
      62,    64,     0,     0,     0,     0,    74,    67,    68,    69,
      70,    71,     0,    25,    81,     0,     0,    83,     0,    80,
       0,    91,     0,    97,     0,    88,    53,    29,    30,    51,
      57,     0,    33,     0,    49,    85,    84,     0,    86,    90,
      89,    94,    31,     0,     0,    82,     0,    34,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,   268,    12,  -112,  -112,   157,  -112,   240,    18,
     -34,   -42,   -46,   220,  -112,   128,   -51,  -112,   -62,  -112,
     137,   -32,   -36,   105,  -112,  -101,   196,  -112,  -112,   193,
     206,   118,    58,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    15,    29,    30,    49,
      77,    51,    52,    53,   121,   122,   123,   145,   103,   152,
     104,   105,    79,   165,   129,   130,   175,    55,    56,    98,
     131,    57,    58,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    65,    50,    86,   108,   136,    64,    89,    70,    71,
      72,   137,   102,    54,    78,    50,   167,    54,    13,    50,
      20,   124,    24,    81,    82,   172,   166,   106,   116,   117,
     106,    54,    16,    50,    14,    33,    83,   142,   143,    84,
     119,   111,   112,   113,    36,    85,    37,   106,   155,   139,
     140,   125,   126,   128,   144,    25,   153,    61,    12,    17,
     132,   128,   142,   143,   106,   106,    12,   188,    12,   141,
      39,   106,    31,   191,   106,    38,   167,    90,    91,   176,
      27,    12,   157,   158,   159,   160,    40,   161,    19,     4,
       5,    81,    82,    92,   179,   136,    31,     6,   178,    93,
     124,   174,   177,    83,    62,   173,    84,    84,    54,   106,
      50,    63,   182,    85,    35,    41,   106,    28,    36,    42,
      43,    44,    45,    19,     4,     5,   106,   109,    21,     2,
     125,   -39,     6,    46,    22,    19,     4,     5,    66,   192,
      47,    70,    71,    72,     6,    46,    67,    54,   142,   143,
     198,    87,    47,   127,   197,   142,   143,    36,    48,    41,
      54,    88,    50,    42,    43,    44,    45,    19,     4,     5,
      26,    60,   181,    32,    94,    36,     6,    46,    95,    96,
      97,    41,    34,    99,    47,    42,    43,    44,    45,    19,
       4,     5,   -54,   -54,   134,    92,   107,   137,     6,    46,
     154,    36,   -27,    41,   163,   162,    47,    42,    43,    44,
      45,    19,     4,     5,   168,   183,    36,    27,   185,   119,
       6,    46,   186,    36,   -38,    19,     4,     5,    47,   187,
     127,   136,   100,   189,     6,    68,    69,    70,    71,    72,
      73,    74,     1,     2,   190,    36,   101,   120,     3,     4,
       5,   170,    18,    70,    71,    72,   196,     6,    19,     4,
       5,   114,   115,   116,   117,   100,   171,     6,    68,    69,
      70,    71,    72,    73,    74,   119,   193,    23,    59,   101,
      68,    69,    70,    71,    72,    73,    74,   110,   135,   180,
     184,    75,   195,   138,   127,   114,   115,   116,   117,   133,
       0,   194,   -48,     0,     0,     0,   -48,     0,     0,   119,
     114,   115,   116,   117,   -78,   -78,   -78,   -78,   118,   114,
     115,   116,   117,    92,   119,     0,   156,     0,   -78,   114,
     115,   116,   117,   119,   114,   115,   116,   117,     0,   164,
       0,     0,     0,   119,   169,     0,     0,     0,   119,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,     0,
      75,     0,    76,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,    75,   146,   147,   148,   149,   150,
     151
};

static const yytype_int16 yycheck[] =
{
      36,    43,    36,    49,    66,    40,     5,    53,    28,    29,
      30,    46,    63,    49,    46,    49,   127,    53,     4,    53,
       8,    83,    10,    24,    25,   136,   127,    63,    33,    34,
      66,    67,     4,    67,    37,    23,    37,    21,    22,    40,
      45,    73,    74,    75,    43,    46,    28,    83,   110,   100,
     101,    83,    84,    85,    38,    26,   107,    39,     0,     0,
      92,    93,    21,    22,   100,   101,     8,   168,    10,   101,
      38,   107,    14,   174,   110,    42,   187,    24,    25,    38,
       1,    23,   114,   115,   116,   117,    26,   119,     9,    10,
      11,    24,    25,    40,   145,    40,    38,    18,   144,    46,
     162,    46,   144,    37,    40,   137,    40,    40,   144,   145,
     144,    37,   154,    46,    39,     1,   152,    38,    43,     5,
       6,     7,     8,     9,    10,    11,   162,     1,     3,     4,
     162,    44,    18,    19,     9,     9,    10,    11,    37,   181,
      26,    28,    29,    30,    18,    19,    37,   183,    21,    22,
     196,    39,    26,    40,   196,    21,    22,    43,    44,     1,
     196,    44,   196,     5,     6,     7,     8,     9,    10,    11,
      13,    39,    38,    16,    39,    43,    18,    19,    42,    39,
      26,     1,    25,    41,    26,     5,     6,     7,     8,     9,
      10,    11,    21,    22,    26,    40,    37,    46,    18,    19,
      38,    43,    44,     1,    38,    42,    26,     5,     6,     7,
       8,     9,    10,    11,    42,    39,    43,     1,    41,    45,
      18,    19,    41,    43,    44,     9,    10,    11,    26,    42,
      40,    40,    23,    41,    18,    26,    27,    28,    29,    30,
      31,    32,     3,     4,    41,    43,    37,    38,     9,    10,
      11,    26,     3,    28,    29,    30,    38,    18,     9,    10,
      11,    31,    32,    33,    34,    23,    41,    18,    26,    27,
      28,    29,    30,    31,    32,    45,    26,     9,    38,    37,
      26,    27,    28,    29,    30,    31,    32,    67,    95,   152,
     162,    37,   187,    97,    40,    31,    32,    33,    34,    93,
      -1,   183,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,
      31,    32,    33,    34,    31,    32,    33,    34,    39,    31,
      32,    33,    34,    40,    45,    -1,    38,    -1,    45,    31,
      32,    33,    34,    45,    31,    32,    33,    34,    -1,    41,
      -1,    -1,    -1,    45,    41,    -1,    -1,    -1,    45,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    -1,    39,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    12,    13,    14,    15,    16,
      17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     9,    10,    11,    18,    48,    49,    50,
      51,    52,    79,     4,    37,    53,     4,     0,     3,     9,
      50,     3,     9,    49,    50,    26,    53,     1,    38,    54,
      55,    79,    53,    50,    53,    39,    43,    56,    42,    38,
      26,     1,     5,     6,     7,     8,    19,    26,    44,    56,
      57,    58,    59,    60,    69,    74,    75,    78,    79,    55,
      39,    56,    40,    37,     5,    58,    37,    37,    26,    27,
      28,    29,    30,    31,    32,    37,    39,    57,    68,    69,
      80,    24,    25,    37,    40,    46,    59,    39,    44,    59,
      24,    25,    40,    46,    39,    42,    39,    26,    76,    41,
      23,    37,    63,    65,    67,    68,    69,    37,    65,     1,
      60,    68,    68,    68,    31,    32,    33,    34,    39,    45,
      38,    61,    62,    63,    65,    68,    68,    40,    68,    71,
      72,    77,    68,    77,    26,    76,    40,    46,    73,    63,
      63,    68,    21,    22,    38,    64,    12,    13,    14,    15,
      16,    17,    66,    63,    38,    65,    38,    68,    68,    68,
      68,    68,    42,    38,    41,    70,    72,    80,    42,    41,
      26,    41,    80,    68,    46,    73,    38,    58,    59,    63,
      67,    38,    58,    39,    62,    41,    41,    42,    72,    41,
      41,    72,    58,    26,    78,    70,    38,    58,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    49,    49,    49,    50,
      50,    51,    52,    52,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    62,
      62,    63,    63,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     2,     3,     3,     2,
       1,     3,     1,     1,     3,     3,     4,     4,     2,     4,
       3,     1,     1,     2,     3,     4,     3,     1,     2,     5,
       5,     6,     2,     5,     8,     8,     2,     1,     1,     1,
       2,     2,     2,     3,     2,     1,     1,     1,     1,     3,
       1,     3,     2,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     1,     1,     1,     1,
       4,     4,     3,     1,     3,     3,     3,     1,     2,     3,
       3,     2,     1,     3,     5,     3,     2,     3,     1,     1,
       1,     3,     3,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 53 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeList3((yyvsp[-1].val), (yyvsp[-2].val), (yyvsp[0].val)); printTree((yyval.val));}
#line 1466 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 54 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeList2((yyvsp[0].val), (yyvsp[-1].val)); printTree((yyval.val));}
#line 1472 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 55 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeList2((yyvsp[-1].val), (yyvsp[0].val)); printTree((yyval.val));}
#line 1478 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 56 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = (yyvsp[0].val); printTree((yyval.val));}
#line 1484 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 59 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=makeAST(KUALA_AST,0,(yyvsp[0].val));}
#line 1490 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 60 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=makeAST(KUALA_AST,0,(yyvsp[0].val));}
#line 1496 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 61 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=makeAST(KUALA_AST,(yyvsp[-2].val),(yyvsp[0].val));}
#line 1502 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 64 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeList2((yyvsp[0].val), (yyvsp[-1].val));}
#line 1508 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 68 "translate.y" /* yacc.c:1652  */
    {(yyvsp[-1].val)->sym->type = (yyvsp[-2].type); (yyval.val) = (yyvsp[-1].val); (yyval.val)=makeAST(FUNC,(yyvsp[-1].val),(yyvsp[0].val)); ht_set(env->hash,(yyvsp[-1].val)->sym->name,createSymbolFunct((yyvsp[-1].val)->sym->name,yylineno,(yyvsp[-2].type),1));}
#line 1514 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 72 "translate.y" /* yacc.c:1652  */
    {(yyval.type) = VOID;}
#line 1520 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 75 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=makeAST(DCLR_FUNC,0,(yyvsp[0].val));}
#line 1526 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 76 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=makeAST(DCLR_FUNC,0,0);}
#line 1532 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 77 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=makeAST(DCLR_FUNC,(yyvsp[-2].val),0);}
#line 1538 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 78 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=makeAST(DCLR_FUNC,(yyvsp[-2].val),(yyvsp[0].val));}
#line 1544 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 81 "translate.y" /* yacc.c:1652  */
    { (yyvsp[0].val)->sym->type = (yyvsp[-1].type); (yyval.val) = (yyvsp[0].val);}
#line 1550 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 82 "translate.y" /* yacc.c:1652  */
    {(yyvsp[-2].val)->sym->type = (yyvsp[-3].type); (yyval.val) = (yyvsp[-2].val);}
#line 1556 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 85 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeList2((yyvsp[0].val), (yyvsp[-2].val));}
#line 1562 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 87 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=NULL;}
#line 1568 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 90 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=NULL;}
#line 1574 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 91 "translate.y" /* yacc.c:1652  */
    { (yyval.val) = makeAST(BLOCK_STATEMENT, (yyvsp[-1].val), 0);}
#line 1580 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 94 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(CALL_OP, (yyvsp[-3].val), (yyvsp[-1].val)); Symbol_table *table = lookup((yyvsp[-3].val)->sym->name,"função"); 
					if( table ==  NULL){
						(yyval.val)->hold_type=-1;
					}else{
						(yyval.val)->hold_type=table->tipo;
					}
				}
#line 1592 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 101 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(CALL_OP, (yyvsp[-2].val), 0); 
			 		Symbol_table *table = lookup((yyvsp[-2].val)->sym->name,"função"); 
					if( table ==  NULL){
						(yyval.val)->hold_type=-1;
					}else{
						(yyval.val)->hold_type=table->tipo;
					}
				}
#line 1605 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 111 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(BLOCK_STATEMENT, (yyvsp[0].val), 0);}
#line 1611 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 112 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(BLOCK_STATEMENT, (yyvsp[-1].val), (yyvsp[0].val));}
#line 1617 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 115 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(IF_STATEMENT,(yyvsp[-2].val),(yyvsp[0].val));}
#line 1623 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 116 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(IF_STATEMENT,(yyvsp[-2].val),(yyvsp[0].val));}
#line 1629 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 117 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(ELSE_IF_STATEMENT,(yyvsp[-2].val),(yyvsp[0].val));}
#line 1635 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 118 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(ELSE_STATEMENT,(yyvsp[0].val),0);}
#line 1641 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 119 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(WHILE_STATEMENT,(yyvsp[-2].val),(yyvsp[0].val));}
#line 1647 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 120 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(FOR_STATEMENT,makeList3((yyvsp[-5].val),(yyvsp[-4].val),(yyvsp[-2].val)),(yyvsp[0].val));}
#line 1653 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 121 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(FOR_STATEMENT,makeList3((yyvsp[-5].val),(yyvsp[-4].val),(yyvsp[-2].val)),(yyvsp[0].val));}
#line 1659 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 122 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(BLOCK_STATEMENT, (yyvsp[-1].val), (yyvsp[0].val));}
#line 1665 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 125 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=NULL;}
#line 1671 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 131 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(RETURN_STATEMENT, (yyvsp[-1].val), NULL);}
#line 1677 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 132 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(RETURN_STATEMENT, NULL, NULL);}
#line 1683 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 133 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=NULL;}
#line 1689 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 141 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(LIST, (yyvsp[-2].val), (yyvsp[0].val));}
#line 1695 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 142 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1701 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 145 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST((yyvsp[-1].type), (yyvsp[-2].val), (yyvsp[0].val));}
#line 1707 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 146 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(NOT, (yyvsp[0].val), NULL);}
#line 1713 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 147 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=(yyvsp[-1].val);}
#line 1719 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 151 "translate.y" /* yacc.c:1652  */
    {(yyval.type) = OR;}
#line 1725 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 152 "translate.y" /* yacc.c:1652  */
    {(yyval.type) = AND;}
#line 1731 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 155 "translate.y" /* yacc.c:1652  */
    {(yyval.val)= makeAST((yyvsp[-1].type), (yyvsp[-2].val), (yyvsp[0].val));}
#line 1737 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 159 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=LE_OP_AST;}
#line 1743 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 160 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=EQ_OP_AST;}
#line 1749 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 161 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=LT_OP_AST;}
#line 1755 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 162 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=GE_OP_AST;}
#line 1761 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 163 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=GT_OP_AST;}
#line 1767 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 164 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=DIF_OP_AST;}
#line 1773 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 170 "translate.y" /* yacc.c:1652  */
    {
							(yyval.val)= makeAST(PLUS_OP, (yyvsp[-2].val), (yyvsp[0].val));
							if((yyvsp[-2].val)->hold_type!=(yyvsp[0].val)->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							(yyval.val)->hold_type=(yyvsp[-2].val)->hold_type;
						}
#line 1783 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 175 "translate.y" /* yacc.c:1652  */
    {(yyval.val)= makeAST(MINUS_OP, (yyvsp[-2].val), (yyvsp[0].val));
	   						if((yyvsp[-2].val)->hold_type!=(yyvsp[0].val)->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							(yyval.val)->hold_type=(yyvsp[-2].val)->hold_type;
						   }
#line 1792 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 179 "translate.y" /* yacc.c:1652  */
    {(yyval.val)= makeAST(MUL_OP, (yyvsp[-2].val), (yyvsp[0].val));
	   						if((yyvsp[-2].val)->hold_type!=(yyvsp[0].val)->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							(yyval.val)->hold_type=(yyvsp[-2].val)->hold_type;
	   					}
#line 1801 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 183 "translate.y" /* yacc.c:1652  */
    {(yyval.val)= makeAST(DIV_OP, (yyvsp[-2].val), (yyvsp[0].val));
	   						if((yyvsp[-2].val)->hold_type!=(yyvsp[0].val)->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							(yyval.val)->hold_type=(yyvsp[-2].val)->hold_type;
						   }
#line 1810 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 187 "translate.y" /* yacc.c:1652  */
    {(yyval.val)= makeAST(REST_OP, (yyvsp[-2].val), (yyvsp[0].val));
	   						if((yyvsp[-2].val)->hold_type!=(yyvsp[0].val)->hold_type) printf("\e[1;93mSemantica - Valores de Operação incompatives; linha: %d\e[0m \n",yylineno);
							(yyval.val)->hold_type=(yyvsp[-2].val)->hold_type;
	   					}
#line 1819 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 191 "translate.y" /* yacc.c:1652  */
    {(yyval.val)= makeAST(MUL_OP, (yyvsp[0].val), makeNum(-1)); (yyval.val)->hold_type=(yyvsp[0].val)->hold_type;}
#line 1825 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 192 "translate.y" /* yacc.c:1652  */
    {(yyval.val)= (yyvsp[0].val); (yyval.val)->hold_type=(yyvsp[0].val)->hold_type;}
#line 1831 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 193 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=(yyvsp[-1].val); (yyval.val)->hold_type=(yyvsp[-1].val)->hold_type;}
#line 1837 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 194 "translate.y" /* yacc.c:1652  */
    {(yyval.val)->hold_type=(yyvsp[0].val)->hold_type;}
#line 1843 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 195 "translate.y" /* yacc.c:1652  */
    {(yyval.val)->hold_type=(yyvsp[0].val)->sym->type;}
#line 1849 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 196 "translate.y" /* yacc.c:1652  */
    {(yyval.val)->hold_type=STRING;}
#line 1855 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 198 "translate.y" /* yacc.c:1652  */
    {(yyval.val)->hold_type=(yyvsp[0].val)->hold_type;}
#line 1861 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 201 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(SET_ARRAY_OP, (yyvsp[-3].val), (yyvsp[-1].val));}
#line 1867 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 202 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeAST(SET_ARRAY_OP, (yyvsp[-3].val), (yyvsp[-1].val)); }
#line 1873 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 205 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeList2((yyvsp[-2].val), (yyvsp[0].val));}
#line 1879 "y.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 209 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = (yyvsp[-1].val);}
#line 1885 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 210 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = (yyvsp[-1].val);}
#line 1891 "y.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 213 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeList2((yyvsp[-2].val), (yyvsp[0].val));}
#line 1897 "y.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 218 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = makeList2((yyvsp[-1].val), (yyvsp[0].val));}
#line 1903 "y.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 219 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = (yyvsp[-1].val);}
#line 1909 "y.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 220 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = (yyvsp[-1].val);}
#line 1915 "y.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 221 "translate.y" /* yacc.c:1652  */
    {(yyval.val) = NULL;}
#line 1921 "y.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 225 "translate.y" /* yacc.c:1652  */
    {
			   												(yyvsp[-1].val)->sym->type = (yyvsp[-2].type); 
														    (yyval.val) = makeAST(SET_ARRAY_OP, (yyvsp[-1].val), (yyvsp[0].val)); 
															ht_set(env->hash,(yyvsp[-1].val)->sym->name,createSymbolBasic((yyvsp[-1].val)->sym->name,yylineno,(yyvsp[-2].type)));	
														}
#line 1931 "y.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 230 "translate.y" /* yacc.c:1652  */
    {	
			   												(yyvsp[-3].val)->sym->type = (yyvsp[-4].type); 
		   													(yyval.val) = makeAST(EX_EQ, makeAST(SET_ARRAY_OP, (yyvsp[-3].val), (yyvsp[-2].val)), (yyvsp[0].val) );
															ht_set(env->hash,(yyvsp[-3].val)->sym->name,createSymbolBasic((yyvsp[-3].val)->sym->name,yylineno,(yyvsp[-4].type)));
														}
#line 1941 "y.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 237 "translate.y" /* yacc.c:1652  */
    {   (yyval.val) = makeList2((yyvsp[-2].val), (yyvsp[0].val)); 
											
												(yyval.val)->hold_type=(yyvsp[-2].val)->hold_type;
												if ((yyvsp[0].val)->sym != NULL){
													ht_set(env->hash,(yyvsp[0].val)->sym->name,createSymbolBasic((yyvsp[0].val)->sym->name,yylineno,(yyval.val)->hold_type));
												}else{
													ht_set(env->hash,(yyvsp[0].val)->left->sym->name,createSymbolBasic((yyvsp[0].val)->left->sym->name,yylineno,(yyval.val)->hold_type));
												}

											}
#line 1956 "y.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 247 "translate.y" /* yacc.c:1652  */
    { if((yyvsp[0].val)->sym != NULL){ 
													(yyvsp[0].val)->sym->type = (yyvsp[-1].type); 
											    	ht_set(env->hash,(yyvsp[0].val)->sym->name,createSymbolBasic((yyvsp[0].val)->sym->name,yylineno,(yyvsp[-1].type)));
												}else{ 
													(yyvsp[0].val)->left->sym->type = (yyvsp[-1].type);
											    	ht_set(env->hash,(yyvsp[0].val)->left->sym->name,createSymbolBasic((yyvsp[0].val)->left->sym->name,yylineno,(yyvsp[-1].type)));
												}  
											  	(yyval.val) = (yyvsp[0].val);
												(yyval.val)->hold_type = (yyvsp[-1].type);
											}
#line 1971 "y.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 259 "translate.y" /* yacc.c:1652  */
    {(yyval.val)=makeAST(EX_EQ,(yyvsp[-2].val),(yyvsp[0].val));}
#line 1977 "y.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 267 "translate.y" /* yacc.c:1652  */
    { 
												(yyval.val) = makeAST(EX_EQ, (yyvsp[-2].val), (yyvsp[0].val));  		
												Symbol_table *table = lookup((yyvsp[-2].val)->sym->name,"variavel");
												
												if(table == NULL){
													if (-1 != (yyvsp[0].val)->hold_type) printf("\e[1;93mSemantico - Atribuição imcompativel; linha: %d\n \e[0m",yylineno);											  	
												}else{
													if (table->parms_count >= 1){
														printf("\e[1;93mSemantico - Atribuição em FUNÇÃO; linha: %d\n \e[0m",yylineno);	
													}else{
														if (table->tipo != (yyvsp[0].val)->hold_type) printf("\e[1;93mSemantico - Atribuição imcompativel; linha: %d\n \e[0m",yylineno);											  														
													}
												}
											}
#line 1996 "y.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 281 "translate.y" /* yacc.c:1652  */
    { (yyval.val) = makeAST(EX_EQ, (yyvsp[-2].val), (yyvsp[0].val)); }
#line 2002 "y.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 282 "translate.y" /* yacc.c:1652  */
    { (yyval.val) = makeAST(EX_EQ, (yyvsp[-1].val), makeAST(EX_EQ, (yyvsp[-1].val),makeAST(PLUS_OP, (yyvsp[-1].val), makeNum(1)))); }
#line 2008 "y.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 283 "translate.y" /* yacc.c:1652  */
    { (yyval.val) = makeAST(EX_EQ, (yyvsp[-1].val), makeAST(EX_EQ, (yyvsp[-1].val),makeAST(MINUS_OP, (yyvsp[-1].val), makeNum(1)))); }
#line 2014 "y.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 284 "translate.y" /* yacc.c:1652  */
    { (yyval.val) = makeAST(EX_EQ, (yyvsp[-1].val), makeAST(EX_EQ, (yyvsp[-1].val),makeAST(PLUS_OP, (yyvsp[-1].val), makeNum(1))));}
#line 2020 "y.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 285 "translate.y" /* yacc.c:1652  */
    { (yyval.val) = makeAST(EX_EQ, (yyvsp[-1].val), makeAST(EX_EQ, (yyvsp[-1].val),makeAST(MINUS_OP, (yyvsp[-1].val), makeNum(1)))); }
#line 2026 "y.tab.c" /* yacc.c:1652  */
    break;

  case 107:
#line 288 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=INT;}
#line 2032 "y.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 289 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=FLOAT;}
#line 2038 "y.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 290 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=BOOL;}
#line 2044 "y.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 291 "translate.y" /* yacc.c:1652  */
    {(yyval.type)=STRING;}
#line 2050 "y.tab.c" /* yacc.c:1652  */
    break;

  case 111:
#line 294 "translate.y" /* yacc.c:1652  */
    {(yyval.val)->hold_type=INT;}
#line 2056 "y.tab.c" /* yacc.c:1652  */
    break;

  case 112:
#line 295 "translate.y" /* yacc.c:1652  */
    {(yyval.val)->hold_type=STRING;}
#line 2062 "y.tab.c" /* yacc.c:1652  */
    break;

  case 113:
#line 296 "translate.y" /* yacc.c:1652  */
    {(yyval.val)->hold_type=FLOAT;}
#line 2068 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2072 "y.tab.c" /* yacc.c:1652  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 299 "translate.y" /* yacc.c:1918  */

Symbol_table *lookup(char *search,char* type) {
	Symbol_table *table = ht_get(env->hash,search);
	if (table == 0){
	 	printf("\e[1;93mSemantico - A %s '%s' não foi declarada; linha: %d\n \e[0m",type,search,yylineno); 	
		return NULL;
	}else{
		return table;
	}
	
}

int main(int argc,char *argv[])
{
	yydebug = 0;

	
 	
	env = createEnv();

	
	extern int verbose;
	extern int verbose_mode;

	 if( argc == 2 && strcmp(argv[1],"--verbose")==0) {
      verbose=1;
	  verbose_mode=1;
      printf("\n\n\e[1;32mVerbose Mode\e[0m\n\n");

      printf("\e[1;32m-->Analise Lexica & Sintatica & Semantica\e[0m\n");
    }


    yyparse();

	if(verbose){
		printEnv(env);
	}

	

    if(success)
    	printf("\n\n\e[1;32mPrograma sintaticamente correto ʕ·͡ᴥ·ʔ\e[0m \n\n");
	else printf("\n\n\e[1;31mPrograma sintaticamente incorreto ʕ·͡ᴥ·ʔ\e[0m \n\n");
    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	extern int yyline;
	extern int yychar_count;

	printf("\e[1;34mSyntatic Error:\nErro próximo a linha(yylineno): %d\nErro próximo a linha(yyline): %d  coluna: %d\n\e[1;0mMenssage:\n  %s\e[0m \n\n ",yylineno,yyline, yychar_count, msg);
	success = 0;
	return 0;
}
