/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: cmt.h
 */

#include <iostream>
#include <string>
#include "../clave/clave.h"
#include "../instante/instante.h"
#include "../pregunta/pregunta.h"
#ifndef CMT_H
#define CMT_H
using namespace std;

template <typename T1, typename T2, typename T3> struct terna;
template <typename T1, typename T2, typename T3> struct cmt;
// definir operaciones de agrupacion

template <typename T1, typename T2, typename T3> void crear(cmt<T1, T2, T3>& c);
template <typename T1, typename T2, typename T3> bool esVacio(cmt<T1, T2, T3>& c);
template <typename T1, typename T2, typename T3> bool existeClave(cmt<T1, T2, T3>& c, T1& k);
template <typename T1, typename T2, typename T3> void introducir(cmt<T1, T2, T3>& c, T1& k, T2& v);

template <typename T1, typename T2, typename T3> bool tieneTiempo(cmt<T1, T2, T3>& c, T1& k);
template <typename T1, typename T2, typename T3> bool obtenerDato(cmt<T1, T2, T3>& c, T1& k, T2& v);
template <typename T1, typename T2, typename T3> bool obtenerTiempo(cmt<T1, T2, T3>& c, T1& k, T3& t);
template <typename T1, typename T2, typename T3> bool marcarTiempo(cmt<T1, T2, T3>& c, T1& k, T3& t);
template <typename T1, typename T2, typename T3> void borrar(cmt<T1, T2, T3>& c, T1& k);
template <typename T1, typename T2, typename T3> int tamano(cmt<T1, T2, T3>& c);
template <typename T1, typename T2, typename T3> string listar(cmt<T1, T2, T3>& c);
// ITERADORES
template <typename T1, typename T2, typename T3> void iniciarIterador(cmt<T1, T2, T3>& c);
template <typename T1, typename T2, typename T3> bool existeSiguiente(cmt<T1, T2, T3>& c);
template <typename T1, typename T2, typename T3> bool siguiente(cmt<T1, T2, T3>& c, T1& k, T2& v, T3& t);

template <typename T1, typename T2, typename T3> struct terna {
    T1 k;
    T2 v;
    T3 t;
    bool hayTiempo;
};
template <typename T1, typename T2, typename T3> 
struct cmt {
    friend void crear<T1, T2, T3>(cmt<T1, T2, T3>& c);
    friend bool esVacio<T1, T2, T3>(cmt<T1, T2, T3>& c);
    friend bool existeClave<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k);
    friend void introducir<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k, T2& v);

    friend bool tieneTiempo<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k);
    friend bool obtenerDato<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k, T2& v);
    friend bool obtenerTiempo<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k, T3& t);
    friend bool marcarTiempo<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k, T3& t);
    friend void borrar<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k);
    friend int tamano<T1, T2, T3>(cmt<T1, T2, T3>& c);
    friend string listar<T1, T2, T3>(cmt<T1, T2, T3>& c);
    // ITERADORES
    friend void iniciarIterador<T1, T2, T3>(cmt<T1, T2, T3>& c);
    friend bool existeSiguiente<T1, T2, T3>(cmt<T1, T2, T3>& c);
    friend bool siguiente<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k, T2& v, T3& t);

private:
		terna<T1, T2, T3> dato;
		cmt* izq;
		cmt* der;
};



template <typename T1, typename T2, typename T3>
void crear(cmt<T1,T2,T3>& c){
	c=nullptr;
}


template <typename T1, typename T2, typename T3>
bool esVacio(cmt<T1,T2,T3>& c){
	return c==nullptr;
	
}

template <typename T1, typename T2, typename T3>
bool existeClave(cmt<T1, T2, T3>& c, T1& k){
	if (!esVacio(c)){
		if (k<c->dato.k){
			return existeClave(k->izq,k);	
		}
		else if (k>c->dato.k){
			return existeClave(k->der,k);	
		}
		else if (k==c->dato.k){
			return true;
		}
	}
	else{
		return false;
	}
}
template <typename T1, typename T2, typename T3>
void introducir(cmt<T1, T2, T3>& c, T1& k, T2& v){
	if (c==nullptr){
		new typename cmt<T1,T2> aux;
		aux.dato.k=k;
		aux.dato.v=v;
		aux.der=nullptr;
		aux.izq=nullptr;
	}
	else {
		if (k<=aux.)
	}
}
	
#endif  // fin de cmt
