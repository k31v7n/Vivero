#include "pch.h"
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

Helper *ph;

Planta::Planta()
{
}

Planta::~Planta()
{
}

void Planta::set_nombre_planta(int planta)
{
	switch (planta) {
		case 1: 
			nomPlanta = "ORNAMENTAL";
			nomPlantaArchivo = "Ornamental.txt";
			nomPlantaArchivoHistorial = "Historial_ornamental.txt";
		break;
		case 2: 
			nomPlanta = "SILVESTRE";
			nomPlantaArchivo = "Silvestre.txt";
			nomPlantaArchivoHistorial = "Historial_silvestre.txt";
		break;
		case 3: 
			nomPlanta = "MEDICINAL";
			nomPlantaArchivo = "Medicinal.txt";
			nomPlantaArchivoHistorial = "Historial_medicinal.txt";
		break;
	}
}

void Planta::PlantaOperacion(int planta)
{
	switch (planta)
	{
		case 1:
			NuevaPlanta();
		break;
		case 2:
			MostrarPlanta();
		break;
		default:
			if (planta != 6) 
			{
				ph->SaltoLinea(1);
				cout << "Ups! Ha seleccionado una operacion incorrecta.";
				ph->SaltoLinea(1);
				ph->Pausa();
			}
		break;
	}
}

void Planta::EncabezadoPlanta(string mensaje)
{
	Encabezado edatos;
	edatos.px = 30;
	edatos.py = 1;
	edatos.titulo  = "VIVERO LAS FLORES - MODULO DE PLANTAS -  PLANTA " + nomPlanta;
	edatos.mensaje = mensaje;
	ph->verEncabezado(edatos);
}

void Planta::NuevaPlanta()
{
	Pdatos datos;
	int  continuar = 1;

	do {
		EncabezadoPlanta("NUEVA PLANTA: complete el formulario por favor:");

		int correlativo = ph->VerCorrelativo(nomPlantaArchivo);
		string subcodigo = "P" + nomPlanta.substr(0, 1) + "-";

		cout << "- Codigo: " << subcodigo << correlativo;
		datos.correlativo = correlativo;
		datos.codigo = subcodigo;
		ph->SaltoLinea(2);

		getchar();
		cout << "- Nombre: ";
		datos.nombre = ph->verDato(datos.nombre);
		ph->SaltoLinea(1);

		cout << "- Descripcion: ";
		datos.descripcion = ph->verDato(datos.descripcion);
		ph->SaltoLinea(3);
	
		ofstream guardar(nomPlantaArchivo, ios::app);
		guardar << "|" << datos.correlativo 
			    << "|" << datos.codigo << datos.correlativo 
			    << "|" << datos.nombre 
			    << "|" << datos.descripcion << endl;
		guardar.close();

		cout << "La planta fue agregada correctamente.";
		continuar = ph->Continuar();

	} while (continuar == 1);
}

void Planta::MostrarPlanta()
{
	int busca = 0;

	do {
		EncabezadoPlanta("CONSULTA DE PLANTAS: seleccione una opcion de busqueda:");
		cout << "1. Por termino" << endl;
		cout << "2. Mostrar todos" << endl;
		cout << "3. Cancelar";
		ph->SaltoLinea(2);

		cout << "Opcion seleccionada: ";
		cin >> busca;
		
		if (1 == busca) {
			MostrarPlantaTermino();

		} else if (2 == busca) {
			MostrarPlantaTodos();

		} else if (3 != busca) {

			ph->SaltoLinea(2);
			cout << "Opcion de busqueda incorrecta. ";
			ph->Pausa();
		}

	} while (3 != busca);
}

void Planta::MostrarPlantaTermino()
{
}

void Planta::MostrarPlantaTodos()
{
	ifstream lista(nomPlantaArchivo);
	if (!lista.fail()) {
		HeadTable();
		do {
			
		} while (!lista.eof());
	} else {
		cout << "Ups! No se encontro ningun registro";
		ph->SaltoLinea(1);
		ph->Pausa();
	}
	lista.close();
}

void Planta::HeadTable()
{
	EncabezadoPlanta("CONSULTA DE PLANTAS: seleccione una opcion de busqueda:");

	ph->PosicionIncono(0, 6, 195);
	ph->PosicionIncono(20, 6, 194);
	ph->PosicionIncono(40, 6, 194);
	ph->PosicionIncono(60, 6, 194);

	ph->PosicionIncono(0, 7, 179);
	ph->PosicionTextoXY(2, 7);
	cout << "Numero";
	
	ph->PosicionIncono(20, 7, 179);
	ph->PosicionTextoXY(24, 7);
	cout << "Codigo";

	ph->PosicionIncono(40, 7, 179);
	ph->PosicionTextoXY(44, 7);
	cout << "Nombre";

	ph->PosicionIncono(60, 7, 179);
	ph->PosicionTextoXY(64, 7);
	cout << "Descripcion";

	ph->PosicionIncono(0, 8, 192);

	for (int i = 0; i < 118; i++)
	{
		ph->PosicionIncono(i+1, 8, 196);
	}

	ph->PosicionIncono(20, 8, 193);
	ph->PosicionIncono(40, 8, 193);
	ph->PosicionIncono(60, 8, 193);

	ph->PosicionIncono(119, 6, 180);
	ph->PosicionIncono(119, 7, 179);
	ph->PosicionIncono(119, 8, 217);
}
