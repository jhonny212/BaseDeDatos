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



class columnasData {
public:
    columnasData();
    void add(columna c);
    void get(int i);
   // Nodo *valor;
   // Nodo *sigu;
    NodoColumna *valor;
    NodoColumna *sigu;
    void insertarEnColumna(string nameColumn,string);
    
private:
    int size;
};

#endif /* COLUMNASDATA_H */

