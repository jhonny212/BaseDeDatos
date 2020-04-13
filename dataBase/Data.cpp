/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.cpp
 * Author: jhonny
 * 
 * Created on 12 de abril de 2020, 11:55 AM
 */

#include "Data.h"

Data::Data() {
    inicial = NULL;
    siguienteBaseDeDatos = NULL;
}

Data::Data(const Data& orig) {
    inicial = NULL;
    siguienteBaseDeDatos = NULL;
}

Data::~Data() {
}

void Data::add(string s) {
    if (valid(s)) {
        if (inicial == NULL) {
            siguienteBaseDeDatos = new dataBase(s);
            siguienteBaseDeDatos->nombreDeLaBaseDeDatos = s;
            inicial = siguienteBaseDeDatos;
        } else {
            siguienteBaseDeDatos->siguienteBaseDeDatos = new dataBase(s);
            siguienteBaseDeDatos = siguienteBaseDeDatos->siguienteBaseDeDatos;
        }
    } else {
        cout << " la base de datos ya existe " << endl;
    }
}

int Data::cantDatos() {
    int total = 0;
    if (inicial != NULL) {
        dataBase *aux = inicial;
        while (aux != NULL) {
            int tmp = aux->getTotal();
            cout << " base de datos " << aux->nombreDeLaBaseDeDatos << " tiene un total de " << tmp << " datos ingresados" << endl;
            total += tmp;
            aux = aux->siguienteBaseDeDatos;
        }
    } else {
        cout << " no hay base de datos " << endl;

    }
    return total;
}

dataBase* Data::get(string s) {
    if (inicial != NULL) {
        dataBase *aux = inicial;
        while (aux != NULL) {
            if (aux->nombreDeLaBaseDeDatos == s) {
                cout << "---------------base de datos encontrada------------" << endl;
                return aux;
                break;
            } else {
                aux = aux->siguienteBaseDeDatos;
            }
        }
    } else {
        cout << " no hay base de datos " << endl;

    }
    return NULL;
}

bool Data::valid(string name) {
    if (inicial != NULL) {
        dataBase *aux = inicial;
        while (aux != NULL) {
            if (aux->nombreDeLaBaseDeDatos == name) {
                return false;
                break;
            } else {
                aux = aux->siguienteBaseDeDatos;
            }
        }
    }
    return true;
}


