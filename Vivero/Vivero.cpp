#include "Vivero.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>

using namespace std;
Vivero v;

int opcion = 0;

Vivero::Vivero()
{
	system("color 0A");
}


Vivero::~Vivero()
{
}

int main()
{
	v.verEncabezado("MENU PRINCIPAL: Bienvenido al sistema, por favor seleccione un modulo.");
	return 0;
}

void Vivero::PosicionXY(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Vivero::verEncabezado(string mensaje)
{
	v.LimpiarPantalla();
	v.PosicionXY(45, 1);
	cout << "VIVERO LAS FLORES";
	v.SaltoLinea(2);

	if (!empty(mensaje)) {
		cout << mensaje;
		v.SaltoLinea(2);
	}
	v.LineaDivision(120);
}

void Vivero::LineaDivision(int cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		printf("%c", 205);
	}

	v.SaltoLinea(2);
}

void Vivero::SaltoLinea(int cnt)
{
	for (int i = 0; i < cnt; i++) {
		cout << endl;
	}
}

void Vivero::LimpiarPantalla()
{
	system("cls");
}


