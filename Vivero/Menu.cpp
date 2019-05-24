#include "pch.h"
#include "Menu.h"
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

Helper *h;

Menu::Menu()
{
	opcion = 0;
	h = new Helper();
}


Menu::~Menu()
{
}

int Menu::MenuPrincipal()
{
	Encabezado edatos;
	edatos.px = 50;
	edatos.py = 1;
	edatos.titulo  = "VIVERO LAS FLORES";
	edatos.mensaje = "Bienvenidos al menu principal. Elija un modulo para continuar:";
	h->verEncabezado(edatos);

	cout << "1. Plantas" << endl;
	cout << "2. Insumos" << endl;
	cout << "3. Cliente" << endl;
	cout << "4. Inventario"  << endl;
	cout << "5. Facturacion" << endl;
	cout << "6. Cerrar Sesion";
	h->SaltoLinea(2);
	cout << "Modulo seleccionado: ";
	
	cin  >> opcion;

	return opcion;
}

int Menu::MenuPlanta()
{
	Encabezado edatos;
	edatos.px = 40;
	edatos.py = 1;
	edatos.titulo = "VIVERO LAS FLORES - MODULO DE PLANTAS";
	edatos.mensaje = "Seleccione un tipo de planta para continuar:";
	h->verEncabezado(edatos);

	cout << "1. Ornamental" << endl;
	cout << "2. Silvestre"  << endl;
	cout << "3. Medicinal"  << endl;
	cout << "4. Regresar a menu principal";
	h->SaltoLinea(2);
	cout << "Tipo seleccionado: ";
	cin  >> opcion;

	return opcion;
}

void Menu::MenuPlantaOperacion(int planta)
{
	set_nombre_planta(planta);

	do {
		Encabezado edatos;
		edatos.px = 30;
		edatos.py = 1;
		edatos.titulo = "VIVERO LAS FLORES - MODULO DE PLANTAS -  PLANTA " + nomPlanta;
		edatos.mensaje = "Seleccione una operacion para continuar:";
		h->verEncabezado(edatos);

		cout << "1. Nueva" << endl;
		cout << "2. Consulta" << endl;
		cout << "3. Modificar" << endl;
		cout << "4. Cambio de estado" << endl;
		cout << "5. Historial" << endl;
		cout << "6. Regresar al menu de tipos";
		h->SaltoLinea(2);
		cout << "Operacion seleccionada: ";
		cin >> opcion;

		PlantaOperacion(opcion);

	} while (opcion != 6);
	
}
