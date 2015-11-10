#include <stdio.h> //biblioteca que controla os comandos de entrada e saída
#include <stdlib.h> //biblioteca que define funções básicas de propósito geral
#include <conio2.h> //biblioteca usada para edição da janela de console, como posição e cor
#include <string.h> //biblioteca usada para a manipulação de dados 'string'
#include <ctype.h>
#include "design.h"
#include "biblioteca.h"

/* Todas as linhas com textcolor() ou gotoxy(x,y) fazem parte da biblioteca conio, sendo
   usadas respectivamente para alterar cor do texto e posicionar a próxima linha em X,Y  */

int IDcont=0;

// INICIO DO PROGRAMA
int main() {
    system("cmd /c \"mode con: cols=120 lines=47\"");
    load_dados();

    int setas=0, controle=1;
    cabecalho();
    mostralivro();
    rodape();

    textcolor(LIGHTGREEN);
    cputsxy(83,20, "--> CONSULENTE");
    textcolor(WHITE);
    cputsxy(87,25, "BIBLIOTECARIO");
    gotoxy(120,47);

    do {
        setas=get_key();

        if (setas==ACIMA) {
            controle--;
            if (controle<1) {
                controle=2;
                cputsxy(83,20, "    CONSULENTE");
                textcolor(LIGHTGREEN);
                cputsxy(83,25, "--> BIBLIOTECARIO");
                textcolor(WHITE);
                gotoxy(120,47);
            }
            else {
                textcolor(LIGHTGREEN);
                cputsxy(83,20, "--> CONSULENTE");
                textcolor(WHITE);
                cputsxy(83,25, "    BIBLIOTECARIO");
                gotoxy(120,47);
            }
        }
        if (setas==ABAIXO) {
            controle++;
            if (controle>2) {
                controle=1;
                textcolor(LIGHTGREEN);
                cputsxy(83,20, "--> CONSULENTE");
                textcolor(WHITE);
                cputsxy(83,25, "    BIBLIOTECARIO");
                gotoxy(120,47);
            }
            else {
                textcolor(LIGHTGREEN);
                cputsxy(83,25, "--> BIBLIOTECARIO");
                textcolor(WHITE);
                cputsxy(83,20, "    CONSULENTE");
                gotoxy(120,47);
            }
        }

    } while (setas!=ESC && setas!=ENTER);

    if (controle==1) {
        consul_main();
    }

    else if (controle==2) {
        char password[19];
        char senha[] = "102030";
        int contador=0;

        do {
            cabecalho();
            mostralivro();
            rodape();
            gotoxy(85,20);
            puts("Informe a senha:");
            gotoxy(87,22);
            getpass("", password);
            if (strcmp(senha, &password[2]) == 0) {
                textcolor(LIGHTGREEN);
                cputsxy(80,25, "Login efetuado com sucesso!");
                textcolor(WHITE);
                cputsxy(81,27, "Pressione qualquer tecla");
                cputsxy(85,28, "para continuar.");
                gotoxy(120,47);
                getch();
                menu();
                break;
            }
            else {
                int setas2=0;

                contador++;
                textcolor(LIGHTRED);
                cputsxy(87,25, "Senha errada!");
                textcolor(WHITE);
                gotoxy(80,26);
                printf("Voce tem mais %d tentativas.", 4-contador);
                cputsxy(79,28, "Pressione qualquer tecla para");
                cputsxy(76,29, "tentar novamente ou ESC para sair");

                setas2=get_key();

                if(setas2==ESC)
                    return 0;
            }

        } while (contador<=3);
    }

    printf("\n\nSenha errada 3x.");

    //menu();

    return 0;
}
// FIM DO PROGRAMA
