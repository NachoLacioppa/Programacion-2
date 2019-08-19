#ifndef REPARACIONES_H
#define REPARACIONES_H

const char *A_REPARACIONES = "ARCHIVOS/Reparacion.dat";
const char *BKP_REPARACIONES = "BKP/Reparacion.BK";


/*
REPARACIONES:

-INICIAR: LISTO
-FINALIZAR: LISTO
-LISTAR: LISTO

***VALIDAR FECHA DE INICIO Y FINAL DE REPARACION
***EDITAR REPARACION


*/

class Reparaciones
{
     private:

        ///inicio
        int nro_orden;
        int idtec;
        char pass[10];
        long dni;
        char tipo[20];
        char marca[20];
        char modelo[20];
        char desc_inicio[150];
        Fecha iniciof;
        ///final
        Fecha finalf;
        int cod_rep;
        float precio;
        char desc_final[150];
        ///inicio y final
        bool estado;

    public:

        ///CONSTRUCTOR
        Reparaciones() {}

        ///GET
        int Getnro_orden() { return nro_orden; }
        int Getcod_rep() { return cod_rep; }
        int Getidtec(){return idtec;}
        char *Getpass() { return pass; }
        long getdni(){return dni;}
        float Getprecio() { return precio; }
        Fecha Getiniciof(){return iniciof;}
        Fecha Getfinalf(){return finalf;}
        char *Gettipo(){ return tipo; }
        char *Getmarca(){ return marca; }
        char *Getmodelo(){ return modelo; }
        char *Getdesc_inicio() { return desc_inicio; }
        char *Getdesc_final() { return desc_final; }
        bool Getestado(){return estado;}

        ///SET
        void Setidtec(int val) { idtec = val; }
        void Setcod_rep(int val) { cod_rep = val; }
        void Setnro_orden(int val) { nro_orden = val; }
        void Setprecio(float val) { precio = val; }
        void setdni(long val){dni=val;}
        void Setpass(char *val){strcpy(val,pass);}
        void Settipo(char *val){strcpy(val,tipo);}
        void Setmarca(char *val){strcpy(val,marca);}
        void Setmodelo(char *val){strcpy(val,modelo);}
        void Setiniciof(Fecha val){iniciof = val;}
        void Setfinalf(Fecha val){finalf = val;}
        void Setdesc_inicio(char *val) { strcpy(val,desc_inicio); }
        void Setdesc_final(char *val) { strcpy(val,desc_final); }
        void Setestado(bool val){estado = val;}

        ///FUNCIONES PROTOTIPO
        bool iniciar_reparacion();
        bool finalizar_reparacion();
        void guardar_reparacion();
        int leer_reparacion(int );
        void modificar_reparacion_de_disco(int );
        void mostrar_reparaciones_nofinalizadas();
        void mostrar_reparaciones_finalizadas();

};

///**************************************FUNCIONES EXTERNAS DE LA CLASE REPUESTOS**************************************

///BUSCAR REPARACION
int buscar_nro_orden(int ord){
    Reparaciones r;
    int pos = 0;
    while(r.leer_reparacion(pos)){
        if(ord == r.Getnro_orden()){
            return pos;
        }
    pos++;
    }
    return -1;
}
///COMPARAR FECHA DE ENTREGA CON INICIO
bool verificarFecha(int nord, Fecha finalf){
  int pos = buscar_nro_orden(nord);
  Reparaciones aux;
  aux.leer_reparacion(pos);
  Fecha reg;
  reg = aux.Getiniciof();
  if(finalf == reg) return true;
  if(finalf < reg){
    clrscr();
    titulo_programa();
    cout<<"FECHA DE SALIDA INVALIDA!!!"<<endl;
    pause();
    return false;
    }
    return true;
}

