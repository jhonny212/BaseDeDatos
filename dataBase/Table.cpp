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
 tablaSiguiente=NULL;
 content=NULL;
 arbolInt = BinaryThreeForInt();
}

/*Table::Table(Table array[]) {
    content = array;
    //arbolString = BinaryThreeForString();
    //arbolChar = BinaryThreeForChar();
   
   // arbolInt = BinaryThreeForInt();
   // arbolFloat = BinaryThreeForFloat();
}*/

Table::~Table() {
}

int Table::getFactorDeCarga() {
    return factroDeCarga;
}

int Table::getSize() {
    return size;
}

Table::Table(string _type) {
      
    //arbolString = BinaryThreeForString();
    //arbolChar = BinaryThreeForChar();
     
   
   // arbolInt = BinaryThreeForInt();
   // arbolFloat = BinaryThreeForFloat();
   
    /*if (_type == "string") {
        arbolString = BinaryThreeForString();
    } else if (_type == "char") {
        arbolChar = BinaryThreeForChar();
    } else if (_type == "int") {
        cout<<"inicializando arbol binario int"<<endl;
        arbolInt = BinaryThreeForInt();
    } else if (_type == "double") {
        arbolFloat = BinaryThreeForFloat();
    }*/
}


