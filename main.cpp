#include <stdio.h>
#include "arquivo.h"

int main()
{

    int op, n = 0;

    // Lista de alunos (structs)
    Alunos aluno[100];

    do
    {
        // Menu de opcoes
        printf("Digite a opção desejada:")
        printf("========= Menu ========\n");
        printf("1)- CADASTRAR ALUNO\n");
        printf("2)- BUSCAR ALUNO\n");                      // verificar
        printf("3)- LER ARQUIVO DE LISTAGEM DE ALUNOS\n"); // verificar
        printf("4)- GERAR LISTA APROVADO\n");
        printf("5)- GERAR LISTA REPROVADOS\n");
        printf("6)- FECHAR PROGRAMA\n"); // verificar
        printf("=======================\n")

        // Ler opção
        scanf("%d", &op);

        if (op == 1)
        {
            cadastrarAluno(aluno, n);
            n++;
        }
        else if (op == 2)
        {
            ordenarAlunos(aluno, n);
        }
        else if (op == 3)
        {
            n = lerArquivo(aluno, n);
        }
        else if (op == 4)
        {
            gerarListaAp(aluno, n);
        }
        else if (op == 5)
        {
            gerarListaRep(aluno, n);
        }
        else if (op == 6)
        {
            fecharPrograma(aluno, n);
        }
    } while (op != 6);
}