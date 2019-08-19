#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

void menu_principal();
void menu_login();
void menu_adm();
void ocultar_Password(char *);
void recupero_pass();



bool login(){
    clrscr();
    titulo_programa();

    Tecnicos tec;
    int iduser;
    char pass[10];
    int buscar_id;
    bool log;

    cout<<"ID Usuario: ";
    cin>>iduser;

    if (iduser == 0){
        clrscr();
        titulo_programa();
        cout<<"BIENVENIDO ADMINISTRADOR!!!"<<endl;
        cout<<"Contrase\245a: ";
        ocultar_Password(pass);
        if (strcmp(pass,"147369")==0){
            menu_adm();
        }
        if (strcmp(pass,"147369")!=0){
            clrscr();
            titulo_programa();
            cout<<"PASSWORD DE ADMINISTRADOR INCORRECTA"<<endl;
            pause();
            return false;
        }
    }

    if (iduser != 0){

        buscar_id = buscar_reg_tec(iduser);

        if (buscar_id >= 0){
            clrscr();
            titulo_programa();

            tec.Leer_Tecnico(buscar_id);

            if (tec.getestado()==false){
                clrscr();
                titulo_programa();
                cout<<"TECNICO DADO DE BAJA!!!"<<endl;
                pause();
                return false;
            }

            cout<<"BIENVENIDO "<<tec.getnombre()<<"!!!"<<endl;
            cout<<"Contrase\245a: ";
            ocultar_Password(pass);

            if (strcmp(pass,tec.getcontrasena())==0){

                log = true;

                tec.setid(iduser);
                tec.setcontrasena(pass);
                tec.setlog(log);
                tec.modificar_de_disco(buscar_id);
                return true;
            }

            else{
                clrscr();
                titulo_programa();
                cout<<"CONTRASE\245A INCORRECTA!!!";
                pause();
                return false;
            }
        }
        else{
            clrscr();
            titulo_programa();
            cout<<"USUARIO NO ENCONTRADO!!!"<<endl;
            pause();
            return false;
        }
    }
}
///REGISTRO DE TECNICO
void registro(){
    Tecnicos tec;
    if (tec.Cargar_Tecnico() == true){
        tec.Guardar_Tecnico();
        menu_login();
    }
}

///OCULTAR PASSWORD
void ocultar_Password( char *frase){
    int i = 0;
    cout.flush();
    do{
        frase[i] = (unsigned char)getch();
        if(frase[i] != 8){
            cout << '*';
            i++;
        }
        else if(i > 0){
            cout << (char)8 << (char)32 << (char)8;
            i--;
        }
        cout.flush();
    }
    while(frase[i-1] != 13);
    frase[i-1] = 0;
    cout << endl;
}

///RECUPERO DE PASSWORD
void recupero_pass(){
    clrscr();
    titulo_programa();
    cout<<"Recuperacion de Contrase\245a: "<<endl<<endl;

    Tecnicos tec;
    char pass[10];
    int user;

    cout<<"Ingrese ID de Usuario: ";
    cin>>user;

    int pos = buscar_reg_tec(user);

    if(pos == -1){
        clrscr();
        titulo_programa();
        cout<<"USUARIO NO ENCONTRADO!!!"<<endl;
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

    cout<<endl;
    cout<<"Nombre y Apellido del Tecnico: "<<tec.getnombre()<<", "<<tec.getapellido()<<endl<<endl;

    cout<<"Ingrese nueva contrase\245a: ";
    ocultar_Password(pass);

    tec.setcontrasena(pass);
    tec.modificar_de_disco(pos);

    clrscr();
    titulo_programa();

    cout<<"Contrase\245a cambiada!!!"<<endl;
    pause();
    return;

}

void ayuda(){
    clrscr();
    titulo_programa();
    cout<<"AYUDA"<<endl<<endl<<endl;
    cout<<"PASO 1: DEBE REGISTRARSE EN LA OPCION 'Registrar Usuario'"<<endl<<endl;
    cout<<"PASO 2: ANTES DE INICIAR UNA REPARACION, ES NECESARIO CARGAR UN CLIENTE"<<endl<<endl;
    cout<<"PASO 3: SI CUENTA CON REPUESTOS, NO DUDE EN CARGARLOS EN LA OPCION DEL MENU PRINCIPAL 'Repuestos'"<<endl;
    cout<<"        YA QUE ESTE PROGRAMA PERMITE GESTIONAR LOS REPUESTOS QUE PUEDE UTILIZAR CUANDO FINALIZA UNA REPARACION"<<endl<<endl;
    cout<<"PASO 4: YA ESTA LISTO PARA FINALIZAR UNA REPARACION"<<endl<<endl;
    pause();
    return;
}

///MENU LOGIN
void menu_login(){
    while(true){
        clrscr();
        titulo_programa();

        Tecnicos tec;

        char opc;
        char passadm[10];


        cout<<"BIENVENIDO!"<<endl<<endl;
        cout<<"1) Iniciar Sesion"<<endl;
        cout<<"2) Registrar Usuario"<<endl;
        cout<<"3) Listar Tecnicos Registrados"<<endl;
        cout<<"4) Olvide mi contrase\245a"<<endl;
        cout<<"H) AYUDA"<<endl<<endl;
        cout<<"0) SALIR"<<endl<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;

        gotoxy(0,12);
        switch(opc){

        case '1':
            if (login()==true){menu_principal();}
            break;

        case '2':
            registro();
            break;

        case '3':
            clrscr();
            titulo_programa();
            cout<<"Ingrese la contrase\245a de Administrador: ";
            ocultar_Password(passadm);
            if (strcmp(passadm,"147369")==0){Listar_Tecnicos();}
            else{
                clrscr();
                titulo_programa();
                cout<<"PASSWORD DE ADMINISTRADOR INCORRECTA"<<endl;
                pause();
            }
            break;

        case '4':
            recupero_pass();
            break;

        case '0':
            salida();
            break;

        case 'h':
        case 'H':
            ayuda();
            break;

            default:
                clrscr();
                titulo_programa();
                cout<<"OPCION INVALIDA!!!"<<endl;
                pause();
                break;
        }
    }
}


#endif // LOGIN_H_INCLUDED
