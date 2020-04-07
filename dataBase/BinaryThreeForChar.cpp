/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryThreeForChar.cpp
 * Author: jhonny
 * 
 * Created on 7 de abril de 2020, 09:49 AM
 */

#include "BinaryThreeForChar.h"

BinaryThreeForChar::BinaryThreeForChar() {
    raiz = NULL;
    lastInserted = NULL;

}

void BinaryThreeForChar::showIntegerThree() {
    if (raiz != NULL) {
        int i = raiz->getValueOfInt();
        string padre = to_string(i);
        if (raiz->left != NULL) {
            int j = raiz->left->getValueOfInt();
            string izq = to_string(j);
            textoGrafica = textoGrafica + padre + " -> " + izq + " \n";
        }

        if (raiz->right != NULL) {
            int k = raiz->right->getValueOfInt();
            string der = to_string(k);
            textoGrafica = textoGrafica + padre + " -> " + der + " \n";
        }
        starPrint(raiz);
        cout << textoGrafica << endl;
    }
}

void BinaryThreeForChar::starPrint(Nodo* father) {

    if (father != NULL) {
        if (father->dad != NULL) {
            int i = father->getValueOfInt();
            string padre = to_string(i);
            if (father->left != NULL) {
                int j = father->left->getValueOfInt();
                string izq = to_string(j);
                textoGrafica = textoGrafica + padre + " -> " + izq + " \n";
            }

            if (father->right != NULL) {
                int k = father->right->getValueOfInt();
                string der = to_string(k);
                textoGrafica = textoGrafica + padre + " -> " + der + " \n";
            }

        }
        printLeft(father->left);
        printRight(father->right);
    }
}

void BinaryThreeForChar::printLeft(Nodo* izq) {
    if (izq != NULL) {
        starPrint(izq);
    }
}

void BinaryThreeForChar::printRight(Nodo* der) {
    if (der != NULL) {
        starPrint(der);
    }
}

