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
    factorVariador = 0;
}

TablaHash::~TablaHash() {
    if (start != NULL) {
        while (start != NULL) {
            Table *tmp = (start + 4);
            for (int i = 0; i < 3; i++) {
                delete (start + i);
            }
            start = tmp;
        }
    }
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
        obj[i].arbolInt.contarNodos = ((i + 10)*5);
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
    next->tablaSiguiente = NULL;
    //start->tablaSiguiente=next;
    //(start + 4)->tablaSiguiente = next;
    // (start + 4)->tablaSiguiente = next;
}

string TablaHash::paintPosicion(string x, string paramname) {
    Table *tmp = start;
    string txtT = "";
    string param = to_string((factorVariador * 2));
    string txt = " node [shape=record]; \n";
    txt += "struct" + param + " [label=\" ";
    string getpaint = "";
    string txtAux = "";
    int cont = 1;
    string key = "";

    for (int j = 0; j < size; j++) {
        Table t = Table();
        for (int i = 0; i < 5; i++) {
            key = to_string(cont);
            txtAux += "<f" + key + "> " + key + " |";
            
            if ((tmp + i)->arbolInt.raiz != NULL) {

                t = *(tmp + i);
                if (x == "string") {
                    getpaint += ((tmp + i)->arbolInt.showIntegerThree(2));
                    int aux = ((tmp + i)->arbolInt.raiz->claveGenerada);
                    key = to_string(aux);
                    string keyAux = to_string(cont);
                    txtT += "struct" + param + ":f" + keyAux + " -> node" + key + "; \n";

                } else if (x == "char") {
                    getpaint += ((tmp + i)->arbolInt.showIntegerThree(3));
                    int aux = ((tmp + i)->arbolInt.raiz->claveGenerada);
                    key = to_string(aux);
                    string keyAux = to_string(cont);
                    txtT += "struct" + param + ":f" + keyAux + " -> node" + key + "; \n";

                } else if (x == "double") {
                    getpaint += ((tmp + i)->arbolInt.showIntegerThree(4));
                    int aux = ((tmp + i)->arbolInt.raiz->claveGenerada);
                    key = to_string(aux);
                    string keyAux = to_string(cont);
                    txtT += "struct" + param + ":f" + keyAux + " -> node" + key + "; \n";


                } else if (x == "int") {
                    getpaint += ((tmp + i)->arbolInt.showIntegerThree(1));
                    int aux = ((tmp + i)->arbolInt.raiz->claveGenerada);
                    key = to_string(aux);
                    string keyAux = to_string(cont);
                    txtT += "struct" + param + ":f" + keyAux + " -> node" + key + "; \n";
                }

            }
            cont++;
        }
        /*if ((start)->tablaSiguiente != NULL) {
            (tmp) = (tmp->tablaSiguiente);
          
        } else {
            cout << " vacio " << endl;
        }*/

    }
    txt += txtAux + " <f0> " + paramname + " \"]; \n ";
    txt += getpaint;
    txt += txtT;
    //string print = "digraph G \n {\n" + txt + " \n}";
    return txt;
}

void TablaHash::searchDataForCond(seleccion* cd) {
    for (int i = 0; i < cd->tm; i++) {

    }

}

void TablaHash::searchData(string column, seleccion* cd, bool isAll) {
    Table *tmp = start;
    Table *aux = NULL;
    Nodo *getStart = NULL;
    Nodo *encolaAux = NULL;
    int longitud = 0;
    int tmDatos = 0;
    seleccion datosGet = seleccion();
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < 5; i++) {
            if ((tmp + i)->arbolInt.raiz != NULL) {
                Table t = Table();
                t = *(tmp + i);
                getStart = t.href;
                encolaAux = t.inicio;
                bool valid = true;
                while (valid) {
                    while (true) {
                        if (getStart->nodoPrevio != NULL) {
                            getStart = getStart->nodoPrevio;
                        } else {
                            break;
                        }
                    }
                    bool v = true;
                    int k = 0;
                    if (isAll) {
                        k = 1;
                    }
                    while (v) {
                        string nam = cd->get(k);
                        Nodo *aux = getStart;
                        string valor;
                        v = true;
                        while (v) {
                            int opc = aux->typodeSeleccion;

                            if (nam == aux->nombreDeColumna) {

                                tmDatos++;
                                if (opc == 1) {
                                    valor = to_string(aux->valorInt);
                                    datosGet.addC(valor);
                                    cout << "|" << aux->valorInt << "      |";

                                } else if (opc == 2) {
                                    cout << "|" << aux->valorString << "      |";
                                    valor = aux->valorString;
                                    datosGet.addC(valor);
                                } else if (opc == 3) {
                                    cout << "|" << aux->valorChar << "      |";
                                    valor = aux->valorChar;
                                    datosGet.addC(valor);
                                } else if (opc == 4) {
                                    cout << "|" << aux->valorDouble << "      |";
                                    valor = to_string(aux->valorDouble);
                                    datosGet.addC(valor);

                                }
                            }
                            if (aux->nodoSiguiente != NULL) {
                                aux = aux->nodoSiguiente;
                            } else {
                                v = false;
                            }
                        }
                        v = true;
                        if (getStart->nodoSiguiente != NULL) {
                            getStart = getStart->nodoSiguiente;
                        } else {
                            v = false;
                        }
                        k++;
                    }
                    cout << "\n " << endl;
                    longitud += 1;
                    if (encolaAux != NULL) {
                        getStart = encolaAux;
                        encolaAux = encolaAux->encolado;
                    } else {
                        valid = false;
                    }
                }
            }
        }
        tmp = tmp->tablaSiguiente;
    }
    cout << " ------------------------------------------------------------------------" << endl;
}

