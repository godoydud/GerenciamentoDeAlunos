#include <stdio.h>
#include <string.h>
#include "arquivo.h"

int lerArquivo(Alunos *aluno, int n)
{
    int count = 0;
    FILE *arquivo;
    char nomearq[30];
    printf("Digite o nome do arquivo a ser buscado:");
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
    }

    return n+count;
}

// void fecharPrograma()
// {
//     // chamada método de ordenação de alunos

//     // fopen para atual.txt

//     // impressao das informacoes (fprintf)

//     fclose(arquivo);
// }