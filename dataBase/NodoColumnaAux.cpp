/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoColumnaAux.cpp
 * Author: jhonny
 * 
 * Created on 11 de abril de 2020, 03:41 PM
 */

#include "NodoColumnaAux.h"

NodoColumnaAux::NodoColumnaAux() {
    siguiente = NULL;
}

NodoColumnaAux::NodoColumnaAux(const NodoColumnaAux& orig) {
}

NodoColumnaAux::~NodoColumnaAux() {
}

NodoColumnaAux::NodoColumnaAux(int data) {
    valor_ = data;
}


/*
NodoColumnaAux::NodoColumnaAux(string data) {
    valor=data;
}

NodoColumnaAux::NodoColumnaAux(char data) {
    valor=data;
}

NodoColumnaAux::NodoColumnaAux(double data) {
    valor = to_string(data);
}*/
