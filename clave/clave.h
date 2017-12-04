/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: clave.h
 */

#include <string>
#ifndef CLAVE_H
#define CLAVE_H

using namespace std;

bool mayorClave(int& c1,int& c2);
string generaCadena(int& c);

bool mayorClave(int& c1,int& c2){
  return (c1 > c2);
}

string generaCadena(int& c){
  string s = to_string(c);
  return s;
}

#endif
