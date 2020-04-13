/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryThreeForInt.h
 * Author: jhonny
 *
 * Created on 2 de abril de 2020, 08:26 PM
 */

#ifndef BINARYTHREEFORINT_H
#define BINARYTHREEFORINT_H
#include "Nodo.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "seleccion.h"

using namespace std;

class BinaryThreeForInt {
public:
    BinaryThreeForInt();

    virtual ~BinaryThreeForInt();
    void insertarNodo(Nodo nodo);
    int addInteger(Nodo *add, Nodo data);
    string showIntegerThree(int);
    void printLeft(Nodo *izq);
    void printRight(Nodo *der);
    void starPrint(Nodo *father);

    void SimpleRotationTurnLeft(Nodo *param);
    void SimpleRotationTurnRight(Nodo *param);
    void RotationLeftRight(Nodo *param);
    void RotationRightLeft(Nodo *param);
    int detectRotation(Nodo *param);
    void FixLevelNodo(Nodo *param);

    int opc;
    int TamanoArbol;
    string textoGrafica;
    string txtGraficaTmp;
    Nodo *lastInserted;
    Nodo *raiz = NULL;
    bool isEmpty;
    int contador;
    string estruct;
    int contarNodos;
    void setString(string nuevotxt);
private:

};

#endif /* BINARYTHREEFORINT_H */

