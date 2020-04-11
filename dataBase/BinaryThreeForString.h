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
#include "Nodo.h"
using namespace std;

class BinaryThreeForString {
public:
    BinaryThreeForString();
    void showStringThree();
    void printLeft(Nodo *izq);
    void printRight(Nodo *der);
    void starPrint(Nodo *father);

    void insertarNodo(Nodo);
    int addInteger(Nodo *add, Nodo data);

    void SimpleRotationTurnLeft(Nodo *param);
    void SimpleRotationTurnRight(Nodo *param);
    void RotationLeftRight(Nodo *param);
    void RotationRightLeft(Nodo *param);
    int detectRotation(Nodo *param);
    void FixLevelNodo(Nodo *param);

private:
    string textoGrafica;

    int TamanoArbol;
    Nodo *lastInserted;
    Nodo *raiz;

};

#endif /* BINARYTHREEFORSTRING_H */

