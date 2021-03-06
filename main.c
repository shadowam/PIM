#include <stdio.h> //biblioteca que controla os comandos de entrada e saída
#include <stdlib.h> //biblioteca que define funções básicas de propósito geral
#include <conio2.h> //biblioteca usada para edição da janela de console, como posição e cor
#include <string.h> //biblioteca usada para a manipulação de dados 'string'
#include <ctype.h>
#include "design.h"
#include "biblioteca.h"
//#include "livros.h" //header que contém a lista de livros

/* Todas as linhas com textcolor() ou gotoxy(x,y) fazem parte da biblioteca conio, sendo
   usadas respectivamente para alterar cor do texto e posicionar a próxima linha em X,Y  */

/* definindo que a VAR corresponde ao código X da tecla no teclado.
#define VAR X  */

/*
struct Usuarios {
    int id_cliente;
    int documento;
    char nome[100];
    int telefone;
} Usuario;
*/

//FUNÇÃO PARA GRAVAR O VALOR DAS TECLAS F1~FX E SETAS
int get_key() {
    int c = getch();
    switch (c) {
      case 0:   return getch() + 256;
      case 224: return getch() + 512;
    }
    return c;
}

//FUNÇÃO USADA PARA VALIDAR ENTRADA DE NUMERO INTEIRO
int SomenteNumeros(int *i, int x, int y) {
    int invalido = 0;
    int FimIndex;
    char buffer[100];
    do {
        if (invalido) {
            gotoxy(40,37);
            textcolor(LIGHTRED);
            fputs("Dados invalidos! Digite apenas numeros.\n", stdout);
            textcolor(WHITE);
        }
        invalido = 1;
        cputsxy(x, y, "                                                                        ");
        //printf("%d | %d", x, y);
        gotoxy(x, y);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return 1;
        }

        cputsxy(37, 37, "                                                         ");

    } while ((sscanf(buffer, "%d %n", i, &FimIndex) != 1) || buffer[FimIndex]);

    return 0;
}

char to_maiuscula (char *pal, int x, int y) {
    int j, invalido=0;
    int FimIndex;
    char buffer[99];

    do
    {
        if(invalido)
        {
            gotoxy(37,37);
            textcolor(LIGHTRED);
            fputs("Dados invalidos! Digite ao menos um caractere.\n", stdout);
            textcolor(WHITE);
        }

        invalido = 1;
        cputsxy(x, y, "                                                                         ");

        gotoxy(x, y);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return 1;
        }
        else
        {
            for(j=0; j <= strlen(buffer); j++)
            {
                if(buffer[j] == '\n')
                {
                    buffer[j] = '\0';
                    //break;
                }
                else
                {
                    buffer[j] = toupper(buffer[j]);
                }
            }
        }

        cputsxy(37, 37, "                                                         ");

        strncpy(pal, buffer, sizeof(buffer));

    } while (strlen(buffer) < 1 || sscanf(buffer, "%s %n", buffer, &FimIndex) != 1); //verifica se o conteudo de buffer é uma string com mais de 1 caractere.

    return 0;
}

void load_dados() {
    FILE* arq;

    char buffer[1000];

    int i=1;

    if ((arq=fopen("teste.txt", "r")) == NULL)
    {
        clrscr();
        printf("\n\nO Arquivo nao pode ser aberto, por favor tente novamente.");
    }
    else
    {
        //while (!feof(arq))
        //while (fscanf(arq, "%d %s %s", &book[i].ID, &book[i].titulo, &book[i].genero) == 3)
        while((fgets(buffer, sizeof(buffer), arq)) != 0)
        {
            sscanf(buffer, "%d:%[^:\n]:%[^:]:%[^:\n]:%[^:\n]:%d:%d:%d:%[^:\n]:%[^:\n]", &book[i].ID, book[i].titulo, book[i].autor, book[i].genero, book[i].editora, &book[i].edicao, &book[i].ano, &book[i].paginas, book[i].ISBN, book[i].local);

            i++;
            if (IDcont < i)
                IDcont++;
        }

        fclose(arq);
    }

    ultimo_livro = IDcont;

    return;
}

void consulentes() {
    clrscr();
    cabecalho();
    rodape();
    //char contador;  //contador
    int setas;  //variável usada para captura de tecla

    while (setas != ESC) {
        mostradados();
        setas=get_key();
    /*
        contador=getch();

        if (contador==ENTER) {
            gotoxy(24,18);
            scanf("%s", &contador);

            contador=getch();

            if (contador==ENTER) {
                gotoxy(25,21);
                scanf("%s", &contador);
            }

    */
    }

    if (setas == ESC) {
        return;
    }
}

