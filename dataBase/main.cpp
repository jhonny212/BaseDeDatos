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

using namespace std;
void querys(int);
void createDatabase();
void menuSeleccion();
void insertar();

void select();
void split(string Linea, char Separador, vector<string> &TempBuff, int &TotalVector);
int Cuenta(string s, const char Separadorr, int &TotalChars);
dataBase bs;
string name;

int main() {
    cout << "Escriba el nombre de las base de datos" << endl;
    cin>>name;
    createDatabase();
    insertar();
   // select();
    /*cout << "Escriba el nombre de las base de datos" << endl;
    cin>>name;
    createDatabase();
    insertar();
    insertar();
    insertar();*/



    //ArbolBinario t = ArbolBinario((tmp+3)->arbolInt.raiz,4);
    //t.print();

    //(tmp+3)->arbolInt.showIntegerThree(4);
    // ((bs.tabla.columns.valor->column.tablaHash.start->tablaSiguiente)+3)->arbolInt.showIntegerThree(4);
    /*mensajes msj = mensajes();
      msj.welcome();
      int opc = msj.opcion();
      switch (opc) {
          case 1:
              cout << "Escriba el nombre de las base de datos" << endl;
              cin>>name;
              createDatabase();
             // insertar();
             //  insertar();
              break;
          case 2:
              break;
          case 3:
              break;
          default:
              break;
      }*/
}

void createDatabase() {
    string Palabra = "create table alumnos ( nombre double , edad double );";
    cout << "Create table..." << endl;
    // cin>> Palabra;
    // getline(cin, Palabra);
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
        cd.add(c);

    }
    Tabla tab = Tabla();
    tab.columns = cd;
    tab.nombre = name;
    bs = dataBase(tab, name);


}

void menuSeleccion() {
    mensajes msj = mensajes();
    int opc = 0;

    while (opc != 4) {
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
        }
    }

}

void querys(int opc) {
    cout << "Inserte el query" << endl;
    switch (opc) {
        case 1:
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

    string Palabra = "insert into alumnos ( nombre , edad ) VALUES ( 10.2 , 9.2 );";
    //cin>> Palabra;
    // getline(cin, Palabra);
    vector<string> TempBuff(0);
    int TotalVector;
    split(Palabra, *" ", TempBuff, TotalVector);
    int distancia;
    for (int i = 4; i < TotalVector; i++) {
        if (TempBuff[i] == "(") {
            distancia = i;
        }
    }
    int aux = distancia;
    int count = 0;
    for (int i = 4; i < TotalVector - 1; i += 2) {
        if (TempBuff[i] != "VALUES") {

            if (count == 0) {
                tmP = bs.tabla.columns.insertarEnColumna(TempBuff[i], TempBuff[distancia + 1]);

            } else {
                tmP2 = bs.tabla.columns.insertarEnColumna(TempBuff[i], TempBuff[distancia + 1]);
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
    distancia = aux;
}

void select() {
    columnasData cd=columnasData();
    
    string Palabra = "select nombre , edad from alumnos ;";
    //cin>> Palabra;
    // getline(cin, Palabra);
    vector<string> TempBuff(0);
    int TotalVector;
    split(Palabra, *" ", TempBuff, TotalVector);

    string string2 = "WHERE";
    if (Palabra.find(string2) != string::npos) {
        cout << "found!" << '\n';
    } else {
        string tabla = TempBuff[TotalVector - 2];

        if (TempBuff[2] == "*") {
            
        } else {
            for (int i = 1; i < TotalVector; i++) {
                if (TempBuff[i] != "FROM" && TempBuff[i] != "from") {
                    if (TempBuff[i] != ",") {
                        cd.addC(TempBuff[i]);
                        //bs.tabla.columns.buscarColumna(TempBuff[i]);
                    }
                } else {
                    break;
                }
            }
            
            
            
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