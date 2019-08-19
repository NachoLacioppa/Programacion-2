#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

const char *A_CLIENTES = "ARCHIVOS/Clientes.dat";
const char *BKP_CLIENTES = "BKP/Clientes.BK";


/*
CLIENTES:

-CARGA DE CLIENTE: LISTO
-MOSTRAR CLIENTES: LISTO
-MODIFICAR CLIENTES: LISTO
-DAR DE BAJA: LISTO
-DAR DE ALTA: LISTO
-BORRAR ARCHIVO: LISTO

***-BACKUP: FALTA
***-RESTAURAR: FALTA

FALTA VALIDACION DE DNI PARA QUE NO SE REPITA DNI

*/



///CLIENTES///

class Cliente{

private:

    char nombre[40];
    char apellido[40];
    long dni;
    long telefono;
    char direccion[50];
    char localidad[50];
    bool estado;

public:
    ///CONSTRUCTOR
    Cliente() {}

    ///GET
    char *getnombre(){return nombre;}
    char *getapellido(){return apellido;}
    long getdni(){return dni;}
    long gettelefono(){return telefono;}
    char *getdireccion(){return direccion;}
    char *getlocalidad(){return localidad;}
    bool getestado(){return estado;}

    ///SET
    void setnombre(char *n){strcpy(nombre,n);}
    void setapellido(char *a){strcpy(apellido,a);}
    void setdni(long d){dni=d;}
    void settelefono(long t){telefono=t;}
    void setdireccion(char *dir){strcpy(direccion,dir);}
    void setlocalidad(char *loc){strcpy(localidad,loc);}
    void setestado(bool e){estado=e;}

    ///FUNCIONES PROTOTIPO
    bool cargar_nuevo_cliente();
    int leerCliente(int );
    void guardar_cliente();
    void mostrar_cliente();
    void modificar_cliente_de_disco(int );
};

///******************************************FUNCIONES EXTERNAS DE LA CLASE**********************************************

///VERIFICAR DNI
bool verificar_dni(long ID){
    Cliente cl;
    int pos = 0;
    while(cl.leerCliente(pos)){
        if (ID == cl.getdni())return false;
        pos++;
    }
    return true;
}

///CONTAR REGISTROS DE CLIENTES
long contar_reg_clientes(){
    Cliente cl;
    int pos = 0;
    int cant = 0;
    while (cl.leerCliente(pos)){
        if (cl.getestado()==true)cant++;
            pos++;
    }
    return cant;
}

///BUSCAR CLIENTE
int buscar_cliente(long DNI){
    Cliente cl;
    int pos = 0;
    while(cl.leerCliente(pos)){
        if(DNI == cl.getdni()){
            return pos;
        }
    pos++;
    }
    return -1;
}

///BUSCAR CLIENTE POR DNI
void buscar_cliente_dni(){
    clrscr();
    titulo_programa();

    Cliente cl;
    long dni;
    int buscar;

    cout<<"BUSQUEDA DE CLIENTE POR DNI"<<endl<<endl;
    cout<<"Ingrese DNI: ";
    cin>>dni;

    buscar=buscar_cliente(dni);

    if (buscar < 0){
        clrscr();
        titulo_programa();
        cout<<"CLIENTE NO ENCONTRADO!!!"<<endl;
        pause();
        return;
    }

    if (buscar >= 0){
        cl.leerCliente(buscar);
        if (cl.getestado()==false){
            clrscr();
            titulo_programa();
            cout<<"CLIENTE DADO DE BAJA"<<endl;
            pause();
            return;
        }
        clrscr();
        titulo_programa();
        cout<<"Cliente encontrado!!!"<<endl<<endl;
        cl.mostrar_cliente();
    }
    pause();
    return;
}

///MOSTRAR TODOS CLIENTE
void listar_clientes(){
    clrscr();
    Cliente cl;
    int pos = 0;
    titulo_programa();
    //loading_bar(20,"Cargando clientes...",120);
    clrscr();
    titulo_programa();
    cout<<"LISTAR TODOS LOS CLIENTES"<<endl<<endl;
    while (cl.leerCliente(pos++)){
        if (cl.getestado() == true) cl.mostrar_cliente();
    }
    if (pos <= 1){
        clrscr();
        titulo_programa();
        cout<<"NO HAY CLIENTES CARGADOS!!!"<<endl;
        pause();
        return;
    }
    pause();
    return;
}

