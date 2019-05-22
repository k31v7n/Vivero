#include "pch.h"
#include "Menu.h"
#include "Planta.h"
#include <iostream>
#include <string>
using namespace std;

Planta *p;

Planta::Planta()
{
	p = new Planta();
}


Planta::~Planta()
{
}

void Planta::setNombrePlanta(int opcion)
{
	switch (opcion) {
		case 1: p->nombrePlanta = "Ornamental";
		case 2: p->nombrePlanta = "Medicinal";
		case 3: p->nombrePlanta = "Silvestre";
	}

	switch (opcion) {
		case 1: p->nombreArchivo = "Ornamental.txt";
		case 2: p->nombreArchivo = "Medicinal.txt";
		case 3: p->nombreArchivo = "Silvestre.txt";
	}

	switch (opcion) {
		case 1: p->nombreArchivoHistorial = "Historial_ornamental.txt";
		case 2: p->nombreArchivoHistorial = "Historial_medicinal.txt";
		case 3: p->nombreArchivoHistorial = "Historial_silvestre.txt";
	}
}

void Planta::setNombreArchivo(int opcion)
{
}

void Planta::setNombreHistorial(int opcion)
{
}

void Planta::MenuOperacion()
{
	p->MenuPlantaOperacion();
}
