/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   columna.cpp
 * Author: jhonny
 * 
 * Created on 1 de abril de 2020, 03:00 PM
 */

#include "columna.h"


columna::columna(string _name, string _type){
    name=_name;
    type=_type;
}

string columna::getName(){
    return type;
}

string columna::getType(){
    return name;
}

columna::columna(){
}

columna::~columna() {
}

