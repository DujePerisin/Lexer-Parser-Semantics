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
#line 3 "kalk.y"

#include "kalk.h"

#line 75 "kalk.tab.c"

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

#include "kalk.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_VARIABLE = 4,                   /* VARIABLE  */
  YYSYMBOL_MATFUN = 5,                     /* MATFUN  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_END = 9,                        /* END  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_NL = 11,                        /* NL  */
  YYSYMBOL_STMT_LIST = 12,                 /* STMT_LIST  */
  YYSYMBOL_SWITCH = 13,                    /* SWITCH  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_20_ = 20,                       /* '?'  */
  YYSYMBOL_21_ = 21,                       /* ':'  */
  YYSYMBOL_GE = 22,                        /* GE  */
  YYSYMBOL_LE = 23,                        /* LE  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NE = 25,                        /* NE  */
  YYSYMBOL_26_ = 26,                       /* '>'  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '^'  */
  YYSYMBOL_UMINUS = 33,                    /* UMINUS  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '.'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_stmt = 42,                      /* stmt  */
  YYSYMBOL_null_stmt = 43,                 /* null_stmt  */
  YYSYMBOL_stmt_list = 44,                 /* stmt_list  */
  YYSYMBOL_switch_stmt = 45,               /* switch_stmt  */
  YYSYMBOL_case_list = 46,                 /* case_list  */
  YYSYMBOL_for_stmt = 47,                  /* for_stmt  */
  YYSYMBOL_expr = 48                       /* expr  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   469

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


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
      36,    37,    30,    28,     2,    29,    35,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    21,    34,
      27,    19,    26,    20,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      15,    16,    17,    18,    22,    23,    24,    25,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    33,    33,    34,    35,    39,    40,    41,    42,    43,
      44,    45,    46,    48,    49,    50,    51,    53,    54,    56,
      57,    60,    64,    66,    68,    70,    74,    78,    79,    86,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "VARIABLE",
  "MATFUN", "WHILE", "IF", "ELSE", "END", "PRINT", "NL", "STMT_LIST",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "FOR", "'='", "'?'",
  "':'", "GE", "LE", "EQ", "NE", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'^'", "UMINUS", "';'", "'.'", "'('", "')'", "'{'", "'}'", "$accept",
  "program", "stmt", "null_stmt", "stmt_list", "switch_stmt", "case_list",
  "for_stmt", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,    43,   -27,   -27,    -5,   -21,   -16,   -14,    22,   -27,
     -13,     8,    10,     9,    22,   -27,   -27,    22,   -27,   -27,
     -27,   -27,   265,    22,    22,    22,    22,   287,    22,   -27,
     -27,    22,   -27,   300,   -27,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,   -27,   437,   316,
     332,   348,   -27,   -27,   364,   396,   -27,   424,   -26,   -26,
     -26,   -26,   -26,   -26,   -19,   -19,    20,    20,   -27,   -27,
     239,   239,    17,    22,    22,   -27,   137,   103,    -6,   409,
     437,   -27,   -27,   239,   -27,    54,    41,    26,    22,   171,
      42,   239,    61,    47,   -27,   380,   -27,   239,   239,    48,
     239,   239,   239,   239,   239,   205,   239,   -27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    27,    28,     0,     0,     0,     0,    17,
       0,     0,     0,     0,     0,    18,     3,     0,     4,     5,
      13,    14,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,    32,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,    29,     0,
       0,     0,     8,     9,     0,     0,    44,     0,    40,    41,
      43,    42,    38,    37,    33,    34,    35,    36,    39,    30,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      31,    10,    20,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,    12,     0,    25,     0,
       0,     0,    24,     0,    23,     0,    22,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -27,   -27,    -1,   -27,   180,   -27,   -27,   -27,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    75,    19,    76,    20,    87,    21,    22
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,    27,    42,    43,    44,    45,    46,    32,    85,    86,
      33,    44,    45,    46,    23,    24,    48,    49,    50,    51,
      25,    54,    26,    28,    55,     3,     4,     5,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      92,    93,    29,     2,    30,    31,     3,     4,     5,     6,
       7,    14,    46,     8,     9,    78,    10,    90,    17,    11,
      12,    13,    91,    97,    99,    94,    79,    80,   100,   103,
       0,     0,    14,     0,     0,    82,    82,    15,    16,    17,
       0,    95,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,    82,     0,    82,    82,    82,     3,     4,     5,     6,
       7,    83,    84,     8,     9,     0,    10,     0,     0,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,    15,     0,    17,
       3,     4,     5,     6,     7,     0,    81,     8,     9,     0,
      10,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,     0,    17,     3,     4,     5,     6,     7,     0,
      96,     8,     9,     0,    10,     0,     0,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,    15,     0,    17,     3,     4,
       5,     6,     7,     0,   107,     8,     9,     0,    10,     0,
       0,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    15,
       0,    17,     3,     4,     5,     6,     7,     0,     0,     8,
       9,    77,    10,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,    14,     0,
       0,    98,     0,    15,     0,    17,    34,   102,     0,     0,
     104,   105,     0,   106,     0,    35,     0,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    52,    47,
       0,     0,     0,     0,     0,     0,     0,    35,     0,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      35,    53,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,     0,     0,    35,    56,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,     0,    35,    69,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,     0,    35,    70,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,     0,     0,    35,    71,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,     0,     0,
      35,    72,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,     0,     0,    35,   101,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    35,
      73,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,    88,    35,    74,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    35,     0,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46
};

static const yytype_int8 yycheck[] =
{
       1,     8,    28,    29,    30,    31,    32,    14,    14,    15,
      17,    30,    31,    32,    19,    36,    23,    24,    25,    26,
      36,    28,    36,    36,    31,     3,     4,     5,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      14,    15,    34,     0,    34,    36,     3,     4,     5,     6,
       7,    29,    32,    10,    11,    38,    13,     3,    36,    16,
      17,    18,    21,    21,     3,    39,    73,    74,    21,    21,
      -1,    -1,    29,    -1,    -1,    76,    77,    34,    35,    36,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,   104,   105,   106,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    -1,    -1,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    -1,    36,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    34,    -1,    36,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      -1,    36,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    71,    13,    -1,    -1,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    91,    -1,    34,    -1,    36,    11,    97,    -1,    -1,
     100,   101,    -1,   103,    -1,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    11,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      20,    34,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    20,    37,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    20,    37,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    20,    37,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    20,    37,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      20,    37,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    20,    37,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    20,
      34,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,     0,     3,     4,     5,     6,     7,    10,    11,
      13,    16,    17,    18,    29,    34,    35,    36,    42,    43,
      45,    47,    48,    19,    36,    36,    36,    48,    36,    34,
      34,    36,    48,    48,    11,    20,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    34,    48,    48,
      48,    48,    11,    34,    48,    48,    37,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    37,
      37,    37,    37,    34,    21,    42,    44,    44,    38,    48,
      48,     9,    42,     8,     9,    14,    15,    46,    34,    44,
       3,    21,    14,    15,    39,    48,     9,    21,    44,     3,
      21,    37,    44,    21,    44,    44,    44,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    41,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    43,    43,    44,
      44,    45,    46,    46,    46,    46,    47,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     2,     3,     3,
       6,     6,     8,     1,     1,     2,     2,     1,     1,     1,
       2,     7,     5,     4,     4,     3,    10,     1,     1,     3,
       4,     5,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
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
  case 3: /* program: program '.'  */
