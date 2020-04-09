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
    createInitialTable();

}

/*TablaHash::TablaHash(string t) {
    tipo = t;
    size = 1;
    cout << "entro aca ostia" << endl;
    //  createInitialTable();
}*/

/*TablaHash::TablaHash(const TablaHash& orig) {
    
}*/

void TablaHash::createInitialTable() {
    for (int i = 0; i < 5; i++) {

        array[i].arbolInt.TamanoArbol = 0;
    }
    start = array;
    size = 1;

    //cout<<(start+1)->size<<endl;

}

void TablaHash::makeRehashing(Table obj[]) {
    //    next->tablaSiguiente = new Table(obj);
    //    next = next->tablaSiguiente;
    //    size += 1;
}

void TablaHash::get(int x) {
    /*if (size != 0 && false) {
        Table *aux = start;
        for (int j = 0; j < x; j++) {
            Table *array;
            array = start;
            
        }
    }*/
}

int TablaHash::getSize() {
    return size;
}

void TablaHash::insertData(int indice, int tipo_, string valor) {
    if (size != 0) {
        bool isFound = true;
        int auxInd = (indice / 5) + 1;
        Table *aux = start;
        for (int i = 0; i < auxInd; i++) {
            aux = aux->tablaSiguiente;
        }

        while (isFound) {
            int index = indice % 10;
            if (index >= 5) {
                index -= 5;
            }
            Nodo *nodo;
            Nodo nodoSave;
            if (tipo_ == 1) {
                nodoSave = Nodo(valor);
                nodo = &nodoSave;
                //  aux->arbolString.insertarNodo(nodoSave);
                aux->href = &nodoSave;
            } else if (tipo_ == 2) {
                char char_array[1];
                strcpy(char_array, valor.c_str());
                nodoSave = Nodo(char_array[0]);
                nodo = &nodoSave;
                //  aux->arbolChar.insertarNodo(nodoSave);
                aux->href = &nodoSave;
            } else if (tipo_ == 3) {

                int k = stoi(valor);
                nodoSave = Nodo(k);
                nodo = &nodoSave;
                aux->arbolInt.insertarNodo(nodoSave);
                aux->href = &nodoSave;

                 aux->arbolInt.showIntegerThree();
                isFound = false;
            } else if (tipo_ == 4) {
                double j = atof(valor.c_str());
                nodoSave = Nodo(j);
                nodo = &nodoSave;
                //  aux->arbolFloat.insertarNodo(nodoSave);
                aux->href = &nodoSave;
            }
            /*switch (tipo_) {
                case 1:
                    nodoSave = Nodo(valor);
                    nodo = &nodoSave;
                    aux->arbolString.insertarNodo(nodoSave);
                    aux->href = &nodoSave;
                    break;
                case 2:
                    char char_array[1];
                    strcpy(char_array, valor.c_str());
                    nodoSave = Nodo(char_array[0]);
                    nodo = &nodoSave;
                    aux->arbolChar.insertarNodo(nodoSave);
                    aux->href = &nodoSave;

                    break;
                case 3:
                    int k = stoi(valor);
                    nodoSave = Nodo(k);
                    nodo = &nodoSave;
                    aux->arbolInt.insertarNodo(nodoSave);
                    aux->href = &nodoSave;
                    aux->arbolInt.showIntegerThree();
                    break;
                case 4:
                    double j = atof(valor.c_str());
                    nodoSave = Nodo(j);
                    nodo = &nodoSave;
                    aux->arbolFloat.insertarNodo(nodoSave);
                    aux->href = &nodoSave;

                    break;
            }*/

        }

    }
}