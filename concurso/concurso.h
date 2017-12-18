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
bool preguntaUtilizada(concurso& c, int clave);
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
	friend bool preguntaUtilizada(concurso& c, int clave);
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
		ronda<string,participante> round;
		cmt<int,pregunta,instante> grupo;
};

void crearConcurso(int PMax, int FMax, int numGmax, concurso& c){
	c.maximoPases = PMax;
	c.maximoFallos = FMax;
	c.maximoNumGanadores = numGmax;
	c.enDoc = true;
	c.enInsc = false;
	c.enJ = false;
	crear(c.round);
	crear(c.grupo);
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
	if(enDocumentacion(c)){
		return introducir(c.grupo,clave,pregunta);
	}
	else{
		return 2;
	}
}

int borrarPregunta(concurso& c, int clave){
	if(enDocumentacion(c)){
		return borrar(c.grupo, clave);
	}
	else{
		return 2;
	}
}

int totalPreguntas(concurso& c){
	return tamano(c.grupo);
}

bool existePregunta(concurso& c, int clave){
	return existeClave(c.grupo, clave);
}

bool obtenerPregunta(concurso& c, int clave, pregunta& p){
	return obtenerDato(c.grupo, clave, p);
}

bool preguntaUtilizada(concurso& c, int clave){
	return tieneTiempo(c.grupo, clave);
}

int obtenerUltimoUsoPregunta(concurso& c, int clave, instante& t){
	/*
	 * 0: correcto
	 * 1: no tiene tiempo
	 * 2: no existe
	 */
	return obtenerTiempo(concurso& c, clave, t);
}

bool marcarPregunta(concurso& c, int clave, instante t){
	return marcarTiempo(c.grupo, clave, t);
}

bool iniciarInscripcion(concurso& c){
	if(!enDocumentacion(c) && totalPreguntas(c)==0){
		c.enDoc = false;
		c.enInsc = true;
		return true;
	else{
		return false;
	}
}

int anadirConcursante(concurso& c, string IDconcursante, participante p){
	return annadir(c.round, IDconcursante, p);
}

int borrarConcursante(concurso& c, string IDconcursante){
	return quitar(c.round, IDconcursante);
}

bool existeConcursante(concurso& c, string IDconcursante){
	return pertenece(c.round, IDconcursante);
}

bool obtenerInfoConcursante(concurso& c, string IDconcursante, participante p){
	return obtenerValor(c.round, IDconcursante, p);
}

int totalConcursantes(concurso& c){
	return cardinal(c.round);
}

bool iniciarJuego(concurso c){
	if(enInscripcion(c) && totalConcursantes(c)>máximoNúmeroGanadores(c)){
		c.enJ = true;
		c.enInsc = false;
		return true;
	}
	else{
		return false;
	}
}

bool existeConcursanteActual(concurso& c){
	if(enjuego(c) && totalConcursantes(c)>0){
		return true;
	}
	else{
		return false;
	}
}

int obtenerConcursanteActual(concurso& c, string& concursante){
	if(enJuego(c)){
		if(totalConcursantes(c)>0){
			obtenerCandidatoSuClave(c.round,concursante);
			return 2; // Se consigue obtener
		else{
			return 1; // No hay concursantes
		}
	}
	else{
		return 0; // No esta en juego
}

bool hayGanadores(concurso c){
	if(enJuego(c) && totalConcursantes(c)<=maximoNumeroGanadores(c)){
		return true;
	}
	else{
		return false;
	}
}

int probarConcursanteActual(concurso& c, int clave, instante t, int respuesta){

}

string listarPreguntas(concurso& c){
	return listar(c.grupo);
}

string listarConcursantes(concurso& c){
	return listar(c.round);
}

string listarConcurso(concurso& c){
	string texto;
	texto = "********** ESTADO del CONCURSO **********\n";
	if(enDoc){
		texto = texto + "FASE: Documentacion\n";
	}
	else if(enInsc){
		texto = texto + "FASE: Inscripcion\n";
	}
	else {
		texto = texto + "FASE: Juego\n";
	}
	texto = texto + "LIMITES maximos-> Pases: " + to_string(c.maximoPases) + " Fallos: " + to_string(c.maximoFallos);
	texto = texto + " Ganadores: " + to_string(c.maximoNumGanadores);
	if(enJ){
		texto = texto + "JUGANDO concursante: ";
		string concursante;
		if(obtenerConcursanteActual(c, concursante)==2){
			texto = texto + concursante;
		}
		else{
			texto = texto + "---";
		}
		texto = texto + "\n";
	}
	texto = texto + listarPreguntas(c);
	texto = texto + listarConcursantes(c);
	texto = texto + "******************************";
	return texto;
}

#endif
