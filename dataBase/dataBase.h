/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dataBase.h
 * Author: jhonny
 *
 * Created on 6 de abril de 2020, 03:28 PM
 */

#ifndef DATABASE_H
#define DATABASE_H
#include <string.h> 
#include <iostream>
#include <string>
#include <sstream>
#include "Tabla.h"
#include "columnasData.h"


using namespace std;

class dataBase {
public:
    dataBase();
    dataBase(Tabla tb, string v);
    string  getName();
    int getTypeHashFunction(string valor);
    int getInt(string valor);
    int getInt2(string valor);
    void addTable(columnasData tb, string name);
    void cantOfColumns();
    void totalDeDatos();
    void equalsCantTypeRowsForATable(string param);
    virtual ~dataBase();
    void get(string par);
    Tabla tabla;
        string nombreDeLaBaseDeDatos;

private:
    
    Tabla *valor;
    Tabla *sigu;
    int tamTabla;
    string Name;
};

#endif /* DATABASE_H */

