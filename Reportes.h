#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

/*
SI TODO VA BIEN PRESENTAR ESTOS REPORTE PARA EL FINAL
REPORTE 5: A PARTIR DE UN DNI DE UN CLIENTE MOSTRAR LA CANTIDAD DINERO QUE GASTO EN TOTAL

*/

void reporte_5();

///FUNCIONES GENERALES
void poner_cero_vector(int *v, int tam){
    for (int i = 0 ; i < tam ; i++)v[i]=0;
}

int contar_reparaciones_idtec(int ID){
  Reparaciones aux;
  int pos = 0;
  int cant = 0;
  while(aux.leer_reparacion(pos)){
    if(ID == aux.Getidtec()){
        cant++;
    }
    pos++;
    }
    return cant;
}

///*****************************************************************************

///REPORTE 1: CANTIDAD DE REPARACIONES POR MES
void reporte_1(){
    clrscr();
    titulo_programa();

    Reparaciones rep;
    int posrep = 0;
    int vec[12];
    poner_cero_vector(vec,12);
    int cant = cuenta_reparaciones_finalizadas();

    while(rep.leer_reparacion(posrep++)){
        if (rep.Getestado()==true) vec[rep.Getfinalf().getMes()-1]++;
    }

    cout<<"--------------------------------------------------------"<<endl<<endl;
    cout<<"CANTIDAD DE REPARACIONES FINALIZADAS POR MES"<<endl<<endl;
    for (int i=0;i<12;i++){
        if (i==0)cout<<"ENERO       : "<<vec[i]<<endl<<endl;
        if (i==1)cout<<"FEBRERO     : "<<vec[i]<<endl<<endl;
        if (i==2)cout<<"MARZO       : "<<vec[i]<<endl<<endl;
        if (i==3)cout<<"ABRIL       : "<<vec[i]<<endl<<endl;
        if (i==4)cout<<"MAYO        : "<<vec[i]<<endl<<endl;
        if (i==5)cout<<"JUNIO       : "<<vec[i]<<endl<<endl;
        if (i==6)cout<<"JULIO       : "<<vec[i]<<endl<<endl;
        if (i==7)cout<<"AGOSTO      : "<<vec[i]<<endl<<endl;
        if (i==8)cout<<"SEPTIEMBRE  : "<<vec[i]<<endl<<endl;
        if (i==9)cout<<"OCTUBRE     : "<<vec[i]<<endl<<endl;
        if (i==10)cout<<"NOVIEMBRE  : "<<vec[i]<<endl<<endl;
        if (i==11)cout<<"DICIEMBRE  : "<<vec[i]<<endl<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl<<endl;
    cout<<"REPARACIONES FINALIZADAS EN TOTAL: "<<cant<<endl<<endl;
    cout<<"--------------------------------------------------------"<<endl<<endl;
    pause();
    return;
}

///REPORTE 2: INGRESOS GANADOS POR REPARACION POR MES Y DETERMINAR UN PROMEDIO DE GANANCIA CON LAS REPARACIONES FINALIZADAS
void reporte_2(){
    clrscr();
    titulo_programa();

    Reparaciones rep;
    int vec[12];
    int posrep = 0;
    int cant = cuenta_reparaciones_finalizadas();
    int acum = 0;
    float promedio = 0;
    poner_cero_vector(vec,12);

    while (rep.leer_reparacion(posrep++)){
        if (rep.Getestado()==true){
            vec[rep.Getfinalf().getMes()-1]+=rep.Getprecio();
            acum+=rep.Getprecio();
        }
    }
    cout<<"--------------------------------------------------------"<<endl<<endl;
    cout<<"GANANCIA TOTAL POR MES"<<endl<<endl;
     for (int i=0;i<12;i++){
        if (i==0)cout<<"ENERO       : "<<vec[i]<<endl<<endl;
        if (i==1)cout<<"FEBRERO     : "<<vec[i]<<endl<<endl;
        if (i==2)cout<<"MARZO       : "<<vec[i]<<endl<<endl;
        if (i==3)cout<<"ABRIL       : "<<vec[i]<<endl<<endl;
        if (i==4)cout<<"MAYO        : "<<vec[i]<<endl<<endl;
        if (i==5)cout<<"JUNIO       : "<<vec[i]<<endl<<endl;
        if (i==6)cout<<"JULIO       : "<<vec[i]<<endl<<endl;
        if (i==7)cout<<"AGOSTO      : "<<vec[i]<<endl<<endl;
        if (i==8)cout<<"SEPTIEMBRE  : "<<vec[i]<<endl<<endl;
        if (i==9)cout<<"OCTUBRE     : "<<vec[i]<<endl<<endl;
        if (i==10)cout<<"NOVIEMBRE  : "<<vec[i]<<endl<<endl;
        if (i==11)cout<<"DICIEMBRE  : "<<vec[i]<<endl<<endl;
    }
    if (acum == 0 || cant == 0){
        cout<<"--------------------------------------------------------"<<endl<<endl;
        cout<<"PROMEDIO DE GANANCIA :"<<promedio<<endl<<endl;
        cout<<"--------------------------------------------------------"<<endl<<endl;
        pause();
        return;
    }
    promedio = acum / cant;
    cout<<"--------------------------------------------------------"<<endl<<endl;
    cout<<"PROMEDIO DE GANANCIA :"<<promedio<<endl<<endl;
    cout<<"--------------------------------------------------------"<<endl<<endl;
    pause();
    return;
}

///REPORTE 3: PARA TODOS LOS TECNICOS LA CANTIDAD DE REPARACIONES FINALIZADAS
void reporte_3(){
    clrscr();
    titulo_programa();
    cout<<"CANTIDAD DE REPARACIONES FINALIZADAS POR TECNICOS"<<endl<<endl;

    Reparaciones rep;
    Tecnicos tec;
    int cant_tec = Contar_Registros_Tecnicos();
    int *vec;
    vec = new int [cant_tec];
    poner_cero_vector(vec,cant_tec);
    int pos = 0;
    int repar;

    while (rep.leer_reparacion(pos)){
        if (rep.Getestado()==true){
            repar = contar_reparaciones_idtec(rep.Getidtec());
            vec[rep.Getidtec()-1]=repar;
        }
        pos++;
    }
    cout<<"-------------------------------------------------"<<endl<<endl;
    for (int i=0 ; i<cant_tec ; i++){
        tec.Leer_Tecnico(i);
        if (tec.getestado()==true){
             cout<<tec.getnombre()<<", "<<tec.getapellido()<<"\t\t"<<vec[i]<<endl<<endl;
        }
    }
    cout<<"-------------------------------------------------"<<endl<<endl;

    delete vec;

    pause();
    return;
}

///REPORTE 4: CANTIDAD DE REPUESTOS POR CATEGORIA
void reporte_4(){
    clrscr();
    titulo_programa();
    cout<<"CANTIDAD DE REPUESTOS POR CATEGORIAS"<<" "<<"(Tambien se cuentan los que estan en Falta)"<<endl<<endl;

    Repuestos rep;
    int vec[7];
    int posrepu=0;

    poner_cero_vector(vec,7);

    while (rep.leer_repuesto(posrepu++)){
        vec[rep.Getcategoria()-1]++;
    }
    cout<<endl<<endl;
    cout<<"-------------------------------------------------"<<endl<<endl;
    for (int i=0 ; i<7 ; i++){
        if (i==0)cout<<"MOTHERBOARDS      :"<<vec[i]<<endl<<endl;
        if (i==1)cout<<"MICROPROCESADORES :"<<vec[i]<<endl<<endl;
        if (i==2)cout<<"MEMORIAS RAM      :"<<vec[i]<<endl<<endl;
        if (i==3)cout<<"DISCOS (HDD & SDD):"<<vec[i]<<endl<<endl;
        if (i==4)cout<<"PLACAS DE VIDEO   :"<<vec[i]<<endl<<endl;
        if (i==5)cout<<"FUENTES           :"<<vec[i]<<endl<<endl;
        if (i==6)cout<<"VARIOS            :"<<vec[i]<<endl<<endl;
    }
    cout<<"-------------------------------------------------"<<endl<<endl;
    pause();
    return;
}

///REPORTE 5: A PARTIR DE UN DNI DE UN CLIENTE MOSTRAR LA CANTIDAD DE DINERO QUE GASTO EN REPARACIONES
void reporte_5(){
    clrscr();
    titulo_programa();

    Cliente cli;
    Reparaciones rep;
    long dni;
    int buscardni;
    float acumprecio=0;
    int posr=0;

    cout<<"BUSCAR CLIENTE, MUESTRA DINERO GASTADO EN TOTAL Y QUE NUMERO DE ORDENES TIENE A SU NOMBRE"<<endl<<endl;
    cout<<"Ingrese DNI: ";
    cin>>dni;

    buscardni=buscar_cliente(dni);
    if (buscardni == -1){
        clrscr();
        titulo_programa();
        cout<<"NO SE ENCONTRO DNI!!!"<<endl;
        pause();
        return;
    }
    cli.leerCliente(buscardni);
    if (cli.getestado()==false){
        clrscr();
        titulo_programa();
        cout<<"CLIENTE DADO DE BAJA!!!"<<endl;
        pause();
        return;
    }
    clrscr();
    titulo_programa();
    cout<<"CLIENTE ENCONTRADO!!!"<<endl<<endl;
    cout<<"Nombre y Apellido: "<<cli.getnombre()<<", "<<cli.getapellido()<<" | DNI:"<<cli.getdni()<<endl<<endl;
    cout<<"Ordenes Finalizadas Registradas a este cliente: ";
    while(rep.leer_reparacion(posr++)){
        if (dni == rep.getdni() && rep.Getestado()==true){
            acumprecio = rep.Getprecio() + acumprecio;
            cout<<"| "<<rep.Getnro_orden()<<" |";
        }
    }
    cout<<endl<<endl;
    cout<<"CANTIDAD DE DINERO GASTADO EN TOTAL: $"<<acumprecio<<endl<<endl;

    pause();
    return;

}


#endif // REPORTES_H_INCLUDED
