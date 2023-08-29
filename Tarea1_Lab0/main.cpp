/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 29 de agosto de 2023, 11:52 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include "Funciones.h"
using namespace std;

/*
 * 
 *//*Con Libros_Modificado.csv
    2) Imprimir correctamente los libros.
    - Todos los nombres están en mayúsculas. Tienen que transformar a minúsculas los necesarios.
    - Solo se deben conservar en mayúsculas la primera letra y las que originalmente eran mayúsculas. Las podrán reconocer porque hay dos espacios en blanco antes de estas mayúsculas (en lugar de uno).
    Ejemplo:
    ESTÁ:		EL  DUQUE EN SU TERRITORIO (DUQUE tiene dos espacios antes de la D, por lo que la D conserva su mayúscula)
    DEBE ESTAR:	El Duque en su territorio
    3) Imprimir correctamente los autores.
    - Solo hay que imprimir en mayúscula la primera letra de cada nombre o apellido.*/
int main(int argc, char** argv) {
    
    //QV96140,EL  DUQUE EN SU TERRITORIO,fiorella florencio polo,12,37.47
    ifstream in("Libros_Modificado.csv");
    if(!in){
        cout<<"error al abrir el archivo "<<endl;
        exit (1);
    }
    ofstream out("Reporte_Modificado.txt");
    if(!out){
        cout<<"error al abrir el archivo "<<endl;
        exit (1);
    }
    lectura_impresion(in,out);
    
    in.close();
    out.close();
    return 0;
}

