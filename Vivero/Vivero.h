#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vivero
{
public:
	Vivero();
	~Vivero();
	void PosicionXY(int x, int y);
	void verEncabezado(string mensaje);
	void LineaDivision(int cantidad);
	void SaltoLinea(int cnt);
	void LimpiarPantalla();
};

