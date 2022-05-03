#pragma once
#include "Vertice.h"
#include "Arista.h"
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <unordered_set>

using namespace std;

class Grafo
{
	Vertice* primero;
	int tamano;

public:
	Grafo();
	bool EstaVacio(); // Retorna true si el grafo está vacío
	int ObtenerTamano(); // Retorna el número de vertices en el grafo
	Vertice* ObtenerVertice(string nombre); // Retornar el vertice que tenga el nombre especificado
	void InsertaVertice(string nombre); // Inserta un vertice al grafo
	void InsertaArista(string ori, string dest, int precio); // Inserta arista entre los dos vertices especificados con el precio especificado
	void MostrarListaAdyacencia(); // Mostrar todos los vertices con sus aristas y precios
	void EliminarVertice(string nombre); // Elimina el vertice con el nombre especificado
	void EliminarArista(string ori, string dest); // Elimina la arista entre los dos vertices especificados
	void EliminarTodo(); // Elimina todos los vertices y aristas del grafo
	void EliminarAristas(Vertice* vertice); // Elimina las aristas del vertice especificado
	void EliminarAristasDestino(string dest); // Elimina las aristas que tienen como destino el vertice especificado
	void RecorridoAnchura(string origen); // Recorre el grafo con el algoritmo de anchura
	void RecorridoProfundidad(string origen); // Recorre el grafo con el algoritmo de profundidad
	void PrimeroEnAnchura(string origen, string destino); // Despliega la ruta entre los dos vertices especificados con el algoritmo de primero en anchura
	void PrimeroEnProfundidad(string origen, string destino); // Despliega la ruta entre los dos vertices especificados con el algoritmo de primero en profundidad
	void PrimeroElMejor(string origen, string destino); // Despliega la ruta entre los dos vertices especificados con el algoritmo de primero el mejor
	void MostrarRutaEncontrada(stack<pair<Vertice*, Vertice*>> pilaPar, Vertice* vdest); // Despliega la ruta encontrada
	void Dijkstra(string origen); // Despliega la ruta más corta entre el origen y los demás vertices
	void Kruskal(); // Genera el arbol recubridor minimo con el algoritmo de kruskal
	void Prim(string origen);// Genera el arbol recubridor minimo con el algoritmo de Prim
};

