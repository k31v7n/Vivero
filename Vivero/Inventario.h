#pragma once
class Inventario
{
struct Idatos
{
	int correlativo;
	string codigo;
	int existencia;
	int costo;
	string tipo_planta;
};
public:
	Inventario();
	~Inventario();
	void OperacionInventario(int opcion);
	void NuevoInventario();
	void MostrarInventario();
	void EncabezadoInventario(string mensaje);
	bool validaPlanta(string codigo);
};

