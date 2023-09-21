/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "PunterosGenericos.h"
#define INCREMENTO 5

using namespace std;

enum registroProducto{CODIGO,DESCRIPCION,PRECIO,CANTIDAD};
enum registroCliente{DNICLIENTE,NOMBRECLIENTE,PRODUCTOCLIENTE};
enum registroPedido{CODIGOPEDIDO,DESCRIPCIONPEDIDO,CANTIDADPEDIDO,
DNI,FECHA,ESTADO};
enum registroPedidoCliente{CODIGOPEDIDOCLIENTE,DESCRIPCIONPEDIDOCLIENTE,
CANTIDADPEDIDOCLIENTE,FECHAPEDIDOCLIENTE};

char* leerCadena(ifstream & inProductos){
    
    char cadena[100];
    char *nombre;
    inProductos.getline(cadena,100,',');
    nombre=new char[strlen(cadena)+1];
    strcpy(nombre,cadena);
    
    return nombre;
    
}
char* leerCadenaClientes(ifstream & inProductos){
    
    char cadena[100];
    char *nombre;
    inProductos.getline(cadena,100,'\n');
    nombre=new char[strlen(cadena)+1];
    strcpy(nombre,cadena);
    
    return nombre;
    
}



void* leerRegistroProductos(ifstream &inProductos){
    void **registroProducto;
    int*codigo,*cantidad;
    double* precio;
    char*descripcion,aux;
    
    //Código,Descripción, precio, cantidad
    //459032,GELATINA DANY LIMON 125GR,5.38,24
    
    codigo=new int;
    inProductos>>*codigo>>aux;
    if(inProductos.eof()) return nullptr;
    descripcion=leerCadena(inProductos);
    precio=new double;
    cantidad=new int;
    inProductos>>*precio>>aux>>*cantidad;
    inProductos.get();
    registroProducto=new void*[4];
    registroProducto[CODIGO]=codigo;
    registroProducto[DESCRIPCION]=descripcion;
    registroProducto[PRECIO]=precio;
    registroProducto[CANTIDAD]=cantidad;
    
    return registroProducto;
    
    
    
}

void incrementarProductos(void ** &registroProductos,
        int &nDatos,int &capacidad){
    
    capacidad+=INCREMENTO;
    void **aux;
    if (registroProductos==nullptr) {
        
        registroProductos=new void*[capacidad]{};
        nDatos=1;
        
        
    }
    else {
        aux=new void*[capacidad]{};
        
        for (int i = 0; i < nDatos; i++) {
            aux[i]=registroProductos[i];
        }
        delete registroProductos;
        registroProductos=aux;
        
        
    }

    
}






void cargaproductos( void *&productos){
    
    ifstream inProductos("productos2.csv",ios::in);
    if (!inProductos) {
        cout<<"error al abrir el archivo ";
        exit (1);
    }
    void *bufferProductos[500]{},*registro,**registroProductos;
    productos=nullptr;
    registroProductos=nullptr;
    int nDatos=0;
    
    while (true) {
        registro=leerRegistroProductos(inProductos);
        if (inProductos.eof()) break;
        
        bufferProductos[nDatos]=registro;
        
        nDatos++;
    }
    
    bufferProductos[nDatos]=nullptr;
    nDatos++;
    
    registroProductos=new void*[nDatos];
    
    for (int i = 0; i < nDatos; i++) {
        registroProductos[i]=bufferProductos[i];
    }
    
    
    productos=registroProductos;
    
    inProductos.close();
}

void* leerRegistroPedidos(ifstream & inPedidos){
    
    void **registroPedido;
    int*codigo,*cantidad,*dni,*fecha;
    char*descripcion,aux,*estado;
    
    //675770,JARABE DE MAMEY 1.25KG,5,17913944,20/10/2019
    //Código,Descripción,cantidad solicitada,DNI del cliente,Fecha del pedido
    int dia,mes,anio;
    codigo=new int;
    inPedidos>>*codigo>>aux;
    if(inPedidos.eof()) return nullptr;
    descripcion=leerCadena(inPedidos);
    dni=new int;
    cantidad=new int;
    fecha=new int;
    inPedidos>>*cantidad>>aux>>*dni>>aux>>dia>>aux>>mes>>aux>>anio;
    inPedidos.get();
    (*fecha)=anio*1000+mes*100+dia;
    registroPedido=new void*[6];
    registroPedido[CODIGOPEDIDO]=codigo;
    registroPedido[DESCRIPCIONPEDIDO]=descripcion;
    registroPedido[DNI]=dni;
    registroPedido[CANTIDADPEDIDO]=cantidad;
    registroPedido[FECHA]=fecha;
    estado=new char[2];
    estado[0]='N';
    estado[1]=0;
    registroPedido[ESTADO]=estado;
    
    
    return registroPedido;
    
}

