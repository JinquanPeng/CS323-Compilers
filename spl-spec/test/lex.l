%option noyywrap
%option yylineno

%{
    #include "node.c"
    #include "syntax.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void yyerror(const char *s);
    int tmp_num ;
    char tmp_str[20];
%}

int     (0|-?[1-9][0-9]*)|(0[xX](0|[1-9a-f][0-9a-f]*))
frac    \.[0-9]+
float   -?(0|[1-9][0-9]*){frac}
char    '[a-zA-Z0-9_]'
id      [_a-zA-Z][_a-zA-Z0-9]*
type    int|float|char
empty   [ \t\b\r\n]

%%

{type}                   { yylval = new_node(yytext, "TYPE", yylineno, TYPE); return TYPE; }
{float}                  { yylval = new_node(yytext, "FLOAT", yylineno, FLOAT); return FLOAT; }
{char}                   { yylval = new_node(yytext, "CHAR", yylineno, CHAR); return CHAR; }
'\\[xX][0-9a-fA-F]{2}'   { yylval = new_node(yytext, "CHAR", yylineno, CHAR); return CHAR; }

([1-9][0-9]*|[0]{1,1})                     { tmp_num =atoi(yytext); sprintf(tmp_str,"%d",tmp_num); yylval = new_node(tmp_str,"INT", yylineno, INT); return INT; }
(0[Xx]([1-9a-fA-F][0-9a-fA-F]*|[0]{1,1}))  { tmp_num = strtol(yytext, NULL, 16); sprintf(tmp_str,"%d",tmp_num); yylval = new_node(tmp_str,"INT", yylineno, INT); return INT; }

"struct"     { yylval = new_node(yytext, "STRUCT", yylineno, STRUCT); return STRUCT; }
"if"         { yylval = new_node(yytext, "IF", yylineno, IF); return IF; }
"else"       { yylval = new_node(yytext, "ELSE", yylineno, ELSE); return ELSE; }
"while"      { yylval = new_node(yytext, "WHILE", yylineno, WHILE); return WHILE; }
"return"     { yylval = new_node(yytext, "RETURN", yylineno, RETURN); return RETURN; }
"."          { yylval = new_node(yytext, "DOT", yylineno, DOT); return DOT; }
";"          { yylval = new_node(yytext, "SEMI", yylineno, SEMI); return SEMI; }
","          { yylval = new_node(yytext, "COMMA", yylineno, COMMA); return COMMA; }
"="          { yylval = new_node(yytext, "ASSIGN", yylineno, ASSIGN); return ASSIGN; }
"<"          { yylval = new_node(yytext, "LT", yylineno, LT); return LT; }
"<="         { yylval = new_node(yytext, "LE", yylineno, LE); return LE; }
">"          { yylval = new_node(yytext, "GT", yylineno, GT); return GT; }
">="         { yylval = new_node(yytext, "GE", yylineno, GE);  return GE; }
"!="         { yylval = new_node(yytext, "NE", yylineno, NE); return NE; }
"=="         { yylval = new_node(yytext, "EQ", yylineno, EQ); return EQ; }
"+"          { yylval = new_node(yytext, "PLUS", yylineno, PLUS); return PLUS; }
"-"          { yylval = new_node(yytext, "MINUS", yylineno, MINUS);  return MINUS; }
"*"          { yylval = new_node(yytext, "MUL", yylineno, MUL); return MUL; }
"/"          { yylval = new_node(yytext, "DIV", yylineno, DIV); return DIV; }
"&&"         { yylval = new_node(yytext, "AND", yylineno, AND); return AND; }
"||"         { yylval = new_node(yytext, "OR", yylineno, OR); return OR; }
"!"          { yylval = new_node(yytext, "NOT", yylineno, NOT); return NOT; }
"("          { yylval = new_node(yytext, "LP", yylineno, LP); return LP; }
")"          { yylval = new_node(yytext, "RP", yylineno, RP); return RP; }
"["          { yylval = new_node(yytext, "LB", yylineno, LB); return LB; }
"]"          { yylval = new_node(yytext, "RB", yylineno, RB); return RB; }
"{"          { yylval = new_node(yytext, "LC", yylineno, LC); return LC; }
"}"          { yylval = new_node(yytext, "RC", yylineno, RC); return RC; }

{id}         { yylval = new_node(yytext, "ID", yylineno, ID); return ID; }
{empty}      { }

[0-9]+{id}                         { printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext); return ERR; }
(0[xX][0-9]*[g-zG-Z]+)|(0[0-9]+)   { printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext); return ERR; }
'[[:print:]]*'                     { printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext); return ERR; }
0[0-9]+{frac}                      { printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext); return ERR; }
.                                  { printf("Error type A at Line %d: unknown lexeme %s\n",yylineno,yytext); return ERR; }

%%