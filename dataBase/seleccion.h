/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   seleccion.h
 * Author: jhonny
 *
 * Created on 11 de abril de 2020, 03:30 PM
 */

#ifndef SELECCION_H
#define SELECCION_H
#include <iostream>
#include "NodoColumnaAux.h"

using namespace std;

class seleccion {
public:
    seleccion();
   
    
    seleccion(const seleccion& orig);
    virtual ~seleccion();
    void addC(string simple);
    void addD(string,string,string);
    string get(int);
    NodoColumnaAux * getCond(int);
    
    string name;
    NodoColumnaAux *value;
    NodoColumnaAux *siguT;
    string tipoDeCondicion;
    int tm;
private:
    
};

#endif /* SELECCION_H */

