#include <iostream>
#include <iomanip>

#ifndef COLA_H
#define COLA_H
using namespace std;

template <typename Elemento> struct Cola;
template <typename Elemento> void vacia(Cola<Elemento>& c);
template <typename Elemento> void encolar(Cola<Elemento>& c, const Elemento& dato); 
template <typename Elemento> void desencolar(Cola<Elemento>& c);
template <typename Elemento> void primero(const Cola<Elemento>& c, Elemento& dato, bool& error); 
template <typename Elemento> bool esVacia(const Cola<Elemento>& c);
template <typename Elemento> int longitud(const Cola<Elemento>& c);
//template <typename Elemento> void duplicar(const Cola<Elemento>& cOrigen,Cola<Elemento>& cDestino);
//template <typename Elemento> bool operator== (const Cola<Elemento>& c1, const Cola<Elemento>& c2); template <typename Elemento> void liberar(Cola<Elemento>& c);
//template <typename Elemento> void iniciarIterador(Cola<Elemento>& c); template <typename Elemento> bool haySiguiente(const Cola<Elemento>& c);
//template <typename Elemento> bool siguiente(Cola<Elemento>& c, Elemento& dato);

// Declaración
template <typename Elemento> struct Cola{
	
friend void vacia<Elemento>(Cola<Elemento>& c);
friend void encolar<Elemento>(Cola<Elemento>& c, const Elemento& dato); 
friend void desencolar<Elemento>(Cola<Elemento>& c);
friend void primero<Elemento>(const Cola<Elemento>& c, Elemento& dato, bool& error); 
friend bool esVacia<Elemento>(const Cola<Elemento>& c);
friend int longitud<Elemento>(const Cola<Elemento>& c);
//friend void duplicar<Elemento>(const Cola<Elemento>& cOrigen, Cola<Elemento>& cDestino); 
//friend bool operator==<Elemento> (const Cola<Elemento>& c1, const Cola<Elemento>& c2);
//friend void liberar<Elemento>(Cola<Elemento>& c);
//friend void iniciarIterador<Elemento>(Cola<Elemento>& c); 
//friend bool haySiguiente<Elemento>(const Cola<Elemento>& c);
//friend bool siguiente<Elemento>(Cola<Elemento>& c, Elemento& dato);

// Representación de los valores del TAD
private:
struct Nodo{
	Elemento valor; 
	Nodo* siguiente;
	};
	
	Nodo* elPrimero; 
	Nodo* elUltimo; 
	int numDatos; 
	Nodo* iter;
};
// Implementación de las operaciones
template<typename Elemento> 
void vacia(Cola<Elemento>& c) { 
	c.numDatos = 0;
	c.elPrimero = nullptr; 
	c.elUltimo = nullptr;
}
template <typename Elemento> 
void encolar(Cola<Elemento>& c, const Elemento& dato){
	if (c.numDatos==0){
		c.elUltimo = new typename Cola<Elemento>::Nodo;
		c.elPrimero=c.elUltimo;
	}
	else{
	c.elUltimo->siguiente=new typename Cola<Elemento>::Nodo;
	c.elUltimo=c.elUltimo->siguiente;
	}
	c.elUltimo->=dato=dato;
	c.elPrimero
}
// etc etc implementación de las demás operaciones
#endif
