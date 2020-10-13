CC=gcc
FLEX=flex
BISON=bison

.lex: splc.l
	$(FLEX) splc.l
.syntax: splc.y
	$(BISON) -t -d -v splc.y
splc: .lex .syntax
	$(CC) splc.tab.c -lfl -ly -o bin/splc
	#@chmod +x bin/splc
clean:
	@rm -rf bin/* syntax.tab.* syntax.ouput lex.yy.c

.PHONY: splc