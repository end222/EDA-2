/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: instante.h
 */

#ifndef INSTANTE_H
#define INSTANTE_H
#include <string>
#include <cstring>

using namespace std;

struct instante;

string generaCadena(instante& t);

struct instante{
  friend string generaCadena(instante& t);
  friend void crearInstante(instante& t,int horas, int minutos);
  private:
    int horas;
    int minutos;
};

string generaCadena(instante& t){
  string s1 = to_string(t.horas);
  string s2 = to_string(t.minutos);
  string puntos = ":";
  string s = s1 + puntos + s2;
  return s;
}

void crearInstante(instante& t,int horas, int minutos){
  t.horas = horas;
  t.minutos = minutos;
}

#endif
