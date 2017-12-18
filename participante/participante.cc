/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: participante.cc
 */

#include "participante.h"
#include <string>
#include <cstring>

using namespace std;

string generaCadena(participante& p){
  string mostrar = "OK: " + to_string(p.aciertos) + "||F: " + to_string(p.fallos) + "||P: " \
  + to_string(p.intentos) + "||D: " + p.datos;
  return mostrar;
}

void crearParticipante(participante& p,string datos){
  p.datos = datos;
  p.intentos = 0;
  p.aciertos = 0;
  p.fallos = 0;
}

void sumarAcierto(participante& p){
  p.aciertos++;
}

void sumarFallo(participante& p){
  p.fallos++;
}

void sumarIntento(participante& p){
  p.intentos++;
}

int aciertos(participante& p){
  return p.aciertos;
}

int fallos(participante& p){
  return p.fallos;
}

int intentos(participante& p){
  return p.intentos;
}
