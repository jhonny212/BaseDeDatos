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
#include "TablaHash.h"
#include "hashFunctions.h"

using namespace std;

class columna {
public:
    columna();
    void inicializarArboles();
    string getName();
    string getType();
    void insertarDato(std::string dato);
    TablaHash tablaHash;
    
    int getIdForString(string value);
    int getIdForInt(string value, int plus);
    int getIdForChar(char value);
    int getIdForDouble(double value);
    int getIndex(int clave,int espacio);
    
    string name, type;
    int key;
    int Index;
private:
   
 
};

#endif /* COLUMNA_H */

