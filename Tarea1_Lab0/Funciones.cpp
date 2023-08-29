/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Funciones.h"
#define MAXLEN 100 
using namespace std;

void imprimirCadena(ofstream& arch, const char* cadena){
    bool repetido = false;
    int nCaracteresImpresos = 0;
    
    for(int i=0; i<50; i++){
        if(cadena[i] == '\0')
            break;
        // Si el caracter es el espacio y ya hay un espacio repetido
        //  no hacer nada
        // Si el caracter es el espacio y no hay repetido, imprimirlo
        //  y cambiar la bandera repetido
        if(not(cadena[i] == ' ' and repetido)){      
            if(cadena[i] == ' ' and not repetido)
                repetido = true;
            if(cadena[i] != ' ' and repetido)
                repetido = false;
            arch << cadena[i];
            nCaracteresImpresos++;
        }
    }
    // Imprimir los espacios con los caracteres que sobran.
    for(int i=nCaracteresImpresos; i<40; i++) arch << ' ';
}

void modificaTitulo(char*titulo){
    
    
    int inicio=0,cont=0;
    char letra;
    for (int i = 0; i < strlen(titulo); i++) {
        if (titulo[i] != ' ') {
            cont=0;
            if(inicio!=0){
                titulo[i]=tolower(titulo[i]);
            }
            else{
                titulo[i]=toupper(titulo[i]);
            }
            inicio++;
            
        }
        else { //si estoy en espacio
            inicio=1; //asummo minuscula
            if(cont>0){
                inicio=0;
                cont=0;
            }
            else{
                inicio=1;
                cont++;
            }
            
        }
        letra=titulo[i];
    }
}
void lectura_impresion(ifstream &in,ofstream &out){
    //QV96140,EL  DUQUE EN SU TERRITORIO,fiorella florencio polo,12,37.47
    char codigo[10],titulo[100],nombre1[100],nombre2[20],nombre3[20],extra;
    int cantidad,numLibros=0;
    double precio,valor=0;
    out<<"Reporte de datos "<<endl;
    while (true) {
        in.getline(codigo,MAXLEN,',');
        if(in.eof()) break;
        in.getline(titulo,MAXLEN,',');
        modificaTitulo(titulo);
        in.getline(nombre1,MAXLEN,',');
        /*in.getline(nombre1,MAXLEN,' ');
        nombre1[0]=toupper(nombre1[0]);
        //in.ignore(MAXLEN,' ')
        in.getline(nombre2,MAXLEN,' ');
        nombre2[0]=toupper(nombre2[0]);
        in.getline(nombre3,MAXLEN,',');
        nombre3[0]=toupper(nombre3[0]);*/
        
        in>>cantidad;
        extra=in.get();
        in>>precio;
        extra=in.get();
        numLibros+=cantidad;
        valor+=(cantidad*precio);
        
        
        //imprimir reporte
        
        
        out<<left;
        out<<setw(10)<<codigo;
        out<<setw(40)<<titulo;
        out<<setw(10)<<' ';
        /*
        cout<<setw(10)<<nombre1;
        cout<<setfill(' ');
        cout<<setw(10)<<nombre2;
        cout<<setfill(' ');
        cout<<setw(10)<<nombre3;
        cout<<setfill(' ');*/
        imprimirCadena(out,nombre1);
        out<<setw(10)<<cantidad;
        out<<setfill(' ');
        out<<setw(10)<<precio;
        out<<endl;
        
    }

}