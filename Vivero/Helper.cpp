#include "pch.h"
#include "Helper.h"
#include <iostream>
#include <string>
#include <stdio.h>  
#include <windows.h>  
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

void Helper::PosicionTextoXY(int x, int y, string texto)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);

	cout << texto;
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
