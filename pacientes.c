#include "comunes.h"

Paciente* crear_Paciente(int ident,char nom[50],char Ap[50],int eddd)
{
    Paciente* current;
    current=(Paciente*)malloc(sizeof(Paciente));
    current->id=ident;
    strcpy(current->Nombres ,nom);
    strcpy(current->Apellido,Ap);
    current->edad=eddd;
    current->sgt=NULL;
    return current;
}
void ingresar_paciente(Paciente** cabeza)
{
    if(saberfunc_est(*cabeza)>9)
    {
        system("CLS");
        marco();
        printf("Solo se pueden registrar un maximo de 10 pacientes.");
        getch();

    }
    else
    {


        system("CLS");
        marco();
        int id;
        Paciente* nuevo,*aux;
        char Nombres[50],Departamento[50],op;
        int duracion;

        fflush(stdin);
        puts("Ingrese nombre: ");
        gotoxy(11,11);
        gets(Nombres);
        fflush(stdin);
        gotoxy(11,13);
        puts("Ingrese el apellido: ");
        gotoxy(11,15);
        gets(Departamento);
        fflush(stdin);

        gotoxy(11,19);
        printf("Ingrese edad: ");
        scanf("%d",&duracion);
        fflush(stdin);

        id=saberfunc_pac(*cabeza);
        nuevo=crear_Paciente(id,Nombres,Departamento,duracion);


        gotoxy(11,21);
        nuevo->sgt=*cabeza;
        gotoxy(11,22);
        textbackground(GREEN);
        printf("Registrado!");
        getch();
        *cabeza=nuevo;
    }
}


void mostrar_paciente(Paciente* cabeza)
{
    Paciente* aux;
    printf("\n");
    system("CLS");
    marco();
    int Y=10,X=11;

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
        printf("   Apellido: ");
        printf("%s",aux->Apellido);
        gotoxy(X,Y+3);
        textcolor(YELLOW);
        printf("%c",186);
        textcolor(WHITE);
        printf("   Edad: ");
        printf("%d",aux->edad);
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


void salvar_paciente(Paciente** cabeza)
{
    FILE* arch;
    Paciente* aux,*voltear;
    aux=(Paciente*)malloc(sizeof(Paciente));
    if((arch=fopen("arch_paciente.BIN","w+b"))==NULL)
    {
        printf("No se pudo guardar el archivo de estudiante");
        return 0;
    }
    aux=*cabeza;
    while(aux!=NULL)
    {
        fwrite(aux,sizeof(Paciente),1,arch);
        aux=aux->sgt;


    }

}

void cargar_paciente(Paciente** cabeza)
{
    FILE* arch;
    Paciente *aux = (Paciente*)malloc(sizeof(Paciente)),aux2;
    if((arch=fopen("arch_paciente.BIN","r+b"))==NULL)
    {
        *cabeza = NULL;
        printf("No se pudo abrir el archivo de estudiante");
        return ;
    }
    rewind(arch);
    fseek(arch,0,SEEK_END);
    int tamano;
    aux = *cabeza;
    tamano  = ftell(arch)/sizeof(Paciente);
    if(tamano == 0)
    {
        *cabeza = NULL;
        return;
    }
    rewind(arch);
    while(!feof(arch) && tamano!= 0)
    {
        fread(aux,sizeof(Paciente),1,arch);
        //system("Pause");
        //aux=crear_Paciente(aux2.id,aux2.Matricula,aux2.Nombres,aux2.Apellidos,aux2.Carrera);
        //printf("%s\n",aux->Nombres);
        aux->sgt=(Paciente*)malloc(sizeof(Paciente));
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

    printf("\nPacientes cargados!\nPresione enter para iniciar");

}

int saberfunc_pac(Paciente* cabeza)
{
    int k=0;
    Paciente* aux =(Paciente*)malloc(sizeof(Paciente));
    aux= cabeza;
    for (; aux!=NULL; aux=aux->sgt)
        k++;
    free(aux);
    return k;

}
