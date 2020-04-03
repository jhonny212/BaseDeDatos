/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryThreeForString.h
 * Author: jhonny
 *
 * Created on 2 de abril de 2020, 08:52 PM
 */

#ifndef BINARYTHREEFORSTRING_H
#define BINARYTHREEFORSTRING_H
#include "ArbolBinario.h"

class BinaryThreeForString : public ArbolBinario {
public:
    BinaryThreeForString();
    void insertarNodo(Nodo nodo);
    void showIntegerThree();
    void printLeft(Nodo *izq);
    void printRight(Nodo *der);
    void starPrint(Nodo *father);
   
private:

};

#endif /* BINARYTHREEFORSTRING_H */

