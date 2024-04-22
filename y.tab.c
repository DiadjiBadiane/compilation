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
#line 1 "grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include "defs.h"
#include "common.h"
#include "miniccutils.h"
#include "passe_1.h"
#include "passe_2.h"



/* Global variables */
extern bool stop_after_syntax;
extern bool stop_after_verif;
extern char * outfile;
int nbno=0;

/* prototypes */
int yylex(void);
extern int yylineno;

void yyerror(node_t * program_root, char * s);
void analyse_tree(node_t root);
node_t make_node(node_nature nature, int nops, ...);
node_t make_node_ident(char* s);
node_t make_node_intval(int64_t value);
node_t make_node_boolval(int64_t value);
node_t make_node_stringval(char* s);
node_t make_node_type(node_type type);

/* A completer */


#line 111 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TOK_VOID = 258,                /* TOK_VOID  */
    TOK_INT = 259,                 /* TOK_INT  */
    TOK_BOOL = 260,                /* TOK_BOOL  */
    TOK_TRUE = 261,                /* TOK_TRUE  */
    TOK_FALSE = 262,               /* TOK_FALSE  */
    TOK_IF = 263,                  /* TOK_IF  */
    TOK_ELSE = 264,                /* TOK_ELSE  */
    TOK_WHILE = 265,               /* TOK_WHILE  */
    TOK_FOR = 266,                 /* TOK_FOR  */
    TOK_DO = 267,                  /* TOK_DO  */
    TOK_PRINT = 268,               /* TOK_PRINT  */
    TOK_SEMICOL = 269,             /* TOK_SEMICOL  */
    TOK_COMA = 270,                /* TOK_COMA  */
    TOK_LPAR = 271,                /* TOK_LPAR  */
    TOK_RPAR = 272,                /* TOK_RPAR  */
    TOK_LACC = 273,                /* TOK_LACC  */
    TOK_RACC = 274,                /* TOK_RACC  */
    TOK_THEN = 275,                /* TOK_THEN  */
    TOK_AFFECT = 276,              /* TOK_AFFECT  */
    TOK_OR = 277,                  /* TOK_OR  */
    TOK_AND = 278,                 /* TOK_AND  */
    TOK_BOR = 279,                 /* TOK_BOR  */
    TOK_BXOR = 280,                /* TOK_BXOR  */
    TOK_BAND = 281,                /* TOK_BAND  */
    TOK_EQ = 282,                  /* TOK_EQ  */
    TOK_NE = 283,                  /* TOK_NE  */
    TOK_GT = 284,                  /* TOK_GT  */
    TOK_LT = 285,                  /* TOK_LT  */
    TOK_GE = 286,                  /* TOK_GE  */
    TOK_LE = 287,                  /* TOK_LE  */
    TOK_SRL = 288,                 /* TOK_SRL  */
    TOK_SRA = 289,                 /* TOK_SRA  */
    TOK_SLL = 290,                 /* TOK_SLL  */
    TOK_PLUS = 291,                /* TOK_PLUS  */
    TOK_MINUS = 292,               /* TOK_MINUS  */
    TOK_MUL = 293,                 /* TOK_MUL  */
    TOK_DIV = 294,                 /* TOK_DIV  */
    TOK_MOD = 295,                 /* TOK_MOD  */
    TOK_UMINUS = 296,              /* TOK_UMINUS  */
    TOK_NOT = 297,                 /* TOK_NOT  */
    TOK_BNOT = 298,                /* TOK_BNOT  */
    TOK_INTVAL = 299,              /* TOK_INTVAL  */
    TOK_IDENT = 300,               /* TOK_IDENT  */
    TOK_STRING = 301               /* TOK_STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TOK_VOID 258
#define TOK_INT 259
#define TOK_BOOL 260
#define TOK_TRUE 261
#define TOK_FALSE 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_FOR 266
#define TOK_DO 267
#define TOK_PRINT 268
#define TOK_SEMICOL 269
#define TOK_COMA 270
#define TOK_LPAR 271
#define TOK_RPAR 272
#define TOK_LACC 273
#define TOK_RACC 274
#define TOK_THEN 275
#define TOK_AFFECT 276
#define TOK_OR 277
#define TOK_AND 278
#define TOK_BOR 279
#define TOK_BXOR 280
#define TOK_BAND 281
#define TOK_EQ 282
#define TOK_NE 283
#define TOK_GT 284
#define TOK_LT 285
#define TOK_GE 286
#define TOK_LE 287
#define TOK_SRL 288
#define TOK_SRA 289
#define TOK_SLL 290
#define TOK_PLUS 291
#define TOK_MINUS 292
#define TOK_MUL 293
#define TOK_DIV 294
#define TOK_MOD 295
#define TOK_UMINUS 296
#define TOK_NOT 297
#define TOK_BNOT 298
#define TOK_INTVAL 299
#define TOK_IDENT 300
#define TOK_STRING 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 43 "grammar.y"

    int32_t intval;
    char * strval;
    node_t ptr;

#line 262 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (node_t * program_root);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_VOID = 3,                   /* TOK_VOID  */
  YYSYMBOL_TOK_INT = 4,                    /* TOK_INT  */
  YYSYMBOL_TOK_BOOL = 5,                   /* TOK_BOOL  */
  YYSYMBOL_TOK_TRUE = 6,                   /* TOK_TRUE  */
  YYSYMBOL_TOK_FALSE = 7,                  /* TOK_FALSE  */
  YYSYMBOL_TOK_IF = 8,                     /* TOK_IF  */
  YYSYMBOL_TOK_ELSE = 9,                   /* TOK_ELSE  */
  YYSYMBOL_TOK_WHILE = 10,                 /* TOK_WHILE  */
  YYSYMBOL_TOK_FOR = 11,                   /* TOK_FOR  */
  YYSYMBOL_TOK_DO = 12,                    /* TOK_DO  */
  YYSYMBOL_TOK_PRINT = 13,                 /* TOK_PRINT  */
  YYSYMBOL_TOK_SEMICOL = 14,               /* TOK_SEMICOL  */
  YYSYMBOL_TOK_COMA = 15,                  /* TOK_COMA  */
  YYSYMBOL_TOK_LPAR = 16,                  /* TOK_LPAR  */
  YYSYMBOL_TOK_RPAR = 17,                  /* TOK_RPAR  */
  YYSYMBOL_TOK_LACC = 18,                  /* TOK_LACC  */
  YYSYMBOL_TOK_RACC = 19,                  /* TOK_RACC  */
  YYSYMBOL_TOK_THEN = 20,                  /* TOK_THEN  */
  YYSYMBOL_TOK_AFFECT = 21,                /* TOK_AFFECT  */
  YYSYMBOL_TOK_OR = 22,                    /* TOK_OR  */
  YYSYMBOL_TOK_AND = 23,                   /* TOK_AND  */
  YYSYMBOL_TOK_BOR = 24,                   /* TOK_BOR  */
  YYSYMBOL_TOK_BXOR = 25,                  /* TOK_BXOR  */
  YYSYMBOL_TOK_BAND = 26,                  /* TOK_BAND  */
  YYSYMBOL_TOK_EQ = 27,                    /* TOK_EQ  */
  YYSYMBOL_TOK_NE = 28,                    /* TOK_NE  */
  YYSYMBOL_TOK_GT = 29,                    /* TOK_GT  */
  YYSYMBOL_TOK_LT = 30,                    /* TOK_LT  */
  YYSYMBOL_TOK_GE = 31,                    /* TOK_GE  */
  YYSYMBOL_TOK_LE = 32,                    /* TOK_LE  */
  YYSYMBOL_TOK_SRL = 33,                   /* TOK_SRL  */
  YYSYMBOL_TOK_SRA = 34,                   /* TOK_SRA  */
  YYSYMBOL_TOK_SLL = 35,                   /* TOK_SLL  */
  YYSYMBOL_TOK_PLUS = 36,                  /* TOK_PLUS  */
  YYSYMBOL_TOK_MINUS = 37,                 /* TOK_MINUS  */
  YYSYMBOL_TOK_MUL = 38,                   /* TOK_MUL  */
  YYSYMBOL_TOK_DIV = 39,                   /* TOK_DIV  */
  YYSYMBOL_TOK_MOD = 40,                   /* TOK_MOD  */
  YYSYMBOL_TOK_UMINUS = 41,                /* TOK_UMINUS  */
  YYSYMBOL_TOK_NOT = 42,                   /* TOK_NOT  */
  YYSYMBOL_TOK_BNOT = 43,                  /* TOK_BNOT  */
  YYSYMBOL_TOK_INTVAL = 44,                /* TOK_INTVAL  */
  YYSYMBOL_TOK_IDENT = 45,                 /* TOK_IDENT  */
  YYSYMBOL_TOK_STRING = 46,                /* TOK_STRING  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_listdecl = 49,                  /* listdecl  */
  YYSYMBOL_listdeclnonnull = 50,           /* listdeclnonnull  */
  YYSYMBOL_vardecl = 51,                   /* vardecl  */
  YYSYMBOL_type = 52,                      /* type  */
  YYSYMBOL_listtypedecl = 53,              /* listtypedecl  */
  YYSYMBOL_decl = 54,                      /* decl  */
  YYSYMBOL_maindecl = 55,                  /* maindecl  */
  YYSYMBOL_listinst = 56,                  /* listinst  */
  YYSYMBOL_listinstnonnull = 57,           /* listinstnonnull  */
  YYSYMBOL_inst = 58,                      /* inst  */
  YYSYMBOL_block = 59,                     /* block  */
  YYSYMBOL_expr = 60,                      /* expr  */
  YYSYMBOL_listparamprint = 61,            /* listparamprint  */
  YYSYMBOL_paramprint = 62,                /* paramprint  */
  YYSYMBOL_ident = 63                      /* ident  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    92,   100,   105,   112,   116,   126,   134,
     138,   142,   150,   154,   162,   166,   174,   182,   187,   194,
     198,   206,   210,   214,   218,   222,   226,   230,   234,   238,
     248,   255,   258,   262,   266,   270,   274,   278,   282,   286,
     290,   294,   298,   302,   306,   310,   314,   318,   322,   326,
     330,   334,   338,   342,   346,   350,   355,   359,   363,   370,
     373,   381,   384,   388
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
  "\"end of file\"", "error", "\"invalid token\"", "TOK_VOID", "TOK_INT",
  "TOK_BOOL", "TOK_TRUE", "TOK_FALSE", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_FOR", "TOK_DO", "TOK_PRINT", "TOK_SEMICOL", "TOK_COMA", "TOK_LPAR",
  "TOK_RPAR", "TOK_LACC", "TOK_RACC", "TOK_THEN", "TOK_AFFECT", "TOK_OR",
  "TOK_AND", "TOK_BOR", "TOK_BXOR", "TOK_BAND", "TOK_EQ", "TOK_NE",
  "TOK_GT", "TOK_LT", "TOK_GE", "TOK_LE", "TOK_SRL", "TOK_SRA", "TOK_SLL",
  "TOK_PLUS", "TOK_MINUS", "TOK_MUL", "TOK_DIV", "TOK_MOD", "TOK_UMINUS",
  "TOK_NOT", "TOK_BNOT", "TOK_INTVAL", "TOK_IDENT", "TOK_STRING",
  "$accept", "program", "listdecl", "listdeclnonnull", "vardecl", "type",
  "listtypedecl", "decl", "maindecl", "listinst", "listinstnonnull",
  "inst", "block", "expr", "listparamprint", "paramprint", "ident", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,   -44,   -44,   -44,     7,    15,   -44,   -43,   -44,   -44,
     -44,   -44,   -44,     1,   -44,   -13,   -44,   -43,    -8,    67,
     -44,    24,    31,   -44,   -44,    67,    67,    67,    67,   -44,
     284,    30,    15,   -44,   169,   -44,   -44,   -44,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    50,    15,
     -43,   -44,   302,   319,   335,   350,   364,   378,   378,   390,
     390,   390,   390,   398,   398,   398,   -17,   -17,   -44,   -44,
     -44,   284,    36,    38,    43,    50,    49,   -44,    48,    50,
     -44,   -44,    91,    67,    67,    67,    59,     2,   -44,   -44,
     -44,   193,   217,   118,    56,   -44,   -11,   -44,   -44,    50,
      50,    67,    67,     2,    61,    68,   -44,   145,   241,   -44,
     -44,    50,    67,    62,   -44,   265,   -44,    50,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,     9,    10,     0,     0,     6,     0,     3,     1,
       7,     2,    63,     0,    12,    14,     8,     0,     0,     0,
      13,    14,     0,    56,    57,     0,     0,     0,     0,    55,
      15,    58,     5,    16,     0,    38,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     4,
       0,    53,    44,    43,    46,    47,    45,    41,    42,    37,
      36,    39,    40,    48,    49,    50,    33,    34,    31,    32,
      35,    54,     0,     0,     0,     0,     0,    28,     0,    17,
      19,    27,     0,     0,     0,     0,     0,     0,    30,    20,
      21,     0,     0,     0,     0,    62,     0,    60,    61,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,    59,
      29,     0,     0,     0,    22,     0,    26,     0,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,   -44,    46,    -4,   -15,   -44,    69,    79,   -44,
     -44,   -39,    63,   -14,   -44,   -24,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,    58,     5,     6,     7,    13,    14,     8,    88,
      89,    90,    91,    92,   106,   107,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    10,    12,    18,   113,    30,   114,     9,    19,    22,
      21,    34,    35,    36,    37,    16,    17,    60,     1,     2,
       3,    54,    55,    56,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    60,    19,    96,    12,   105,    32,
      99,    57,    93,    21,    94,    10,    23,    24,    82,    95,
      83,    84,    85,    86,    87,    97,    25,    98,    32,   104,
     115,   116,   112,    23,    24,   120,   126,   121,    59,   101,
     102,   103,   124,    25,    11,    33,    20,    26,   128,   119,
     108,     0,    27,    28,    29,    12,     0,   117,   118,     0,
       0,     0,     0,     0,    26,   100,   108,     0,   125,    27,
      28,    29,    12,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,   111,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,   122,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    61,     0,     0,     0,
       0,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
     109,     0,     0,     0,     0,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,   110,     0,     0,     0,     0,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,   123,     0,
       0,     0,     0,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,   127,     0,     0,     0,     0,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    52,    53,    54,    55,    56
};

static const yytype_int8 yycheck[] =
{
       7,     5,    45,    16,    15,    19,    17,     0,    21,    17,
      17,    25,    26,    27,    28,    14,    15,    32,     3,     4,
       5,    38,    39,    40,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    59,    21,    85,    45,    46,    18,
      89,    21,    16,    60,    16,    59,     6,     7,     8,    16,
      10,    11,    12,    13,    14,    16,    16,    19,    18,    10,
     109,   110,    16,     6,     7,    14,    14,     9,    32,    93,
      94,    95,   121,    16,     5,    22,    17,    37,   127,   113,
      97,    -1,    42,    43,    44,    45,    -1,   111,   112,    -1,
      -1,    -1,    -1,    -1,    37,    14,   113,    -1,   122,    42,
      43,    44,    45,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    17,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    17,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    33,    34,    35,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    48,    50,    51,    52,    55,     0,
      51,    55,    45,    53,    54,    63,    14,    15,    16,    21,
      54,    63,    17,     6,     7,    16,    37,    42,    43,    44,
      60,    63,    18,    59,    60,    60,    60,    60,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    21,    49,    50,
      52,    17,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,     8,    10,    11,    12,    13,    14,    56,    57,
      58,    59,    60,    16,    16,    16,    58,    16,    19,    58,
      14,    60,    60,    60,    10,    46,    61,    62,    63,    17,
      17,    14,    16,    15,    17,    58,    58,    60,    60,    62,
      14,     9,    14,    17,    58,    60,    14,    17,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    50,    50,    51,    52,
      52,    52,    53,    53,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     1,     2,     3,     1,
       1,     1,     1,     3,     1,     3,     5,     1,     0,     1,
       2,     2,     7,     5,     5,     9,     7,     1,     1,     5,
       4,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1
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
        yyerror (program_root, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, program_root); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, node_t * program_root)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (program_root);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, node_t * program_root)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, program_root);
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
                 int yyrule, node_t * program_root)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], program_root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, program_root); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, node_t * program_root)
{
  YY_USE (yyvaluep);
  YY_USE (program_root);
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
yyparse (node_t * program_root)
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
  case 2: /* program: listdeclnonnull maindecl  */
