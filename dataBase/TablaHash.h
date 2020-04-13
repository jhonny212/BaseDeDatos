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
#include "seleccion.h"
#include "ArbolBinario.h"
#include "NodoColumnaAux.h"


using namespace std;

class TablaHash {
public:
    TablaHash();
    void createInitialTable();
    void makeRehashing();
    int getSize();
    Nodo* insertData(int indice, int tipo_, string valor,string);
   
    void actualizarInicio();
    string tipo;
    void searchData(string,seleccion* cd,bool);
    string paintPosicion(string,string);
    virtual ~TablaHash();
    Table *start = NULL;
    Table *next = NULL;
    Table array[5];
    Table d[1];
    //Table *f;
    int size;
    int factorVariador;
private:
    double factorDeCarga;
    int datasInsert;


};

#endif /* TABLAHASH_H */

