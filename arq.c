#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro
{
    int isbn;
    char nome[80];
    char autor[80];
    float preco;
    struct livro *next;
} livro;

typedef struct lista
{
    livro *head;
    livro *tail;
} lista;

lista livros;

int getOp()
{
    int op;
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Procurar\n");
    printf("4 - Listar\n");
    printf("5 - Sair\n");
    printf("\nDigite sua opção: ");
    scanf("%d", &op);
    return op;
}

void printLivro(livro *l)
{
    printf("\n---------\n");
    printf("ISBN: %d\n", l->isbn);
    printf("Autor: %s\n", l->autor);
    printf("Nome: %s\n", l->nome);
    printf("Preço: %.2f\n", l->preco);
    printf("---------\n");
}

void inserirLivro()
{
    livro *novoLivro = malloc(sizeof(livro));
    printf("ISBN: ");
    scanf(" %d", &novoLivro->isbn);
    printf("Autor: ");
    scanf(" %s", novoLivro->autor);
    printf("Nome: ");
    scanf(" %s", novoLivro->nome);
    printf("Preço: ");
    scanf(" %f", &novoLivro->preco);
    novoLivro->next = NULL;

    if (livros.head == NULL)
    {
        livros.head = novoLivro;
        livros.tail = novoLivro;
    }
    else
    {
        livros.tail->next = novoLivro;
        livros.tail = novoLivro;
    }
}

void removerLivro()
{
    int isbn;
    printf("ISBN: ");
    scanf(" %d", &isbn);
    livro *it = NULL;
    for (it = livros.head; it != NULL && it->isbn != isbn; it = it->next)
        ;
    if (it)
    {
        if (it == livros.head)
        {
            livros.head = it->next;
        }
        else
        {
            (it - 1)->next = it->next;
        }
        free(it);
        return;
    }

    printf("ISBN não encontrado. Procure por autor.\n");

    char autor[80];
    printf("Autor: ");
    scanf(" %s", autor);
    it = NULL;
    for (it = livros.head; strcmp(it->autor, autor) != 0; it = it->next)
        ;
    if (it)
    {
        if (it == livros.head)
        {
            livros.head = it->next;
        }
        else
        {
            (it - 1)->next = it->next;
        }
        free(it);
        return;
    }
}

void procurarLivro()
{
    int isbn;
    printf("ISBN: ");
    scanf(" %d", &isbn);
    livro *it = NULL;
    for (it = livros.head; it != NULL && it->isbn != isbn; it = it->next)
        ;
    if (it)
    {
        printLivro(it);
        return;
    };

    printf("ISBN não encontrado. Procure por autor.\n");

    char autor[80];
    printf("Autor: ");
    scanf(" %s", autor);
    it = NULL;
    for (it = livros.head; strcmp(it->autor, autor) != 0; it = it->next)
        ;
    if (it)
        printLivro(it);
}

void listarLivros()
{
    for (livro *it = livros.head; it != NULL; it = it->next)
    {
        printLivro(it);
    }
}

void salvar()
{
    FILE *file = fopen("livros.txt", "w");
    for (livro *it = livros.head; it != NULL; it = it->next)
    {
        fprintf(file, "%d, %s, %s, %.2f\n", it->isbn, it->autor, it->nome, it->preco);
    }
    fclose(file);

    file = fopen("livros.bin", "wb");
    for (livro *it = livros.head; it != NULL; it = it->next)
    {
        fwrite(it, sizeof(livro), 1, file);
    }
    fclose(file);
}

void lerTxt()
{
    FILE *file = fopen("livros.txt", "r");
    if (!file)
        return;
    livro *novoLivro;
    for (int i = 0; !feof(file); i++)
    {
        novoLivro = malloc(sizeof(livro));
        fscanf(file, "%d, %[^,], %[^,], %f\n",
               &novoLivro->isbn, novoLivro->autor, novoLivro->nome, &novoLivro->preco);
        if (i == 0)
        {
            livros.head = novoLivro;
            livros.tail = novoLivro;
        }
        else
        {
            livros.tail->next = novoLivro;
            livros.tail = novoLivro;
        }
    }
    fclose(file);
}

void lerBin()
{
    FILE *file = fopen("livros.bin", "rb");
    if (!file)
        return;
    livro *novoLivro;
    for (int i = 0; !feof(file); i++)
    {
        novoLivro = malloc(sizeof(livro));
        if (fread(novoLivro, sizeof(livro), 1, file))
        {
            if (i == 0)
            {
                livros.head = novoLivro;
                livros.tail = novoLivro;
            }
            else
            {
                livros.tail->next = novoLivro;
                livros.tail = novoLivro;
            }
        }
    }
    fclose(file);
}

int main()
{
    livros.head = NULL;
    livros.tail = NULL;

    lerTxt();

    int continua = 1;

    while (continua)
    {
        int op = getOp();
        switch (op)
        {
        case 1:
            inserirLivro();
            salvar();
            break;
        case 2:
            removerLivro();
            salvar();
            break;
        case 3:
            procurarLivro();
            break;
        case 4:
            listarLivros();
            break;
        case 5:
            continua = 0;
            break;
        default:
            printf("Opção inválida!\n\n");
            break;
        }
    }
    return 0;
}