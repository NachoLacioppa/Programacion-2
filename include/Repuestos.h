#ifndef REPUESTOS_H
#define REPUESTOS_H

const char *A_REPUESTOS= "ARCHIVOS/Repuestos.dat";
const char *BKP_REPUESTOS = "BKP/Repuestos.BK";

/*

REPUESTOS:

-CARGAR REPUESTOS: LISTO
-LISTAR POR CATEGORIA: LISTO
-VACIAR ARCHIVO: LISTO
-DEFINIR CATEGORIAS: LISTO

***AGREGAR REPUESTOS: FALTA


FUNCION PARA SUMAR Y RESTAR REPUESTOS UNA VEZ QUE LA CLASE REPARACIONES ESTE LISTA

*/

class Repuestos
{
    private:
        int cod_repuesto;
        char nombre_repuesto[100];
        int categoria;
        int cantidad;
        int aux;
        bool estado;

    public:
        ///CONSTRUCTOR
        Repuestos() {}

        ///GET
        int Getcod_repuesto() {return cod_repuesto;}
        char *Getnombre_repuesto() {return nombre_repuesto;}
        int Getcategoria() {return categoria;}
        int Getcantidad() {return cantidad;}
        int Getaux() {return aux;}
        bool Getestado() {return estado;}

        ///SET
        void Setcod_repuesto(int val) {cod_repuesto = val;}
        void Setnombre_repuesto(char *val) {strcpy(nombre_repuesto,val);}
        void Setcategoria(int val) {categoria = val;}
        void Setcantidad(int val) {cantidad = val;}
        void Setaux(int val) {aux = val;}
        void Setestado(bool val) {estado = val;}

        ///FUNCIONES PROTOTIPO
        bool cargar_nuevo_repuesto();
        void mostrar_repuesto();
        void guardar_repuesto();
        int leer_repuesto(int );
        void modificar_repuesto_de_disco(int );
        void mostrar_nombre_repuesto();
};

///******************************************FUNCIONES EXTERNAS DE LA CLASE**********************************************

///CONTAR REGISTROS DE REPUESTOS
long contar_reg_repuestos(){
    Repuestos re;
    int pos = 0;
    int cant = 0;
    while (re.leer_repuesto(pos)){
            cant++;
            pos++;
    }
    return cant;
}

///BUSCAR REPUESTOS POR CATEGORIA
int buscar_repuesto_cat(int cat){
    Repuestos re;
    int pos = 0;
    while(re.leer_repuesto(pos++)){
        if(cat == re.Getcategoria())return pos;
    }
    return -1;
}

///BUSCAR REPUESTO POR CODIGO
int buscar_repuesto_cod(int cod){
    Repuestos re;
    int pos = 0;
    while (re.leer_repuesto(pos)){
        if (cod == re.Getcod_repuesto())return pos;
        pos++;
    }
    return -1;
}

///AGREGAR REPUESTO

void agregar_repuesto(){
    Repuestos re;
    clrscr();
    titulo_programa();
    cout<<"AGREGAR REPUESTO"<<endl<<endl;
    int cant, cod;
    bool est;
    int cant_fin;

    cout<<"Ingrese codigo de repuesto: ";
    cin>>cod;

    int pos = buscar_repuesto_cod(cod);

    if (pos == -1){
        clrscr();
        titulo_programa();
        cout<<"CODIGO DE REPUESTO NO ENCONTRADO!!!"<<endl;
        pause();
        return;
    }

    re.leer_repuesto(pos);
    clrscr();
    titulo_programa();
    cout<<"CODIGO DE REPUESTO ENCONTRADO!!!"<<endl<<endl;
    cout<<"Nombre de Repuesto: "<<re.Getnombre_repuesto()<<endl;
    cout<<"Ingrese cantidad para agregar: ";
    cin>>cant;

    cant_fin = re.Getcantidad()+cant;

    if (cant_fin > 0)est=true;
    if (cant_fin == 0)est=false;
    if (cant_fin < 0){
        clrscr();
        cout<<"CANTIDAD FINAL INVALIDA!!!"<<endl;
        pause();
        return;
    }

    re.Setcantidad(cant_fin);
    re.Setestado(est);
    re.modificar_repuesto_de_disco(pos);
    cout<<endl;
    cout<<"REPUESTOS AGREGADOS!!!"<<endl<<endl;
    pause();
    return;


}


