#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char music[50];
    struct node *prox;
    struct node *ant;
} node;
typedef node *playlist;
void inserir(playlist *);
void show_list(playlist);
void remover(playlist *);
node *next(node *);
node *prv(node *);

void inserir(playlist *l)
{
    node *novo;
    novo = (node *)malloc(sizeof(node));
    printf("Insira o nome da musica: ");
    scanf(" %[^\n]s", novo->music);

    if ((*l) != NULL)
    {
        node *aux = (*l);
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        novo->prox = NULL;
    }
    else
    {
        (*l) = novo;
        novo->prox = NULL;
        novo->ant = NULL;
    }
}
void show_list(playlist l)
{
    node *aux;
    aux = l;
    while (aux != NULL)
    {
        printf("%s\n", aux->music);
        aux = aux->prox;
    }
}
void remover(playlist *l)
{
    node *aux = *l;
    char search[50];
    printf("Qual eh a musica que deseja remover ?: ");
    scanf(" %[^\n]s", search);

    while (aux != NULL && strcmp(search, aux->music) != 0)
        aux = aux->prox;
    if (aux == NULL)
    {
        printf("\nMusica nao encontrada,tente novamente.\n");
    }
    else
    {
        if (aux == (*l))
        {
            (*l) = aux->prox;
            if ((*l) != NULL)
                (*l)->ant = NULL;
            free(aux);
            printf("\nmusica excluida.\n");
        }
        else
        {
            if (aux->prox != NULL)
            {
                aux->prox->ant = aux->ant;
                aux->ant->prox = aux->prox;
            }
            else
                aux->ant->prox = NULL;
            free(aux);
            printf("\nMusica excluida.\n");
        }
    }
}
node *next(node *tocando)
{
    if (tocando != NULL)
        tocando = tocando->prox;
    return tocando;
}
node *prv(node *tocando)
{
    if (tocando != NULL)
        tocando = tocando->ant;
    return tocando;
}

int menu()
{

    int comando;
    printf("\n--------Menu Playlist-------\n");
    printf("1 - inserir musica\n");
    printf("2 - remover musica\n");
    printf("3 - iniciar playlist\n");
    printf("4 - mostrar playlist\n");
    printf("5 - proxia musica\n");
    printf("6 - anterior musica\n");
    printf("7 - musica sendo tocada\n");
    printf("0 - sair\n");
    printf("Insira sua opcao: ");
    scanf("%d", &comando);

    return comando;
}

int main()
{
    playlist l = NULL;
    node *tocando = NULL;
    int comando;

    do
    {
        comando = menu();
        switch (comando)
        {

        case 1:
        {
            inserir(&l);
            break;
        }
        case 2:
        {
            remover(&l);
            break;
        }
        case 3:
        {
            tocando = l;
            break;
        }
        case 4:
        {
            show_list(l);
            break;
        }
        case 5:
        {
            tocando = next(tocando);
            break;
        }
        case 6:
        {
            tocando = prv(tocando);
            break;
        }
        case 7:
        {
            if (tocando == NULL)
                printf("\nnenhuma musica sendo tocada\n");
            else
                printf("%s\n", tocando->music);
        }
        }

    } while (comando != 0);
    return 0;
}