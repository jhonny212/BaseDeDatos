/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   columnasData.h
 * Author: jhonny
 *
 * Created on 1 de abril de 2020, 03:20 PM
 */

#ifndef COLUMNASDATA_H
#define COLUMNASDATA_H
#include "columna.h"
#include "NodoColumna.h"
#include "Nodo.h"

#include <iostream>

using namespace std;

class columnasData {
public:
    columnasData();
    virtual ~columnasData();
    void add(columna c);
    void addC(string simple);
    void get(int i);
    void buscarColumna(string nameColumn);
    NodoColumna *valor;
    NodoColumna *sigu;
    Nodo* insertarEnColumna(string nameColumn,string);
    void actualizarColumnas(string nameColumn,string);
    
   
private:
    int size;
};

#endif /* COLUMNASDATA_H */

