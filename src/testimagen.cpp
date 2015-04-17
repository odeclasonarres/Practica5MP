#include<iostream>
#include<imagen.h>

using namespace std;

int main(){
    Imagen origen;
    Imagen destino(150,200);
	
	// Crear un degradado en la imagen destino
    for (int i=0; i < destino.filas()*destino.columnas(); i++)
		   destino.setPos(i, i%destino.columnas()+20);
	   
	// Guardar la imagen destino en el fichero degradado.pgm
	if (destino.escribirImagen("degradado.pgm")){
		// si todo va bien
		cout << "degradado.pgm guardado correctamente \n";
		cout << "usa: display degradado.pgm para ver el resultado\n";
	} else { // si error
		cerr << "Error guardando la imagen degradado.pgm\n";
		return 1;
	}
	
	// Leer la imagen lena.pgm
	if (!origen.leerImagen("imagenes/lena.pgm")){
		cerr << "error leyendo imagenes/lena.pgm\n";
		return 1;
	}
	
	// Recortar un trozo de la imagen origen
	destino.crear(40,90);
	for (int i=0; i < destino.filas(); i++)
		for (int j=0; j < destino.columnas(); j++)
			destino.set(i, j, origen.get(i+110,j+100));
		
	// Guardar la imagen destino en el fichero trozo.pgm
	if (destino.escribirImagen("trozo.pgm")){
		// si todo va bien
		cout << "trozo.pgm guardado correctamente \n";
		cout << "usa: display trozo.pgm para ver el resultado\n";
	} else { // si error
		cerr << "Error guardando la imagen trozo.pgm\n";
		return 1;
	}	
	
	return 0;
}
