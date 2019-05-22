#pragma once
#include <iostream>
#include <string>
using namespace std;

class Menu
{
public:
	Menu();
	~Menu();
	int opcion;
	void verEncabezado(string titulo, string mensaje);
	int MenuPrincipal();
	int MenuPlanta();
	int MenuPlantaOperacion();
};

