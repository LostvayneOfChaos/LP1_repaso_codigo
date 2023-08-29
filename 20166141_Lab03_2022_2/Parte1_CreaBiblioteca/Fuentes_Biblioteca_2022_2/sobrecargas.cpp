/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#define MAXLEN 100





void separarCadena(char* cadena,char*nombre,char*especialidad){
    
    char* pos;
    int longitud;
    int total=strlen(cadena);
    pos=strrchr(cadena,'_');
    longitud=pos-cadena+1;
    
    for (int i = 0; i < longitud; i++) {
        nombre[i]=cadena[i];        
    }
    nombre[longitud-1]=0;
    int j=0;
    for (int i = longitud; i < total; i++) {
        especialidad[j]=cadena[i];
        j++;
    }
    especialidad[j]=0;
    
    
    
    
    
    
}
bool operator >> (ifstream & in, StMedico & medico){
    //506117   EDGAR_MUNOZ_VERGEL_Urologia   337.03
    int  codigo;
    char extra;
    char  cadena[100];
    char  nombre[60];
    char  especialidad[50];
    double tarifa;
    
        in>>codigo;
        if(in.eof()) return false;
        in>>ws;
        in.getline(cadena,MAXLEN,' ');
        separarCadena(cadena,nombre,especialidad);
        in>>tarifa;
        extra=in.get();
        
        medico.codigo=codigo;
        strcpy(medico.especialidad,especialidad);
        strcpy(medico.nombre,nombre);
        medico.tarifaPoxConsulta=tarifa;
        
        return  true;
}





bool operator >> (ifstream & in, StPaciente & paciente){
    
    int  dni,telefono;
    char extra;
    char  nombre[60];
    
        in>>dni;
        if(in.eof()) return false;
        in>>ws;
        in.getline(nombre,MAXLEN,' ');
        in>>ws;
        
        in>>telefono;
        extra=in.get();
        
        paciente.dni=dni;
        strcpy(paciente.nombre,nombre);
        paciente.telefono=telefono;
        paciente.numeroDeCitas=0;
        paciente.totalGastado=0;
        //paciente.citas;
        
        return  true;
}




int operator >> (ifstream & in, StCita & cita){
    //43704548 732354 9/09/2022
    int  dni,codigo,fecha;
    int dia,mes,anio;
    char extra;
    
    
        in>>dni;
        if(in.eof()) return false;
        in>>ws;
        in>>codigo;
        in>>ws;
        
        in>>dia;
        if (in.fail()) {
            in.clear();
            extra=in.get();
            in>>mes;
            if (in.fail()) {
                in.clear();
                extra=in.get();
                in>>anio;
            }
        } 

        fecha=anio*10000+mes*100+dia;
        extra=in.get();
        
        
        cita.codigoDelMedico=codigo;
        cita.fecha=fecha;
        
        
        return  dni;
}