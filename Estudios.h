#ifndef ESTUDIANTES
#define ESTUDIANTES

Estudio* crear_Estudio(int ident,char nom[50],char dep[50],int dur);
void ingresar_estudio(Estudio** cabeza);
void mostrar_estudios(Estudio* cabeza,Departamentos* cabeza_dept);
void modificar_estudio(Estudio*);
int saberfunc_est(Estudio*);


#endif //EST
