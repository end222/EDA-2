/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: ronda.h
 */

#include <fstream>
#include <string>
#include <iostream>
#include "../alias/alias.h"
#include "../participante/participante.h"

#ifndef RONDA_H
#define RONDA_H
using namespace std;

const int MAX = 100;

template<typename T1, typename T2> struct ronda;
//definir operaciones de ronda

template<typename T1, typename T2> void crear(ronda<T1,T2>& r);
template<typename T1, typename T2> int cardinal(ronda<T1,T2>& r);
template<typename T1, typename T2> bool esVacio(ronda<T1,T2>& r);
template<typename T1, typename T2> bool pertenece(ronda<T1,T2>& r,T1& c);
template<typename T1, typename T2> bool obtenerValor(ronda<T1,T2>& r,T1& c, T2& v);
template<typename T1, typename T2> bool enSeleccion(ronda<T1,T2>& r);
template<typename T1, typename T2> int annadir(ronda<T1,T2>& r,T1& c,T2& v);
template<typename T1, typename T2> int quitar (ronda<T1,T2>& r,T1& c);
template<typename T1, typename T2> void cerrarInscripcion(ronda<T1,T2>& r);
template<typename T1, typename T2> bool pasarTurno(ronda<T1,T2>& r);
template<typename T1, typename T2> bool obtenerCandidatoSuClave(ronda<T1,T2>& r,T1& c);
template<typename T1, typename T2> bool obtenerCandidatoSuValor(ronda<T1,T2>& r,T2& v);
template<typename T1, typename T2> bool actualizarCandidato(ronda<T1,T2>& r,T2& v);
template<typename T1, typename T2> bool eliminarCandidato(ronda<T1,T2>& r);
template<typename T1, typename T2> string listar(ronda<T1,T2>& r);

//ITERADORES
template<typename T1, typename T2> void iniciarIterador(ronda<T1,T2>& r);
template<typename T1, typename T2> bool existeSiguiente(ronda<T1,T2>& r);
template<typename T1, typename T2> bool siguiente(ronda<T1,T2>& r ,T1& c, T2& v);

template<typename T1, typename T2>
struct ronda{
	
	//Definición de las variables amigas para poder utilizas fuera de la especificación.
    
    friend void crear<T1,T2>(ronda<T1,T2>& r);
    friend int cardinal<T1,T2>(ronda<T1,T2>& r);
    friend bool esVacio<T1,T2>(ronda<T1,T2>& r);
    friend bool pertenece<T1,T2>(ronda<T1,T2>& r,T1& c);
    friend bool obtenerValor<T1,T2>(ronda<T1,T2>& r,T1& c, T2& v);
    friend bool enSeleccion<T1,T2>(ronda<T1,T2>& r);
    friend int annadir<T1,T2>(ronda<T1,T2>& r,T1& c,T2& v);
    friend int quitar<T1,T2>(ronda<T1,T2>& r,T1& c);
    friend void cerrarInscripcion<T1,T2>(ronda<T1,T2>& r);
    friend bool pasarTurno<T1,T2>(ronda<T1,T2>& r);
    friend bool obtenerCandidatoSuClave<T1,T2>(ronda<T1,T2>& r,T1& c);
    friend bool obtenerCandidatoSuValor<T1,T2>(ronda<T1,T2>& r,T2& v);
    friend bool actualizarCandidato<T1,T2>(ronda<T1,T2>& r,T2& v);
    friend bool eliminarCandidato<T1,T2>(ronda<T1,T2>& r);
    friend string listar<T1,T2>(ronda<T1,T2>& r);

    //ITERADORES
    friend void iniciarIterador<T1,T2>(ronda<T1,T2>& r);
    friend bool existeSiguiente<T1,T2>(ronda<T1,T2>& r);
    friend bool siguiente<T1,T2>(ronda<T1,T2>& r ,T1& c, T2& v);

private:

struct Nodo{
  T1 c;
  T2 v;
  Nodo* siguiente;
};

    bool seleccion=0;
    int numDatos;
    Nodo* primero;
    Nodo* iterador;
    Nodo* turno;
    };
	