#line 88 "grammar.y"
        {
            (yyval.ptr) = make_node(NODE_PROGRAM, 2, (yyvsp[-1].ptr), (yyvsp[0].ptr));
            *program_root = (yyval.ptr);
        }
#line 1451 "y.tab.c"
    break;

  case 3: /* program: maindecl  */
#line 93 "grammar.y"
        {
            (yyval.ptr) = make_node(NODE_PROGRAM, 2, NULL, (yyvsp[0].ptr));
            *program_root = (yyval.ptr);
        }
#line 1460 "y.tab.c"
    break;

  case 4: /* listdecl: listdeclnonnull  */
#line 101 "grammar.y"
        {
		(yyval.ptr) = (yyvsp[0].ptr);
	}
#line 1468 "y.tab.c"
    break;

  case 5: /* listdecl: %empty  */
#line 105 "grammar.y"
        {
		(yyval.ptr) = NULL;
	}
#line 1476 "y.tab.c"
    break;

  case 6: /* listdeclnonnull: vardecl  */
#line 113 "grammar.y"
        {
		(yyval.ptr) = (yyvsp[0].ptr);
	}
#line 1484 "y.tab.c"
    break;

  case 7: /* listdeclnonnull: listdeclnonnull vardecl  */
#line 117 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_LIST, 2,(yyvsp[-1].ptr), (yyvsp[0].ptr)); 
	}
