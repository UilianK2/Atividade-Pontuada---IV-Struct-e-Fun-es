#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
    char email[50];
};

struct Contato contatos[3];

char* buscarTelefone(char* nome) {
	int i;
    for(i= 0; i < 3; i++) {
        if(strcmp(contatos[i].nome, nome) == 0) {
            return contatos[i].telefone;
        }
    }
   // return NULL;
   printf("Contato nao encontrado");
}

int main() {
    for(int i = 0; i < 3; i++) {
        printf("Digite o nome do contato %d: ", i+1);
        scanf("%s", contatos[i].nome);
        printf("Digite o telefone do contato %d: ", i+1);
        scanf("%s", contatos[i].telefone);
        printf("Digite o email do contato %d: ", i+1);
        scanf("%s", contatos[i].email);
    }

    char nome[50];
    printf("Digite o nome do contato que deseja buscar: ");
    scanf("%s", nome);

    char* telefone = buscarTelefone(nome);
    if(telefone != NULL) {
        printf("O telefone do contato %s é %s\n", nome, telefone);
    } else {
        printf("Contato não encontrado.\n");
    }

    return 0;
}