///FINALIZAR REPARACION
/*
void finalizar_reparacion(){
    clrscr();
    Reparaciones r;
    Repuestos rep;
    Tecnicos tec;
    titulo_programa();
    cout<<"FINALIZAR REPARACION"<<endl<<endl;

    Fecha fi;
    int buscar_repu;
    int id_tec;
    char pass[10];
    int ord;
    int codrep;
    int cant;
    float pre;
    bool est;
    char desc_fin[150];

    cout<<"Ingrese numero de orden: ";
    cin>>ord;
    int pos = buscar_nro_orden(ord);

    if (pos == -1){
        clrscr();
        titulo_programa();
        cout<<"NO SE ENCONTRO NUMERO DE ORDEN!!!"<<endl;
        pause();
        return;
    }

    if (pos >= 0){
        r.leer_reparacion(pos);

        if (r.Getestado()==true){
            clrscr();
            titulo_programa();
            cout<<"ESTA REPARACION FUE FINALIZADA!!!"<<endl<<endl;
            pause();
            return;
        }

        clrscr();
        titulo_programa();
        cout<<"FINALIZAR REPARACION"<<endl<<endl;
        cout<<"NRO ORDEN ENCONTRADO!!!"<<endl<<endl;

        cout<<"Numero de orden: "<<r.Getnro_orden()<<endl<<endl;
        r.mostrar_reparaciones_nofinalizadas();
        cout<<"-------------------------------------------"<<endl<<endl<<endl;

        cout<<"ID de tecnico: ";
        cin>>id_tec;

        int buscartec = buscar_reg_tec(id_tec);
        tec.Leer_Tecnico(buscartec);

        cout<<endl<<endl;
        cout<<"Esta Reparacion estuvo acargo el Tecnico: "<<tec.getnombre()<<", "<<tec.getapellido()<<endl;
        cout<<"Ingrese Contrase\245a: ";
        ocultar_Password(pass);
        cout<<endl<<endl;

        if (strcmp(pass,tec.getcontrasena())!=0){
            clrscr();
            titulo_programa();
            cout<<"CONTRASE\245A INCORRECTA!!!"<<endl;
            pause();
            return;
        }

        cout<<"Descripcion de la Reparacion: ";
        fflush(stdin);
        cin.getline(desc_fin,150);

        cout<<endl;

        cout<<"Fecha de salida: ";
        if (fi.cargar()==false)return;
        if (verificarFecha(r.Getnro_orden(),fi)==false){
            return;
        }

        cout<<"Codigo de Repuesto (MANO DE OBRA ingrese 0): ";
        cin>>codrep;

        cout<<endl;

        if (codrep == 0){
            cout<<endl;
            cout<<"Precio: $";
            cin>>pre;

            est = true;

            r.Setdesc_final(desc_fin);
            r.Setidtec(id_tec);
            r.Setprecio(pre);
            r.Setestado(est);
            r.Setfinalf(fi);

            r.modificar_reparacion_de_disco(pos);
            r.guardar_reparacion();


            clrscr();
            titulo_programa();
            cout<<"Reparacion finalizada!!!"<<endl;
            pause();
            return;
        }

        buscar_repu = buscar_repuesto_cod(codrep);

        if (buscar_repu == -1){
            clrscr();
            titulo_programa();
            cout<<"Repuesto no encontrado"<<endl;
            pause();
            return;
        }

        if (buscar_repu >= 0){
            rep.leer_repuesto(buscar_repu);
            cout<<"Nombre del repuesto: "<<rep.Getnombre_repuesto()<<endl;
            cout<<"Cantidad del repuesto: "<<rep.Getcantidad()<<endl<<endl;

            cout<<"Cantidad usada de Repuesto: ";
            cin>>cant;

            int resultado = rep.Getcantidad() - cant;

            if (resultado < 0){
                clrscr();
                titulo_programa();
                cout<<"NO HAY CANTIDAD DISPONIBLE!!!"<<endl;
                pause();
                return;
            }

            cout<<endl;

            cout<<"Precio: $";
            cin>>pre;

            est = true;

            rep.Setcantidad(resultado);
            r.Setdesc_final(desc_fin);
            r.Setidtec(id_tec);
            r.Setprecio(pre);
            r.Setestado(est);
            r.Setfinalf(fi);

            rep.modificar_repuesto_de_disco(buscar_repu);
            r.modificar_reparacion_de_disco(pos);
            r.guardar_reparacion();

            cout<<"Reparacion finalizada!!!"<<endl;
            pause();
            return;
        }
    }
}
*/