///MODIFICAR CLIENTE
void modificar_cliente(){
    clrscr();
    Cliente cl;
    long DNI;
    char opc1;
    char nom[100];
    char ape[100];
    long documento;
    long tel;
    char dir[50];
    char loc[50];
    int pos;
    titulo_programa();
    cout<<"MODIFICAR CLIENTE"<<endl<<endl;
    cout<<"Ingrese DNI de un cliente: ";
    cin>>DNI;
    pos = buscar_cliente(DNI);
    if (pos == -1){
        clrscr();
        titulo_programa();
        cout<<"NO EXISTE DNI!!!"<<endl;
        pause();
        return;
    }

    cl.leerCliente(pos);

     if (cl.getestado()==false){
        clrscr();
        titulo_programa();
        cout<<"CLIENTE DADO DE BAJA!!!"<<endl;
        pause();
        return;
    }

    clrscr();
    titulo_programa();
    //loading_bar(20,"Buscando Cliente...",200);
    clrscr();
    titulo_programa();
    cout<<"MODIFICAR CLIENTE"<<endl<<endl;
    cout<<"DNI de cliente encontrado, se modificara los datos del siguiente cliente: "<<endl<<endl;
    cl.mostrar_cliente();
    cout<<"Desea proceder a cambiar los datos del cliente encontrado? (S/N)";
    cin>>opc1;
    if (opc1 == 'N' || opc1 == 'n'){
        return;
    }
    if (opc1 == 'S' || opc1 == 's'){
        clrscr();
        titulo_programa();
        cout<<"MODIFICAR CLIENTE"<<endl<<endl;

        cout<<"Nombre: ";
        fflush(stdin);
        cin.getline(nom,100);

        cout<<"Apellido: ";
        fflush(stdin);
        cin.getline(ape,100);

        cout<<"DNI: ";
        cin>>documento;

        cout<<"Telefono: ";
        cin>>tel;

        cout<<"Direccion: ";
        fflush(stdin);
        cin.getline(dir,50);

        cout<<"Localidad: ";
        fflush(stdin);
        cin.getline(loc,50);

        cl.setnombre(nom);
        cl.setapellido(ape);
        cl.setdni(documento);
        cl.settelefono(tel);
        cl.setdireccion(dir);
        cl.setlocalidad(loc);

        cl.modificar_cliente_de_disco(pos);

        cout<<endl;
        cout<<"DATOS DE CLIENTE MODIFICADOS Y GUARDADOS!!!"<<endl<<endl;
        pause();
        return;
    }
}

///DAR DE BAJA CLIENTE
void baja_cliente(){
    clrscr();

    titulo_programa();
    cout<<"BAJA CLIENTE"<<endl<<endl;

    long DNI;
    int pos;
    bool est;
    char opc;
    Cliente cl;

    cout<<"Ingrese DNI: ";
    cin>>DNI;
    pos = buscar_cliente(DNI);

    if (pos == -1){
        clrscr();
        titulo_programa();
        cout<<"BAJA CLIENTE"<<endl<<endl;
        loading_bar(20,"Buscando cliente...",45);
        clrscr();
        textcolor(15,0);
        titulo_programa();
        cout<<"BAJA CLIENTE"<<endl<<endl;
        cout<<"NO EXISTE ESE DNI!!!"<<endl<<endl;
        pause();
        return;
    }

    if (cl.getestado() == true){
    cl.leerCliente(pos);
    clrscr();
    titulo_programa();
    loading_bar(20,"Buscando Cliente...",50);
    clrscr();
    titulo_programa();
    cout<<"BAJA CLIENTE"<<endl<<endl;
        cl.mostrar_cliente();
        cout<<endl<<endl;
        cout<<"ATENCION!!!"<<endl<<endl;
        cout<<"Esta a punto de dar de baja el cliente"<<endl;
        cout<<"Desea proceder? (S/N)";
        cin>>opc;
        switch(opc){
            case 's':
            case 'S':
                est=false;
                cl.setestado(est);
                cl.modificar_cliente_de_disco(pos);
                clrscr();
                titulo_programa();
                loading_bar(20,"Espere por favor...",50);
                clrscr();
                titulo_programa();
                cout<<"BAJA CLIENTE"<<endl<<endl;
                cout<<"Cliente dado de BAJA con EXITO!!!"<<endl;
                pause();
                return;
                break;
            case 'n':
            case 'N':
                return;
                break;
            }
    }

    if (cl.getestado() == false){
        clrscr();
        titulo_programa();
        cout<<"BAJA CLIENTE"<<endl<<endl;
        cout<<"Este cliente ya fue dado de baja!!!"<<endl;
        pause();
        return;
    }
}

///DAR DE ALTA CLIENTE
void alta_cliente(){
    clrscr();

    titulo_programa();
    cout<<"ALTA CLIENTE"<<endl<<endl;

    long DNI;
    int pos;
    bool est;
    char opc;
    Cliente cl;

    cout<<"Ingrese DNI: ";
    cin>>DNI;
    pos = buscar_cliente(DNI);
    if (pos == -1){
        clrscr();
        titulo_programa();
        cout<<"ALTA CLIENTE"<<endl<<endl;
        loading_bar(20,"Buscando cliente...",45);
        clrscr();
        textcolor(15,0);
        titulo_programa();
        cout<<"ALTA CLIENTE"<<endl<<endl;
        cout<<"NO EXISTE ESE DNI!!!"<<endl<<endl;
        pause();
        return;
    }
    cl.leerCliente(pos);
    clrscr();
    titulo_programa();
    loading_bar(20,"Buscando Cliente...",50);
    clrscr();
    titulo_programa();
    cout<<"ALTA CLIENTE"<<endl<<endl;

    if (cl.getestado()==false){
    cl.mostrar_cliente();
    cout<<endl<<endl;
    cout<<"ATENCION!!!"<<endl<<endl;
    cout<<"Esta a punto de dar de ALTA el cliente"<<endl;
    cout<<"Desea proceder? (S/N)";
    cin>>opc;
    switch(opc){
        case 's':
        case 'S':
            est=true;
            cl.setestado(est);
            cl.modificar_cliente_de_disco(pos);
            clrscr();
            titulo_programa();
            loading_bar(20,"Espere por favor...",50);
            clrscr();
            titulo_programa();
            cout<<"ALTA CLIENTE"<<endl<<endl;
            cout<<"Cliente dado de ALTA con EXITO!!!"<<endl;
            pause();
            return;
            break;
        case 'n':
        case 'N':
            return;
            break;
        }
    }
    if (cl.getestado() == true){
        clrscr();
        titulo_programa();
        cout<<"ALTA CLIENTE"<<endl<<endl;
        cout<<"Este cliente no se puede dar de ALTA!!!"<<endl;
        pause();
        return;
    }

}

