%{
    #define YYSTYPE Node *
    #include "lex.yy.c"
    void yyerror (const char* msg){}
    Node* temp;
    int FAIL = 0;
%}

%token TYPE ERR
%token CHAR INT FLOAT
%token ID
%token STRUCT IF ELSE WHILE RETURN
%token DOT SEMI COMMA ASSIGN
%token LT LE GT GE NE EQ
%token PLUS MINUS MUL DIV SUB
%token AND OR NOT
%token LP RP LB RB LC RC

%nonassoc THEN
%nonassoc ELSE
%nonassoc ERR
%right ASSIGN
%left  OR
%left  AND
%left  LT LE GT GE EQ NE
%left  PLUS SUB
%left  MUL DIV
%right NOT
%right TYPE MINUS
%left  DOT LP RP LB RB

%%


Program:
      ExtDefList                          { temp = new_node("Program", "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   ;
ExtDefList:
      ExtDef ExtDefList                   { temp = new_node("ExtDefList", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); $$ = temp; }
   |  %empty                              { temp = new_node("NULL", "NULL", 0, 0); $$ = temp;}
   ;
ExtDef:
      Specifier ExtDecList SEMI           { temp = new_node("ExtDef", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Specifier SEMI                      { temp = new_node("ExtDef", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); $$ = temp; }
   |  Specifier FunDec CompSt             { temp = new_node("ExtDef", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Specifier ExtDecList error          { printf("Error type B at Line %d: Missing semicolon ';'\n", $2->line_no); FAIL = 1; }
   |  error SEMI                          { printf("Error type B at Line %d: Missing specifier\n",$2->line_no); FAIL = 1;}
   ;
ExtDecList:
      VarDec                              { temp = new_node("ExtDecList", "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   |  VarDec COMMA ExtDecList             { temp = new_node("ExtDecList", "NULL", $1->line_no, 233);  insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   ;

Specifier:
      TYPE                                { temp = new_node("Specifier", "NULL", $1->line_no, 233);  insert_node(temp, $1); $$ = temp; }
   |  StructSpecifier                     { temp = new_node("Specifier", "NULL", $1->line_no, 233);  insert_node(temp, $1); $$ = temp; }
   ;
StructSpecifier:
      STRUCT ID LC DefList RC             { temp = new_node("StructSpecifier", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); insert_node(temp, $4); insert_node(temp, $5); $$ = temp; }
   |  STRUCT ID                           { temp = new_node("StructSpecifier", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); $$ = temp; }
   ;

VarDec:
      ID                                  { temp = new_node("VarDec", "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   |  VarDec LB INT RB                    { temp = new_node("VarDec", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); insert_node(temp, $4); $$ = temp; }
   |  ERR                                 { FAIL = 1; }
   ;
FunDec:
      ID LP VarList RP                    { temp = new_node("FunDec", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); insert_node(temp, $4); $$ = temp; }
   |  ID LP RP                            { temp = new_node("FunDec", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  ID LP VarList error LC              { unput('{'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no); FAIL = 1;}
   |  ID LP error LC                      { unput('{'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no); FAIL = 1;}
   /*
   |  ID ERR VarList RP                   { FAIL = 1;}
   |  ID ERR RP                           { FAIL = 1;}
   |  ERR LP RP                           { FAIL = 1;}
   */
   ;
VarList:
      ParamDec COMMA VarList              { temp = new_node("VarList", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  ParamDec                            { temp = new_node("VarList", "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp;  }
   ;
ParamDec:
      Specifier VarDec                    { temp = new_node("ParamDec", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); $$ = temp;  }
   |  error VarDec                     { printf("Error type B at Line %d: Missing semicolon ';'\n", $2->line_no); FAIL = 1;}
   ;

CompSt:
      LC DefList StmtList RC              { temp = new_node("CompSt", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); insert_node(temp, $4); $$ = temp;  }
   /*
   |  LC DefList error                    { printf("Error type B at line %d: Missing closing brace '}'\n", $1->line_no); }
   |  LC error                            { printf("Error type B at line %d: Missing closing brace '}'\n", $1->line_no); }
   */
   ;
StmtList:
      Stmt StmtList                       { temp = new_node("StmtList", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); $$ = temp; }
   |  %empty                              { temp = new_node("NULL", "NULL", 0, 0); $$ = temp; }
   ;
Stmt:
      Exp SEMI                            { temp = new_node("Stmt", "NULL", $1->line_no, 233);  insert_node(temp, $1); insert_node(temp, $2); $$ = temp;}
   |  CompSt                              { temp = new_node("Stmt", "NULL", $1->line_no, 233);  insert_node(temp, $1); $$ = temp;}
   |  RETURN Exp SEMI                     { temp = new_node("Stmt", "NULL", $1->line_no, 233);  insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp error SEMI                      { printf("Error type B at Line %d: Missing semicolon ';'\n",$1->line_no); FAIL = 1; }
   |  RETURN Exp error SEMI               { printf("Error type B at Line %d: Missing semicolon ';'\n",$1->line_no); FAIL = 1; }
   |  IF LP Exp RP Stmt %prec THEN        { temp = new_node("Stmt", "NULL", $1->line_no, 233);  insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); insert_node(temp, $4); insert_node(temp, $5); $$ = temp; }
   |  IF LP Exp RP Stmt ELSE Stmt         { temp = new_node("Stmt", "NULL", $1->line_no, 233);  insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); insert_node(temp, $4); insert_node(temp, $5); insert_node(temp, $6); insert_node(temp, $7); $$ = temp; }
   |  WHILE LP Exp RP Stmt                { temp = new_node("Stmt", "NULL", $1->line_no, 233);  insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); insert_node(temp, $4); insert_node(temp, $5); $$ = temp; }
   /*
   |  RETURN ERR SEMI                     { FAIL = 1;}
   |  WHILE LP ERR RP Stmt                { FAIL = 1;}
   |  WHILE LP error                      { FAIL = 1;}
   */
   ;
DefList:
      Def DefList                         { temp = new_node("DefList",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); $$ = temp; }
   |  %empty                              { temp = new_node("NULL", "NULL", 0, 0); $$ = temp; }
   ;
Def:
      Specifier DecList SEMI              { temp = new_node("Def", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Specifier DecList error SEMI        { printf("Error type B at Line %d: Missing semicolon ';'\n", $2->line_no); FAIL = 1; }
   |  error DecList SEMI                  { printf("Error type B at Line %d: Missing specifier\n", $2->line_no); FAIL = 1; }
   |  error FunDec CompSt                 { printf("Error type B at Line %d: Missing specifier\n", $2->line_no); FAIL = 1; }
   ;
DecList:
      Dec                                 { temp = new_node("DecList", "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   |  Dec COMMA DecList                   { temp = new_node("DecList",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   ;
Dec:
      VarDec                              { temp = new_node("Dec", "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   |  VarDec ASSIGN Exp                   { temp = new_node("Dec", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  VarDec ASSIGN ERR                   { FAIL = 1;}
   ;
Exp:
      Exp ASSIGN Exp                      { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp ERR Exp                         { FAIL = 1;}
   |  Exp ASSIGN ERR                      { FAIL = 1;}
   |  Exp AND Exp                         { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp OR Exp                          { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp LT Exp                          { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp LE Exp                          { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp GT Exp                          { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp GE Exp                          { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp NE Exp                          { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp EQ Exp                          { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp PLUS Exp                        { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp MINUS Exp %prec SUB             { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp MUL Exp                         { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp DIV Exp                         { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  LP Exp RP                           { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  LP Exp error RP                     { printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no); FAIL = 1;}
   |  SUB Exp %prec MINUS                 { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); $$ = temp; }
   |  ID LP Args error SEMI               { unput(';'); printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no); FAIL = 1;}
   |  NOT Exp                             { temp = new_node("Exp",  "NULL", $1->line_no, 233);  insert_node(temp, $1); insert_node(temp, $2); $$ = temp; }
   |  ID LP Args RP                       { temp = new_node("Exp",  "NULL", $1->line_no, 233);  insert_node(temp, $1); insert_node(temp, $2);  insert_node(temp, $3); insert_node(temp, $4); $$ = temp;  }
   |  ID LP RP                            { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp LB Exp RB                       { temp = new_node("Exp",  "NULL", $1->line_no, 233);  insert_node(temp, $1); insert_node(temp, $2);  insert_node(temp, $3); insert_node(temp, $4); $$ = temp;  }
   |  Exp DOT ID                          { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  ID                                  { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   |  INT                                 { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   |  FLOAT                               { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   |  CHAR                                { temp = new_node("Exp",  "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   |  ID LP error RP                      { printf("Error type B at Line %d: Missing closing parenthesis ')'\n", $1->line_no); FAIL = 1; }
   ;
Args:
      Exp COMMA Args                      { temp = new_node("Args", "NULL", $1->line_no, 233); insert_node(temp, $1); insert_node(temp, $2); insert_node(temp, $3); $$ = temp; }
   |  Exp                                 { temp = new_node("Args", "NULL", $1->line_no, 233); insert_node(temp, $1); $$ = temp; }
   ;

%%

void show_node(Node* node, int num) {
   if (node->type == 0)
       return;
   for(int i = 0; i < num; ++i)
       printf("  ");

   if (!strcmp(node->type_name, "TYPE"))
       printf("TYPE: %s\n", node->name);
   else if (!strcmp(node->type_name, "ID"))
       printf("ID: %s\n", node->name);
   else if(!strcmp(node->type_name, "CHAR")){
       char ans[20];
       strncpy(ans,node->name+1,strlen(node->name)-2);
       ans[strlen(node->name) -2] = '\0';
       printf("%s: '%s'\n",node->type_name, ans);
   }
   else if(!strcmp(node->type_name, "INT") || !strcmp(node->type_name, "FLOAT")){
       printf("%s: %s\n",node->type_name, node->name);
   }
   else if(node->type >= 258 && node->type <= 293)
       printf("%s\n",node->type_name);
   else
       printf("%s (%d)\n", node->name, node->line_no);

   return;
}

void show(Node* root, int depth) {
   if (root->type == 0)
       return;
   show_node(root, depth);
   if(root->child_no == 0) return;
   Node *temp = root->child;
   for(int i = 0; i < root->child_no; ++i) {
      show(temp, depth + 1);
      temp = temp->dummy_head;
   }
   return;
}

int main(int argc, char** argv) {
    FILE* fin=NULL;
    extern FILE* yyin;

    fin=fopen(argv[1],"r");

    if(fin==NULL){
        printf("open file failed.\n");
        return -1;
    }

    yyin=fin;
    yydebug = 1;
    yyparse();
    fclose(fin);
    if (!FAIL)
        show(temp, 0);

    return 0;
}