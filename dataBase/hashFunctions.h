/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashFunctions.h
 * Author: jhonny
 *
 * Created on 2 de abril de 2020, 09:12 AM
 */

#ifndef HASHFUNCTIONS_H
#define HASHFUNCTIONS_H
#include <iostream>
#include <stdio.h>
#include <string.h> /* Archivo que contiene la definción de funciones que trabajan con caracteres.*/
#include <math.h>  /* Para que funcione  sqrt  */   
#include <time.h>    
using namespace std;

class hashFunctions {
public:
    hashFunctions();
    hashFunctions(const hashFunctions& orig);
    virtual ~hashFunctions();
    void getId(int typeHash);
private:
    void getIdForString(string value);
    void getIdForInt(int value);
    void getIdForChar(char value);
    void getIdForDouble(double value);
    
};

#endif /* HASHFUNCTIONS_H */

