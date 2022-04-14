
#include <iostream>
#include "Grafo.h"

int main()
{
	Grafo* grafo = new Grafo();
	int opc = 0;

	grafo->InsertaVertice("A");
	grafo->InsertaVertice("B");
	grafo->InsertaVertice("C");
	grafo->InsertaVertice("D");
	grafo->InsertaVertice("E");
	grafo->InsertaVertice("F");
	grafo->InsertaVertice("G");
	grafo->InsertaArista("A", "A", 13);
	grafo->InsertaArista("A", "D", 8);
	grafo->InsertaArista("B", "B", 52);
	grafo->InsertaArista("B", "C", 17);
	grafo->InsertaArista("B", "D", 83);
	grafo->InsertaArista("B", "F", 97);
	grafo->InsertaArista("B", "G", 60);
	grafo->InsertaArista("C", "A", 4);
	grafo->InsertaArista("D", "B", 97);
	grafo->InsertaArista("D", "C", 37);
	grafo->InsertaArista("D", "D", 22);
	grafo->InsertaArista("D", "E", 41);
	grafo->InsertaArista("D", "G", 64);
	grafo->InsertaArista("E", "B", 8);
	grafo->InsertaArista("E", "E", 45);
	grafo->InsertaArista("E", "F", 92);
	grafo->InsertaArista("F", "A", 12);
	grafo->InsertaArista("F", "B", 8);
	grafo->InsertaArista("F", "E", 42);
	grafo->InsertaArista("G", "D", 17);

	while (opc != 13)
	{
		system("cls");
		cout << "1. Insertar vertice" << endl;
		cout << "2. Insertar arista" << endl;
		cout << "3. Obtener tamano" << endl;
		cout << "4. Mostrar lista de adyacencia" << endl;
		cout << "5. Eliminar vertice" << endl;
		cout << "6. Eliminar arista" << endl;
		cout << "7. Eliminar todo" << endl;
		cout << "8. Recorrido en anchura" << endl;
		cout << "9. Recorrido en profundidad" << endl;
		cout << "10. Primero en anchura" << endl;
		cout << "11. Primero en profundidad" << endl;
		cout << "12. Primero el mejor" << endl;
		cout << "13. Salir" << endl;

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
		case 8:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string nombre;
				cout << "Ingrese el nombre del vertice origen: ";
				cin >> nombre;

				grafo->RecorridoAnchura(nombre);
			}

			break;
		}
		case 9:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string nombre;
				cout << "Ingrese el nombre del vertice origen: ";
				cin >> nombre;

				grafo->RecorridoProfundidad(nombre);
			}

			break;
		}
		case 10:
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

				grafo->PrimeroEnAnchura(ori, dest);
			}

			break;
		}
		case 11:
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

				grafo->PrimeroEnProfundidad(ori, dest);
			}

			break;
		}
		case 12:
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

				grafo->PrimeroElMejor(ori, dest);
			}

			break;
		}
		}

		cin.get();
		cin.get();
	}

}
