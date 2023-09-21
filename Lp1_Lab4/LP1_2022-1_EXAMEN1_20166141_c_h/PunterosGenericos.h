/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: alulab14
 *
 * Created on 19 de septiembre de 2023, 02:57 PM
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;



#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H


void cargaproductos( void *&productos);
void incrementarProductos(void ** &registroProductos,
        int &nDatos,int &capacidad);
void* leerRegistroProductos(ifstream &inProductos);
char* leerCadena(ifstream & inProductos);
void cargapedidos(void *&pedidos);
void incrementarPedidos(void ** &registroPedidos,
        int &nDatos,int &capacidad);
void* leerRegistroPedidos(ifstream & inPedidos);

void imprimeProductos(void *&productos);
void imprimirProducto(ofstream &outProductos,void *&producto);
void imprimePedidos(void *&pedidos);
void imprimirPedido(ofstream &outPedidos,void *&pedido);
void procesaclientes(void * &productos,void * &pedidos,void * &clientes);
int asignarSuma(void * &producto);
int sonIguales(void * &producto,void * &pedido);
int evaluarCantidad(int suma,void * &pedido);
void actualizarAtendido(void * &pedido);
void actualizarEstadoPedidos(void * &productos,void * &pedidos);
void incrementarClientes(void ** &registroClientes,int & nDatos,int  & capacidad);
void* leerRegistroClientes(ifstream &inClientes,void * &productos,
        void * &pedidos,void * &clientes,int &nPedidos, int &nCap);
void agregarPedido(void* &cliente,void *&pedido,int &nPedidosXCliente, int &nCapXCliente);
void insertarPedido(void* &posicionPedidoColocar,void* &pedido);
void incrementarPedidosXCliente(void* &producto,
                int &nPedidosXCliente, int &nCapXCliente);
int BuscarYEvaluarPedidoAtendido(void * &cliente,void *&pedido);
char* leerCadenaClientes(ifstream & inProductos);
void imprimeclientes(void *&clientes);
void imprimirCliente(ofstream &out,void *&cliente);
void imprimirPedidoXCliente
            (ofstream &out,void * & pedido);
void imprimirDetallesPedido(ofstream &out,
        void *&pedido);



#endif /* PUNTEROSGENERICOS_H */

