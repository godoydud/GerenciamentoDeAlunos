#include <stdio.h>
#include "Aluno.cpp"
#include "Arquivo.cpp"
#include "arquivo.h"

int main()
{

    int op, n = 0;

    // Lista de alunos (structs)
    Alunos aluno[100];

    do
    {
        // Menu de opcoes
        printf("----- Menu -----\n");
        printf("(1) CADASTRAR ALUNO\n");
        printf("(2) BUSCAR ALUNO\n");                      // verificar
        printf("(3) LER ARQUIVO DE LISTAGEM DE ALUNOS\n"); // verificar
        printf("(4) GERAR LISTA APROVADO\n");
        printf("(5) GERAR LISTA REPROVADOS\n");
        printf("(6) FECHAR PROGRAMA\n"); // verificar

        // Ler opção
        scanf("%d", &op);

        if (op == 1)
        {
            cadastrarAluno(aluno, n);
            n++;
        }
        else if (op == 2)
        {
            //buscaraluno
        }
        // else if (op == 3)
        // {
        //     lerArquivo();
        // }
        // else if (op == 4)
        // {
        //     gerarListaAp();
        // }
        // else if (op == 5)
        // {
        //     gerarListaRep();
        // }
        // else if (op == 0)
        // {
        //     fecharPrograma();
        // }
    } while (op != 0);
}