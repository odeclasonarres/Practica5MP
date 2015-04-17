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

bool ocultar (Imagen *img, char mensaje[]){

	int longMensaje = strlen(mensaje);
	int numPixel = img->filas() * img->columnas();

	int mensajePixeles = (longMensaje +1) * 8;

	
	if(mensajePixeles <= numPixel){
		if(mensaje[longMensaje] != '\0'){
			mensaje[longMensaje] = '\0';
		}

		int indiceImagen = 0;
		for (unsigned int i=0; i<=strlen(mensaje) && indiceImagen < numPixel; i++){
			
			for(int j=7;j >= 0; j--){
				if(get(mensaje[i],j)){
					byte pixelAux = 0;
					pixelAux = img->getPos(indiceImagen);

					on(pixelAux, 0);
					img->setPos(indiceImagen, pixelAux);

					indiceImagen++;
				}else{

					byte pixelAux = 0;
					pixelAux = img->getPos(indiceImagen);

					off(pixelAux, 0);
					img->setPos(indiceImagen, pixelAux);
					
					indiceImagen++;
				}
				
			}
		
			
		}		
		return true;
	}
	return false;
}
