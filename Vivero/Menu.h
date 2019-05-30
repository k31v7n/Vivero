#pragma once
#include <iostream>
#include <string>
using namespace std;

class Menu : public Planta, public Inventario
{
public:
	Menu();
	~Menu();
	int opcion;
	int MenuPrincipal();
	int MenuPlanta();
	void MenuPlantaOperacion(int planta);
	void MenuInsumosOperacion();
	void MenuClienteOperacion();
	void MenuInventario();
};

