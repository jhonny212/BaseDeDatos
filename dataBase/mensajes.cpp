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
    cout << "¿Que desea hacer?" << endl;
    cout << "1. Ejecutar querys" << endl;
    cout << "2. Reportes" << endl;
    cout << "3. Añadir una columna mas" << endl;
    cout << "4. salir" << endl;
    cin>> x;

}

int mensajes::typeQuery() {
    int x;
    cout << "1. Hacer select" << endl;
    cout << "2. Hacer Insert" << endl;
    cout << "3. Hacer delete" << endl;
    cin>>x;
}



