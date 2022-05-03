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


void Grafo::PrimeroEnAnchura(string origen, string destino)
{
	Vertice* vori = ObtenerVertice(origen);
	Vertice* vdest = ObtenerVertice(destino);

	if (vori == NULL)
		cout << "El vertice origen no existe" << endl;

	if (vdest == NULL)
		cout << "El vertice destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		queue<Vertice*> cola;
		stack<pair<Vertice*, Vertice*>> pilaPar;
		list<Vertice*> visitados;
		bool rutaEncontrada = false;
		cola.push(vori);

		while (!cola.empty())
		{
			Vertice* vActual = cola.front();
			cola.pop();

			list<Vertice*>::iterator iter = find(visitados.begin(), visitados.end(), vActual);

			if (iter == visitados.end())
			{
				if (vActual == vdest)
				{
					rutaEncontrada = true;
					MostrarRutaEncontrada(pilaPar, vdest);
					break;
				}

				visitados.push_back(vActual);
				Arista* i = vActual->ari;

				while (i != NULL)
				{
					Vertice* dest = i->dest;
					iter = find(visitados.begin(), visitados.end(), dest);

					if (iter == visitados.end())
					{
						cola.push(dest);
						pair<Vertice*, Vertice*> par;
						par.first = vActual;
						par.second = dest;
						pilaPar.push(par);
					}

					i = i->sig;
				}
			}
		}

		if (!rutaEncontrada)
			cout << "No existe una ruta entre esos dos vertices" << endl;
	}
}

void Grafo::PrimeroEnProfundidad(string origen, string destino)
{
	Vertice* vori = ObtenerVertice(origen);
	Vertice* vdest = ObtenerVertice(destino);

	if (vori == NULL)
		cout << "El vertice origen no existe" << endl;

	if (vdest == NULL)
		cout << "El vertice destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		stack<Vertice*> pila;
		stack<pair<Vertice*, Vertice*>> pilaPar;
		list<Vertice*> visitados;
		bool rutaEncontrada = false;
		pila.push(vori);

		while (!pila.empty())
		{
			Vertice* vActual = pila.top();
			pila.pop();

			list<Vertice*>::iterator iter = find(visitados.begin(), visitados.end(), vActual);

			if (iter == visitados.end())
			{
				if (vActual == vdest)
				{
					rutaEncontrada = true;
					MostrarRutaEncontrada(pilaPar, vdest);
					break;
				}

				visitados.push_back(vActual);
				Arista* i = vActual->ari;

				while (i != NULL)
				{
					Vertice* dest = i->dest;
					iter = find(visitados.begin(), visitados.end(), dest);

					if (iter == visitados.end())
					{
						pila.push(dest);
						pair<Vertice*, Vertice*> par;
						par.first = vActual;
						par.second = dest;
						pilaPar.push(par);
					}

					i = i->sig;
				}
			}
		}

		if (!rutaEncontrada)
			cout << "No existe una ruta entre esos dos vertices" << endl;
	}
}

bool OrderPorCosto(const pair<Vertice*, int>& a, const pair<Vertice*, int>& b)
{
	return a.second < b.second;
}

