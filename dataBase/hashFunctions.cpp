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

void hashFunctions::getIdForString(string value) {
    char tab2[value.length()];
    strcpy(tab2, value.c_str());
    int indice = 0;
    for (int i = 0; i < value.length(); i++) {
        char car = tab2[i];
        int numcar;
        numcar = int(car);
        if (numcar != 32) {
            if (numcar < 100) {
                numcar -= 64;
            } else {
                numcar -= 99;
            }
        }
        indice += numcar;
    }
}

void hashFunctions::getIdForChar(char value) {
    char car = value;
    int numcar;
    numcar = int(car);
    if (numcar != 32) {
        if (numcar < 100) {
            numcar -= 43;
        } else {
            numcar -= 100;
        }
    }
    cout << numcar << endl;
}

void hashFunctions::getIdForInt(int value) {
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
    if (value > 100) {
        indice -= 100;
    }
    cout << indice << endl;
}

void hashFunctions::getIdForDouble(double value) {
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
    if (value > 100) {
        indice -= 100;
    }
    cout << indice << endl;
}