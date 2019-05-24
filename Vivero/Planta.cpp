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
	edatos.px = 50;
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

		cout << "- Nombre: ";
		cin >> datos.nombre;
		ph->SaltoLinea(1);

		getchar();
		cout << "- Descripcion: ";
		getline(cin, datos.descripcion);
		cin.sync();
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
