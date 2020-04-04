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

            } else {
                cout << add->left->NivelDer << endl;
                cout << add->left->NivelDer << endl;

                if (add->left->NivelDer != 0 or add->left->NivelIzq != 0) {
                    //   cout<<"ENTRO ACA RIGHT"<<add->right->getValueOfInt()<<endl;
                    retorno = 1;
                    add->NivelDer = add->NivelDer + 1;
                }
                if (add == raiz) {
                    retorno = 1;
                    add->NivelDer = add->NivelDer + 1;
                }
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

                if (add->right->NivelDer != 0 or add->right->NivelIzq != 0) {
                    retorno = 1;
                    add->NivelIzq = add->NivelIzq + 1;
                }
                if (add == raiz) {
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
        Nodo *aux = new Nodo();
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
        int iz = father->NivelIzq;
        int der = father->NivelDer;
        cout << "Padre " << father->getValueOfInt() << endl;
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
        }
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
        int iz = param->NivelIzq;
        int der = param->NivelDer;

        if (param->dad != NULL) {
            if ((der - iz) > 1) {
                if (param->right->left != NULL) {
                    RotationLeftRight(param);
                } else {
                    SimpleRotationTurnLeft(param);
                }
            } else if ((der - iz)<-1) {
                if (param->left->right != NULL) {
                    RotationRightLeft(param);
                } else {
                    SimpleRotationTurnRight(param);
                }
            }
            detectRotation(param->dad);
        } else if (param == raiz) {
            if ((der - iz) > 1) {
                if (param->right->left != NULL) {
                } else {
                }
            } else if ((der - iz)<-1) {
                if (param->left->right != NULL) {
                    RotationRightLeftType2(param);
                } else {
                }
            }
            //  detectRotation(param->dad);

            /* if ((der - iz) > 1) {
                   cout << iz <<" ACA " << endl;
          
             } else if ((der - iz)<-1) {
                             cout << iz <<" ACA2 " << endl;
          
             }*/
        }

    }
    return retorno;
}

void BinaryThreeForInt::SimpleRotationTurnLeft(Nodo *param) {
    int iz = param->NivelIzq;
    int der = param->NivelDer;
    /* Nodo Param
     * Param representa un hijo, el papa de este que apunta a el hijo cambiarlo al hijo derecho de param
     * Nodo param->Nodo hijo derecho-> para de hijo derecho es el papa de Nodo param
     * Ahora el papa de param es su hijo derecho
     * Hijo derecho de param hijo izq es param
     * Hjo derecho de paran se anula
     * Asignar Nivel de nodo
     */
    param->dad->right = param->right;
    param->right->dad = param->dad;
    param->dad = param->right;
    param->right->left = param;
    param->right = NULL;
    param->dad->NivelIzq = iz + 1;
    param->dad->NivelDer = der - 1;
    param->NivelDer = 0;
    
    if (param->dad->dad != NULL) {
        Nodo* aux = param->dad->dad;
        while (aux != NULL) {
            aux->NivelDer = aux->NivelDer - 1;
            aux = aux->dad;
        }
    }
}

void BinaryThreeForInt::SimpleRotationTurnRight(Nodo *param) {
    int iz = param->NivelIzq;
    int der = param->NivelDer;
    param->dad->left = param->left;
    param->left->dad = param->dad;
    param->dad = param->left;
    param->left->right = param;
    param->left = NULL;
    param->dad->NivelDer = der + 1;
    param->dad->NivelDer = iz - 1;
    param->NivelIzq = 0;

    if (param->dad->dad != NULL) {
        Nodo* aux = param->dad->dad;
        while (aux != NULL) {
            aux->NivelIzq = aux->NivelIzq - 1;
            aux = aux->dad;
        }
    }

}

void BinaryThreeForInt::RotationLeftRight(Nodo *param) {

    Nodo *N1 = param->dad;
    Nodo *N2 = param;
    Nodo *N3 = param->right;

    Nodo *N4 = param->right->left;

    N2->dad = N4;

    N3->dad = N4;

    N4->left = N2;
    N4->right = N3;

    N4->dad = N1;
    N1->right = N4;

    N2->right = NULL;
    N3->left = NULL;
    N2->NivelDer = 0;
    N3->NivelIzq = 0;

    N4->NivelIzq = N2->NivelIzq + 1;
    N4->NivelDer = N3->NivelDer + 1;

    Nodo *aux = param->dad->dad;

    N4 = NULL;
    N3 = NULL;
    N2 = NULL;
    N1 = NULL;


    while (aux != NULL) {
        aux->NivelDer = aux->NivelDer - 1;
        aux = aux->dad;
    }
}

void BinaryThreeForInt::RotationRightLeft(Nodo* param) {

    Nodo *N1 = param->dad;
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
    }
}

void BinaryThreeForInt::RotationRightLeftType2(Nodo* param) {
   
}