///VACIAR ARCHIVO CLIENTE
void vaciar_cliente(){
   clrscr();
   char opc;
   titulo_programa();
   cout<<"VACIAR ARCHIVO CLIENTE"<<endl<<endl;
   cout<<"ATENCION!!!"<<endl<<endl;
   cout<<"Esta a punto de BORRAR todo registro de Clientes..."<<endl;
   cout<<"Desea proceder? (S/N)";
   cin>>opc;
   switch(opc){
        case 's':
        case 'S':
            clrscr();
            FILE *pfc;
            pfc=fopen(A_CLIENTES,"wb");
            if (pfc == NULL){return;}
            fclose(pfc);
            clrscr();
            titulo_programa();
            cout<<"VACIAR ARCHIVO CLIENTE"<<endl<<endl;
            loading_bar(20,"BORRANDO CLIENTES...",70);
            clrscr();
            titulo_programa();
            cout<<"VACIAR ARCHIVO CLIENTE"<<endl<<endl;
            cout<<"Registros de CLIENTE borrados!!!"<<endl;
            pause();
            break;
        case 'n':
        case 'N':
            return;
            break;
   }
}

///*************************************FUNCIONES INTERNAS DE LA CLASE***********************************************

///CARGAR NUEVO CLIENTE
bool Cliente::cargar_nuevo_cliente(){
    clrscr();
    titulo_programa();
    cout<<"CARGAR NUEVO CLIENTE"<<endl<<endl;

    cout<<"Nombre: ";
    fflush(stdin);
    cin.getline(nombre,40);

    cout<<"Apellido: ";
    fflush(stdin);
    cin.getline(apellido,40);

    cout<<"DNI: ";
    cin>>dni;
    if (verificar_dni(dni)==false){
        clrscr();
        titulo_programa();
        cout<<"DNI YA CARGADO"<<endl;
        pause();
        return false;
    }

    cout<<"Telefono: ";
    cin>>telefono;

    cout<<"Direccion: ";
    fflush(stdin);
    cin.getline(direccion,50);

    cout<<"Localidad: ";
    fflush(stdin);
    cin.getline(localidad,50);

    estado = true;

    cout<<endl;
    cout<<"DATOS DE CLIENTE GUARDADOS!!!"<<endl<<endl;
    pause();
    return true;
}
///LEER CLIENTE
int Cliente::leerCliente(int pos){
    bool leyo;
    FILE *pfc;
    pfc = fopen(A_CLIENTES,"rb");
    if (pfc == NULL){return false;}
    fseek(pfc, (sizeof *this) * (pos), 0);
    leyo = fread(this,sizeof *this,1,pfc);
    return leyo;
}
///GUARDAR CLIENTE
void Cliente::guardar_cliente(){
    FILE *pfc;
    pfc = fopen(A_CLIENTES,"ab");
    if (pfc == NULL){
        clrscr();
        cout<<"ERROR DE ARCHIVO!!!"<<endl;
        pause();
        return;
    }
    fwrite(this,(sizeof *this),1,pfc);
    fclose(pfc);
}
///MODIFICAR CLIENTE DE  DISCO
void Cliente::modificar_cliente_de_disco(int pos){
    FILE *pfc;
	pfc = fopen(A_CLIENTES,"rb+");
	if (pfc == NULL){
        clrscr();
        titulo_programa();
        cout<<"ERROR DE ARCHIVO!!!"<<endl;
        pause();
        return;
    }
	fseek(pfc,(pos) * (sizeof *this),0);
	fwrite(this,(sizeof *this),1,pfc);
	fclose(pfc);
}


///MOSTRAR CLIENTE
void Cliente::mostrar_cliente(){
        cout<<"Nombre y Apellido: "<<nombre<<", "<<apellido<<endl;
        cout<<"DNI:               "<<dni<<endl;
        cout<<"Telefono:          "<<telefono<<endl;
        cout<<"Direccion:         "<<direccion<<endl;
        cout<<"Localidad:         "<<localidad<<endl;
        cout<<"---------------------------------------------------------------------"<<endl<<endl;
}


#endif // CLIENTES_H_INCLUDED
