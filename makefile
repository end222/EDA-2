# Practica 2 de EDA
# Pablo Orduna
# Daniel Naval
# Fichero: makefile

CC = gcc

main: cmt.h concurso.h main.cpp
	$(CC) cmt.h concurso.h main.cpp -o main
	
clean: 
	rm main
