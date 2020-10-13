%{
    #include"lex.yy.c"
    void yyerror(const char*);
%}

%token LC RC LB RB COLON COMMA
%token STRING NUMBER
%token TRUE FALSE VNULL
%%

Json:
      Value
    ;
Value:
      Object
    | Array
    | STRING
    | NUMBER
    | TRUE
    | FALSE
    | VNULL
    ;
Object:
      LC RC
    | LC Members RC
    | LC Members COMMA RC error {puts("extra comma, recovered");}
    | LC Members COMMA error {puts("Comma instead of RC, recovered");}
    | LC Members RC STRING error {puts("Misplace quoted value, recovered");}
    ;
Members:
      Member
    | Member COMMA Members
    | Member COMMA error {puts("extra comma, recovered");}
    ;
Member:
      STRING COLON Value
    | STRING COLON Value Value error {puts("numbers cannot have leading zeros, recovered");}
    | STRING COLON COLON Value error {puts("Double colone, recovered");}
    | STRING COMMA Value error {puts("Expected colon but get comma, recovered");}
    | STRING Value error {puts("Missing colon, recovered");}
    ;
Array:
      LB RB
    | LB Values RB
    | LB Values COMMA RB error {puts("extra comma, recovered");}
    | LB Values RB COMMA error {puts("Comma after the close, recovered");}
    | LB Values error {puts("Missing ']', recovered");}
    | LB Values RB RB error {puts("Double ']', recovered");}
    | LB Values RC error { puts("unmatched right bracket, recovered"); }
    ;
Values:
      Value
    | Value COMMA Values
    | Value COMMA error {puts("extra comma, recovered");}
    | Value COMMA COMMA error {puts("Double extra comma, recovered");}
    | COMMA Values error {puts("Missing value, recovered");}
    ;
%%

void yyerror(const char *s){
    printf("syntax error: ");
}

int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    yyparse();
    return 0;
}
