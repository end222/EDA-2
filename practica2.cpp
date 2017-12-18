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
#include "concurso/concurso.h"
#include "instante/instante.h"
#include "pregunta/pregunta.h"

#include <iostream>
#include <fstream>
#include <string>

int convertir(char* cadena);
void separar(int& horas, int& minutos, char* tiempo);

string mostrarTiempo(char* tiempo){
	string mostrar;
	int horas;
	int minutos;
	separar(horas, minutos, tiempo);
	mostrar = to_string(horas) + ":";
	if(minutos != 0){
		mostrar = mostrar + to_string(minutos);
	}
	else{
		mostrar = mostrar + "0";
	}
	return mostrar;
}

void separar(int& horas, int& minutos, char* tiempo){
	char horasStr[10];
	horasStr[0] = tiempo[0];
	horasStr[1] = tiempo[1];
	horasStr[2] = '\0';

	char minutosStr[10];
	minutosStr[0] = tiempo[3];
	minutosStr[1] = tiempo[4];
	minutosStr[2] = '\0';

	horas = convertir(horasStr);
	minutos = convertir(minutosStr);
}

int convertir(char* cadena){
  	int i = 0;
  	int numero = 0;
  	while(cadena[i]!='\0'){
    		numero = numero * 10 + cadena[i] - '0';
    		i++;
  	}
  	return numero;
}

/*
 * Insertar o actualizar pregunta en la coleccion
 */

void ip(ifstream& entrada, ofstream& salida, concurso& c){
	char argumento[5][1000];
	pregunta question;
	int i = 0;
	
	/*
	 * argumento[0]: Clave de la pregunta
	 * argumento[1]: Texto con el que se formula la pregunta
	 * argumento[2]: Primera solucion
	 * argumento[3]: Segunda solucion
	 * argumento[4]: Solucion correcta
	 */

	while(i < 5){
		entrada.getline(argumento[i],100);
		i++;
	}

	/*
	 * Codigo de error utilizado en la funcion introducir en concurso.h
	 * 0: no existia una pregunta con la clave de la que se quiere introducir en la coleccion
	 * 1: si que existia
	 * 2: se descarta la insercion
	 */	

	crearPregunta(question, argumento[1], argumento[2], argumento[3], convertir(argumento[4]));
	switch(anadirPregunta(c, convertir(argumento[0]), question))
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
	salida << argumento[0] << ":::-" << endl;
	salida << generaCadena(question) << flush; 
}

/*
 * Muestra la info de una pregunta con la clave que se pasa en el fichero de entrada, si existe
 */

void lp(ifstream& entrada, ofstream& salida, concurso& c){
	char argumento[1000];
	entrada.getline(argumento,1000);
	switch(existePregunta(c, convertir(argumento)))
	{
		case false:
			salida << "PREGUNTA NO encontrada: " << argumento << endl;
			break;
		case true:
			salida << "PREGUNTA ENCONTRADA: " << flush;
			// Info de la pregunta
			break;
	}
}

/*
 * Borra la pregunta con la clave que se pasa en el fichero de entrada, si es posible
 */

void bp(ifstream& entrada, ofstream& salida, concurso& c){
	char argumento[1000];
	entrada.getline(argumento,1000);
	
	/*
	 * Codigo utilizado en la funcion borrar en concurso.h
	 * 0: la pregunta a borrar se encuentra en la coleccion 
	 * 1: la pregunta a borrar no se encuentra en la coleccion
	 * 2: no se puede borrar debido al estado del concurso
	 */

	switch(borrarPregunta(c, convertir(argumento)))
	{
		case 0:
			salida << "PREGUNTA BORRADA: " << convertir(argumento) << endl;
			break;
		case 1:
			salida << "BORRADO DESCARTADO: " << convertir(argumento) << endl;
			break;
		case 2:
			salida << "BORRADO pregunta NO POSIBLE: " << convertir(argumento) << endl;
	}
}

/*
 * Listar
 */

void lc(ifstream& entrada, ofstream& salida, concurso& c){
	salida << listarPreguntas(c) << endl;
}

/*
 * Poner marca de tiempo a una pregunta con la clave mandada por el archivo de entrada
 */

void mp(ifstream& entrada, ofstream& salida, concurso& c){
	char argumento[2][1000];
	entrada.getline(argumento[0],1000);
	entrada.getline(argumento[1],1000);
	/*
	 * argumento[0]: clave
	 * argumento[1]: marca de tiempo en formato hh:mm
	 */

	instante t;
	int horas;
	int minutos;


	separar(horas, minutos, argumento[1]);
	crearInstante(t, horas, minutos);

	/*
	 * Codigo utilizado en la funcion marcarTiempo en concurso.h
	 * false: la pregunta a marcar se encuentra en la coleccion 
	 * true: la pregunta a marcar no se encuentra en la coleccion
	 */

	switch(marcarPregunta(c, convertir(argumento[0]),t))
	{
		case false:
			salida << "PREGUNTA MARCADA: " << convertir(argumento[0]) << ";" << argumento[1] << endl;
			break;
		case true:
			salida << "MARCA DESCARTADA: " << convertir(argumento[0]) << endl;
			break;
	}

}

