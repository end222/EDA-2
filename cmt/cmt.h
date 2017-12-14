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
template <typename T1, typename T2, typename T3> bool introducir(cmt<T1, T2, T3>& c, T1& k, T2& v);

template <typename T1, typename T2, typename T3> bool tieneTiempo(cmt<T1, T2, T3>& c, T1& k);
template <typename T1, typename T2, typename T3> bool obtenerDato(cmt<T1, T2, T3>& c, T1& k, T2& v);
template <typename T1, typename T2, typename T3> int obtenerTiempo(cmt<T1, T2, T3>& c, T1& k, T3& t);
template <typename T1, typename T2, typename T3> bool marcarTiempo(cmt<T1, T2, T3>& c, T1& k, T3& t);
template <typename T1, typename T2, typename T3> int borrar(cmt<T1, T2, T3>& c, T1& k);
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
    friend bool introducir<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k, T2& v);

    friend bool tieneTiempo<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k);
    friend bool obtenerDato<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k, T2& v);
    friend int obtenerTiempo<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k, T3& t);
    friend bool marcarTiempo<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k, T3& t);
    friend int borrar<T1, T2, T3>(cmt<T1, T2, T3>& c, T1& k);
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
bool existe_aux (Nodo<T1,T2,T3>* entrada, Nodo<T1,T2,T3>* salida, const T1& clave){
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
	return (existe_aux(c.abb,aux,k));
}

template <typename T1, typename T2, typename T3>
bool introducir_aux (Nodo<T1,T2,T3>* entrada, T1& k, T2& v){
	if (entrada==nullptr){
		entrada=new typename cmt<T1,T2,T3>::Nodo;
		entrada->dato.k=k;
		entrada->dato.v=v;
		entrada->der=nullptr;
		entrada->izq=nullptr;
		return 0;
	}
	else if (entrada->dato.k==k){
		entrada->dato.v=v;
		return 1;
	}
	else{
		if(k<=entrada->dato.k){
			introducir_aux(entrada->izq);
		}
		else{
			introducir_aux(entrada->der);
		}
	}
}

template <typename T1, typename T2, typename T3>
bool introducir(cmt<T1, T2, T3>& c, T1& k, T2& v){
	bool control;
	if (control=introducir_aux(c.abb,k,v)){
		c.numElementos++;
	}
	return control;
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
bool tieneTiempo(cmt<T1, T2, T3>& c, T1& k){
	Nodo<T1, T2, T3>* testigo;
	existe_aux(c.abb,testigo,k);
	if (testigo->dato.hayTiempo==true){
		return true;
	}
	else{
		return false;
	}
}

template <typename T1, typename T2, typename T3> 
bool obtenerDato(cmt<T1, T2, T3>& c, T1& k, T2& v){
	bool fase;
	Nodo<T1, T2, T3>* testigo;
	fase = existe_aux(c.abb,testigo,k);
	v=testigo->dato;
	return fase;
}

template <typename T1, typename T2, typename T3>
int obtenerTiempo(cmt<T1, T2, T3>& c, T1& k, T3& t){
	bool fase; //0EXISTE LA CLAVE, 1NOEXISTE LA CLAVE
	Nodo<T1, T2, T3>* testigo;
	fase = existe_aux(c.abb,testigo,k);
	if (fase){
		if (testigo->dato.hayTiempo==true){
			t=testigo->dato.t;
			return 0; //Ha ido todo correctamente :)
		}
		else{
			return 1; // La clave no tiene tiempo :(
		}
	}
	else{
		return 2; //La clave no existe :(
	}
}
template <typename T1, typename T2, typename T3> 
bool marcarTiempo(cmt<T1, T2, T3>& c, T1& k, T3& t){
	bool fase; //0EXISTE LA CLAVE, 1NOEXISTE LA CLAVE
	Nodo<T1, T2, T3>* testigo;
	fase = existe_aux(c.abb,testigo,k);
	if (fase){
		testigo->dato.t=t;
		return 0; //Ha ido todo correctamente :)
	}
	
	else{
		return 1; //La clave no existe :(
	}
}
template <typename T1, typename T2, typename T3> 
void max(Nodo<T1,T2,T3>* entrada, T1& clave){
	if (entrada.der==nullptr){
		clave=entrada->dato.k;
	}
	else{
		max(entrada->der,clave);
	}
}
template <typename T1, typename T2, typename T3> 
int borrar_aux (Nodo<T1,T2,T3>* entrada, T1& k){
	Nodo<T1,T2,T3>* aux;
	if (entrada==nullptr){
		if (k<(entrada->dato.k)){
			borrar_aux(entrada->izq,k);
		}
		else if (k>(entrada->dato.k)){
			borrar_aux(entrada->der,k);
		}
		else if (k==(entrada->dato.k)){
			if (entrada->izq==nullptr){
				aux=entrada;
				entrada=entrada->der;
				delete (aux);
				return 0; //Todo correcto
			}
			else{
				entrada->dato.k=max(entrada->izq);
				borrar(entrada->izq,entrada->dato.k);
			}
		}
	
	}
	else{
		return 1; // Problemas al borrar, árbol vacio
	}
}
template <typename T1, typename T2, typename T3> 
int borrar(cmt<T1, T2, T3>& c, T1& k){
	int control;
	if (borrar=borrar_aux(c->abb)==0){
		c.numElementos--;
	}
	return control;
}
template <typename T1, typename T2, typename T3> 
int tamano(cmt<T1, T2, T3>& c){
	return c.numElementos;
}
template <typename T1, typename T2, typename T3> 
string listar(cmt<T1, T2, T3>& c){
	string corcheteA="[";
	string corcheteC="]";
	string dosPuntos=":";
	string escribe;
	T1 clave;
	T2 valor;
	T3 tiempo;
	iniciarIterador(c);
	
	while (existeSiguiente(c)){
		siguiente(c,clave,valor,tiempo);
		if(tieneTiempo(c,clave)){
			escribe=corcheteA+generaCadena(clave)+dosPuntos+dosPuntos+dosPuntos+generaCadena(tiempo)+'\n'+generaCadena(valor)+corcheteC+'\n';
		}
		else{
			escribe=corcheteA+generaCadena(clave)+dosPuntos+dosPuntos+dosPuntos+'-'+'\n'+generaCadena(valor)+corcheteC+'\n';
		}
	}
	return escribe;
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
	if (existeSiguiente(c)){
		c.iterador=c.l.pop();
		return true;
	}
	else{
		return false;
	}
}

template <typename T1, typename T2, typename T3> 
bool existeSiguiente(cmt<T1, T2, T3>& c){
	return (c.l.size()>0);
}

	
#endif  // fin de cmt