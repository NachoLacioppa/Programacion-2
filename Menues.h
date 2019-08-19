#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

///BORRAR TODO (PRUEBA)
void vaciar_todo(){
    FILE *p1;
    FILE *p2;
    FILE *p3;
    FILE *p4;

    p1=fopen(A_CLIENTES,"wb");
    p2=fopen(A_REPARACIONES,"wb");
    p3=fopen(A_REPUESTOS,"wb");
    p4=fopen(A_TECNICOS,"wb");

    fclose(p1);
    fclose(p2);
    fclose(p3);
    fclose(p4);
}


///MENU PRINCIPAL CLIENTES///
void menu_clientes(){
    while(true){
        clrscr();
        char opc;
        Cliente cl;
        titulo_programa();
        cout<<"MENU CLIENTES"<<endl<<endl;
        cout<<"1) Cargar nuevo cliente"<<endl;
        cout<<"2) Modificar cliente"<<endl;
        cout<<"3) Buscar Cliente"<<endl;
        cout<<"4) Listar clientes"<<endl<<endl;
        cout<<"0) Volver"<<endl<<endl;
        cout<<"Elija una Opcion: ";
        cin>>opc;
        switch(opc){
        case '1':
            if (cl.cargar_nuevo_cliente()==true){cl.guardar_cliente();}
            break;
        case '2':
            modificar_cliente();
            break;
        case '3':
            buscar_cliente_dni();
            break;
        case '4':
            listar_clientes();
            break;
        case '0':
            return;
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
///MENU PRINCIPAL REPARACIONES///
void menu_reparaciones(){
    Reparaciones r;
    while(true){
        clrscr();
        char opc;
        titulo_programa();
        cout<<"MENU REPARACIONES"<<endl<<endl;
        cout<<"1) Iniciar una reparacion "<<endl;
        cout<<"2) Finalizar una reparacion"<<endl;
        cout<<"3) Listar Reparaciones"<<endl;
        cout<<"4) Buscar reparaciones por Numero de Orden"<<endl<<endl;
        cout<<"0) Volver"<<endl<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;
        switch(opc){

        case '1':
            if (r.iniciar_reparacion()==true){r.guardar_reparacion();}
            break;

        case '2':
            if (r.finalizar_reparacion()==true){
                cout<<"REPARACION FINALIZADA!!!"<<endl;
                pause();
            }
            break;

        case '3':
            listar_reparaciones();
            break;

        case '4':
            buscar_reparacion();
            break;

        case '0':
            return;
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

///MENU PRINCIPAL TECNICOS///
void menu_tecnicos(){
    Tecnicos tec;
    while(true){
        clrscr();
        char opc;
        titulo_programa();
        cout<<"MENU TECNICOS"<<endl<<endl;
        cout<<"1) Cargar nuevo tecnico"<<endl;
        cout<<"2) Modificar datos de tecnico"<<endl;
        cout<<"3) Buscar Tecnico por ID"<<endl;
        cout<<"4) Listar TODOS los tecnicos"<<endl<<endl;
        cout<<"0) Volver"<<endl<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;
        switch(opc){

        case '1':
        if (tec.Cargar_Tecnico() == true){tec.Guardar_Tecnico();}
        break;

        case '2':
            modificar_tecnico();
            break;

        case '3':
            buscar_tecnico_x_id();
            break;

        case '4':
            Listar_Tecnicos();
            break;

        case '0':
            return;
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

///MENU PRINCIPAL REPUESTOS///
void menu_repuestos(){
     while(true){
        clrscr();
        char opc;
        Repuestos re;

        titulo_programa();
        cout<<"MENU REPUESTOS"<<endl<<endl;
        cout<<"1) Cargar nuevo repuesto"<<endl;
        cout<<"2) Agregar repuesto"<<endl;
        cout<<"3) Buscar repuesto por codigo"<<endl;
        cout<<"4) Listar TODOS los repuestos que estan en falta"<<endl;
        cout<<"5) Listar TODOS los repuestos en stock"<<endl<<endl;
        cout<<"0) Volver"<<endl<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;

        switch(opc){
        case '1':
            if (re.cargar_nuevo_repuesto()==true){re.guardar_repuesto();}
            break;

        case '2':
            agregar_repuesto();
            break;

        case '3':
            listar_repuesto_por_codigo();
            break;

        case '4':
            listar_repuestos_falta();
            break;

        case '5':
            listar_todo_repuestos();
            break;

        case '0':
            return;
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

///MENU MANTENIMIENTO///
void opc_tecnico(){
    while(true){
        char opc;
        clrscr();
        titulo_programa();
        cout<<"OPCIONES TECNICOS"<<endl<<endl;
        cout<<"1) BAJA Tecnico"<<endl;
        cout<<"2) ALTA Tecnico"<<endl;
        cout<<"3) Modificar Tecnico"<<endl;
        cout<<"4) Vaciar registros TECNICOS"<<endl<<endl;
        cout<<"0) Volver"<<endl<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;

        switch(opc){
        case '1':
            baja_tecnico();
            break;
        case '2':
            alta_cliente();
            break;
        case '3':
            modificar_tecnico();
            break;
        case '4':
            vaciar_tecnico();
            break;
        case '0':
            return;
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

void opc_cliente(){
    while(true){
        char opc;
        clrscr();

        titulo_programa();
        cout<<"OPCIONES CLIENTE"<<endl<<endl;
        cout<<"1) BAJA Cliente"<<endl;
        cout<<"2) ALTA Cliente"<<endl;
        cout<<"3) Vaciar archivo CLIENTE"<<endl<<endl;
        cout<<"0) Volver"<<endl<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;
        switch(opc){
        case '1':
            baja_cliente();
        break;
        case '2':
            alta_cliente();
            break;
        case '3':
            vaciar_cliente();
            break;
        case '0':
            return;
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


void menu_mantenimiento(){
    while(true){
    char opc;
    clrscr();
    titulo_programa();
    cout<<"MENU MANTENIMIENTO"<<endl<<endl;
    cout<<"1) Realizar backup"<<endl;
    cout<<"2) Restaurar desde el ultimo backup"<<endl<<endl;
    //cout<<"3) VACIAR TODO (SACAR)"<<endl<<endl;
    cout<<"0) Volver"<<endl<<endl;
    cout<<"Elija una opcion: ";
    cin>>opc;
        switch(opc){
        case '1':
            if (bkp_todo()==true){
                clrscr();
                titulo_programa();
                loading_bar(22,"REALIZANDO BACKUP...",40);
                clrscr();
                titulo_programa();
                cout<<"BACKUP TERMINADO!!!"<<endl;
                pause();
                return;
            }
           break;
        case '2':
            if (restaurar_todo()==true){
                clrscr();
                titulo_programa();
                loading_bar(22,"RESTAURANDO...",40);
                clrscr();
                titulo_programa();
                cout<<"RESTAURACION TERMINADA!!!"<<endl;
                pause();
                return;
            }
            break;
            /*
        case '3':
            vaciar_todo();
            break;
            */
        case '0':
            return;
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
///MENU ADMIN///
void menu_adm(){
    while (true){
        clrscr();
        titulo_programa();
        char opc;
        cout<<"MENU ADMINISTRADOR"<<endl<<endl;
        cout<<"1) Mantenimiento"<<endl;
        cout<<"2) Vaciar REPARACIONES"<<endl;
        cout<<"3) Vaciar REPUESTOS"<<endl;
        cout<<"4) Administrar CLIENTES"<<endl;
        cout<<"5) Administrar TECNICOS"<<endl<<endl;
        cout<<"0) CERRAR SESION"<<endl<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;
        switch(opc){
        case '1':
            menu_mantenimiento();
            break;
        case '2':
            vaciar_reparacion();
            break;
        case '3':
            vaciar_repuesto();
            break;
        case '4':
            opc_cliente();
            break;
        case '5':
            opc_tecnico();
            break;
        case '0':
            return;
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

///MENU REPORTES///
void menu_reportes(){
    while (true){
        clrscr();
        char opc;
        titulo_programa();
        cout<<"REPORTES"<<endl<<endl;
        //CAMBIAR NOMBRE DE REPORTES
        cout<<"1) Cantidad de Reparaciones finalizadas en total y por mes"<<endl;
        cout<<"2) Ganancia total por mes y promedio de ganancia total"<<endl;
        cout<<"3) Cantidad de Reparaciones finalizadas por tecnico"<<endl;
        cout<<"4) Cantidad de Repuestos por categoria"<<endl;
        cout<<"5) Buscar cliente, muestra gastos totales y las ordenes"<<endl<<endl;
        cout<<"0) Volver"<<endl<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;
        switch(opc){

        case '1':
            reporte_1();
            break;

        case '2':
            reporte_2();
            break;

        case '3':
            reporte_3();
            break;

        case '4':
            reporte_4();
            break;

        case '5':
            reporte_5();
            break;

        case '0':
            return;
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


///MENU PRINCIPAL///
void menu_principal(){
    while(true){
        char opc;
        char opcsalida;
        titulo_programa();

        Tecnicos tec;
        int pos=0;
        bool log;
        while(tec.Leer_Tecnico(pos++)){
            clrscr();
            titulo_programa();
            if (tec.getlog()==true){
            cout<<"BIENVENIDO: ";
            cout<<tec.getnombre()<<", "<<tec.getapellido()<<endl<<endl;
            pos=0;
            cout<<"MENU PRINCIPAL"<<endl<<endl;
            cout<<"1) Clientes"<<endl;
            cout<<"2) Reparaciones"<<endl;
            cout<<"3) Repuestos"<<endl;
            cout<<"4) Reportes"<<endl<<endl;
            cout<<"0) CERRAR SESION"<<endl<<endl;
            cout<<"Elija una Opcion: ";
            cin>>opc;
                switch(opc){
            case '1':
                menu_clientes();
                break;
            case '2':
                menu_reparaciones();
                break;
            case '3':
                menu_repuestos();
                break;
            case '4':
                menu_reportes();
                break;
            case '0':
                clrscr();
                titulo_programa();
                cout<<"CERRAR SESION? (S/N)";
                cin>>opcsalida;

                switch(opcsalida){
                case 'n':
                case 'N':
                    menu_principal();
                    break;

                case 's':
                case 'S':
                    log = false;
                    tec.setlog(log);
                    tec.modificar_de_disco(pos);
                    return;
                    break;

                default:
                    clrscr();
                    titulo_programa();
                    cout<<"OPCION INVALIDA!!!"<<endl;
                    pause();
                    break;
                }

            default:
            clrscr();
            titulo_programa();
            cout<<"OPCION INVALIDA!!!"<<endl;
            pause();
            break;
                }
            }
        }
    }
}


#endif // MENUES_H_INCLUDED
