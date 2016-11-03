#Makefile

OBJS =Circular.c  				#Objects var
CC=gcc						#Var to hold the compiler name

all: Circular Generic
	@echo Compilat tot el projecte

Circular: Circular.c
		$(CC) -o circular Circular.c

Generic: Generic.c
		$(CC) -o generic Generic.c


clean:						#allows to remove temp files
	@echo Cleaning executable files...
	rm circular generic
	@echo Clean done

tar:						#Entrada per a generar paquet comprimit
	@echo Starting compresion
	tar cfv compilado.tar *
	@echo Compresion done

