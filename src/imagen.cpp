
#include "imagen.h"
#include "pgm.h"
#include <iostream>

using namespace std;

Imagen::Imagen(){
	nfilas = 0;
	ncolumnas = 0;
}

Imagen::Imagen(int filas, int columnas){
	crear(filas, columnas);
}

void Imagen::crear(int filas, int columnas){

	if((filas * columnas) <= MAXPIXELS){
		nfilas =  filas;
		ncolumnas =  columnas;
		for(int i = 0; i < MAXPIXELS; i++){
			datos[i] = 0;
		}
	}else{
		nfilas = 0;
		ncolumnas = 0;
	}
}
   

int Imagen::filas(){
	return nfilas;
}

int Imagen::columnas(){
	return ncolumnas;
}
   

void Imagen::set(int y, int x, byte v){

	if(x >= 0 && y >= 0 && x < ncolumnas && y < nfilas){
		datos[y * ncolumnas + x] = v;
	}
}
   
   
byte Imagen::get(int y, int x){
	
	if(x >= 0 && y >= 0 && x<ncolumnas && y < nfilas){
		
		return datos[ y * ncolumnas + x];
	}else
		return 0;
	
}
   
   
void Imagen::setPos(int i, byte v){
	if(i >= 0 && i < MAXPIXELS){
		datos[i] = v;
	}
}
   
 
byte Imagen::getPos(int i){

	if(i >= 0 && i < MAXPIXELS){
		return datos[i];
	}else{
		return 0;
	}

}

   
bool Imagen::leerImagen(const char nombreFichero[]){

	TipoImagen tipo =  infoPGM(nombreFichero, nfilas, ncolumnas);
	if((nfilas * ncolumnas) > MAXPIXELS){
		return false;
	}else if(tipo ==  IMG_PGM_BINARIO){
		return leerPGMBinario (nombreFichero, datos,nfilas, ncolumnas);
	}
	return false;

}
   

bool Imagen::escribirImagen(const char nombreFichero[]){
	return escribirPGMBinario (nombreFichero, datos, nfilas, ncolumnas);

}

