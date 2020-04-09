/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TablaHash.h
 * Author: jhonny
 *
 * Created on 5 de abril de 2020, 06:34 PM
 */

#ifndef TABLAHASH_H
#define TABLAHASH_H
#include "Table.h"
#include "Nodo.h"

#include <stdio.h>
#include <cstdlib>
#include <iostream>


using namespace std;

class TablaHash {
public:
    TablaHash();
    void createInitialTable();
    void makeRehashing();
    void get(int);
    int getSize();
    void insertData( int indice, int tipo_,string valor);
    void actualizarInicio();
    string tipo;
    
    Table *start=NULL;
    Table *next=NULL;
    Table array[5];
    int size;
private:
    
  

};

#endif /* TABLAHASH_H */

