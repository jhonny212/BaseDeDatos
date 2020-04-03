/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolBinario.cpp
 * Author: jhonny
 * 
 * Created on 2 de abril de 2020, 02:45 PM
 */

#include "ArbolBinario.h"

ArbolBinario::ArbolBinario() {
}


/*
void ArbolBinario::insertarNodoINT(int nodo) {
    if (isEmpty()) {
        raiz = new Nodo(nodo);
    } else {
        addInteger(raiz, nodo);

    }
}

int ArbolBinario::addInteger(Nodo* add, int data) {
    int valor1 = add->getValueOfInt();
    int retorno = 0;
    if (data > valor1) {
        if (add->right == NULL) {
            add->right = new Nodo(data);
            add->right->dad = add;
            // cout << " Hijo der:" << add->right->getValueOfInt() << " Padre: " << add->right->dad->getValueOfInt() << endl;
            if (add->left == NULL) {
                retorno = 1;
                add->NivelDer = add->NivelDer + 1;
            } else if (add->left->NivelDer == 0 && add->left->NivelIzq == 0) {
                retorno = 1;
                add->NivelDer = add->NivelDer + 1;
            }
    } else {
            int value = addInteger(add->right, data);
            retorno = value;
            add->NivelDer = add->NivelDer + value;
        }
    } else {
        if (add->left == NULL) {
            add->left = new Nodo(data);
            add->left->dad = add;
            if (add->right == NULL) {
                retorno = 1;
                add->NivelIzq = add->NivelIzq + 1;
            } else {
                
                if ((add->right->right!=NULL) or (add->right->left!=NULL)) {
                    retorno = 1;
                    add->NivelIzq = add->NivelIzq + 1;
                }
       }
            //  cout << " Hijo izq:" << add->left->getValueOfInt() << " Padre: " << add->left->dad->getValueOfInt() << endl;
        } else {
            int value = addInteger(add->left, data);
            retorno = value;
            add->NivelIzq = add->NivelIzq + value;
        }
    }
    return retorno;
}

void ArbolBinario::showIntegerThree() {
    if (!isEmpty()) {
        starPrint(raiz);
    }
}

void ArbolBinario::starPrint(Nodo* father) {
    if (father != NULL) {
        cout << "Padre " << father->getValueOfInt() << endl;
        cout << " cant de hijos a la derecha " << father->NivelDer << endl;
        cout << " cant de hijos a la izquierda " << father->NivelIzq << endl;

        printLeft(father->left);
        printRight(father->right);

    }
}

void ArbolBinario::printLeft(Nodo* izq) {
    if (izq != NULL) {
        cout << "       LEFT->" << izq->getValueOfInt() << endl;
        starPrint(izq);
    }
}

void ArbolBinario::printRight(Nodo* der) {
    if (der != NULL) {
        cout << "       RIGHT->" << der->getValueOfInt() << endl;
        starPrint(der);
    }
}

bool ArbolBinario::isEmpty() {
    if (raiz == NULL)
        return true;
    else return false;
}
*/