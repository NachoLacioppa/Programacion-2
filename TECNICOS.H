#ifndef TECNICOS_H_INCLUDED
#define TECNICOS_H_INCLUDED

const char *A_TECNICOS = "ARCHIVOS/Tecnico.dat";
const char *BKP_TECNICOS = "BKP/Tecnicos.BK";

void ocultar_Password(char *);

///TECNICO///
class Tecnicos{

    private:

        int ID;
        int sueldo;
        char mail[50];
        char Nombre[15];
        char Apellido[15];
        char Contrasena[10];
        bool Estado;
        bool log;

    public:
        ///GET
        int getid(){return ID;}
        int getsueldo(){return sueldo;}
        char *getmail(){return mail;}
        char *getnombre(){return Nombre;}
        char *getapellido(){return Apellido;}
        char *getcontrasena(){return Contrasena;}
        bool getestado(){return Estado;}
        bool getlog(){return log;}

        ///SET
        void setid(int val){ID = val;}
        void setsueldo(int val){sueldo = val;}
        void setmail(char *val){strcpy(mail,val);}
        void setnombre(char *val){strcpy(Nombre,val);}
        void setapellido(char *val){strcpy(Apellido,val);}
        void setcontrasena(char *val){strcpy(Contrasena,val);}
        void setestado(bool val){Estado = val;}
        void setlog(bool val){log = val;}

        ///FUNCIONES PROTOTIPO
        bool Cargar_Tecnico();
        void Guardar_Tecnico();
        void Mostrar_Tecnico();
        void modificar_de_disco(int );
        int Leer_Tecnico(int );
};


///******************************************FUNCIONES EXTERNAS DE LA CLASE**********************************************

///FUNCION DE BUSCAR REG DE TECNICO
int buscar_reg_tec(int id){
    Tecnicos tec;
    int pos = 0;
    while(tec.Leer_Tecnico(pos)){
        if(id == tec.getid()){
            return pos;
        }
    pos++;
    }
    return -1;
}

///MODIFICAR TECNICO
void modificar_tecnico(){
    clrscr();

    Tecnicos tec;
    int id;
    int pos;
    char opc1;
    char nombre[15];
    char apellido[15];
    char mail[50];
    int sueldo;
    bool estado;
    bool log;

    titulo_programa();

    cout<<"MODIFICAR DATOS DE TECNICO"<<endl<<endl;
    cout<<"Ingrese ID de un Tecnico: ";
    cin>>id;
    pos = buscar_reg_tec(id);
    if (pos == -1){
        clrscr();
        titulo_programa();
        cout<<"NO EXISTE TECNICO!!!"<<endl;
        pause();
        return;
    }

    tec.Leer_Tecnico(pos);

    if (tec.getestado()==false){
        clrscr();
        titulo_programa();
        cout<<"TECNICO DADO DE BAJA!!!"<<endl;
        pause();
        return;
    }


    clrscr();
    titulo_programa();
    //loading_bar(20,"Buscando Cliente...",200);
    clrscr();
    titulo_programa();
    cout<<"MODIFICAR DATOS DE TECNICO"<<endl<<endl;
    cout<<"ID de Tecnico encontrado, se modificara los datos del siguiente tecnico: "<<endl<<endl;
    tec.Mostrar_Tecnico();
    cout<<"Desea proceder a cambiar los datos del Tecnico encontrado? (S/N)";
    cin>>opc1;
    if (opc1 == 'N' || opc1 == 'n'){
        return;
    }
    if (opc1 == 'S' || opc1 == 's'){
        clrscr();
        titulo_programa();
        cout<<"MODIFICAR DATOS TECNICO"<<endl<<endl;

        cout<<"Nombre: ";
        fflush(stdin);
        cin.getline(nombre,15);

        cout<<"Apellido: ";
        fflush(stdin);
        cin.getline(apellido,15);

        cout<<"Mail: ";
        cin>>mail;

        cout<<"Sueldo: $";
        cin>>sueldo;

        estado = true;
        log = false;

        tec.setnombre(nombre);
        tec.setapellido(apellido);
        tec.setmail(mail);
        tec.setsueldo(sueldo);
        tec.setestado(estado);
        tec.setlog(log);

        tec.modificar_de_disco(pos);

        cout<<"DATOS DE TECNICO MODIFICADOS Y GUARDADOS!!!"<<endl<<endl;
        pause();
        return;
    }
}

///BUSCAR LOS TECNICOS
void buscar_tecnico_x_id(){
    clrscr();
    titulo_programa();
    cout<<"BUSCAR TECNICO POR ID"<<endl<<endl;

    int idtec;
    int buscar;
    Tecnicos tec;

    cout<<"Ingrese ID de tecnico: ";
    cin>>idtec;

    buscar = buscar_reg_tec(idtec);

    if (buscar == -1){
        clrscr();
        titulo_programa();
        cout<<"TECNICO NO ENCONTRADO!!!"<<endl;
        pause();
        return;
    }
    clrscr();
    titulo_programa();
    cout<<"TECNICO ENCONTRADO!!!"<<endl<<endl;
    tec.Leer_Tecnico(buscar);
    tec.Mostrar_Tecnico();
    pause();
    return;

}


