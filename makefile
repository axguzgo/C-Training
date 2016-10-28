#Makefile

OBJS =Circular.c  				#Objects var
CC=gcc						#Var to hold the compiler name

all: Circular
	@echo Compilat tot el projecte

Circular: Circular.c
		$(CC) -o circular Circular.c


clean:						#allows to remove temp files
	@echo Cleaning executable files...
	rm circular
	@echo Clean done

tar:						#Entrada per a generar paquet comprimit
	@echo Starting compresion
	tar cfv compilado.tar *
	@echo Compresion done

