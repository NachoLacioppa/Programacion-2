#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED

///****EXTRAS****

enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNCIONES UTILES

void clrscr(){
    system("cls");
}
void pause(){
    system("pause >nul");
}
void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//COLOR DE TEXTO
void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//RECUADRO
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            ///Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            ///Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            ///Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            ///Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            ///Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            ///Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            ///Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//VALIDACION DE FECHA
bool esBisiesto(int anio){
    if(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)){
        return true;
        }
        return false;
    }

bool validarFecha(int dia, int mes, int anio){
    if(anio < 0){
        return false;
    }
    if (mes < 1 || mes > 12){
        return false;
    }
    if (mes==1 || mes==12 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10){
        if (dia <1 || dia >31){
            return false;
        }
    }
    if (mes==4 || mes==6 || mes==9 || mes==11){
        if (dia < 1 || dia > 30){
        return false;
        }
    }
    if (mes == 2){
        int b;
        b=esBisiesto(anio);

        if (b==true){
            if (dia <1 || dia >29){
            return false;
            }
        }
        if (b==false){
            if (dia <1 || dia >28){
            return false;
            }
        }
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void titulo_programa(){
        recuadro(0,0,21,2);
        gotoxy(1,1);
        cout<<"***I.L. TALLER PC***"<<endl<<endl<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//COMPARACION DE FECHAS
bool comparar_fechas(int dia1,int mes1, int anio1, int dia2, int mes2, int anio2){
    if (anio1 > anio2){
        return false;
    }
    if (anio1 < anio2){
        return true;
    }
    if (anio1 == anio2){
        if (mes1 > mes2){
            return false;
        }
        if (mes1 < mes2){
            return true;
        }
        if (mes1 == mes2){
            if (dia1 > dia2){
                return false;
            }
            if (dia1 < dia2){
                return true;
            }
            if (dia1 == dia2){
                return true;
            }
        }
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loading_bar(int tambarra, char *v,int tiempo){
    textcolor(14,0);
    cout<<"\n\n\t"<<v<<"\n\n";
    char a=177, b=219;
    cout<<"\t";
    textcolor(10,0);
    for (int i=0;i<=tambarra;i++)
    cout<<a;
    cout<<"\r";
    cout<<"\t";
    for (int i=0;i<=tambarra;i++){
        cout<<b;
        Sleep(tiempo);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//SALIDA
int salida(){
    char salir;
    clrscr();
    titulo_programa();
    cout<<"Desea salir del programa? (S/N) ";
    cin>>salir;

    switch(salir){
    case 's':
    case 'S':
        clrscr();
        titulo_programa();
        cout<<"HASTA LUEGO!"<<endl;
        loading_bar(20,"Cerrando Programa...",70);
        exit(1);
        break;

    case 'n':
    case 'N':
        clrscr();
        return 1;
        break;

    default:
        cout<<"OPCION INVALIDA"<<endl;
        pause();
        break;

    }
    return 0;
}


#endif // EXTRAS_H_INCLUDED
