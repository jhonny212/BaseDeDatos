/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoColumnaAux.h
 * Author: jhonny
 *
 * Created on 11 de abril de 2020, 03:41 PM
 */

#ifndef NODOCOLUMNAAUX_H
#define NODOCOLUMNAAUX_H
#include <iostream>
using namespace std;
class NodoColumnaAux {
public:
    NodoColumnaAux();
    NodoColumnaAux(const NodoColumnaAux& orig);
    virtual ~NodoColumnaAux();
    NodoColumnaAux *siguiente;
    string name;
private:

};

#endif /* NODOCOLUMNAAUX_H */

