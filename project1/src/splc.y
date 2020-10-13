%{
#define YYSTYPE Node *
#include "lex.yy.c"

void yyerror(const char* e);
void display(Node *root, int depth);
Node* new_node;
int fail = 0;
%}

%token ERROR
%token INT FLOAT CHAR
%token ID 
%token TYPE 
%token STRUCT
%token IF ELSE WHILE RETURN
%token DOT SEMI COMMA
%token ASSIGN
%token LT LE GT GE NE EQ
%token PLUS MINUS MUL DIV
%token AND OR NOT
%token LP RP LB RB LC RC

%right ASSIGN
%left  OR
%left  AND
%left  LT LE GT GE EQ NE
%left  PLUS MINUS
%left  MUL DIV
%right NOT
%left  LP RP LB RB LC RC DOT


%%
/* high-level definition */
Program: ExtDefList                       { new_node = create_node("Program", "", $1->line_no, 1); insert_node(new_node, $1); }
   ;
ExtDefList: ExtDef ExtDefList             { new_node = create_node("ExtDefList", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); $$ = new_node; }
   | %empty                               { new_node = create_node("", "", 0, 0); $$ = new_node;}
   ;
ExtDef: 
      Specifier ExtDecList SEMI           { new_node = create_node("ExtDef", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Specifier SEMI                      { new_node = create_node("ExtDef", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); $$ = new_node; }
   |  Specifier FunDec CompSt             { new_node = create_node("ExtDef", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Specifier ExtDecList error          { printf("Error type B at Line %d: Missing semicolon ';'\n", $2->line_no); }
   |  error SEMI                          { printf("Error type B at Line %d: Missing specifier\n",$2->line_no); }
   ;
ExtDecList: VarDec                        { new_node = create_node("ExtDecList", "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node; }
   |  VarDec COMMA ExtDecList             { new_node = create_node("ExtDecList", "", $1->line_no, 1);  insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   ;

/* specifier */
Specifier: TYPE                           { new_node = create_node("Specifier", "", $1->line_no, 1);  insert_node(new_node, $1); $$ = new_node; }
   |  StructSpecifier                     { new_node = create_node("Specifier", "", $1->line_no, 1);  insert_node(new_node, $1); $$ = new_node; }
   ;
StructSpecifier: STRUCT ID LC DefList RC  { new_node = create_node("StructSpecifier", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); insert_node(new_node, $4); insert_node(new_node, $5); $$ = new_node; }
   |  STRUCT ID                           { new_node = create_node("StructSpecifier", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); $$ = new_node; }
   ;

/* declarator */
VarDec: ID                                { new_node = create_node("VarDec", "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node; }
   |  VarDec LB INT RB                    { new_node = create_node("VarDec", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); insert_node(new_node, $4); $$ = new_node; }
   | ERROR                                { fail = 1;}
   ;
FunDec:
      ID LP VarList RP                    { new_node = create_node("FunDec", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); insert_node(new_node, $4); $$ = new_node; }
   |  ID LP RP                            { new_node = create_node("FunDec", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  ID LP VarList error LC              { unput('{'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no); }
   |  ID LP error LC                      { unput('{'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no); }
   ;
VarList: ParamDec COMMA VarList           { new_node = create_node("VarList", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  ParamDec                            { new_node = create_node("VarList", "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node;  }
   ;
ParamDec:
      Specifier VarDec                    { new_node = create_node("ParamDec", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); $$ = new_node;  }
   |  error VarDec                        { printf("Error type B at Line %d: Missing semicolon ';'\n", $2->line_no); }
   ;

/* statement */
CompSt: LC DefList StmtList RC            { new_node = create_node("CompSt", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); insert_node(new_node, $4); $$ = new_node;  }
   ;
StmtList: Stmt StmtList                   { new_node = create_node("StmtList", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); $$ = new_node; }
   |  %empty                              { new_node = create_node("", "", 0, 0); $$ = new_node; }
   ;
Stmt:
      Exp SEMI                            {  new_node = create_node("Stmt", "", $1->line_no, 1);  insert_node(new_node, $1); insert_node(new_node, $2); $$ = new_node;}
   |  CompSt                              { new_node = create_node("Stmt", "", $1->line_no, 1);  insert_node(new_node, $1); $$ = new_node;}
   |  RETURN Exp SEMI                     { new_node = create_node("Stmt", "", $1->line_no, 1);  insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp error                           { printf("Error type B at Line %d: Missing semicolon ';'\n",$1->line_no); }
   |  RETURN Exp error SEMI               { printf("Error type B at Line %d: Missing semicolon ';'\n",$1->line_no);  }
   |  IF LP Exp RP Stmt                   { new_node = create_node("Stmt", "", $1->line_no, 1);  insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); insert_node(new_node, $4); insert_node(new_node, $5); $$ = new_node; }
   |  IF LP Exp RP Stmt ELSE Stmt         { new_node = create_node("Stmt", "", $1->line_no, 1);  insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); insert_node(new_node, $4); insert_node(new_node, $5); insert_node(new_node, $6); insert_node(new_node, $7); $$ = new_node; }
   |  WHILE LP Exp RP Stmt                { new_node = create_node("Stmt", "", $1->line_no, 1);  insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); insert_node(new_node, $4); insert_node(new_node, $5); $$ = new_node; }
   ;

/* local definition */
DefList:
      Def DefList                         { new_node = create_node("DefList",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); $$ = new_node; }
   |  %empty                              { new_node = create_node("", "", 0, 0); $$ = new_node; }
   ;
Def:
      Specifier DecList SEMI              { new_node = create_node("Def", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Specifier DecList error SEMI        { printf("Error type B at Line %d: Missing semicolon ';'\n", $2->line_no);  }
   |  error DecList SEMI                  { printf("Error type B at Line %d: Missing specifier\n", $2->line_no);  }
   |  error FunDec CompSt                 { printf("Error type B at Line %d: Missing specifier\n", $2->line_no);  }
   ;
DecList:
      Dec                                 { new_node = create_node("DecList", "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node; }
   |  Dec COMMA DecList                   { new_node = create_node("DecList",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   ;
Dec:
      VarDec                              { new_node = create_node("Dec", "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node; }
   |  VarDec ASSIGN Exp                   { new_node = create_node("Dec", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  VarDec ASSIGN ERROR                 { fail = 1;}
   ;

/* Expression */
Exp:
      Exp ASSIGN Exp                      { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp ERROR Exp                       { fail = 1;} 
   |  Exp ASSIGN ERROR                    { fail = 1; }
   |  Exp AND Exp                         { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp OR Exp                          { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp LT Exp                          { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp LE Exp                          { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp GT Exp                          { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp GE Exp                          { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp NE Exp                          { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp EQ Exp                          { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp PLUS Exp                        { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp MINUS Exp                       { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp MUL Exp                         { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp DIV Exp                         { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  LP Exp RP                           { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  LP Exp error RP                     { printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no); }
   |  MINUS Exp %prec MINUS                 { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); $$ = new_node; }
   |  ID LP Args error SEMI               { unput(';'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no); }
   |  NOT Exp                             { new_node = create_node("Exp",  "", $1->line_no, 1);  insert_node(new_node, $1); insert_node(new_node, $2); $$ = new_node; }
   |  ID LP Args RP                       { new_node = create_node("Exp",  "", $1->line_no, 1);  insert_node(new_node, $1); insert_node(new_node, $2);  insert_node(new_node, $3); insert_node(new_node, $4); $$ = new_node;  }
   |  ID LP RP                            { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp LB Exp RB                       { new_node = create_node("Exp",  "", $1->line_no, 1);  insert_node(new_node, $1); insert_node(new_node, $2);  insert_node(new_node, $3); insert_node(new_node, $4); $$ = new_node;  }
   |  Exp DOT ID                          { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  ID                                  { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node; }
   |  INT                                 {  new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node; }
   |  FLOAT                               { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node; }
   |  CHAR                                { new_node = create_node("Exp",  "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node; }
   |  ID LP error RP                      { printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no);  }
   ;
Args:
      Exp COMMA Args                      { new_node = create_node("Args", "", $1->line_no, 1); insert_node(new_node, $1); insert_node(new_node, $2); insert_node(new_node, $3); $$ = new_node; }
   |  Exp                                 { new_node = create_node("Args", "", $1->line_no, 1); insert_node(new_node, $1); $$ = new_node; }
   ;

%%

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

