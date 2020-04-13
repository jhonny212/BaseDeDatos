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

Nodo::Nodo() {
    siguiente = NULL;
    encolado = NULL;
    right = NULL;
    left = NULL;
    dad = NULL;
    ;
}

Nodo::~Nodo() {
}

Nodo::Nodo(int data) {
    valorInt = data;
    siguiente = NULL;
    left = NULL;
    right = NULL;
    dad = NULL;
    NivelIzq = 0;
    NivelDer = 0;
    valueToCompare = data;
    typodeSeleccion = 1;
    encolado = NULL;
    nodoSiguiente = NULL;
    nodoPrevio = NULL;

}

Nodo::Nodo(string data) {
    valorString = data;
    siguiente = NULL;
    left = NULL;
    right = NULL;
    dad = NULL;
    NivelIzq = 0;
    NivelDer = 0;
    encolado = NULL;
    char tab2[data.length()];
    strcpy(tab2, data.c_str());
    int indice = 0;
    for (int i = 0; i < data.length(); i++) {
        char car = tab2[i];
        int numcar;
        numcar = int(car);
        indice += numcar;
    }
    valueToCompare = indice;
    typodeSeleccion = 2;
    nodoSiguiente = NULL;
    nodoPrevio = NULL;
}

Nodo::Nodo(char data) {
    valorChar = data;
    siguiente = NULL;
    left = NULL;
    right = NULL;
    dad = NULL;
    NivelIzq = 0;
    NivelDer = 0;
    char car = data;
    int numcar;
    numcar = int(car);
    valueToCompare = numcar;
    typodeSeleccion = 3;
    encolado = NULL;
    nodoSiguiente = NULL;
    nodoPrevio = NULL;
}

Nodo::Nodo(double data) {
    valorDouble = data;
    siguiente = NULL;
    left = NULL;
    right = NULL;
    dad = NULL;
    NivelIzq = 0;
    NivelDer = 0;
    valueToCompare = data;
    typodeSeleccion = 4;
    encolado = NULL;
    nodoSiguiente = NULL;
    nodoPrevio = NULL;
}

int Nodo::getValueOfInt() {
    return valorInt;
}