///MOSTRAR REPUESTOS POR CATEGORIA
void listar_repuesto_por_codigo(){
    clrscr();

    Repuestos re;
    int cod_rep;
    int buscar;

    titulo_programa();
    cout<<"BUSCAR REPUESTO POR CODIGO"<<endl<<endl;
    cout<<"Ingrese codigo: ";
    cin>>cod_rep;

    buscar = buscar_repuesto_cod(cod_rep);

    if (buscar == -1){
        cout<<"NO EXISTE"<<endl;
        pause();
        return;
    }

    clrscr();
    titulo_programa();
    cout<<"REPUESTO ENCONTRADO!!!"<<endl<<endl;
    re.leer_repuesto(buscar);
    re.mostrar_repuesto();
    pause();
    return;
}

///VACIAR ARCHIVO REPUESTO
void vaciar_repuesto(){
   clrscr();
   char opc;
   titulo_programa();
   cout<<"VACIAR ARCHIVO REPUESTOS"<<endl<<endl;
   cout<<"ATENCION!!!"<<endl<<endl;
   cout<<"Esta a punto de BORRAR todo registro de Repuesto..."<<endl;
   cout<<"Desea proceder? (S/N)";
   cin>>opc;
   switch(opc){
        case 's':
        case 'S':
            clrscr();
            FILE *pfr;
            pfr=fopen(A_REPUESTOS,"wb");
            if (pfr == NULL){return;}
            fclose(pfr);
            clrscr();
            titulo_programa();
            cout<<"VACIAR ARCHIVO REPUESTOS"<<endl<<endl;
            loading_bar(20,"BORRANDO REPUESTOS...",70);
            clrscr();
            titulo_programa();
            cout<<"VACIAR ARCHIVO REPUESTOS"<<endl<<endl;
            cout<<"Registros de REPUESTOS borrados!!!"<<endl;
            pause();
            break;
        case 'n':
        case 'N':
            return;
            break;
   }
}
///VERIFICAR COD REPUESTO
bool verificar_cod_rep(int ID){
    Repuestos re;
    int pos = 0;
    while(re.leer_repuesto(pos)){
        if (ID == re.Getcod_repuesto())return false;
        pos++;
    }
    return true;
}


///LISTAR TODOS LOS REPUESTOS
void listar_todo_repuestos(){
    clrscr();

    Repuestos re;
    int pos=0;

    titulo_programa();
    cout<<"LISTAR TODOS LOS REPUESTOS EN STOCK"<<endl<<endl;
    while(re.leer_repuesto(pos++)){
        if (re.Getestado()==true){
            re.mostrar_repuesto();
        }
    }
    pause();
    return;
}

///LISTAR REPUESTOS QUE ESTAN EN FALTA
void listar_repuestos_falta(){
    clrscr();

    Repuestos re;
    int pos=0;

    titulo_programa();
    cout<<"LISTAR TODOS LOS REPUESTOS QUE ESTAN EN FALTA"<<endl<<endl;
    while(re.leer_repuesto(pos++)){
        if (re.Getestado()==false){
        re.mostrar_repuesto();
        }
    }
    pause();
    return;
}


///**************************************FUNCIONES INTERNAS DE LA CLASE REPUESTOS**************************************