#line 1492 "y.tab.c"
    break;

  case 8: /* vardecl: type listtypedecl TOK_SEMICOL  */
#line 127 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_DECLS, 2, (yyvsp[-2].ptr), (yyvsp[-1].ptr)); 
	}
#line 1500 "y.tab.c"
    break;

  case 9: /* type: TOK_INT  */
#line 135 "grammar.y"
        {
		(yyval.ptr) = make_node_type(TYPE_INT);
	}
#line 1508 "y.tab.c"
    break;

  case 10: /* type: TOK_BOOL  */
#line 139 "grammar.y"
        {
		(yyval.ptr) = make_node_type(TYPE_BOOL);
	}
#line 1516 "y.tab.c"
    break;

  case 11: /* type: TOK_VOID  */
#line 143 "grammar.y"
        {
		(yyval.ptr) = make_node_type(TYPE_VOID);
	}
#line 1524 "y.tab.c"
    break;

  case 12: /* listtypedecl: decl  */
#line 151 "grammar.y"
        {
		(yyval.ptr) = (yyvsp[0].ptr);
	}
#line 1532 "y.tab.c"
    break;

  case 13: /* listtypedecl: listtypedecl TOK_COMA decl  */
#line 155 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_LIST, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr)); 
	}
#line 1540 "y.tab.c"
    break;

  case 14: /* decl: ident  */