///BUSCAR REPARACION POR NRO DE ORDEN
void buscar_reparacion(){
    clrscr();
    titulo_programa();

    int nro;
    int buscar;
    Reparaciones rep;
    Cliente cli;

    cout<<"BUSCAR REPARACION POR NUMERO DE ORDEN"<<endl<<endl;
    cout<<"Ingrese Numero de orden: ";
    cin>>nro;

    buscar = buscar_nro_orden(nro);
    if (buscar == -1){
        clrscr();
        titulo_programa();
        cout<<"NUMERO DE ORDEN NO ENCONTRADO"<<endl;
        pause();
        return;
    }
    rep.leer_reparacion(buscar);

    clrscr();
    titulo_programa();
    if (rep.Getestado()==true){
        cout<<"ESTA REPARACION FUE FINALIZADA!!!"<<endl<<endl;
        rep.mostrar_reparaciones_finalizadas();
        pause();
        return;
    }
    if (rep.Getestado()==false){
        cout<<"ESTA REPARACION ESTA SIN FINALIZAR"<<endl<<endl;
        rep.mostrar_reparaciones_nofinalizadas();
        pause();
        return;
    }
}

///VACIAR REPARACION
void vaciar_reparacion(){
   clrscr();
   char opc;
   titulo_programa();
   cout<<"VACIAR ARCHIVO REPARACION"<<endl<<endl;
   cout<<"ATENCION!!!"<<endl<<endl;
   cout<<"Esta a punto de BORRAR todo registro de Reparacion..."<<endl;
   cout<<"Desea proceder? (S/N)";
   cin>>opc;
   switch(opc){
        case 's':
        case 'S':
            clrscr();
            FILE *pfr;
            pfr=fopen(A_REPARACIONES,"wb");
            if (pfr == NULL){return;}
            fclose(pfr);
            clrscr();
            titulo_programa();
            cout<<"VACIAR ARCHIVO REPARACION"<<endl<<endl;
            loading_bar(20,"BORRANDO REPARACION...",70);
            clrscr();
            titulo_programa();
            cout<<"VACIAR ARCHIVO REPARACION"<<endl<<endl;
            cout<<"Registros de REPARACION borrados!!!"<<endl;
            pause();
            break;
        case 'n':
        case 'N':
            return;
            break;
   }
}
//CUENTA ORDENES
int cuenta_ordenes(){
    Reparaciones r;
    int pos = 0;
    int cant = 0;
    while (r.leer_reparacion(pos++)){
            cant++;
    }
    return cant;
}
///SIN FINALIZAR
void sin_finalizar(){
    clrscr();
    titulo_programa();
    Reparaciones r;
    int posr = 0;
    cout<<"REPARACIONES SIN FINALIZAR"<<endl;
    while(r.leer_reparacion(posr++)){
        if(r.Getestado()==false){
            r.mostrar_reparaciones_nofinalizadas();
        }
    }
    pause();
    return;
}
///FINALIZADO
void finalizados(){
    clrscr();
    titulo_programa();
    Reparaciones r;
    int posr = 0;
    cout<<"REPARACIONES FINALIZADAS"<<endl;
    while(r.leer_reparacion(posr++)){
        if(r.Getestado()==true){
            r.mostrar_reparaciones_finalizadas();
        }
    }
    pause();
    return;
}

///LISTAR REPARACIONES
void listar_reparaciones(){
    clrscr();
    titulo_programa();

    char opc1;
    int posr = 0;

    Reparaciones r;

    cout<<"LISTAR REPARACIONES"<<endl<<endl;

    cout<<"1) Listar Reparaciones SIN FINALIZAR"<<endl;
    cout<<"2) Listar Reparaciones FINALIZADAS"<<endl<<endl;
    cout<<"0) Volver"<<endl<<endl;
    cout<<"Elija una Opcion: ";
    cin>>opc1;

    switch(opc1){

    case '1':
        sin_finalizar();
        break;

    case '2':
        finalizados();
        break;

         case '0':
            return;
            break;
    }
}

