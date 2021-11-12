#include <stdio.h>
#include <string.h>
#include "arquivo.h"

int lerArquivo(Alunos *aluno, int n)
{
    int count = 0;
    FILE *arquivo;
    char nomearq[30];
    printf("Digite o nome do arquivo a ser lido:");
    scanf(" %s", &nomearq);

    // Lendo o arquivo
    arquivo = fopen(nomearq, "r");

    if(arquivo == NULL){
        printf("\nErro na abertura do arquivo");    // Testando pra ver se ta funcionando
    }
    else{
        for(int i=n; feof(arquivo) == 0; i++, count++){
            fscanf(arquivo, " %[^1234567890] %s %lf %lf %lf %lf ", aluno[i].nome, aluno[i].rga, &aluno[i].p1, &aluno[i].p2, &aluno[i].trab, &aluno[i].po);
        }
        printf("Alunos lidos: %d\n", count);
        fclose(arquivo);
    }

    return n+count;
}

void fecharPrograma(Alunos *aluno, int n)
{
    // chamada método de ordenação de alunos
    ordenarAlunos(aluno, n);

    // fopen para atual.txt
    FILE *arquivo;
    arquivo = fopen("atual.txt", "w");

    // impressao das informacoes (fprintf)
    for(int i=0; i<n; i++){
        fprintf(arquivo, "%s %s %.1f %.1f %.1f %.1f\n", aluno[i].nome, aluno[i].rga, aluno[i].p1, aluno[i].p2, aluno[i].trab, aluno[i].po);
    }

    fclose(arquivo);
}