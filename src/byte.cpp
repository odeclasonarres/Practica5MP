/**
@file byte.cpp
@author Eloy Fajardo Sánchez, Juan Manuel Salcedo Serrano
@brief Interfaz de uso de un dato de un byte byte
*/
#include <iostream>
#include <stdio.h>
#include "byte.h"

using namespace std;

void on(byte &b, int pos){
	byte mask = 1; 

	mask = mask << pos; 	//ponemos el 1 en la posicion deseada 0000100
	b =  b | mask;		//ponemos a 1 en b usando un or
}

void off(byte &b, int pos){
	byte mask = 1; 

	mask = mask << pos; 	//ponemos el 1 en la posicion deseada 0000100
	mask = ~mask;		//hacemos un NOT 11111011
	b =  b & mask;		//ponemos a 0 en b segun la mascara anterio
}

bool get(byte b, int pos){
	byte mask = 1;
	byte auxiliar = 0; //donde guardaremos el resultado true (1) o false(0)

	mask = mask << pos;
	auxiliar =  b & mask;
	auxiliar = auxiliar >> pos;

	return (int) auxiliar;

}


void print(byte b){

	for(int i = 7; i >= 0 ;i--){
		if(get(b,i)){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	cout << endl;
}

void encender(byte &b){
  for(int i=7;i>=0;i--){
    on(b,i);
 }
}


void apagar(byte &b){
  for(int i=7;i>=0;i--){
    off(b,i);
  }
}


void asignar(byte &b, const bool v[]){

   for(unsigned int i=0; i<=7;i++){  
    if (v[i]){
      on(b,i);
    }else{
      off(b,i);
    }
  }
}


void volcar(byte b, bool v[]){

	for(int i = 7; i >= 0 ;i--){
		if(get(b,i)){
			v[i] = true;
		}else{
			v[i] = false;
		}
	}
}


void encendidos(byte b, int posic[], int &cuantos){
	cuantos = 0;
	for(int i = 7; i >= 0 ;i--){
		if(get(b,i)){
			posic[cuantos] = i;
			cuantos++;
		}
	}
}