// INICIO DA FUNÇÃO PARA SAIR DO PROGRAMA
void sair() {
    clrscr();

    int contador=1;  //contador
    int setas;  //variável usada para captura de tecla

    while (contador==1 || contador==2) {

	    cabecalho();
	    mostralivro();
	    rodape();

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
                gotoxy(81,14);
                printf("Deseja sair do sistema?");
                textcolor(LIGHTGREEN);
                gotoxy(88,20);
                printf("-> Sim");
                textcolor(WHITE);
                gotoxy(91,23);
                printf("Nao");
                gotoxy(120,47);
                setas=get_key();
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
                gotoxy(81,14);
                printf("Deseja sair do sistema?");
                gotoxy(91,20);
                printf("Sim");
                textcolor(LIGHTGREEN);
                gotoxy(88,23);
                printf("-> Nao");
                textcolor(WHITE);
                gotoxy(120,47);
                setas=get_key();
                //caso cursor estiver na posição 2 (Nao) e tecla pressionada for ENTER, entrar na função 'menu()' novamente
                if (setas==ENTER) {
                    return;
                }
                // else/if para movimentação do cursor
                else if (setas==ACIMA)
                    contador--;
                else if (setas==ABAIXO)
                    contador=1;
                break;
            default:
                printf("Opcao invalida, tente novamente!\n");
                break;
        }
    }
}
// FIM DA FUNÇÃO SAIR DO PROGRAMA
void adicionar_livro() {
    FILE * arq;

    int setas;
    int controle=1;

    do {
        clrscr();
        cabecalho();
        mostradados();
        rodape();

        book[IDcont].ID = IDcont;

        to_maiuscula(book[IDcont].titulo, 26, 12);
        gotoxy(25,13);
        printf("%s", book[IDcont].titulo);

        to_maiuscula(book[IDcont].autor, 25, 15);
        gotoxy(24,16);
        printf("%s", book[IDcont].autor);

        to_maiuscula(book[IDcont].genero, 26, 18);
        gotoxy(25,19);
        printf("%s", book[IDcont].genero);

        to_maiuscula(book[IDcont].editora, 27, 21);
        gotoxy(26,22);
        printf("%s", book[IDcont].editora);

        fflush(stdin);
        SomenteNumeros(&book[IDcont].edicao, 26, 24);
        fflush(stdin);
        gotoxy(25,25);
        printf("%d", book[IDcont].edicao);

        SomenteNumeros(&book[IDcont].ano, 23, 27);
        fflush(stdin);
        gotoxy(22,28);
        printf("%d", book[IDcont].ano);

        SomenteNumeros(&book[IDcont].paginas, 27, 30);
        fflush(stdin);
        gotoxy(26,31);
        printf("%d", book[IDcont].paginas);

        to_maiuscula(book[IDcont].ISBN, 24, 33);
        fflush(stdin);
        gotoxy(23,34);
        printf("%s", book[IDcont].ISBN);

        to_maiuscula(book[IDcont].local, 31, 36);
        fflush(stdin);
        gotoxy(30,37);
        printf("%s", book[IDcont].local);

        do
        {
            gotoxy(29, 40);
            textcolor(LIGHTGREEN);
            printf("PRESSIONE ENTER PARA CONFIRMAR INCLUSAO OU ESC PARA CANCELAR.");
            textcolor(WHITE);
            gotoxy(120,47);
            setas=get_key();
            if (setas==ENTER)
            {
                if((arq=fopen("teste.txt", "a")) == NULL)
                {
                    clrscr();
                    gotoxy(1,1);
                    printf("Erro ao abrir arquivo! Por favor, tente novamente.\n");
                    getch();
                    break;
                }
                else
                {
                    fflush(stdin);
                    fflush(stdout);
                    fprintf(arq, "%d:%s:%s:%s:%s:%d:%d:%d:%s:%s\n", book[IDcont].ID, book[IDcont].titulo, book[IDcont].autor, book[IDcont].genero, book[IDcont].editora, book[IDcont].edicao, book[IDcont].ano, book[IDcont].paginas, book[IDcont].ISBN, book[IDcont].local);
                    gotoxy(1,40);
                    clreol();
                    gotoxy(47,39);
                    textcolor(LIGHTCYAN);
                    printf("LIVRO INSERIDO COM SUCESSO!");
                    textcolor(WHITE);
                    IDcont++;
                    gotoxy(27,41);
                    //cputsxy(47,40, "                                    ");
                    printf("Para adicionar outro livro pressione      . Para sair pressione    .");
                    gotoxy(64,41);
                    textcolor(LIGHTGREEN);
                    printf("ENTER");
                    gotoxy(91,41);
                    printf("ESC");
                    gotoxy(120,47);
                    textcolor(WHITE);
                }

                fclose(arq);
            }
            else if (setas==ESC)
                return;
        } while (setas != ESC && setas != ENTER);

        do
        {
            setas=get_key();
            if(setas==ESC) {
                clrscr();
                controle=0;
            }
        } while(setas != ENTER && setas != ESC);

    } while (controle != 0);

}

