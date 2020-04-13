all:lista
lista:	main.o ArbolBinario.o BinaryThreeForInt.o BinaryThreeForString.o Data.o Nodo.o NodoColumna.o NodoColumnaAux.o NuevaTabla.o Tabla.o 			TablaHash.o Table.o claseDePrueba.o columna.o columnasData.o dataBase.o hashFunctions.o mensajes.o seleccion.o
		g++ main.o ArbolBinario.o BinaryThreeForInt.o BinaryThreeForString.o Data.o Nodo.o NodoColumna.o NodoColumnaAux.o NuevaTabla.o Tabla.o TablaHash.o Table.o claseDePrueba.o columna.o columnasData.o dataBase.o hashFunctions.o mensajes.o seleccion.o -o lista
			./lista
main.o:			main.cpp
			g++ -c main.cpp
ArbolBinario.o:		ArbolBinario.cpp
			g++ -c ArbolBinario.cpp
BinaryThreeForInt.o:	BinaryThreeForInt.cpp
			g++ -c BinaryThreeForInt.cpp
Data.o:			Data.cpp
			g++ -c Data.cpp
Nodo.o:			Nodo.cpp
			g++ -c Nodo.cpp
NodoColumna.o:		NodoColumna.cpp
			g++ -c NodoColumna.cpp
NodoColumnaAux.o:	NodoColumnaAux.cpp
			g++ -c NodoColumnaAux.cpp
NuevaTabla.o:		NuevaTabla.cpp
			g++ -c NuevaTabla.cpp
Tabla.o:		Tabla.cpp
			g++ -c Tabla.cpp
TablaHash.o:		TablaHash.cpp
			g++ -c TablaHash.cpp
Table.o:		Table.cpp
			g++ -c Table.cpp
claseDePrueba.o:	claseDePrueba.cpp
			g++ -c claseDePrueba.cpp
columna.o:		columna.cpp
			g++ -c columna.cpp
columnasData.o:		columnasData.cpp
			g++ -c columnasData.cpp
dataBase.o:		dataBase.cpp
			g++ -c dataBase.cpp
hashFunction.o:		hashFunction.cpp
			g++ -c hashFunction.cpp
mensajes.o:		mensajes.cpp
			g++ -c mensajes.cpp
seleccion.o:		seleccion.cpp
			g++ -c seleccion.cpp
clean:
			rm -rf *o dataBase
