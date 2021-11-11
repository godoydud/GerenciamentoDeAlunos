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

    if (aluno[i].p1 < aluno[i].po && aluno[i].p1 < aluno[i].p2)
    {
        aluno[i].auxp1 = aluno[i].p1;
        aluno[i].p1 = aluno[i].po;
    }
    else if (aluno[i].p2 < aluno[i].po && aluno[i].p2 < aluno[i].p1)
    {
        aluno[i].auxp2 = aluno[i].p2;
        aluno[i].p2 = aluno[i].po;
    }
    aluno[i].mf = (0.35 * aluno[i].p1) + (0.35 * aluno[i].p2) + (0.3 * aluno[i].trab);

    if (aluno[i].mf >= 6)
    {
        // aluno aprovado
        strcpy(aluno[i].statusAluno, "Aprovado");
    }
    else
    {
        //aluno reprovado
        strcpy(aluno[i].statusAluno, "Reprovado");
    }
}



void ordenarAlunos(Alunos *aluno, int n)
{
    int i, j, min;
    Alunos aux;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n - 1; j++)
        {
            if (strcmp(aluno[min].nome, aluno[j].nome) < 0)
            {
                min = j;
            }
            // processo de troca
            aux = aluno[i];
            aluno[i] = aluno[min];
            aluno[min] = aux;
        }
    }

    //  int x, y, r;
    //  char aux[30];
    //  int len = sizeof(aluno) / sizeof(aluno[0]);
    //  for (x = 0; x <= len; x++){
    //      for (y = x+1; y <= len; y++){
    //          r = strcmp(aluno[x].nome, aluno[y].nome);
    //          if(r > 0){
    //              strcpy(aux, aluno[x].nome);
    //              strcpy(aluno[x].nome, aluno[y].nome);
    //              strcpy(aluno[y].nome, aux);
    //          }
    //      }
    //  }
    // printf("%d", len);
    // printf("Nomes ordenados\n");
    //  for(x = 0; x <= len; x++){
    //      puts(aluno[x].nome);
    //  }
}

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