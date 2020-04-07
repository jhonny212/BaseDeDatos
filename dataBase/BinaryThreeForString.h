/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryThreeForString.h
 * Author: jhonny
 *
 * Created on 7 de abril de 2020, 09:48 AM
 */

#ifndef BINARYTHREEFORSTRING_H
#define BINARYTHREEFORSTRING_H
#include "ArbolBinario.h"
using namespace std;

class BinaryThreeForString : public ArbolBinario {
public:
    BinaryThreeForString();
    void showIntegerThree();
    void printLeft(Nodo *izq);
    void printRight(Nodo *der);
    void starPrint(Nodo *father);
private:
    string textoGrafica;
};

#endif /* BINARYTHREEFORSTRING_H */

