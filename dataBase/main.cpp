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
using namespace std;
void querys(int);
void createDatabase();
void menuSeleccion();
void insertar();
void select();
void split(string Linea, char Separador, vector<string> &TempBuff, int &TotalVector);
int Cuenta(string s, const char Separadorr, int &TotalChars);
//dataBase bs;
string name;

int main() {
    /*
    mensajes msj = mensajes();
    msj.welcome();
    int opc = msj.opcion();
    switch (opc) {
        case 1:
            cout << "Escriba el nombre de las base de datos" << endl;
            cin>>name;
            createDatabase();

            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

void createDatabase() {
   /* columnasData cd=columnasData();
    string Palabra;
    cout << "Create table..." << endl;
    cin>> Palabra;
    getline(cin, Palabra);
/*
    vector<string> TempBuff(0);
    int TotalVector;
    split(Palabra, *" ", TempBuff, TotalVector);

    cout << TotalVector << endl; // Devuelve tamaño del vector: 3
    string name = TempBuff[2];
    for (int i = 4; i < TotalVector-1; i+=3) {
        columna c=columna(TempBuff[i],TempBuff[i+1]);
        cd.add(c);
    }*/
    
    



}

void menuSeleccion() {
   /* mensajes msj = mensajes();
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
*/
}

void querys(int opc) {
    cout << "Inserte el query" << endl;
    switch (opc) {
        case 1:
            break;
        case 2:

            break;
        default:
            break;
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