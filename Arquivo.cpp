#include <stdio.h>
#include <string.h>

void lerArquivo()
{
    FILE *arquivo;
    char nomearq[30];
    scanf(" %s", &nomearq);

    // Lendo o arquivo
    arquivo = fopen(nomearq, "r");

    if(arquivo == NULL){
        printf("Erro na abertura do arquivo");    // Testando pra ver se ta funcionando
    }
}

// void fecharPrograma()
// {
//     // chamada método de ordenação de alunos

//     // fopen para atual.txt

//     // impressao das informacoes (fprintf)

//     fclose(arquivo);
// }