void alterar(int id) {
    int setas=0;

    typedef struct temp {
        char titulo[100];
        char autor[100];
        char genero[50];
        char editora[50];
        char local[400];
        char ISBN[400];
        int status;
        int ano;
        int edicao;
        int ID;
        int paginas;
        float aval;
    } temporario;

    temporario livro[100];

    //pesq_livro();
    cabecalho();
    mostradados2();
    rodape();
    gotoxy(25,12);
    printf("%s", book[id].titulo);
    gotoxy(24,15);
    printf("%s", book[id].autor);
    gotoxy(25,18);
    printf("%s", book[id].genero);
    gotoxy(26,21);
    printf("%s", book[id].editora);
    gotoxy(25,24);
    printf("%d", book[id].edicao);
    gotoxy(22,27);
    printf("%d", book[id].ano);
    gotoxy(26,30);
    printf("%d", book[id].paginas);
    gotoxy(23,33);
    printf("%s", book[id].ISBN);
    gotoxy(30,36);
    printf("%s", book[id].local);

    gotoxy(32,40);
    printf("Pressione       para iniciar alteracao ou     para voltar.");
    textcolor(LIGHTGREEN);
    cputsxy(42,40, "ENTER");
    cputsxy(74,40, "ESC");
    textcolor(WHITE);
    gotoxy(120,47);

    do
    {
        setas=getch();

        if (setas==ENTER)
        {
            gotoxy(1,40);
            clreol();
            gotoxy(17,13);
            printf("Previa: ");
            gotoxy(25,13);
            to_maiuscula(livro[id].titulo, 25, 13);
            gotoxy(17,16);
            printf("Previa: ");
            gotoxy(25,13);
            to_maiuscula(livro[id].autor, 25, 16);
            gotoxy(17,19);
            printf("Previa: ");
            gotoxy(25,13);
            to_maiuscula(livro[id].genero, 25, 19);
            gotoxy(17,22);
            printf("Previa: ");
            gotoxy(25,13);
            to_maiuscula(livro[id].editora, 25, 22);
            gotoxy(17,25);
            printf("Previa: ");
            gotoxy(25,13);
            SomenteNumeros(&livro[id].edicao, 25, 25);
            gotoxy(17,28);
            printf("Previa: ");
            gotoxy(25,13);
            SomenteNumeros(&livro[id].ano, 25, 28);
            gotoxy(17,31);
            printf("Previa: ");
            gotoxy(25,13);
            SomenteNumeros(&livro[id].paginas, 25, 31);
            gotoxy(17,34);
            printf("Previa: ");
            gotoxy(25,13);
            to_maiuscula(livro[id].ISBN, 25, 34);
            gotoxy(17,37);
            printf("Previa: ");
            gotoxy(25,13);
            to_maiuscula(livro[id].local, 25, 37);

            do
            {
                FILE * arq;
                int i=1;
                gotoxy(30,40);
                printf("PRESSIONE       PARA CONFIRMAR ALTERACOES OU     PARA CANCELAR.");
                textcolor(LIGHTGREEN);
                cputsxy(40,40, "ENTER");
                cputsxy(75,40, "ESC");
                textcolor(WHITE);
                gotoxy(120,47);
                setas=getch();
                if (setas==ENTER)
                {
                    if((arq=fopen("teste.txt", "r+")) == NULL)
                    {
                        clrscr();
                        gotoxy(1,1);
                        printf("Erro ao abrir arquivo! Por favor, tente novamente.\n");
                        getch();
                        break;
                    }
                    else
                    {
                        strncpy(book[id].titulo, livro[id].titulo, sizeof(livro[id].titulo));
                        strncpy(book[id].autor, livro[id].autor, sizeof(livro[id].autor));
                        strncpy(book[id].genero, livro[id].genero, sizeof(livro[id].genero));
                        strncpy(book[id].editora, livro[id].editora, sizeof(livro[id].editora));
                        book[id].edicao = livro[id].edicao;
                        book[id].ano = livro[id].ano;
                        book[id].paginas = livro[id].paginas;
                        strncpy(book[id].ISBN, livro[id].ISBN, sizeof(livro[id].ISBN));
                        strncpy(book[id].local, livro[id].local, sizeof(livro[id].local));

                        for(i=1;i<IDcont;i++) {
                            fprintf(arq, "%d:%s:%s:%s:%s:%d:%d:%d:%s:%s\n", book[i].ID, book[i].titulo, book[i].autor, book[i].genero, book[i].editora, book[i].edicao, book[i].ano, book[i].paginas, book[i].ISBN, book[i].local);
                        }
                        /*
                        while (i<id)
                        {
                            fprintf(arq, "%d:%s:%s:%s:%s:%d:%d:%d:%s:%s\n", book[i].ID, book[i].titulo, book[i].autor, book[i].genero, book[i].editora, book[i].edicao, book[i].ano, book[i].paginas, book[i].ISBN, book[i].local);
                            i++;
                        }

                        fprintf(arq, "%d:%s:%s:%s:%s:%d:%d:%d:%s:%s\n", livro[id].ID, livro[id].titulo, livro[id].autor, livro[id].genero, livro[id].editora, livro[id].edicao, livro[id].ano, livro[id].paginas, livro[id].ISBN, livro[id].local);

                        while (book[i+1].ID != 0)
                        {
                            fprintf(arq, "%d:%s:%s:%s:%s:%d:%d:%d:%s:%s\n", book[i+1].ID, book[i+1].titulo, book[i+1].autor, book[i+1].genero, book[i+1].editora, book[i+1].edicao, book[i+1].ano, book[i+1].paginas, book[i+1].ISBN, book[i+1].local);
                            i++;
                        }
                        */
                        fclose(arq);
                    }
                    gotoxy(1,40);
                    clreol();
                    gotoxy(47,40);
                    textcolor(LIGHTCYAN);
                    printf("LIVRO ALTERADO COM SUCESSO!");
                    textcolor(WHITE);
                    gotoxy(120,47);
                    getch();
                }

            } while (setas != ESC && setas != ENTER);
        }
    } while (setas != ESC && setas != ENTER);
}

