/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: concurso.h
 */

#include <iostream>
#include "../clave/clave.h"
#include "../pregunta/pregunta.h"
#include "../instante/instante.h"
#include "../cmt/cmt.h"
#include "../ronda/ronda.h"


#ifndef CONCURSO_H
#define CONCURSO_H

using namespace std;

struct concurso;

void crearConcurso(int PMax, int FMax, int numGmax, concurso& c);
int maximoPasesPermitidos(concurso& c);
int maximoFallosPermitidos(concurso& c);
int maximoNumeroGanadores(concurso& c);
bool enDocumentacion(concurso& c);
bool enInscripcion(concurso& c);
bool enJuego(concurso& c);
int anadirPregunta(concurso& c, int clave, pregunta p);
int borrarPregunta(concurso& c, int clave);
int totalPreguntas(concurso& c);
bool existePregunta(concurso& c, int clave);
bool obtenerPregunta(concurso& c, int clave, pregunta& p);
int preguntaUtilizada(concurso& c, int clave);
int obtenerUltimoUsoPregunta(concurso& c, int clave, instante& t);
bool marcarPregunta(concurso& c, int clave, instante t);
bool iniciarInscripcion(concurso& c);
int anadirConcursante(concurso& c, string IDconcursante, participante p);
int borrarConcursante(concurso& c, string IDconcursante);
bool existeConcursante(concurso& c, string IDconcursante);
bool obtenerInfoConcursante(concurso& c, string IDconcursante, participante p);
int totalConcursantes(concurso& c);
bool iniciarJuego(concurso c);
bool existeConcursanteActual(concurso& c);
int obtenerConcursanteActual(concurso& c, string& concursante);
bool hayGanadores(concurso c);
int probarConcursanteActual(concurso& c, int clave, instante t, int respuesta);
string listarPreguntas(concurso& c);
string listarConcursantes(concurso& c);
string listarConcurso(concurso& c);

struct concurso{
	friend void crearConcurso(int PMax, int FMax, int numGmax, concurso& c);
	friend int maximoPasesPermitidos(concurso& c);
	friend int maximoFallosPermitidos(concurso& c);
	friend int maximoNumeroGanadores(concurso& c);
	friend bool enDocumentacion(concurso& c);
	friend bool enInscripcion(concurso& c);
	friend bool enJuego(concurso& c);
	friend int anadirPregunta(concurso& c, int clave, pregunta p);
	friend int borrarPregunta(concurso& c, int clave);
	friend int totalPreguntas(concurso& c);
	friend bool existePregunta(concurso& c, int clave);
	friend bool obtenerPregunta(concurso& c, int clave, pregunta& p);
	friend int preguntaUtilizada(concurso& c, int clave);
	friend int obtenerUltimoUsoPregunta(concurso& c, int clave, instante& t);
	friend bool marcarPregunta(concurso& c, int clave, instante t);
	friend bool iniciarInscripcion(concurso& c);
	friend int anadirConcursante(concurso& c, string IDconcursante, participante p);
	friend int borrarConcursante(concurso& c, string IDconcursante);
	friend bool existeConcursante(concurso& c, string IDconcursante);
	friend bool obtenerInfoConcursante(concurso& c, string IDconcursante, participante p);
	friend int totalConcursantes(concurso& c);
	friend bool iniciarJuego(concurso c);
	friend bool existeConcursanteActual(concurso& c);
	friend int obtenerConcursanteActual(concurso& c, string& concursante);
	friend bool hayGanadores(concurso c);
	friend int probarConcursanteActual(concurso& c, int clave, instante t, int respuesta);
	friend string listarPreguntas(concurso& c);
	friend string listarConcursantes(concurso& c);
	friend string listarConcurso(concurso& c);

	private:
		int maximoPases;
		int maximoFallos;
		int maximoNumGanadores;
		bool enDoc;
		bool enInsc;
		bool enJ;
		ronda<T1,T2> ronda;
		cmt<T1,T2,T3> cmt;
};

void crearConcurso(int PMax, int FMax, int numGmax, concurso& c){
	c.maximoPases = PMax;
	c.maximoFallos = FMax;
	c.maximoNumGanadores = numGmax;
	c.enDoc = true;
	c.enInsc = false;
	c.enJ = false;
}

int maximoPasesPermitidos(concurso& c){
	return c.maximoPases;
}

int maximoFallosPermitidos(concurso& c){
	return c.maximoFallos;
}

int maximoNumeroGanadores(concurso& c){
	return c.maximoNumGanadores;
}

bool enDocumentacion(concurso& c){
	return c.enDoc;
}

bool enInscripcion(concurso& c){
	return c.enInsc;
}

bool enJuego(concurso& c){
	return c.enJ;
}

int anadirPregunta(concurso& c, int clave, pregunta p){
	return annadir(c.ronda,clave,pregunta);
}

int borrarPregunta(concurso& c, int clave){
	return quitar(c.ronda, clave);
}

int totalPreguntas(concurso& c){
	return cardinal(c.ronda);
}

bool existePregunta(concurso& c, int clave){
	return pertenece(c.ronda, clave);
}

bool obtenerPregunta(concurso& c, int clave, pregunta& p){
	return obtenerValor(c.ronda, clave, p);
}

int preguntaUtilizada(concurso& c, int clave){

}

int obtenerUltimoUsoPregunta(concurso& c, int clave, instante& t){

}

bool marcarPregunta(concurso& c, int clave, instante t){

}

bool iniciarInscripcion(concurso& c){

}

int anadirConcursante(concurso& c, string IDconcursante, participante p){

}

int borrarConcursante(concurso& c, string IDconcursante){

}

bool existeConcursante(concurso& c, string IDconcursante){

}

bool obtenerInfoConcursante(concurso& c, string IDconcursante, participante p){

}

int totalConcursantes(concurso& c){

}

bool iniciarJuego(concurso c){

}

bool existeConcursanteActual(concurso& c){

}

int obtenerConcursanteActual(concurso& c, string& concursante){

}

bool hayGanadores(concurso c){

}

int probarConcursanteActual(concurso& c, int clave, instante t, int respuesta){

}

string listarPreguntas(concurso& c){

}

string listarConcursantes(concurso& c){

}

string listarConcurso(concurso& c){

}

#endif
