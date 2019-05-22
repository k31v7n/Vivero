#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;
Helper *h;

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::verEncabezado(string titulo, string mensaje)
{
	h = new Helper();

	h->LimpiarPantalla();
	h->ColorPantalla();
	h->PosicionTextoXY(45, 1, titulo);
	h->SaltoLinea(2);

	if (!empty(mensaje)) {
		cout << mensaje;
		h->SaltoLinea(2);
	}
						 
	h->LineaDivision(120, "-");
}

int Menu::MenuPrincipal()
{
	string titulo  = "VIVERO LAS FLORES";
	string mensaje = "Bienvenido al Menu Principal, seleccione una opcion para continuar:";

	verEncabezado(titulo, mensaje);
	cout << " 1. Plantas"     << endl;
	cout << " 2. Insumos"     << endl;
	cout << " 3. Inventario"  << endl;
	cout << " 4. Cliente"     << endl;
	cout << " 5. Facturacion" << endl;
	cout << " 6. Cerrar Sesion";
	h->SaltoLinea(2);

	cout << " Opcion seleccionada: "; 
	cin  >> opcion;

	return opcion;
}

int Menu::MenuPlanta()
{
	string titulo  = "VIVERO LAS FLORES - Modulo de Plantas";
	string mensaje = "Para continuar seleccione un tipo de planta:";

	verEncabezado(titulo, mensaje);
	cout << " 1. Planta Ornamental" << endl;
	cout << " 2. Planta Medicinal"  << endl;
	cout << " 3. Planta Silvestre"  << endl;
	cout << " 4. Menu Principal"    << endl;
	h->SaltoLinea(2);

	cout << " Opcion seleccionada: ";
	cin >> opcion;

	return opcion;
}

int Menu::MenuPlantaOperacion()
{
	return 0;
}