void incrementarPedidos(void ** &registroPedidos,
        int &nDatos,int &capacidad){
    
    
    capacidad+=INCREMENTO;
    void **aux;
    if (registroPedidos==nullptr) {
        
        registroPedidos=new void*[capacidad]{};
        nDatos=1;
        
        
    }
    else {
        aux=new void*[capacidad]{};
        
        for (int i = 0; i < nDatos; i++) {
            aux[i]=registroPedidos[i];
        }
        delete registroPedidos;
        registroPedidos=aux;
        
        
    }
    
    
    
}



void cargapedidos(void *&pedidos){
    
    
    ifstream inPedidos("pedidos2.csv",ios::in);
    if (!inPedidos) {
        cout<<"error al abrir el archivo ";
        exit (1);
    }
    void *bufferPedidos[500]{},*registro,**registroPedidos;
    pedidos=nullptr;
    registroPedidos=nullptr;
    int nDatos=0,capacidad=0;
    
    while (true) {
        registro=leerRegistroPedidos(inPedidos);
        if (inPedidos.eof()) break;
        
        
        bufferPedidos[nDatos]=registro;
        nDatos++;
    }
    bufferPedidos[nDatos]=nullptr;
    nDatos++;
    
    registroPedidos=new void*[nDatos];
    
    for (int i = 0; i < nDatos; i++) {
        registroPedidos[i]=bufferPedidos[i];
    }
    
    pedidos=registroPedidos;
    
    inPedidos.close();
    
}

void imprimirProducto(ofstream &outProductos,void *&producto){
    
    void **registroProducto,*registro;
    registroProducto=(void**)producto;
    int*codigo,*cantidad;
    double* precio;
    char*descripcion,aux;
    codigo=(int*)registroProducto[CODIGO];
    descripcion=(char*)registroProducto[DESCRIPCION];
    precio=(double*)registroProducto[PRECIO];
    cantidad=(int*)registroProducto[CANTIDAD];
    
    
    outProductos<<*codigo
            <<"  "<<descripcion
            <<"  "<<*precio<<"  "<<
            *cantidad<<endl;
    
    
    
}


void imprimeProductos(void *&productos){
    
    ofstream outProductos("productos.txt",ios::out);
    if (!outProductos) {
        cout<<"error al abrir el archivo ";
        exit (1);
    }
    void **registroProductos,*registro;
    registroProductos=(void**)productos;
    
    for (int i = 0; registroProductos[i]; i++) {
        imprimirProducto(outProductos,registroProductos[i]);
    }
    
    outProductos.close();
    
    
    
}

void imprimirPedido(ofstream &outPedidos,void *&pedido){
    
    void **registroPedido,*registro;
    registroPedido=(void**)pedido;
    
    int*codigo,*cantidad,*dni,*fecha;
    char*descripcion,aux,*estado;
    
    codigo=(int*)registroPedido[CODIGOPEDIDO];
    descripcion=(char*)registroPedido[DESCRIPCIONPEDIDO];
    dni=(int*)registroPedido[DNI];
    cantidad=(int*)registroPedido[CANTIDADPEDIDO];
    fecha=(int*)registroPedido[FECHA];
    estado=(char*)registroPedido[ESTADO];
    
    
    outPedidos<<*codigo
            <<"  "<<descripcion
            <<"  "<<*dni<<"  "<<
            *cantidad<<"  "<<
            *fecha<<"  "<<
            estado<<endl;
    
    
    
}





void imprimePedidos(void *&pedidos){
    
    ofstream outPedidos("pedidos.txt",ios::out);
    if (!outPedidos) {
        cout<<"error al abrir el archivo ";
        exit (1);
    }
    void **registroPedidos,*registro;
    registroPedidos=(void**)pedidos;
    
    for (int i = 0; registroPedidos[i]; i++) {
        imprimirPedido(outPedidos,registroPedidos[i]);
    }
    
    outPedidos.close();
    
    
    
}





