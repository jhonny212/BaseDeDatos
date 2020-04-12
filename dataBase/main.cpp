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


using namespace std;
void querys(int);
void createDatabase();
void menuSeleccion();
void insertar();
void reportes(int);
void select();
void split(string Linea, char Separador, vector<string> &TempBuff, int &TotalVector);
int Cuenta(string s, const char Separadorr, int &TotalChars);
void createTable();
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

void createDatabase() {
    /*string Palabra = "create table alumnos ( nombre int , edad int , apellido string );";
    cout << "Create table..." << endl;
    cin>> Palabra;
    getline(cin, Palabra);
    vector<string> TempBuff(0);
    int TotalVector;
    split(Palabra, *" ", TempBuff, TotalVector);
    string nameD = TempBuff[2];
    columnasData cd = columnasData();
    for (int i = 4; i < TotalVector - 1; i += 3) {
        cout << "creando columna" << endl;
        columna c = columna();
        c.name = TempBuff[i];
        c.type = TempBuff[i + 1];
        c.totalData = 0;
        cd.add(c);
    }
    Tabla tab = Tabla();
    tab.columns = cd;
    tab.nombre = nameD;
    bs = dataBase(tab, name);
    bs.nombreDeLaBaseDeDatos = name;
    bs.tabla.columns.count = 0;
    bs.valor = &(bs.tabla);*/
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
    switch (opc) {
        case 1:

            break;
        case 2:
            bs.totalDeDatos();
            break;
        case 3:
            bs.equalsCantTypeRowsForATable("alumnos");
            break;
        case 4:
            bs.cantOfColumns();
            break;
        case 5:
            break;
    }
}

void createTable() {
    //create table alumnos ( nombre int , edad int , apellido string );
    string Palabra;
    cout << "Create table..." << endl;
    cin>> Palabra;
    getline(cin, Palabra);
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

    while (opc != 5) {
        opc = msj.seleccion();
        switch (opc) {
            case 1:
                opc = msj.typeQuery();
                querys(opc);
                break;
            case 2:
                break;
            case 3:
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
    //baseDeDatosActual
    //insert into alumnos ( nombre , edad , apellido ) VALUES ( 20 , 26 , juan );
    /*string Palabra = "insert into alumnos ( nombre , edad , apellido ) VALUES ( 10 , 6 , juan );";
    cin>> Palabra;
    getline(cin, Palabra);
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

    int aux = distancia;
    int count = 0;
    for (int i = 4; i < TotalVector - 1; i += 2) {
        if (TempBuff[i] != "VALUES") {
            Tabla *auxD = bs.getT(nombreTabla);
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
    }*/

    string Palabra;
    cin>> Palabra;
    getline(cin, Palabra);
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

    int aux = distancia;
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
    string Palabra;
    //select *  from alumnos ;
    cin>> Palabra;
    getline(cin, Palabra);
    vector<string> TempBuff(0);
    int TotalVector;
    split(Palabra, *" ", TempBuff, TotalVector);

    string string2 = "WHERE";
    if (Palabra.find(string2) != string::npos) {
        cout << "found!" << '\n';
    } else {
        string tabla = TempBuff[TotalVector - 2];
        Tabla *auxD = baseDeDatosActual->getT(tabla);
        string param = "";
        int count = 0;
        if (TempBuff[1] == "*") {
            param = "*";
            string insertData;
            os.addC("*");
            for (int i = 0; i < auxD->columns.size + 1; i++) {
                insertData = auxD->columns.get(i);
                os.addC(insertData);
            }
            auxD->columns.buscarColumna("*", &os);
            auxD->columns.createDiagram(auxD->nombre);
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
            auxD->columns.buscarColumna(param, &os);
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