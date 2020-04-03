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
using namespace std;

int main() {
    BinaryThreeForInt t = BinaryThreeForInt();
    t.insertarNodo(Nodo(10));
    t.insertarNodo(Nodo(5));

    t.insertarNodo(Nodo(15));
    t.insertarNodo(Nodo(20));
    t.insertarNodo(Nodo(25));
   
 t.insertarNodo(Nodo(4));
   


    //    t.insertarNodo(Nodo(3));
    ///  t.insertarNodo(Nodo(27));

    cout << "TERMINADO--------------------->" << endl;

    /*  t.insertarNodo(Nodo(100));
      t.insertarNodo(Nodo(99));
      t.insertarNodo(Nodo(89));
      t.insertarNodo(Nodo(105));
      t.insertarNodo(Nodo(104));
      t.insertarNodo(Nodo(600));
      t.insertarNodo(Nodo(602));
      t.insertarNodo(Nodo(601));
     */

    t.showIntegerThree();
























    /* mensajes msj= mensajes();
     msj.welcome();
     int op=msj.opcion();
     switch(op){
         case 1:
            
             break;
         case 2:
            
             break;
    
     }
     */

    /*columnasData t=columnasData();
    columna c=columna("Nombre","string");
    columna d=columna("edad","int");
    columna e=columna("caracter","char");
    columna f=columna("decimal","flooat");
    t.add(c);
    t.add(d);
    t.add(e);
    t.add(f);*/
    /*  string valor="10.f";
       try {
          int i = std::stoi(valor);
          string str = to_string(i);
          if (valor.length() == str.length()) {
               cout << "numero" << endl;
             // indiceTypeHash = 1;
          }
      } catch (std::invalid_argument const &e) {
      } catch (std::out_of_range const &e) {
      }
    
      double s = 46;
      int a = s;
      if (a < s) {
          cout << "decimal" << endl;

      } else {
         cout << "numero" << endl;

      }
  string num = "0";
  double temp = -10;
  temp=atof(num.c_str());
  cout<<temp;
     */


    return 0;
}