void excluir(int id) {

    int setas=0, setas2=0, controle=2;

    cabecalho();
    mostradados2();
    rodape();
    gotoxy(25,12);
    printf("%s", book[id].titulo);
    gotoxy(24,15);
    printf("%s", book[id].autor);
    gotoxy(25,18);
    printf("%s", book[id].genero);
    gotoxy(26,21);
    printf("%s", book[id].editora);
    gotoxy(25,24);
    printf("%d", book[id].edicao);
    gotoxy(22,27);
    printf("%d", book[id].ano);
    gotoxy(26,30);
    printf("%d", book[id].paginas);
    gotoxy(23,33);
    printf("%s", book[id].ISBN);
    gotoxy(30,36);
    printf("%s", book[id].local);

    while (setas != ESC && setas != ENTER) {
        gotoxy(30,40);
        printf("Pressione       para prosseguir com a exclusao ou     para voltar.");
        textcolor(LIGHTGREEN);
        gotoxy(40,40);
        printf("ENTER");
        gotoxy(80,40);
        printf("ESC");
        textcolor(WHITE);
        gotoxy(120,47);

        setas=get_key();
    }

    if(setas==ENTER) {
        gotoxy(1,40);
        clreol();

        gotoxy(40,39);
        textcolor(LIGHTRED);
        printf("CONFIRMA EXCLUSAO DO LIVRO ACIMA?");
        gotoxy(42,40);
        textcolor(WHITE);
        printf("Obs.: Esse processo nao pode");
        gotoxy(52,41);
        printf("ser revertido!");
        gotoxy(80,39);
        printf("Sim");
        gotoxy(80,41);
        printf("Nao");
        gotoxy(120,47);

        gotoxy(76,41);
        printf("-->");
        gotoxy(120,47);

        do {
            setas2=get_key();

            if (setas2==ABAIXO) {
                cputsxy(76,41,"    ");
                cputsxy(76,39,"    ");

                controle++;

                if(controle>2) {
                    controle=1;
                    gotoxy(76,39);
                    printf("-->");
                    gotoxy(120,47);
                }
                else {
                    gotoxy(76,41);
                    printf("-->");
                    gotoxy(120,47);
                }
            }
            else if (setas2==ACIMA) {
                cputsxy(76,41,"    ");
                cputsxy(76,39,"    ");

                controle--;

                if(controle<1) {
                    controle=2;
                    gotoxy(76,41);
                    printf("-->");
                    gotoxy(120,47);
                }
                else {
                    gotoxy(76,39);
                    printf("-->");
                    gotoxy(120,47);
                }
            }
        } while (setas2 != ENTER && setas2 != ESC);

        if(setas2==ENTER && controle==1)
        {
            int i;
            FILE * arq;

            if((arq=fopen("teste.txt", "r+")) == NULL) {
                clrscr();
                gotoxy(1,1);
                printf("ERRO AO ABRIR ARQUIVO! POR FAVOR TENTE NOVAMENTE.");
                getch();
            }
            else {
                IDcont--;
                for(i=1; i<IDcont; i++){
                    if(i==id)
                    {
                        fprintf(arq, "%d:\0:\0:\0:\0:\0:\0:\0:\0:\0\n", book[i].ID, book[i].titulo, book[i].autor, book[i].genero, book[i].editora, book[i].edicao, book[i].ano, book[i].paginas, book[i].ISBN, book[i].local);
                    }
                    else
                        fprintf(arq, "%d:%s:%s:%s:%s:%d:%d:%d:%s:%s\n", book[i].ID, book[i].titulo, book[i].autor, book[i].genero, book[i].editora, book[i].edicao, book[i].ano, book[i].paginas, book[i].ISBN, book[i].local);
                }

                mostradel();
                gotoxy(40,39);
                clreol();
                gotoxy(40,40);
                clreol();
                gotoxy(40,41);
                clreol();
                gotoxy(43,40);
                textcolor(LIGHTGREEN);
                printf("LIVRO EXCLUIDO DO SISTEMA COM SUCESSO!");
                textcolor(WHITE);
                fclose(arq);
                gotoxy(120,47);
                getch();
            }
        }
    }

    return;
}

int infolivro(int num) {
    clrscr();
    cabecalho();
    rodape();

    //char contador;  //contador
    int setas;  //variável usada para captura de tecla

    do {
        mostradados2();
        gotoxy(25,12);
        printf("%s", book[num].titulo);
        gotoxy(24,15);
        printf("%s", book[num].autor);
        gotoxy(25,18);
        printf("%s", book[num].genero);
        gotoxy(26,21);
        printf("%s", book[num].editora);
        gotoxy(25,24);
        printf("%d", book[num].edicao);
        gotoxy(22,27);
        printf("%d", book[num].ano);
        gotoxy(26,30);
        printf("%d", book[num].paginas);
        gotoxy(23,33);
        printf("%s", book[num].ISBN);
        gotoxy(30,36);
        printf("%s", book[num].local);

        mostrabotoes();

        gotoxy(120,47);

        setas=get_key();

        if (setas==F1) {
            clrscr();
            printf("F1 OK.");
            //alterar(book[num].ID);
        }
        else if (setas==F2) {
            clrscr();
            alterar(book[num].ID);
        }
        else if (setas==F3) {
            clrscr();
            excluir(book[num].ID);
        }
        else if (setas == ESC) {
            return 1;
        }

    } while (setas != ESC);

    return 0;
}