void Grafo::PrimeroElMejor(string origen, string destino)
{
	Vertice* vori = ObtenerVertice(origen);
	Vertice* vdest = ObtenerVertice(destino);

	if (vori == NULL)
		cout << "El vertice origen no existe" << endl;

	if (vdest == NULL)
		cout << "El vertice destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		typedef pair<Vertice*, int> parVerInt;
		typedef pair<Vertice*, Vertice*> parVerVer;
		list<parVerInt> costos, costosOrd;
		stack<parVerVer> pilaPar;
		bool rutaEncontrada = false;
		parVerInt parVI;
		parVI.first = vori;
		parVI.second = 0;
		costos.push_back(parVI);
		costosOrd.push_back(parVI);

		while (!costosOrd.empty())
		{
			Vertice* vActual = costosOrd.front().first;
			int costoActual = costosOrd.front().second;
			costosOrd.pop_front();

			if (vActual == vdest)
			{
				rutaEncontrada = true;
				MostrarRutaEncontrada(pilaPar, vdest);
				break;
			}

			Arista* i = vActual->ari;

			while (i != NULL)
			{
				Vertice* dest = i->dest;
				costoActual += i->precio;

				list<parVerInt>::iterator iter = find_if(costos.begin(), costos.end(), [&](const parVerInt& par) { return par.first == dest; });

				if (iter == costos.end())
				{
					parVI.first = dest;
					parVI.second = costoActual;
					costos.push_back(parVI);
					costosOrd.push_back(parVI);
					costosOrd.sort(OrderPorCosto);
					parVerVer parVV;
					parVV.first = vActual;
					parVV.second = dest;
					pilaPar.push(parVV);
				}
				else if (costoActual < iter->second)
				{
					iter->second = costoActual;
					iter = find_if(costosOrd.begin(), costosOrd.end(), [&](const parVerInt& par) { return par.first == dest; });
					iter->second = costoActual;
					costosOrd.sort(OrderPorCosto);
					parVerVer parVV;
					parVV.first = vActual;
					parVV.second = dest;
					pilaPar.push(parVV);
				}

				costoActual -= i->precio;
				i = i->sig;
			}
		}

		if (!rutaEncontrada)
			cout << "No existe una ruta entre esos dos vertices" << endl;
	}
}

void Grafo::MostrarRutaEncontrada(stack<pair<Vertice*, Vertice*>> pilaPar, Vertice* vdest)
{
	Vertice* destinoActual = vdest;

	while (!pilaPar.empty())
	{
		cout << destinoActual->nombre << "<-";

		while (!pilaPar.empty() && pilaPar.top().second != destinoActual)
			pilaPar.pop();

		if (!pilaPar.empty())
			destinoActual = pilaPar.top().first;
	}
}

bool CostoMinimo(const pair<Vertice*, int>& a, const pair<Vertice*, int>& b)
{
	return a.second < b.second;
}

void Grafo::Dijkstra(string origen)
{
	Vertice* vorigen = ObtenerVertice(origen);

	if (vorigen == NULL)
		cout << "El vertice origen no existe" << endl;
	else
	{
		map<Vertice*, map<Vertice*, int>> matriz;
		map<Vertice*, bool> visitados;
		map<Vertice*, Vertice*> rutas;
		map<Vertice*, int> cola;
		map<Vertice*, int> distancias;

		Vertice* vi = primero;

		// Inicializar colecciones de datos
		while (vi != NULL)
		{
			visitados[vi] = false;
			rutas[vi] = NULL;
			distancias[vi] = numeric_limits<int>::max();

			Vertice* vj = primero;

			while (vj != NULL)
			{
				matriz[vi][vj] = numeric_limits<int>::max();
				vj = vj->sig;
			}

			Arista* aj = vi->ari;

			while (aj != NULL)
			{
				matriz[vi][aj->dest] = aj->precio;
				aj = aj->sig;
			}

			vi = vi->sig;
		}

		distancias[vorigen] = 0;
		visitados[vorigen] = true;
		cola[vorigen] = distancias[vorigen];

		while (!cola.empty())
		{
			// Encuentra el vertice con el costo menor en la cola
			map<Vertice*, int>::iterator iter = min_element(cola.begin(), cola.end(), CostoMinimo);
			visitados[iter->first] = true;

			// Recorre todos los vertices que tiene como destino
			Arista* ai = iter->first->ari;

			while (ai != NULL)
			{
				if (!visitados[ai->dest])
				{
					if (distancias[ai->dest] > distancias[iter->first] + matriz[iter->first][ai->dest])
					{
						distancias[ai->dest] = distancias[iter->first] + matriz[iter->first][ai->dest];
						rutas[ai->dest] = iter->first;
						cola[ai->dest] = distancias[ai->dest];
					}
				}

				ai = ai->sig;
			}

			cola.erase(iter->first);
		}

		// Muestra los vertices destino con su respectivo peso total
		for (map<Vertice*, int>::iterator i = distancias.begin(); i != distancias.end(); i++)
			cout << i->first->nombre << ": " << i->second << endl;


		// Muestra las rutas completas
		for (map<Vertice*, Vertice*>::iterator i = rutas.begin(); i != rutas.end(); i++)
		{
			Vertice* vAct = i->first;

			while (vAct != NULL)
			{
				cout << vAct->nombre << " <- ";
				vAct = rutas[vAct];
			}

			cout << endl;
		}
	}
}

