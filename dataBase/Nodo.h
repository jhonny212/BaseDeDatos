/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: jhonny
 *
 * Created on 1 de abril de 2020, 03:23 PM
 */

#ifndef NODO_H
#define NODO_H

using namespace std;
#include "columna.h"
#include "Nodo.h"

class Nodo {
public:
    Nodo ();
    Nodo (columna c);
    Nodo (int data);
    Nodo (string data);
    Nodo (char data);
    Nodo (double data);
   
    columna column;
    Nodo *siguiente;
    Nodo *left;
    Nodo *right;
    Nodo *dad;
    int NivelIzq;
    int NivelDer;
    int getValueOfInt();
    string getValueOfString();
    char getValueOfChar();
    double getValueOfDouble();
    bool isEmptyNodo();
    int valueCompare;
    
private:
    int valorInt;
    string valorString;
    char valorChar;
    double valorDouble;
   
};

#endif /* NODO_H */

