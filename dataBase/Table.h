/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.h
 * Author: jhonny
 *
 * Created on 6 de abril de 2020, 09:34 AM
 */

#ifndef TABLE_H
#define TABLE_H
#include "BinaryThreeForInt.h"
#include "Nodo.h"

class Table {
public:
    Table();
    virtual ~Table();
    void addForColisions(Table* t);
    int getSize();
    int getFactorDeCarga();
    Table* tablaSiguiente;
    Nodo *encolado;
    Nodo *inicio;
    int size;
    BinaryThreeForInt arbolInt;
    Nodo *href;
    bool bandera;
private:
    int factroDeCarga;



};

#endif /* TABLE_H */

