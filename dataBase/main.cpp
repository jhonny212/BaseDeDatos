/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: jhonny
 *
 * Created on 1 de abril de 2020, 11:22 AM
 */
#include <cstdlib>
#include <math.h>
#include <iostream>
#include "mensajes.h"
#include <stdio.h>
#include <string.h> 
#include <math.h>  
#include <time.h> 
#include "ArbolBinario.h"
#include "BinaryThreeForInt.h"
#include "columnasData.h"
#include <vector>
#include <fstream>
#include "dataBase.h"
#include "Tabla.h"
#include "TablaHash.h"
#include "hashFunctions.h"
#include "seleccion.h"
#include "Data.h"
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;
void querys(int);
void createDatabase();
void menuSeleccion();
void insertar();
void reportes(int);
void select();
void addColumn();
void split(string Linea, char Separador, vector<string> &TempBuff, int &TotalVector);
int Cuenta(string s, const char Separadorr, int &TotalChars);
void createTable();
string getTime();
dataBase bs;
dataBase *baseDeDatosActual;

string name;
Data controlDeBaseDeDatos;
string nombreDeBase;

int main() {

    controlDeBaseDeDatos = Data();
    mensajes msj = mensajes();
    msj.welcome();
    bool querys = true;
    while (querys) {
        int opc = msj.opcion();
        switch (opc) {
            case 1:
                cout << "Escriba el nombre de las base de datos" << endl;
                cin>>name;
                createDatabase();
                break;
            case 2:
                cout << "Ingrese el nombre de la base de datos a accede" << endl;
                cin>>nombreDeBase;
                baseDeDatosActual = controlDeBaseDeDatos.get(nombreDeBase);
                if (baseDeDatosActual == NULL) {
                    cout << " No se encontro la base de datos " << endl;
                } else {
                    menuSeleccion();
                }
                break;
            case 3:
                querys = false;
                break;
            default:
                break;
        }
    }
}

string getTime() {
    string tmp = "";
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();

    tmp = str;
    return tmp;
}

void createDatabase() {
    string Palabra;
    cout << "Create data base..." << endl;
    cin>> Palabra;
    getline(cin, Palabra);
    vector<string> TempBuff(0);
    int TotalVector;
    split(Palabra, *" ", TempBuff, TotalVector);
    string nameD = TempBuff[1];
    controlDeBaseDeDatos.add(nameD);

}

void reportes(int opc) {
    string param;
    int total = 0;
    switch (opc) {
        case 1:
            cout << "******************************************" << endl;
            total = controlDeBaseDeDatos.cantDatos();
            cout << " en total hay " << total << " datos ingresados " << endl;
            cout << "******************************************" << endl;
            break;
        case 2:
            baseDeDatosActual->totalDeDatos();
            break;
        case 3:
            cout << "*************Ingrese la tabla ****************" << endl;
            cin>>param;
            baseDeDatosActual->equalsCantTypeRowsForATable(param);
            cout << "*************************************" << endl;

            break;
        case 4:
            cout << "*************************************" << endl;
            baseDeDatosActual->cantOfColumns();
            cout << "*************************************" << endl;
            break;
        case 5:
            cout << "***************LOG*******************" << endl;
            cout << "Base de dato: " << baseDeDatosActual->nombreDeLaBaseDeDatos << endl;
            cout << baseDeDatosActual->archivoLog << endl;
            break;
    }
}

void createTable() {
    string Palabra;
    cout << "Create table..." << endl;
    cin>> Palabra;
    getline(cin, Palabra);
    baseDeDatosActual->archivoLog += "Creacion de tabla \n";
    baseDeDatosActual->archivoLog += "    " + Palabra + " fecha: " + getTime() + "\n";

    vector<string> TempBuff(0);
    int TotalVector;
    split(Palabra, *" ", TempBuff, TotalVector);
    string nameD = TempBuff[2];
    columnasData cd = columnasData();
    for (int i = 4; i < TotalVector - 1; i += 3) {
        cout << "\n " << endl;
        columna c = columna();
        c.name = TempBuff[i];
        c.type = TempBuff[i + 1];
        c.totalData = 0;
        cd.add(c);
    }
    baseDeDatosActual->addTable(cd, nameD);
}

void menuSeleccion() {
    mensajes msj = mensajes();
    int opc = 0;
    int opc2 = 0;
    while (opc != 5) {
        opc = msj.seleccion();
        switch (opc) {
            case 1:
                opc = msj.typeQuery();
                querys(opc);
                break;
            case 2:
                opc2 = msj.reportes();
                reportes(opc2);
                break;
            case 3:
                cout << "ingrese en nombre de la tabla " << endl;
                addColumn();
                break;
            case 4:
                createTable();
                break;
            case 5:
                break;
            default:
                opc = 10;
                break;
        }
    }

}

void addColumn() {
    string tab;
    string col;
    string typ;
    cin>>tab;
    Tabla *auxD = baseDeDatosActual->getT(tab);
    cout << " ingrese el nombre de la columna " << endl;
    cin>>col;
    cout << " ingrese el tipo de dato" << endl;
    cin>>typ;
    baseDeDatosActual->archivoLog += "Agregando columna a tabla " + auxD->nombre + " \n";
    baseDeDatosActual->archivoLog += "    Columna: " + col + " Tipo: " + typ + "\n";

    columna c = columna();
    c.name = col;
    c.type = typ;
    c.totalData = 0;
    auxD->columns.add(c);
}

