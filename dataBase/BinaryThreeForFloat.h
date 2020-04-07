/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryThreeForFloat.h
 * Author: jhonny
 *
 * Created on 7 de abril de 2020, 09:49 AM
 */

#ifndef BINARYTHREEFORFLOAT_H
#define BINARYTHREEFORFLOAT_H
#include "ArbolBinario.h"
using namespace std;

class BinaryThreeForFloat : public ArbolBinario {
public:
    BinaryThreeForFloat();
    void showIntegerThree();
    void printLeft(Nodo *izq);
    void printRight(Nodo *der);
    void starPrint(Nodo *father);
private:
      string textoGrafica;
};

#endif /* BINARYTHREEFORFLOAT_H */

