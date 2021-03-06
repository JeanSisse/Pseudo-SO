all: build clean

build: escalonador.o memoria.o processos.o recursos.o main.o
	@echo "Criando executavel...Pronto!"
	@gcc escalonador.o memoria.o processos.o main.o recursos.o -ansi -std=c99 -lcunit -o dispatcher -Wall -g -lm -lpthread -lrt

main.o: source/main.c
	@echo "Compilando..."
	@gcc -c -ansi -Wall -std=c99 source/main.c -lcunit -g -lpthread -lrt

processos.o: source/processos.c
	@gcc -c -ansi -Wall -std=c99 source/processos.c -lcunit -g -lpthread -lrt

memoria.o: source/memoria.c
	@gcc -c -ansi -Wall -std=c99 source/memoria.c -lcunit -g -lpthread -lrt

recursos.o: source/recursos.c
	@gcc -c -ansi -Wall -std=c99 source/recursos.c -lcunit -g -lpthread -lrt

escalonador.o: source/escalonador.c
	@gcc -c -ansi -Wall -std=c99 source/escalonador.c -lcunit -g -lpthread -lrt

#run: dispatcher
#	@./dispatcher input/process.txt

clean:
	@rm *.o