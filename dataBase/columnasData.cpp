/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   columnasData.cpp
 * Author: jhonny
 * 
 * Created on 1 de abril de 2020, 03:20 PM
 */

#include "columnasData.h"
using namespace std;

columnasData::columnasData() {
    valor = NULL;
    sigu = NULL;
}



void columnasData::add(columna c) {
    if (sigu == NULL) {
        sigu = new Nodo(c);
        valor = sigu;
    } else {
        sigu->siguiente = new Nodo(c);
        sigu = sigu->siguiente;
    }
}

void columnasData::get() {

    if (valor != NULL) {
        columna c = valor->column;
        cout << c.getName() << " " << c.getType() << endl;
        valor = valor->siguiente;
    }
}


