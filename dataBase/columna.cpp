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
    cout << "paos aca" << endl;
}

/*columna::~columna() {
}*/

void columna::insertarDato(std::string dato) {



    //int clave = 0;
    //int index = 0;

    if (type == "string") {
        int clave = getIdForString(dato);
        int index = getIndex(clave, tablaHash.getSize());
        tablaHash.insertData(index, 1, dato);
    } else if (type == "char") {
        /* hashFunctions t = hashFunctions();
         char char_array[1];
         strcpy(char_array, dato.c_str());
         int clave = t.getIdForChar(char_array[0]);
         int index = t.getIndex(clave, tablaHash.getSize());
         */
        // tablaHash.insertData(index, 2, dato);
    } else if (type == "int") {
        int i = std::stoi(dato);
        int clave = getIdForInt(dato, i);
        int index = getIndex(clave, tablaHash.getSize());


        tablaHash.insertData(index, 3, dato);

    } else if (type == "double") {
        /*hashFunctions t = hashFunctions();
        double i = atof(dato.c_str());
        int clave = t.getIdForDouble(i);
        int index = t.getIndex(clave, tablaHash.getSize());*/

        //tablaHash.insertData(index, 4, dato);
    }



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

    int num = int((espacio * 5) * (clave * (0.4) - int(clave * 0.4)));
    return num;
}