int asignarSuma(void * &producto){
    
    void **registroProducto;
    registroProducto=(void**)producto;
    
    return *(int*)(registroProducto[CANTIDAD]);
    
}


int sonIguales(void * &producto,void * &pedido){
    
    void **registroPedido,**registroProducto;
    registroPedido=(void**)pedido;
    registroProducto=(void**)producto;
    
    int dniProd,dniPed;
    dniProd=*(int*)registroProducto[CODIGO];
    dniPed=*(int*)registroPedido[CODIGOPEDIDO];
    
    /*if((dniProd==874503) &&(dniPed==874503) ){
        cout<<"holi"<<endl;
        cout<<*(int*)registroPedido[DNI]<< "  "<<
                *(int*)registroPedido[CANTIDADPEDIDO]
                << "  "<<
                (char*)registroPedido[DESCRIPCION]<<endl;
    }*/
    if (dniPed==dniProd) {
        
        return 1;
    }
    else return 0;
    
    
    
}

int evaluarCantidad(int suma,void * &pedido){
    
    void **registroPedido;
    registroPedido=(void**)pedido;
    
    int total;    
    total= *(int*)registroPedido[CANTIDADPEDIDO];
    return (total);
    
}

void actualizarAtendido(void * &pedido){
    void **registroPedido;
    registroPedido=(void**)pedido;
    char* estado;
    estado=new char[2];
    estado[0]='A';
    estado[1]=0;
    //delete registroPedido[ESTADO];
    registroPedido[ESTADO]=estado;
    
    
}
void actualizarEstadoPedidos(void * &productos,void * &pedidos){
    
    void **registroPedidos,**registroProductos;
    registroPedidos=(void**)pedidos;
    registroProductos=(void**)productos;
    int suma=0;
        
        
        
        for (int j = 0; registroPedidos[j]; j++) {
            
            
            for (int i = 0;registroProductos[i]; i++){
                
                suma=asignarSuma(registroProductos[i]);
                if (sonIguales(registroProductos[i],registroPedidos[j])) {
                    suma-=evaluarCantidad(suma,registroPedidos[j]);
                    if(suma>=0)
                        actualizarAtendido(registroPedidos[j]);
                    else break;
                } 
            }
            
        }
    
    
}

int BuscarYEvaluarPedidoAtendido(void * &cliente,void *&pedido){
    
    void **registroPedido,**registroCliente;
    registroPedido=(void**)pedido;
    
    
    
    int*codigo,*cantidad,*dni,*fecha;
    char*descripcion,aux,*estado;
    
    codigo=(int*)registroPedido[CODIGOPEDIDO];
    descripcion=(char*)registroPedido[DESCRIPCIONPEDIDO];
    dni=(int*)registroPedido[DNI];
    cantidad=(int*)registroPedido[CANTIDADPEDIDO];
    fecha=(int*)registroPedido[FECHA];
    estado=(char*)registroPedido[ESTADO];
    
    
    registroCliente=(void**)cliente;
    void**valor=(void**)registroPedido[ESTADO];
    void*letra= valor;
    int*dni1=(int*)registroCliente[DNICLIENTE];
    int*dni2=(int*)registroPedido[DNI];
    
    if(((*(char*)letra=='A'))&&
            ((*dni1))==(*dni2))
        return 1;
    
    return 0;
    
}

void incrementarPedidosXCliente(void* &producto,
                int &nPedidosXCliente, int &nCapXCliente){
    
    
    //pedido deberia ser void **
    
    nCapXCliente+=INCREMENTO;
    void **aux;
    void **regProd=(void**)producto;
    if (regProd==nullptr) {
        
        regProd=new void*[nCapXCliente]{};
        nPedidosXCliente=1;
        
        
    }
    else {
        aux=new void*[nCapXCliente]{};
        
        for (int i = 0; i < nPedidosXCliente; i++) {
            aux[i]=regProd[i];
        }
        delete regProd;
        regProd=aux;
        
        
    }
    
    producto=regProd;
    
    
    
    
}

