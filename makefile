# Practica 2 de EDA
# Pablo Orduna
# Daniel Naval
# Fichero: makefile

CC = g++

main: cmt/cmt.h concurso/concurso.h ronda/ronda.h main.cpp alias.o participante.o 
	$(CC) cmt/cmt.h concurso/concurso.h ronda/ronda.h alias.o participante.o main.cpp -std=c++11 -o main
	
alias.o: alias/alias.h alias/alias.cc
	$(CC) alias/alias.h alias/alias.cc -c -std=c++11

participante.o: participante/participante.h participante/participante.cc
	$(CC) participante/participante.h participante/participante.cc -c -std=c++11

clean: 
	rm main
	rm *.o
