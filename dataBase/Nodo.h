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
#include <stdio.h>
#include <string.h> 
#include <math.h>     
#include <time.h>    

#include <iostream>
using namespace std;

    class Nodo {
public:
    Nodo();
    Nodo(int data);
    Nodo(string data);
    Nodo(char data);
    Nodo(double data);
    Nodo *siguiente;
    Nodo *left;
    Nodo *right;
    Nodo *dad;
    Nodo *encolado;
    Nodo *nodoSiguiente;
    Nodo *nodoPrevio;
    int NivelIzq;
    int NivelDer;
    int getValueOfInt();
    string getValueOfString();
    char getValueOfChar();
    double getValueOfDouble();
    bool isEmptyNodo();
    int valueCompare;
    double valueToCompare;
    int valorInt;
    virtual ~Nodo();
    string valorString;
    string nombreDeColumna;
    char valorChar;
    double valorDouble;
    int typodeSeleccion;
    int claveGenerada;
private:


};

#endif /* NODO_H */

