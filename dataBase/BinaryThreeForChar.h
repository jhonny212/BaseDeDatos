/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryThreeForChar.h
 * Author: jhonny
 *
 * Created on 7 de abril de 2020, 09:49 AM
 */

#ifndef BINARYTHREEFORCHAR_H
#define BINARYTHREEFORCHAR_H
#include "ArbolBinario.h"
using namespace std;

class BinaryThreeForChar : public ArbolBinario {
public:
    BinaryThreeForChar();
    void showIntegerThree();
    void printLeft(Nodo *izq);
    void printRight(Nodo *der);
    void starPrint(Nodo *father);

private:
    string textoGrafica;
};

#endif /* BINARYTHREEFORCHAR_H */

