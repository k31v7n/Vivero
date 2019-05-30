#pragma once
#include <iostream>
#include <string>
using namespace std;

class Helper
{
public:
	Helper();
	~Helper();
	
	void LimpiarPantalla();
	void PosicionTextoXY(int x, int y);
	void SaltoLinea(int cantidad);
	void LineaDivision(int cantidad, string caracter);
	void ColorPantalla();
	void Pausa();
	void verEncabezado(struct Encabezado);
	int VerCorrelativo(string archivo);
	int Continuar();
	string verDato(string dato);
	void PosicionIncono(int x, int y, int codigo);
	bool ValidarNombre(string nombre, string archivo, string codigo);
	bool validaCodigo(string codigo, string archivo);
};

