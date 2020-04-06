/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   columnasData.cpp
 * Author: jhonny
 * 
 * Created on 1 de abril de 2020, 03:20 PM
 */

#include "columnasData.h"
using namespace std;

columnasData::columnasData() {
    //valor = NULL;
    //sigu = NULL;
    size=0;
}


/*
void columnasData::add(columna c) {
    if (sigu == NULL) {
        sigu = new Nodo(c);
        valor = sigu;
        size+=1;
    } else {
        sigu->siguiente = new Nodo(c);
        sigu = sigu->siguiente;
        size+=1;
    }
}

void columnasData::get(int i) {

    if (valor != NULL) {
        Nodo *aux=valor;
        for (int j = 0; j < i; j++) {
            cout<<" Nombre de columna "<<aux->column.getName()<<endl;
            cout<<" typo "<<aux->column.getType()<<endl;
            aux=aux->siguiente;
       }

    }
}

*/