int cuenta_reparaciones_finalizadas(){
    Reparaciones r;
    int pos = 0;
    int cant = 0;
    while (r.leer_reparacion(pos++)){
        if (r.Getestado()==true)cant++;
    }
    return cant;
}


///**************************************FUNCIONES INTERNAS DE LA CLASE REPUESTOS**************************************

///INICIAR REPARACION
bool Reparaciones::iniciar_reparacion(){
    clrscr();
    titulo_programa();

    Cliente cli;
    int poscli = 0;

    nro_orden = cuenta_ordenes()+1;

    cout<<"INICIAR REPARACION"<<endl<<endl;

    cout<<"Numero de Orden: "<<nro_orden<<endl;

    cout<<"Ingrese DNI del cliente: ";
    cin>>dni;
    if (verificar_dni(dni)==true){
        clrscr();
        titulo_programa();
        cout<<"NO EXISTE DNI"<<endl;
        pause();
        return false;
    }
    cout<<endl;

    while (cli.leerCliente(poscli++)){
        if (dni == cli.getdni()){
            if (cli.getestado()==true){
            cout<<"Cliente: "<<cli.getnombre()<<", "<<cli.getapellido()<<endl<<endl;
            }
            if (cli.getestado()==false){
                clrscr();
                titulo_programa();
                cout<<"CLIENTE DADO DE BAJA"<<endl<<endl;
                pause();
                return false;
            }
        }
    }
    cout<<"Tipo de Equipo: ";
    fflush(stdin);
    cin.getline(tipo,20);

    cout<<"Marca: ";
    fflush(stdin);
    cin.getline(marca,20);

    cout<<"Modelo: ";
    fflush(stdin);
    cin.getline(modelo,20);

    cout<<endl;

    cout<<"Fecha de entrada: ";
    if (iniciof.cargar()==false)return false;

    cout<<endl;

    cout<<"Descripcion problema: ";
    fflush(stdin);
    cin.getline(desc_inicio,150);

    estado = false;

    cout<<endl;

    cout<<"SE INICIO LA REPARACION!!!"<<endl;

    pause();
    return true;
}

///FINALIZAR REPARACIONES