void querys(int opc) {
    cout << "Inserte el query" << endl;
    switch (opc) {
        case 1:
            select();
            break;
        case 2:
            insertar();
            break;
        default:
            break;
    }
}

void insertar() {
    Nodo *tmP = NULL;
    Nodo *tmP2 = NULL;
    string Palabra;
    cin>> Palabra;
    getline(cin, Palabra);
    baseDeDatosActual->archivoLog += "Insert: \n";
    baseDeDatosActual->archivoLog += "   " + Palabra + " Fecha: " + getTime() + " \n";

    vector<string> TempBuff(0);
    int TotalVector;
    split(Palabra, *" ", TempBuff, TotalVector);
    int distancia;
    for (int i = 4; i < TotalVector; i++) {
        if (TempBuff[i] == "(") {
            distancia = i;
        }
    }
    string nombreTabla = TempBuff[2];

    int count = 0;
    for (int i = 4; i < TotalVector - 1; i += 2) {
        if (TempBuff[i] != "VALUES") {
            Tabla *auxD = baseDeDatosActual->getT(nombreTabla);
            if (count == 0) {
                tmP = auxD->columns.insertarEnColumna(TempBuff[i], TempBuff[distancia + 1]);
            } else {
                tmP2 = auxD->columns.insertarEnColumna(TempBuff[i], TempBuff[distancia + 1]);
                tmP2->nodoPrevio = tmP;
                tmP->nodoSiguiente = tmP2;
                tmP = tmP2;
            }
            count += 1;
            distancia += 2;
        } else {
            break;
        }
    }
}

void select() {
    seleccion os = seleccion();
    seleccion os2 = seleccion();

    bool v = false;
    string Palabra;
    cin>> Palabra;
    getline(cin, Palabra);
    baseDeDatosActual->archivoLog += "Select : \n";

    baseDeDatosActual->archivoLog += "   " + Palabra + " Fecha: " + getTime();

    vector<string> TempBuff(0);
    int TotalVector;
    split(Palabra, *" ", TempBuff, TotalVector);

    string string2 = "WHERE";
    string tipocon = "";
    if (Palabra.find(string2) != string::npos) {
        for (int i = 1; i < TotalVector; i++) {
            if (v) {
                os2.addD(TempBuff[i], TempBuff[i + 1], TempBuff[i + 2]);
                if (TempBuff[i + 3] == ";") {
                    break;
                } else {
                    i += 3;
                }

            }
            if (TempBuff[i] == "WHERE" or TempBuff[i] == "where") {
                v = true;
            }

            if (TempBuff[i] == "and" or TempBuff[i] == "AND") {
                tipocon = "and";
            } else if (TempBuff[i] == "or" or TempBuff[i] == "OR") {
                tipocon = "or";
            }
        }
        os2.tipoDeCondicion = tipocon;
    }
    string tabla = TempBuff[3];
    Tabla *auxD = baseDeDatosActual->getT(tabla);
    string param = "";
    int count = 0;
    if (TempBuff[1] == "*") {
        param = "*";
        string insertData;
        os.addC("*");
        for (int i = 1; i < auxD->columns.size + 1; i++) {
            insertData = auxD->columns.get(i);
            os.addC(insertData);
        }
        auxD->columns.buscarColumna("*", &os, &os2, v);
        if (!v) {
            auxD->columns.createDiagram(auxD->nombre, &os);
        }
    } else {
        for (int i = 1; i < TotalVector; i++) {
            if (TempBuff[i] != "FROM" && TempBuff[i] != "from") {
                if (TempBuff[i] != ",") {
                    if (count == 0) {
                        param = TempBuff[i];
                        count++;
                    }
                    os.addC(TempBuff[i]);
                }
            } else {
                break;
            }
        }
        auxD->columns.buscarColumna(param, &os, &os2, v);
        if (!v) {
            auxD->columns.createDiagram(auxD->nombre, &os);
        }
    }

}

void split(string Linea, char Separador, vector<string> &TempBuff, int &TotalVector) {
    TempBuff.resize(0);
    TotalVector = 0;
    int Nums = -1;
    int NumPos = -1;
    int ValorNum = 0;
    int TotalChars = 0;
    int TotalEspacios = Linea.length();
    string Valor;
    int size = 0;
    Cuenta(Linea, Separador, TotalChars);
    if (TotalChars != 0) {
        while (Nums < TotalChars) {
            Nums++;
            ValorNum = Linea.find(Separador, NumPos + 1);
            Valor = Linea.substr(NumPos + 1, ValorNum);
            Valor = Valor.substr(0, Valor.find_first_of(Separador));
            TempBuff.push_back(Valor);
            size = size + 1;
            NumPos = ValorNum;
            TotalEspacios++;
        }
        TotalVector = size;
    } else {
        TotalVector = 0;
    }
}

int Cuenta(string s, const char Separadorr, int &TotalChars) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] == Separadorr) TotalChars++;
}