CC=gcc-7

parser:
	bison -d -v  parser.y
	lex lex.l
	gcc -o parser parser.tab.c lex.yy.c -ll -ly
#test



clean:
	rm -f parser
	rm -f *.output
	rm -f *.tab*
	rm -f *.yy.c
	rm -f *.o
