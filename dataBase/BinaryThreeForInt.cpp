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

            add->NivelDer = add->NivelDer + 1;

            if (add->left == NULL) {
                retorno = 1;
            }/* else {
                int DerLeft = add->left->NivelDer;
                int DerRight = add->left->NivelIzq;
                if (DerLeft == 0 && DerRight == 0) {
                    retorno = 0;
                } else {
                    retorno = 1;
                }

            }*/
        } else {

            retorno = addInteger(add->right, data);
            int x = add->right->NivelDer;
            int y = add->right->NivelIzq;
            if (x > y) {
                add->NivelDer = x + 1;
            } else if (x < y) {
                add->NivelDer = y + 1;
            } else if (x == y) {
                add->NivelDer = x + 1;
            }
            //  add->NivelDer = add->NivelDer + retorno;

        }
    } else {
        if (add->left == NULL) {
            add->left = new Nodo(data);
            add->left->dad = add;
            lastInserted = add->left;
            add->NivelIzq = add->NivelIzq + 1;

            if (add->right == NULL) {
                retorno = 1;
            } /*else {
                int DerLeft = add->right->NivelDer;
                int DerRight = add->right->NivelIzq;
                if (DerLeft == 0 && DerRight == 0) {
                    retorno = 0;
                } else {
                    retorno = 1;
                }
            }*/
        } else {
            retorno = addInteger(add->left, data);

            int x = add->left->NivelDer;
            int y = add->left->NivelIzq;
            if (x > y) {
                add->NivelIzq = x + 1;
            } else if (x < y) {
                add->NivelIzq = y + 1;
            } else if (x == y) {
                add->NivelIzq = x + 1;
            }
            // add->NivelIzq = add->NivelIzq + retorno;


        }
    }
    return retorno;
}

void BinaryThreeForInt::insertarNodo(Nodo nodo) {
    if (raiz == NULL) {
        raiz = new Nodo(nodo);
        lastInserted = raiz;
    } else {
        int x = addInteger(raiz, nodo.getValueOfInt());
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

        detectRotation(lastInserted->dad);

    }


}

void BinaryThreeForInt::showIntegerThree() {
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

void BinaryThreeForInt::starPrint(Nodo* father) {
    
    if (father != NULL) {
        int iz = father->NivelIzq;
        int der = father->NivelDer;

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
        /* cout << "Padre " << father->getValueOfInt() << endl;
         cout << " cant de hijos a la derecha " << der << endl;
         cout << " cant de hijos a la izquierda " << iz << endl;
         if (father->left != NULL) {
             cout << "        hijo izq " << father->left->getValueOfInt() << endl;
         } else {
             cout << "             No tiene izq" << endl;
         }
         if (father->right != NULL) {
             cout << "        hijo der " << father->right->getValueOfInt() << endl;
         } else {
             cout << "             No tiene der" << endl;
         }*/

        printLeft(father->left);
        printRight(father->right);


    }
}

void BinaryThreeForInt::printLeft(Nodo* izq) {
    if (izq != NULL) {
        starPrint(izq);
    }
}

void BinaryThreeForInt::printRight(Nodo* der) {
    if (der != NULL) {
        starPrint(der);
    }
}

int BinaryThreeForInt::detectRotation(Nodo* param) {
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

void BinaryThreeForInt::SimpleRotationTurnLeft(Nodo *param) {
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

void BinaryThreeForInt::SimpleRotationTurnRight(Nodo *param) {
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

void BinaryThreeForInt::FixLevelNodo(Nodo* param) {
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
}

void BinaryThreeForInt::RotationLeftRight(Nodo *param) {

    //    Nodo *n1 = param;
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

void BinaryThreeForInt::RotationRightLeft(Nodo* param) {

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
    /* Nodo *N1 = param->dad;
     Nodo *N2 = param;
     Nodo *N3 = param->left;
     Nodo *N4 = param->left->right;

     N2->dad = N4;

     N3->dad = N4;

     N4->left = N3;
     N4->right = N2;

     N4->dad = N1;
     N1->left = N4;

     N2->left = NULL;
     N3->right = NULL;
     N2->NivelIzq = 0;
     N3->NivelDer = 0;


     N4->NivelIzq = N3->NivelIzq + 1;
     N4->NivelDer = N2->NivelDer + 1;
     N4 = NULL;
     N3 = NULL;
     N2 = NULL;

     N1 = NULL;
     Nodo *aux = param->dad->dad;

     while (aux != NULL) {
         aux->NivelIzq = aux->NivelIzq - 1;
         aux = aux->dad;
     }*/
}

