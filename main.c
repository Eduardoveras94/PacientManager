/* Proyeto final - Turnero medico */
#include <stdio.h>
#include <stdlib.h>
#include "comunes.h"
#include <conio.c>

int main()
{
    Estudio *primer_Estudio=(Estudio*)malloc(sizeof(Estudio));
    Paciente *primer_Paciente=(Paciente*)malloc(sizeof(Paciente));
    Departamentos *primer_Departamento=(Departamentos*)malloc(sizeof(Departamentos));

    int opcion;                                    //En esta parte se cargan todos los datos guardados anteriormente
    cargar_estudios(&primer_Estudio);              //se declaran el inicio de las listas enlazadas y se hacen 3
    cargar_paciente(&primer_Paciente);             //switch para los 3 menus principales, ademas de que se llaman
    cargar_departamento(&primer_Departamento);     //las funciones para las estetica del programa
    loading();                                     //
    //ingresar_departamento(&primer_Departamento);
    do
    {
        switch(menu_inicio())
        {
        case 1:
            contrasenia();
            do
            {
                //MENU DE PACIENTES
                marco();
                switch(menu_paciente())
                {
                case 1:
                    ingresar_paciente(&primer_Paciente);
                    break;
                case 2:
                    mostrar_paciente(primer_Paciente);
                    getch();
                    break;
                case 3:
                    turnero(primer_Paciente,primer_Estudio,primer_Departamento);
                    break;
                case 4:
                    opcion=-1;
                    break;

                }
            }
            while(opcion!=-1);
            break;
        case 2:
            contrasenia();  //MENU MEDICOS
            do
            {
                marco();
                switch(menu_medico())
                {
                case 1:
                    ingresar_estudio(&primer_Estudio,&primer_Departamento);
                    break;
                case 2:
                    break;
                case 3:
                    mostrar_estudios(primer_Estudio,primer_Departamento);
                    getch();
                    break;
                case 4:
                    mostrar_departamento(primer_Departamento);
                    getch();
                    break;
                case 5:
                    turnero(primer_Paciente,primer_Estudio,primer_Departamento);

                    break;
                case 6:
                    opcion=145;
                    break;

                }
            }
            while(opcion!=145);
            break;
        case 3:
            system("CLS");
            marco();
            salvar_estudios(&primer_Estudio);              //Aqui se guardan todos los datos
            salvar_paciente(&primer_Paciente);             //de pacientes, departamentos y estudios
            salvar_departamento(&primer_Departamento);
            bye();
            return 0;
        }
    }
    while(opcion!=3);
    return 0;

}

