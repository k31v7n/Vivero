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
	bool insumo = false;
	bool cliente = false;
	void set_nombre_planta(int planta);
	void PlantaOperacion(int planta);
	void EncabezadoPlanta(string mensaje);
	void NuevaPlanta();
	void MostrarPlanta();
	void MostrarPlantaTermino();
	void MostrarPlantaTodos();
	void HeadTable();
	void FooterTable(int pos);
	void ModificarPlanta();
	void CambioEstadoPlanta();
	void HistorialPlanta();
};