/* Devuelve una ronda de selección vacía, sin elementos (pares), 
	y en estado de Inscripción.
*/
template<typename T1, typename T2>
void crear(ronda<T1,T2>& r){
    r.primero=nullptr;
    r.numDatos=0;
}
/*Devuelve el nº de elementos (de pares) en la ronda r */

template<typename T1, typename T2>
int cardinal(ronda<T1,T2>& r){
    return r.numDatos;
}

/* Devuelve verdad si y sólo si r no tiene elementos */

template<typename T1, typename T2>
bool esVacio(ronda<T1,T2>& r){
    return r.numDatos==0;
}

/*Devuelve verdad si y sólo si en r hay algún par (c,v)} */
template<typename T1, typename T2>
bool pertenece(ronda<T1,T2>& r,T1& c){
    typename ronda<T1,T2>::Nodo* aux = r.primero;
    bool encontrado=false;
    T1 laClave;
    T2 elValor;
    
    while (!encontrado && aux != nullptr){
	laClave = aux->c;
	elValor = aux->v;
        aux = aux->siguiente;
        if (laClave==c){
            encontrado=true;
        }
    }
    return encontrado;
}

/* Devuelve el valor asociado a la clave c en un par en r. 
 * Parcial: la operación no está definida si c no está en r.
 */
template<typename T1, typename T2>
bool obtenerValor(ronda<T1,T2>& r,T1& c, T2& v){
    typename ronda<T1,T2>::Nodo* aux = r.primero;
    bool encontrado=false;
    T1 laClave;
    T2 elValor;
    
    while (!encontrado && aux != nullptr){
	laClave = aux->c;
	elValor = aux->v;
        aux = aux->siguiente;
        if (laClave==c){
            encontrado=true;
            v=elValor;
        }
    }
    return encontrado;
}
/* Devuelve verdad si y sólo si r está en estado de Selección.*/
template<typename T1, typename T2>
bool enSeleccion(ronda<T1,T2>& r){
    return r.seleccion;
}

/* Si en r no hay ningún par con clave c, devuelve una ronda igual a la resultante de añadir el 
 * par (c,v) a r; si en r hay un par (c,v), entonces devuelve una igual a ronda la resultante de sustituir (c,v’) por el par (c,v) en r.
 * Parcial: la operación no está definida si c no está en r. 
 */
template<typename T1, typename T2>
int annadir(ronda<T1,T2>& r,T1& c,T2& v){
    
    /*
     * Codigo de error utilizado
     * 0: no existia una pregunta con la clave de la que se quiere introducir en la coleccion
     * 1: si que existia
     * 2: se descarta la insercion
     */

    typename ronda<T1,T2>::Nodo* aux;
    typename ronda<T1,T2>::Nodo unaCelda;
    if (r.primero==nullptr){
        r.primero=new typename ronda<T1,T2>::Nodo;
        r.primero->c=c;
        r.primero->v=v;
        r.primero->siguiente=nullptr;
        r.numDatos=1;
	return 0;
    }
    else if(c<(r.primero->c)) {
        aux=r.primero;
        r.primero=new typename ronda<T1,T2>::Nodo;
        r.primero->c=c;
        r.primero->v=v;
        r.primero->siguiente=aux;
        r.numDatos=r.numDatos+1;            
        return 0;
    }  
    else{
        aux=r.primero;
        while((aux->c)<c && aux->siguiente!=nullptr){
            aux=aux->siguiente;
        }
        if(c<aux->c){
            unaCelda.c=c;
            unaCelda.v=v;
	    typename ronda<T1,T2>::Nodo* nuevo= new typename ronda<T1,T2>::Nodo;			
            *nuevo=*aux;
            *aux=unaCelda;
            aux->siguiente=nuevo;
            r.numDatos=r.numDatos+1;        
	    return 0;
        }
        else{
            if(c==aux->c){
                aux->v=v;
	        return 1;
            }
            else{
                aux->siguiente=new typename ronda<T1,T2>::Nodo;
                aux=aux->siguiente;
                aux->c=c;
                aux->v=v;
		aux->siguiente=nullptr;
                r.numDatos=r.numDatos+1;                        
		return 0;
            }
        }
    }
}
/* Si c está en r, devuelve una ronda igual a la resultante de borrar en r el par con clave c si c no está en r devuelve una ronda igual a r.
 * Parcial: la operación no está definida si enSelección?(r).*/
