#pragma once
#include <iostream>

class Vertice;

class Arista
{
	int precio;
	Arista* sig;
	Vertice* dest;

	friend class Grafo;
public:
	Arista(Vertice* _dest, int precio);
};