#line 163 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_DECL, 1, (yyvsp[0].ptr));
	}
#line 1548 "y.tab.c"
    break;

  case 15: /* decl: ident TOK_AFFECT expr  */
#line 167 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_DECL, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr)); 
	}
#line 1556 "y.tab.c"
    break;

  case 16: /* maindecl: type ident TOK_LPAR TOK_RPAR block  */
#line 175 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_FUNC, 3, (yyvsp[-4].ptr), (yyvsp[-3].ptr), (yyvsp[0].ptr)); 
	}
#line 1564 "y.tab.c"
    break;

  case 17: /* listinst: listinstnonnull  */
#line 183 "grammar.y"
        {
		(yyval.ptr) = (yyvsp[0].ptr);
	}
#line 1572 "y.tab.c"
    break;

  case 18: /* listinst: %empty  */
#line 187 "grammar.y"
        {
		(yyval.ptr) = NULL;
	}
#line 1580 "y.tab.c"
    break;

  case 19: /* listinstnonnull: inst  */
#line 195 "grammar.y"
        {
		(yyval.ptr) = (yyvsp[0].ptr);
	}
#line 1588 "y.tab.c"
    break;

  case 20: /* listinstnonnull: listinstnonnull inst  */
#line 199 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_LIST, 2, (yyvsp[-1].ptr), (yyvsp[0].ptr)); 
	}
