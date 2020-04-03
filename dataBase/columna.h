/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   columna.h
 * Author: jhonny
 *
 * Created on 1 de abril de 2020, 03:00 PM
 */

#ifndef COLUMNA_H
#define COLUMNA_H
#include <iostream>
using namespace std;

class columna {
public:
    columna(string _name,string _type);
    columna();
    string getName();
    string getType();
    
    virtual ~columna();
private:
    string name,type;
    

};

#endif /* COLUMNA_H */

