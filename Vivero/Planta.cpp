#include "pch.h"
#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

Helper *ph;
vector<string> explode(const string &delimiter, const string &explodeme);

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
			insumo = false;
			cliente = false;
		break;
		case 2: 
			nomPlanta = "SILVESTRE";
			nomPlantaArchivo = "Silvestre.txt";
			nomPlantaArchivoHistorial = "Historial_silvestre.txt";
			insumo = false;
			cliente = false;
		break;
		case 3: 
			nomPlanta = "MEDICINAL";
			nomPlantaArchivo = "Medicinal.txt";
			nomPlantaArchivoHistorial = "Historial_medicinal.txt";
			insumo = false;
			cliente = false;
		break;
		case 4:
			nomPlanta = "INSUMO";
			nomPlantaArchivo = "Insumo.txt";
			nomPlantaArchivoHistorial = "Historial_insumo.txt";
			insumo = true;
			cliente = false;
			break;
		case 5:
			nomPlanta = "CLIENTE";
			nomPlantaArchivo = "Cliente.txt";
			nomPlantaArchivoHistorial = "Historial_cliente.txt";
			insumo = false;
			cliente = true;
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
		case 3:
			ModificarPlanta();
		break;
		case 4:
			CambioEstadoPlanta();
		break;
		case 5:
			HistorialPlanta();
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
	edatos.py = 1;
	if (insumo) {
		edatos.px = 45;
		edatos.titulo = "VIVERO LAS FLORES - MODULO DE INSUMOS";
	}
	else if (cliente) {
		edatos.px = 45;
		edatos.titulo = "VIVERO LAS FLORES - MODULO DE CLIENTES";
	} else {
		edatos.px = 30;
		edatos.titulo = "VIVERO LAS FLORES - MODULO DE PLANTAS -  PLANTA " + nomPlanta;
	}
	edatos.mensaje = mensaje;
	ph->verEncabezado(edatos);
}

void Planta::NuevaPlanta()
{
	Pdatos datos;
	int  continuar = 1;

	do {
		if (insumo) {
			EncabezadoPlanta("NUEVO " + nomPlanta + ": complete el formulario por favor:");
		} else if (cliente) {
			EncabezadoPlanta("NUEVO " + nomPlanta + ": complete el formulario por favor:");
		} else {
			EncabezadoPlanta("NUEVA " + nomPlanta + ": complete el formulario por favor:");
		}

		int correlativo = ph->VerCorrelativo(nomPlantaArchivo);
		string subcodigo = "P" + nomPlanta.substr(0, 1) + "-";

		if (cliente) {
			char nit[9];

			cout << "- Codigo: " << correlativo;
			datos.correlativo = correlativo;
			ph->SaltoLinea(2);

			do {
				cout << "- NIT: ";
				cin >> nit;
				ph->SaltoLinea(1);
				if (strlen(nit) != 9) {
					cout << "Formato de NIT invalido";
					ph->SaltoLinea(2);
				} 
			} while (strlen(nit) != 9);

			datos.codigo = nit;
			ph->SaltoLinea(1);
			getchar();
			cout << "- Nombre: ";
			datos.nombre = ph->verDato(datos.nombre);
			ph->SaltoLinea(1);

			cout << "- Direccion: ";
			datos.descripcion = ph->verDato(datos.descripcion);
			ph->SaltoLinea(3);

		} else {
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
		}

		if (ph->ValidarNombre(datos.nombre, nomPlantaArchivo, "")) {
			ofstream guardar(nomPlantaArchivo, ios::app);
			guardar << datos.correlativo
				<< "|" << datos.codigo << datos.correlativo
				<< "|" << datos.nombre
				<< "|" << datos.descripcion
				<< "|" << "Activo" << endl;
			guardar.close();

			if (insumo) {
				cout << "El insumo fue agregado correctamente.";
			} else if (cliente) {
				cout << "El cliente fue agregado correctamente.";
			} else { 
				cout << "La planta fue agregada correctamente.";
			}

		} else {
			cout << "Los datos ya se encuentra registrados.";
		}
		continuar = ph->Continuar();

	} while (continuar == 1);
}

