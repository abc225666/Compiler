CC=gcc-7

parser:
	bison -d -v  parser.y
	lex lex.l
	${CC} -o parser parser.tab.c lex.yy.c -ll -ly

clean:
	rm -f parser
	rm -f *.output
	rm -f *.tab*
	rm -f *.yy.c
	rm -f *.o
