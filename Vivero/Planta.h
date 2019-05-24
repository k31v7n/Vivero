#pragma once
#include <iostream>
#include <string>
using namespace std;

class Planta
{
struct Pdatos
{
	int correlativo;
	string codigo;
	string nombre;
	string descripcion;
};
public:
	Planta();
	~Planta();
	string nomPlanta = "";
	string nomPlantaArchivo = "";
	string nomPlantaArchivoHistorial = "";
	void set_nombre_planta(int planta);
	void PlantaOperacion(int planta);
	void EncabezadoPlanta(string mensaje);
	void NuevaPlanta();
};

