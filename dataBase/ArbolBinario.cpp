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

ArbolBinario::~ArbolBinario() {
}

ArbolBinario::ArbolBinario(Nodo* r, int _op) {
    raiz = r;
    opc = _op;
}

void ArbolBinario::print() {
    if (raiz != NULL) {
        string padre;
        if (opc == 1) {
            int i = raiz->getValueOfInt();
            padre = to_string(i);
        } else if (opc == 2) {
            padre = raiz->valorString;
        } else if (opc == 3) {
            padre = raiz->valorChar;
        } else if (opc == 4) {
            padre = to_string(raiz->valorDouble);
        }

        if (raiz->left != NULL) {
            string izq;
            if (opc == 1) {
                int j = raiz->left->getValueOfInt();
                izq = to_string(j);

            } else if (opc == 2) {
                izq = raiz->left->valorString;
            } else if (opc == 3) {
                izq = raiz->left->valorChar;
            } else if (opc == 4) {
                izq = to_string(raiz->left->valorDouble);
            }
            textoGrafica = textoGrafica + padre + " -> " + izq + " \n";
            cout << padre << " -> " << izq << endl;
        }

        if (raiz->right != NULL) {
            string der;

            if (opc == 1) {
                int k = raiz->right->getValueOfInt();
                der = to_string(k);

            } else if (opc == 2) {
                der = raiz->right->valorString;
            } else if (opc == 3) {
                der = raiz->right->valorChar;
            } else if (opc == 4) {
                der = to_string(raiz->right->valorDouble);
            }
            textoGrafica = textoGrafica + padre + " -> " + der + " \n";
            cout << padre << " -> " << der << endl;
        }
        if (raiz != NULL) {
            starPrint(raiz);
        }

        cout << textoGrafica << endl;
    }
}

void ArbolBinario::starPrint(Nodo* father) {
    if (father != NULL) {
        if (father->dad != NULL) {
            string padre;
            int opc = father->typodeSeleccion;

            if (opc == 1) {
                int i = father->getValueOfInt();
                padre = to_string(i);
            } else if (opc == 2) {
                padre = father->valorString;
            } else if (opc == 3) {
                padre = father->valorChar;
            } else if (opc == 4) {
                padre = to_string(father->valorDouble);
            }


            if (father->left != NULL) {
                string izq;
                if (opc == 1) {
                    int j = father->left->getValueOfInt();
                    izq = to_string(j);

                } else if (opc == 2) {
                    izq = father->left->valorString;
                } else if (opc == 3) {
                    izq = father->left->valorChar;
                } else if (opc == 4) {
                    izq = to_string(father->left->valorDouble);
                }
                textoGrafica = textoGrafica + padre + " -> " + izq + " \n";

                cout << padre << " -> " << izq << endl;
            }

            if (father->right != NULL) {
                string der;
                if (opc == 1) {
                    int k = father->right->getValueOfInt();
                    der = to_string(k);

                } else if (opc == 2) {
                    der = father->right->valorString;
                } else if (opc == 3) {
                    der = father->right->valorChar;
                } else if (opc == 4) {
                    der = to_string(father->right->valorDouble);
                }
                textoGrafica = textoGrafica + padre + " -> " + der + " \n";

                cout << padre << " -> " << der << endl;
            }

        }
        printLeft(father->left);
        printRight(father->right);
    }
}

void ArbolBinario::printLeft(Nodo* izq) {
    if (izq != NULL) {
        cout << izq->getValueOfInt() << endl;
        starPrint(izq);
    }
}

void ArbolBinario::printRight(Nodo* der) {
    if (der != NULL) {
        starPrint(der);
    }
}

