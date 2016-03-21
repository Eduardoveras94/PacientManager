#include "comunes.h"

int turnero(Paciente* cabeza_pac,Estudio* cabeza_est,Departamentos* cabeza_dept)
{
    int posX=11,posY=11;
    Departamentos *aux_depp;
    ID p_estudios[11];
    marco();
    gotoxy(posX,posY);
    printf("Digite el ID del estudio que realizara cada paciente");
    posY=Mostrar_studios_registrados(cabeza_est)+2;


    int n,i,j,k,arr[4][300],copyarr[4][300],cont=0,suma=0;
    for(i=0; i<11; i++)
        for(j=0; j<11; j++)
        {
            p_estudios[i].tarea[j].longi=-1;
            p_estudios[i].cant_tareas=0;
            p_estudios[i].tarea[j].tamano=0;
        }

    for(i=0; i<4; i++)
    {
        for(j=0; j<300; j++)
        {
            arr[i][j]=-1;
            copyarr[i][j]=-1;
        }
    }

    n=saberfunc_pac(cabeza_pac);
    for(i=0; i<n; i++)
    {

        textbackground(i+1);
        textcolor(WHITE);
        gotoxy(posX,posY++);
        printf("Paciente no.%d:",i+1);
        textcolor(WHITE);
        textbackground(BLACK);
        scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&p_estudios[i].tarea[0].longi,
              &p_estudios[i].tarea[1].longi,
              &p_estudios[i].tarea[2].longi,
              &p_estudios[i].tarea[3].longi,
              &p_estudios[i].tarea[4].longi,
              &p_estudios[i].tarea[5].longi,
              &p_estudios[i].tarea[6].longi,
              &p_estudios[i].tarea[7].longi,
              &p_estudios[i].tarea[8].longi,
              &p_estudios[i].tarea[9].longi);
        gotoxy(posX,posY++);


        p_estudios[i].no_proceso=i+1;

        suma+=(p_estudios[i].tarea[0].tamano+
               p_estudios[i].tarea[1].tamano+
               p_estudios[i].tarea[2].tamano+
               p_estudios[i].tarea[3].tamano+
               p_estudios[i].tarea[4].tamano+
               p_estudios[i].tarea[5].tamano+
               p_estudios[i].tarea[6].tamano+
               p_estudios[i].tarea[7].tamano+
               p_estudios[i].tarea[8].tamano+
               p_estudios[i].tarea[9].tamano);

        for(j=0; j<11; j++)
            p_estudios[i].tarea[j].indice=j;

        if(suma>10)
        {
            printf("\nError, maximo de 10 horas.");
            suma=0;
            i--;
            continue;
        }
        printf("Especifique el ordenamiento(Ascendente o Descendente)(A) o (D): ");
        fflush(stdin);
        scanf("%c",&p_estudios[i].orden);
        insetar_tamanos(cabeza_est,p_estudios[i].tarea);
        if(p_estudios[i].orden=='A'||p_estudios[i].orden=='a')
        {
            QuickSortRec((p_estudios[i].tarea),0,9);
        }
        else
            QuickSortRec_b((p_estudios[i].tarea),0,9);
        suma=0;
        posY++;

    }
    posY+=2;
    gotoxy(posX,posY);
    textbackground(BLACK);
    int maximo_lineas=0;
    marco();
    posX=11;
    posY=11;
    posY+=4;
    gotoxy(posX,posY);
    printf("Gr%cfica de las cargas de cada departamento:",160);
    posY++;
    gotoxy(posX,posY);
    printf("N.\tCargas (Estudio/Paciente)");
    posY++;
    gotoxy(posX,posY);
    printf("==\t========================");
    posY++;
    gotoxy(posX,posY);
    posY+=2;


    int l,m,procesador=0,test=0,duracion;
    Estudio* aux=cabeza_est;
    for(i=0; i<n; i++)
    {
        k=0;

        for(j=0; j<10; j++)
        {


            if(p_estudios[i].tarea[j].longi!=-1)
            {

                for(aux=cabeza_est; aux; aux=aux->sgt)
                {
                    if(p_estudios[i].tarea[j].longi==aux->id)
                    {
                        procesador=aux->Departamento;
                        break;
                    }
                }
                m=k;
                for(;;)
                {
                    test=0;
                    for(; k<aux->duracion+m; k++)
                    {
                        if(revisarfila(arr,procesador,k,(aux->duracion)+k)==0&&test==0)
                        {
                            m++;
                            continue;
                        }
                        arr[procesador][k]=p_estudios[i].tarea[j].longi;
                        copyarr[procesador][k]=p_estudios[i].no_proceso;
                        test=1;
                        if(k>=maximo_lineas)
                            maximo_lineas=k;
                    }
                    if(test==1)break;
                }
            }
        }
    }


    for(i=0; i<4; i++)
    {
        posY++;
        gotoxy(posX,posY);
        //printf("%d:\t",i+1);

        for(aux_depp=cabeza_dept;aux_depp;aux_depp=aux_depp->sgt)
        {
            if(aux_depp->id==i)
            {
                printf("%s:\t",aux_depp->Nombre);
            }
        }

        for(j=0; j<maximo_lineas+1; j++)
        {
            if(copyarr[i][j]==-1)
            {
                textbackground(BLACK);
                printf("x ");
                continue;
            }
            else
            {
                if(copyarr[i][j]==0)
                    textbackground(0);
                if(copyarr[i][j]==1)
                    textbackground(1);
                if(copyarr[i][j]==2)
                    textbackground(2);
                if(copyarr[i][j]==3)
                    textbackground(3);
                if(copyarr[i][j]==4)
                    textbackground(4);
                if(copyarr[i][j]==5)
                    textbackground(5);
                if(copyarr[i][j]==6)
                    textbackground(6);
                if(copyarr[i][j]==7)
                    textbackground(7);
                if(copyarr[i][j]==8)
                    textbackground(8);
                if(copyarr[i][j]==9)
                    textbackground(9);
                if(copyarr[i][j]==10)
                    textbackground(10);
            }
            printf("%d ",arr[i][j]);

        }
        printf("\n");
        textbackground(BLACK);

    }
    posY+=3;
    Paciente *aux_pac= cabeza_pac;
    for(k=0;k<n;k++)
    {
        textbackground(BLACK);

        textcolor(WHITE);
        gotoxy(posX,posY);
        posY+=2;
        textbackground(k+1);
        printf("Paciente:");
        for(aux_pac= cabeza_pac;aux_pac;aux_pac=aux_pac->sgt)
            if(aux_pac->id==k)
            {
                gotoxy(posX,posY);
                printf("\t%s   %s",aux_pac->Nombres,aux_pac->Apellido);
                posY++;
                break;

            }
            textcolor(WHITE);
        textbackground(BLACK);
            for(j=0;j<10;j++)
            {
                if(p_estudios[k].tarea[j].longi==-1)
                continue;
                printf(" %d ",p_estudios[k].tarea[j].longi);
            }

    }



    getch();
    return 0;
}

int revisarfila(int arr[4][300],int y,int ind, int lugares)
{
    for(; ind<lugares; ind++)
    {
        if(arr[y][ind]>=0)
            return 0;
    }
    return 1;
}
