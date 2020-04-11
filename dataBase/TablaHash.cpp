/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TablaHash.cpp
 * Author: jhonny
 * 
 * Created on 5 de abril de 2020, 06:34 PM
 */

#include "TablaHash.h"

TablaHash::TablaHash() {
    size = 1;
    start = NULL;
    next = NULL;
    datasInsert = 0;
    factorDeCarga = 0.0;
    // createInitialTable();
}

TablaHash::~TablaHash() {

}

void TablaHash::createInitialTable() {
    for (int i = 0; i < 5; i++) {
        array[i] = Table();
    }
    size = 1;
    start = &array[0];
    next = &array[4];


}

void TablaHash::makeRehashing() {
    Table obj[5];
    for (int i = 0; i < 5; i++) {
        obj[i] = Table();
    }

    next->tablaSiguiente = obj;
    next = next->tablaSiguiente;
    size += 1;

}

int TablaHash::getSize() {
    return size;
}

void TablaHash::actualizarInicio() {
    next = array;
    start = next;
    // makeRehashing();
}

void TablaHash::searchData(string column) {
    Table *tmp = start;
    Table *aux = NULL;
    for (int i = 0; i < size; i++) {
        for (int i = 0; i < 5; i++) {
            if ((tmp + i)->arbolInt.raiz != NULL) {
                Table t=Table();
                t=*(tmp+i);
                cout<<t.href->valueToCompare<<endl;
                cout<<t.href->nodoSiguiente->valueToCompare<<endl;
            }
        }
        tmp=tmp->tablaSiguiente;
    }
}

Nodo* TablaHash::insertData(int indice, int tipo_, string valor, string nombreColumna) {
    Nodo nodoSave;
    Table *aux = NULL;

    if (size != 0) {
        bool isFound = true;
        int auxInd = (indice / 5) + 1;
        Table *tmp = start;
        for (int i = 0; i < auxInd - 1; i++) {
            if (tmp->tablaSiguiente != NULL) {
                tmp = tmp->tablaSiguiente;
            } else {
                break;
            }
        }

        int getSumForPunt = indice - ((auxInd - 1)*5);
        aux = (tmp + getSumForPunt);

        while (isFound) {
            int index = indice % 10;
            if (index >= 5) {
                index -= 5;
            }
            if (tipo_ == 1) {
                nodoSave = Nodo(valor);
                if (aux->arbolInt.raiz == NULL) {
                    (aux)->arbolInt.insertarNodo(nodoSave);
                    aux->href = aux->arbolInt.lastInserted;
                    aux->size = 1;
                    datasInsert += 1;
                } else {
                    (aux)->arbolInt.insertarNodo(nodoSave);
                    if (aux->size == 1) {
                        aux->size = 2;
                        aux->encolado = aux->arbolInt.lastInserted;
                        aux->inicio = aux->encolado;
                    } else {
                        aux->encolado->encolado = aux->arbolInt.lastInserted;
                        aux->encolado = aux->encolado->encolado;
                    }
                }

                isFound = false;

            } else if (tipo_ == 2) {
                char char_array[1];
                strcpy(char_array, valor.c_str());
                nodoSave = Nodo(char_array[0]);
                if (aux->arbolInt.raiz == NULL) {
                    (aux)->arbolInt.insertarNodo(nodoSave);
                    aux->href = aux->arbolInt.lastInserted;
                    aux->size = 1;
                    datasInsert += 1;

                } else {
                    (aux)->arbolInt.insertarNodo(nodoSave);
                    if (aux->size == 1) {
                        aux->size = 2;
                        aux->encolado = aux->arbolInt.lastInserted;
                        aux->inicio = aux->encolado;

                    } else {
                        aux->encolado->encolado = aux->arbolInt.lastInserted;
                        aux->encolado = aux->encolado->encolado;

                    }
                }

                isFound = false;

            } else if (tipo_ == 3) {
                int k = stoi(valor);
                nodoSave = Nodo(k);
                if (aux->arbolInt.raiz == NULL) {
                    (aux)->arbolInt.insertarNodo(nodoSave);
                    aux->href = aux->arbolInt.lastInserted;
                    aux->size = 1;
                    datasInsert += 1;
                } else {
                    (aux)->arbolInt.insertarNodo(nodoSave);
                    if (aux->size == 1) {
                        aux->size = 2;
                        aux->encolado = aux->arbolInt.lastInserted;
                        aux->inicio = aux->encolado;
                    } else {
                        aux->encolado->encolado = aux->arbolInt.lastInserted;
                        aux->encolado = aux->encolado->encolado;
                    }
                }

                isFound = false;
            } else if (tipo_ == 4) {
                double j = atof(valor.c_str());
                nodoSave = Nodo(j);
                nodoSave.nombreDeColumna=nombreColumna;
                if (aux->arbolInt.raiz == NULL) {
                    (aux)->arbolInt.insertarNodo(nodoSave);
                    aux->href = aux->arbolInt.lastInserted;
                    aux->size = 1;
                    datasInsert += 1;

                } else {
                    (aux)->arbolInt.insertarNodo(nodoSave);
                    if (aux->size == 1) {
                        aux->size = 2;
                        aux->encolado = aux->arbolInt.lastInserted;
                        aux->inicio = aux->encolado;

                    } else {
                        aux->encolado->encolado = aux->arbolInt.lastInserted;
                        aux->encolado = aux->encolado->encolado;
                    }
                }


                isFound = false;

            }
        }
    }
    //cout<<aux->arbolInt.lastInserted<<endl;

    factorDeCarga = datasInsert / (size * 5);
    if (factorDeCarga > 0.6) {
        cout << "hacer rehashing" << endl;
    }
    return aux->arbolInt.lastInserted;
}