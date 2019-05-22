#pragma once
#include <iostream>
#include <string>
using namespace std;

class Planta: public Menu 
{
public:
	Planta();
	~Planta();
	string nombrePlanta;
	string nombreArchivo;
	string nombreArchivoHistorial;
	void setNombrePlanta(int opcion);
	void setNombreArchivo(int opcion);
	void setNombreHistorial(int opcion);
	void MenuOperacion();
};

