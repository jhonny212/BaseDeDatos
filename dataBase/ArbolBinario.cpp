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
    /*raiz = NULL;
    lastInserted = NULL;
    TamanoArbol = 0;
    textoGrafica="";*/
}

/*void ArbolBinario::insertarNodo(Nodo nodo) {
    if (TamanoArbol==16) {
        raiz = new Nodo(nodo.valorInt);
        lastInserted = raiz;


    } else  {
        
        int x = addInteger(raiz, nodo);
        if (raiz->right != NULL) {
            int x = raiz->right->NivelDer;
            int y = raiz->right->NivelIzq;
            if (x > y) {
                raiz->NivelDer = x + 1;
            } else if (x < y) {
                raiz->NivelDer = y + 1;
            } else if (x == y) {
                raiz->NivelDer = x + 1;
            }
        }
        if (raiz->left != NULL) {
            int x = raiz->left->NivelDer;
            int y = raiz->left->NivelIzq;
            if (x > y) {
                raiz->NivelIzq = x + 1;
            } else if (x < y) {
                raiz->NivelIzq = y + 1;
            } else if (x == y) {
                raiz->NivelIzq = x + 1;
            }
        }

      //  detectRotation(lastInserted->dad);

    }
}

int ArbolBinario::addInteger(Nodo* add, Nodo data) {
    int valor1 = add->valueToCompare;
    int retorno = 0;
    if (data.valueToCompare > valor1) {
        if (add->right == NULL) {
            add->right = new Nodo(data.getValueOfInt());
            add->right->dad = add;
            lastInserted = add->right;

            add->NivelDer = add->NivelDer + 1;

            if (add->left == NULL) {
                retorno = 1;
            }
        } else {

            retorno = addInteger(add->right, data.valueToCompare);
            int x = add->right->NivelDer;
            int y = add->right->NivelIzq;
            if (x > y) {
                add->NivelDer = x + 1;
            } else if (x < y) {
                add->NivelDer = y + 1;
            } else if (x == y) {
                add->NivelDer = x + 1;
            }
        }
    } else {
        if (add->left == NULL) {
            add->left = new Nodo(data.getValueOfInt());
            add->left->dad = add;
            lastInserted = add->left;
            add->NivelIzq = add->NivelIzq + 1;

            if (add->right == NULL) {
                retorno = 1;
            }
        } else {
            retorno = addInteger(add->left, data.valueToCompare);

            int x = add->left->NivelDer;
            int y = add->left->NivelIzq;
            if (x > y) {
                add->NivelIzq = x + 1;
            } else if (x < y) {
                add->NivelIzq = y + 1;
            } else if (x == y) {
                add->NivelIzq = x + 1;
            }
        }
    }
    return retorno;

}

int ArbolBinario::detectRotation(Nodo* param) {
    int retorno = 0;
    if (param != NULL) {
        int iz = param->NivelIzq;
        int der = param->NivelDer;
        int factorEq1 = der - iz;
        if ((factorEq1) > 1) {
            int factorEq2 = (param->right->NivelDer - param->right->NivelIzq);
            if (factorEq1 == 2 && factorEq2 < 0) {
                RotationRightLeft(param);
            } else {
                SimpleRotationTurnLeft(param);
            }

        } else if ((factorEq1)<-1) {

            int factorEq2 = (param->left->NivelDer - param->left->NivelIzq);
            if (factorEq1 == -2 && factorEq2 > 0) {
                RotationLeftRight(param);
            } else {
                SimpleRotationTurnRight(param);
            }
        }
        if (param->dad != NULL) {
            detectRotation(param->dad);
        }


    }
    return retorno;
}

void ArbolBinario::SimpleRotationTurnLeft(Nodo* param) {
    int iz = param->NivelIzq;
    int der = param->NivelDer;

    if (param == raiz) {

        Nodo *aux = param->right->left;
        int data = param->right->NivelIzq;
        param->right->left = param;
        param->right->dad = NULL;
        param->dad = new Nodo();
        param->dad = param->right;
        raiz = param->right;
        raiz->left->right = aux;
        raiz->NivelIzq = raiz->NivelIzq + 1;
        raiz->NivelDer = raiz->left->NivelDer - 1;
        raiz->left->NivelDer = data;

    } else {
        Nodo *aux = param->right->left;
        int data = param->right->NivelIzq;
        Nodo *N2 = param->dad->right;
        if (N2 == param) {
            param->dad->right = param->right;
        } else {
            param->dad->left = param->right;
        }
        param->right->dad = param->dad;
        param->dad = param->right;
        param->right->left = param;
        param->right = aux;
        param->dad->NivelIzq = iz + 1;
        param->dad->NivelDer = der - 1;
        param->NivelDer = data;


        FixLevelNodo(param);

    }
}

void ArbolBinario::SimpleRotationTurnRight(Nodo* param) {
    int iz = param->NivelIzq;
    int der = param->NivelDer;
    if (param->dad == NULL) {
        Nodo *aux = param->left->right;
        int data = param->left->NivelDer;
        param->left->right = param;
        param->left->dad = NULL;
        param->dad = new Nodo();
        param->dad = param->left;
        raiz = param->left;
        raiz->right->left = aux;
        raiz->NivelDer = raiz->NivelDer + 1;
        raiz->NivelIzq = raiz->right->NivelIzq - 1;
        raiz->right->NivelIzq = data;

    } else {
        cout << param->getValueOfInt() << " aca " << endl;
        Nodo *aux = param->left->right;
        int data = param->left->NivelDer;
        Nodo *N2 = param->dad->left;
        if (N2 == param) {
            param->dad->left = param->left;
        } else {
            param->dad->right = param->left;
        }
        param->left->dad = param->dad;
        param->dad = param->left;
        param->left->right = param;
        param->left = aux;
        param->dad->NivelDer = der + 1;
        param->dad->NivelIzq = iz - 1;
        param->NivelIzq = data;
        if (N2 == param) {
            param->dad->dad->left = param->dad;
        } else {
            param->dad->dad->right = param->dad;
        }
        FixLevelNodo(param);
    }
}

void ArbolBinario::RotationLeftRight(Nodo* param) {
    Nodo *n2 = param->left;
    Nodo *aux = param->left->right->left;
    int x = param->left->right->NivelIzq;
    param->left->dad = param->left->right;
    param->left->right->left = param->left;
    param->left->right->dad = param;
    param->left = param->left->right;
    param->left->left->NivelDer = 0;
    param->left->left->right = aux;
    param->left->left->NivelDer = x;
    SimpleRotationTurnRight(param);
}

void ArbolBinario::RotationRightLeft(Nodo* param) {
    Nodo *n1 = param;
    Nodo *n2 = param->right;
    Nodo *n3 = param->right->left;
    Nodo *aux = param->right->left->right;
    int x = param->right->left->NivelDer;
    param->right->left->dad = param;
    param->right->dad = param->right->left;
    param->right->left->right = param->right;
    param->right = param->right->left;
    param->right->right->NivelIzq = 0;
    param->right->right->left = aux;
    param->right->right->NivelIzq = x;
    SimpleRotationTurnLeft(param);
}

void ArbolBinario::FixLevelNodo(Nodo* param) {
    if (param->dad != NULL) {
        Nodo *aux = param->dad;
        while (aux != NULL) {
            if (aux->right != NULL) {
                int x = aux->right->NivelDer;
                int y = aux->right->NivelIzq;
                if (x > y) {
                    aux->NivelDer = x + 1;
                } else if (x < y) {
                    aux->NivelDer = y + 1;
                } else if (x == y) {
                    aux->NivelDer = x + 1;
                }
            }
            if (aux->left != NULL) {
                int x = aux->left->NivelDer;
                int y = aux->left->NivelIzq;
                if (x > y) {
                    aux->NivelIzq = x + 1;
                } else if (x < y) {
                    aux->NivelIzq = y + 1;
                } else if (x == y) {
                    aux->NivelIzq = x + 1;
                }
            }
            aux = aux->dad;
        }
    }
}*/