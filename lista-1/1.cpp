#include<bits/stdc++.h>
#define TAM 1000


typedef struct {
    char nome[80];
    char genero[40];
    float precoUnitario;
    int qtde;
}ListaCompras;

ListaCompras lista[TAM];
int qtde = 0;

void criaLista() {
    qtde = 0;
    for(int i = 0; i < TAM; i++) lista[i].qtde = -1;
}

bool isVazia() {
    return qtde == 0;
}

bool isCheia() {
    return qtde == TAM;
}

bool insere(int pos) {
    if(isCheia()) return false;
    if(pos < qtde) {
        for(int i = TAM - 1; i > pos; i--) {
            lista[i] = lista[i-1];
        }
    }
    else if(pos > qtde) pos = qtde;
    scanf(" %s %s %f %d", 
        lista[pos].nome,
        lista[pos].genero,
        &lista[pos].precoUnitario,
        &lista[pos].qtde);
    qtde++;
    return true
}

bool retira(int pos) {
    if(isVazia()) return false;
    if(lista[pos].qtde != -1) {
        for(int i = pos; i < TAM - 1; i++) {
            lista[i] = lista[i+1];
        }
    }
    lista[TAM - 1].qtde = -1;
    return true;
}

void imprimeItem(ListaCompras item) {
    printf("\n-----------------");
    printf("Nome: %s \n", item.nome);
    printf("Tipo: %s \n", item.genero);
    printf("Preco unitario: %.2f \n", item.precoUnitario);
    printf("Qtde: %d \n", item.qtde);
    printf("-----------------\n");
}

void imprimeLista() {
    for(int i = 0; i < qtde; i++){
        imprimeItem(lista[i]);
    }
}