#line 1596 "y.tab.c"
    break;

  case 21: /* inst: expr TOK_SEMICOL  */
#line 207 "grammar.y"
        {
		(yyval.ptr) = (yyvsp[-1].ptr); 
	}
#line 1604 "y.tab.c"
    break;

  case 22: /* inst: TOK_IF TOK_LPAR expr TOK_RPAR inst TOK_ELSE inst  */
#line 211 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_IF, 3, (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); 
	}
#line 1612 "y.tab.c"
    break;

  case 23: /* inst: TOK_IF TOK_LPAR expr TOK_RPAR inst  */
#line 215 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_IF, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr)); 
	}
#line 1620 "y.tab.c"
    break;

  case 24: /* inst: TOK_WHILE TOK_LPAR expr TOK_RPAR inst  */
#line 219 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_WHILE, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr)); 
	}
#line 1628 "y.tab.c"
    break;

  case 25: /* inst: TOK_FOR TOK_LPAR expr TOK_SEMICOL expr TOK_SEMICOL expr TOK_RPAR inst  */
#line 223 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_FOR, 4, (yyvsp[-6].ptr), (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); 
	}
#line 1636 "y.tab.c"
    break;

  case 26: /* inst: TOK_DO inst TOK_WHILE TOK_LPAR expr TOK_RPAR TOK_SEMICOL  */
