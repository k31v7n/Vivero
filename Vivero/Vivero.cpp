#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

Helper *hv;
Menu *m;

int mprincipal;
int mplanta;

int main()
{
	hv = new Helper();
	m = new Menu();

	mprincipal = 0;
	do 
	{
		mprincipal = m->MenuPrincipal();

		switch (mprincipal) {
			case 1:
				mplanta = 0;

				do {
					mplanta = m->MenuPlanta();

					if (mplanta != 4) {
						m->MenuPlantaOperacion(mplanta);
					}

				} while (mplanta != 4);
				
			break;
			default:
				if (mprincipal != 6) 
				{
					hv->SaltoLinea(1);
					cout << "Ups! Ha seleccionado una opcion incorrecta. Intentelo de nuevo.";
					hv->SaltoLinea(1);
					hv->Pausa();
				}
			break;
		}

	} while (mprincipal != 6);

	return 0;
}
