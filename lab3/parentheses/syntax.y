%{
    #include"lex.yy.c"
    int result=1;
    void yyerror(const char *s){ result = 0;}
%}
%token LP RP LB RB LC RC
%%
/*
String:
   String String
|   LP String RP
|   LB String RB
|   LC String RC
|   %empty
;
*/

Expr : %empty
    | LP Expr RP Expr
    | LB Expr RB Expr
    | LC Expr RC Expr
    ;

%%

int validParentheses(char *expr){
    yy_scan_string(expr);
    yyparse();
    return result;
}
