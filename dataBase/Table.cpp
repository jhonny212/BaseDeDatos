/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.cpp
 * Author: jhonny
 * 
 * Created on 6 de abril de 2020, 09:34 AM
 */

#include "Table.h"

Table::Table() {
    tablaSiguiente = NULL;
    encolado = NULL;
    inicio=NULL;
    arbolInt = BinaryThreeForInt();
    bandera=false;
    size=0;
}

int Table::getFactorDeCarga() {
    return factroDeCarga;
}

int Table::getSize() {
    return size;
}
Table::~Table(){
   
}

void Table::addForColisions(Table* t){

}