void pesq_livro() {
    int j, contador=1, setas;
    char pesqLivro[100];

    do
    {
        int qntlivros=0;
        cabecalho();
        mostralivro();
        rodape();

        if (contador<1)
            contador=3;
        else if (contador>3)
            contador=1;

        switch(contador)
        {
            case(1):
                gotoxy(79,16);
                printf("Escolha a forma de pesquisa:");
                textcolor(LIGHTGREEN);
                gotoxy(83,21);
                printf("Pesquisa por livro   <--");
                textcolor(WHITE);
                gotoxy(83,24);
                printf("Pesquisa por autor      ");
                gotoxy(83,27);
                printf("Pesquisa por genero      ");
                gotoxy(120,47);

                setas=get_key();

                if(setas==ENTER) {

                    int FimIndex, invalido=0;

                    do
                    {
                        clrscr();
                        cabecalho();
                        mostralivro();
                        rodape();

                        textcolor(LIGHTCYAN);
                        gotoxy(81,18);
                        printf("Informe o nome do livro");
                        gotoxy(82,19);
                        printf("que deseja pesquisar:");
                        textcolor(WHITE);

                        if(invalido)
                        {
                            textcolor(LIGHTRED);
                            gotoxy(78,28);
                            fputs("Digite ao menos tres caracteres.", stdout);
                            textcolor(WHITE);
                        }
                        invalido = 1;
                        gotoxy(83, 24);
                        if (fgets(pesqLivro, sizeof(pesqLivro), stdin) == NULL) {
                            printf("\n\nERRO!! TENTE NOVAMENTE.");
                            getch();
                        }

                    } while (strlen(pesqLivro) <= 3 || (sscanf(pesqLivro, "%s %n", pesqLivro, &FimIndex) != 1));

                    qntlivros=0;

                    for(j=1; j<=IDcont; j++)
                    {
                        //if(strncmp(book[j].titulo, strupr(pesqLivro), strlen(pesqLivro)) == 0)
                        if(strstr(book[j].titulo, strupr(pesqLivro)) != NULL)
                        {
                            qntlivros++;
                        }
                    }

                    if(qntlivros==0)
                    {
                        cputsxy(73,24, "                               ");
                        cputsxy(73,28, "                                         ");
                        gotoxy(81,28);
                        printf("Nenhum livro encontrado!");
                        gotoxy(120,47);
                        getch();
                    }
                    else
                    {
                        clrscr();
                        cabecalho();
                        retangulo();
                        rodape();

                        gotoxy(49,9);
                        printf("%d LIVRO(S) ENCONTRADO(S)!\n\n", qntlivros);

                        int controle=1, i=1;
                        int linhas=11, linhas2[20];
                        int salvaID[100];
                        int setas2;

                        for(j=1; j<=IDcont; j++)
                        {
                            if(strstr(book[j].titulo, strupr(pesqLivro)) != NULL)
                            {
                                linhas2[i]=linhas+1;
                                salvaID[i]=book[j].ID;
                                gotoxy(10,linhas);
                                printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                                gotoxy(10,linhas+1);
                                //printf("book[j].ID: %d   |  i: %d", book[j].ID, i);
                                printf("³ Livro: %s", book[j].titulo);
                                gotoxy(53,linhas+1);
                                //printf("linhas2[%d]: %d", i, linhas2[i]);
                                printf("³ Autor: %s", book[j].autor);
                                gotoxy(93,linhas+1);
                                printf("³ Localizacao: %s", book[j].local);
                                //printf("³ SalvaID[%d]: %d", j, salvaID[i]);
                                gotoxy(114,linhas+1);
                                printf("³");
                                //gotoxy(53,linhas+2);
                                //printf("%d", salvaID[i]);
                                gotoxy(10,linhas+2);
                                printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                                linhas=linhas+3;
                                i=i+1;
                            }
                        }

                        gotoxy(5,12);
                        printf("-->");
                        gotoxy(120,47);

                        do
                        {
                            setas2=get_key();

                            if(setas2==ABAIXO){

                                gotoxy(5,12);
                                printf("   ");
                                gotoxy(5,15);
                                printf("   ");
                                gotoxy(5,18);
                                printf("   ");
                                gotoxy(5,21);
                                printf("   ");
                                gotoxy(5,24);
                                printf("   ");
                                gotoxy(5,27);
                                printf("   ");
                                gotoxy(5,30);
                                printf("   ");
                                gotoxy(5,33);
                                printf("   ");
                                gotoxy(5,36);
                                printf("   ");
                                gotoxy(5,39);
                                printf("   ");

                                controle++;
                                if(controle>qntlivros) {
                                    controle=1;
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }
                                else {
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }
                            }

                            else if(setas2==ACIMA){
                                gotoxy(5,12);
                                printf("   ");
                                gotoxy(5,15);
                                printf("   ");
                                gotoxy(5,18);
                                printf("   ");
                                gotoxy(5,21);
                                printf("   ");
                                gotoxy(5,24);
                                printf("   ");
                                gotoxy(5,27);
                                printf("   ");
                                gotoxy(5,30);
                                printf("   ");
                                gotoxy(5,33);
                                printf("   ");
                                gotoxy(5,36);
                                printf("   ");
                                gotoxy(5,39);
                                printf("   ");

                                controle--;
                                if(controle<1){
                                    controle=qntlivros;
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }
                                else{
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }

                            }

                        } while (setas2 != ENTER && setas2 != ESC);

                        if (setas2==ENTER) {
                            infolivro(salvaID[controle]);
                        }
                        else {
                            if (setas==ESC) {
                                return;
                            }
                        }
                    }

                }

                else if(setas==ACIMA)
                    contador=3;
                else if(setas==ABAIXO)
                    contador++;
                break;
            case(2):
                textcolor(WHITE);
                gotoxy(79, 16);
                printf("Escolha a forma de pesquisa:");
                gotoxy(83, 21);
                printf("Pesquisa por livro      ");
                textcolor(LIGHTGREEN);
                gotoxy(83, 24);
                printf("Pesquisa por autor   <--");
                textcolor(WHITE);
                gotoxy(83, 27);
                printf("Pesquisa por genero      ");
                gotoxy(120,47);

                setas=get_key();

                if(setas==ENTER){

                    int FimIndex, invalido=0;

                    do
                    {
                        clrscr();
                        cabecalho();
                        mostralivro();
                        rodape();

                        textcolor(LIGHTCYAN);
                        gotoxy(81,18);
                        printf("Informe o nome do autor");
                        gotoxy(82,19);
                        printf("que deseja pesquisar:");
                        textcolor(WHITE);

                        if(invalido)
                        {
                            textcolor(LIGHTRED);
                            gotoxy(78,28);
                            fputs("Digite ao menos tres caracteres.", stdout);
                            textcolor(WHITE);
                        }
                        invalido = 1;
                        gotoxy(83, 24);
                        if (fgets(pesqLivro, sizeof(pesqLivro), stdin) == NULL) {
                            printf("\n\nERRO!! TENTE NOVAMENTE.");
                            getch();
                        }

                    } while (strlen(pesqLivro) <= 3 || (sscanf(pesqLivro, "%s %n", pesqLivro, &FimIndex) != 1));

                    qntlivros=0;

                    for(j=1; j<=IDcont; j++)
                    {
                        //if(strncmp(book[j].titulo, strupr(pesqLivro), strlen(pesqLivro)) == 0)
                        if(strstr(book[j].autor, strupr(pesqLivro)) != NULL)
                        {
                            qntlivros++;
                        }
                    }

                    if(qntlivros==0)
                    {
                        cputsxy(73,24, "                               ");
                        cputsxy(73,28, "                                         ");
                        gotoxy(81,28);
                        printf("Nenhum livro encontrado!");
                        gotoxy(120,47);
                        getch();
                    }
                    else
                    {
                        clrscr();
                        cabecalho();
                        retangulo();
                        rodape();

                        gotoxy(49,9);
                        printf("%d LIVRO(S) ENCONTRADO(S)!\n\n", qntlivros);

                        int controle=1, i=1;
                        int linhas=11, linhas2[20];
                        int salvaID[100];
                        int setas2;

                        for(j=1; j<=IDcont; j++)
                        {
                            if(strstr(book[j].autor, strupr(pesqLivro)) != NULL)
                            {
                                linhas2[i]=linhas+1;
                                salvaID[i]=book[j].ID;
                                gotoxy(10,linhas);
                                printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                                gotoxy(10,linhas+1);
                                //printf("book[j].ID: %d   |  i: %d", book[j].ID, i);
                                printf("³ Livro: %s", book[j].titulo);
                                gotoxy(53,linhas+1);
                                //printf("linhas2[%d]: %d", i, linhas2[i]);
                                printf("³ Autor: %s", book[j].autor);
                                gotoxy(93,linhas+1);
                                printf("³ Localizacao: %s", book[j].local);
                                //printf("³ SalvaID[%d]: %d", j, salvaID[i]);
                                gotoxy(114,linhas+1);
                                printf("³");
                                //gotoxy(53,linhas+2);
                                //printf("%d", salvaID[i]);
                                gotoxy(10,linhas+2);
                                printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                                linhas=linhas+3;
                                i=i+1;
                            }
                        }

                        gotoxy(5,12);
                        printf("-->");
                        gotoxy(120,47);

                        do
                        {
                            setas2=get_key();

                            if(setas2==ABAIXO){

                            gotoxy(5,12);
                            printf("   ");
                            gotoxy(5,15);
                            printf("   ");
                            gotoxy(5,18);
                            printf("   ");
                            gotoxy(5,21);
                            printf("   ");
                            gotoxy(5,24);
                            printf("   ");
                            gotoxy(5,27);
                            printf("   ");
                            gotoxy(5,30);
                            printf("   ");
                            gotoxy(5,33);
                            printf("   ");
                            gotoxy(5,36);
                            printf("   ");
                            gotoxy(5,39);
                            printf("   ");

                                controle++;
                                if(controle>qntlivros){
                                    controle=1;
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }
                                else{
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }
                            }

                            else if(setas2==ACIMA){
                                gotoxy(5,12);
                                printf("   ");
                                gotoxy(5,15);
                                printf("   ");
                                gotoxy(5,18);
                                printf("   ");
                                gotoxy(5,21);
                                printf("   ");
                                gotoxy(5,24);
                                printf("   ");
                                gotoxy(5,27);
                                printf("   ");
                                gotoxy(5,30);
                                printf("   ");
                                gotoxy(5,33);
                                printf("   ");
                                gotoxy(5,36);
                                printf("   ");
                                gotoxy(5,39);
                                printf("   ");

                                controle--;
                                if(controle<1){
                                    controle=qntlivros;
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }
                                else{
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }

                            }

                        } while (setas2 != ENTER && setas2 != ESC);

                        if (setas2==ENTER) {
                            infolivro(salvaID[controle]);
                        }
                        else {
                            if (setas==ESC) {
                                return;
                            }
                        }
                    }
                }

                else if(setas==ACIMA)
                    contador--;
                else if(setas==ABAIXO)
                    contador++;
                break;
            case(3):
                textcolor(WHITE);
                gotoxy(79, 16);
                printf("Escolha a forma de pesquisa:");
                gotoxy(83, 21);
                printf("Pesquisa por livro      ");
                gotoxy(83, 24);
                printf("Pesquisa por autor      ");
                textcolor(LIGHTGREEN);
                gotoxy(83, 27);
                printf("Pesquisa por genero   <--");
                textcolor(WHITE);
                gotoxy(120,47);

                setas=get_key();

                if(setas==ENTER){
                    int FimIndex, invalido=0;

                    do
                    {
                        clrscr();
                        cabecalho();
                        mostralivro();
                        rodape();

                        textcolor(LIGHTCYAN);
                        gotoxy(84,18);
                        printf("Informe o genero");
                        gotoxy(82,19);
                        printf("que deseja pesquisar:");
                        textcolor(WHITE);

                        if(invalido)
                        {
                            textcolor(LIGHTRED);
                            gotoxy(78,28);
                            fputs("Digite ao menos tres caracteres.", stdout);
                            textcolor(WHITE);
                        }
                        invalido = 1;
                        gotoxy(83, 24);
                        if (fgets(pesqLivro, sizeof(pesqLivro), stdin) == NULL) {
                            printf("\n\nERRO!! TENTE NOVAMENTE.");
                            getch();
                        }

                    } while (strlen(pesqLivro) <= 3 || (sscanf(pesqLivro, "%s %n", pesqLivro, &FimIndex) != 1));

                    qntlivros=0;

                    for(j=1; j<=IDcont; j++)
                    {
                        //if(strncmp(book[j].titulo, strupr(pesqLivro), strlen(pesqLivro)) == 0)
                        if(strstr(book[j].genero, strupr(pesqLivro)) != NULL)
                        {
                            qntlivros++;
                        }
                    }

                    if(qntlivros==0)
                    {
                        cputsxy(73,24, "                               ");
                        cputsxy(73,28, "                                         ");
                        gotoxy(81,28);
                        printf("Nenhum livro encontrado!");
                        gotoxy(120,47);
                        getch();
                    }
                    else
                    {
                        clrscr();
                        cabecalho();
                        retangulo();
                        rodape();

                        gotoxy(49,9);
                        printf("%d LIVRO(S) ENCONTRADO(S)!\n\n", qntlivros);

                        int controle=1, i=1;
                        int linhas=11, linhas2[20];
                        int salvaID[100];
                        int setas2;

                        for(j=1; j<=IDcont; j++)
                        {
                            if(strstr(book[j].genero, strupr(pesqLivro)) != NULL)
                            {
                                linhas2[i]=linhas+1;
                                salvaID[i]=book[j].ID;
                                gotoxy(10,linhas);
                                printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
                                gotoxy(10,linhas+1);
                                printf("³ Livro: %s", book[j].titulo);
                                gotoxy(53,linhas+1);
                                printf("³ Autor: %s", book[j].autor);
                                gotoxy(93,linhas+1);
                                printf("³ Localizacao: %s", book[j].local);
                                gotoxy(114,linhas+1);
                                printf("³");
                                gotoxy(10,linhas+2);
                                printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
                                linhas=linhas+3;
                                i=i+1;
                            }
                        }

                        gotoxy(5,12);
                        printf("-->");
                        gotoxy(120,47);

                        do
                        {
                            setas2=get_key();

                            if(setas2==ABAIXO){

                            gotoxy(5,12);
                            printf("   ");
                            gotoxy(5,15);
                            printf("   ");
                            gotoxy(5,18);
                            printf("   ");
                            gotoxy(5,21);
                            printf("   ");
                            gotoxy(5,24);
                            printf("   ");
                            gotoxy(5,27);
                            printf("   ");
                            gotoxy(5,30);
                            printf("   ");
                            gotoxy(5,33);
                            printf("   ");
                            gotoxy(5,36);
                            printf("   ");
                            gotoxy(5,39);
                            printf("   ");

                                controle++;
                                if(controle>qntlivros){
                                    controle=1;
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }
                                else{
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }
                            }

                            else if(setas2==ACIMA){
                                gotoxy(5,12);
                                printf("   ");
                                gotoxy(5,15);
                                printf("   ");
                                gotoxy(5,18);
                                printf("   ");
                                gotoxy(5,21);
                                printf("   ");
                                gotoxy(5,24);
                                printf("   ");
                                gotoxy(5,27);
                                printf("   ");
                                gotoxy(5,30);
                                printf("   ");
                                gotoxy(5,33);
                                printf("   ");
                                gotoxy(5,36);
                                printf("   ");
                                gotoxy(5,39);
                                printf("   ");

                                controle--;
                                if(controle<1){
                                    controle=qntlivros;
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }
                                else{
                                    gotoxy(5,linhas2[controle]);
                                    printf("-->");
                                    gotoxy(120,47);
                                }

                            }

                        } while (setas2 != ENTER && setas2 != ESC);

                        if (setas2==ENTER) {
                            infolivro(salvaID[controle]);
                        }
                        else {
                            if (setas==ESC) {
                                return;
                            }
                        }
                    }
                }


                else if(setas==ACIMA)
                    contador--;
                else if(setas==ABAIXO)
                    contador=1;
                break;
            default:
                printf("\n\nESCOLHA INVALIDA!\n");
                getch();
                break;
        }

        if (setas==ESC) {
            clrscr();
            return;
        }

    } while (contador != 0);
}