///LISTAR TODOS LOS TECNICOS
void Listar_Tecnicos(){

    Tecnicos tec;
    int pos = 0;
    titulo_programa();
    //loading_bar(20,"Cargando clientes...",120);
    clrscr();
    titulo_programa();
    cout<<"LISTAR TODOS LOS TECNICOS"<<endl<<endl;
    while (tec.Leer_Tecnico(pos++)){
        tec.Mostrar_Tecnico();
    }
    if (pos <= 1){
        clrscr();
        titulo_programa();
        cout<<"NO HAY TECNICOS CARGADOS!!!"<<endl;
        pause();
        return;
    }
    pause();
}


///CONTAR TECNICOS
int Contar_Registros_Tecnicos(){

    Tecnicos tec;
    int pos = 0;
    int cant = 0;

    while (tec.Leer_Tecnico(pos)){
        cant++;
        pos++;
    }
    return cant;
}

///DAR DE BAJA TECNICO
void baja_tecnico(){
    clrscr();

    titulo_programa();
    cout<<"BAJA TECNICO"<<endl<<endl;

    int id;
    int pos;
    bool est;
    char opc;
    Tecnicos tec;

    cout<<"Ingrese ID: ";
    cin>>id;
    pos = buscar_reg_tec(id);
    if (pos == -1){
        clrscr();
        titulo_programa();
        cout<<"BAJA TECNICO"<<endl<<endl;
        loading_bar(20,"Buscando tecnico...",25);
        clrscr();
        textcolor(15,0);
        titulo_programa();
        cout<<"BAJA TECNICO"<<endl<<endl;
        cout<<"NO EXISTE TECNICO!!!"<<endl<<endl;
        pause();
        return;
    }
    tec.Leer_Tecnico(pos);
    clrscr();
    titulo_programa();
    //loading_bar(20,"Buscando tecnico...",25);
    clrscr();
    titulo_programa();
    cout<<"BAJA TECNICO"<<endl<<endl;

    if (tec.getestado()==true){
    tec.Mostrar_Tecnico();
    cout<<endl<<endl;
    cout<<"ATENCION!!!"<<endl<<endl;
    cout<<"Esta a punto de dar de BAJA el tecnico"<<endl;
    cout<<"Desea proceder? (S/N)";
    cin>>opc;
    switch(opc){
        case 's':
        case 'S':
            est=false;
            tec.setestado(est);
            tec.modificar_de_disco(pos);
            clrscr();
            titulo_programa();
            loading_bar(20,"Espere por favor...",50);
            clrscr();
            titulo_programa();
            cout<<"BAJA TECNICO"<<endl<<endl;
            cout<<"Tecnico dado de BAJA con EXITO!!!"<<endl;
            pause();
            return;
            break;
        case 'n':
        case 'N':
            return;
            break;
        }
    }
    if (tec.getestado() == true){
        clrscr();
        titulo_programa();
        cout<<"BAJA TECNICO"<<endl<<endl;
        cout<<"Este tecnico no se puede dar de BAJA!!!"<<endl;
        pause();
        return;
    }
}

///DAR DE ALTA TECNICO
void alta_tecnico(){
    clrscr();

    titulo_programa();
    cout<<"ALTA TECNICO"<<endl<<endl;

    int id;
    int pos;
    bool est;
    char opc;
    Tecnicos tec;

    cout<<"Ingrese ID: ";
    cin>>id;
    pos = buscar_reg_tec(id);
    if (pos == -1){
        clrscr();
        titulo_programa();
        cout<<"ALTA TECNICO"<<endl<<endl;
        //loading_bar(20,"Buscando tecnico...",25);
        clrscr();
        textcolor(15,0);
        titulo_programa();
        cout<<"ALTA TECNICO"<<endl<<endl;
        cout<<"NO EXISTE TECNICO!!!"<<endl<<endl;
        pause();
        return;
    }
    tec.Leer_Tecnico(pos);
    clrscr();
    titulo_programa();
    loading_bar(20,"Buscando tecnico...",25);
    clrscr();
    titulo_programa();
    cout<<"ALTA TECNICO"<<endl<<endl;

    if (tec.getestado()==false){
    tec.Mostrar_Tecnico();
    cout<<endl<<endl;
    cout<<"ATENCION!!!"<<endl<<endl;
    cout<<"Esta a punto de dar de ALTA el tecnico"<<endl;
    cout<<"Desea proceder? (S/N)";
    cin>>opc;
    switch(opc){
        case 's':
        case 'S':
            est=true;
            tec.setestado(est);
            tec.modificar_de_disco(pos);
            clrscr();
            titulo_programa();
            loading_bar(20,"Espere por favor...",50);
            clrscr();
            titulo_programa();
            cout<<"ALTA TECNICO"<<endl<<endl;
            cout<<"Tecnico dado de ALTA con EXITO!!!"<<endl;
            pause();
            return;
            break;
        case 'n':
        case 'N':
            return;
            break;
        }
    }
    if (tec.getestado() == true){
        clrscr();
        titulo_programa();
        cout<<"ALTA TECNICO"<<endl<<endl;
        cout<<"Este tecnico no se puede dar de ALTA!!!"<<endl;
        pause();
        return;
    }
}

