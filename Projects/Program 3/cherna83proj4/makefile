
code: code1.o code2.o code3.o 
	gcc -o code code1.o code2.o code3.o
code1.o: code1.c code.h
	gcc -c code1.c
code2.o: code2.c code.h
	gcc -c code2.c
code3.o: code3.c code.h
	gcc -c code3.c
clean:
	rm code1.o code2.o code3.o code 

