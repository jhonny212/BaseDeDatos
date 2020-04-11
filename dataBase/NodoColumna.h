/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoColumna.h
 * Author: jhonny
 *
 * Created on 8 de abril de 2020, 12:01 PM
 */

#ifndef NODOCOLUMNA_H
#define NODOCOLUMNA_H
#include "columna.h"
#include <iostream>

using namespace std;
class NodoColumna {
public:
    NodoColumna();
    NodoColumna(const NodoColumna& orig);
    virtual ~NodoColumna();
    columna column;
    NodoColumna *siguiente;
    string name;
private:

};

#endif /* NODOCOLUMNA_H */

