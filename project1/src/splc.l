%{
#include "node.h"
#include "splc.tab.h"

static int prev_state;

void yyerror(const char* s);
void int_to_str(int type);
void set_val(char* type_name,int type);
void print_error();
%}

%option noyywrap
%option yylineno
%x BLK_COMMENT

digit [0-9]
hex [0-9a-fA-F]
letter [a-zA-Z]
letter_ [a-zA-Z_]
delim [ \t\n]
newline  (\n|\r|\r\n)

decimal (0|-?[1-9]{digit}{0,9})
hexadecimal (0(x|X)(0|[1-9a-fA-F][0-9a-fA-F]*))

ws ({delim}+)
float_ ({decimal}\.{decimal})
character (('[^']')|('\\x{hex}{1,2}'))
type_ (int|float|char)
id_ ({letter_}({letter_}|{digit}){0,31})

line_cmmt       "//"[^\r\n]*
blk_cmmt_begin  "/*"
blk_cmmt_end    "*/"

%%
{line_cmmt}   {}
{blk_cmmt_begin}                { prev_state = YYSTATE; BEGIN BLK_COMMENT; }
{blk_cmmt_end}                  { printf("Illegal block comment at %d\n",yylineno); return ERROR; }
<BLK_COMMENT>{blk_cmmt_begin}   { printf("Illegal block comment at %d\n",yylineno); return ERROR; }
<BLK_COMMENT>{blk_cmmt_end}     { BEGIN prev_state; }
<BLK_COMMENT>(.|{newline})      ;

{ws} {}
{decimal} { int_to_str(1); return INT;}
{hexadecimal} { int_to_str(2); return INT;}
{float_} { set_val("FLOAT",FLOAT); return FLOAT;}
{character} { set_val("CHAR",CHAR); return CHAR;}
{type_} { set_val("TYPE",TYPE); return TYPE;}

"struct" { set_val("STRUCT",STRUCT); return STRUCT; }
"if" { set_val("IF",IF); return IF; }
"else" { set_val("ELSE",ELSE); return ELSE; }
"while" { set_val("WHILE",WHILE); return WHILE; }
"return" { set_val("RETURN",RETURN); return RETURN; }
"." { set_val("DOT",DOT); return DOT; }
";" { set_val("SEMI",SEMI); return SEMI; }
"," { set_val("COMMA",COMMA); return COMMA; }
"=" { set_val("ASSIGN",ASSIGN); return ASSIGN; }
"<" { set_val("LT",LT); return LT; }
"<=" { set_val("LE",LE); return LE; }
">" { set_val("GT",GT); return GT; }
">=" { set_val("GE",GE);  return GE; }
"!=" { set_val("NE",NE); return NE; }
"==" { set_val("EQ",EQ); return EQ; }
"+" { set_val("PLUS",PLUS); return PLUS; }
"-" { set_val("MINUS",MINUS);  return MINUS; }
"*" { set_val("MUL",MUL); return MUL; }
"/" { set_val("DIV",DIV); return DIV; }
"&&" { set_val("AND",AND); return AND; }
"||" { set_val("OR",OR); return OR; }
"!" { set_val("NOT",NOT); return NOT; }
"(" { set_val("LP",LP); return LP; }
")" { set_val("RP",RP); return RP; }
"[" { set_val("LB",LB); return LB; }
"]" { set_val("RB",RB); return RB; }
"{" { set_val("LC",LC); return LC; }
"}" { set_val("RC",RC); return RC; }

{id_} { set_val("ID",ID); return ID;}
[0-9]+{id_} { print_error(); return ERROR;}
(0[xX][0-9]*[g-zG-Z]+)|(0[0-9]+) {print_error(); return ERROR;}
'[[:print:]]*' { print_error(); return ERROR;}
. { print_error(); return ERROR;}

%%
void int_to_str(int type)
{
    int num;
    if(type==1){
        num=atoi(yytext);
    }else if(type==2){
        num = strtol(yytext, NULL, 16);
    }
    char tmp_str[30];
    sprintf(tmp_str,"%d",num);
    yylval = create_node(tmp_str,"INT",yylineno,INT);
}
void set_val(char* type_name,int type)
{
    yylval = create_node(yytext, type_name, yylineno, type);
}
void print_error(){
    printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext); 
}