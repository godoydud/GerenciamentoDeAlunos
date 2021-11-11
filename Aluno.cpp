#include <stdio.h>
#include <string.h>

struct Alunos
{
    char nome[30];
    char rga[10];
    double p1, p2, po, trab, mf, auxp1, auxp2;
    char statusAluno[15];
};

void cadastrarAluno(Alunos *aluno, int i)
{
    printf("Insira nome do aluno: ");
    scanf(" %[^\n]", aluno[i].nome);

    printf("Insira RGA do aluno: ");
    scanf(" %[^\n]", aluno[i].rga);

    printf("Insira nota PROVA 01: ");
    scanf("%lf", &aluno[i].p1);

    printf("Insira nota PROVA 02: ");
    scanf("%lf", &aluno[i].p2);

    printf("Insira nota PROVA OPTATIVA: ");
    scanf("%lf", &aluno[i].po);

    printf("Insira nota TRABALHO: ");
    scanf("%lf", &aluno[i].trab);

    
}

void calcularNota(Alunos &aluno)
{
    if (aluno.p1 < aluno.po && aluno.p1 < aluno.p2)
    {
        aluno.auxp1 = aluno.p1;
        aluno.p1 = aluno.po;
    }
    else if (aluno.p2 < aluno.po && aluno.p2 < aluno.p1)
    {
        aluno.auxp2 = aluno.p2;
        aluno.p2 = aluno.po;
    }
    aluno.mf = (0.35 * aluno.p1) + (0.35 * aluno.p2) + (0.3 * aluno.trab);

    if (aluno.mf >= 6)
    {
        // aluno aprovado
        strcpy(aluno.statusAluno, "Aprovado");
    }
    else
    {
        //aluno reprovado
        strcpy(aluno.statusAluno, "Reprovado");
    }
    
}

// void ordenarAlunos(Alunos *aluno, int n)
// {
//     int menor, aux = 0;
//    // int len = sizeof(aluno) / sizeof(aluno[0]);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (strcmp(aluno[i].nome, aluno[j].nome > 0 *))
//             {
//                 menor = aluno[j];
//             }
//         }
//         if (i !=menor)
//         {
//             aux = aluno[i];
//             aluno[i] = aluno[menor];
//             aluno[menor] = aux;
//         }
//     }
//     printf("%s, média final: %.1f, situação: %s\n", aluno[i].nome, aluno[i].mf, aluno[i].statusAluno);
// }

// void buscarAluno()
// {
// }

// void gerarListaAp(Alunos *aluno)
// {
//     ordenarAlunos(aluno);
//     int len = sizeof(aluno) / sizeof(aluno[0]);
//     int r, count = 0;

//     FILE *arquivo;

//     arquivo = fopen("aprovados.txt", "w");

//     for (int i = 0; i < aluno.lenght; i++)
//     {
//         r = strcmp(aluno[i].statusAluno, "Aprovado") if (r == 0)
//         {
//             fprintf("%s, %s, %f", aluno[i].nome, aluno[i].rga, aluno[i].mf);
//             count++;
//         }
//     }
//     fprintf(arquivo, "\nTotal: %d", count);
//     fclose(arquivo);
// }

// void gerarListaRep(Alunos *aluno)
// {
//     ordenarAlunos(aluno);
//     int len = sizeof(aluno) / sizeof(aluno[0]);
//     int r, count = 0;
//     FILE *arquivo;

//     arquivo = fopen("reprovados.txt", "w");

//     for (int i = 0; i < len; i++)
//     {
//         r = strcmp(aluno[i].statusAluno, "Reprovado") if (r == 0)
//         {
//             fprintf(arquivo, "%s, %s, %f", aluno[i].nome, aluno[i].rga, aluno[i].mf);
//             count++;
//         }
//     }
//     fprintf(arquivo, "\nTotal: %d", count);
//     fclose(arquivo);
// }