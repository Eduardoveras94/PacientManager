#ifndef COMUNESH
#define COMUNESH

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void marco();
int menu_medico();
int menu_paciente();

typedef struct estudio
{
    short id;
    char Nombres [100];
    int Departamento;
    int duracion;
    struct estudio *sgt;

}Estudio;


typedef struct paciente
{
    short id;
    char Nombres [100];
    char Apellido[60];
    int edad;
    struct estudio *sgt;

}Paciente;

typedef struct departamentos
{
    int id;
    char Nombre [50];
    struct departamentos *sgt;

}Departamentos;


typedef struct
{
    int indice;
    int longi;
    int tamano;
} hw;

typedef struct
{
    hw tarea[11];
    int no_proceso;
    int cant_tareas;
    char orden;
} ID;


#endif // COMUNESH

