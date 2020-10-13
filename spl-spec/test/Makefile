CC=gcc
FLEX=flex
BISON=bison

.lex: lex.l
	$(FLEX) lex.l
.syntax: syntax.y
	$(BISON) -t -d -v syntax.y
splc: .lex .syntax
	$(CC) syntax.tab.c -lfl -ly -o splc
	#@chmod +x bin/splc
clean:
	@rm -rf bin/ syntax.tab.* syntax.ouput lex.yy.c

.PHONY: splc