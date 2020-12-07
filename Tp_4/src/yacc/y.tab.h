/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 22 "translate.y" /* yacc.c:1921  */

	struct abstract_syntax_tree *val;
	int type;
	int count;

#line 124 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
