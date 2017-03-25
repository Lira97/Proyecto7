#include <iostream>
#include "Lista.h"

using namespace std;
int main() 
{
	List testList;
	testList.insertarNodo(457);
	testList.insertarNodo(34);
	testList.insertarFinal(78);
	testList.insertarFinal(25);
	testList.insertarFinal(2);
	testList.insertarNodo(457);
	testList.insertarNodo(4);
	testList.insertaDespues(6,34);
	testList.imprimirNodo();
	cout<<"\n";
	int h;
	testList.eliminaPrimero(h);
	testList.eliminaUltimo(h);
	testList.eliminaNodo(78,h);
	testList.imprimirNodo();
	cout<<"\n";
	testList.eliminaUltimo(h);
	testList.imprimirNodo();
	}