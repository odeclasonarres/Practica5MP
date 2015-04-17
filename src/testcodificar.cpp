#include<iostream>
#include<cstring>
#include<imagen.h>
#include<codificar.h>
#include<byte.h>


using namespace std;

int main(){
	const int MAXTAM = 30;
	char mensaje[MAXTAM];
	Imagen img(4,5);

	// Rellenar la imagen con valores del 0 al 19
	for (int i=0; i < img.filas()*img.columnas(); i++){
		img.setPos(i, i+70);
	}
	
	cout << "La imagen original tiene los siguientes valores\n";
	for (int y=0; y < img.filas(); y++){
		for (int x=0; x < img.columnas(); x++){
			cout << (img.get(y, x)) << " ";
		}
		cout << endl;
	}

	cout << "Los bits menos significativos de los  primeros 16 pixeles de la imagen son\n";
	for (int i=0; i < 16; i++){
		cout << img.getPos(i)%2; // El bit en la posición 0 es el resto de la división entera por 2
	}
	cout << endl;
	
	strcpy(mensaje, "E"); // El mensaje a ocultar
	
	cout << "Voy a ocultar la cadena '" << mensaje << "' y el '\\0' en la imagen\n";
	cout << "La cadena tiene " << (strlen(mensaje)+1)*8 << " bits que son:\n";
	for (int i=0; i<=strlen(mensaje); i++){
		print(mensaje[i]);
	}
	cout << endl;
	
	if (!ocultar(&img, mensaje)){
		cout << "Error: El mensaje es muy largo para ocultarlo en la imagen\n";
		return 1;
	}

	cout << "La imagen después de ocultar tiene los siguientes valores\n";
	for (int y=0; y < img.filas(); y++){
		for (int x=0; x < img.columnas(); x++){
			cout << (char)(img.get(y, x)) << " ";
		}
		cout << endl;
	}
	
	cout << "Los bits menos significativos de los 16 primeros pixeles de la imagen son\n";
	for (int i=0; i < 16; i++){
		cout << img.getPos(i)%2; // El bit en la posición 0 es el resto de la división entera por 2
	}
	cout << "\n y deberían ser:\n";
	print(mensaje[0]); 
	print(mensaje[1]);
	cout << endl;	

	/*
	if (!revelar(img, mensaje, MAXTAM)){
		cout << "Error: La imagen no contiene un mensaje o el mensaje es demasiado largo\n";
		return 1;
	}
	else {
		cout << "El mensaje oculto en la imagen es: '" << mensaje << "'\n";

	}
	
	strcpy(mensaje, "Supercalifragilisticoespialidoso"); // El mensaje a ocultar (demasiado largo para la imagen)
	cout << "Voy a ocultar la cadena '" << mensaje << "' y el '\\0' en la imagen\n";

	if (!ocultar(img, mensaje)){
		cout << "Error: El mensaje es muy largo para ocultarlo en la imagen\n";
		return 1;
	}
	*/
	return 0;
}
