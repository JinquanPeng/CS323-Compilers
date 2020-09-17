%{
    int indicator = 0;
    char *addr_type = NULL;
%}
%option noyywrap
n255 ([0-9]|([1-9][0-9])|(1[0-9]{2})|(2[0-4][0-9])|(25[0-5]))
hexnum ([0-9a-fA-F]{1,4})
v4 ^({n255}\.){3}{n255}$
v6 ^({hexnum}\:){7}{hexnum}$

%%
{v4} { indicator = 4; }
{v6} { indicator = 6; }
<<EOF>> {
    if(indicator == 4)
        addr_type = "IPv4";
    else if(indicator == 6)
        addr_type = "IPv6";
    else
        addr_type = "Neither";
    indicator = 0;
    return 0;
}
\n {}
. {}
%%
char *validIPAddress(char *IP){
    YY_BUFFER_STATE buf;
    buf = yy_scan_string(IP);
    yylex();
    yy_delete_buffer(buf);
    return addr_type;
}
