/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "splc.y" /* yacc.c:339  */

#define YYSTYPE Node *
#include "lex.yy.c"

void yyerror(const char* e);
void display(Node *root, int depth);
Node* new_node;
int fail = 0;

#line 76 "splc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "splc.tab.h".  */
#ifndef YY_YY_SPLC_TAB_H_INCLUDED
# define YY_YY_SPLC_TAB_H_INCLUDED
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
    ERROR = 258,
    INT = 259,
    FLOAT = 260,
    CHAR = 261,
    ID = 262,
    TYPE = 263,
    STRUCT = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    RETURN = 268,
    DOT = 269,
    SEMI = 270,
    COMMA = 271,
    ASSIGN = 272,
    LT = 273,
    LE = 274,
    GT = 275,
    GE = 276,
    NE = 277,
    EQ = 278,
    PLUS = 279,
    MINUS = 280,
    MUL = 281,
    DIV = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    LP = 286,
    RP = 287,
    LB = 288,
    RB = 289,
    LC = 290,
    RC = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SPLC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 164 "splc.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   411

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    38,    39,    42,    43,    44,    45,    46,
      48,    49,    53,    54,    56,    57,    61,    62,    63,    66,
      67,    68,    69,    71,    72,    75,    76,    80,    82,    83,
      86,    87,    88,    89,    90,    91,    92,    93,    98,    99,
     102,   103,   104,   105,   108,   109,   112,   113,   114,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   150,   151
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "INT", "FLOAT", "CHAR", "ID",
  "TYPE", "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "DOT", "SEMI",
  "COMMA", "ASSIGN", "LT", "LE", "GT", "GE", "NE", "EQ", "PLUS", "MINUS",
  "MUL", "DIV", "AND", "OR", "NOT", "LP", "RP", "LB", "RB", "LC", "RC",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     172,    -8,   -63,    43,    20,   -63,   172,    67,   -63,   -63,
     -24,   -63,   -63,   -63,    41,   -63,    11,   -10,    38,    13,
      79,   -63,   -63,     6,    87,    54,   -63,    68,     6,    56,
      54,    22,   -63,     6,    14,    77,   -63,   -63,    81,   196,
      36,    38,   102,   127,    50,   -63,   -63,   -63,    85,    85,
     118,   -63,   203,   -63,   -63,   -63,   -63,   123,   145,   146,
     144,   144,   144,   144,   -63,   142,   196,    80,   249,   -63,
     -63,     6,   181,   -63,   -63,     6,   -63,   115,   144,   144,
     109,   378,   111,   138,   -63,   -63,   -63,   144,   188,   -63,
     303,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   -63,   297,   -63,   -63,   175,   -63,
     216,    15,   243,   270,   182,   -63,   183,   -63,   297,   -63,
     -63,   297,   364,   364,   364,   364,   364,   364,   378,   378,
     111,   111,   350,   324,   165,   -63,   144,   198,   -63,   196,
     196,   -63,   -63,   -63,   -63,   -63,   205,   -63,   196,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,     0,     0,     2,     0,     0,    13,     9,
      15,     1,     3,    18,    16,     6,     0,    10,     0,     0,
       0,     8,     5,     0,     0,     0,     7,     0,     0,     0,
       0,     0,    20,     0,     0,    24,    16,    11,     0,    29,
      46,     0,     0,    44,     0,    14,    38,    22,    26,    25,
       0,    19,     0,    17,    74,    75,    76,    73,     0,     0,
       0,     0,     0,     0,    31,     0,    29,     0,     0,    43,
      42,     0,     0,    40,    21,     0,    23,     0,     0,     0,
       0,    66,    68,     0,    27,    28,    33,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    47,    45,    41,     0,    70,
      79,     0,     0,     0,     0,    32,     0,    64,    50,    72,
      51,    49,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    52,    53,     0,    77,     0,     0,    69,     0,
       0,    34,    65,    71,    78,    67,    35,    37,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   208,   -63,   194,     4,   -63,    21,   191,   168,
     -63,    27,   156,   -62,   180,   -63,   -23,   -63,   -60,    88
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    16,    28,     8,    40,    18,    34,
      35,    64,    65,    66,    29,    30,    42,    43,    67,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,    81,    82,    83,     7,    44,    23,     9,   105,    13,
       7,    19,    21,    36,    27,    50,   137,   110,   112,   113,
      11,     2,     3,    24,    33,    13,    22,   118,    17,    36,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,    17,    26,    51,   138,   106,   -39,
      10,    72,    48,    68,    49,    27,    33,    47,   -39,   -39,
     -39,   -39,     2,     3,   -39,    73,   -39,   -39,    69,    24,
      13,    13,    20,    25,    14,    14,   110,   146,   147,   -39,
      31,    86,    15,    87,   -39,   -39,   149,     2,     3,   -39,
     -39,    38,    45,    52,    88,    89,    48,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     114,    32,    87,   103,    87,    53,   108,    70,    24,    54,
      55,    56,    57,    88,   115,    88,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   116,
      61,    87,   103,    71,   103,    62,    63,   109,    54,    55,
      56,    57,    88,    74,    77,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    87,    61,
     117,   103,    -4,     1,    62,    63,    78,    79,    84,    88,
       2,     3,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   119,   107,   141,   103,   143,
      54,    55,    56,    57,    75,    39,    58,   135,    59,    60,
      46,     2,     3,   145,    12,   142,   148,    37,    41,    87,
      76,    61,    85,     0,   144,     0,    62,    63,     0,     0,
      88,    25,   136,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    87,     0,     0,   103,
       0,     0,   104,    54,    55,    56,    57,    88,     0,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    87,    61,   139,   103,     0,     0,    62,
      63,     0,     0,     0,    88,     0,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      87,     0,   140,   103,     0,     0,   120,    54,    55,    56,
      57,    88,     0,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    87,    61,     0,
     103,     0,     0,    62,    63,     0,     0,     0,    88,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    87,     0,     0,     0,   103,     0,     0,
       0,     0,     0,     0,    88,     0,     0,    87,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    88,     0,
       0,    87,     0,   103,     0,     0,     0,     0,    97,    98,
      99,   100,    88,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,     0,    99,   100,     0,     0,     0,     0,
       0,   103
};

