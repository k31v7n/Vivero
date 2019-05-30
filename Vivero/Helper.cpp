#include "pch.h"
#include "Helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>  
#include <windows.h>  
#include <fstream>
#include <iostream>
using namespace std;
vector<string> explode1(const string &delimiter, const string &explodeme);
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
	SaltoLinea(2);
	cout << "Desear realizar de nuevo la operacion?" << endl;
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

bool Helper::ValidarNombre(string nombre, string archivo, string codigo)
{
	string linea;
	bool exito = true;

	ifstream lista(archivo);
	if (!lista.fail()) {
		do {
			if (!lista.eof()) {
				getline(lista, linea);

				if (!empty(linea)) {
					vector<string> vh = explode1("|", linea);

					if (!empty(codigo)) {
						if (vh[2] == nombre && vh[0] != codigo) {
							exito = false;
							break;
						}
					}
					else {
						if (vh[2] == nombre) {
							exito = false;
							break;
						}
					}
				}
			}
		} while (!lista.eof());
	}
	lista.close();

	return exito;
}

bool Helper::validaCodigo(string codigo, string archivo)
{
	string linea;
	bool exito = true;

	ifstream lista(archivo);
	if (!lista.fail()) {
		do {
			if (!lista.eof()) {
				getline(lista, linea);

				if (!empty(linea)) {
					vector<string> vh = explode1("|", linea);
					if (vh[1] == codigo) {
						exito = false;
						break;
					}
				}
			}
		} while (!lista.eof());
	}
	lista.close();

	return exito;
}

vector<string> explode1(const string &delimiter, const string &str)
{
	vector<string> arr;

	int strleng = str.length();
	int delleng = delimiter.length();
	if (delleng == 0)
		return arr;//no change

	int i = 0;
	int k = 0;
	while (i < strleng)
	{
		int j = 0;
		while (i + j < strleng && j < delleng && str[i + j] == delimiter[j])
			j++;
		if (j == delleng)//found delimiter
		{
			arr.push_back(str.substr(k, i - k));
			i += delleng;
			k = i;
		}
		else
		{
			i++;
		}
	}
	arr.push_back(str.substr(k, i - k));
	return arr;
}