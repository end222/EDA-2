/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: pregunta.h
 */

#ifndef PREGUNTA_H
#define PREGUNTA_H
#include <string>

using namespace std;

struct pregunta;

string generaCadena(pregunta& t);

void crearPregunta(pregunta& t, string pregunta1, string respuesta1, string respuesta2, int correcta);

struct pregunta{
  friend string generaCadena(pregunta& t);
  friend void crearPregunta(pregunta& t, string pregunta1, string respuesta1, string respuesta2, int correcta);
  private:
    string pregunta;
    string respuesta1;
    string respuesta2;
    int correcta;
};

string generaCadena(pregunta& t){
  string st = "<*" + t.pregunta + "*>\n" + "<A) " + t.respuesta1 + " ; B) " + t.respuesta2 + " ; OK: " + to_string(t.correcta) + ">\n";
  return st;
}

void crearPregunta(pregunta& t, string pregunta1, string respuesta1, string respuesta2, int correcta){
  t.pregunta = pregunta1;
  t.respuesta1 = respuesta1;
  t.respuesta2 = respuesta2;
  t.correcta = correcta;
}

#endif
