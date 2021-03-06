/**
@file esteganografia.cpp
@author Eloy Fajardo Sánchez, Juan Manuel Salcedo Serrano
@brief Prueba para la ocultacion y revelado de mensajes
*/
#include<iostream>
#include<cstring>
#include <stdlib.h> 
#include<string>
#include<imagen.h>
#include<codificar.h>
#include<byte.h>

using namespace std;

int main(){
	int op=0, grados=0;
	string strOp = "";
	char sentido;
	bool correcto=false;
	
	string entrada="", salida="";
	Imagen img;
	do{
		do{
			cout << endl;
			cout<<"1.Ocultar"<<endl;
			cout<<"2.Revelar"<<endl;
			cout<<"3.Rotar"<<endl;
			cout<<"4.Salir"<<endl;
			cout<<"Seleccione una opción: ";
			cin>>strOp;
			op = atoi(strOp.c_str());
			
		}while(op!=1 && op!=2 && op!=3 && op!=4);
		
		switch(op){
			case 1:{
				cout<<"Introduzca la imagen de entrada: "; 
				cin>>entrada;
		
				if (!img.leerImagen(entrada.c_str())){
					cerr << "error leyendo " << entrada << endl << endl;
				}else{
					cout<<"Introduzca la imagen de salida: ";
					cin>>salida;
				
					int size=((img.filas() * img.columnas())/8);
					char *mensaje=0;
					mensaje =new char[size];		
	
					cout<<"Introduzca el mensaje: ";
					do{				
						cin.getline(mensaje,size);
					}while(mensaje[0]=='\0');

					if (!ocultar(img, mensaje)){
						cout << "Error: El mensaje es muy largo para ocultarlo en la imagen\n";
					}else{
						cout <<"Ocultando...";
						if (img.escribirImagen(salida.c_str())){
							// si todo va bien
							cout << salida<<" guardado correctamente \n";
							cout << "usa: display "<<salida<<" para ver el resultado\n";
						} else { // si error
							cerr << "Error guardando la imagen";
						}				
					}
					delete []mensaje;
				}
				break;
			}



			case 2:{
				cout<<"Introduzca la imagen de entrada: "; 
				cin>>entrada;
					
				if (!img.leerImagen(entrada.c_str())){
					cerr << "error leyendo " << entrada << endl;
				}else{
					int size=((img.filas() * img.columnas())/8);
					char *mensaje=0;
					mensaje =new char[size];
				
					if (!revelar(img, mensaje, size)){
						cout << "Error: La imagen no contiene un mensaje o el mensaje es demasiado largo\n";
					}else {
						cout << "El mensaje oculto en la imagen es: '" << mensaje << "'\n";
					}	
					delete []mensaje;
				}
				break;
			}

			case 3:{
				cout<<"Introduzca la imagen de entrada: "; 
				cin>>entrada;
		
				if (!img.leerImagen(entrada.c_str())){
					cerr << "error leyendo " << entrada << endl << endl;
				}else{
					cout<<"Introduzca los grados(90,180 o 270) a rotar: ";
					cin>>grados;				
					
					do{
						
						cout<<"¿Quiere rotar siguiendo el sentido horario? s/n ";
						cin>>sentido;
						if(sentido=='s'||sentido=='n'||sentido=='N'||sentido=='S'){
							correcto=true;
						}
					}while(!correcto);
					if(sentido=='s'||sentido=='S'){
						img.rotacion(grados,true);
					}else{
						img.rotacion(grados,false);
					}
					cout <<"rotando..."<<endl;
					if (img.escribirImagen(entrada.c_str())){
						// si todo va bien
						cout << salida<<" guardado correctamente \n";
						cout << "usa: display "<<entrada<<" para ver el resultado\n";
					} else { // si error
						cerr << "Error guardando la imagen";
					}				
					
				}
				break;
			}

			case 4:{
				cout<<"Adios"<<endl;
				break;
			}
		}
	}while(op!=4);
	

}
