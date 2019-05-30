#include "pch.h"
#include "Inventario.h"
#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
Helper *hi;

Inventario::Inventario()
{
}


Inventario::~Inventario()
{
}

void Inventario::OperacionInventario(int opcion)
{
	switch (opcion)
	{
	case 1:
		NuevoInventario();
		break;
	case 2:
		MostrarInventario();
	default:
		if (opcion != 3)
		{
			hi->SaltoLinea(1);
			cout << "Ups! Ha seleccionado una operacion incorrecta.";
			hi->SaltoLinea(1);
			hi->Pausa();
		}
		break;
	}
}

void Inventario::NuevoInventario()
{
	Idatos datos;

	EncabezadoInventario("NUEVO INVENTARIO: complete el formulario");

	int correlativo = hi->VerCorrelativo("Inventario.txt");
	datos.correlativo = correlativo;

	cout << "- Codigo asignado: I" << correlativo;
	hi->SaltoLinea(1);

	int tp = 0;
	do {
		cout << "- Tipo de Planta: ";
		cin >> datos.tipo_planta;

		if (datos.tipo_planta == "Ornamental") {
			tp = 1;
		}
		else if (datos.tipo_planta == "Medicinal") {
			tp = 1;
		}
		else if (datos.tipo_planta == "Silvestre") {
			tp = 1;
		} else {
			cout << "Tipo de planta incorrecto" << endl << endl;
		};
	} while (tp == 0);

	hi->SaltoLinea(1);
	int existea = 0;
	do {
		cout << "- Codigo de planta: ";
		cin >> datos.codigo;
		existea = validaPlanta(datos.codigo);
		if (existea == 0) {
			cout << "Codigo de planta incorrecto" << endl << endl;
		}
	} while (existea == 0);

	hi->SaltoLinea(1);
	int existeb = 0;
	do {
		cout << "- Existencias: ";
		cin >> datos.existencia;
		if (datos.existencia > 0) {
			existeb = 1;
		}
		else {
			cout << "La existencia debe ser mayor a cero." << endl << endl;
		}

	} while (existeb == 0);

	hi->SaltoLinea(1);
	cout << "- Costro Unitario: ";
	cin >> datos.costo;

	hi->Pausa();
}

void Inventario::MostrarInventario()
{
}

void Inventario::EncabezadoInventario(string mensaje)
{
	Encabezado edatos;
	edatos.py = 1;
	edatos.px = 45;
	edatos.titulo = "VIVERO LAS FLORES - MODULO DE INVENTARIOS";
	edatos.mensaje = mensaje;
	hi->verEncabezado(edatos);
}

bool Inventario::validaPlanta(string codigo)
{
	string tcodigo = codigo.substr(0, 2);
	bool existe = false;
	cout << tcodigo;
	if (tcodigo == "PO") {
		existe = hi->validaCodigo(codigo, "Ornamental.txt");
	}
	else if (tcodigo == "PS") {
		existe = hi->validaCodigo(codigo, "Silvestre.txt");
	}
	else if (tcodigo == "PM") {
		existe = hi->validaCodigo(codigo, "Medicinal.txt");
	}
	else {
		existe = false;
	}

	return false;
}
