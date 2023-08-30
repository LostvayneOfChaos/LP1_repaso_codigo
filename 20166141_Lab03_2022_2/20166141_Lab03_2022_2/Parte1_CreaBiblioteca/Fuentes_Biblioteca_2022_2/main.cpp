/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 29 de agosto de 2023, 04:45 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "sobrecargas.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    StMedico medico;
    StPaciente paciente;
    StCita cita;
    ifstream in,in2,in3;
    bool result,result2;
    int dni;
    
    AperturaDeUnArchivoDeTextosParaLeer(in,"MedicosLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(in2,"PacientesLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(in3,"ConsultasLab3.txt");
    
    result=in>>medico;
    
    cout<<medico.codigo;
    cout<<medico.especialidad;
    cout<<medico.nombre;
    cout<<medico.tarifaPoxConsulta;
    
    
    result2=in2>>paciente;
    
    cout<<endl;
    cout<<paciente.dni;
    cout<<paciente.nombre;
    cout<<paciente.telefono;
    
    cout<<endl;
    
    dni=in3>>cita;
    
    cout<<dni<<endl;
    cout<<cita.fecha<<endl;
    cout<<cita.codigoDelMedico<<endl;
    
    
    //busqueda
    StMedico medicos[100];
    
    while(true) {
        
        
        
        
    }

    
    
    
    
    return 0;
}

