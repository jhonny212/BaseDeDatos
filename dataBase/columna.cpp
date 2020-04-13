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

columna::columna() {
    totalData = 0;
}

columna::~columna() {
}

string columna::arbolPintado() {
    return tablaHash.paintPosicion(type, name);
}

int columna::getTotal() {
    cout << " la columna  tiene un total de " << " datos " << endl;
    return 1;
}

void columna::search(seleccion* cd) {
    string data;
    data = cd->get(0);
    int i;
    bool v = false;
    if (data == "*") {
        i = 1;
        v = true;
    } else {
        i = 0;
    }
    data = "";
    for (; i < cd->tm; i++) {
        data += cd->get(i);
        data += " | ";
    }
    cout << "\n" << endl;
    cout << "******* Datos de la Columna \"" << "\" *******" << endl;
    cout << data << endl;
    tablaHash.searchData(name, cd, v);



}

void columna::insertarDato(string dato) {
    if (type == "string") {
        int clave = getIdForString(dato);
        int index = getIndex(clave, tablaHash.getSize());

        ultimo = tablaHash.insertData(index, 1, dato, name);
    } else if (type == "char") {
        hashFunctions t = hashFunctions();
        char char_array[1];
        strcpy(char_array, dato.c_str());
        int clave = t.getIdForChar(char_array[0]);
        int index = t.getIndex(clave, tablaHash.getSize());
        ultimo = tablaHash.insertData(index, 2, dato, name);
    } else if (type == "int") {
        int i = std::stoi(dato);
        int clave = getIdForInt(dato, i);
        int index = getIndex(clave, tablaHash.getSize());
        ultimo = tablaHash.insertData(index, 3, dato, name);

    } else if (type == "double") {
        hashFunctions t = hashFunctions();
        double i = atof(dato.c_str());
        int clave = t.getIdForDouble(i);
        int index = t.getIndex(clave, tablaHash.getSize());
        ultimo = tablaHash.insertData(index, 4, dato, name);

    }
    totalData += 1;

}

void columna::buscarDato(string dato,seleccion* cd2) {
    if (type == "string") {
        int clave = getIdForString(dato);
        for (int i = tablaHash.getSize(); i > 0; i--) {
            int index = getIndex(clave, i);
            tablaHash.buscarData(index, 1, dato,cd2);
        }

    } else if (type == "char") {
        hashFunctions t = hashFunctions();
        char char_array[1];
        strcpy(char_array, dato.c_str());
        int clave = t.getIdForChar(char_array[0]);
        for (int i = tablaHash.getSize(); i > 0; i--) {
            int index = t.getIndex(clave, i);
            tablaHash.buscarData(index, 2, dato,cd2);
        }

    } else if (type == "int") {
        int i = std::stoi(dato);
        int clave = getIdForInt(dato, i);
        for (int i = tablaHash.getSize(); i > 0; i--) {
            int index = getIndex(clave, i);
            tablaHash.buscarData(index, 3, dato,cd2);
        }
    } else if (type == "double") {
        hashFunctions t = hashFunctions();
        double i = atof(dato.c_str());
        int clave = t.getIdForDouble(i);
        for (int i = tablaHash.getSize(); i > 0; i--) {
            int index = t.getIndex(clave, i);
            tablaHash.buscarData(index, 4, dato,cd2);
        }
    }
}

void columna::actualizarDato(std::string dato) {

}

int columna::getIdForString(string value) {
    char tab2[value.length()];
    strcpy(tab2, value.c_str());
    int indice = 0;
    int aux = int (tab2[(int) (value.length() / 2)]);
    if (aux >= 97) {
        aux -= 97;
    } else if (aux >= 65 && aux < 97) {
        aux -= 64;
    }
    for (int i = 0; i < value.length(); i++) {
        char car = tab2[i];
        int numcar;

        numcar = int(car);
        if (numcar >= 97) {
            numcar -= 97;
        } else if (numcar >= 65 && numcar < 97) {
            numcar -= 64;
        }
        indice += numcar;
    }
    indice += aux;
    return indice;
}

int columna::getIdForChar(char value) {
    int numcar = (int) value;
    numcar -= 32;
    return numcar;
}

int columna::getIdForInt(string value, int plus) {
    string str = value;
    char tab2[str.length()];
    strcpy(tab2, str.c_str());
    int indice = 0;
    for (int i = 0; i < str.length(); i++) {
        char car = tab2[i];
        int numcar;
        numcar = int(car);
        numcar -= 47;
        indice += numcar;

    }
    indice += plus;
    return indice;
}

int columna::getIdForDouble(double value) {
    string str = to_string(value);
    cout << str << endl;
    char tab2[str.length()];
    strcpy(tab2, str.c_str());
    int indice = 0;
    bool valid = false;
    for (int i = str.length() - 1; i >= 0; i--) {
        char car = tab2[i];
        int numcar;
        numcar = int(car);

        if (numcar != 48 && !valid) {
            valid = true;
        }
        if (valid) {
            if (numcar == 46) {
                numcar -= 45;
            } else {
                numcar -= 47;
            }
            indice += numcar;
        }
    }
    indice += value;
    return indice;
}

int columna::getIndex(int clave, int espacio) {

    int num = int((espacio * 4) * (clave * (0.4) - int(clave * 0.4)));
    return num;
}