void TablaHash::buscarData(int indice, int tipo_, string valor, seleccion* cd2) {
    Table *aux = NULL;
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
    Nodo *encolado = aux->href;
    Nodo *getS = aux->inicio;
    while (encolado != NULL) {

        if (tipo_ == 1) {
            if (encolado->valorString == valor) {
                Nodo *temporal = encolado;
                while (temporal != NULL) {
                    if (temporal->nodoPrevio == NULL) {
                        break;
                    } else {
                        temporal = temporal->nodoPrevio;
                    }
                }
                while (temporal != NULL) {
                    int tipo = temporal->typodeSeleccion;
                    switch (tipo) {
                        case 1:
                            cout << "|" << temporal->valorInt << "      |";

                            break;
                        case 2:
                            cout << "|" << temporal->valorString << "      |";

                            break;
                        case 3:
                            cout << "|" << temporal->valorChar << "      |";

                            break;
                        case 4:
                            cout << "|" << temporal->valorDouble << "      |";
                            break;

                    }
                    if (temporal->nodoSiguiente != NULL) {
                        temporal = temporal->nodoSiguiente;
                    } else {
                        break;
                    }
                }

            }
        } else if (tipo_ == 2) {
            string saux(1, encolado->valorChar);
            if (saux == valor) {
                Nodo *temporal = encolado;
                while (temporal != NULL) {
                    if (temporal->nodoPrevio == NULL) {
                        break;
                    } else {
                        temporal = temporal->nodoPrevio;
                    }
                }
                while (temporal != NULL) {
                    int tipo = temporal->typodeSeleccion;
                    switch (tipo) {
                        case 1:
                            cout << "|" << temporal->valorInt << "      |";

                            break;
                        case 2:
                            cout << "|" << temporal->valorString << "      |";

                            break;
                        case 3:
                            cout << "|" << temporal->valorChar << "      |";

                            break;
                        case 4:
                            cout << "|" << temporal->valorDouble << "      |";
                            break;

                    }
                    if (temporal->nodoSiguiente != NULL) {
                        temporal = temporal->nodoSiguiente;
                    } else {
                        break;
                    }
                }

            }

        } else if (tipo_ == 3) {
            string saux = to_string(encolado->valorInt);
            if (saux == valor) {
                Nodo *temporal = encolado;
                while (temporal != NULL) {
                    if (temporal->nodoPrevio == NULL) {
                        break;
                    } else {
                        temporal = temporal->nodoPrevio;
                    }
                }
                while (temporal != NULL) {
                    int tipo = temporal->typodeSeleccion;
                    switch (tipo) {
                        case 1:
                            cout << "|" << temporal->valorInt << "      |";

                            break;
                        case 2:
                            cout << "|" << temporal->valorString << "      |";

                            break;
                        case 3:
                            cout << "|" << temporal->valorChar << "      |";

                            break;
                        case 4:
                            cout << "|" << temporal->valorDouble << "      |";
                            break;

                    }
                    if (temporal->nodoSiguiente != NULL) {
                        temporal = temporal->nodoSiguiente;
                    } else {
                        break;
                    }
                }

            }

        } else if (tipo_ == 4) {
            string saux = to_string(encolado->valorDouble);
            if (saux == valor) {
                Nodo *temporal = encolado;
                while (temporal != NULL) {
                    if (temporal->nodoPrevio == NULL) {
                        break;
                    } else {
                        temporal = temporal->nodoPrevio;
                    }
                }
                while (temporal != NULL) {
                    int tipo = temporal->typodeSeleccion;
                    switch (tipo) {
                        case 1:
                            cout << "|" << temporal->valorInt << "      |";

                            break;
                        case 2:
                            cout << "|" << temporal->valorString << "      |";

                            break;
                        case 3:
                            cout << "|" << temporal->valorChar << "      |";

                            break;
                        case 4:
                            cout << "|" << temporal->valorDouble << "      |";
                            break;

                    }
                    if (temporal->nodoSiguiente != NULL) {
                        temporal = temporal->nodoSiguiente;
                    } else {
                        break;
                    }
                }

            }
        }
        if (getS != NULL) {
            encolado = getS;
            getS = getS->encolado;
        } else {
            break;
        }
        cout << "\n";
    }

}

Nodo* TablaHash::insertData(int indice, int tipo_, string valor, string nombreColumna, int numeroOfNodo) {
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

            if (tipo_ == 1) {
                nodoSave = Nodo(valor);
                nodoSave.nombreDeColumna = nombreColumna;
                aux->arbolInt.contarNodos += numeroOfNodo;
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
                nodoSave.nombreDeColumna = nombreColumna;
                aux->arbolInt.contarNodos = numeroOfNodo;
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
                nodoSave.nombreDeColumna = nombreColumna;
                aux->arbolInt.contarNodos = numeroOfNodo;
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
                nodoSave.nombreDeColumna = nombreColumna;
                aux->arbolInt.contarNodos = numeroOfNodo;
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

    float alter = (datasInsert * 100 / (size * 5));


    if (alter >= 20) {
       // makeRehashing();

    }

    return aux->arbolInt.lastInserted;
}