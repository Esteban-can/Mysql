#pragma once
#include <iostream>
using namespace std;
class Persona
{
protected:
	string nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0;


protected:
	Persona()
	{
	}
	Persona(string nom, string ape, string dire, int tel, string fn)
	{
		nombres = nom;
		apellidos = ape;
		direccion = dire;
		telefono = tel;
		fecha_nacimiento = fn;

	}
	

};

