#include <mysql.h>
#include <iostream>
#include <iostream>
#include "Cliente.h"
using namespace std;
int q_estado;
int main()
{
   /* MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "Empresa@123", "db_empresa", 3306, NULL, 0);
    if (conectar)
    {
        //cout << "Conexion Exitosa..." << endl;
        string puesto;
        cout << "Ingrese Puesto: ";
        cin >> puesto;
        string insert = "insert into puestos(puesto) values('" + puesto + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar,i);
        if  (!q_estado)
        {
            cout << "Ingreso Exitoso..." << endl;
        }
        else
        {
            cout << "xxx Error al Ingresar xxx" << endl;
        }
        string consulta = "select * from puestos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado)
        {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado))
            {
                cout << fila[0] << " , "<< fila[1] << endl;
            }
        }
        else
        {
            cout << "xxx Error al consultar xxx" << endl;
        }

     }
    else
    {
       // cout << "Error en la coexion..." << endl;
    }*/
    
    string nit, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;
    cout << "Ingrese Nit: ";
    getline(cin, nit);
    cout << "Ingrese Nombres:";
    getline(cin, nombres);
    cout << "Ingrese Apellidos:";
    getline(cin, apellidos);
    cout << "Ingrese Direccion:";
    getline(cin, direccion);
    cout << "Ingrese Telefono :";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Fecha Nacimieno :";
    cin >> fecha_nacimiento;
    
    Cliente c = Cliente(nombres,apellidos,direccion,telefono,fecha_nacimiento,nit);
    c.crear();
    c.leer();
    system("pause");
    return 0;

}

