/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: participante.h
 */

#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include <string>
#include <cstring>

using namespace std;

struct participante;

string generaCadena(participante& p);
void crearParticipante(participante& p,string datos);
void sumarAcierto(participante& p);
void sumarFallo(participante& p);
void sumarIntento(participante& p);
int aciertos(participante& p);
int fallos(participante& p);
int intentos(participante& p);

struct participante{
  friend string generaCadena(participante& p);
  friend void crearParticipante(participante& p,string datos);
  friend void sumarAcierto(participante& p);
  friend void sumarFallo(participante& p);
  friend void sumarIntento(participante& p);
  friend int aciertos(participante& p);
  friend int fallos(participante& p);
  friend int intentos(participante& p);
  private:
    string datos;
    int aciertos;
    int fallos;
    int intentos;
};

#endif
