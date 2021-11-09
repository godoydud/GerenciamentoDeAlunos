#include <stdio.h>
#include "Aluno.cpp"
#include "Arquivo.cpp"

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
        printf("[2] BUSCAR ALUNO\n");
        printf("[3] LER ARQUIVO DE LISTAGEM DE ALUNOS\n");
        printf("[4] GERAR LISTA APROVADO\n");
        printf("[5] GERAR LISTA REPROVADOS\n");
        printf("[6] FECHAR PROGRAMA\n");


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