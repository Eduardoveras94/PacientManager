#ifndef PACIENTE
#define PACIENTE

Paciente* crear_Paciente(int ident,char nom[50],char dep[50],int dur);
void ingresar_Paciente(Paciente** cabeza);
void mostrar_paciente(paciente* cabeza);
void modificar_paciente(Paciente*);
int saberfunc_pac(Paciente*);





#endif // PACIENTE
