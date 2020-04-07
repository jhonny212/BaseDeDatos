/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tabla.h
 * Author: jhonny
 *
 * Created on 6 de abril de 2020, 03:28 PM
 */

#ifndef TABLA_H
#define TABLA_H
#include "columnasData.h"
#include <iostream>

#include <string.h> 
#include <string>
#include <sstream>

using namespace std;
class Tabla {
public:
    Tabla();
      Tabla(columnasData, string data  );
      Tabla *siguiente;
      string nombre;
private:
    columnasData columns;
    
};

#endif /* TABLA_H */

