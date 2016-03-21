#include "comunes.h"

Departamentos* crear_departamento(int id,char Nombre[50])
{
    Departamentos* current;
    current=(Departamentos*)malloc(sizeof(Departamentos));
    current->id=id;
    strcpy(current->Nombre,Nombre);
    current->sgt=NULL;
    return current;
}
void salvar_departamento(Departamentos** cabeza)
{
    FILE* data;
    Departamentos* aux,*voltear;
    aux=(Departamentos*)malloc(sizeof(Departamentos));
    if((data=fopen("arch_departamentos.BIN","w+b"))==NULL)
    {
        printf("No se pudo guardar el archivo de departamento");
        return 0;
    }
    aux=*cabeza;
    while(aux!=NULL)
    {
        fwrite(aux,sizeof(Departamentos),1,data);
        aux=aux->sgt;


    }

}

void cargar_departamento(Departamentos** cabeza)
{
    FILE* data;
    Departamentos *aux = (Departamentos*)malloc(sizeof(Departamentos)),aux2;
    if((data=fopen("arch_departamentos.BIN","r+b"))==NULL)
    {
        *cabeza = NULL;
        printf("No se pudo abrir el archivo de departamento");
        return ;
    }

    rewind(data);
    fseek(data,0,SEEK_END);
    int tamano;
    aux = *cabeza;

    tamano  = ftell(data)/sizeof(Departamentos);
    if(tamano == 0)
    {
        *cabeza = NULL;
        return;
    }
    rewind(data);
    while(!feof(data) && tamano!= 0)
    {
        fread(aux,sizeof(Departamentos),1,data);

        aux->sgt=(Departamentos*)malloc(sizeof(Departamentos));

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

    printf("\nDepartamentos cargados!\nPresione enter para iniciar");

}

void ingresar_departamento(Departamentos** cabeza)
{
    system("CLS");
    marco();
    int id,Creditos,siono;

    if(saberfunc_dep(*cabeza)>=4)
    {
        printf("No se admiten mas Departamentos");
        getch();
        return;
    }

    Departamentos* nuevo,*aux;
    char Codigo[10],Nombre [50];
    fflush(stdin);
    gotoxy(11,11);

    gotoxy(11,12);
    puts("Nombre del departamento: ");
    gotoxy(11,13);
    scanf("%s",&Nombre);
    fflush(stdin);
    gotoxy(11,15);
    fflush(stdin);
    id=saberfunc_dep(*cabeza);

    nuevo=crear_departamento(id,Nombre);
    nuevo->sgt=(*cabeza);
    gotoxy(13,17);
    printf("Departamento creado exitosamente!");
    getch();
    *cabeza=nuevo;
}




int Departamentos_registrados(Departamentos* cabeza)
{
    Departamentos* aux_asig;
    int i=11;

    printf("Estas son las Departamentos registradas\n",161);
    for(aux_asig=(cabeza); aux_asig; aux_asig=aux_asig->sgt)
    {
        gotoxy(13,i+1);
        i++;
        printf("%d\t%s",aux_asig->id,aux_asig->Nombre);
    }
    return i;
}

void mostrar_departamento(Departamentos* cabeza)
{
    Departamentos* aux;
    int i=11,j=12;
    system("CLS");
    marco();
    for(aux=cabeza; aux; aux=aux->sgt)
    {
        gotoxy(i,j);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        gotoxy(i,j+1);
        printf("%c \t %d \t %s",186,aux->id+1,aux->Nombre);
        j+=2;
    }
}

int saberfunc_dep(Departamentos* cabeza)
{
    int k=0;
    Departamentos* aux= cabeza;
    for (; aux!=NULL; aux=aux->sgt)
        k++;
    return k;
}
