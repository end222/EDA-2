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
void crearParticipante(participante& p,int datos);
void sumarAcierto(participante& p);
void sumarFallo(participante& p);
void sumarIntento(participante& p);

struct participante{
  friend string generaCadena(participante& p);
  friend void crearParticipante(participante& p,string& datos);
  friend void sumarAcierto(participante& p);
  friend void sumarFallo(participante& p);
  friend void sumarIntento(participante& p);
  private:
    string datos;
    int aciertos;
    int fallos;
    int intentos;
};

#endif
