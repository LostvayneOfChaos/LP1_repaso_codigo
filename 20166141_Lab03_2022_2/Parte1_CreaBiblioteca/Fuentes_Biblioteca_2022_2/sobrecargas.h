/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecargas.h
 * Author: alulab14
 *
 * Created on 29 de agosto de 2023, 04:48 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Estructuras.h"
#include "AperturaDeArchivos.h"

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

void separarCadena(char* cadena,char*nombre,char*especialidad);
bool operator >> (ifstream & in, StMedico & medico);
bool operator >> (ifstream & in, StPaciente & paciente);
int operator >> (ifstream & in, StCita & cita);




#endif /* SOBRECARGAS_H */