void insertarPedido(void* &posicionPedidoColocar,void* &pedido){
    
    
    void **registroPedido=(void**)pedido;
    void** registroPedidoCliente=new void*[4]{};
    
    registroPedidoCliente[CANTIDADPEDIDOCLIENTE]=registroPedido[CANTIDADPEDIDO];
    registroPedidoCliente[CODIGOPEDIDOCLIENTE]=registroPedido[CODIGOPEDIDO];
    registroPedidoCliente[DESCRIPCIONPEDIDOCLIENTE]=registroPedido[DESCRIPCIONPEDIDO];
    registroPedidoCliente[FECHAPEDIDOCLIENTE]=registroPedido[FECHA];
    
    posicionPedidoColocar=registroPedidoCliente;
    
}
void agregarPedido(void* &cliente,void *&pedido,int &nPedidosXCliente, int &nCapXCliente){
    
    //no usaremos capacidad
    
    
    
    void**registroCliente=(void **) cliente;
    void**registroPedido=(void **) pedido;
    
    //registroCliente{DNICLIENTE,NOMBRECLIENTE,PRODUCTOCLIENTE};
    //registroPedido{CODIGOPEDIDO,DESCRIPCIONPEDIDO,CANTIDADPEDIDO,DNI,FECHA,ESTADO};
    
    
    if(nPedidosXCliente == 0){ 
        void** bufferPedidoCliente=(void**)registroCliente[PRODUCTOCLIENTE];
        bufferPedidoCliente=new void*[500]{};
        registroCliente[PRODUCTOCLIENTE]=bufferPedidoCliente;
        
    }
    
    void**producto=(void**)registroCliente[PRODUCTOCLIENTE];
    insertarPedido(producto[nPedidosXCliente],pedido);
    nPedidosXCliente++;
    
    //insertar null al que le sigue
    
    //insertarPedidoNulo(producto[nPedidosXCliente],nullptr);
    
    
}
void* leerRegistroClientes(ifstream &inClientes,void * &productos,
        void * &pedidos,void * &clientes,int &nPedidos, int &nCap){
    
    int*codigo,*cantidad,*dni,*fecha,pos;
    char*descripcion,aux,*estado,*nombre;
    
    //DNI,Nombre del cliente
    int dia,mes,anio;
    dni=new int;
    inClientes>>*dni>>aux;
    if(inClientes.eof()) return nullptr;
    nombre=leerCadenaClientes(inClientes);
    //crear Cliente
    void **registroCliente,**registroPedido;
    registroCliente=(void**)clientes;
    registroPedido=(void**)pedidos;
    
    registroCliente=new void*[3];
    registroCliente[PRODUCTOCLIENTE]=nullptr;
    registroCliente[NOMBRECLIENTE]=nombre;
    registroCliente[DNICLIENTE]=dni;
    
    //cout<<*dni<<endl;
    //aca falta crear espacio para PRODUCTO CLIENTE con new de acuerdo a nPedidosy
    //capacidad
    return registroCliente;
    
}



void incrementarClientes(void ** &registroClientes,int & nDatos,int  & capacidad){
    
    capacidad+=INCREMENTO;
    void **aux;
    if (registroClientes==nullptr) {
        
        registroClientes=new void*[capacidad]{};
        nDatos=1;
        
        
    }
    else {
        aux=new void*[capacidad]{};
        
        for (int i = 0; i < nDatos; i++) {
            aux[i]=registroClientes[i];
        }
        delete registroClientes;
        registroClientes=aux;
        
        
    }
    
    
}


