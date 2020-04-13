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
    TamanoArbol = 0;
    raiz = NULL;
    lastInserted = NULL;
    textoGrafica = "";
    isEmpty = false;
    opc = 0;
    contador = 0;
    estruct = "";
    contarNodos = 0;
    txtGraficaTmp = "";
}

BinaryThreeForInt::~BinaryThreeForInt() {
    if (raiz != NULL) {
        eliminarNodo(raiz);
    }
}

void BinaryThreeForInt::eliminarNodo(Nodo* param) {
    if (param->left != NULL) {
        eliminarNodo(param->left);
    } else {
        if (param->dad != NULL) {
            param->dad = NULL;
      }
        delete param;
    }
    if (param->right != NULL) {
        eliminarNodo(param->right);
    } else {
        if (param->dad != NULL) {
            param->dad = NULL;
        }
        delete param;
    }
}

string BinaryThreeForInt::showIntegerThree(int opc) {
    contador = 0;
    txtGraficaTmp = "\n";
    if (raiz != NULL) {
        string padre = to_string(raiz->claveGenerada);
        if (opc == 1) {
            int i = raiz->getValueOfInt();
            //padre = to_string(i);
        } else if (opc == 2) {
            //padre = raiz->valorString;
        } else if (opc == 3) {
            //padre = raiz->valorChar;
        } else if (opc == 4) {
            //padre = to_string(raiz->valorDouble);
        }
        if (raiz->left != NULL) {
            string izq = to_string(raiz->left->claveGenerada);
            txtGraficaTmp += "node" + padre + " -> node" + izq + " ;";

            if (opc == 1) {
                int j = raiz->left->getValueOfInt();
                //izq = to_string(j);

            } else if (opc == 2) {
                //izq = raiz->left->valorString;
            } else if (opc == 3) {
                //izq = raiz->left->valorChar;
            } else if (opc == 4) {
                //izq = to_string(raiz->left->valorDouble);
            }


            /*string count = to_string(contador + 1);
            textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + izq + "] \n";
            string count2 = to_string(contador);
            textoGrafica += "node" + count2 + " -> node" + count + ";\n";*/
        }

        if (raiz->right != NULL) {
            string der = to_string(raiz->right->claveGenerada);
            txtGraficaTmp += "node" + padre + " -> node" + der + " ;";

            if (opc == 1) {
                int k = raiz->right->getValueOfInt();
                //der = to_string(k);

            } else if (opc == 2) {
                //der = raiz->right->valorString;
            } else if (opc == 3) {
                //der = raiz->right->valorChar;
            } else if (opc == 4) {
                //der = to_string(raiz->right->valorDouble);
            }
            /*string count = to_string(contador + 2);
            textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + der + "] \n";
            string count2 = to_string(contador);
            textoGrafica += "node" + count2 + " -> node" + count + ";\n";*/
        }
        if (raiz != NULL) {
            starPrint(raiz);
        }
        // cout << textoGrafica << "\n" << txtGraficaTmp << endl;
    }
    return (textoGrafica + txtGraficaTmp);
}

void BinaryThreeForInt::starPrint(Nodo* father) {
    if (father != NULL) {
        if (father->dad != NULL) {
            string padre = to_string(father->claveGenerada);
            int opc = father->typodeSeleccion;

            if (opc == 1) {
                int i = father->getValueOfInt();
                //padre = to_string(i);
            } else if (opc == 2) {
                //padre = father->valorString;
            } else if (opc == 3) {
                //padre = father->valorChar;
            } else if (opc == 4) {
                //padre = to_string(father->valorDouble);
            }
            if (father->left != NULL) {
                string izq = to_string(father->left->claveGenerada);
                txtGraficaTmp += "node" + padre + " -> node" + izq + " ; \n";

                if (opc == 1) {
                    int j = father->left->getValueOfInt();
                    //izq = to_string(j);

                } else if (opc == 2) {
                    //izq = father->left->valorString;
                } else if (opc == 3) {
                    //izq = father->left->valorChar;
                } else if (opc == 4) {
                    //izq = to_string(father->left->valorDouble);
                }
                /*string count = to_string(contador + 1);
                textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + izq + "] \n";
                string count2 = to_string(contador);
                textoGrafica += "node" + count2 + " -> node" + count + ";\n";*/


            }

            if (father->right != NULL) {

                string der = to_string(father->right->claveGenerada);
                txtGraficaTmp += "node" + padre + " -> node" + der + " ; \n";

                if (opc == 1) {
                    int k = father->right->getValueOfInt();
                    //der = to_string(k);

                } else if (opc == 2) {
                    //der = father->right->valorString;
                } else if (opc == 3) {
                    //der = father->right->valorChar;
                } else if (opc == 4) {
                    //der = to_string(father->right->valorDouble);
                }
                /*string count = to_string(contador + 1);
                textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + der + "] \n";
                string count2 = to_string(contador);
                textoGrafica += "node" + count2 + " -> node" + count + ";\n";*/
            }

        }
        printLeft(father->left);
        printRight(father->right);
    }
}

