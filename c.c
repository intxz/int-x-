#include <iostream>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
	
	MYSQL *conn;
	int err;
	MYSQL_RES resultado;
	MYSQL_ROW row;
	
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		printf("Error al crear la conexion\n");
		exit (1);
	}
	
	conn = mysql_real_connect(conn,"localhost","user","pass","bd",0,NULL,0);
	if (conn == NULL)
	{
		printf("Error al crear la conexion\n");
		exit (1);
	}
	
	char[20] jugador;
	printf("Nombre de un jugador:");
	scanf(%s, jugador);
	
	char[20] pasaber;
	strcpy(pasaber, "SELECT Partida.PARTICIPANTES FROM (Jugador, Partida, Relacion) WHERE
		   Jugador.NOMBRE = '");
		   strcat(pasaber,nombre);
	strcat("AND Partida.ID = Relacion.IDPARTIDA AND Jugador.ID = Relacion.IDJUGADOR");
	
	err=mysql_query (conn, pasaber);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	resultado = mysql_store_result (conn);
	
	row = mysql_fetch_row (resultado);
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {
			
			printf ("%s\n", row[0]);
			
			row = mysql_fetch_row (resultado);
	}
		
		mysql_close (conn);
		exit(0);
		
	
	
}

