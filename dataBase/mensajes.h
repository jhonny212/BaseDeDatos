/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mensajes.h
 * Author: jhonny
 *
 * Created on 1 de abril de 2020, 01:23 PM
 */

#ifndef MENSAJES_H
#define MENSAJES_H
#include <iostream>

using namespace std;

class mensajes {
public:
    mensajes();
    mensajes(const mensajes& orig);
    void welcome();
    int opcion();
    int seleccion();
    int typeQuery();
    int reportes();
    virtual ~mensajes();
    
private:

};

#endif /* MENSAJES_H */

