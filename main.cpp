/*
NOMBRE Y APELLIDO: IGNACIO LACIOPPA
DNI: 38788859
LEGAJO: 19992
FACULTAD: UTN FRGP
TP FINAL DE LABORATORIO 2, PRIMER CUATRIMESTRE 2018

TEMATICA DEL PROYECTO:  PROGRAMA DE GESTION DE REPARACION DE COMPUTADORAS
                        DONDE SE CARGA CLIENTES, TECNICOS ASIGNADOS A LAS REPARACIONES
                        QUE PODRAN INICIAR Y FINALIZAR REPARACIONES Y CARGAR REPUESTOS DE COMPUTACION


*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <ctype.h>
#include <locale.h>

using namespace std;

#include "Extras.h"
#include "TECNICOS.H"
#include "LOGIN.h"
#include "Fecha.h"
#include "Clientes.h"
#include "Repuestos.h"
#include "Reparaciones.h"
#include "Reportes.h"
#include "Mantenimiento.h"
#include "Menues.h"

int main(){
    Fecha f;
    loading_bar(22,"Iniciando IL TALLER PC...",70);
    textcolor(15,0);
    menu_login();
}