///VACIAR ARCHIVO TECNICO
void vaciar_tecnico(){
   clrscr();
   char opc;
   titulo_programa();
   cout<<"VACIAR ARCHIVO TECNICO"<<endl<<endl;
   cout<<"ATENCION!!!"<<endl<<endl;
   cout<<"Esta a punto de BORRAR todo registro de Tecnico..."<<endl;
   cout<<"Desea proceder? (S/N)";
   cin>>opc;
   switch(opc){
        case 's':
        case 'S':
            clrscr();
            FILE *pfc;
            pfc=fopen(A_TECNICOS,"wb");
            if (pfc == NULL){return;}
            fclose(pfc);
            clrscr();
            titulo_programa();
            cout<<"VACIAR ARCHIVO TECNICO"<<endl<<endl;
            loading_bar(20,"BORRANDO TECNICOS...",70);
            clrscr();
            titulo_programa();
            cout<<"VACIAR ARCHIVO TECNICO"<<endl<<endl;
            cout<<"Registros de TECNICOS borrados!!!"<<endl;
            pause();
            break;
        case 'n':
        case 'N':
            return;
            break;
   }
}

///******************************************FUNCIONES INTERNAS DE LA CLASE**********************************************


///CARGAR TECNICO
bool Tecnicos::Cargar_Tecnico(){

    clrscr();
    titulo_programa();
    cout<<"CARGAR NUEVO TECNICO"<<endl<<endl;

    ID = Contar_Registros_Tecnicos()+1;
    char psw[10];

    cout<<"Usuario: "<<ID<<endl;

    cout<<"Contrase\245a: ";
    ocultar_Password(Contrasena);

    cout<<"Reingrese la contrase\245a: ";
    ocultar_Password(psw);

    if (strcmp(Contrasena,psw)!=0){
        clrscr();
        titulo_programa();
        cout<<"Los campos de la contrase\245a no coinsiden!!!";
        pause();
        return false;
    }

    clrscr();
    titulo_programa();
    cout<<"USUARIO REGISTRADO!!!"<<endl;
    cout<<"A continuacion complete sus datos personales"<<endl<<endl;

    cout<<"DATOS DEL TECNICO"<<endl<<endl;

    cout<<"Nombre: ";
    fflush(stdin);
    cin.getline(Nombre,15);

    cout<<"Apellido: ";
    fflush(stdin);
    cin.getline(Apellido,15);

    cout<<"Mail: ";
    fflush(stdin);
    cin.getline(mail,50);

    cout<<"Sueldo: $";
    cin>>sueldo;

    Estado = true;
    log = false;

    //ID = Contar_Registros_Tecnicos()+1;

    clrscr();
    titulo_programa();
    cout<<"TECNICO CARGADO!!!"<<endl;

    pause();
    return true;
}

///LEER TECNICO
int Tecnicos::Leer_Tecnico(int pos){

    bool Leyo;
    FILE *p;

    p = fopen(A_TECNICOS,"rb");
    if (p == NULL){return false;}

    fseek(p, (sizeof *this) * (pos), 0);
    Leyo = fread(this, sizeof *this, 1, p);

    return Leyo;
}

///GUARDAR TECNICO
void Tecnicos::Guardar_Tecnico(){

    FILE *p;
    p = fopen(A_TECNICOS,"ab");

    if (p == NULL){

        clrscr();
        cout<<"ERROR DE ARCHIVO!!!"<<endl;
        pause();
        return;
    }

    fwrite(this, (sizeof *this), 1, p);
    fclose(p);
}

///MOSTRAR TECNICO
void Tecnicos::Mostrar_Tecnico(){
    cout<<"ID (Usuario)      : "<<ID<<endl;
    cout<<"Nombre y Apellido : "<<Nombre<<", "<<Apellido<<endl;
    cout<<"Mail              : "<<mail<<endl;
    cout<<"Sueldo            : $"<<sueldo<<endl;
    cout<<"Estado            : "<<Estado<<endl;
    cout<<"---------------------------------------------------------------------"<<endl<<endl;
}

///MODIFICAR CLIENTE DE  DISCO
void Tecnicos::modificar_de_disco(int pos){
    FILE *pfc;
	pfc = fopen(A_TECNICOS,"rb+");
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


#endif // TECNICOS_H_INCLUDED