#line 34 "kalk.y"
                       { exit(0); }
#line 1237 "kalk.tab.c"
    break;

  case 4: /* program: program stmt  */
#line 35 "kalk.y"
                       { Execute((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1243 "kalk.tab.c"
    break;

  case 5: /* stmt: null_stmt  */
#line 39 "kalk.y"
                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1249 "kalk.tab.c"
    break;

  case 6: /* stmt: expr NL  */
#line 40 "kalk.y"
                                        { (yyval.nPtr) = Opr1(PRINT, (yyvsp[-1].nPtr)); }
#line 1255 "kalk.tab.c"
    break;

  case 7: /* stmt: expr ';'  */
#line 41 "kalk.y"
                                        { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1261 "kalk.tab.c"
    break;

  case 8: /* stmt: PRINT expr NL  */
#line 42 "kalk.y"
                                        { (yyval.nPtr) = Opr1(PRINT, (yyvsp[-1].nPtr)); }
#line 1267 "kalk.tab.c"
    break;

  case 9: /* stmt: PRINT expr ';'  */
#line 43 "kalk.y"
                                        { (yyval.nPtr) = Opr1(PRINT, (yyvsp[-1].nPtr)); }
#line 1273 "kalk.tab.c"
    break;

  case 10: /* stmt: WHILE '(' expr ')' stmt_list END  */
#line 44 "kalk.y"
                                           { (yyval.nPtr) = Opr2(WHILE, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1279 "kalk.tab.c"
    break;

  case 11: /* stmt: IF '(' expr ')' stmt_list END  */
#line 45 "kalk.y"
                                           { (yyval.nPtr) = Opr2(IF, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1285 "kalk.tab.c"
    break;

  case 12: /* stmt: IF '(' expr ')' stmt_list ELSE stmt_list END  */
#line 47 "kalk.y"
                                        { (yyval.nPtr) = Opr3(IF, (yyvsp[-5].nPtr), (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1291 "kalk.tab.c"
    break;

  case 13: /* stmt: switch_stmt  */
#line 48 "kalk.y"
                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1297 "kalk.tab.c"
    break;

  case 14: /* stmt: for_stmt  */
#line 49 "kalk.y"
                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1303 "kalk.tab.c"
    break;

  case 15: /* stmt: BREAK ';'  */
#line 50 "kalk.y"
                                        { (yyval.nPtr) = Opr0(BREAK); }
#line 1309 "kalk.tab.c"
    break;

  case 16: /* stmt: CONTINUE ';'  */
#line 51 "kalk.y"
                                        { (yyval.nPtr) = Opr0(CONTINUE); }
#line 1315 "kalk.tab.c"
    break;

  case 17: /* null_stmt: NL  */
#line 53 "kalk.y"
                                        { (yyval.nPtr) = NULL; }
#line 1321 "kalk.tab.c"
    break;

  case 18: /* null_stmt: ';'  */
#line 54 "kalk.y"
                                        { (yyval.nPtr) = NULL; }
#line 1327 "kalk.tab.c"
    break;

  case 19: /* stmt_list: stmt  */
#line 56 "kalk.y"
                                { (yyval.nPtr) = AppendStmt(NULL, (yyvsp[0].nPtr)); }
#line 1333 "kalk.tab.c"
    break;

  case 20: /* stmt_list: stmt_list stmt  */
#line 57 "kalk.y"
                                { (yyval.nPtr) = AppendStmt((yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1339 "kalk.tab.c"
    break;

  case 21: /* switch_stmt: SWITCH '(' expr ')' '{' case_list '}'  */
#line 61 "kalk.y"
        { (yyval.nPtr) = Opr2(SWITCH, (yyvsp[-4].nPtr), (yyvsp[-1].nPtr)); }
#line 1345 "kalk.tab.c"
    break;

  case 22: /* case_list: case_list CASE NUMBER ':' stmt_list  */
#line 65 "kalk.y"
        { (yyval.nPtr) = AppendCase((yyvsp[-4].nPtr), (yyvsp[-2].fValue), (yyvsp[0].nPtr)); }
#line 1351 "kalk.tab.c"
    break;

  case 23: /* case_list: case_list DEFAULT ':' stmt_list  */
#line 67 "kalk.y"
        { (yyval.nPtr) = AppendDefaultCase((yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1357 "kalk.tab.c"
    break;

  case 24: /* case_list: CASE NUMBER ':' stmt_list  */
#line 69 "kalk.y"
        { (yyval.nPtr) = CreateCase((yyvsp[-2].fValue), (yyvsp[0].nPtr)); }
#line 1363 "kalk.tab.c"
    break;

  case 25: /* case_list: DEFAULT ':' stmt_list  */
#line 71 "kalk.y"
        { (yyval.nPtr) = CreateDefaultCase((yyvsp[0].nPtr)); }
#line 1369 "kalk.tab.c"
    break;

  case 26: /* for_stmt: FOR '(' expr ';' expr ';' expr ')' stmt_list END  */
#line 75 "kalk.y"
        { (yyval.nPtr) = Opr4(FOR, (yyvsp[-7].nPtr), (yyvsp[-5].nPtr), (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1375 "kalk.tab.c"
    break;

  case 27: /* expr: NUMBER  */
#line 78 "kalk.y"
                                { (yyval.nPtr) = NumConst((yyvsp[0].fValue)); }
#line 1381 "kalk.tab.c"
    break;

  case 28: /* expr: VARIABLE  */
#line 79 "kalk.y"
                                { Symbol *sp = lookupSym((yyvsp[0].str)); 
                                  if(!sp) 
                                       yyerror("Variable not defined");
                                  else if(sp->name != (yyvsp[0].str)) 
                                       free((yyvsp[0].str)); 
                                  (yyval.nPtr) = Var(sp); 
                                }
#line 1393 "kalk.tab.c"
    break;

  case 29: /* expr: VARIABLE '=' expr  */
#line 86 "kalk.y"
                                { Symbol *sp = lookupSym((yyvsp[-2].str));
                                  if(!sp) sp = insertSym((yyvsp[-2].str));
                                  (yyval.nPtr) = Opr2('=', Var(sp), (yyvsp[0].nPtr)); 
                                }
#line 1402 "kalk.tab.c"
    break;

  case 30: /* expr: MATFUN '(' expr ')'  */
#line 90 "kalk.y"
                                {(yyval.nPtr) = MatFun((yyvsp[-3].pmatFun), (yyvsp[-1].nPtr)); }
#line 1408 "kalk.tab.c"
    break;

  case 31: /* expr: expr '?' expr ':' expr  */
#line 91 "kalk.y"
                                   { (yyval.nPtr) = Opr3('?', (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1414 "kalk.tab.c"
    break;

  case 32: /* expr: '-' expr  */
#line 92 "kalk.y"
                                { (yyval.nPtr) = Opr1(UMINUS, (yyvsp[0].nPtr)); }
#line 1420 "kalk.tab.c"
    break;

  case 33: /* expr: expr '+' expr  */
#line 93 "kalk.y"
                                { (yyval.nPtr) = Opr2('+', (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1426 "kalk.tab.c"
    break;

  case 34: /* expr: expr '-' expr  */
#line 94 "kalk.y"
                                { (yyval.nPtr) = Opr2('-', (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1432 "kalk.tab.c"
    break;

  case 35: /* expr: expr '*' expr  */
#line 95 "kalk.y"
                                { (yyval.nPtr) = Opr2('*', (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1438 "kalk.tab.c"
    break;

  case 36: /* expr: expr '/' expr  */
#line 96 "kalk.y"
                                { (yyval.nPtr) = Opr2('/', (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1444 "kalk.tab.c"
    break;

  case 37: /* expr: expr '<' expr  */
#line 97 "kalk.y"
                                { (yyval.nPtr) = Opr2('<', (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1450 "kalk.tab.c"
    break;

  case 38: /* expr: expr '>' expr  */
#line 98 "kalk.y"
                                { (yyval.nPtr) = Opr2('>', (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1456 "kalk.tab.c"
    break;

  case 39: /* expr: expr '^' expr  */
#line 99 "kalk.y"
                                { (yyval.nPtr) = Opr2('^', (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1462 "kalk.tab.c"
    break;

  case 40: /* expr: expr GE expr  */
#line 100 "kalk.y"
                                { (yyval.nPtr) = Opr2(GE,  (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1468 "kalk.tab.c"
    break;

  case 41: /* expr: expr LE expr  */
#line 101 "kalk.y"
                                { (yyval.nPtr) = Opr2(LE,  (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1474 "kalk.tab.c"
    break;

  case 42: /* expr: expr NE expr  */
#line 102 "kalk.y"
                                { (yyval.nPtr) = Opr2(NE,  (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1480 "kalk.tab.c"
    break;

  case 43: /* expr: expr EQ expr  */
#line 103 "kalk.y"
                                { (yyval.nPtr) = Opr2(EQ,  (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1486 "kalk.tab.c"
    break;

  case 44: /* expr: '(' expr ')'  */
#line 104 "kalk.y"
                                { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1492 "kalk.tab.c"
    break;


#line 1496 "kalk.tab.c"

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

#line 106 "kalk.y"


void yyerror(char *s) {
	if(yyin != stdin) fprintf(stdout, "Line: %d: %s\n", lineno, s);
	else              fprintf(stdout, "%s\n", s);			
	longjmp(jumpdata,0);	/*a better exit than yyparse()==0 error*/
}