#line 227 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_DOWHILE, 2, (yyvsp[-5].ptr), (yyvsp[-2].ptr)); 
	}
#line 1644 "y.tab.c"
    break;

  case 27: /* inst: block  */
#line 231 "grammar.y"
        {
		(yyval.ptr) = (yyvsp[0].ptr);
	}
#line 1652 "y.tab.c"
    break;

  case 28: /* inst: TOK_SEMICOL  */
#line 235 "grammar.y"
        {
		(yyval.ptr) = NULL; 
	}
#line 1660 "y.tab.c"
    break;

  case 29: /* inst: TOK_PRINT TOK_LPAR listparamprint TOK_RPAR TOK_SEMICOL  */
#line 239 "grammar.y"
        {
		(yyval.ptr) = make_node(NODE_PRINT, 1, (yyvsp[-2].ptr)); 
	}
#line 1668 "y.tab.c"
    break;

  case 30: /* block: TOK_LACC listdecl listinst TOK_RACC  */
#line 249 "grammar.y"
        {	
		(yyval.ptr) = make_node(NODE_BLOCK, 2, (yyvsp[-2].ptr), (yyvsp[-1].ptr));
	}
#line 1676 "y.tab.c"
    break;

  case 31: /* expr: expr TOK_MUL expr  */
