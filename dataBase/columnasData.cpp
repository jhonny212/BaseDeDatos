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

columnasData::~columnasData() {
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
        t->column.tablaHash.actualizarInicio();
    } else {
        if (sigu->siguiente == NULL) {
            NodoColumna *t = new NodoColumna();
            t->column = c;
            t->siguiente = NULL;
            sigu->siguiente = t;
            t->column.tablaHash.actualizarInicio();
        }
        sigu = sigu->siguiente;
        size += 1;

    }
}

Nodo* columnasData::insertarEnColumna(string nameColumn, string valorRecibido) {
    if (valor != NULL) {
        NodoColumna *aux = valor;
        for (int i = 0; i < size; i++) {
            if (aux->column.name == nameColumn) {
                aux->column.insertarDato(valorRecibido);
                return aux->column.ultimo;
                break;
            }
            aux = aux->siguiente;
        }
    }
}

void columnasData::actualizarColumnas(string nameColumn, string valorRecibido) {
    if (valor != NULL) {
        NodoColumna *aux = valor;
        for (int i = 0; i < size; i++) {
            if (aux->column.name == nameColumn) {
                aux->column.actualizarDato(valorRecibido);
                break;
            }
            aux = aux->siguiente;
        }
    }
}

void columnasData::buscarColumna(string nameColumn, seleccion* cd) {
    if (valor != NULL) {
        if (nameColumn == "*") {
            valor->column.search(cd);
        } else {
            NodoColumna *aux = valor;
            for (int i = 0; i < size; i++) {
                if (aux->column.name == nameColumn) {
                    aux->column.search(cd);
                    break;
                }
                aux = aux->siguiente;
            }
        }
    }
}

string columnasData::get(int x) {
    string retorno = "";
    if (size >0) {
        NodoColumna *aux = valor;
        for (int i = 0; i < x; i++) {
            retorno = aux->column.name;
            if (aux->siguiente != NULL) {
                aux = aux->siguiente;
            } else {
                break;
            }
        }
    }
    return retorno;
}




