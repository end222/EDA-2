/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: cmt.h
 */

#include <iostream>
#include <string>
#include <queue>
#include "../clave/clave.h"
#include "../instante/instante.h"
#include "../pregunta/pregunta.h"
#ifndef CMT_H
#define CMT_H
using namespace std;

template <typename T1, typename T2, typename T3> struct terna;
template <typename T1, typename T2, typename T3> struct cmt;
template <typename T1, typename T2, typename T3> struct Nodo;
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

template <typename T1, typename T2, typename T3>  struct Nodo{
	terna<T1, T2, T3> dato;
	Nodo* izq;
	Nodo* der;
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
	Nodo<T1, T2, T3>* abb;
	Nodo<T1, T2, T3>* iterador;
	int numElementos;
	queue <terna<T1, T2, T3>* > l;
};

template <typename T1, typename T2, typename T3>
void crear(cmt<T1,T2,T3>& c){
	c=nullptr;
	c.numElementos=0;
}

template <typename T1, typename T2, typename T3>
bool esVacio(cmt<T1,T2,T3>& c){
	return c==nullptr;	
}
template <typename T1, typename T2, typename T3>
bool existe_aux (Nodo<T1,T2,T3>* entrada, Nodo<T1,T2,T3>& salida, const T1& clave){
	if (entrada==nullptr){
		return true;
	}
	else{
		if (clave<entrada->dato.k){
			return existe_aux(entrada->izq,salida,clave);	
		}
		else if (clave>entrada->dato.k){
			return existe_aux(entrada->der,salida,clave);	
		}
		else if (clave==entrada->dato.k){
			salida=entrada;
			return true;
		}
	}
}

template <typename T1, typename T2, typename T3>
bool existeClave(cmt<T1, T2, T3>& c, T1& k){
	Nodo<T1,T2,T3>* aux; 
	return (c.abb,aux,k);
}

template <typename T1, typename T2, typename T3>
void introducir_aux (Nodo<T1,T2,T3>* entrada, Nodo<T1,T2,T3>& salida){
	
}

template <typename T1, typename T2, typename T3>
void introducir(cmt<T1, T2, T3>& c, T1& k, T2& v){
	introducir_aux(c->abb);
}
template <typename T1, typename T2, typename T3>
void inOrden(Nodo<T1,T2,T3>* entrada, queue <terna<T1,T2,T3>* > l){
	bool error;
	Nodo<T1,T2,T3>* ai;
	Nodo<T1,T2,T3>* ad;
	if (entrada!=nullptr){
		ai=entrada->izq;
		inOrden(entrada,l);
		l.push(entrada->dato);
		ad=entrada->der;
		inOrden(entrada,l);
		
	}
}

template <typename T1, typename T2, typename T3>
void iniciarIterador(cmt<T1, T2, T3>& c){
	inOrden(c,c.l);
	c.iterador=c.l.pop();
}

template <typename T1, typename T2, typename T3>
bool siguiente(cmt<T1, T2, T3>& c, T1& k, T2& v, T3& t){
	k=c.iterador->dato.k;
	v=c.iterador->dato.v;
	if (c.iterador->dato.hayTiempo){
		t=c.iterador->dato.t;
	}
	if (existeSiguiente(c){
		c.iterador=c.l.pop();
	} 
}

template <typename T1, typename T2, typename T3> 
bool existeSiguiente(cmt<T1, T2, T3>& c){
	return (c.l.size()>0);
}

	
#endif  // fin de cmt
