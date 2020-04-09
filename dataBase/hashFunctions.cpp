/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashFunctions.cpp
 * Author: jhonny
 * 
 * Created on 2 de abril de 2020, 09:12 AM
 */

#include "hashFunctions.h"

hashFunctions::hashFunctions() {
}

hashFunctions::hashFunctions(const hashFunctions& orig) {
}

hashFunctions::~hashFunctions() {
}

void hashFunctions::getId(int typeHash) {
    int cod = -1;
}

int hashFunctions::getIdForString(string value) {
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

int hashFunctions::getIdForChar(char value) {
    int numcar = (int) value;
    numcar -= 32;
   // cout << numcar << endl;
    return numcar;
}

int hashFunctions::getIdForInt(int value) {
    string str = to_string(value);
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
    indice += value;
   // cout << indice << endl;
    return indice;
}

int hashFunctions::getIdForDouble(double value) {
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
    //cout << indice << endl;
    return indice;
}

int hashFunctions::getIndex(int clave, int espacio) {
    
    int num = int((espacio*5) * (clave * (0.4) - int(clave * 0.4)));
    return num;
}