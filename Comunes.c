#include "comunes.h"
#include <conio.h>


void loading()
{
    int i;
    system("CLS");
    system("color 2f");
    gotoxy(15,15);
    printf("CARGANDO");
    for(i=0; i<3; i++)
    {
        printf(". ");
        Sleep(400);
    }
    int x=15,y=16;
    for(i=0; i<16; i++)
    {
        gotoxy(x,y);
        textbackground(RED);
        printf("  ");
        x+=2;
        Sleep(60);
    }
    textbackground(GREEN);
    gotoxy(15,y+2);
    printf("Presione enter para entrar a la aplicacion.");

}


int menu_paciente()
{
    int lol,opcion;
    int menu=1;
    _setcursortype(0);

    do
    {
        textcolor(WHITE);
        textbackground (BLACK);
        gotoxy(11,10);
        printf("Buenas, Que desea hacer?\n");
        if(menu==1)
        {
            textcolor(RED);
            textbackground (YELLOW);
            gotoxy(11,12);
            printf("\t1: Registrar paciente.                                      \n");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            gotoxy(11,12);
            printf("\t1: Registrar paciente.                                      \n");
        }

        if (menu==2)
        {
            textcolor(RED);
            textbackground (YELLOW);
            gotoxy(11,13);
            printf("\t2: Mostrar pacientes registrados.                                 \n");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            gotoxy(11,13);
            printf("\t2: Mostrar pacientes registrados.                                 \n");
        }

        if (menu==3)
        {
            textcolor(RED);
            textbackground (YELLOW);
            gotoxy(11,14);
            printf("\t3: Control de turnos.                                          \n");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            gotoxy(11,14);
            printf("\t3: Control de turnos.                                           \n");
        }
        if (menu==4)
        {
            textcolor(BLACK);
            textbackground (YELLOW);
            gotoxy(97,7);
            printf("  X  ");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            textcolor(WHITE);
            textbackground (RED);
            gotoxy(97,7);
            printf("  X  ");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        lol=getch();
        //arriba
        if (lol==72)
        {
            menu-=1;
            if (menu<1)
            {
                menu=4;
            }
        }
        //abajo
        if (lol==80)
        {
            menu+=1;
            if (menu>4)
            {
                menu=1;
            }
        }
        if (lol==102||lol==70||lol==13)
        {
            lol=0;
        }
    }
    while(lol!=0);
    return menu;
}

void contrasenia()
{
    marco();
    char variable[100];
    _setcursortype(1);
    marco();
    gotoxy(54,15);
    printf("Usuario:");
    gotoxy(45,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(45,18);
    printf("%c                        %c",186,186);
    gotoxy(45,19);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(54,21);
    printf("Contrasena:");
    gotoxy(45,23);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(45,24);
    printf("%c                        %c",186,186);
    gotoxy(45,25);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(66,39);
    printf("  ");
    gotoxy(46,18);
    gets(variable);
    gotoxy(46,24);
    while(getch()!=13)
    {
        printf("*");
    }
    _setcursortype(0);
}


void marco()
{
    int i;
    system("CLS");
    system("color 4c");

    for(i=0; i<13; i++)
    {
        printf(" / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\_ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\_\n");
        printf("/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\__/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\__\n");
        printf("\\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / _\\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / __ \\ \\__/ / _\n");
        printf(" \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ /  \\ \\____/ / \n");

    }
    textcolor(WHITE);



    time_t now;
    time(&now);

    for(i=7; i<45; i++)
    {
        textbackground(BLACK);
        gotoxy(10,i);
        printf("%c                                                                                            %c",186,186);
        textbackground(RED);
    }

    for(i=5; i<52; i++)
    {
        textbackground(BLACK);
        gotoxy(i*2,6);
        printf("%c%c",205,205);
        textbackground(RED);
    }

    for(i=5; i<52; i++)
    {
        textbackground(BLACK);
        gotoxy(i*2,8);
        printf("%c%c",205,205);
        textbackground(RED);
    }

    for(i=5; i<52; i++)
    {
        textbackground(BLACK);
        gotoxy(i*2,45);
        printf("%c%c",205,205);
        textbackground(RED);
    }
    gotoxy(30,7);
    textbackground(BLACK);
    printf("\t\t\tCENTRO RADIOAGNOSIS");
    gotoxy(10,8);
    printf("%c",204);
    gotoxy(103,8);
    printf("%c",185);
    gotoxy(103,6);
    printf("%c",187);
    gotoxy(10,6);
    printf("%c",201);
    textbackground(RED);
    gotoxy(97,7);
    printf("  X  ");
    printf("\n");

    gotoxy(44,45);

    textbackground(BLACK);
    textcolor(WHITE);
    printf("%s", ctime(&now));
    gotoxy(11,9);
    _setcursortype(0);

}





int menu_medico()
{
    system("CLS");
    marco();
    int lol,opcion;
    int menu=1;
    do
    {
        textcolor(WHITE);
        textbackground (BLACK);
        gotoxy(11,10);
        printf("Buenas, Que desea hacer?\n");
        if(menu==1)
        {
            textcolor(RED);
            textbackground (YELLOW);
            gotoxy(11,12);
            printf("\t1: Registrar estudio nuevo.                                      \n");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            gotoxy(11,12);
            printf("\t1: Registrar estudio nuevo.                                      \n");
        }

        if (menu==2)
        {
            textcolor(RED);
            textbackground (YELLOW);
            gotoxy(11,13);
            printf("\t2: Modificar estudio existente.                                 \n");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            gotoxy(11,13);
            printf("\t2: Modificar estudio existente.                                 \n");
        }

        if (menu==3)
        {
            textcolor(RED);
            textbackground (YELLOW);
            gotoxy(11,14);
            printf("\t3: Mostrar estudios.                                          \n");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            gotoxy(11,14);
            printf("\t3: Mostrar estudios.                                           \n");
        }
        if (menu==4)
        {
            textcolor(RED);
            textbackground (YELLOW);
            gotoxy(11,15);
            printf("\t4: Mostrar departamentos.                                          \n");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            gotoxy(11,15);
            printf("\t4: Mostrar departamentos.                                           \n");
        }
        if (menu==5)
        {
            textcolor(RED);
            textbackground (YELLOW);
            gotoxy(11,16);
            printf("\t5: Control de turnero.                                          \n");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            gotoxy(11,16);
            printf("\t5: Control de turnero.                                           \n");
        }
        if (menu==6)
        {
            textcolor(BLACK);
            textbackground (YELLOW);
            gotoxy(97,7);
            printf("  X  ");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        else
        {
            textcolor(WHITE);
            textbackground (RED);
            gotoxy(97,7);
            printf("  X  ");
            textcolor(WHITE);
            textbackground (BLACK);
        }
        lol=getch();
        //arriba
        if (lol==72)
        {
            menu-=1;
            if (menu<1)
            {
                menu=6;
            }
        }
        //abajo
        if (lol==80)
        {
            menu+=1;
            if (menu>6)
            {
                menu=1;
            }
        }
        if (lol==102||lol==70||lol==13)
        {
            return menu;
            lol=0;
        }
    }
    while(lol!=0);
}

int menu_inicio()
{
    int opcion=75,menu=1;
    int seleccionado=75;
    system("CLS");
    marco();
    gotoxy(20,30);
    printf("\t*Use las teclas para moverse atravez de la aplicacion.");
    gotoxy(20,31);
    printf("\t*Muevase hasta la X para salir o volver atras.");
    gotoxy(20,32);
    printf("\t*Si no sale de esta manera, los datos no se guardaran.");

    do
    {



        if(menu==1)
        {
            textcolor(WHITE);
            textbackground (RED);
            gotoxy(97,7);
            printf("  X  ");
            textcolor(WHITE);
            textbackground(BLACK);

            gotoxy(30,13);
            printf("Como desea iniciar sesion?");
            textcolor(YELLOW);
            gotoxy(30,16);
            printf("%c%c%c%c%c%c*PACIENTES*%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,187);
            gotoxy(30,17);
            printf("%c         .-.         %c",186,186);
            gotoxy(30,18);
            printf("%c       __| |_        %c",186,186);
            gotoxy(30,19);
            printf("%c      [__   __]      %c",186,186);
            gotoxy(30,20);
            printf("%c         | |         %c",186,186);
            gotoxy(30,21);
            printf("%c         | |         %c",186,186);
            gotoxy(30,22);
            printf("%c         | |         %c",186,186);
            gotoxy(30,23);
            printf("%c         '-'         %c",186,186);
            gotoxy(30,24);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
            textcolor(WHITE);

            gotoxy(65,16);
            printf("%c%c%c%c%c%c%c*MEDICOS*%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,187);
            gotoxy(65,17);
            printf("%c        (            %c",186,186);
            gotoxy(65,18);
            printf("%c         \\           %c",186,186);
            gotoxy(65,19);
            printf("%c          )          %c",186,186);
            gotoxy(65,20);
            printf("%c     ##-------->     %c",186,186);
            gotoxy(65,21);
            printf("%c          )          %c",186,186);
            gotoxy(65,22);
            printf("%c         /           %c",186,186);
            gotoxy(65,23);
            printf("%c        (            %c",186,186);
            gotoxy(65,24);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

        }
        else if(menu==2)
        {
            textcolor(WHITE);
            textbackground (RED);
            gotoxy(97,7);
            printf("  X  ");
            textcolor(WHITE);
            textbackground (BLACK);

            textcolor(WHITE);
            gotoxy(30,16);
            gotoxy(30,16);
            printf("%c%c%c%c%c%c*PACIENTES*%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,187);
            gotoxy(30,17);
            printf("%c         .-.         %c",186,186);
            gotoxy(30,18);
            printf("%c       __| |_        %c",186,186);
            gotoxy(30,19);
            printf("%c      [__   __]      %c",186,186);
            gotoxy(30,20);
            printf("%c         | |         %c",186,186);
            gotoxy(30,21);
            printf("%c         | |         %c",186,186);
            gotoxy(30,22);
            printf("%c         | |         %c",186,186);
            gotoxy(30,23);
            printf("%c         '-'         %c",186,186);
            gotoxy(30,24);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
            textcolor(YELLOW);

            gotoxy(65,16);
            printf("%c%c%c%c%c%c%c*MEDICOS*%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,187);
            gotoxy(65,17);
            printf("%c        (            %c",186,186);
            gotoxy(65,18);
            printf("%c         \\           %c",186,186);
            gotoxy(65,19);
            printf("%c          )          %c",186,186);
            gotoxy(65,20);
            printf("%c     ##-------->     %c",186,186);
            gotoxy(65,21);
            printf("%c          )          %c",186,186);
            gotoxy(65,22);
            printf("%c         /           %c",186,186);
            gotoxy(65,23);
            printf("%c        (            %c",186,186);
            gotoxy(65,24);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
            textcolor(WHITE);

        }
        else if (menu==3)
        {
            textcolor(BLACK);
            textbackground (YELLOW);
            gotoxy(97,7);
            printf("  X  ");
            textcolor(WHITE);
            textbackground (BLACK);
            gotoxy(30,13);
            printf("Como desea iniciar sesion?");
            textcolor(WHITE);
            gotoxy(30,16);
            printf("%c%c%c%c%c%c*PACIENTES*%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,187);
            gotoxy(30,17);
            printf("%c         .-.         %c",186,186);
            gotoxy(30,18);
            printf("%c       __| |_        %c",186,186);
            gotoxy(30,19);
            printf("%c      [__   __]      %c",186,186);
            gotoxy(30,20);
            printf("%c         | |         %c",186,186);
            gotoxy(30,21);
            printf("%c         | |         %c",186,186);
            gotoxy(30,22);
            printf("%c         | |         %c",186,186);
            gotoxy(30,23);
            printf("%c         '-'         %c",186,186);
            gotoxy(30,24);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
            textcolor(WHITE);

            gotoxy(65,16);
            printf("%c%c%c%c%c%c%c*MEDICOS*%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,187);
            gotoxy(65,17);
            printf("%c        (            %c",186,186);
            gotoxy(65,18);
            printf("%c         \\           %c",186,186);
            gotoxy(65,19);
            printf("%c          )          %c",186,186);
            gotoxy(65,20);
            printf("%c     ##-------->     %c",186,186);
            gotoxy(65,21);
            printf("%c          )          %c",186,186);
            gotoxy(65,22);
            printf("%c         /           %c",186,186);
            gotoxy(65,23);
            printf("%c        (            %c",186,186);
            gotoxy(65,24);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);


        }

        opcion=getch();


        if (opcion==75)
        {
            menu-=1;
            if (menu<1)
            {
                menu=3;
            }
        }
        //abajo
        if (opcion==77)
        {
            menu+=1;
            if (menu>3)
            {
                menu=1;
            }
        }
        if (opcion==102||opcion==70||opcion==13)
        {
            return menu;
            opcion=0;
        }

    }
    while(opcion!=0);
}


void bye()
{
    int i;
    for(i=0; i<4; i++)
    {
        printf("\n\n\n\n");
        gotoxy(11,11);
        textcolor(i);
        printf("\t\t      _              __    _                     _   _  \n");
        Sleep(120);
        gotoxy(11,12);
        textcolor(i+1);
        printf("\t\t     / \\            |  ]  (_)                   | | | | \n");
        Sleep(120);
        gotoxy(11,13);
        textcolor(i+2);
        printf("\t\t    / _ \\       .--.| |   __     .--.    .--.   | | | | \n");
        Sleep(120);
        gotoxy(11,14);
        textcolor(i+3);
        printf("\t\t   / ___ \\    / /'`\\' |  [  |  / .'`\\ \\ ( (`\\]  | | | | \n");
        Sleep(120);
        gotoxy(11,15);
        textcolor(i+4);
        printf("\t\t _/ /   \\ \\_  | \\__/  |   | |  | \\__. |  `'.'.  |_| |_| \n");
        Sleep(120);
        gotoxy(11,16);
        textcolor(i+5);
        printf("\t\t|____| |____|  '.__.; __] [__]  '.__.'  [\\__) ) (_) (_) \n\n\n\n\n");
        Sleep(120);
    }
}