void Planta::MostrarPlanta()
{
	int busca = 0;

	do {
		EncabezadoPlanta("CONSULTA DE "+nomPlanta+": seleccione una opcion de busqueda:");
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
	int continuar;
	int exito = 0;
	string codigo;
	string linea;
	do {
		EncabezadoPlanta("CONSULTA DE "+nomPlanta+" POR CRITERIO: escriba el codigo de la planta:");
		cout << "- Codigo Ingresado: ";
		cin >> codigo;

		ifstream lista(nomPlantaArchivo);
		if (!lista.fail()) {
			do {
				if (!lista.eof()) {
					getline(lista, linea);

					if (!empty(linea)) {
						vector<string> v = explode("|", linea);

						if (v[1] == codigo) {
							exito = 1;
							ph->SaltoLinea(3);
							HeadTable();
							ph->PosicionIncono(0, 9, 179);
							ph->PosicionTextoXY(2, 9);
							cout << v[0];

							ph->PosicionIncono(20, 9, 179);
							ph->PosicionTextoXY(22, 9);
							cout << v[1];

							ph->PosicionIncono(40, 9, 179);
							ph->PosicionTextoXY(42, 9);
							cout << v[2];

							ph->PosicionIncono(60, 9, 179);
							ph->PosicionTextoXY(62, 9);
							cout << v[3];

							ph->PosicionIncono(105, 9, 179);
							ph->PosicionTextoXY(109, 9);
							cout << v[4];

							ph->PosicionIncono(119, 9, 179);

							FooterTable(10);

							break;
						}
					}
				}
			} while (!lista.eof());

			if (exito == 0) {
				EncabezadoPlanta("Ups! No se encontro ningun registro");
			}
		}
		else {
			EncabezadoPlanta("Ups! No se encontro ningun registro");
		}
		lista.close();

		continuar = ph->Continuar();
	} while (continuar == 1);
}

void Planta::MostrarPlantaTodos()
{
	Pdatos datos;
	int pos = 9;
	string linea;
	ifstream lista(nomPlantaArchivo);
	if (!lista.fail()) {
		
		do {
			//lista >> datos.correlativo >> datos.codigo >> datos.nombre >> datos.descripcion;
			if (!lista.eof()) {
				

				getline(lista, linea);
			
				if (!empty(linea)) {

					if (pos == 9) {
						HeadTable();
					}

					vector<string> v = explode("|", linea);
					ph->PosicionIncono(0, pos, 179);
					ph->PosicionTextoXY(2, pos);
					cout << v[0];

					ph->PosicionIncono(20, pos, 179);
					ph->PosicionTextoXY(22, pos);
					cout << v[1];

					ph->PosicionIncono(40, pos, 179);
					ph->PosicionTextoXY(42, pos);
					cout << v[2];

					ph->PosicionIncono(60, pos, 179);
					ph->PosicionTextoXY(62, pos);
					cout << v[3];

					ph->PosicionIncono(105, pos, 179);
					ph->PosicionTextoXY(109, pos);
					cout << v[4];

					ph->PosicionIncono(119, pos, 179);
					pos++;
				}
			}

		} while (!lista.eof());

		if (pos > 9) {
			FooterTable(pos);
		}
	} else {
		EncabezadoPlanta("Ups! No se encontro ningun registro");
	}
	lista.close();
}

void Planta::HeadTable()
{
	EncabezadoPlanta("CONSULTA DE "+nomPlanta+": se muestra el resultado de la consulta.");
	ph->PosicionIncono(0, 6, 195);
	ph->PosicionIncono(20, 6, 194);
	ph->PosicionIncono(40, 6, 194);
	ph->PosicionIncono(60, 6, 194);
	ph->PosicionIncono(105, 6, 194);


	ph->PosicionIncono(0, 7, 179);
	ph->PosicionTextoXY(8, 7);
	string a1 = (cliente) ? "Codigo" : "Numero";
	cout << a1;
	
	ph->PosicionIncono(20, 7, 179);
	ph->PosicionTextoXY(28, 7);
	string a2 = (cliente) ? "NIT" : "Codigo";
	cout << a2;

	ph->PosicionIncono(40, 7, 179);
	ph->PosicionTextoXY(48, 7);
	cout << "Nombre";

	ph->PosicionIncono(60, 7, 179);
	ph->PosicionTextoXY(78, 7);
	string a3 = (cliente) ? "Direccion" : "Descripcion";
	cout << a3;

	ph->PosicionIncono(105, 7, 179);
	ph->PosicionTextoXY(110, 7);
	cout << "Estado";

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
	
	ph->PosicionIncono(0, 8, 195);
	ph->PosicionIncono(20, 8, 197);
	ph->PosicionIncono(40, 8, 197);
	ph->PosicionIncono(60, 8, 197);
	ph->PosicionIncono(105, 8, 197);
	ph->PosicionIncono(119, 8, 180);
}

void Planta::FooterTable(int pos)
{
	ph->PosicionIncono(0, pos, 192);
	for (int i = 1; i < 119; i++)
	{
		ph->PosicionIncono(i, pos, 196);
	}
	ph->PosicionIncono(20, pos, 193);
	ph->PosicionIncono(40, pos, 193);
	ph->PosicionIncono(60, pos, 193);
	ph->PosicionIncono(105, pos, 193);
	ph->PosicionIncono(0, pos, 192);
	ph->PosicionIncono(119, pos, 217);
}

void Planta::ModificarPlanta()
{
	string codigo;
	int continuar, exito = 0;
	string linea;

	do {
		MostrarPlantaTodos();
		exito = 0;
		ph->SaltoLinea(2);

		cout << "Codigo seleccionado para la edicion: ";
		cin >> codigo;

		ifstream lista(nomPlantaArchivo);
		if (!lista.fail()) {
			do {
				if (!lista.eof()) {
					getline(lista, linea);

					ofstream temporal("ptemporal.txt", ios::app);

					if (!empty(linea)) {
						vector<string> v = explode("|", linea);

						if (v[1] == codigo) {
							if (v[4] == "Inactivo") {
								temporal << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << v[4] << endl;
								ph->SaltoLinea(2);
								cout << "*** No puede modificar una planta inactiva ***" << endl;
								ph->LineaDivision(120, "_");

							} else {
								ph->SaltoLinea(2);
								ph->LineaDivision(120, "_");
								cout << "EDICION DE LA PLANTA " + v[1];
								ph->SaltoLinea(2);
								Pdatos nuevo;
								nuevo.correlativo = atoi(v[0].c_str());
								nuevo.codigo = v[1];
								cout << "- Escriba el nuevo nombre: ";
								nuevo.nombre = ph->verDato(nuevo.nombre);

								ph->SaltoLinea(1);
								cout << "- Escriba la nueva descripcion: ";
								nuevo.descripcion = ph->verDato(nuevo.descripcion);

								if (ph->ValidarNombre(nuevo.nombre, nomPlantaArchivo, v[0])) {
									exito = 1;
									temporal << nuevo.correlativo
										<< "|" << nuevo.codigo
										<< "|" << nuevo.nombre
										<< "|" << nuevo.descripcion 
										<< "|" << "Activo"<< endl;
								}
								else {
									temporal << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << v[4] << endl;
									ph->SaltoLinea(2);
									cout << "*** El nombre que desea agregar ya esta registado ***" << endl;
									ph->LineaDivision(120, "_");
								}
							}
						} else {
							temporal << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << v[4] << endl;
							exito = 2;
						}
					}
					temporal.close();
				}
			} while (!lista.eof());
		}
		lista.close();

		const char * doc = nomPlantaArchivo.c_str();
		remove(doc);
		rename("ptemporal.txt", doc);

		if (exito == 1 or exito == 2) {
			MostrarPlantaTodos();
			ph->SaltoLinea(2);
			if (exito == 2) {
				cout << "*** El codigo ingresado es incorrecto ***" << endl;
			} else {
				cout << "*** Se modifico correctamente la planta ***" << endl;
			}
			ph->LineaDivision(120, "_");

		}
		continuar = ph->Continuar();

	} while (continuar == 1);
}

void Planta::CambioEstadoPlanta()
{
	string codigo;
	int continuar, exito = 0;
	string linea;

	do {
		MostrarPlantaTodos();
		exito = 0;
		ph->SaltoLinea(2);

		cout << "Escriba el codigo para cambiar de estado: ";
		cin >> codigo;

		ifstream lista(nomPlantaArchivo);
		if (!lista.fail()) {
			do {
				
				if (!lista.eof()) {
					getline(lista, linea);

					ofstream temporalx("ptemporal.txt", ios::app);

					if (!empty(linea)) {
						vector<string> v = explode("|", linea);

						if (v[1] == codigo) {
							if (v[4] == "Inactivo") {
								temporalx << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << v[4] << endl;
								ph->SaltoLinea(2);
								cout << "*** No puede cambiar estado a una planta inactiva ***" << endl;
								ph->LineaDivision(120, "_");

							} else {
								temporalx << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << "Inactivo" << endl;

								ofstream guardarx(nomPlantaArchivoHistorial, ios::app);
								guardarx << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << v[4] << endl;
								guardarx.close();

								exito = 1;
							}
						}
						else {
							temporalx << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << v[4] << endl;
							exito = 2;
						}
					}
					temporalx.close();
				}
			} while (!lista.eof());
		}
		lista.close();

		const char * doc = nomPlantaArchivo.c_str();
		remove(doc);
		rename("ptemporal.txt", doc);

		if (exito == 1 or exito == 2) {
			MostrarPlantaTodos();
			ph->SaltoLinea(2);
			if (exito == 2) {
				cout << "*** El codigo ingresado es incorrecto. ***" << endl;
			} else {
				cout << "*** Se cambio correctamente el estado de la planta ***" << endl;
			}
			ph->LineaDivision(120, "_");

		}
		continuar = ph->Continuar();

	} while (continuar == 1);
}

void Planta::HistorialPlanta()
{
	Pdatos datos;
	int pos = 9;
	string linea;
	ifstream lista(nomPlantaArchivoHistorial);
	if (!lista.fail()) {

		do {
			//lista >> datos.correlativo >> datos.codigo >> datos.nombre >> datos.descripcion;
			if (!lista.eof()) {


				getline(lista, linea);

				if (!empty(linea)) {

					if (pos == 9) {
						HeadTable();
					}

					vector<string> v = explode("|", linea);
					ph->PosicionIncono(0, pos, 179);
					ph->PosicionTextoXY(2, pos);
					cout << v[0];

					ph->PosicionIncono(20, pos, 179);
					ph->PosicionTextoXY(22, pos);
					cout << v[1];

					ph->PosicionIncono(40, pos, 179);
					ph->PosicionTextoXY(42, pos);
					cout << v[2];

					ph->PosicionIncono(60, pos, 179);
					ph->PosicionTextoXY(62, pos);
					cout << v[3];

					ph->PosicionIncono(105, pos, 179);
					ph->PosicionTextoXY(109, pos);
					cout << v[4];

					ph->PosicionIncono(119, pos, 179);
					pos++;
				}
			}

		} while (!lista.eof());

		if (pos > 9) {
			FooterTable(pos);
		}
	}
	else {
		EncabezadoPlanta("Ups! No se encontro ningun registro");
	}
	lista.close();

	ph->Pausa();
}

vector<string> explode(const string &delimiter, const string &str)
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