bool Reparaciones::finalizar_reparacion(){
    clrscr();
    titulo_programa();

    Tecnicos tec;
    Repuestos rep;
    Cliente cli;

    ///orden
    int num_orden;
    int buscar_num_orden;

    ///tecnico
    int id;
    char pass[10];
    int buscartec;

    ///repuesto
    int codrep;
    int buscar_codrep;
    int resultado;
    int cantidad;
    ///estado
    bool est;
    //variables
    int pos = 0;

    cout<<"FINALIZAR REPARACION"<<endl<<endl;

    ///BUSCA Y MUESTRA LA ORDEN
    cout<<"Ingrese numero de orden: ";
    cin>>num_orden;
    buscar_num_orden = buscar_nro_orden(num_orden);
    if (buscar_num_orden >= 0){
    leer_reparacion(buscar_num_orden);
    if (Getestado() == true){
        clrscr();
        titulo_programa();
        cout<<"REPARACION YA FINALIZADA!!!"<<endl;
        pause();
        return false;
    }
    mostrar_reparaciones_nofinalizadas();
    }
    if (buscar_num_orden == -1 || buscar_num_orden < 0){
        cout<<"NO SE ENCONTRO NUMERO DE ORDEN"<<endl;
        pause();
        return false;
    }
/*
    ///BUSCA TECNICO, MUESTRA EL NOMBRE Y VALIDA EL PASSWORD
    cout<<"ID de tecnico: ";
    cin>>id;
    buscartec = buscar_reg_tec(id);
    if (buscartec == -1 || buscartec < 0){
        clrscr();
        titulo_programa();
        cout<<"NO SE ENCONTRO EL TECNICO!!!"<<endl;
        pause();
        return false;
    }
    if (buscartec >= 0){
        tec.Leer_Tecnico(buscartec);
        if (tec.getestado()==false){
            cout<<"TECNICO DADO DE BAJA!!!"<<endl;
            pause();
            return false;
        }
        cout<<endl<<endl;
        cout<<"Esta Reparacion estuvo acargo el Tecnico: "<<tec.getnombre()<<", "<<tec.getapellido()<<endl;
        cout<<"Ingrese Contrase\245a: ";
        ocultar_Password(pass);
        cout<<endl<<endl;
            if (strcmp(pass,tec.getcontrasena())!=0){
            clrscr();
            titulo_programa();
            cout<<"CONTRASE\245A INCORRECTA!!!"<<endl;
            pause();
            return false;
        }
    }
*/
    ///BUSCA TECNICO CON EL ESTADO DE LOG EN TRUE
    while(tec.Leer_Tecnico(pos++)){
        if (tec.getlog()==true){
            cout<<"Orden a cargo de: "<<tec.getnombre()<<", "<<tec.getapellido()<<endl<<endl;
            id = tec.getid();
        }
    }

    ///DESCRIPCION DE LA REPARACION
    cout<<"Descripcion de la Reparacion: ";
    fflush(stdin);
    cin.getline(desc_final,150);

    ///FECHA DE SALIDA
    cout<<endl;
    cout<<"Fecha de salida: ";
    if (finalf.cargar()==false)return false;
    if (verificarFecha(Getnro_orden(),finalf)==false){return false;}
    cout<<endl;

    ///BUSCAR REPUESTO Y MUESTRA EL NOMBRE Y LA CANTIDAD
    cout<<"Codigo Repuesto (MANO DE OBRA 0): ";
    cin>>codrep;
    if (codrep == 0){
        cout<<endl;
        cout<<"Precio: $";
        cin>>precio;
        est = true;
        Setestado(est);
        Setcod_rep(codrep);
        modificar_reparacion_de_disco(buscar_num_orden);
        pause();
        return true;
    }
    buscar_codrep = buscar_repuesto_cod(codrep);
    if (buscar_codrep == -1){
        cout<<"REPUESTO NO ENCONTRADO"<<endl;
        pause();
        return false;
    }
    rep.leer_repuesto(buscar_codrep);
    if (rep.Getestado()==false){
        cout<<"NO QUEDA MAS STOCK DE ESTE REPUESTO!!!"<<endl;
        pause();
        return false;
    }
    cout<<"Nombre de repuesto y cantidad del mismo: "<<rep.Getnombre_repuesto()<<", "<<rep.Getcantidad()<<endl<<endl;
    cout<<"Ingrese cantidad para usar: ";
    cin>>cantidad;
    if (cantidad <= 0){
        clrscr();
        titulo_programa();
        cout<<"CANTIDAD INGRESADA INVALIDA!!!"<<endl;
        pause();
        return false;
    }
    resultado = rep.Getcantidad() - cantidad;
        if (resultado < 0){
            clrscr();
            titulo_programa();
            cout<<"NO HAY CANTIDAD DISPONIBLE!!!"<<endl;
            pause();
            return false;
        }
        if (resultado == 0){
            bool estadorepu;

            ///PRECIO
            cout<<"Precio: $";
            cin>>precio;

            est = true;
            estadorepu = false;
            Setestado(est);
            Setidtec(id);
            Setcod_rep(codrep);
            rep.Setcantidad(resultado);
            rep.Setestado(estadorepu);
            rep.modificar_repuesto_de_disco(buscar_codrep);
            modificar_reparacion_de_disco(buscar_num_orden);
            return true;
        }


    ///PRECIO
    cout<<"Precio: $";
    cin>>precio;

    est = true;
    Setestado(est);
    Setidtec(id);
    Setcod_rep(codrep);
    rep.Setcantidad(resultado);
    rep.modificar_repuesto_de_disco(buscar_codrep);
    modificar_reparacion_de_disco(buscar_num_orden);
    return true;

}

///MODIFICAR REPARACION DE  DISCO
void Reparaciones::modificar_reparacion_de_disco(int pos){
    FILE *pfr;
	pfr = fopen(A_REPARACIONES,"rb+");
	if (pfr == NULL){
        clrscr();
        titulo_programa();
        cout<<"ERROR DE ARCHIVO!!!"<<endl;
        pause();
        return;
    }
	fseek(pfr,(pos) * (sizeof *this),0);
	fwrite(this,(sizeof *this),1,pfr);
	fclose(pfr);
}

