#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

float calcularValorTotal(Produto produto) {
    return produto.preco * produto.quantidade;
}

Produto realizarCompra(Produto produto, int quantidade) {
    if (produto.quantidade >= quantidade) {
        produto.quantidade -= quantidade;
        printf("Compra feita!\n");
    } else {
        printf("Não temos em estoque!\n");
    }
    return produto;
}

int main() {
    setlocale(LC_ALL,"");
    Produto produto;

    printf("Digite o nome do produto: ");
    scanf("%s", produto.nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &produto.preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto.quantidade);

    int opcao;
    do {
        printf("Escolha uma opção: \n");
        printf("\n1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantos produtos voce deseja comprar? ");
                int quantidade;
                scanf("%d", &quantidade);
                produto = realizarCompra(produto, quantidade);
                break;
            case 2:
                printf("Quantidade em estoque: %d\n", produto.quantidade);
                printf("Valor total em estoque: %.2f\n", calcularValorTotal(produto));
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}