void Grafo::Kruskal()
{
	map<Vertice*, map<Vertice*, int>> matrizady;
	map<Vertice*, map<Vertice*, int>> matrizsol;
	map<Vertice*, Vertice*> conectados;

	Vertice* vi = primero;

	while (vi != NULL)
	{
		conectados[vi] = vi;

		Vertice* vj = primero;

		while (vj != NULL)
		{
			matrizady[vi][vj] = 0;
			vj = vj->sig;
		}

		Arista* aj = vi->ari;

		while (aj != NULL)
		{
			matrizady[vi][aj->dest] = aj->precio;
			aj = aj->sig;
		}

		vi = vi->sig;
	}


	Vertice* vA, * vB;
	int aristas = 1;

	while (aristas < tamano)
	{
		int min = numeric_limits<int>::max();

		for (map<Vertice*, map<Vertice*, int>>::iterator i = matrizady.begin(); i != matrizady.end(); i++)
		{
			for (map<Vertice*, int>::iterator j = i->second.begin(); j != i->second.end(); j++)
			{
				if (j->second < min && j->second != 0 && conectados[i->first] != conectados[j->first])
				{
					min = j->second;
					vA = i->first;
					vB = j->first;
				}
			}
		}

		if (conectados[vA] != conectados[vB])
		{
			matrizsol[vA][vB] = min;

			Vertice* vTemp = conectados[vB];
			conectados[vB] = conectados[vA];

			for (map<Vertice*, Vertice*>::iterator i = conectados.begin(); i != conectados.end(); i++)
			{
				if (i->second == vTemp)
					i->second = conectados[vA];
			}

			aristas++;
		}
	}

	for (map<Vertice*, map<Vertice*, int>>::iterator i = matrizsol.begin(); i != matrizsol.end(); i++)
	{
		for (map<Vertice*, int>::iterator j = i->second.begin(); j != i->second.end(); j++)
		{
			cout << i->first->nombre << " <-> " << j->second << " <-> " << j->first->nombre << endl;
		}
	}

}

void Grafo::Prim(string origen)
{
	Vertice* vOrigen = ObtenerVertice(origen);

	if (vOrigen == NULL)
	{
		cout << "El vertice origen no existe" << endl;
		return;
	}

	map<Vertice*, map<Vertice*, int>> matrizady;
	list<pair<Vertice*, pair<Vertice*, int>>> listaSolucion;
	unordered_set<Vertice*> visitados;

	Vertice* vi = primero;

	while (vi != NULL)
	{
		Vertice* vj = primero;

		while (vj != NULL)
		{
			matrizady[vi][vj] = 0;
			vj = vj->sig;
		}

		Arista* aj = vi->ari;

		while (aj != NULL)
		{
			matrizady[vi][aj->dest] = aj->precio;
			aj = aj->sig;
		}

		vi = vi->sig;
	}

	visitados.insert(vOrigen);
	int aristas = 1;

	while (aristas < tamano)
	{
		Vertice* vMinOrigen, * vMinDestino;
		int precioMin = numeric_limits<int>::max();

		for (unordered_set<Vertice*>::iterator i = visitados.begin(); i != visitados.end(); i++)
		{
			for (map<Vertice*, int>::iterator j = matrizady[*i].begin(); j != matrizady[*i].end(); j++)
			{
				if (j->second < precioMin && j->second != 0 && visitados.count(j->first) == 0)
				{
					precioMin = j->second;
					vMinOrigen = *i;
					vMinDestino = j->first;
				}
			}
		}

		listaSolucion.push_back(pair<Vertice*, pair<Vertice*, int>>(vMinOrigen, pair<Vertice*, int>(vMinDestino, precioMin)));
		visitados.insert(vMinDestino);
		aristas++;
	}

	for (list<pair<Vertice*, pair<Vertice*, int>>>::iterator i = listaSolucion.begin(); i != listaSolucion.end(); i++)
	{
		cout << i->first->nombre << " <-> " << i->second.second << " <-> " << i->second.first->nombre << endl;
	}
}