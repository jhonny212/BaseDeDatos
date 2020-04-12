/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dataBase.cpp
 * Author: jhonny
 * 
 * Created on 6 de abril de 2020, 03:28 PM
 */

#include "dataBase.h"

dataBase::dataBase() {
}

dataBase::~dataBase() {
}

void dataBase::get(string par) {
    Tabla *aux = valor;
    while (aux != NULL) {
        if (par == aux->nombre) {
            cout << " el valor es" << aux->nombre << endl;
            break;
        } else {
            aux = aux->siguiente;
        }
    }

}

dataBase::dataBase(Tabla tb, string name) {
    tabla = tb;
    Name = name;
    valor = &tb;
    sigu = NULL;
    tamTabla = 1;

}

void dataBase::cantOfColumns() {
    Tabla *aux = valor;
    int tam = 0;
    int total = 0;
    cout << "\n \n " << endl;
    for (int i = 0; i < tamTabla; i++) {
        tam = aux->columns.size;
        cout << "La tabla " << aux->nombre << " contiene " << tam << " columnas" << endl;
        aux = aux->siguiente;
        total += tam;
    }
    cout << "La base de datos seleccionada \"" << nombreDeLaBaseDeDatos << "\" contiene un total de " << total << " columnas " << endl;
}

void dataBase::equalsCantTypeRowsForATable(string param) {
    Tabla *aux = valor;
    cout << "\n \n " << endl;
    for (int i = 0; i < tamTabla; i++) {
        if (aux->nombre == param) {
            aux->columns.types();
            break;
        }
        aux = aux->siguiente;

    }
}

void dataBase::totalDeDatos() {
    int total = 0;
    cout << "\n \n -------------------------------------------------------" << endl;
    if (valor != NULL) {
        Tabla *aux = valor;
        for (int i = 0; i < tamTabla; i++) {
            aux->columns.dataForColumns();
            aux = aux->siguiente;
        }
        cout << " la base de datos tiene " << total << " datos ingresados " << endl;
    }
}

string dataBase::getName() {
    cout << "el nombre es" << tabla.nombre << endl;
    return Name;
}

void dataBase::addTable(columnasData tb, string name) {
    if (valor == NULL) {
        sigu = new Tabla();
        sigu->columns = tb;
        sigu->nombre = name;
        valor = sigu;
        tamTabla += 1;
    } else {
        sigu->siguiente = new Tabla();
        sigu->siguiente->columns = tb;
        sigu->siguiente->nombre = name;
        sigu = sigu->siguiente;
        tamTabla += 1;
    }
}

int dataBase::getTypeHashFunction(string valor) {
    int aux = getInt(valor);
    int indiceTypeHash = -1;
    if (valor.length() == 1) {
        if (aux == 1) {
            indiceTypeHash = 1;
        } else {
            indiceTypeHash = 2;
        }
    } else {
        if (aux == 1) {
            indiceTypeHash = 1;
        } else {
            if (getInt2(valor) == 3) {
                indiceTypeHash = 3;
            } else {
                indiceTypeHash = 4;
            }
        }
    }
    return indiceTypeHash;
}

int dataBase::getInt(string valor) {
    int indiceTypeHash = -2;
    try {
        int i = std::stoi(valor);
        string str = to_string(i);
        if (valor.length() == str.length()) {
            indiceTypeHash = 1;
        }
    } catch (std::invalid_argument const &e) {
    } catch (std::out_of_range const &e) {
    }
    return indiceTypeHash;
}

int dataBase::getInt2(string valor) {
    int retorno = -2;
    double temp = atof(valor.c_str());
    if (temp != 0) {
        retorno = 3;
    }
    return retorno;
}


