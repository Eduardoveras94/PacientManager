#include "comunes.h"

void insetar_tamanos(Estudio *cabeza,hw tareas[])
{
    Estudio *aux=cabeza;
    int i;
    for(i=0; i<10; i++)
    {
        if(tareas[i].longi<0)
            continue;
        for(aux=cabeza; aux; aux=aux->sgt)
        {
            if(tareas[i].longi==aux->id)
            {
                tareas[i].tamano=aux->duracion;
            }

        }

    }

}

void Burbuja(hw valores[],int indice1,int indice2)
{
    int burbuja;
    burbuja = valores[indice1].longi;
    valores[indice1].longi = valores[indice2].longi;
    valores[indice2].longi = burbuja;
    burbuja = valores[indice1].tamano;
    valores[indice1].tamano = valores[indice2].tamano;
    valores[indice2].tamano = burbuja;
    //printf("%d %d \n",valores[indice1].longi,valores[indice2].longi);
}

int Particionar (hw valores[],int limI,int limS)
{
    //Asumimos que valore[limI] tine el pivote
    int i, part=limI+1;

    for(i = limI+1; i<=limS; i++)
    {
        if(valores[i].tamano< valores[limI].tamano)
        {
            Burbuja(valores, i, part);
            part++;
        }
    }
    //Colocamos el pivote donde corresponde:
    Burbuja(valores,limI,part-1);
    return part-1;
}

void QuickSortRec(hw valores[], int limI, int limS)
{
    //AXIOMA
    int pivote,k;
    if(limI>=limS)
    {
//            for(k=0;k<10;k++)
//            {
//                printf("%d,",valores[k].longi);
//            }
//
//        printf("\n");
        return;
    }


    pivote = SeleccionarPivote(valores);
    pivote = Particionar(valores,limI,limS);

    QuickSortRec(valores, limI, pivote-1);
    QuickSortRec(valores,pivote+1,limS);

}

int SeleccionarPivote(int valores[])
{
    //Esta funcion deberia implementar un
    //algoritmo Rand omizer para elegir cualquier
    //valor aleatorio
    //Luego lo deberia colocar en la posicion 0
    //porque Particionar espera que sea asi.

    return 0; //El arreglo ya esta aleaotorio
}



















int Particionar_b(hw valores[],int limI,int limS)
{
    //Asumimos que valore[limI] tine el pivote
    int i, part=limI+1;

    for(i = limI+1; i<=limS; i++)
    {
        if(valores[i].tamano> valores[limI].tamano)
        {
            Burbuja(valores, i, part);
            part++;
        }
    }
    //Colocamos el pivote donde corresponde:
    Burbuja(valores,limI,part-1);
    return part-1;
}

void QuickSortRec_b(hw valores[], int limI, int limS)
{
    //AXIOMA
    int pivote,k;
    if(limI>=limS)
    {
//            for(k=0;k<10;k++)
//            {
//                printf("%d,",valores[k].longi);
//            }
//
//        printf("\n");
        return;
    }


    pivote = SeleccionarPivote(valores);
    pivote = Particionar_b(valores,limI,limS);

    QuickSortRec(valores, limI, pivote-1);
    QuickSortRec(valores,pivote+1,limS);

}
