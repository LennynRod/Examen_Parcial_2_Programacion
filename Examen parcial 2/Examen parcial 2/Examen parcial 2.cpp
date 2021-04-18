#include <iostream>
#include<conio.h>
#include<mysql.h>

using namespace std;
int q_estado;

void Crear_registro_puesto();
void Crear_registro_empleado();
void Leer_registro_puesto();
void Leer_registro_empleado();
void Actualizar_registro_puesto();
void Actualizar_registro_empleado();
void Borrar_registro_puesto();
void Borrar_registro_empleado();
int main()
{



	int op = 0, op1 = 0, op2 = 0;


	cout << "*****************MENU******************" << endl << endl;
	cout << "SELECCIONE LA TABLA QUE DESEA EDITAR:" << endl << endl;
	cout << "Puesto...................................1" << endl;
	cout << "Empleado.................................2" << endl;
	cout << "Salir....................................3" << endl << endl;
	cin >> op;

	switch (op) {

	case 1: system("cls");

		cout << "*************Editar_Tabla_Puesto**************" << endl << endl;
		cout << "SELECCIONE LA OPERACION QUE DESEA REALIZAR..." << endl << endl;
		cout << "Crear registro.......................1" << endl;
		cout << "Leer registro........................2" << endl;
		cout << "Actualizar registro..................3" << endl;
		cout << "Borrar registro......................4" << endl;
		cout << "Regresar.............................5" << endl << endl;
		cin >> op1;

		switch (op1) {
			case 1: Crear_registro_puesto();
			break;
		case 2: Leer_registro_puesto();
			break;
			case 3: Actualizar_registro_puesto();
			break;
			case 4:  Borrar_registro_puesto();
			break;
		case 5: system("cls"); main();
			break; 
		default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
		}

		break;
		
	case 2:  system("cls");

		cout << "************Editar_Tabla_Empleado**************" << endl << endl;
		cout << "SELECCIONE LA OPERACION QUE DESEA REALIZAR..." << endl << endl;
		cout << "Crear registro.......................1" << endl;
		cout << "Leer registro........................2" << endl;
		cout << "Actualizar registro..................3" << endl;
		cout << "Borrar registro......................4" << endl;
		cout << "Regresar.............................5" << endl << endl;
		cin >> op2;

		switch (op2) {
			case 1: Crear_registro_empleado();
			break;
			case 2: Leer_registro_empleado();
				break;
				case 3: Actualizar_registro_empleado();
				break;
				case 4:  Borrar_registro_empleado();
				break;
			case 5: system("cls"); main();
				break;
		default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
		}


		break;
	case 3: system("exit");
		break;
	default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
	}


}
void Crear_registro_puesto() {

	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_empleados", 3306, NULL, 0);


	if (conectar) {

		string puesto;
		cout << "Ingrese el puesto:" << endl;
		cin >> puesto;
		string insert = "insert into puestos(puesto) values('" + puesto + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Ingreso de registro exitoso..." << endl;
		}
		else {
			cout << "error al ingresar..." << endl;
		}
	}
	else {
		cout << "error en la conexión..." << endl;
	}
	system("pause");	system("cls"); main();
}
void Crear_registro_empleado() {

	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_empleados", 3306, NULL, 0);


	if (conectar) {

		string c1, c2,c3,c4,c5,c6,c7,c8,c9,c10;
		cout << "Ingrese el nombre del empleado:" << endl;
		cin >> c1;
		cout << "Ingrese el apellido del empleado:" << endl;
		cin >> c2;
		cout << "Ingrese la dirección del empleado:" << endl;
		cin >> c3;
		cout << "Ingrese el telefono del empleado:" << endl;
		cin >> c4;
		cout << "Ingrese el numero de DPI del empleado:" << endl;
		cin >> c5;
		cout << "Ingrese el genero del empleado  (M o F):" << endl;
		cin >> c6;
		cout << "Ingrese la fecha de nacimiento del emplado en formato AA-MM-DD: " << endl;
		cin >> c7;
		cout << "Ingrese el ID de puesto del empleado: " << endl;
		cin >> c8;
		cout << "Ingrese la fecha de inicio de labores del empleado en formato AA-MM-DD:" << endl;
		cin >> c9;
		cout << "Ingrese la fecha de ingreso del empleado en formato AA-MM-DD:" << endl;
		cin >> c10;

	

		string insert = "insert into empleados(nombres,apellidos,direccion,telefono,DPI,genero,fecha_nacimiento,idPuesto,fecha_inicio_labores,fechaingreso) values('" + c1 + "','" + c2 + "','" + c3 + "','" + c4 + "','" + c5 + "','" + c6 + "','" + c7 + "','" + c8 + "','" + c9 + "','" + c10 + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Ingreso exitoso..." << endl;
		}
		else {
			cout << "error al ingresar, es posible que no se hallan ingresado los datos en el formato que se le solicitan..." << endl;
		}
	}
	else {
		cout << "error en la conexión a la base de datos ..." << endl;
	}
	system("pause");	system("cls"); main();
}
void Leer_registro_puesto() {

	system("cls");

	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_empleados", 3306, NULL, 0);


	if (conectar) {

		string consulta = "select * from puestos";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << ", " << fila[1]       << endl;


			}

		}
		else {
			cout << "error al consultar..." << endl;
		}
	}
	else {
		cout << "error en la conexión..." << endl;
	}
	system("pause");	system("cls"); main();
}
void Leer_registro_empleado() {

	system("cls");

	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_empleados", 3306, NULL, 0);


	if (conectar) {
		
		string consulta = "select * from empleados";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {

			cout << "|Nombres|Apellidos|Direccion|Tel.|DPI|Genero|Fecha_nacimiento|ID_Puesto|Fecha_inicio_labores|fecha_ingreso|" << endl<<endl;

			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8] << ", " << fila[9] << ", " << fila[10] << endl;


			}

		}
		
		else {
			cout << "error al consultar..." << endl;
		}
	}
	else {
		cout << "error en la conexión..." << endl;
	}
	system("pause");	system("cls"); main();
}
void Actualizar_registro_puesto() {

	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_empleados", 3306, NULL, 0);


	if (conectar) {

		string puesto;
		string idpuesto;
		cout << "Ingrese la ID del puesto que desa actualizar:" << endl;
		cin >> idpuesto;
		cout << "Ingrese la el nuevo puesto:" << endl;
		cin >> puesto;

		string update = "update db_empleados.puestos set puesto=('" + puesto + "') where('" + idpuesto + "')=idpuestos";
		const char* i = update.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Actualizacion exitosa..." << endl;
		}
		else {
			cout << "Error al Actualizar..." << endl;
		}
	}
	else {
		cout << "Error en la conexión..." << endl;
	}

	system("pause");	system("cls"); main();
}
void Actualizar_registro_empleado() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_empleados", 3306, NULL, 0);


	if (conectar) {

		string idempleado,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;

		cout << "Ingrese la ID del empleado que desa actualizar:" << endl;
		cin >> idempleado;

		cout << "Ingrese el nombre del empleado:" << endl;
		cin >> c1;
		cout << "Ingrese el apellido del empleado:" << endl;
		cin >> c2;
		cout << "Ingrese la dirección del empleado:" << endl;
		cin >> c3;
		cout << "Ingrese el telefono del empleado:" << endl;
		cin >> c4;
		cout << "Ingrese el numero de DPI del empleado:" << endl;
		cin >> c5;
		cout << "Ingrese el genero del empleado  (M o F):" << endl;
		cin >> c6;
		cout << "Ingrese la fecha de nacimiento del emplado en formato AA-MM-DD: " << endl;
		cin >> c7;
		cout << "Ingrese el ID de puesto del empleado: " << endl;
		cin >> c8;
		cout << "Ingrese la fecha de inicio de labores del empleado en formato AA-MM-DD:" << endl;
		cin >> c9;
		cout << "Ingrese la fecha de ingreso del empleado en formato AA-MM-DD:" << endl;
		cin >> c10;

		string insert = "update db_empleados.empleados set  nombres =('" + c1 + "'),apellidos =('" + c2 + "'),direccion =('" + c3 + "' ), telefono = ('" + c4 + "'), DPI =('" + c5 + "'), genero =('" + c6 + "'), fecha_nacimiento =('" + c7 + "'), idPuesto =('" + c8 + "'), fecha_inicio_labores =('" + c9 + "'), fechaingreso =('" + c10 + "')    where('" + idempleado + "') = idEmpleados";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Actualización de datos exitosa..." << endl;
		}
		else {
			cout << "error al ingresar..." << endl;
		}
	}
	else {
		cout << "error en la conexión..." << endl;
	}



	system("pause");	system("cls"); main();

}
void Borrar_registro_puesto() {

	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_empleados", 3306, NULL, 0);


	if (conectar) {

		
		string idpuesto;
		cout << "Ingrese la ID del puesto que desea eliminar:" << endl;
		cin >> idpuesto;

		string update = "delete from db_empleados.puestos  where('" + idpuesto + "') = idpuestos";
		const char* i = update.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Eliminacion exitosa..." << endl;
		}
		else {
			cout << "Error al eliminar..." << endl;
		}
	}
	else {
		cout << "Error en la conexión..." << endl;
	}
	system("pause");	system("cls"); main();
}
void Borrar_registro_empleado() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_empleados", 3306, NULL, 0);


	if (conectar) {

		string empleado;
		string idempleado;
		cout << "Ingrese la ID del empleado que desea eliminar:" << endl;
		cin >> idempleado;

		string update = "delete from db_empleados.empleados  where('" + idempleado + "')=idEmpleados";
		const char* i = update.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Eliminacion exitosa..." << endl;
		}
		else {
			cout << "Error al eliminar..." << endl;
		}
	}
	else {
		cout << "Error en la conexión..." << endl;
	}

	system("pause");	system("cls"); main();
}