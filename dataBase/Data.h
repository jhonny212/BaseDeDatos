/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.h
 * Author: jhonny
 *
 * Created on 12 de abril de 2020, 11:55 AM
 */

#ifndef DATA_H
#define DATA_H
#include "dataBase.h"
#include <iostream>
#include "Tabla.h"

using namespace std;
class Data {
public:
    Data();
    
    Data(const Data& orig);
    virtual ~Data();
    dataBase *inicial;
    dataBase *siguienteBaseDeDatos;
    void add(string);
    dataBase* get(string);
    bool valid(string);
    int cantDatos();
private:

};

#endif /* DATA_H */