void colocarFinPedidosClientes(void* &cliente,int& nPedidos){
    
    
    void**registroCliente=(void **) cliente;
    
    //registroCliente{DNICLIENTE,NOMBRECLIENTE,PRODUCTOCLIENTE};
    //registroPedido{CODIGOPEDIDO,DESCRIPCIONPEDIDO,CANTIDADPEDIDO,DNI,FECHA,ESTADO};
    
    if(registroCliente[PRODUCTOCLIENTE]){
        
        void**producto=(void**)registroCliente[PRODUCTOCLIENTE];
    
        //cout<<nPedidos<<producto<<endl;
        producto[nPedidos]=nullptr;
        nPedidos++;
        
    }
    
    
    //insertar null al que le sigue
    
    //insertarPedidoNulo(producto[nPedidosXCliente],nullptr);
    
    
}
void procesaclientes(void * &productos,void * &pedidos,void * &clientes){
    
    ifstream inClientes("clientes2.csv",ios::in);
    if (!inClientes) {
        cout<<"error al abrir el archivo ";
        exit (1);
    }
    void *bufferClientes[500]{},*registro,**registroPedido,**registroClientes;
    registroClientes=nullptr;
    int nDatos=0,capacidad=0;
    int nPedidos[700]{},nCap[700]{};
    //DNI,Nombre del cliente
    actualizarEstadoPedidos(productos,pedidos);
    imprimePedidos(pedidos);
    registroPedido=(void**)pedidos;
    while (true) {
        registro=leerRegistroClientes(inClientes,productos,pedidos,clientes,nPedidos[nDatos-1], nCap[nDatos-1]);
        if (inClientes.eof()) break;
        
        for (int i = 0; registroPedido[i]; i++) {
            if (BuscarYEvaluarPedidoAtendido(registro,registroPedido[i])) {
                agregarPedido(registro,registroPedido[i],nPedidos[nDatos],
                        nCap[nDatos]);
                //cout<<"estoy en "<< i <<" y nDatos"<<nDatos<<"capacidad "<<nCap<<" nPedidos"<< nPedidos[nDatos-1]<<" nCapacidad de pedidos"<< nCap[nDatos-1]<<endl;
            }
        }
        colocarFinPedidosClientes(registro,nPedidos[nDatos]);
        bufferClientes[nDatos]=registro;
        nDatos++;
    }
    
    
    bufferClientes[nDatos]=nullptr;
    nDatos++;
    
    registroClientes=new void*[nDatos];
    
    for (int i = 0; i < nDatos; i++) {
        registroClientes[i]=bufferClientes[i];
    }
    /////////////////////////////////////////////////////faltaaaaaaaaa agregar com otros
    clientes=registroClientes;
    
    inClientes.close();
    
}

void imprimirDetallesPedido(ofstream &out,
        void *&pedido){
    
    void **regPedidoCliente,*registro;
    regPedidoCliente=(void**)pedido;
    
    int*codigo,*cantidad,*fecha;
    char*descripcion,aux;
    
    codigo=(int*)regPedidoCliente[CODIGOPEDIDOCLIENTE];
    descripcion=(char*)regPedidoCliente[DESCRIPCIONPEDIDOCLIENTE];
    cantidad=(int*)regPedidoCliente[CANTIDADPEDIDOCLIENTE];
    fecha=(int*)regPedidoCliente[FECHAPEDIDOCLIENTE];
    
    out<<"  "<<*codigo
            <<"  "<<*fecha
            <<"  "<<descripcion
            <<"  "<<*cantidad<<endl;
    
    
    
}


void imprimirPedidoXCliente
            (ofstream &out,void * & pedido){
    
    void**registroPed=(void**)pedido;
    
    for (int i = 0; registroPed[i]; i++) {
        imprimirDetallesPedido(out,registroPed[i]);
    }
    
    
}

void imprimirCliente(ofstream &out,void *&cliente){
    
    void **registroCliente,*registro;
    registroCliente=(void**)cliente;
    
    int*codigo,*cantidad,*dni,*fecha;
    char*nombre,aux,*estado;
    
    nombre=(char*)registroCliente[NOMBRECLIENTE];
    dni=(int*)registroCliente[DNICLIENTE];
    
    out<<"  "<<nombre
            <<"  "<<*dni<<endl;
    out<<"---------------------------"<<endl;
    
    if(registroCliente[PRODUCTOCLIENTE])
    imprimirPedidoXCliente
            (out,registroCliente[PRODUCTOCLIENTE]);
    else
        out<<" NO hay pedidos "<<endl;
    
    out<<"---------------------------"<<endl;
}

void imprimeclientes(void *&clientes){
    
    ofstream outClientes("clientes.txt",ios::out);
    if (!outClientes) {
        cout<<"error al abrir el archivo ";
        exit (1);
    }
    void **registroClientes,*registro;
    registroClientes=(void**)clientes;
    
    for (int i = 0; registroClientes[i]; i++) {
        //cout<<i<<endl;
        imprimirCliente(outClientes,registroClientes[i]);
    }
    
    outClientes.close();
    
    
    
    
}