#line 255 "grammar.y"
                         {
		(yyval.ptr) = make_node(NODE_MUL, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1684 "y.tab.c"
    break;

  case 32: /* expr: expr TOK_DIV expr  */
#line 258 "grammar.y"
                           {
		(yyval.ptr) = make_node(NODE_DIV, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1692 "y.tab.c"
    break;

  case 33: /* expr: expr TOK_PLUS expr  */
#line 262 "grammar.y"
                            {
		(yyval.ptr) = make_node(NODE_PLUS, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1700 "y.tab.c"
    break;

  case 34: /* expr: expr TOK_MINUS expr  */
#line 266 "grammar.y"
                             {
		(yyval.ptr) = make_node(NODE_MINUS, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1708 "y.tab.c"
    break;

  case 35: /* expr: expr TOK_MOD expr  */
#line 270 "grammar.y"
                           {
		(yyval.ptr) = make_node(NODE_MOD, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1716 "y.tab.c"
    break;

  case 36: /* expr: expr TOK_LT expr  */
#line 274 "grammar.y"
                          {
		(yyval.ptr) = make_node(NODE_LT, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1724 "y.tab.c"
    break;

  case 37: /* expr: expr TOK_GT expr  */
#line 278 "grammar.y"
                          {
		(yyval.ptr) = make_node(NODE_GT, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1732 "y.tab.c"
    break;

  case 38: /* expr: TOK_MINUS expr  */
#line 282 "grammar.y"
                                         {
		(yyval.ptr) = make_node(NODE_UMINUS, 1, (yyvsp[0].ptr));
	}
#line 1740 "y.tab.c"
    break;

  case 39: /* expr: expr TOK_GE expr  */
#line 286 "grammar.y"
                          {
		(yyval.ptr) = make_node(NODE_GE, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1748 "y.tab.c"
    break;

  case 40: /* expr: expr TOK_LE expr  */
#line 290 "grammar.y"
                          {
		(yyval.ptr) = make_node(NODE_LE, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1756 "y.tab.c"
    break;

  case 41: /* expr: expr TOK_EQ expr  */
#line 294 "grammar.y"
                          {
		(yyval.ptr) = make_node(NODE_EQ, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1764 "y.tab.c"
    break;

  case 42: /* expr: expr TOK_NE expr  */
#line 298 "grammar.y"
                          {
		(yyval.ptr) = make_node(NODE_NE, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1772 "y.tab.c"
    break;

  case 43: /* expr: expr TOK_AND expr  */
#line 302 "grammar.y"
                           {
		(yyval.ptr) = make_node(NODE_AND, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1780 "y.tab.c"
    break;

  case 44: /* expr: expr TOK_OR expr  */
#line 306 "grammar.y"
                          {
		(yyval.ptr) = make_node(NODE_OR, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1788 "y.tab.c"
    break;

  case 45: /* expr: expr TOK_BAND expr  */
#line 310 "grammar.y"
                            {
		(yyval.ptr) = make_node(NODE_BAND, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1796 "y.tab.c"
    break;

  case 46: /* expr: expr TOK_BOR expr  */
#line 314 "grammar.y"
                           {
		(yyval.ptr) = make_node(NODE_BOR, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1804 "y.tab.c"
    break;

  case 47: /* expr: expr TOK_BXOR expr  */
#line 318 "grammar.y"
                            {
		(yyval.ptr) = make_node(NODE_BXOR, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1812 "y.tab.c"
    break;

  case 48: /* expr: expr TOK_SRL expr  */
#line 322 "grammar.y"
                           {
		(yyval.ptr) = make_node(NODE_SRL, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1820 "y.tab.c"
    break;

  case 49: /* expr: expr TOK_SRA expr  */
#line 326 "grammar.y"
                           {
		(yyval.ptr) = make_node(NODE_SRA, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1828 "y.tab.c"
    break;

  case 50: /* expr: expr TOK_SLL expr  */
#line 330 "grammar.y"
                           {
		(yyval.ptr) = make_node(NODE_SLL, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1836 "y.tab.c"
    break;

  case 51: /* expr: TOK_NOT expr  */
#line 334 "grammar.y"
                      {
		(yyval.ptr) = make_node(NODE_NOT, 1, (yyvsp[0].ptr));
	}
#line 1844 "y.tab.c"
    break;

  case 52: /* expr: TOK_BNOT expr  */
#line 338 "grammar.y"
                       {
		(yyval.ptr) = make_node(NODE_BNOT, 1, (yyvsp[0].ptr));
	}
#line 1852 "y.tab.c"
    break;

  case 53: /* expr: TOK_LPAR expr TOK_RPAR  */
#line 342 "grammar.y"
                                {
		(yyval.ptr) = (yyvsp[-1].ptr);
	}
#line 1860 "y.tab.c"
    break;

  case 54: /* expr: ident TOK_AFFECT expr  */
#line 346 "grammar.y"
                               {
		(yyval.ptr) = make_node(NODE_AFFECT, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1868 "y.tab.c"
    break;

  case 55: /* expr: TOK_INTVAL  */
#line 351 "grammar.y"
        {
		(yyval.ptr) = make_node_intval((yyvsp[0].intval));
	}
#line 1876 "y.tab.c"
    break;

  case 56: /* expr: TOK_TRUE  */
#line 356 "grammar.y"
        {
		(yyval.ptr) = make_node_boolval(true);
	}
#line 1884 "y.tab.c"
    break;

  case 57: /* expr: TOK_FALSE  */
#line 360 "grammar.y"
        {
		(yyval.ptr) = make_node_boolval(false);
	}
#line 1892 "y.tab.c"
    break;

  case 58: /* expr: ident  */
#line 364 "grammar.y"
        {
		(yyval.ptr) = (yyvsp[0].ptr);
	}
#line 1900 "y.tab.c"
    break;

  case 59: /* listparamprint: listparamprint TOK_COMA paramprint  */
#line 370 "grammar.y"
                                          {
		(yyval.ptr) = make_node(NODE_LIST, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
	}
#line 1908 "y.tab.c"
    break;

  case 60: /* listparamprint: paramprint  */
#line 374 "grammar.y"
        {
		(yyval.ptr) = (yyvsp[0].ptr);
	}
#line 1916 "y.tab.c"
    break;

  case 61: /* paramprint: ident  */
#line 381 "grammar.y"
             {
		(yyval.ptr) = (yyvsp[0].ptr);
	}
#line 1924 "y.tab.c"
    break;

  case 62: /* paramprint: TOK_STRING  */
#line 384 "grammar.y"
                   {
		(yyval.ptr) = make_node_stringval((yyvsp[0].strval));
	}
#line 1932 "y.tab.c"
    break;

  case 63: /* ident: TOK_IDENT  */
#line 388 "grammar.y"
                 {
		(yyval.ptr) = make_node_ident((yyvsp[0].strval));
	}
#line 1940 "y.tab.c"
    break;


#line 1944 "y.tab.c"

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
      yyerror (program_root, YY_("syntax error"));
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
                      yytoken, &yylval, program_root);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, program_root);
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
  yyerror (program_root, YY_("memory exhausted"));
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
                  yytoken, &yylval, program_root);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, program_root);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 395 "grammar.y"


/* A completer et/ou remplacer avec d'autres fonctions */
node_t make_node(node_nature nature, int nops, ...) {
	node_t node=malloc(sizeof(node_s));
	node->nature=nature;
	

	if(nops>=1){
		node->opr=malloc(sizeof(node_t)*nops);
		va_list args;
	    	va_start(args, nops);
	   	for(int i=0;i<nops;i++){
	    		node->opr[i]=va_arg(args, node_t);
	    	}
	 	va_end(args);
	 }
	 else{
	 	node-> opr = NULL; 
	 }

	node->ident = NULL;
    	node->str = NULL;
    	node->decl_node = NULL;
    	node->value = -1;
	node->nops = nops;
	node->lineno=yylineno;
	node->type = TYPE_NONE;
	node->offset = -1;
	node->node_num = -1;
	node->global_decl = false;
	nbno++;
	return node;
}




//noeux terminal ident
node_t make_node_ident(char* s){

	node_t tmp=make_node(NODE_IDENT, 0);
	tmp->ident=strdupl(s);

	return tmp;
}




//noeux terminal str
node_t make_node_stringval(char* s){
	node_t tmp=make_node(NODE_STRINGVAL, 0);
	tmp->str=strdupl(s);
	return tmp;
}

node_t make_node_intval(int64_t value){
	node_t tmp = make_node(NODE_INTVAL, 0);
	tmp->value = value;
	return tmp;
}
node_t make_node_boolval(int64_t value){
	node_t tmp = make_node(NODE_BOOLVAL, 0);
	tmp->value = value;
	return tmp;
}




node_t make_node_type(node_type type){
	node_t tmp=make_node(NODE_TYPE, 0);
	tmp->type=type;
	return tmp;
}


void analyse_tree(node_t root) {
    dump_tree(root, "apres_syntaxe.dot");
    if (!stop_after_syntax) {
        analyse_passe_1(root);
        dump_tree(root, "apres_passe_1.dot");
        if (!stop_after_verif) {
            create_program(); 
            gen_code_passe_2(root);
            dump_mips_program(outfile);
            free_program();
        }
        free_global_strings();
    }
    free_nodes(root);
}



/* Cette fonction est appelee automatiquement si une erreur de syntaxe est rencontree
 * N'appelez pas cette fonction vous-meme :    
 * la valeur donnee par yylineno ne sera plus correcte apres l'analyse syntaxique
 */
void yyerror(node_t * program_root, char * s) {
    fprintf(stderr, "Error line %d: %s\n", yylineno, s);
    exit(1);
}

