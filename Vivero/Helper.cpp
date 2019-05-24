#include "pch.h"
#include "Helper.h"
#include <iostream>
#include <string>
#include <stdio.h>  
#include <windows.h>  
#include <fstream>
#include <iostream>
using namespace std;



Helper::Helper()
{
	
}


Helper::~Helper()
{
}

void Helper::LimpiarPantalla()
{
	system("cls");
}

void Helper::PosicionTextoXY(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Helper::SaltoLinea(int cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		cout << endl;
	}
}

void Helper::LineaDivision(int cantidad, string caracter)
{
	for (int i = 0; i < cantidad; i++)
	{
		cout << caracter;
	}

	SaltoLinea(2);
}

void Helper::ColorPantalla()
{
	system("color 0A");
}

void Helper::Pausa()
{
	system("pause");
}

void Helper::verEncabezado(Encabezado datos)
{

	LimpiarPantalla();
	ColorPantalla();

	PosicionTextoXY(0, 0);
	printf("%c\n", 218);

	PosicionTextoXY(119, 0);
	printf("%c\n", 191);

	for (int i = 1; i < 119; i++)
	{
		PosicionTextoXY(i, 0);
		printf("%c\n", 196);

		PosicionTextoXY(i, 4);
		printf("%c\n", 196);

		PosicionTextoXY(i, 6);
		printf("%c\n", 196);
	}

	PosicionTextoXY(0, 1);
	printf("%c\n", 179);

	PosicionTextoXY(0, 2);
	printf("%c\n", 179);

	PosicionTextoXY(0, 3);
	printf("%c\n", 179);

	PosicionTextoXY(0, 4);
	printf("%c\n", 195);

	PosicionTextoXY(119, 1);
	printf("%c\n", 179);

	PosicionTextoXY(119, 2);
	printf("%c\n", 179);

	PosicionTextoXY(119, 3);
	printf("%c\n", 179);

	PosicionTextoXY(119, 4);
	printf("%c\n", 180);

	PosicionTextoXY(0, 5);
	printf("%c\n", 179);

	PosicionTextoXY(119, 5);
	printf("%c\n", 179);

	PosicionTextoXY(0, 6);
	printf("%c\n", 192);

	PosicionTextoXY(119, 6);
	printf("%c\n", 217);


	PosicionTextoXY(datos.px, 2);
	cout << datos.titulo;

	if (!empty(datos.mensaje)) {
		PosicionTextoXY(2, 5);
		cout << datos.mensaje;
	}

	SaltoLinea(2);
}

int Helper::VerCorrelativo(string archivo)
{
	int numero = 1;

	ifstream correlativo(archivo);
	if (!correlativo.fail()) {
		string linea;
		while (getline(correlativo, linea))
		{
			if (!linea.empty()) numero++;
		}
	}
	correlativo.close();

	return numero;
}

int Helper::Continuar()
{
	int continuar;
	SaltoLinea(1);
	LineaDivision(70, "-");
	cout << "¿Desear realizar de nuevo la operacion?" << endl;
	cout << "1. Si" << endl;
	cout << "2. No" << endl;
	cin >> continuar;

	return continuar;
}

string Helper::verDato(string dato)
{
	do {
		getline(cin, dato);
		cin.sync();
	} while (dato == "");

	return dato;
}

void Helper::PosicionIncono(int x, int y, int codigo)
{
	PosicionTextoXY(x, y);
	printf("%c\n", codigo);
}
