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

void modificaTitulo(char*titulo){
    
    
    int inicio=0,cont=0;
    char letra;
    for (int i = 0; i < strlen(titulo); i++) {
        if (letra != ' ') {
            if(inicio==0){
                titulo[i]=toupper(titulo[i]);
                
            } 
            inicio++;
            
        }
        else {
            inicio=1;
            if(cont!=0){
                inicio=0;
            }
            else inicio=1;
            
        }

          
        
        
        
        
    }

    
    
    
}








void lectura_impresion(ifstream & in,ofstream &out){
    //QV96140,EL  DUQUE EN SU TERRITORIO,fiorella florencio polo,12,37.47
    char codigo[10],titulo[20],nombre[20],extra;
    int cantidad,numLibros=0;
    double precio,valor=0;
    out<<"Reporte de datos "<<endl;
    while (true) {
        in.getline(codigo,MAXLEN,',');
        if(in.eof()) break;
        in.getline(titulo,MAXLEN,',');
        modificaTitulo(titulo);
        in.getline(nombre,MAXLEN,' ');
        nombre[0]=toupper(nombre[0]);
        in.getline(nombre,MAXLEN,' ');
        nombre[0]=toupper(nombre[0]);
        in.getline(nombre,MAXLEN,',');
        nombre[0]=toupper(nombre[0]);
        in>>cantidad;
        extra=in.get();
        in>>precio;
        extra=in.get();
        numLibros+=cantidad;
        valor+=(cantidad*precio);
        //imprimir reporte
        
        cout<<setw(10)<<codigo;
        cout<<left<<setfill(' ');
        cout<<setw(20)<<titulo;
        cout<<setfill(' ');
        cout<<setw(20)<<nombre;
        cout<<right<<setfill(' ');
        cout<<setw(10)<<cantidad;
        cout<<setfill(' ');
        cout<<setw(10)<<precio;
        cout<<endl;
        
    }

}