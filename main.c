#include <stdio.h> //biblioteca que controla os comandos de entrada e saída
#include <stdlib.h> //biblioteca que define funções básicas de propósito geral
#include <conio2.h> //biblioteca usada para edição da janela de console, como posição e cor
#include <string.h> //biblioteca usada para a manipulação de dados 'string'

/* Todas as linhas com textcolor() ou gotoxy(x,y) fazem parte da biblioteca conio, sendo
   usadas respectivamente para alterar cor do texto e posicionar a próxima linha em X,Y  */

/* definindo que a VAR corresponde ao código X da tecla no teclado.
#define VAR X  */

#define ACIMA 72
#define ABAIXO 80
#define ESQUERDA 75
#define DIREITA 77
#define ESC 27
#define ENTER 13
#define BACKSPACE 8
#define TAB 9

struct Livros {
    char titulo[100];
    char autor[100];
    char genero[100];
    char editora[100];
    char status[25];
    char ISBN[10];
    int edicao;
    int id;
    int paginas;
    float aval;
} livro[100];

/*
struct Usuarios {
    int id_cliente;
    int documento;
    char nome[100];
    int telefone;
} Usuario;
*/


void cabecalho()
{
    gotoxy(1,1);
    printf("\n ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
    printf(" ³                                                                                                                    ³\n");
    printf(" ³                                             BIBLIOTECA A.S.T.R.A.                                                  ³\n");
    printf(" ³                                                                                                                    ³\n");
    printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
}

void rodape()
{
    gotoxy(1,38);
    printf("\n ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
    printf(" ³                                                                                                                    ³\n");
    printf(" ³                                   UNIP - PROJETO INTEGRADO MULTIDISCIPLINAR                                        ³\n");
    printf(" ³                                                                                                                    ³\n");
    printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
}

void lista() {

    char tecla;
    int i = 1;

    struct Livros livro[10];

    strcpy(livro[1].titulo, "Treinamento Funcional");
    strcpy(livro[1].autor, "Diego Martins");
    strcpy(livro[1].genero, "Educacao Fisica");
    strcpy(livro[1].editora, "Finnet Brasil");
    strcpy(livro[1].ISBN, "8586702854");
    strcpy(livro[1].status, "Disponivel");
    livro[1].edicao = 3;
    livro[1].paginas = 666;
    livro[1].aval = 10;
    livro[1].id = 1;

    strcpy(livro[2].titulo, "Programacao em C");
    strcpy(livro[2].autor, "Valber Juvenal");
    strcpy(livro[2].genero, "Programacao");
    strcpy(livro[2].editora, "Finnet Brasil");
    strcpy(livro[2].ISBN, "2541632547");
    strcpy(livro[2].status, "Nao disponivel");
    livro[2].edicao = 2;
    livro[2].paginas = 333;
    livro[2].aval = 10;
    livro[2].id = 2;

    strcpy(livro[3].titulo, "Como Manipular as Pessoas");
    strcpy(livro[3].autor, "Bruno Melo");
    strcpy(livro[3].genero, "Auto Ajuda");
    strcpy(livro[3].editora, "Finnet Brasil");
    strcpy(livro[3].ISBN, "1563895247");
    strcpy(livro[3].status, "Disponivel");
    livro[3].edicao = 7;
    livro[3].paginas = 69;
    livro[3].aval = 8;
    livro[3].id = 3;

    /*
    printf("\nTitulo do Livro: %s\n", livro.titulo);
    printf("Nome do Autor : %s\n", livro.autor);
    printf("Genero do Livro : %s\n", livro.genero);
    printf("ID do Livro : %d\n", livro.livro_id);
    */

    //SEGUNDA PARTE
    while (tecla != ESC) {
        system("cls");
        cabecalho();
        rodape();
        gotoxy(1,8);
        printf("                                            ~~~~~:D8                                                              \n");
        printf("                                      ~~~~~~~~~~~~::D                 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
        printf("                                   ::~~~~~~~~~~~~~~::D                ³                                          ³\n");
        printf("                                 ::::::::~~~~~~~~~~~::D               ³                                          ³\n");
        printf("                                :::::::::::~~~~~~~~~:::D              ³                                          ³\n");
        printf("                              ~::::::::::::::~~~~~~~~:::D             ³                                          ³\n");
        printf("                     ,::::::~~~:::,,,,,,:::::::~~~~~:::::D            ³                                          ³\n");
        printf("                  ,,,,:::::::~+~:,,....,,,::::::~~::::::::D           ³                                          ³\n");
        printf("               ,,,,,,,,,::::::~~:,,......,,,::::::~~:::::::D          ³                                          ³\n");
        printf("             ,,,,,,,,,,,,,:::::=~,,.......,,,::::::~~:::::,,D         ³                                          ³\n");
        printf("           ,,,,,,,,,,,,,,,,::::~=:,,.......,,,::::::~~~::::,,D        ³                                          ³\n");
        printf("        =,,,,,,,,,,,,,,,,,,,::::~=:,,.......,,,:::::::~~::::,.D       ³                                          ³\n");
        printf("        ?=,,,,,,,,,,,,,,,,,,:::::~=,,,........,,:::::::~~:::::,D      ³                                          ³\n");
        printf("       8O~=,,,,,,,,,,,,,,,,,::::::~=,,,........,,::::::::~~::::ID     ³                                          ³\n");
        printf("       8OO~,,,,,,,,,,,,,,,,,:::::::~=,,,........,,,::::::::::,7O$N    ³                                          ³\n");
        printf("        8O?=,,,,,...,,,,,,,,::::::::~:,,,.........,,,.?77Z$O7NDO      ³                                          ³\n");
        printf("         DO++,,,,......,,,,,,::::::,:~:,,,....  ?IZ$$$$$$NDD          ³                                          ³\n");
        printf("         DOO~~,,,,......,,,,,,::::::,:~:,,,..?O$$$O$$$DO              ³                                          ³\n");
        printf("          8OO~,,,,.......,,,,,,::::::,:~:,,.8$$$$$ZDD                 ³                                          ³\n");
        printf("           DO7=,,,........,,,,,,::::::,:~:,$Z$$$N8                    ³                                          ³\n");
        printf("           DDO==,,,........,,,,,,::????I:~$$$$D                       ³                                          ³\n");
        printf("            8OO=,,,.........,..???$$$ZZ$$NNMN                         ³                                          ³\n");
        printf("             DO7=,,,.........??$$$$$$$$$$MD8                          ³                                          ³\n");
        printf("             DDO?+,,.......I$ZO$$8$$NN   N                            ³                                          ³\n");
        printf("              DOO+,,.....7Z$$$$$DO                                    ³                                          ³\n");
        printf("               DOO+,....$$$$$NO                                       ³                                          ³\n");
        printf("               NDO7+..$$$$ND                                          ³                                          ³\n");
        printf("                DOO=$$$NDM                                            ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        printf("                 DO$$NO                                                                                           \n");
        printf("                 NNDN                                                                                             \n");
        textcolor(LIGHTCYAN);
        gotoxy(74,12);
        printf("Titulo:");
        textcolor(LIGHTCYAN);
        gotoxy(74,15);
        printf("Autor:");
        textcolor(LIGHTCYAN);
        gotoxy(74,18);
        printf("Genero:");
        textcolor(LIGHTCYAN);
        gotoxy(74,21);
        printf("Editora:");
        textcolor(LIGHTCYAN);
        gotoxy(74,24);
        printf("Edicao:");
        textcolor(LIGHTCYAN);
        gotoxy(74,27);
        printf("ISBN:");
        textcolor(LIGHTCYAN);
        gotoxy(74,30);
        printf("Paginas:");
        textcolor(LIGHTCYAN);
        gotoxy(74,33);
        printf("Status:");
        textcolor(WHITE);
        gotoxy(82,12);
        printf("%s", livro[i].titulo);
        textcolor(WHITE);
        gotoxy(81,15);
        printf("%s", livro[i].autor);
        textcolor(WHITE);
        gotoxy(82,18);
        printf("%s", livro[i].genero);
        textcolor(WHITE);
        gotoxy(83,21);
        printf("%s", livro[i].editora);
        textcolor(WHITE);
        gotoxy(82,24);
        printf("%d", livro[i].edicao);
        textcolor(WHITE);
        gotoxy(80,27);
        printf("%s", livro[i].ISBN);
        textcolor(WHITE);
        gotoxy(83,30);
        printf("%d", livro[i].paginas);
        if (strcmp(livro[i].status, "Disponivel") == 0) {
            textcolor(LIGHTGREEN);
        }
        else {
            textcolor(LIGHTRED);
        }
        gotoxy(82,33);
        printf("%s", livro[i].status);
        textcolor(WHITE);
        gotoxy(120,44);
        tecla = getch();
        if (tecla == DIREITA) {
            i++;
        }
        else if (tecla == ESQUERDA) {
            if (i > 1) {
                i--;
            }
        }
        else if (tecla == ESC) {
            system("cls");
            menu();
        }
    }


}

void cadastrar() {

    system("cls");
    cabecalho();
    rodape();

    char contador;  //contador
    char setas;  //variável usada para captura de tecla

    while (setas != ESC) {
        gotoxy(1,8);
        printf("            ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
        printf("            ³                                   CADASTRO DE NOVO LIVRO                                   ³\n");
        printf("            ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        printf("\n            ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³   Titulo:                                                                                  ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³   Autor:                                                                                   ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³   Genero:                                                                                  ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³   Editora:                                                                                 ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³   Edicao:                                                                                  ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³   Paginas:                                                                                 ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³   ISBN:                                                                                    ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ³                                                                                            ³\n");
        printf("            ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

        gotoxy(25,15);
        scanf("%s", &setas);

        contador=getch();

        if (contador==ENTER) {
            gotoxy(24,18);
            scanf("%s", &contador);

            contador=getch();

            if (contador==ENTER) {
                gotoxy(25,21);
                scanf("%s", &contador);
            }
        }
    }

    if (setas == ESC) {
        system("cls");
        menu();
    }
}

void sair()
{
    system("cls");
    cabecalho();
    rodape();

    int contador=1;  //contador
    char setas;  //variável usada para captura de tecla

    while (setas != ESC) {
        //se usuário estiver na primeira opção do menu e apertar seta para cima
        //cursor vai para a opção de baixo
        if (contador<1)
            contador=2;
        //se usuário estiver na opção de baixo e apertar seta para baixo
        //cursor vai para a primeira opção
        else if (contador>2)
            contador=1;

        switch (contador) {
            case(1):
                gotoxy(1,8);
                printf("                                            ~~~~~:D8                                                    \n");
                printf("                                      ~~~~~~~~~~~~::D                 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("                                   ::~~~~~~~~~~~~~~::D                ³                                ³\n");
                printf("                                 ::::::::~~~~~~~~~~~::D               ³                                ³\n");
                printf("                                :::::::::::~~~~~~~~~:::D              ³                                ³\n");
                printf("                              ~::::::::::::::~~~~~~~~:::D             ³                                ³\n");
                printf("                     ,::::::~~~:::,,,,,,:::::::~~~~~:::::D            ³                                ³\n");
                printf("                  ,,,,:::::::~+~:,,....,,,::::::~~::::::::D           ³                                ³\n");
                printf("               ,,,,,,,,,::::::~~:,,......,,,::::::~~:::::::D          ³                                ³\n");
                printf("             ,,,,,,,,,,,,,:::::=~,,.......,,,::::::~~:::::,,D         ³                                ³\n");
                printf("           ,,,,,,,,,,,,,,,,::::~=:,,.......,,,::::::~~~::::,,D        ³                                ³\n");
                printf("        =,,,,,,,,,,,,,,,,,,,::::~=:,,.......,,,:::::::~~::::,.D       ³                                ³\n");
                printf("        ?=,,,,,,,,,,,,,,,,,,:::::~=,,,........,,:::::::~~:::::,D      ³                                ³\n");
                printf("       8O~=,,,,,,,,,,,,,,,,,::::::~=,,,........,,::::::::~~::::ID     ³                                ³\n");
                printf("       8OO~,,,,,,,,,,,,,,,,,:::::::~=,,,........,,,::::::::::,7O$N    ³                                ³\n");
                printf("        8O?=,,,,,...,,,,,,,,::::::::~:,,,.........,,,.?77Z$O7NDO      ³                                ³\n");
                printf("         DO++,,,,......,,,,,,::::::,:~:,,,....  ?IZ$$$$$$NDD          ³                                ³\n");
                printf("         DOO~~,,,,......,,,,,,::::::,:~:,,,..?O$$$O$$$DO              ³                                ³\n");
                printf("          8OO~,,,,.......,,,,,,::::::,:~:,,.8$$$$$ZDD                 ³                                ³\n");
                printf("           DO7=,,,........,,,,,,::::::,:~:,$Z$$$N8                    ³                                ³\n");
                printf("           DDO==,,,........,,,,,,::????I:~$$$$D                       ³                                ³\n");
                printf("            8OO=,,,.........,..???$$$ZZ$$NNMN                         ³                                ³\n");
                printf("             DO7=,,,.........??$$$$$$$$$$MD8                          ³                                ³\n");
                printf("             DDO?+,,.......I$ZO$$8$$NN   N                            ³                                ³\n");
                printf("              DOO+,,.....7Z$$$$$DO                                    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                printf("               DOO+,....$$$$$NO                                                                         \n");
                printf("               NDO7+..$$$$ND                                                                            \n");
                printf("                DOO=$$$NDM                                                                              \n");
                printf("                 DO$$NO                                                                                 \n");
                printf("                 NNDN                                                                                   \n");
                gotoxy(76,14);
                printf("Deseja sair do sistema?");
                textcolor(LIGHTGREEN);
                gotoxy(83,20);
                printf("-> Sim");
                textcolor(WHITE);
                gotoxy(86,23);
                printf("Nao");
                gotoxy(120,43);
                setas=getch();
                //caso cursor estiver na posição (1) e tecla pressionada for ENTER, sai do sistema.
                if (setas==ENTER){
                    exit(0);
                }
                // else/if para movimentação do cursor
                else if (setas==ACIMA)
                    contador=2;
                else if (setas==ABAIXO)
                    contador++;
                break;
            case(2):
                gotoxy(1,8);
                printf("                                            ~~~~~:D8                                                    \n");
                printf("                                      ~~~~~~~~~~~~::D                 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("                                   ::~~~~~~~~~~~~~~::D                ³                                ³\n");
                printf("                                 ::::::::~~~~~~~~~~~::D               ³                                ³\n");
                printf("                                :::::::::::~~~~~~~~~:::D              ³                                ³\n");
                printf("                              ~::::::::::::::~~~~~~~~:::D             ³                                ³\n");
                printf("                     ,::::::~~~:::,,,,,,:::::::~~~~~:::::D            ³                                ³\n");
                printf("                  ,,,,:::::::~+~:,,....,,,::::::~~::::::::D           ³                                ³\n");
                printf("               ,,,,,,,,,::::::~~:,,......,,,::::::~~:::::::D          ³                                ³\n");
                printf("             ,,,,,,,,,,,,,:::::=~,,.......,,,::::::~~:::::,,D         ³                                ³\n");
                printf("           ,,,,,,,,,,,,,,,,::::~=:,,.......,,,::::::~~~::::,,D        ³                                ³\n");
                printf("        =,,,,,,,,,,,,,,,,,,,::::~=:,,.......,,,:::::::~~::::,.D       ³                                ³\n");
                printf("        ?=,,,,,,,,,,,,,,,,,,:::::~=,,,........,,:::::::~~:::::,D      ³                                ³\n");
                printf("       8O~=,,,,,,,,,,,,,,,,,::::::~=,,,........,,::::::::~~::::ID     ³                                ³\n");
                printf("       8OO~,,,,,,,,,,,,,,,,,:::::::~=,,,........,,,::::::::::,7O$N    ³                                ³\n");
                printf("        8O?=,,,,,...,,,,,,,,::::::::~:,,,.........,,,.?77Z$O7NDO      ³                                ³\n");
                printf("         DO++,,,,......,,,,,,::::::,:~:,,,....  ?IZ$$$$$$NDD          ³                                ³\n");
                printf("         DOO~~,,,,......,,,,,,::::::,:~:,,,..?O$$$O$$$DO              ³                                ³\n");
                printf("          8OO~,,,,.......,,,,,,::::::,:~:,,.8$$$$$ZDD                 ³                                ³\n");
                printf("           DO7=,,,........,,,,,,::::::,:~:,$Z$$$N8                    ³                                ³\n");
                printf("           DDO==,,,........,,,,,,::????I:~$$$$D                       ³                                ³\n");
                printf("            8OO=,,,.........,..???$$$ZZ$$NNMN                         ³                                ³\n");
                printf("             DO7=,,,.........??$$$$$$$$$$MD8                          ³                                ³\n");
                printf("             DDO?+,,.......I$ZO$$8$$NN   N                            ³                                ³\n");
                printf("              DOO+,,.....7Z$$$$$DO                                    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                printf("               DOO+,....$$$$$NO                                                                         \n");
                printf("               NDO7+..$$$$ND                                                                            \n");
                printf("                DOO=$$$NDM                                                                              \n");
                printf("                 DO$$NO                                                                                 \n");
                printf("                 NNDN                                                                                   \n");
                gotoxy(76,14);
                printf("Deseja sair do sistema?");
                gotoxy(86,20);
                printf("Sim");
                textcolor(LIGHTGREEN);
                gotoxy(83,23);
                printf("-> Nao");
                textcolor(WHITE);
                gotoxy(120,43);
                setas=getch();
                //caso cursor estiver na posição 2 (Nao) e tecla pressionada for ENTER, entrar na função 'menu()' novamente
                if (setas==ENTER) {
                    system("cls");
                    return;
                }
                // else/if para movimentação do cursor
                else if (setas==ACIMA)
                    contador--;
                else if (setas==ABAIXO)
                    contador=1;
                break;
        }
    }
    if (setas == ESC)
        menu();
}


void menu()
{
    int contador=1;  //contador
    char setas;  //variável usada para captura de tecla

    while(setas != ESC){

        cabecalho();
        rodape();

        //se usuário estiver na primeira opção do menu e apertar seta para cima
        //cursor vai para a última opção (4)
        if (contador<1)
            contador=4;
        //se usuário estiver na última opção do menu e apertar seta para baixo
        //cursor vai para a primeira opção (1)
        else if (contador>4)
            contador=1;

        switch (contador)
        {
            case(1):
                gotoxy(1,8);
                printf("                                            ~~~~~:D8                                                    \n");
                printf("                                      ~~~~~~~~~~~~::D                 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("                                   ::~~~~~~~~~~~~~~::D                ³                                ³\n");
                printf("                                 ::::::::~~~~~~~~~~~::D               ³                                ³\n");
                printf("                                :::::::::::~~~~~~~~~:::D              ³                                ³\n");
                printf("                              ~::::::::::::::~~~~~~~~:::D             ³                                ³\n");
                printf("                     ,::::::~~~:::,,,,,,:::::::~~~~~:::::D            ³                                ³\n");
                printf("                  ,,,,:::::::~+~:,,....,,,::::::~~::::::::D           ³     Autores                    ³\n");
                printf("               ,,,,,,,,,::::::~~:,,......,,,::::::~~:::::::D          ³                                ³\n");
                printf("             ,,,,,,,,,,,,,:::::=~,,.......,,,::::::~~:::::,,D         ³                                ³\n");
                printf("           ,,,,,,,,,,,,,,,,::::~=:,,.......,,,::::::~~~::::,,D        ³     Cadastrar                  ³\n");
                printf("        =,,,,,,,,,,,,,,,,,,,::::~=:,,.......,,,:::::::~~::::,.D       ³                                ³\n");
                printf("        ?=,,,,,,,,,,,,,,,,,,:::::~=,,,........,,:::::::~~:::::,D      ³                                ³\n");
                printf("       8O~=,,,,,,,,,,,,,,,,,::::::~=,,,........,,::::::::~~::::ID     ³     Sair                       ³\n");
                printf("       8OO~,,,,,,,,,,,,,,,,,:::::::~=,,,........,,,::::::::::,7O$N    ³                                ³\n");
                printf("        8O?=,,,,,...,,,,,,,,::::::::~:,,,.........,,,.?77Z$O7NDO      ³                                ³\n");
                printf("         DO++,,,,......,,,,,,::::::,:~:,,,....  ?IZ$$$$$$NDD          ³                                ³\n");
                printf("         DOO~~,,,,......,,,,,,::::::,:~:,,,..?O$$$O$$$DO              ³                                ³\n");
                printf("          8OO~,,,,.......,,,,,,::::::,:~:,,.8$$$$$ZDD                 ³                                ³\n");
                printf("           DO7=,,,........,,,,,,::::::,:~:,$Z$$$N8                    ³     Creditos                   ³\n");
                printf("           DDO==,,,........,,,,,,::????I:~$$$$D                       ³                                ³\n");
                printf("            8OO=,,,.........,..???$$$ZZ$$NNMN                         ³                                ³\n");
                printf("             DO7=,,,.........??$$$$$$$$$$MD8                          ³                                ³\n");
                printf("             DDO?+,,.......I$ZO$$8$$NN   N                            ³                                ³\n");
                printf("              DOO+,,.....7Z$$$$$DO                                    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                printf("               DOO+,....$$$$$NO                                                                         \n");
                printf("               NDO7+..$$$$ND                                                                            \n");
                printf("                DOO=$$$NDM                                                                              \n");
                printf("                 DO$$NO                                                                                 \n");
                printf("                 NNDN                                                                                   \n");
                textcolor(LIGHTGREEN);
                gotoxy(77,12);
                printf("Livros           <--");
                textcolor(WHITE);
                gotoxy(120,43);
                setas=getch();
                if (setas==ENTER) {
                    lista();
                }
                // else/if para movimentação do cursor
                else if (setas==ACIMA)
                    contador=4;
                else if (setas==ABAIXO)
                    contador++;
                break;
            case(2):
                gotoxy(1,8);
                printf("                                            ~~~~~:D8                                                    \n");
                printf("                                      ~~~~~~~~~~~~::D                 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("                                   ::~~~~~~~~~~~~~~::D                ³                                ³\n");
                printf("                                 ::::::::~~~~~~~~~~~::D               ³                                ³\n");
                printf("                                :::::::::::~~~~~~~~~:::D              ³     Livros                     ³\n");
                printf("                              ~::::::::::::::~~~~~~~~:::D             ³                                ³\n");
                printf("                     ,::::::~~~:::,,,,,,:::::::~~~~~:::::D            ³                                ³\n");
                printf("                  ,,,,:::::::~+~:,,....,,,::::::~~::::::::D           ³                                ³\n");
                printf("               ,,,,,,,,,::::::~~:,,......,,,::::::~~:::::::D          ³                                ³\n");
                printf("             ,,,,,,,,,,,,,:::::=~,,.......,,,::::::~~:::::,,D         ³                                ³\n");
                printf("           ,,,,,,,,,,,,,,,,::::~=:,,.......,,,::::::~~~::::,,D        ³     Cadastrar                  ³\n");
                printf("        =,,,,,,,,,,,,,,,,,,,::::~=:,,.......,,,:::::::~~::::,.D       ³                                ³\n");
                printf("        ?=,,,,,,,,,,,,,,,,,,:::::~=,,,........,,:::::::~~:::::,D      ³                                ³\n");
                printf("       8O~=,,,,,,,,,,,,,,,,,::::::~=,,,........,,::::::::~~::::ID     ³     Sair                       ³\n");
                printf("       8OO~,,,,,,,,,,,,,,,,,:::::::~=,,,........,,,::::::::::,7O$N    ³                                ³\n");
                printf("        8O?=,,,,,...,,,,,,,,::::::::~:,,,.........,,,.?77Z$O7NDO      ³                                ³\n");
                printf("         DO++,,,,......,,,,,,::::::,:~:,,,....  ?IZ$$$$$$NDD          ³                                ³\n");
                printf("         DOO~~,,,,......,,,,,,::::::,:~:,,,..?O$$$O$$$DO              ³                                ³\n");
                printf("          8OO~,,,,.......,,,,,,::::::,:~:,,.8$$$$$ZDD                 ³                                ³\n");
                printf("           DO7=,,,........,,,,,,::::::,:~:,$Z$$$N8                    ³     Creditos                   ³\n");
                printf("           DDO==,,,........,,,,,,::????I:~$$$$D                       ³                                ³\n");
                printf("            8OO=,,,.........,..???$$$ZZ$$NNMN                         ³                                ³\n");
                printf("             DO7=,,,.........??$$$$$$$$$$MD8                          ³                                ³\n");
                printf("             DDO?+,,.......I$ZO$$8$$NN   N                            ³                                ³\n");
                printf("              DOO+,,.....7Z$$$$$DO                                    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                printf("               DOO+,....$$$$$NO                                       \n");
                printf("               NDO7+..$$$$ND                                          \n");
                printf("                DOO=$$$NDM                                            \n");
                printf("                 DO$$NO                                               \n");
                printf("                 NNDN                                                 \n");
                textcolor(LIGHTGREEN);
                gotoxy(77,15);
                printf("Autores          <--");
                textcolor(WHITE);
                gotoxy(120,43);
            setas=getch();
            //caso cursor estiver na posição (2) e tecla pressionada for ENTER, entrar na função 'regras()'
            if (setas==ENTER){
                system("cls");
                //regras();
                gotoxy(120,43);
                getch();
            }
            // else/if para movimentação do cursor
            else if (setas==ACIMA)
                contador--;
            else if (setas==ABAIXO)
                contador++;
            break;
        case(3):
                gotoxy(1,8);
                printf("                                            ~~~~~:D8                                                    \n");
                printf("                                      ~~~~~~~~~~~~::D                 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("                                   ::~~~~~~~~~~~~~~::D                ³                                ³\n");
                printf("                                 ::::::::~~~~~~~~~~~::D               ³                                ³\n");
                printf("                                :::::::::::~~~~~~~~~:::D              ³     Livros                     ³\n");
                printf("                              ~::::::::::::::~~~~~~~~:::D             ³                                ³\n");
                printf("                     ,::::::~~~:::,,,,,,:::::::~~~~~:::::D            ³                                ³\n");
                printf("                  ,,,,:::::::~+~:,,....,,,::::::~~::::::::D           ³     Autores                    ³\n");
                printf("               ,,,,,,,,,::::::~~:,,......,,,::::::~~:::::::D          ³                                ³\n");
                printf("             ,,,,,,,,,,,,,:::::=~,,.......,,,::::::~~:::::,,D         ³                                ³\n");
                printf("           ,,,,,,,,,,,,,,,,::::~=:,,.......,,,::::::~~~::::,,D        ³                                ³\n");
                printf("        =,,,,,,,,,,,,,,,,,,,::::~=:,,.......,,,:::::::~~::::,.D       ³                                ³\n");
                printf("        ?=,,,,,,,,,,,,,,,,,,:::::~=,,,........,,:::::::~~:::::,D      ³                                ³\n");
                printf("       8O~=,,,,,,,,,,,,,,,,,::::::~=,,,........,,::::::::~~::::ID     ³     Sair                       ³\n");
                printf("       8OO~,,,,,,,,,,,,,,,,,:::::::~=,,,........,,,::::::::::,7O$N    ³                                ³\n");
                printf("        8O?=,,,,,...,,,,,,,,::::::::~:,,,.........,,,.?77Z$O7NDO      ³                                ³\n");
                printf("         DO++,,,,......,,,,,,::::::,:~:,,,....  ?IZ$$$$$$NDD          ³                                ³\n");
                printf("         DOO~~,,,,......,,,,,,::::::,:~:,,,..?O$$$O$$$DO              ³                                ³\n");
                printf("          8OO~,,,,.......,,,,,,::::::,:~:,,.8$$$$$ZDD                 ³                                ³\n");
                printf("           DO7=,,,........,,,,,,::::::,:~:,$Z$$$N8                    ³     Creditos                   ³\n");
                printf("           DDO==,,,........,,,,,,::????I:~$$$$D                       ³                                ³\n");
                printf("            8OO=,,,.........,..???$$$ZZ$$NNMN                         ³                                ³\n");
                printf("             DO7=,,,.........??$$$$$$$$$$MD8                          ³                                ³\n");
                printf("             DDO?+,,.......I$ZO$$8$$NN   N                            ³                                ³\n");
                printf("              DOO+,,.....7Z$$$$$DO                                    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                printf("               DOO+,....$$$$$NO                                       \n");
                printf("               NDO7+..$$$$ND                                          \n");
                printf("                DOO=$$$NDM                                            \n");
                printf("                 DO$$NO                                               \n");
                printf("                 NNDN                                                 \n");
                textcolor(LIGHTGREEN);
                gotoxy(77,18);
                printf("Cadastrar        <--");
                textcolor(WHITE);
                gotoxy(120,43);
                setas=getch();
            //caso cursor estiver na posição (3) e tecla pressionada for ENTER, entrar na função 'creditos()'
            if (setas==ENTER){
                system("cls");
                cadastrar();
                gotoxy(120,43);
                getch();
            }
            // else/if para movimentação do cursor
            else if (setas==ACIMA)
                contador--;
            else if (setas==ABAIXO)
                contador++;
            break;
        case(4):
                gotoxy(1,8);
                printf("                                            ~~~~~:D8                                                    \n");
                printf("                                      ~~~~~~~~~~~~::D                 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                printf("                                   ::~~~~~~~~~~~~~~::D                ³                                ³\n");
                printf("                                 ::::::::~~~~~~~~~~~::D               ³                                ³\n");
                printf("                                :::::::::::~~~~~~~~~:::D              ³     Livros                     ³\n");
                printf("                              ~::::::::::::::~~~~~~~~:::D             ³                                ³\n");
                printf("                     ,::::::~~~:::,,,,,,:::::::~~~~~:::::D            ³                                ³\n");
                printf("                  ,,,,:::::::~+~:,,....,,,::::::~~::::::::D           ³     Autores                    ³\n");
                printf("               ,,,,,,,,,::::::~~:,,......,,,::::::~~:::::::D          ³                                ³\n");
                printf("             ,,,,,,,,,,,,,:::::=~,,.......,,,::::::~~:::::,,D         ³                                ³\n");
                printf("           ,,,,,,,,,,,,,,,,::::~=:,,.......,,,::::::~~~::::,,D        ³     Cadastrar                  ³\n");
                printf("        =,,,,,,,,,,,,,,,,,,,::::~=:,,.......,,,:::::::~~::::,.D       ³                                ³\n");
                printf("        ?=,,,,,,,,,,,,,,,,,,:::::~=,,,........,,:::::::~~:::::,D      ³                                ³\n");
                printf("       8O~=,,,,,,,,,,,,,,,,,::::::~=,,,........,,::::::::~~::::ID     ³                                ³\n");
                printf("       8OO~,,,,,,,,,,,,,,,,,:::::::~=,,,........,,,::::::::::,7O$N    ³                                ³\n");
                printf("        8O?=,,,,,...,,,,,,,,::::::::~:,,,.........,,,.?77Z$O7NDO      ³                                ³\n");
                printf("         DO++,,,,......,,,,,,::::::,:~:,,,....  ?IZ$$$$$$NDD          ³                                ³\n");
                printf("         DOO~~,,,,......,,,,,,::::::,:~:,,,..?O$$$O$$$DO              ³                                ³\n");
                printf("          8OO~,,,,.......,,,,,,::::::,:~:,,.8$$$$$ZDD                 ³                                ³\n");
                printf("           DO7=,,,........,,,,,,::::::,:~:,$Z$$$N8                    ³     Creditos                   ³\n");
                printf("           DDO==,,,........,,,,,,::????I:~$$$$D                       ³                                ³\n");
                printf("            8OO=,,,.........,..???$$$ZZ$$NNMN                         ³                                ³\n");
                printf("             DO7=,,,.........??$$$$$$$$$$MD8                          ³                                ³\n");
                printf("             DDO?+,,.......I$ZO$$8$$NN   N                            ³                                ³\n");
                printf("              DOO+,,.....7Z$$$$$DO                                    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                printf("               DOO+,....$$$$$NO                                       \n");
                printf("               NDO7+..$$$$ND                                          \n");
                printf("                DOO=$$$NDM                                            \n");
                printf("                 DO$$NO                                               \n");
                printf("                 NNDN                                                 \n");
                textcolor(LIGHTGREEN);
                gotoxy(77,21);
                printf("Sair             <--");
                textcolor(WHITE);
                gotoxy(120,43);
                setas=getch();
            //caso cursor estiver na posição (4) e tecla pressionada for ENTER, entrar na função 'sair()'
            if (setas==ENTER){
                sair();
            }
            // else/if para movimentação do cursor
            else if (setas==ACIMA)
                contador--;
            else if (setas==ABAIXO)
                contador=1;
            break;
        }

        //se tecla ESC for pressionada, chamar função 'sair()', finalizando o programa
        if (setas==ESC)
            sair();
    }
}
            // ** FIM DA FUNÇÃO MENU **


int main()
{
    system("cmd /c \"mode con: cols=120 lines=44\"");
    menu();
    return 0;
}
