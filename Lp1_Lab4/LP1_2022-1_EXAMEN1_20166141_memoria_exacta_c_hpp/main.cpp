/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Axel 20166141
 *
 * Created on 19 de septiembre de 2023, 02:53 PM
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "PunterosGenericos.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    void *productos,* pedidos , *clientes;
    
    cargaproductos(productos);
    cargapedidos(pedidos);
    imprimeProductos(productos);
    //imprimePedidos(pedidos);
    procesaclientes(productos,pedidos,clientes);
    imprimeclientes(clientes);
    
    return 0;
}

