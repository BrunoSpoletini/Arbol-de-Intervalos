TEMP = itree.o interprete.o intervalo.o
ARG = -Wall -Wextra -Werror -std=c99

all: interprete

interprete: itree.o interprete.o intervalo.o
	gcc $(ARG) -o interprete interprete.o itree.o intervalo.o

itree.o: itree.c itree.h
	gcc $(ARG) -c itree.c 

interprete.o: interprete.c
	gcc $(ARG) -c interprete.c

intervalo.o: intervalo.c intervalo.h
	gcc $(ARG) -c intervalo.c

clean:
	-rm $(TEMP)

.PHONY : all
.PHONY : clean