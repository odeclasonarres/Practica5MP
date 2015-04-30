/**
@file codificar.cpp
@author Eloy Fajardo Sánchez, Juan Manuel Salcedo Serrano
@brief Funciones para la ocultacion y revelado de mensajes
*/
#include <iostream>
#include <stdio.h>
#include <cstring>
#include "imagen.h"
#include "byte.h"

using namespace std;

bool ocultar (Imagen &img, char mensaje[]){

	int longMensaje = strlen(mensaje);
	int numPixel = img.filas() * img.columnas();

	int mensajePixeles = (longMensaje +1) * 8;

	
	if(mensajePixeles <= numPixel){
		if(mensaje[longMensaje] != '\0'){
			mensaje[longMensaje] = '\0';
		}

		int indiceImagen = 0;
		for (int i=0; i <= longMensaje; i++){
			
			for(int j=7;j >= 0; j--){
				if(get(mensaje[i],j)){
					byte pixelAux = 0;
					pixelAux = img.getPos(indiceImagen);

					on(pixelAux, 0);
					img.setPos(indiceImagen, pixelAux);

					indiceImagen++;
				}else{

					byte pixelAux = 0;
					pixelAux = img.getPos(indiceImagen);

					off(pixelAux, 0);
					img.setPos(indiceImagen, pixelAux);
					
					indiceImagen++;
				}
				
			}
			
		}		
		return true;
	}else{
		return false;
	}
}

bool revelar (Imagen &img, char mensaje[],int MAXTAM){

	unsigned char auxMensaje [MAXTAM];
	int numPixel = img.filas() * img.columnas();
	
	int indBitLetras = 7; //indice por donde empie
	int numLetras = 0;
	bool palabraTermina = false;

	for (int i=0; i < numPixel && numLetras <= MAXTAM && !palabraTermina; i++){ // numLetras <= MAXTAM el ultimo debe ser \0
	
		byte pixelAux = 0;
		pixelAux = img.getPos(i);
		if(get(pixelAux, 0)){
		
			on(auxMensaje[numLetras],indBitLetras);
		}else{
			off(auxMensaje[numLetras],indBitLetras);
		}
		indBitLetras--;

		if(indBitLetras < 0){
			if(auxMensaje[numLetras]=='\0'){
				palabraTermina = true;
			}
			mensaje[numLetras] = auxMensaje[numLetras];
			indBitLetras = 7;
			numLetras++;
		}

	}

	if(!palabraTermina){
		return false;
	}

	return true;
}
