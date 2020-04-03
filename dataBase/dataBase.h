/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dataBase.h
 * Author: jhonny
 *
 * Created on 1 de abril de 2020, 02:49 PM
 */

#ifndef DATABASE_H
#define DATABASE_H
#include "columnasData.h"
#include <iostream>



using namespace std;
class dataBase {
public:
    dataBase();
    dataBase(columnasData cd,string name);
   
    columnasData getColumnas();
    string getName();
    int getTypeHashFunction(string valor);
    int getInt(string valor);
    int getInt2(string valor);
private:
    string Name;
    columnasData Columnas;
    
    
    
};

#endif /* DATABASE_H */

