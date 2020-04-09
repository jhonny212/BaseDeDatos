/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   columna.cpp
 * Author: jhonny
 * 
 * Created on 1 de abril de 2020, 03:00 PM
 */

#include "columna.h"

/*columna::columna(string _name, string _type) {
    type = _type;
    name = _name;
    tablaHash.tipo=_type;

}
 */
string columna::getName() {
    return name;
}

string columna::getType() {
    return type;
}

columna::columna() {

}

/*columna::~columna() {
}*/

void columna::insertarDato(std::string dato) {
    hashFunctions t = hashFunctions();
    int clave = 0;
    int index = 0;
    if (type == "string") {
        clave = t.getIdForString(dato);
        index = t.getIndex(clave, tablaHash.getSize());
        tablaHash.insertData(index, 1, dato);
    } else if (type == "char") {
        char char_array[1];
        strcpy(char_array, dato.c_str());
        clave = t.getIdForChar(char_array[0]);
        index = t.getIndex(clave, tablaHash.getSize());
        tablaHash.insertData(index, 2, dato);
    } else if (type == "int") {
        int i = std::stoi(dato);
        clave = t.getIdForInt(i);
        index = t.getIndex(clave, tablaHash.getSize());
        
        tablaHash.insertData(index, 3, dato);

    } else if (type == "double") {
        double i = atof(dato.c_str());
        clave = t.getIdForDouble(i);
        index = t.getIndex(clave, tablaHash.getSize());
        tablaHash.insertData(index, 4, dato);
    }

}
