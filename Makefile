CLFAGS = -Dtest
smartstr:smartstr.o
	gcc -o smartstr smartstr.o

smartstr.o:smartstr.c
	gcc -c ${CLFAGS} -Wall -g -O2 smartstr.c -o smartstr.o

clean:
	@rm -f *.o
	@rm -f tpl
