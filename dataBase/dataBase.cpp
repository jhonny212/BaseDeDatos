/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dataBase.cpp
 * Author: jhonny
 * 
 * Created on 1 de abril de 2020, 02:49 PM
 */

#include "dataBase.h"
#include <string>

dataBase::dataBase() {
}

dataBase::dataBase(columnasData cd, string name) {
    Columnas = cd;
    Name = name;
}

columnasData dataBase::getColumnas() {
    return Columnas;
}

string dataBase::getName() {
    return Name;
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


