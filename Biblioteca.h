#define ACIMA 72 + 512
#define ABAIXO 80 + 512
#define ESQUERDA 75 + 512
#define DIREITA 77 + 512
#define ESC 27
#define ENTER 13
#define BACKSPACE 8
#define TAB 9
#define F1 59 + 256
#define F2 60 + 256
#define F3 61 + 256

extern int IDcont;

struct livros {
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
};

extern struct livros book[100];

extern void consul_main(void);

extern void cabecalho(void);
extern void rodape(void);
extern void retangulo(void);
extern void mostralivro(void);
extern void mostradados(void);
extern void mostradados2(void);
extern void listalivro(void);
extern void mostrabotoes(void);
extern void mostradel(void);

extern int get_key();
extern int SomenteNumeros(int *i, int x, int y);
extern char to_maiuscula (char *pal, int x, int y);
extern void load_dados(void);

extern void sair(void);
extern void adicionar_livro(void);
extern void alterar(int id);
extern void excluir(int id);
extern int infolivro(int num);
extern void pesq_livro(void);
extern void pesq_autor(void);
extern void pesq_genero(void);
extern void menu(void);
