#pragma once
#include <iostream>
#include <string>
#include <mysql.h>
#include "ConeccionBD.h"
#include "Persona.h"
using namespace std;
class Cliente : Persona{

private: string nit;
public:
	Cliente()
	{
	}
	Cliente(string nom, string ape, string dire, int tel, string fn, string n) : Persona(nom, ape, dire, tel, fn)
	{
		nit = n;
	}
	//set (modificar el atributo)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setDireccion(string dire) { direccion = dire; }
	void setTelefono(int tel) { telefono = tel; }
	void setApellidos(string ape) { apellidos = ape; }
	void setFechaN(string fn) { fecha_nacimiento = fn; }

	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFechaN() { return fecha_nacimiento; }

	void crear()
	{
		int q_estado;
		ConeccionBD cn = ConeccionBD();
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string t = to_string(telefono);
			string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES('"+ nit +"','"+ nombres+"','"+apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "' ); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado)
			{
				cout << "Ingreso Exitoso..." << endl;
			}
			else
			{
				cout << "xxx Error al Ingresar la Informacion xxx" << endl;
			}
		}
		else
		{
			cout << "------Error al conectar----" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer()
	{
		int q_estado;
		ConeccionBD cn = ConeccionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado)
			{
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado))
				{
					cout << fila[0] << " , " << fila[1] <<" , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << endl;
				}
			}
			else
			{
				cout << "xxx Error al consultar xxx" << endl;
			}

		}
		else
		{
			cout << "------Error al conectar----" << endl;
		}
		cn.cerrar_conexion();
	}

};

