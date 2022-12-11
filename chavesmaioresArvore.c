#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct estrutura
{
    int chave;
    struct estrutura *esq;
    struct estrutura *dir;
} NO;

void inicializarArvore(NO **raiz)
{
    *raiz = NULL;
}

bool arvoreVazia(NO *raiz)
{
    if (!raiz)
        return (true);
    else
        return (false);
}
NO *buscaNo(NO *raiz, int ch, NO **pai)
{
    NO *atual = raiz;
    *pai = NULL;
    while (atual)
    {
        if (atual->chave == ch)
            return (atual);
        *pai = atual;
        if (ch < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return (NULL);
}
bool inserir(NO **raiz, int ch)
{
    NO *pai = NULL;
    NO *atual = buscaNo(*raiz, ch, &pai);
    if (atual)
        return false;
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    if (pai)
    {
        if (ch < pai->chave)
            pai->esq = novo;
        else
            pai->dir = novo;
    }
    else
        *raiz = novo;
    return true;
}
void exibir(NO *p)
{ // pré ordem

    if (p)
    {

        exibir(p->esq);

        printf("%d ", p->chave);
        exibir(p->dir);
    }
}
void contarMaiores(NO *raiz, NO *p, int *maiores)
{

    if (raiz)
    {
        if (raiz->chave > p->chave)
        {
            *maiores = *maiores + 1;
        }
        contarMaiores(raiz->esq, p, maiores);
        contarMaiores(raiz->dir, p, maiores);
    }
}
int main()
{

    NO *A;

    inicializarArvore(&A);
    int n = 7;
    int vetor[7] = {3, 1, 2, 4, 5, 6, 8};

    for (int i = 0; i < n; i++)
    {
        inserir(&A, vetor[i]);
        // inserirElemListaOrd(vetor[i], &l);
    }
    NO *p;
    inicializarArvore(&p);
    inserir(&p, 6);
    exibir(A);
    printf("\n");
    int maiores = 0;

    contarMaiores(A, p, &maiores);
    printf("\n");
    printf("%d ", maiores);
}
