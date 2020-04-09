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
    size = 0;
}

void columnasData::add(columna c) {
    if (sigu == NULL) {
        NodoColumna *t = new NodoColumna();
        t->column = c;
        t->siguiente = NULL;
        sigu = t;
        valor = sigu;
        sigu->siguiente = NULL;
        size += 1;
    } else {
        if (sigu->siguiente == NULL) {
            NodoColumna *t = new NodoColumna();
            t->column = c;
            t->siguiente = NULL;
            sigu->siguiente = t;
        }
        sigu = sigu->siguiente;
        size += 1;
    }
}

void columnasData::get(int i) {
    if (valor != NULL) {
        NodoColumna *aux = valor;
        for (int j = 0; j < i; j++) {
            cout << " Nombre de columna " << aux->column.getName() << endl;
            cout << " typo " << aux->column.getType() << endl;
            aux = aux->siguiente;
        }

    }
}

void columnasData::insertarEnColumna(string nameColumn, string valorRecibido) {
    if (valor != NULL) {
        cout << " buscando columna " << nameColumn << endl;
        NodoColumna *aux = valor;
        for (int i = 0; i < size; i++) {
            if (aux->column.getName() == nameColumn) {
                aux->column.insertarDato(valorRecibido);
                break;
            }
            aux = aux->siguiente;
        }


    }
}


