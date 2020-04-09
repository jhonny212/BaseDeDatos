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
    void insertarNodo(Nodo );
    int addInteger(Nodo *add, Nodo data);

    virtual void showIntegerThree() = 0;
    virtual void printLeft(Nodo *izq) = 0;
    virtual void printRight(Nodo *der) = 0;
    virtual void starPrint(Nodo *father) = 0;

    int detectRotation(Nodo *param);

    void SimpleRotationTurnLeft(Nodo *param);
    void SimpleRotationTurnRight(Nodo *param);
    void RotationLeftRight(Nodo *param);
    void RotationRightLeft(Nodo *param);
    void FixLevelNodo(Nodo *param);
    int TamanoArbol;
    string textoGrafica;
protected:
    Nodo *lastInserted;
    Nodo *raiz;
    

};

#endif /* ARBOLBINARIO_H */

