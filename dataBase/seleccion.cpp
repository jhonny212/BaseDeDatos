/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   seleccion.cpp
 * Author: jhonny
 * 
 * Created on 11 de abril de 2020, 03:31 PM
 */

#include "seleccion.h"

seleccion::seleccion() {
    tm = 0;
    siguT = NULL;
    value = NULL;
}

seleccion::seleccion(const seleccion& orig) {
}

seleccion::~seleccion() {
}

void seleccion::addC(string c) {
    if (siguT == NULL) {
        NodoColumnaAux *t = new NodoColumnaAux();
        t->name = c;
        t->siguiente = NULL;
        siguT = t;
        value = siguT;
        siguT->siguiente = NULL;
        tm += 1;
    } else {
        NodoColumnaAux *t = new NodoColumnaAux();
        t->name = c;
        t->siguiente = NULL;
        siguT->siguiente = t;
        siguT = siguT->siguiente;
        tm += 1;
    }

}

string seleccion::get(int x) {
    string retorno = "";
    if (value!=NULL) {
        NodoColumnaAux *t = value;
        for (int i = 0; i < (x+1); i++) {
            retorno = t->name;
            if(t->siguiente!=NULL){
            t = t->siguiente;
            }else{
                break;
            }
        }
    }
    return retorno;
}
