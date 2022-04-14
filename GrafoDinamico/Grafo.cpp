#include "Grafo.h"

Grafo::Grafo()
{
	primero = NULL;
	tamano = 0;
}

bool Grafo::EstaVacio()
{
	return tamano == 0;
}

int Grafo::ObtenerTamano()
{
	return tamano;
}

Vertice* Grafo::ObtenerVertice(string nombre)
{
	Vertice* i = primero;

	while (i != NULL)
	{
		if (i->nombre == nombre)
			return i;

		i = i->sig;
	}

	return NULL;
}

void Grafo::InsertaVertice(string nombre)
{
	if (ObtenerVertice(nombre) == NULL)
	{
		Vertice* nuevo = new Vertice(nombre);

		if (EstaVacio())
			primero = nuevo;
		else
		{
			Vertice* i = primero;

			while (i->sig != NULL)
				i = i->sig;

			i->sig = nuevo;
		}

		tamano++;
	}
	else
		cout << "Ese vertice ya existe en el grafo" << endl;
}

void Grafo::InsertaArista(string ori, string dest, int precio)
{
	Vertice* vori = ObtenerVertice(ori);
	Vertice* vdest = ObtenerVertice(dest);

	if (vori == NULL)
		cout << "El vertice origen no existe" << endl;

	if (vdest == NULL)
		cout << "El vertice destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		Arista* nueva = new Arista(vdest, precio);

		if (vori->ari == NULL)
			vori->ari = nueva;
		else
		{
			Arista* j = vori->ari;

			while (j->sig != NULL)
				j = j->sig;
			
			j->sig = nueva;
		}
	}
}

void Grafo::MostrarListaAdyacencia()
{
	Vertice* i = primero;

	while (i != NULL)
	{
		Arista* j = i->ari;
		cout << i->nombre << " = ";
		
		while (j != NULL)
		{
			cout << i->nombre << "->" << j->precio << "->" << j->dest->nombre << ",";
			j = j->sig;
		}

		cout << endl;
		i = i->sig;
	}
}

void Grafo::EliminarAristas(Vertice* vertice)
{
	if (vertice == NULL)
		return;

	Arista* i = vertice->ari;

	while (vertice->ari != NULL)
	{
		i = vertice->ari;
		vertice->ari = vertice->ari->sig;
		cout << "Arista " << vertice->nombre << "->" << i->dest->nombre << " eliminada" << endl;
		delete(i);
	}
}

void Grafo::EliminarAristasDestino(string dest)
{
	Vertice* i = primero;

	while (i != NULL)
	{
		if (i->nombre == dest || i->ari == NULL)
		{
			i = i->sig;
			continue;
		}

		if (i->ari->dest->nombre == dest)
		{
			Arista* j = i->ari;
			i->ari = i->ari->sig;
			cout << "Arista " << i->nombre << "->" << dest << " eliminada" << endl;
			delete(j);
		}
		else
		{
			Arista* x = i->ari;
			Arista* y = x->sig;

			while (y != NULL)
			{
				if (y->dest->nombre == dest)
				{
					x->sig = y->sig;
					cout << "Arista " << i->nombre << "->" << dest << " eliminada" << endl;
					delete(y);
				}

				x = y;
				y = y->sig;
			}
		}

		i = i->sig;
	}
}

void Grafo::EliminarVertice(string nombre)
{
	if (primero->nombre == nombre)
	{
		Vertice* i = primero;
		primero = primero->sig;
		EliminarAristas(i);
		EliminarAristasDestino(i->nombre);
		cout << "Vertice " << nombre << " fue eliminado" << endl;
		delete(i);
		tamano--;
	}
	else 
	{
		Vertice* i = primero;
		Vertice* j = i->sig;
		bool existe = false;

		while (j != NULL)
		{
			if (j->nombre == nombre)
			{
				i->sig = j->sig;
				EliminarAristas(j);
				EliminarAristasDestino(j->nombre);
				cout << "Vertice " << nombre << " fue eliminado" << endl;
				delete(j);
				tamano--;
				existe = true;
				break;
			}

			i = j;
			j = j->sig;
		}

		if (!existe)
			cout << "El vertice especificado no existe" << endl;
	}
}

void Grafo::EliminarArista(string ori, string dest)
{
	Vertice* vori = ObtenerVertice(ori);
	Vertice* vdest = ObtenerVertice(dest);

	if (vori == NULL)
		cout << "El vertice origen no existe" << endl;

	if (vdest == NULL)
		cout << "El vertice destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		if (vori->ari->dest == vdest)
		{
			Arista* i = vori->ari;
			vori->ari = vori->ari->sig;
			cout << "Arista " << ori << "->" << dest << " eliminada" << endl;
			delete(i);
		}
		else
		{
			Arista* i = vori->ari;
			Arista* j = i->sig;

			while (j != NULL)
			{
				if (j->dest == vdest)
				{
					i->sig = j->sig;
					cout << "Arista " << ori << "->" << dest << " eliminada" << endl;
					delete(j);
					break;
				}

				i = j;
				j = j->sig;
			}
		}
	}
}

void Grafo::EliminarTodo()
{
	Vertice* i = primero;

	while (primero != NULL)
	{
		i = primero;
		primero = primero->sig;
		EliminarAristas(i);
		EliminarAristasDestino(i->nombre);
		cout << "Vertice " << i->nombre << " eliminado" << endl;
		delete(i);
		tamano--;
	}
}

void Grafo::RecorridoAnchura(string origen)
{
	Vertice* vOrigen = ObtenerVertice(origen);

	if (vOrigen != NULL)
	{
		cout << "Origen: " << origen << endl;
		cout << "En anchura: ";
		queue<Vertice*> cola;
		list<Vertice*> lista;
		cola.push(vOrigen);

		while (!cola.empty())
		{
			Vertice* vActual = cola.front();
			cola.pop();

			list<Vertice*>::iterator iter = find(lista.begin(), lista.end(), vActual);

			if (iter == lista.end())
			{
				cout << vActual->nombre << ", ";
				lista.push_back(vActual);
			}

			Arista* i = vActual->ari;

			while (i != NULL)
			{
				Vertice* vDestino = i->dest;
				iter = find(lista.begin(), lista.end(), vDestino);

				if (iter == lista.end())
					cola.push(vDestino);

				i = i->sig;
			}
		}
	}
	else
		cout << "El vertice especificado no existe" << endl;
}

void Grafo::RecorridoProfundidad(string origen)
{
	Vertice* vOrigen = ObtenerVertice(origen);

	if (vOrigen != NULL)
	{
		cout << "Origen: " << origen << endl;
		cout << "En profundidad: ";
		stack<Vertice*> pila;
		list<Vertice*> lista;
		pila.push(vOrigen);

		while (!pila.empty())
		{
			Vertice* vActual = pila.top();
			pila.pop();

			list<Vertice*>::iterator iter = find(lista.begin(), lista.end(), vActual);

			if (iter == lista.end())
			{
				cout << vActual->nombre << ", ";
				lista.push_back(vActual);
			}

			Arista* i = vActual->ari;

			while (i != NULL)
			{
				Vertice* vDestino = i->dest;
				iter = find(lista.begin(), lista.end(), vDestino);

				if (iter == lista.end())
					pila.push(vDestino);

				i = i->sig;
			}
		}
	}
	else
		cout << "El vertice especificado no existe" << endl;
}