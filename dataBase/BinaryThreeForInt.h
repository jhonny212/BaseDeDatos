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
#include "ArbolBinario.h"
using namespace std;
class BinaryThreeForInt : public ArbolBinario {
public:
    BinaryThreeForInt();
    //void insertarNodo(Nodo nodo);
    //int addInteger(Nodo *add, double data);
    void showIntegerThree();
    void printLeft(Nodo *izq);
    void printRight(Nodo *der);
    void starPrint(Nodo *father);
  /*  void SimpleRotationTurnLeft(Nodo *param);
    void SimpleRotationTurnRight(Nodo *param);
    void RotationLeftRight(Nodo *param);
    void RotationRightLeft(Nodo *param);*/
    //int detectRotation(Nodo *param);
    //void fixSize(Nodo *aux);
  //  void FixLevelNodo(Nodo *param);
    
private:
    string textoGrafica;
};

#endif /* BINARYTHREEFORINT_H */

