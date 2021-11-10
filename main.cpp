#include <stdio.h>
#include "Aluno.cpp"
#include "Arquivo.cpp"
#include "arquivo.h"

int main()
{

    int op, numAlunos = 0;

    // Lista de alunos (structs)
    Aluno alunos[100];

    do
    {
        // Menu de opcoes
        printf("----- Menu -----\n");
        printf("[1] CADASTRAR ALUNO\n");
        printf("[2] BUSCAR ALUNO\n"); // verificar
        printf("[3] LER ARQUIVO DE LISTAGEM DE ALUNOS\n"); // verificar
        printf("[4] GERAR LISTA APROVADO\n"); // verificar
        printf("[5] GERAR LISTA REPROVADOS\n"); // verificar
        printf("[6] FECHAR PROGRAMA\n"); //


        // Ler opção
        scanf("%d", &op);
        printf("\n");

        if (op == 1){
            cadastrarAluno();
            numAlunos++;
        } else if (op == 2){
            buscarAluno();
        } else if (op == 3){
            lerArquivo();
        } else if (op == 4){
            gerarListaAp();
        } else if (op == 5){
            gerarListaRep();
        } else if (op == 0){
            fecharPrograma();
        }
    }while(op !=0);
}