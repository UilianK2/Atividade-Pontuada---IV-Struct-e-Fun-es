#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct ContaBancaria {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[20]; 
};


void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito de R$%.2f realizado com sucesso!\n", valor);
}

void sacar(struct ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso!\n", valor);
    } else {
        printf("Saldo insuficiente para saque.\n");
    }
}


void imprimirSaldo(struct ContaBancaria conta) {
    printf("Saldo atual: R$%.2f\n", conta.saldo);
}

int main() {
     setlocale(LC_ALL, "portuguese");
    struct ContaBancaria minhaConta;
    minhaConta.numeroConta = 123456;
    strcpy(minhaConta.nomeTitular, "Joao da Silva");
    minhaConta.saldo = 0;
    strcpy(minhaConta.tipoConta, "Corrente");

    int opcao;
    float valor;

    do {
        printf("\nMenu:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Ver saldo\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a depositar: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("Digite o valor a sacar: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                imprimirSaldo(minhaConta);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

