/*
 * Practica 2 de EDA
 * Pablo Orduna
 * Daniel Naval
 * Fichero: practica2.cpp
 */

#include "ronda/ronda.h"
#include "participante/participante.h"
#include "alias/alias.h"
#include "clave/clave.h"
#include "cmt/cmt.h"
#include "concurso/concurso.h"
#include "instante/instante.h"
#include "ronda/ronda.h"
#include "pregunta/pregunta.h"

#include <iostream>
#include <fstream>
#include <string>

int convertir(char* cadena){
  int i = 0;
  int numero = 0;
  while(cadena[i]!='\0'){
    numero = numero * 10 + cadena[i] - '0';
    i++;
  }
  return numero;
}

void ip(ifstream& entrada, ofstream& salida){
	char argumentos[5][1000];
	pregunta question;
	int i = 0;
	
	/*
	 * argumentos[0]: Clave de la pregunta
	 * argumentos[1]: Texto con el que se formula la pregunta
	 * argumentos[2]: Primera solucion
	 * argumentos[3]: Segunda solucion
	 * argumentos[4]: Solucion correcta
	 */

	while(i < 5){
		entrada.getline(argumentos[i],100);
		i++;
	}

	/*
	 * Codigo de error utilizado en la funcion introducir en cmt.h
	 * 0: no existia una pregunta con la clave de la que se quiere introducir en la coleccion
	 * 1: si que existia
	 * 2: se descarta la insercion
	 */	

	crearPregunta(question, argumentos[1], argumentos[2], argumentos[3], convertir(argumentos[4]));
	switch(introducir(c, convertir(argumentos[0]), question)
	{		
		case 0:
			salida << "INSERCION REALIZADA: " << flush;
			break;
		case 1:
			salida << "ACTUALIZACION REALIZADA: " << flush;
			break;
		case 2:
			salida << "INSERCION DESCARTADA: " << flush;
			break;	
	}
	// Falta mostrar la info de la pregunta
}

void lp(ifstream& entrada, ofstream& salida){
	salida << "lp" << endl;
	char argumento[1000];
	entrada.getline(argumento,1000);
	switch(existeClave(c, convertir(argumento)))
	{
		case false:
			salida << "PREGUNTA NO encontrada: " << flush;
			break;
		case true:
			salida << "PREGUNTA ENCONTRADA: " << flush;
			break;
	}
	// Falta mostrar la info de la pregunta
}

void bp(ifstream& entrada, ofstream& salida){
	salida << "bp" << endl;
}

void lc(ifstream& entrada, ofstream& salida){
	salida << "lc" << endl;
}

void mp(ifstream& entrada, ofstream& salida){
	salida << "mp" << endl;
}

void ipa(ifstream& entrada, ofstream& salida){
	salida << "ipa" << endl;
}

void bpa(ifstream& entrada, ofstream& salida){
	salida << "bpa" << endl;
}

void mpa(ifstream& entrada, ofstream& salida){
	salida << "mpa" << endl;
}

void oc(ifstream& entrada, ofstream& salida){
	salida << "oc" << endl;
}

void lr(ifstream& entrada, ofstream& salida){
	salida << "lr" << endl;
}

void ii(ifstream& entrada, ofstream& salida){
	salida << "ii" << endl;
}

void ij(ifstream& entrada, ofstream& salida){
	salida << "ij" << endl;
}

void pca(ifstream& entrada, ofstream& salida){
	salida << "pca" << endl;
}

void hg(ifstream& entrada, ofstream& salida){
	salida << "hg" << endl;
}

void lt(ifstream& entrada, ofstream& salida){
	salida << "lt" << endl;
}

void menu(){
  	char orden[100];
  	string salidaStr = "concursosalida.txt";
  	ronda<string,participante> r;
  	crear(r);
  	ifstream f;
  	ifstream preguntas;
  	ofstream salida(salidaStr);
  	string entrada = "concursoentrada.txt";
  	f.open(entrada);
  	while(!f.eof()){
		f.getline(orden,100);
    		if(strcmp(orden,"ipa")==0){
        		ipa(f,salida);
    		}
    		else if(strcmp(orden,"bpa")==0){
        		bpa(f,salida);
    		}
    		else if(strcmp(orden,"mpa")==0){
        		mpa(f,salida);
    		}
    		else if(strcmp(orden,"ip")==0){
        		ip(f,salida);
 		}
    		else if(strcmp(orden,"oc")==0){
 			oc(f,salida);
		}
		else if(strcmp(orden,"lp")==0){
			lp(f,salida);
		}
		else if(strcmp(orden,"bp")==0){
			bp(f,salida);
		}
		else if(strcmp(orden,"lc")==0){
			lc(f,salida);
		}
		else if(strcmp(orden,"mp")==0){
			mp(f,salida);
		}
		else if(strcmp(orden,"lr")==0){
			lr(f,salida);
		}
		else if(strcmp(orden,"ii")==0){
			ii(f,salida);
		}
		else if(strcmp(orden,"ij")==0){
			ij(f,salida);
		}
		else if(strcmp(orden,"pca")==0){
			pca(f,salida);
		}
		else if(strcmp(orden,"hg")==0){
			hg(f,salida);
		}
		else if(strcmp(orden,"lt")==0){
			lt(f,salida);
		}
	}
}

int main(){
	menu();
	return 0;
}