static const yytype_int16 yycheck[] =
{
      60,    61,    62,    63,     0,    28,    16,    15,    68,     3,
       6,    35,     1,     7,     1,     1,     1,    77,    78,    79,
       0,     8,     9,    33,    20,     3,    15,    87,     7,     7,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    23,    18,    32,    32,    71,    36,
       7,     1,    31,    17,    33,     1,    52,    35,     4,     5,
       6,     7,     8,     9,    10,    15,    12,    13,    41,    33,
       3,     3,    31,    35,     7,     7,   136,   139,   140,    25,
       1,     1,    15,     3,    30,    31,   148,     8,     9,    35,
      36,     4,    36,    16,    14,    15,    75,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       1,    32,     3,    33,     3,    34,     1,    15,    33,     4,
       5,     6,     7,    14,    15,    14,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     1,
      25,     3,    33,    16,    33,    30,    31,    32,     4,     5,
       6,     7,    14,    35,    31,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     3,    25,
      32,    33,     0,     1,    30,    31,    31,    31,    36,    14,
       8,     9,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     7,    15,    15,    33,    34,
       4,     5,     6,     7,     1,    25,    10,    32,    12,    13,
      30,     8,     9,    15,     6,    32,    11,    23,    27,     3,
      52,    25,    66,    -1,   136,    -1,    30,    31,    -1,    -1,
      14,    35,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     3,    -1,    -1,    33,
      -1,    -1,     3,     4,     5,     6,     7,    14,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     3,    25,    32,    33,    -1,    -1,    30,
      31,    -1,    -1,    -1,    14,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       3,    -1,    32,    33,    -1,    -1,     3,     4,     5,     6,
       7,    14,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     3,    25,    -1,
      33,    -1,    -1,    30,    31,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     3,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,     3,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    14,    -1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    14,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     8,     9,    38,    39,    40,    42,    43,    15,
       7,     0,    39,     3,     7,    15,    41,    44,    45,    35,
      31,     1,    15,    16,    33,    35,    48,     1,    42,    51,
      52,     1,    32,    42,    46,    47,     7,    41,     4,    51,
      44,    45,    53,    54,    53,    36,    51,    35,    44,    44,
       1,    32,    16,    34,     4,     5,     6,     7,    10,    12,
      13,    25,    30,    31,    48,    49,    50,    55,    17,    48,
      15,    16,     1,    15,    35,     1,    46,    31,    31,    31,
      55,    55,    55,    55,    36,    49,     1,     3,    14,    15,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    33,     3,    55,    53,    15,     1,    32,
      55,    56,    55,    55,     1,    15,     1,    32,    55,     7,
       3,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    32,    16,     1,    32,    32,
      32,    15,    32,    34,    56,    15,    50,    50,    11,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      41,    41,    42,    42,    43,    43,    44,    44,    44,    45,
      45,    45,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      52,    52,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     2,
       1,     3,     1,     1,     5,     2,     1,     4,     1,     4,
       3,     5,     4,     3,     1,     2,     2,     4,     2,     0,
       2,     1,     3,     2,     4,     5,     7,     5,     2,     0,
       3,     4,     3,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     2,     5,     2,     4,
       3,     4,     3,     1,     1,     1,     1,     4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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
#line 36 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Program", "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); }
#line 1388 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 38 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("ExtDefList", "", (yyvsp[-1])->line_no, 1); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1394 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 39 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("", "", 0, 0); (yyval) = new_node;}
#line 1400 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 42 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("ExtDef", "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1406 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 43 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("ExtDef", "", (yyvsp[-1])->line_no, 1); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1412 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 44 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("ExtDef", "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1418 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 45 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing semicolon ';'\n", (yyvsp[-1])->line_no); }
#line 1424 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 46 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing specifier\n",(yyvsp[0])->line_no); }
#line 1430 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 48 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("ExtDecList", "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1436 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 49 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("ExtDecList", "", (yyvsp[-2])->line_no, 1);  insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1442 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 53 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Specifier", "", (yyvsp[0])->line_no, 1);  insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1448 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 54 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Specifier", "", (yyvsp[0])->line_no, 1);  insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1454 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 56 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("StructSpecifier", "", (yyvsp[-4])->line_no, 1); insert_node(new_node, (yyvsp[-4])); insert_node(new_node, (yyvsp[-3])); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1460 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 57 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("StructSpecifier", "", (yyvsp[-1])->line_no, 1); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1466 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 61 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("VarDec", "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1472 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 62 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("VarDec", "", (yyvsp[-3])->line_no, 1); insert_node(new_node, (yyvsp[-3])); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1478 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 63 "splc.y" /* yacc.c:1646  */
    { fail = 1;}
#line 1484 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 66 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("FunDec", "", (yyvsp[-3])->line_no, 1); insert_node(new_node, (yyvsp[-3])); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1490 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 67 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("FunDec", "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1496 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 68 "splc.y" /* yacc.c:1646  */
    { unput('{'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", (yyvsp[-4])->line_no); }
#line 1502 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 69 "splc.y" /* yacc.c:1646  */
    { unput('{'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", (yyvsp[-3])->line_no); }
#line 1508 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 71 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("VarList", "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1514 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 72 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("VarList", "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node;  }
#line 1520 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 75 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("ParamDec", "", (yyvsp[-1])->line_no, 1); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node;  }
#line 1526 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 76 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing semicolon ';'\n", (yyvsp[0])->line_no); }
#line 1532 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 80 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("CompSt", "", (yyvsp[-3])->line_no, 1); insert_node(new_node, (yyvsp[-3])); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node;  }
#line 1538 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 82 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("StmtList", "", (yyvsp[-1])->line_no, 1); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1544 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 83 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("", "", 0, 0); (yyval) = new_node; }
#line 1550 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 86 "splc.y" /* yacc.c:1646  */
    {  new_node = create_node("Stmt", "", (yyvsp[-1])->line_no, 1);  insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node;}
#line 1556 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 87 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Stmt", "", (yyvsp[0])->line_no, 1);  insert_node(new_node, (yyvsp[0])); (yyval) = new_node;}
#line 1562 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 88 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Stmt", "", (yyvsp[-2])->line_no, 1);  insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1568 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 89 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing semicolon ';'\n",(yyvsp[-1])->line_no); }
#line 1574 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 90 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing semicolon ';'\n",(yyvsp[-3])->line_no);  }
#line 1580 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 91 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Stmt", "", (yyvsp[-4])->line_no, 1);  insert_node(new_node, (yyvsp[-4])); insert_node(new_node, (yyvsp[-3])); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1586 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 92 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Stmt", "", (yyvsp[-6])->line_no, 1);  insert_node(new_node, (yyvsp[-6])); insert_node(new_node, (yyvsp[-5])); insert_node(new_node, (yyvsp[-4])); insert_node(new_node, (yyvsp[-3])); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1592 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 93 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Stmt", "", (yyvsp[-4])->line_no, 1);  insert_node(new_node, (yyvsp[-4])); insert_node(new_node, (yyvsp[-3])); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1598 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 98 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("DefList",  "", (yyvsp[-1])->line_no, 1); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1604 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 99 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("", "", 0, 0); (yyval) = new_node; }
#line 1610 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 102 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Def", "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1616 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 103 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing semicolon ';'\n", (yyvsp[-2])->line_no);  }
#line 1622 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 104 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing specifier\n", (yyvsp[-1])->line_no);  }
#line 1628 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 105 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing specifier\n", (yyvsp[-1])->line_no);  }
#line 1634 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 108 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("DecList", "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1640 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 109 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("DecList",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1646 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 112 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Dec", "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1652 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 113 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Dec", "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1658 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 114 "splc.y" /* yacc.c:1646  */
    { fail = 1;}
#line 1664 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 119 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1670 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 120 "splc.y" /* yacc.c:1646  */
    { fail = 1;}
#line 1676 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 121 "splc.y" /* yacc.c:1646  */
    { fail = 1; }
#line 1682 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 122 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1688 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 123 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1694 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 124 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1700 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 125 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1706 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 126 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1712 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 127 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1718 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 128 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1724 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 129 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1730 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 130 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1736 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 131 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1742 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 132 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1748 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 133 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1754 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 134 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1760 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 135 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing closing parenthesis ')'\n", (yyvsp[-3])->line_no); }
#line 1766 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 136 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-1])->line_no, 1); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1772 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 137 "splc.y" /* yacc.c:1646  */
    { unput(';'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", (yyvsp[-4])->line_no); }
#line 1778 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 138 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-1])->line_no, 1);  insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1784 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 139 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-3])->line_no, 1);  insert_node(new_node, (yyvsp[-3])); insert_node(new_node, (yyvsp[-2]));  insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node;  }
#line 1790 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 140 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1796 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 141 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-3])->line_no, 1);  insert_node(new_node, (yyvsp[-3])); insert_node(new_node, (yyvsp[-2]));  insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node;  }
#line 1802 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 142 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1808 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 143 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1814 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 144 "splc.y" /* yacc.c:1646  */
    {  new_node = create_node("Exp",  "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1820 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 145 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1826 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 146 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Exp",  "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1832 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 147 "splc.y" /* yacc.c:1646  */
    { printf("Error type B at Line %d: Missing closing parenthesis ')'\n", (yyvsp[-3])->line_no);  }
#line 1838 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 150 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Args", "", (yyvsp[-2])->line_no, 1); insert_node(new_node, (yyvsp[-2])); insert_node(new_node, (yyvsp[-1])); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1844 "splc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 151 "splc.y" /* yacc.c:1646  */
    { new_node = create_node("Args", "", (yyvsp[0])->line_no, 1); insert_node(new_node, (yyvsp[0])); (yyval) = new_node; }
#line 1850 "splc.tab.c" /* yacc.c:1646  */
    break;


#line 1854 "splc.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 154 "splc.y" /* yacc.c:1906  */


void yyerror(const char* e)
{
    fail = 1;
}

int main(int argc, char **argv) {
    char *file_path;
    FILE* fin = NULL;
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 0;
    } else {
        file_path = argv[1];
        if(!(fin = fopen(file_path, "r"))) {
            perror(argv[1]);
            return 0;
        }
        yyin = fin;
        yyparse();

        if(!fail){
            display(new_node,0);
        }
        return 0;
    }
}

