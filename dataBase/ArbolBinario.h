/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolBinario.h
 * Author: jhonny
 *
 * Created on 2 de abril de 2020, 02:45 PM
 */

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "Nodo.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

class ArbolBinario {
public:
    ArbolBinario();
    ArbolBinario(Nodo *r, int _op);
    void print();
    virtual ~ArbolBinario();
    void printLeft(Nodo *izq);
    void printRight(Nodo *der);
    void starPrint(Nodo *father);

private:
    int TamanoArbol;
    string textoGrafica;
    Nodo *lastInserted;
    Nodo *raiz;
    int opc;


};

#endif /* ARBOLBINARIO_H */

