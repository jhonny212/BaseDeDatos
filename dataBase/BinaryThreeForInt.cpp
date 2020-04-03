/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryThreeForInt.cpp
 * Author: jhonny
 * 
 * Created on 2 de abril de 2020, 08:26 PM
 */

#include "BinaryThreeForInt.h"

BinaryThreeForInt::BinaryThreeForInt() {
    raiz = NULL;
    lastInserted = NULL;
}

int BinaryThreeForInt::addInteger(Nodo* add, int data) {
    int valor1 = add->getValueOfInt();
    int retorno = 0;
    if (data > valor1) {
        if (add->right == NULL) {
            add->right = new Nodo(data);
            add->right->dad = add;
            lastInserted = add->right;
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
            lastInserted = add->left;
            if (add->right == NULL) {
                retorno = 1;
                add->NivelIzq = add->NivelIzq + 1;
            } else {
                if ((add->right->right != NULL) or (add->right->left != NULL)) {
                    retorno = 1;
                    add->NivelIzq = add->NivelIzq + 1;
                }
            }
            //  cout << " Hijo izq:" << add->left->getValueOfInt() << " Padre: " << add->left->dad->getValueOfInt() << endl;
            //   detectRotation(add);
        } else {
            int value = addInteger(add->left, data);
            retorno = value;
            add->NivelIzq = add->NivelIzq + value;
        }
    }
    return retorno;
}

void BinaryThreeForInt::insertarNodo(Nodo nodo) {
    if (raiz == NULL) {
        raiz = new Nodo(nodo);
        lastInserted = raiz;
        //    cout << "Ultimo valor insertado" << lastInserted->getValueOfInt() << endl;
    } else {
        addInteger(raiz, nodo.getValueOfInt());
        detectRotation(lastInserted->dad);
        //     cout << "Ultimo valor insertado" << lastInserted->getValueOfInt() << endl;
        //     cout << "Padre" << lastInserted->dad->getValueOfInt() << endl;
    }


    // detectRotation(lastInserted);
}

void BinaryThreeForInt::showIntegerThree() {
    if (raiz != NULL) {
        starPrint(raiz);
    }
}

void BinaryThreeForInt::starPrint(Nodo* father) {
    if (father != NULL) {
        cout << "Padre " << father->getValueOfInt() << endl;
        cout << " cant de hijos a la derecha " << father->NivelDer << endl;
        cout << " cant de hijos a la izquierda " << father->NivelIzq << endl;

        printLeft(father->left);
        printRight(father->right);

    }
}

void BinaryThreeForInt::printLeft(Nodo* izq) {
    if (izq != NULL) {
        cout << "       LEFT->" << izq->getValueOfInt() << endl;
        starPrint(izq);
    }
}

void BinaryThreeForInt::printRight(Nodo* der) {
    if (der != NULL) {
        cout << "       RIGHT->" << der->getValueOfInt() << endl;
        starPrint(der);
    }
}

int BinaryThreeForInt::detectRotation(Nodo* param) {
    int retorno = 0;
    if (param != NULL) {
        if (param->dad != NULL) {
            //if (param != raiz) {
            int iz = param->NivelIzq;
            int der = param->NivelDer;


            if ((der - iz) > 1) {
                Nodo *aux = param;
                param->dad->right = aux->right;
                param->right->dad = aux->dad;
                param->dad = aux->right;
                param->right->left = aux;
                param->right = NULL;
                param->dad->NivelIzq = iz + 1;
                param->dad->NivelDer = der - 1;
                param->NivelDer = 0;
                cout << "PADRE:" << param->dad->getValueOfInt() << endl;
                cout << "Hijo derecho :" << param->dad->right->getValueOfInt() << " " << param->dad->NivelDer << endl;
                cout << "Hijo derecho :" << param->dad->left->getValueOfInt() << " " << param->dad->NivelIzq << endl;

                // cout<<"Hijo izq :"<<param->dad->left.getValueOfInt()<<endl;
                //  param->dad->dad->NivelDer=param->dad->dad->NivelDer+retorno;

                if (param->dad->dad != NULL) {
                    Nodo* aux = param->dad->dad;
                    while (aux != NULL) {
                        aux->NivelDer = aux->NivelDer-1;
                        aux=aux->dad;
                    }
                }

            }

            detectRotation(param->dad);

            //}
        }
    }
    return retorno;
}

void BinaryThreeForInt::fixSize(Nodo* aux) {
    

}

void BinaryThreeForInt::SimpleRotationTurnLeft(Nodo *param) {


}

void BinaryThreeForInt::SimpleRotationTurnRight(Nodo *param) {

}