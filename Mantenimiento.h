#ifndef MANTENIMIENTO_H_INCLUDED
#define MANTENIMIENTO_H_INCLUDED

///**************************************************BACKUP Y RESTAURACION**************************************************///

///BACKUPS
//CLIENTE
bool backupCliente(){
    Cliente aux;
    int pos = 0;
    FILE *pf;
    pf=fopen(BKP_CLIENTES,"wb");
    if(pf== NULL) exit(1);
    while(aux.leerCliente(pos)){
        fwrite(&aux,sizeof (Cliente),1,pf);
        pos++;
    }
    fclose(pf);
    return true;
}
//TECNICOS
bool backupTecnico(){
    Tecnicos aux;
    int pos = 0;
    FILE *pf;
    pf=fopen(BKP_TECNICOS,"wb");
    if(pf== NULL) exit(1);
    while(aux.Leer_Tecnico(pos)){
        fwrite(&aux,sizeof (Tecnicos),1,pf);
        pos++;
    }
    fclose(pf);
    return true;
}
//REPARACIONES
bool backupReparaciones(){
    Reparaciones aux;
    int pos = 0;
    FILE *pf;
    pf=fopen(BKP_REPARACIONES,"wb");
    if(pf== NULL) exit(1);
    while(aux.leer_reparacion(pos)){
        fwrite(&aux,sizeof (Reparaciones),1,pf);
        pos++;
    }
    fclose(pf);
    return true;
}
//REPUESTOS
bool backupRepuestos(){
    Repuestos aux;
    int pos = 0;
    FILE *pf;
    pf=fopen(BKP_REPUESTOS,"wb");
    if(pf== NULL) exit(1);
    while(aux.leer_repuesto(pos)){
        fwrite(&aux,sizeof (Repuestos),1,pf);
        pos++;
    }
    fclose(pf);
    return true;
}

///confirmar bkp
bool bkp_todo(){
    if (backupCliente()==false)return false;
    if (backupTecnico()==false)return false;
    if (backupReparaciones()==false)return false;
    if (backupRepuestos()==false)return false;

    return true;
}

///RESTAURACION
bool restaurarCliente(){
    Cliente aux;
    Cliente reg;

    FILE *pf;
    pf=fopen(BKP_CLIENTES,"rb");
    if(pf== NULL) exit(1);

    FILE *cpy;
    cpy=fopen(A_CLIENTES,"wb");
    if(pf==NULL)exit(1);

    while(fread(&aux, sizeof(Cliente),1,pf))
    {
     reg = aux ;
     fwrite(&reg,sizeof (Cliente),1,cpy);
    }
    fclose(cpy);
    fclose(pf);
    return true;

}

///TECNICOS
bool restaurarTecnicos(){
    Tecnicos aux;
    Tecnicos reg;

    FILE *pf;
    pf=fopen(BKP_TECNICOS,"rb");
    if(pf== NULL) exit(1);

    FILE *cpy;
    cpy=fopen(A_TECNICOS,"wb");
    if(pf==NULL)exit(1);

    while(fread(&aux, sizeof(Tecnicos),1,pf))
    {
     reg = aux ;
     fwrite(&reg,sizeof (Tecnicos),1,cpy);
    }
    fclose(cpy);
    fclose(pf);
    return true;

}

///REPARACIONES
bool restaurarReparacion(){
    Reparaciones aux;
    Reparaciones reg;

    FILE *pf;
    pf=fopen(BKP_REPARACIONES,"rb");
    if(pf== NULL) exit(1);

    FILE *cpy;
    cpy=fopen(A_REPARACIONES,"wb");
    if(pf==NULL)exit(1);

    while(fread(&aux, sizeof(Reparaciones),1,pf))
    {
     reg = aux ;
     fwrite(&reg,sizeof (Reparaciones),1,cpy);
    }
    fclose(cpy);
    fclose(pf);
    return true;

}

///REPUESTOS
bool restaurarRepuestos(){
    Repuestos aux;
    Repuestos reg;

    FILE *pf;
    pf=fopen(BKP_REPUESTOS,"rb");
    if(pf== NULL) exit(1);

    FILE *cpy;
    cpy=fopen(A_REPUESTOS,"wb");
    if(pf==NULL)exit(1);

    while(fread(&aux, sizeof(Repuestos),1,pf))
    {
     reg = aux ;
     fwrite(&reg,sizeof (Repuestos),1,cpy);
    }
    fclose(cpy);
    fclose(pf);
    return true;

}

///confirmar restauracion
bool restaurar_todo(){
    if (restaurarCliente()==false)return false;
    if (restaurarTecnicos()==false)return false;
    if (restaurarReparacion()==false)return false;
    if (restaurarRepuestos()==false)return false;

    return true;
}

#endif // MANTENIMIENTO_H_INCLUDED
