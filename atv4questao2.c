#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[50];
    char dataNascimento[250];
    float nota1;
    float nota2;
    float media;
} Aluno;

float calcularMedia(Aluno aluno) {
    aluno.media = (aluno.nota1 + aluno.nota2) / 2;
    return aluno.media;
}

char* verificarAprovacao(Aluno aluno) {
    if (calcularMedia(aluno) >= 7.0) {
        return "Aprovado";
    } else {
        return "Reprovado";
    }
}

int main() {
      setlocale(LC_ALL, "");

    Aluno alunos[2];
    int i;
    for (i = 0; i < 2; i++) {
        printf("\nDigite o nome do %dº aluno: \n", i+1);
        scanf("%s", alunos[i].nome);
        printf("Digite a data de nascimento do %dº aluno: \n",i+1);
        scanf("%s", alunos[i].dataNascimento);
        printf("Digite a primeira nota do aluno: \n");
        scanf("%f", &alunos[i].nota1);
        printf("Digite a segunda nota do aluno: \n");
        scanf("%f", &alunos[i].nota2);

        printf("\nMedia do aluno %s: %.2f\n", alunos[i].nome, calcularMedia(alunos[i]));
        printf("O aluno esta %s\n", verificarAprovacao(alunos[i]));
    }

    return 0;
}
