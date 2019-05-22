#include "pch.h"
#include "Menu.h"
#include "Planta.h"
#include <iostream>
#include <string>
using namespace std;

Menu *m;
Planta *p;

int mprincipal = 0;
int mplanta = 0;

int main()
{
	m = new Menu();
	
	do {
		mprincipal = m->MenuPrincipal();
		
		switch (mprincipal) {
			case 1:
				do {
					mplanta = m->MenuPlanta();

					p = new Planta();
					p->setNombreTools(mplanta);
					p->MenuOperacion();

				} while (mplanta != 4);
			break;
			default:
				if (mprincipal != 6) cout << "Opcion Incorrecta";
			break;
		}
	} while (mprincipal != 6);

	return 0;
}
