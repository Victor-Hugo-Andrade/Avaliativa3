#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
    struct Produto* proximo;
} Produto;

Produto* inicializar() {
    return NULL;
}

Produto* adicionar(Produto* estoque) {
    Produto* novo = (Produto*) malloc(sizeof(Produto));
    printf("Digite o codigo do produto: ");
    scanf("%d", &novo->codigo);
    printf("Digite a descricao do produto: ");
    scanf("%s", novo->descricao);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novo->quantidade);
    printf("Digite o valor do produto: ");
    scanf("%f", &novo->valor);
    novo->proximo = estoque;
    return novo;
}

void relatorio(Produto* estoque) {
    if (estoque == NULL) {
        printf("A lista de estoque esta vazia.\n");
        return;
    }
    Produto* p;
    for (p = estoque; p != NULL; p = p->proximo) {
        printf("Codigo: %d, Descricao: %s, Quantidade: %d, Valor: %.2f\n", p->codigo, p->descricao, p->quantidade, p->valor);
    }
}

Produto* pesquisar(Produto* estoque, int codigo) {
    Produto* p;
    for (p = estoque; p != NULL; p = p->proximo) {
        if (p->codigo == codigo) {
            return p;
        }
    }
    return NULL;
}

Produto* remover(Produto* estoque, int codigo) {
    Produto* anterior = NULL;
    Produto* atual = estoque;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Produto nao cadastrado.\n");
        return estoque;
    }

    if (anterior == NULL) {
        estoque = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return estoque;
}

int main() {
    Produto* estoque = inicializar();
    int opcao, codigo;

    do {
        printf("1. Iniciar nova lista\n2. Adicionar produto\n3. Gerar relatorio\n4. Pesquisar produto\n5. Remover produto\n6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                estoque = inicializar();
                break;
            case 2:
                estoque = adicionar(estoque);
                break;
            case 3:
                relatorio(estoque);
                break;
            case 4:
                printf("Digite o codigo do produto a ser pesquisado: ");
                scanf("%d", &codigo);
                Produto* p = pesquisar(estoque, codigo);
                if (p != NULL) {
                    printf("Codigo: %d, Descricao: %s, Quantidade: %d, Valor: %.2f\n", p->codigo, p->descricao, p->quantidade, p->valor);
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;
            case 5:
                printf("Digite o codigo do produto a ser removido: ");
                scanf("%d", &codigo);
                estoque = remover(estoque, codigo);
                break;
        }
    } while (opcao != 6);

    return 0;
}
