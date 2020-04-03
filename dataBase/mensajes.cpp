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

void mensajes::welcome(){
    cout<<"BIENVENIDO A GUATEMALA'S BD"<<endl;
}
int mensajes::opcion(){
    int x;
    cout<<"¿Que desea hacer?"<<endl;
    cout<<"1. Crear base de datos"<<endl;
    cout<<"2. Acceder a una base de datos"<<endl;
    cin>>x;
    return x;
}

string mensajes::nameDatabase(){
    string name;
    cout<<"Ingrese el nombre de la base de datos"<<endl;
    cin>>name;
}



