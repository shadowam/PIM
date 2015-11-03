	#include <stdio.h> //biblioteca que controla os comandos de entrada e saída
	#include <stdlib.h> //biblioteca que define funções básicas de propósito geral
	#include <conio2.h> //biblioteca usada para edição da janela de console, como posição e cor
	#include <string.h> //biblioteca usada para a manipulação de dados 'string'
	#include <ctype.h>
	#include "design.h"
	//#include "livros.h" //header que contém a lista de livros

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

	int IDcont=1, ultimo_livro;

	typedef struct registro {
	    char titulo[100];
	    char autor[100];
	    char genero[100];
	    char editora[100];
	    char status[25];
	    int ISBN;
	    int edicao;
	    int ID;
	    int paginas;
	    float aval;
	} livros;

	livros book[100];

	/*
	struct Usuarios {
	    int id_cliente;
	    int documento;
	    char nome[100];
	    int telefone;
	} Usuario;
	*/

	void load_dados();
	void menu();
	void cadastrar();
	void consulentes();
	int teste();
	void alterar();
	void adicionar_livro();
	void pesq_livro();

	// INICIO DO PROGRAMA
	int main()
	{
	    system("cmd /c \"mode con: cols=120 lines=46\"");
	    load_dados();

	    menu();

	    return(0);
	}
	// FIM DO PROGRAMA

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
	        cputsxy(x, y, "                                                                              ");
	        //printf("%d | %d", x, y);
	        gotoxy(x, y);
	        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
	            return 1;
	        }

	        gotoxy(40,37);
	        clreol();

	    } while ((sscanf(buffer, "%d %n", i, &FimIndex) != 1) || buffer[FimIndex]);

	    return 0;
	}

	char to_maiuscula (char *pal, int x, int y)
	{
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
	        cputsxy(x, y, "                                                                              ");

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

	        gotoxy(37,37);
	        clreol();

	        strncpy(pal, buffer, sizeof(buffer));

	    } while (strlen(buffer) <= 1 || sscanf(buffer, "%s %n", buffer, &FimIndex) != 1); //verifica se o conteudo de buffer é uma string com mais de 1 caracteres.

	    return 0;
	}

	void load_dados()
	{
	    FILE* arq;

	    char buffer[99];

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
	            sscanf(buffer, "%d : %[^:] : %[^:] : %[^:] : %[^:] : %d : %d : %d", &book[i].ID, book[i].titulo, book[i].autor, book[i].genero, book[i].editora, &book[i].edicao, &book[i].paginas, &book[i].ISBN);

	            i++;
	            if (IDcont < i)
	                IDcont++;
	        }

	        fclose(arq);
	    }

	    ultimo_livro = IDcont;

	    return;
	}

	void consulentes()
	{
	    clrscr();
	    cabecalho();
	    rodape();
	    //char contador;  //contador
	    char setas;  //variável usada para captura de tecla

	    while (setas != ESC) {
	        mostradados();
	        setas=getch();
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
	void sair()
	{
	    clrscr();

	    int contador=1;  //contador
	    char setas;  //variável usada para captura de tecla

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
	                gotoxy(120,46);
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
	                gotoxy(81,14);
	                printf("Deseja sair do sistema?");
	                gotoxy(91,20);
	                printf("Sim");
	                textcolor(LIGHTGREEN);
	                gotoxy(88,23);
	                printf("-> Nao");
	                textcolor(WHITE);
	                gotoxy(120,46);
	                setas=getch();
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
	    //return;
	}
	// FIM DA FUNÇÃO SAIR DO PROGRAMA

	// INICIO DA FUNÇÃO PARA MOSTRAR O MENU INICIAL DO PROGRAMA
	void menu()
	{
	    int contador=1;  //contador
	    char setas;  //variável usada para captura de tecla

	    do {
	        cabecalho();
	        mostralivro();
	        rodape();
	        //retangulo();
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
	                gotoxy(120,46);
	                setas=getch();
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
	                gotoxy(120,46);
	                setas=getch();
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
	                gotoxy(120,46);
	                setas=getch();
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
	                gotoxy(120,46);
	                setas=getch();
	                //caso cursor estiver na posição (3) e tecla pressionada for ENTER, entrar na função 'creditos()'
	                if (setas==ENTER){
	                    alterar();
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
	                gotoxy(120,46);
	                setas=getch();
	                //caso cursor estiver na posição (3) e tecla pressionada for ENTER, entrar na função 'creditos()'
	                if (setas==ENTER){
	                    teste();
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
	                gotoxy(120,46);
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
	// FIM DA FUNÇÃO MENU

	// INICIO DA FUNÇÃO PARA CADASTRAR NOVO LIVRO
	void cadastrar()
	{
	    clrscr();
	    cabecalho();
	    rodape();
	    //char contador;  //contador
	    char setas;  //variável usada para captura de tecla

	    while (setas != ESC) {
	        mostradados();
	        setas=getch();
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

	// INICIO DA FUNÇÃO PARA CADASTRAR NOVO LIVRO
	int teste(num)
	{
	    clrscr();
	    cabecalho();
	    rodape();

	    //char contador;  //contador
	    char setas;  //variável usada para captura de tecla

	    while (setas != ESC) {
	        mostradados();
	        gotoxy(26,15);
	        printf("%s", book[num].titulo);
	        gotoxy(23,18);
	        printf("%s", book[num].autor);
	        gotoxy(24,21);
	        printf("%s", book[num].genero);
	        gotoxy(27,24);
	        printf("%s", book[num].editora);
	        gotoxy(23,27);
	        printf("%d", book[num].edicao);
	        gotoxy(26,30);
	        printf("%d", book[num].paginas);
	        gotoxy(22,33);
	        printf("%d", book[num].ISBN);
	        gotoxy(120,46);

	        setas=getch();
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
	        return 1;
	    }

	    return 0;
	}
	// FIM DA FUNÇÃO CADASTRAR NOVO LIVRO

	void adicionar_livro()
	{
	    FILE * arq;

	    char setas;
	    int controle=1;

	    do {
	        clrscr();
	        cabecalho();
	        mostradados();
	        rodape();

	        book[IDcont].ID = IDcont;

	        //gotoxy(25, 15);
	        //fgets(book[IDcont].titulo, sizeof(book[IDcont].titulo), stdin);
	        to_maiuscula(book[IDcont].titulo, 25, 15);

	        //gotoxy(24, 18);
	        //fgets(book[IDcont].autor, sizeof(book[IDcont].autor), stdin);
	        to_maiuscula(book[IDcont].autor, 24, 18);

	        //gotoxy(25, 21);
	        //fgets(book[IDcont].genero, sizeof(book[IDcont].genero), stdin);
	        to_maiuscula(book[IDcont].genero, 25, 21);

	        //gotoxy(26, 24);
	        //fgets(book[IDcont].editora, sizeof(book[IDcont].editora), stdin);
	        to_maiuscula(book[IDcont].editora, 26, 24);

	        SomenteNumeros(&book[IDcont].edicao, 25, 27);

	        SomenteNumeros(&book[IDcont].paginas, 26, 30);

	        //gotoxy(23, 33);
	        //fgets(book[IDcont].ISBN, sizeof(book[IDcont].ISBN), stdin);
	        //to_maiuscula(book[IDcont].ISBN, 23, 33);
	        SomenteNumeros(&book[IDcont].ISBN, 23, 33);

	        do
	        {
	            gotoxy(27, 37);
	            textcolor(LIGHTGREEN);
	            printf("PRESSIONE ENTER PARA CONFIRMAR INCLUSAO OU ESC PARA CANCELAR.");
	            gotoxy(120,46);
	            setas=getch();
	            if (setas==ENTER)
	            {
	                if((arq=fopen("teste.txt", "a")) == NULL)
	                {
	                    clrscr();
	                    gotoxy(1, 1);
	                    printf("Erro ao abrir arquivo! Por favor, tente novamente.\n");
	                    getch();
	                    break;
	                }
	                else
	                {
	                    fprintf(arq, "%d : %s : %s : %s : %s : %d : %d : %d\n", book[IDcont].ID, book[IDcont].titulo, book[IDcont].autor, book[IDcont].genero, book[IDcont].editora, book[IDcont].edicao, book[IDcont].paginas, book[IDcont].ISBN);
	                    gotoxy(1, 37);
	                    clreol();
	                    gotoxy(47, 37);
	                    textcolor(LIGHTCYAN);
	                    printf("LIVRO INSERIDO COM SUCESSO!");
	                    IDcont++;
	                }

	                fclose(arq);
	            }

	        } while (setas != ESC && setas != ENTER);

	        gotoxy(27, 38);
	        printf("Para adicionar outro livro pressione      . Para sair pressione    .");
	        gotoxy(64, 38);
	        textcolor(LIGHTGREEN);
	        printf("ENTER");
	        gotoxy(91, 38);
	        printf("ESC");
	        textcolor(WHITE);

	        do
	        {
	            setas=getch();
	            if(setas==ESC) {
	                clrscr();
	                controle=0;
	            }
	        } while(setas != ENTER && setas != ESC);

	    } while (controle != 0);

	}

	void pesq_livro()
	{
	    int j, contador=1;
	    char setas, pesqLivro[50];

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
	                gotoxy(120,46);

	                setas = getch();

	                if(setas==ENTER){

	                    int FimIndex, invalido=0;

	                    do
	                    {
	                        //clrscr();
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
	                            printf("\n\nNULO!!");
	                            getch();
	                        }

	                    } while (strlen(pesqLivro) <= 3 || (sscanf(pesqLivro, "%s %n", pesqLivro, &FimIndex) != 1));

	                    for(j=1; j<=IDcont; j++)
	                    {
	                        if(strncmp(book[j].titulo, strupr(pesqLivro), strlen(pesqLivro)) == 0)
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
	                        gotoxy(120,46);
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
	                        int linhas=11, linhas2[100];
	                        int salvaID[100];
	                        char setas2;

	                        salvaID[0]=0;

	                        for(j=1; j<=IDcont; j++)
	                        {
	                            if(strncmp(book[j].titulo, strupr(pesqLivro), strlen(pesqLivro)) == 0)
	                            {
	                                linhas2[i]=linhas+1;
	                                salvaID[i]=book[j].ID;
	                                i=i+1;
	                                gotoxy(10,linhas);
	                                printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	                                gotoxy(10,linhas+1);
	                                printf("³ Livro: %s", book[j].titulo);
	                                gotoxy(53,linhas+1);
	                                printf("³ Autor: %s", book[j].autor);
	                                gotoxy(98,linhas+1);
	                                printf("³ Edicao: %d", book[j].edicao);
	                                gotoxy(114,linhas+1);
	                                //printf("³");
	                                //gotoxy(53,linhas+2);
	                                //printf("%d", salvaID[i]);
	                                gotoxy(10,linhas+2);
	                                printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
	                                linhas=linhas+3;
	                            }
	                        }

	                        gotoxy(5,12);
	                        printf("-->");
	                        gotoxy(120,46);

	                        do
	                        {
	                            setas2=getch();

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

	                            if(setas2==ABAIXO){
	                                controle++;
	                                if(controle>qntlivros){
	                                    controle=1;
	                                    gotoxy(5,linhas2[controle]);
	                                    //printf("controle: %d, linhas2[controle]: %d", controle, linhas2[controle]);
	                                    printf("-->");
	                                    gotoxy(120,46);
	                                }
	                                else{
	                                    gotoxy(5,linhas2[controle]);
	                                    //printf("controle: %d, linhas2[controle]: %d", controle, linhas2[controle]);
	                                    printf("-->");
	                                    gotoxy(120,46);
	                                }
	                            }
	                            else{
	                                if(setas2==ACIMA){
	                                    controle--;
	                                    if(controle<1){
	                                        controle=qntlivros;
	                                        gotoxy(5,linhas2[controle]);
	                                        //printf("controle: %d, linhas2[controle]: %d", controle, linhas2[controle]);
	                                        printf("-->");
	                                        gotoxy(120,46);
	                                    }
	                                    else{
	                                        gotoxy(5,linhas2[controle]);
	                                        //printf("controle: %d, linhas2[controle]: %d", controle, linhas2[controle]);
	                                        printf("-->");
	                                        gotoxy(120,46);
	                                    }
	                                }
	                            }

	                        } while (setas2 != ENTER && setas2 != ESC);

	                        if (setas2==ENTER) {
	                            teste(salvaID[controle]);
	                            getch();
	                        }
	                        else {
	                            if (setas==ESC) {
	                                return;
	                            }
	                        }
	                    }

	                }

	                //clrscr();
	                //printf("UOU FILHOTE!");
	                //getch();

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
	                gotoxy(120,46);

	                setas = getch();

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
	                            printf("\n\nNULO!!");
	                            getch();
	                        }

	                    } while (strlen(pesqLivro) <= 3 || (sscanf(pesqLivro, "%s %n", pesqLivro, &FimIndex) != 1));

	                    for(j=1; j<=IDcont; j++)
	                    {
	                        if(strncmp(book[j].autor, strupr(pesqLivro), strlen(pesqLivro)) == 0)
	                        {
	                            qntlivros++;
	                            clrscr();
	                            cabecalho();
	                            rodape();
	                            gotoxy(1,10);
	                            listalivro();
	                            gotoxy(20,12);
	                            printf("Livro: %s | Autor: %s | Edicao: %d", book[j].titulo, book[j].autor, book[j].edicao);
	                            getch();
	                        }
	                    }

	                    printf("%d", qntlivros);
	                    if(qntlivros==0)
	                    {
	                        cputsxy(73,24, "                               ");
	                        cputsxy(73,28, "                                         ");
	                        gotoxy(81,28);
	                        printf("Nenhum livro encontrado!");
	                        gotoxy(120,46);
	                    }

	                    getch();
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
	                gotoxy(120,46);

	                setas = getch();

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
	                            printf("\n\nNULO!!");
	                            getch();
	                        }

	                    } while (strlen(pesqLivro) <= 3 || (sscanf(pesqLivro, "%s %n", pesqLivro, &FimIndex) != 1));

	                    for(j=1; j<=IDcont; j++)
	                    {
	                        if(strncmp(book[j].genero, strupr(pesqLivro), strlen(pesqLivro)) == 0)
	                        {
	                            qntlivros++;
	                            clrscr();
	                            cabecalho();
	                            rodape();
	                            gotoxy(1,10);
	                            listalivro();
	                            gotoxy(20,12);
	                            printf("Livro: %s | Autor: %s | Edicao: %d", book[j].titulo, book[j].autor, book[j].edicao);
	                            getch();
	                        }
	                    }

	                    printf("%d", qntlivros);
	                    if(qntlivros==0)
	                    {
	                        cputsxy(73,24, "                               ");
	                        cputsxy(73,28, "                                         ");
	                        gotoxy(81,28);
	                        printf("Nenhum livro encontrado!");
	                        gotoxy(120,46);
	                    }

	                    getch();
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

	void alterar()
	{
	    clrscr();
	    int j, contador=0;
	    char pesqLivro[100];

	    fflush(stdin);
	    printf("\n\nDigite o nome do livro que deseja alterar: ");
	    fgets(pesqLivro, sizeof(pesqLivro), stdin);

	    for(j=1; j<IDcont; j++)
	    {
	        if (strncmp(book[j].titulo, pesqLivro, 3) == 0)
	        {
	            contador++;
	            printf("\n\n\nID: %d", book[j].ID);
	            printf("\nLivro: %s\n", strupr(book[j].titulo));
	            printf("Genero: %s\n", book[j].genero);
	        }
	    }

	    if (contador == 0)
	        printf("\nNENHUM LIVRO ENCONTRADO!\n");
	    else {
	        gotoxy(5,2);
	        printf("\n%d LIVROS ENCONTRADOS. Utilize as setas para escolher o livro que deseja alterar.", contador);
	        gotoxy(120,46);
	    }

	    getch();
	    clrscr();
	    return;
	}
