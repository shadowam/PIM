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

int IDcont=1, ultimo_livro;

typedef struct registro {
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
} livros;

livros book[100];

/*
void load_dados(void);
void menu(void);
void cadastrar(void);
void consulentes(void);
void alterar(int);
void adicionar_livro(void);
void pesq_livro(void);
int SomenteNumeros(int *i, int x, int y);
char to_maiuscula (char *pal, int x, int y);
int get_key(void);
int infolivro(int);
*/
