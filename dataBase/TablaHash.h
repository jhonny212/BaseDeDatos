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
   // TablaHash(string);
    void createInitialTable();
    void makeRehashing(Table obj[]);
    //TablaHash(const TablaHash& orig);
    void get(int);
   // virtual ~TablaHash();
    int getSize();
    void insertData( int indice, int tipo_,string valor);
    string tipo;
private:
    Table *start=NULL;
    Table *next=NULL;
    Table array[5];
    int size;
  

};

#endif /* TABLAHASH_H */

