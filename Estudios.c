#include "comunes.h"

Estudio* crear_Estudio(int ident,char nom[50],int dep,int dur)
{
    Estudio* current;
    current=(Estudio*)malloc(sizeof(Estudio));
    current->id=ident;
    current->Departamento=dep;
    strcpy(current->Nombres,nom);
    current->duracion=dur;
    current->sgt=NULL;
    return current;
}

int Mostrar_studios_registrados(Estudio* cabeza)
{
    Estudio* aux_Est;
    int i=11;

    printf("Estas son las estudios registradas",161);
    i++;
    gotoxy(11,i);
    printf("ID\tNombre\t\tDuarcion");
    for(aux_Est=(cabeza); aux_Est; aux_Est=aux_Est->sgt)
    {
        gotoxy(13,i+1);
        i++;
        printf("%d\t%s\t\t%d",aux_Est->id,aux_Est->Nombres,aux_Est->duracion);
    }
    return i;

}

void ingresar_estudio(Estudio** cabeza,Departamentos** cabeza_dep)
{
    if(saberfunc_est(*cabeza)>9)
    {
        system("CLS");
        marco();
        printf("Solo se pueden registrar un maximo de 10 estudios.");
        getch();

    }
    else
    {


        system("CLS");
        marco();
        int id;
        Estudio* nuevo,*aux;
        char Nombres[50],op;
        int duracion,Departamento;

        fflush(stdin);
        puts("Ingrese nombre: ");
        gotoxy(11,11);
        gets(Nombres);
        fflush(stdin);
        marco();
        mostrar_departamento(*cabeza_dep);
        gotoxy(11,30);
        puts("Ingrese el ID del departamento al que pertenece: ");
        gotoxy(11,31);

        scanf("%d",&Departamento);
        fflush(stdin);
        marco();

        gotoxy(12,16);

        do
        {
            printf("Duracion en horas(maximo 10): ");
            scanf("%d",&duracion);
        }
        while(duracion>10||duracion<0);

        fflush(stdin);

        id=saberfunc_est(*cabeza);
        nuevo=crear_Estudio(id,Nombres,Departamento-1,duracion);


        gotoxy(11,21);
        nuevo->sgt=*cabeza;
        gotoxy(11,22);
        textbackground(GREEN);
        printf("Registrado!");
        getch();
        *cabeza=nuevo;
    }
}


void mostrar_estudios(Estudio* cabeza,Departamentos* cabeza_dept)
{
    Estudio* aux;
    printf("\n");
    system("CLS");
    marco();
    int Y=10,X=11;
    Departamentos *aux_dept;

    for(aux=cabeza; aux; aux=aux->sgt)
    {
        textcolor(YELLOW);
        gotoxy(X,Y-1);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

        gotoxy(X,Y);
        printf("%c",186);
        textcolor(WHITE);
        printf(" ID: ");
        printf("%d",aux->id);
        gotoxy(X,Y+1);
        textcolor(YELLOW);
        printf("%c",186);
        textcolor(WHITE);
        printf("   Nombre: ");
        printf("%s",aux->Nombres);
        gotoxy(X,Y+2);
        textcolor(YELLOW);
        printf("%c",186);
        textcolor(WHITE);
        printf("  Departamento:");
        for(aux_dept=cabeza_dept; aux_dept; aux_dept=aux_dept->sgt)
        {
            if(aux_dept->id==aux->Departamento)
            {
                printf("%s",aux_dept->Nombre);
                break;
            }
        }

        //printf("%d",aux->Departamento);
        gotoxy(X,Y+3);
        textcolor(YELLOW);
        printf("%c",186);
        textcolor(WHITE);
        printf("   Duracion en horas: ");
        printf("%d",aux->duracion);
        textcolor(WHITE);
        //printf("   Carrera: ");
        //printf("%s",aux->Carrera);
        gotoxy(X,Y+4);
        textcolor(YELLOW);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        gotoxy(X+43,Y);
        printf("%c",186);
        gotoxy(X+43,Y+1);
        printf("%c",186);
        gotoxy(X+43,Y+2);
        printf("%c",186);
        gotoxy(X+43,Y+3);
        printf("%c",186);
        textcolor(WHITE);
        if(X==11)
            X+=48;
        else
        {
            Y+=6;
            X=11;
        }


    }
}


void salvar_estudios(Estudio** cabeza)
{
    FILE* arch;
    Estudio* aux,*voltear;
    aux=(Estudio*)malloc(sizeof(Estudio));
    if((arch=fopen("arch_estudio.BIN","w+b"))==NULL)
    {
        printf("No se pudo guardar el archivo de estudiante");
        return 0;
    }
    aux=*cabeza;
    while(aux!=NULL)
    {
        fwrite(aux,sizeof(Estudio),1,arch);
        aux=aux->sgt;


    }

}

void cargar_estudios(Estudio** cabeza)
{
    FILE* arch;
    Estudio *aux = (Estudio*)malloc(sizeof(Estudio)),aux2;
    if((arch=fopen("arch_estudio.BIN","r+b"))==NULL)
    {
        *cabeza = NULL;
        printf("No se pudo abrir el archivo de estudiante");
        return ;
    }

    rewind(arch);
    fseek(arch,0,SEEK_END);
    int tamano;
    aux = *cabeza;
    tamano  = ftell(arch)/sizeof(Estudio);
    if(tamano == 0)
    {
        *cabeza = NULL;
        return;
    }
    rewind(arch);
    while(!feof(arch) && tamano!= 0)
    {
        fread(aux,sizeof(Estudio),1,arch);
        //system("Pause");
        //aux=crear_Estudio(aux2.id,aux2.Matricula,aux2.Nombres,aux2.Apellidos,aux2.Carrera);
        //printf("%s\n",aux->Nombres);
        aux->sgt=(Estudio*)malloc(sizeof(Estudio));
        printf("safe");
        tamano--;

        if(tamano == 0)
        {
            aux->sgt = NULL;
            //*cabeza = NULL;
            break;
        }
        //printf("safe");
        aux = aux->sgt;
        //*cabeza=aux;
    }
    printf("safe");

    printf("\nEstudios cargados!\nPresione enter para iniciar");

}

int saberfunc_est(Estudio* cabeza)
{
    int k=0;
    Estudio* aux =(Estudio*)malloc(sizeof(Estudio));
    aux= cabeza;
    for (; aux!=NULL; aux=aux->sgt)
        k++;
    free(aux);
    return k;

}
