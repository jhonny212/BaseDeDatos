/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   columna.h
 * Author: jhonny
 *
 * Created on 1 de abril de 2020, 03:00 PM
 */

#ifndef COLUMNA_H
#define COLUMNA_H
#include <iostream>
#include <string.h> 
#include "TablaHash.h"
#include "hashFunctions.h"
#include "Nodo.h"
#include <stdio.h> 
using namespace std;

class columna {
public:
    columna();
    virtual ~columna();
    void insertarDato(string dato);
    TablaHash tablaHash;
    int getIdForString(string value);
    int getIdForInt(string value, int plus);
    int getIdForChar(char value);
    int getIdForDouble(double value);
    int getIndex(int clave, int espacio);
    void search();
    void actualizarDato(string dato);
    Nodo *ultimo;
    string name;
    string type;
    int contador;

private:


};

#endif /* COLUMNA_H */

