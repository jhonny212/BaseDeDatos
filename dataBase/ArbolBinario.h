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

class ArbolBinario {
public:
    ArbolBinario();
    virtual void insertarNodo(Nodo nodo)=0;
    /*void insertarNodoINT(int nodo);
    bool isEmpty();
    int addInteger(Nodo *add, int data);
    
    */
    virtual void showIntegerThree()=0;
    virtual void printLeft(Nodo *izq)=0;
    virtual void printRight(Nodo *der)=0;
    virtual void starPrint(Nodo *father)=0;
protected:
    Nodo *raiz;
    
};

#endif /* ARBOLBINARIO_H */

