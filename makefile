# Practica 2 de EDA
# Pablo Orduna
# Daniel Naval
# Fichero: makefile

CC = g++

main: cmt/cmt.h concurso/concurso.h ronda/ronda.h clave/clave.h instante/instante.h pregunta/pregunta.h practica2.cpp alias.o participante.o 
	$(CC) cmt/cmt.h concurso/concurso.h ronda/ronda.h clave/clave.h instante/instante.h \
		pregunta/pregunta.h alias.o participante.o practica2.cpp -g -std=c++11 -o main
	
alias.o: alias/alias.h alias/alias.cc
	$(CC) alias/alias.h alias/alias.cc -g -c -std=c++11

participante.o: participante/participante.h participante/participante.cc
	$(CC) participante/participante.h participante/participante.cc -g -c -std=c++11

clean: 
	rm *.o
	rm */*.gch
	rm main