///CARGAR NUEVO REPUESTO
bool Repuestos::cargar_nuevo_repuesto(){
    clrscr();
    recuadro(35,0,20,9);
    gotoxy(36,1);
    cout<<"CATEGORIAS";
    gotoxy(36,2);
    cout<<"1 - Motherboard";
    gotoxy(36,3);
    cout<<"2 - Microprocesador";
    gotoxy(36,4);
    cout<<"3 - Memoria RAM";
    gotoxy(36,5);
    cout<<"4 - Discos";
    gotoxy(36,6);
    cout<<"5 - Placa de video";
    gotoxy(36,7);
    cout<<"6 - Fuentes";
    gotoxy(36,8);
    cout<<"7 - Varios";

    titulo_programa();
    cout<<"CARGAR NUEVO REPUESTO"<<endl<<endl;

    cout<<"Codigo de repuesto: ";
    cin>>cod_repuesto;
    if (verificar_cod_rep(cod_repuesto)==false){
        clrscr();
        titulo_programa();
        cout<<"CODIGO YA EXISTENTE!!!"<<endl;
        pause();
        return false;
    }
    if (cod_repuesto == 0){
        clrscr();
        titulo_programa();
        cout<<"CODIGO DE MANO DE OBRA"<<endl;
        pause();
        return false;
    }

    cout<<"Nombre: ";
    fflush(stdin);
    cin.getline(nombre_repuesto,100);

    cout<<"Cantidad: ";
    cin>>cantidad;
    if (cantidad > 0)estado=true;
    if (cantidad == 0)estado=false;
    if (cantidad < 0){
        clrscr();
        titulo_programa();
        cout<<"CANTIDAD INVALIDA!!!"<<endl;
        return false;
    }

    cout<<"Categoria: ";
    cin>>categoria;
    if (categoria < 1 || categoria > 7){
        clrscr();
        titulo_programa();
        cout<<"CATEGORIA INVALIDA!!!"<<endl;
        pause();
        return false;
    }
    if (categoria == 1){
        cout<<"MOTHERBOARD"<<endl;
    }
     if (categoria == 2){
        cout<<"MICROPROCESADOR"<<endl;
    }
     if (categoria == 3){
        cout<<"MEMORIA RAM"<<endl;

    }
     if (categoria == 4){
        cout<<"DISCOS"<<endl;
    }
     if (categoria == 5){
        cout<<"PLACA DE VIDEO"<<endl;
    }
    if (categoria == 6){
        cout<<"FUENTE"<<endl;
    }
    if (categoria == 7){
        cout<<"VARIOS"<<endl;
    }
    pause();

    cout<<"REPUESTO CARGADO !!!"<<endl<<endl;
    pause();
    return true;
}

///GUARDAR REPUESTO
void Repuestos::guardar_repuesto(){
    FILE *pfr;
    pfr=fopen(A_REPUESTOS,"ab");
    if (pfr == NULL){
        clrscr();
        titulo_programa();
        cout<<"ERROR DE ARCHIVO REPUESTOS!!!"<<endl;
        pause();
        return;
    }
    fwrite(this, sizeof *this,1,pfr);
    fclose(pfr);
}

///LEER REPUESTO
int Repuestos::leer_repuesto(int pos){
    bool leyo;
    FILE *pfr;
    pfr = fopen(A_REPUESTOS,"rb");
    if (pfr == NULL){return false;}
    fseek(pfr, (sizeof *this) * (pos), 0);
    leyo = fread(this,sizeof *this,1,pfr);
    return leyo;
}

///MODIFICAR CLIENTE DE  DISCO
void Repuestos::modificar_repuesto_de_disco(int pos){
    FILE *pfr;
	pfr = fopen(A_REPUESTOS,"rb+");
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

///MOSTRAR REPUESTO
void Repuestos::mostrar_repuesto(){
    cout<<"Codigo          :"<<cod_repuesto<<endl;
    cout<<"Nombre          :"<<nombre_repuesto<<endl;
    cout<<"Categoria       :"<<categoria<<" ";
    if (categoria == 1){
        cout<<"MOTHERBOARD"<<endl;
    }
     if (categoria == 2){
        cout<<"MICROPROCESADOR"<<endl;
    }
     if (categoria == 3){
        cout<<"MEMORIA RAM"<<endl;

    }
     if (categoria == 4){
        cout<<"DISCOS"<<endl;
    }
     if (categoria == 5){
        cout<<"PLACA DE VIDEO"<<endl;
    }
    if (categoria == 6){
        cout<<"FUENTE"<<endl;
    }
     if (categoria == 7){
        cout<<"VARIOS"<<endl;
    }
    cout<<"Cantidad        :"<<cantidad<<endl;
    cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

#endif // REPUESTOS_H
