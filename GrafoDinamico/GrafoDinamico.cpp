
#include <iostream>
#include "Grafo.h"

int main()
{
	Grafo* grafo = new Grafo();
	int opc = 0;

	while (opc != 8)
	{
		system("cls");
		cout << "1. Insertar vertice" << endl;
		cout << "2. Insertar arista" << endl;
		cout << "3. Obtener tamano" << endl;
		cout << "4. Mostrar lista de adyacencia" << endl;
		cout << "5. Eliminar vertice" << endl;
		cout << "6. Eliminar arista" << endl;
		cout << "7. Eliminar todo" << endl;
		cout << "8. Salir" << endl;

		cout << endl;
		cout << "Ingrese una opcion del menu: ";
		cin >> opc;

		system("cls");

		switch (opc)
		{
		case 1:
		{
			string nombre;
			cout << "Ingrese el nombre del vertice: ";
			cin >> nombre;

			grafo->InsertaVertice(nombre);

			break;
		}
		case 2:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string ori, dest;
				int precio;
				cout << "Ingrese el nombre del vertice origen: ";
				cin >> ori;
				cout << "Ingrese el nombre del vertice destino: ";
				cin >> dest;
				cout << "Ingrese el precio: ";
				cin >> precio;

				grafo->InsertaArista(ori, dest, precio);
			}

			break;
		}
		case 3:
		{
			int tamano = grafo->ObtenerTamano();
			cout << "El grafo tiene " << tamano << " vertices" << endl;

			break;
		}
		case 4:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
				grafo->MostrarListaAdyacencia();

			break;
		}
		case 5:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string nombre;
				cout << "Ingrese el nombre del vertice a eliminar: ";
				cin >> nombre;

				grafo->EliminarVertice(nombre);
			}
			
			break;
		}
		case 6:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string ori, dest;
				cout << "Ingrese el nombre del vertice origen: ";
				cin >> ori;
				cout << "Ingrese el nombre del vertice destino: ";
				cin >> dest;

				grafo->EliminarArista(ori, dest);
			}
			break;
		}
		case 7:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				grafo->EliminarTodo();
			}

			break;
		}
		}

		cin.get();
		cin.get();
	}

}