void ipa(ifstream& entrada, ofstream& salida, concurso& c){
	char argumento[2][1000];
	entrada.getline(argumento[0],1000);
	entrada.getline(argumento[1],1000);

	/*
	 * argumento[0]: alias
	 * argumento[1]: datos del participante
	 */
	
	participante p;
	crearParticipante(p, argumento[1]);

	/*
	 * Codigo utilizado en la funcion marcarTiempo en concurso.h
	 * 0: No existia el participante 
	 * 1: ya existia el participante
	 * 2: no es posible introducir al participante
	 */

	switch(anadirConcursante(c, argumento[0], p))
	{
		case 0:
			salida << "participante INSCRITO: " << flush;
			break;
		case 1:
			salida << "participante ACTUALIZADO: " << flush;
			break;
		case 2:
			salida << "inscripcion CERRADA: " << flush;
			break;
	}
	salida << argumento[0] << ";" << generaCadena(p) << endl;
}

void bpa(ifstream& entrada, ofstream& salida, concurso& c){
	char argumento[1000];
	entrada.getline(argumento,1000);

	/*
	 * argumento: alias
	 */
	
	/*
	 * Codigo utilizado en la funcion marcarTiempo en concurso.h
	 * 0: ya existia el participante
	 * 1: No existia el participante 
	 * 2: no es posible borrar al participante
	 */

	switch(borrarConcursante(c, argumento))
	{
		case 0:
			salida << "participante BORRADO: " << argumento << endl;
			break;
		case 1:
			salida << "participante NO ENCONTRADO: " << argumento << endl;
			break;
		case 2:
			salida << "BORRADO participante DESCARTADO: " << argumento << endl;
			break;
	}
	// Falta la info del participante
}

void mpa(ifstream& entrada, ofstream& salida, concurso& c){
	char argumento[1000];
	entrada.getline(argumento,1000);
	participante p;

	/*
	 * argumento: alias
	 */
	
	/*
	 * Codigo utilizado en la funcion marcarTiempo en concurso.h
	 * true: No existia el participante 
	 * false: ya existia el participante
	 */

	switch(obtenerInfoConcursante(c, argumento, p))
	{
		case true:
			salida << "participante DESCONOCIDO: " << argumento << endl;
			break;
		case false:
			salida << "participante ENCONTRADO: " << endl;
			break;
			// Falta la info del participante
	}
}

void oc(ifstream& entrada, ofstream& salida, concurso& c){
	/*
	 * Codigo utilizado en la funcion marcarTiempo en concurso.h
	 * 0: existe un candidato
	 * 1: la ronda esta vacia
	 * 2: consulta descartada por el estado de la ronda
	 */

	string p;

	switch(obtenerConcursanteActual(c, p))
	{
		case 0:
			salida << "CANDIDATO a evaluar: " << endl;
			break;
		case 1:
			salida << "ronda VACIA: " << endl;
			break;
		case 2:
			salida << "CONSULTA candidato DESCARTADA: " << endl;
			break;
	}
	// Falta la info del participante
}

void lr(ifstream& entrada, ofstream& salida, concurso& c){
	salida << listarConcursantes << endl;
}

void ii(ifstream& entrada, ofstream& salida, concurso& c){
	
	/*
	 * Codigo utilizado en la funcion marcarTiempo en concurso.h
	 * false: se puede pasar a inscripcion
	 * true: no se puede pasar a inscripcion
	 */

	switch(iniciarInscripcion(c))
	{
		case true:
			salida << "INSCRIPCION CANCELADA" << endl;
			break;
		case false:
			salida << "INSCRIPCION ABIERTA" << endl;
			break;
	}
}

void ij(ifstream& entrada, ofstream& salida, concurso& c){
	
	/*
	 * Codigo utilizado en la funcion marcarTiempo en concurso.h
	 * false: se puede pasar a fase de juego
	 * true: no se puede pasar a fase de juego
	 */

	switch(iniciarJuego(c))
	{
		case true:
			salida << "NO ES POSIBLE iniciar JUEGO" << endl;
			break;
		case false:
			salida << "INICIANDO JUEGO: " << totalConcursantes(c)  << endl;
			break;
	}
}