template<typename T1, typename T2>
int quitar(ronda<T1,T2>& r,T1& c){
		typename ronda<T1,T2>::Nodo* aux1;
		typename ronda<T1,T2>::Nodo* aux2;
		bool parar;
		int devolver = 0;
		if (r.primero!=nullptr){
			if((r.primero->c)<=c){
				if ((r.primero->c)==c){
					aux1=r.primero;
					r.primero = r.primero->siguiente;
					delete (aux1);
					r.numDatos=r.numDatos-1;
					devolver = 0;
				}
				else{
					parar=false;
					aux1=r.primero->siguiente;
					aux2=r.primero;
					while(aux1!=nullptr && !parar){
						if(c<aux1->c){
							parar=true;
							devolver = 1;
						}
						else if(c==aux1->c){
							aux2->siguiente=aux1->siguiente;
							delete (aux1);
							parar=true;
							r.numDatos=r.numDatos-1;
							devolver = 0;
						}
						else{
							aux2=aux1;
							aux1=aux1->siguiente;
						}
					}
				}
			}
			else devolver = 1;
		}
	return devolver;
}
/* Si enSelección?(r), devuelve una ronda igual a r si no enSelección?(r), devuelve una ronda igual a la resultante de poner r en estado de Selección y 
además, si no esVacía?(r), fijar el turno en el elemento de menor clave en la ronda r.
*/
template<typename T1, typename T2>
void cerrarInscripcion(ronda<T1,T2>& r){
    r.seleccion=true;
    r.turno=r.primero;
}
/*
 * Si enSelección?(r), devuelve una ronda igual a la resultante de pasar el turno del 
 * elemento que actualmente tenga el turno al que le siga en el orden por clave, y 
 * teniendo en cuenta que si el que tenía el turno era el de mayor clave, el turno deberá pasar al elemento de menor clave en r.
 * Parcial: la operación no está definida si no es verdad enSelección?(r) o si es verdad esVacía?(r).
 */

template<typename T1, typename T2>
bool pasarTurno(ronda<T1,T2>& r){
    if(!esVacio(r)){
        if (r.turno->siguiente!=nullptr){
            T1 clave;
            T2 valor;
            // El nuevo turno será el nodo que apunta a siguiente
            r.turno=r.turno->siguiente;
        }
		else {
			r.turno = r.primero;
		}
		return true;
    }
	else{
		return false;
	}
}

/* Si enSelección?(r), devuelve la clave c del par (c,v) que tiene el turno en la ronda r. 
Parcial: 
la operación no está definida si no es verdad enSelección?(r) o si esVacía?(r).
*/
template<typename T1, typename T2>
bool obtenerCandidatoSuClave(ronda<T1,T2>& r,T1& c){
        if (!esVacio(r)){
           c= r.turno->c;
           return true;
        }
        else{
            return false;
        }
}

/* Si enSelección?(r), devuelve el valor v del par (c,v) que tiene el turno en la ronda r la 
 * operación no está definida si no es verdad enSelección?(r) 
 * o si esVacía?(r).
 * Parcial: la operación no está definida si no es verdad enSelección?(r) o si esVacía?(r).*/
template<typename T1, typename T2>
bool obtenerCandidatoSuValor(ronda<T1,T2>& r,T2& v){
        if(!esVacio(r)){
           v = r.turno->v;
           return true;
        }
        else{
            return false;
        }
}
/* Si enSelección?(r), devuelve una ronda igual a la resultante de actualizar en r el valor del elemento que tiene el turno, actualizándolo 
 * a v la operación no está definida si no es verdad enSelección?(r) o si esVacía?(r). 
 * Parcial: la operación no está definida si no es verdad enSelección?(r) o si esVacía?(r).}
 */
template<typename T1, typename T2>
bool actualizarCandidato(ronda<T1,T2>& r,T2& v){
    if (!esVacio(r)){
        r.turno->v=v;
		return true;
    }
	else{
        return false;
    }
    
}