void menu() {
    int contador=1;  //contador
    int setas;  //variável usada para captura de tecla

    do {
        cabecalho();
        mostralivro();
        rodape();
        //se usuário estiver na primeira opção do menu e apertar seta para cima
        //cursor vai para a última opção (6)
        if (contador<1)
            contador=6;
        //se usuário estiver na última opção do menu e apertar seta para baixo
        //cursor vai para a primeira opção (1)
        else if (contador>6)
            contador=1;

        switch (contador)
        {
            case(1):
                textcolor(LIGHTGREEN);
                gotoxy(76,15);
                printf("Adicionar Livro                <--");
                textcolor(WHITE);
                gotoxy(76,18);
                printf("Menu de Consulentes               ");
                gotoxy(76,21);
                printf("Pesquisar Livro                   ");
                gotoxy(76,24);
                printf("Alterar Livro                     ");
                gotoxy(76,27);
                printf("Menu Temporario                   ");
                gotoxy(76,32);
                printf("Sair                              ");
                gotoxy(120,47);
                setas=get_key();
                if (setas==ENTER) {
                    adicionar_livro();
                }
                // else/if para movimentação do cursor
                else if (setas==ACIMA)
                    contador=6;
                else if (setas==ABAIXO)
                    contador++;
                break;
            case(2):
                textcolor(WHITE);
                gotoxy(76,15);
                printf("Adicionar Livro                   ");
                gotoxy(76,18);
                textcolor(LIGHTGREEN);
                printf("Menu de Consulentes            <--");
                textcolor(WHITE);
                gotoxy(76,21);
                printf("Pesquisar Livro                   ");
                gotoxy(76,24);
                printf("Alterar Livro                     ");
                gotoxy(76,27);
                printf("Menu Temporario                   ");
                gotoxy(76,32);
                printf("Sair                              ");
                gotoxy(120,47);
                setas=get_key();
                //caso cursor estiver na posição (2) e tecla pressionada for ENTER, entrar na função 'regras()'
                if (setas==ENTER){
                    consulentes();
                }
                // else/if para movimentação do cursor
                else if (setas==ACIMA)
                    contador--;
                else if (setas==ABAIXO)
                    contador++;
                break;
            case(3):
                textcolor(WHITE);
                gotoxy(76,15);
                printf("Adicionar Livro                   ");
                gotoxy(76,18);
                printf("Menu de Consulentes               ");
                gotoxy(76,21);
                textcolor(LIGHTGREEN);
                printf("Pesquisar Livro                <--");
                textcolor(WHITE);
                gotoxy(76,24);
                printf("Alterar Livro                     ");
                gotoxy(76,27);
                printf("Menu Temporario                   ");
                gotoxy(76,32);
                printf("Sair                              ");
                gotoxy(120,47);
                setas=get_key();
                //caso cursor estiver na posição (3) e tecla pressionada for ENTER, entrar na função 'creditos()'
                if (setas==ENTER){
                    pesq_livro();
                }
                // else/if para movimentação do cursor
                else if (setas==ACIMA)
                    contador--;
                else if (setas==ABAIXO)
                    contador++;
                break;
            case(4):
                textcolor(WHITE);
                gotoxy(76,15);
                printf("Adicionar Livro                   ");
                gotoxy(76,18);
                printf("Menu de Consulentes               ");
                gotoxy(76,21);
                printf("Pesquisar Livro                   ");
                gotoxy(76,24);
                textcolor(LIGHTGREEN);
                printf("Alterar Livro                  <--");
                textcolor(WHITE);
                gotoxy(76,27);
                printf("Menu Temporario                   ");
                gotoxy(76,32);
                printf("Sair                              ");
                gotoxy(120,47);
                setas=get_key();
                //caso cursor estiver na posição (3) e tecla pressionada for ENTER, entrar na função 'creditos()'
                if (setas==ENTER){
                    //alterar();
                }
                // else/if para movimentação do cursor
                else if (setas==ACIMA)
                    contador--;
                else if (setas==ABAIXO)
                    contador++;
                break;
            case(5):
                textcolor(WHITE);
                gotoxy(76,15);
                printf("Adicionar Livro                   ");
                gotoxy(76,18);
                printf("Menu de Consulentes               ");
                gotoxy(76,21);
                printf("Pesquisar Livro                   ");
                gotoxy(76,24);
                printf("Alterar Livro                     ");
                gotoxy(76,27);
                textcolor(LIGHTGREEN);
                printf("Menu Temporario                <--");
                textcolor(WHITE);
                gotoxy(76,32);
                printf("Sair                              ");
                gotoxy(120,47);
                setas=get_key();
                //caso cursor estiver na posição (3) e tecla pressionada for ENTER, entrar na função 'creditos()'
                if (setas==ENTER){
                    //infolivro();
                }
                // else/if para movimentação do cursor
                else if (setas==ACIMA)
                    contador--;
                else if (setas==ABAIXO)
                    contador++;
                break;
            case(6):
                textcolor(WHITE);
                gotoxy(76,15);
                printf("Adicionar Livro                   ");
                gotoxy(76,18);
                printf("Menu de Consulentes               ");
                gotoxy(76,21);
                printf("Pesquisar Livro                   ");
                gotoxy(76,24);
                printf("Alterar Livro                     ");
                gotoxy(76,27);
                printf("Menu Temporario                   ");
                gotoxy(76,32);
                textcolor(LIGHTGREEN);
                printf("Sair                           <--");
                textcolor(WHITE);
                gotoxy(120,47);
                setas=get_key();
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
            default:
                printf("Opcao invalida, tente novamente!\n");
                getch();
                break;
        }
        //se tecla ESC for pressionada, chamar função 'sair()', finalizando o progra

        if (setas==ESC)
        //    break;
            sair();
        //}
    } while (contador != 0);//while(setas != ESC);
}
// INICIO DA FUNÇÃO PARA CADASTRAR NOVO LIVRO
void cadastrar() {
    clrscr();
    cabecalho();
    rodape();
    //char contador;  //contador
    int setas;  //variável usada para captura de tecla

    while (setas != ESC) {
        mostradados();
        setas=get_key();
    /*
        contador=getch();

        if (contador==ENTER) {
            gotoxy(24,18);
            scanf("%s", &contador);

            contador=getch();

            if (contador==ENTER) {
                gotoxy(25,21);
                scanf("%s", &contador);
            }

    */
    }

    if (setas == ESC) {
        return;
    }
}
// FIM DA FUNÇÃO CADASTRAR NOVO LIVRO

// INICIO DO PROGRAMA
int main() {
    system("cmd /c \"mode con: cols=120 lines=47\"");
    load_dados();

    menu();

    return(0);
}
// FIM DO PROGRAMA