void pca(ifstream& entrada, ofstream& salida, concurso& c){

	/*
	 * Argumentos:
	 * argumento[0]: clave de la pregunta
	 * argumento[1]: tiempo
	 * argumento[2]: respuesta
	 */

	char argumento[3][1000];
	int i = 0;

	while(i < 3){
		entrada.getline(argumento[i],1000);
		i++;
	}

	instante tiempo;
	int horas;
	int minutos;

	separar(horas, minutos, argumento[1]);

	crearInstante(tiempo, horas, minutos);

	/*
	 * Codigo utilizado en concurso.h
	 * 0: puede responder
	 * 1: no esta en la fase adecuada
	 * 2: ronda vacia
	 * 3: la clave de la pregunta no esta en el concurso
	 * 4: ninguno de los anteriores
	 */
	
	participante p;
        string concurs;
        obtenerConcursanteActual(c, concurs);
        obtenerInfoConcursante(c,concurs,p);
	pregunta question;
	obtenerPregunta(c,convertir(argumento[0]),question);
	string mostrar = mostrarTiempo(argumento[1]);

	instante ultimo;
	int error = obtenerUltimoUsoPregunta(c, convertir(argumento[0]), ultimo);
	if(esMayor(tiempo,ultimo) ||  error == 1){
		marcarPregunta(c, convertir(argumento[0]), tiempo);
	}
	switch(probarConcursanteActual(c, convertir(argumento[0]), tiempo, convertir(argumento[2])))
	{
		case 0:
			salida << "+++ RESPONDE CONCURSANTE +++" << endl;
			salida << "CONCURSANTE: " << concurs << ";" << generaCadena(p) << endl;
			
			salida << "PREGUNTA: " << generaCadena(question) << flush;
			salida << "RESPUESTA DADA: " << argumento[2] << " TIEMPO: " << mostrar << endl;
			if(fallos(p)+1 == maximoFallosPermitidos(c) && convertir(argumento[2]) != 0 && convertir(argumento[2]) != correcta(question)){
				salida << "CONCURSANTE ELIMINADO" << endl;
			}
			salida << "+++++++++++" << endl;
			break;
		case 1:
			salida << "PROBAR concursante DESCARTADO" << endl;
			break;
		case 2:
			salida << "ronda VACIA" << endl;
			break;
		case 3:
			salida << "PREGUNTA no encontrada: " << convertir(argumento[0]) << endl;
			break;
		case 4:
			salida << "RESPUESTA NO VALIDA" << endl;
			break;
	}
}

void hg(ifstream& entrada, ofstream& salida, concurso& c){
	/*
	 * Codigo utilizado en la funcion marcarTiempo en concurso.h
	 * false: no hay ganadores
	 * true: hay ganadores
	 */

	switch(hayGanadores(c))
	{
		case true:
			salida << "<<< CONCURSANTES GANADORES >>>" << endl;
			salida << listarConcursantes(c) << flush;
			break;
		case false:
			salida << "SIN GANADORES"  << endl;
			break;
	}
}

void lt(ifstream& entrada, ofstream& salida, concurso& c){
	salida << listarConcurso(c) << endl;
}

void menu(){
  	char orden[100];
  	string salidaStr = "concursosalida.txt";
  	concurso c;
  	crearConcurso(2,2,1,c);
  	ifstream f;
  	ifstream preguntas;
  	ofstream salida(salidaStr);
  	string entrada = "concursoentrada.txt";
  	f.open(entrada);
  	while(!f.eof()){
		f.getline(orden,100);
    		if(strcmp(orden,"ipa")==0){
        		ipa(f,salida,c);
    		}
    		else if(strcmp(orden,"bpa")==0){
        		bpa(f,salida,c);
    		}
    		else if(strcmp(orden,"mpa")==0){
        		mpa(f,salida,c);
    		}
    		else if(strcmp(orden,"ip")==0){
        		ip(f,salida,c);
 		}
    		else if(strcmp(orden,"oc")==0){
 			oc(f,salida,c);
		}
		else if(strcmp(orden,"lp")==0){
			lp(f,salida,c);
		}
		else if(strcmp(orden,"bp")==0){
			bp(f,salida,c);
		}
		else if(strcmp(orden,"lc")==0){
			lc(f,salida,c);
		}
		else if(strcmp(orden,"mp")==0){
			mp(f,salida,c);
		}
		else if(strcmp(orden,"lr")==0){
			lr(f,salida,c);
		}
		else if(strcmp(orden,"ii")==0){
			ii(f,salida,c);
		}
		else if(strcmp(orden,"ij")==0){
			ij(f,salida,c);
		}
		else if(strcmp(orden,"pca")==0){
			pca(f,salida,c);
		}
		else if(strcmp(orden,"hg")==0){
			hg(f,salida,c);
		}
		else if(strcmp(orden,"lt")==0){
			lt(f,salida,c);
		}
	}
}

int main(){
	menu();
	return 0;
}
