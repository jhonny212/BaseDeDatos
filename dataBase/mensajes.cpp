/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mensajes.cpp
 * Author: jhonny
 * 
 * Created on 1 de abril de 2020, 01:23 PM
 */

#include "mensajes.h"

mensajes::mensajes() {
}

mensajes::mensajes(const mensajes& orig) {
}

mensajes::~mensajes() {
}

void mensajes::welcome() {
    cout << "BIENVENIDO A GUATEMALA'S BD" << endl;
}

int mensajes::opcion() {
    int x;
    cout << "¿Que desea hacer?" << endl;
    cout << "1. Crear base de datos" << endl;
    cout << "2. Acceder a una base de datos" << endl;
    cout << "3. Salir " << endl;
    cin>>x;
    return x;
}

int mensajes::seleccion() {
    int x;
    cout<<" \n \n "<<endl;
    cout << "¿Que desea hacer?" << endl;
    cout << "1. Ejecutar querys" << endl;
    cout << "2. Reportes" << endl;
    cout << "3. Añadir una columna mas a una tabla " << endl;
    cout << "4. Crear una tabla " << endl;
    cout << "5. salir" << endl;
    cin>> x;
    return x;
}

int mensajes::typeQuery() {
    int x;
    cout << "1. Hacer select" << endl;
    cout << "2. Hacer Insert" << endl;
    cin>>x;
    return x;
}

int mensajes::reportes() {
    int x;
    cout << "-------------------REPORTES----------------------" << endl;
    cout << "1. Cantidad de datos En todas las bases de datos" << endl;
    cout << "2. Cantidad de datos (por base de datos)" << endl;
    cout << "3. Cantidad de datos o filas de un mismo tipo de dato en una tabla" << endl;
    cout << "4. Cantidad de todas las columnas de todas las tablas de una base de datos" << endl;
    cout << "5. archivo log de la base de datos" << endl;
    cin>>x;
}



