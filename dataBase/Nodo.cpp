/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: jhonny
 * 
 * Created on 1 de abril de 2020, 03:24 PM
 */

#include "Nodo.h"
#include "columna.h"

Nodo::Nodo() {
    siguiente = NULL;
}

Nodo::Nodo(columna c) {
    column = c;
    siguiente = NULL;
}


Nodo::Nodo(int data) {
    valorInt = data;
    siguiente = NULL;
    left = NULL;
    right = NULL;
    dad = NULL;
    NivelIzq = 0;
    NivelDer = 0;
    valueCompare=data;
}

Nodo::Nodo(string data) {
    valorString = data;
    siguiente = NULL;
    left = NULL;
    right = NULL;
    dad = NULL;
    NivelIzq = 0;
    NivelDer = 0;
}

Nodo::Nodo(char data) {
    valorChar = data;
    siguiente = NULL;
    left = NULL;
    right = NULL;
    dad = NULL;
    NivelIzq = 0;
    NivelDer = 0;
}

Nodo::Nodo(double data) {
    valorDouble = data;
    siguiente = NULL;
    left = NULL;
    right = NULL;
    dad = NULL;
    NivelIzq = 0;
    NivelDer = 0;
}

int Nodo::getValueOfInt() {
    return valorInt;
}