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
    //Table(Table array[]);
    Table(string _type);
    virtual ~Table();
    int getSize();
    int getFactorDeCarga();
    Table* tablaSiguiente;
    Table* content;
    int size;
    BinaryThreeForInt arbolInt;
    /*BinaryThreeForInt arbolInt;
    BinaryThreeForString arbolString;
    BinaryThreeForChar arbolChar;
    BinaryThreeForFloat arbolFloat;*/
    Nodo *href;
   
private:
    int factroDeCarga;



};

#endif /* TABLE_H */