///GUARDAR REPARACION
void Reparaciones::guardar_reparacion(){
    FILE *pfre;
    pfre=fopen(A_REPARACIONES,"ab");
    if (pfre == NULL){
        clrscr();
        titulo_programa();
        cout<<"ERROR DE ARCHIVO REPUESTOS!!!"<<endl;
        pause();
        return;
    }
    fwrite(this, sizeof *this,1,pfre);
    fclose(pfre);
}


///LEER REPARACION
int Reparaciones::leer_reparacion(int pos){
    bool leyo;
    FILE *pfr;
    pfr = fopen(A_REPARACIONES,"rb");
    if (pfr == NULL){return false;}
    fseek(pfr, (sizeof *this) * (pos), 0);
    leyo = fread(this,sizeof *this,1,pfr);
    return leyo;

}


///MOSTRAR REPARACIONES
void Reparaciones::mostrar_reparaciones_nofinalizadas(){
        Cliente cli;
        int poscli = 0;
        if (estado == false){
        cout<<endl;
        cout<<"Numero de orden         : "<<nro_orden<<endl;
        cout<<"DNI del cliente         : "<<dni<<endl;
        cout<<"Tipo de PC              : "<<tipo<<endl;
        cout<<"Marca                   : "<<marca<<endl;
        cout<<"Modelo                  : "<<modelo<<endl;
        cout<<"Descripcion del problema: "<<desc_inicio<<endl<<endl;
        cout<<"Fecha de entrada"<<endl;
        cout<<iniciof<<endl<<endl;
        while (cli.leerCliente(poscli++)){
            if (dni == cli.getdni()){
                cout<<"CLIENTE: "<<cli.getnombre()<<", "<<cli.getapellido()<<endl;
            }
        }
        cout<<"-------------------------------------------------------"<<endl<<endl;
        }
}

void Reparaciones::mostrar_reparaciones_finalizadas(){
        Cliente cli;
        Tecnicos tec;
        Repuestos rep;
        int postec = 0;
        int poscli = 0;
        int posrep = 0;
        cout<<endl;
        cout<<"Numero de orden             : "<<nro_orden<<endl;
        cout<<"DNI del Cliente             : "<<dni<<endl;
        cout<<"Tipo de PC                  : "<<tipo<<endl;
        cout<<"Marca                       : "<<marca<<endl;
        cout<<"Modelo                      : "<<modelo<<endl;
        cout<<"Descripcion del problema    : "<<desc_inicio<<endl;
        cout<<"Descripcion de la reparacion: "<<desc_final<<endl;
        cout<<"Precio de la Reparacion     : $"<<precio<<endl<<endl;
        cout<<"Fecha de entrada"<<endl;
        cout<<iniciof<<endl;
        cout<<"Fecha de salida"<<endl;
        cout<<finalf<<endl<<endl;

        cout<<"-------------------------------------------------------"<<endl<<endl;
        while (cli.leerCliente(poscli++)){
            if (dni == cli.getdni()){
                cout<<"CLIENTE:         "<<cli.getnombre()<<", "<<cli.getapellido()<<endl<<endl;
            }
        }
        cout<<"-------------------------------------------------------"<<endl<<endl;
        while (tec.Leer_Tecnico(postec++)){
            if (idtec == tec.getid()){
                cout<<"TECNICO A CARGO DE LA REPARACION: "<<tec.getnombre()<<", "<<tec.getapellido()<<endl<<endl;
            }
        }
        cout<<"-------------------------------------------------------"<<endl<<endl;
        while (rep.leer_repuesto(posrep++)){
            if (cod_rep == rep.Getcod_repuesto()){
                cout<<"REPUESTO UTILIZADO: "<<rep.Getnombre_repuesto()<<endl<<endl;
                cout<<"CODIGO DEL REPUESTO: "<<rep.Getcod_repuesto()<<endl<<endl;
                cout<<"-------------------------------------------------------"<<endl<<endl;
            }
        }
}
#endif // REPARACIONES_H