/* Si enSelección?(r), devuelve una ronda igual a la resultante de eliminar de r el elemento que 
actualmente tenía el turno en r. Además, en el caso de que queden más elementos en la ronda, en 
la  ronda  resultante  deberá  tener  el  turno  el  elemento  que  seguía  en  r  a  aquel  que  tenía  el  
turno  (y  que  ha  sido  eliminado),  teniendo  en  cuenta  que  si  el  que  tenía  el  turno  era  el  de  
mayor clave, el turno deberá pasar al de menor clave de los que queden. 
 * Parcial: la  operación  no  está  definida  si  no  es  verdad  enSelección?(r) o  si  es  verdad esVacía?(r). */
template<typename T1, typename T2>
bool eliminarCandidato(ronda<T1,T2>& r){
        if (!esVacio(r)){
			T1 c = r.turno->c;
			typename ronda<T1,T2>::Nodo* aux1;
			typename ronda<T1,T2>::Nodo* aux2;
			bool parar;
			if (r.primero!=nullptr){
				if((r.primero->c)<=c){
					if ((r.primero->c)==c){
						aux1=r.primero;
						r.primero = r.primero->siguiente;
						delete (aux1);
						r.numDatos=r.numDatos-1;
					}
					else{
						parar=false;
						aux1=r.primero->siguiente;
						aux2=r.primero;
						while(aux1!=nullptr && !parar){
							if(c<aux1->c){
								parar=true;
							}
							else if(c==aux1->c){
								aux2->siguiente=aux1->siguiente;
								delete (aux1);
								parar=true;
								r.numDatos=r.numDatos-1;
							}
							else{
								aux2=aux1;
								aux1=aux1->siguiente;
							}
						}
					}
				}
			}
		pasarTurno(r);
		return true;
		}
		else{
			return false;
		}
}
/*
 * Devuelve una cadena que contiene la representación, como cadenas de caracteres, de todos los 
 * elementos de la ronda r en orden por clave de menor a mayor, separados unos de otros por un salto de línea, y de tal
 * forma que para cada elemento su información se incluya con el formato [k:::v],  es  decir:  un  carácter  ‘[‘, 
 * seguido  de  la  cadena  que  represente  la  clave  k,  a  
 * continuación una cadena “:::”, seguido a continuación de la cadena que represente el valor v, seguido de un carácter ‘]‘, 
 * y seguido a continuación del carácter de salto de línea. 
 * Operaciones de iterador interno, para recorrer los elementos de la ronda de selección, en orden por clave de menor a mayor: 
 * iniciarIterador: ronda r.
 * Prepara el iterador y su cursor para que el siguiente elemento (par) a visitar sea el primero  de la ronda r 
 * (situación de no haber visitado ningún elemento);
 */
template<typename T1, typename T2>
string listar(ronda<T1,T2>& r){
	string corcheteA="[";
	string corcheteC="]";
	string dosPuntos=":";
	string escribe;
	T1 clave;
	T2 valor;
	iniciarIterador(r);
	
	while (existeSiguiente(r)){
		siguiente(r,clave,valor);
		escribe=escribe+corcheteA+generaCadena(clave)+dosPuntos+dosPuntos+dosPuntos+generaCadena(valor)+corcheteC+'\n';
	}
	
	return escribe;
	
	
}

//ITERADORES
/*  Operaciones de iterador interno, para recorrer los elementos de la ronda de selección, en orden por clave de menor a mayor: */
template<typename T1, typename T2>
void iniciarIterador(ronda<T1,T2>& r){
    r.iterador=r.primero;
}
/*
 * Devuelve  falso  si  ya  se  ha  visitado  el  último  elemento de  r,  devuelve  verdad  en  caso contrario 
 */
template<typename T1, typename T2>
bool existeSiguiente(ronda<T1,T2>& r){
	//return !(&(*(r.iterador)->siguiente)==nullptr);
	return r.iterador!=nullptr;
}
template<typename T1, typename T2>
/*
 * Devuelve falso si ya se ha visitado el último elemento de r, devuelve verdad en caso contrario;
 */
bool siguiente(ronda<T1,T2>& r ,T1& c, T2& v){
	if (existeSiguiente(r)){
		c=r.iterador->c;
		v=r.iterador->v;
		r.iterador=r.iterador->siguiente;
		return true;
	}
	 else{
		 return false;
	 }
}

#endif //fin de ronda