void BinaryThreeForInt::printLeft(Nodo* izq) {
    if (izq != NULL) {
        //cout << izq->getValueOfInt() << endl;
        starPrint(izq);
    }
}

void BinaryThreeForInt::printRight(Nodo* der) {
    if (der != NULL) {
        starPrint(der);
    }
}

void BinaryThreeForInt::setString(string nuevotxt) {
    textoGrafica = nuevotxt;
}

void BinaryThreeForInt::insertarNodo(Nodo nodo) {
    contarNodos++;
    string count;
    string dato;
    count = to_string(contarNodos);

    if (raiz == NULL) {
        switch (nodo.typodeSeleccion) {
            case 1:
                raiz = new Nodo(nodo.getValueOfInt());
                raiz->nombreDeColumna = nodo.nombreDeColumna;
                raiz->claveGenerada = contarNodos;
                dato = to_string(nodo.getValueOfInt());
                textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";

                break;
            case 2:
                raiz = new Nodo(nodo.valorString);
                raiz->nombreDeColumna = nodo.nombreDeColumna;
                raiz->claveGenerada = contarNodos;
                dato = nodo.valorString;
                textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";


                break;
            case 3:
                raiz = new Nodo(nodo.valorChar);
                raiz->nombreDeColumna = nodo.nombreDeColumna;
                raiz->claveGenerada = contarNodos;

                dato = nodo.valorChar;
                textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";

                break;
            case 4:
                raiz = new Nodo(nodo.valorDouble);
                raiz->nombreDeColumna = nodo.nombreDeColumna;
                raiz->claveGenerada = contarNodos;

                dato = to_string(nodo.valorDouble);
                textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";

                break;
        }
        lastInserted = raiz;

    } else {
        contarNodos++;
        addInteger(raiz, nodo);
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

int BinaryThreeForInt::addInteger(Nodo* add, Nodo data) {
    string count;
    string dato;
    count = to_string(contarNodos);

    int valor1 = add->valueToCompare;
    int retorno = 0;
    if (data.valueToCompare > valor1) {
        if (add->right == NULL) {
            switch (data.typodeSeleccion) {
                case 1:
                    add->right = new Nodo(data.getValueOfInt());
                    add->right->nombreDeColumna = data.nombreDeColumna;
                    add->right->claveGenerada = contarNodos;

                    dato = to_string(data.valorInt);
                    textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";


                    break;
                case 2:
                    add->right = new Nodo(data.valorString);
                    add->right->nombreDeColumna = data.nombreDeColumna;
                    add->right->claveGenerada = contarNodos;

                    dato = data.valorString;
                    textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";


                    break;
                case 3:
                    add->right = new Nodo(data.valorChar);
                    add->right->nombreDeColumna = data.nombreDeColumna;
                    add->right->claveGenerada = contarNodos;

                    dato = data.valorChar;
                    textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";


                    break;
                case 4:
                    add->right = new Nodo(data.valorDouble);
                    add->right->nombreDeColumna = data.nombreDeColumna;
                    add->right->claveGenerada = contarNodos;

                    dato = to_string(data.valorDouble);
                    textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";


                    break;
            }
            add->right->dad = add;
            lastInserted = add->right;

            add->NivelDer = add->NivelDer + 1;

            if (add->left == NULL) {
                retorno = 1;
            }
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
        }
    } else {
        if (add->left == NULL) {

            switch (data.typodeSeleccion) {
                case 1:
                    add->left = new Nodo(data.getValueOfInt());
                    add->left->nombreDeColumna = data.nombreDeColumna;
                    add->left->claveGenerada = contarNodos;

                    dato = to_string(data.valorInt);
                    textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";

                    break;
                case 2:

                    add->left = new Nodo(data.valorString);
                    add->left->nombreDeColumna = data.nombreDeColumna;
                    add->left->claveGenerada = contarNodos;

                    dato = data.valorString;
                    textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";

                    break;
                case 3:
                    add->left = new Nodo(data.valorChar);
                    add->left->nombreDeColumna = data.nombreDeColumna;
                    add->left->claveGenerada = contarNodos;

                    dato = data.valorChar;
                    textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";


                    break;
                case 4:
                    add->left = new Nodo(data.valorDouble);
                    add->left->nombreDeColumna = data.nombreDeColumna;
                    add->left->claveGenerada = contarNodos;

                    dato = to_string(data.valorDouble);
                    textoGrafica += "node" + count + " [fillcolor=yellow, style=\"rounded,filled\", shape=circle, label=" + dato + "] \n";

                    break;
            }

            add->left->dad = add;
            lastInserted = add->left;
            add->NivelIzq = add->NivelIzq + 1;

            if (add->right == NULL) {
                retorno = 1;
            }
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
        }
    }
    return retorno;

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

void BinaryThreeForInt::SimpleRotationTurnLeft(Nodo* param) {
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

void BinaryThreeForInt::SimpleRotationTurnRight(Nodo* param) {
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

void BinaryThreeForInt::RotationLeftRight(Nodo* param) {
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
