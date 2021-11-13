#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "arquivo.h"

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

    printf("Insira nota TRABALHO: ");
    scanf("%lf", &aluno[i].trab);

    printf("Insira nota PROVA OPTATIVA: ");
    scanf("%lf\n", &aluno[i].po);

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
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(aluno[min].nome, aluno[j].nome) > 0)
                min = j;
        }
        aux = aluno[i];
        aluno[i] = aluno[min];
        aluno[min] = aux;
    }
}

void calcularNota(Alunos *aluno, int n)
{
    for (int i = 0; i < n; i++)
    {
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
}

char *toLower(char *s)
{
    for (char *p = s; *p; p++)
        p = tolower(p);
    return s;
}

void buscarAluno(Alunos *aluno, int n){
    char nome[30];
    int cont;

    for (int i = 0; i < n; i++){
        char a = toLower(aluno[i].nome);
        char ab = toLower(nome);
        if(strstr(a, nome)!=0){
            printf("%s %.1f %s" ,aluno[i].nome, aluno[i].mf, aluno[i].statusAluno);
            cont++;
        }
    }
    if(cont == 0){
        printf("Aluno não encontrado.");
    } else{
        printf("Número de alunos buscados com sucesso: %d", cont);
    }
}


void gerarListaAp(Alunos *aluno, int n)
{
    ordenarAlunos(aluno, n);
    int result, count = 0;

    FILE *arquivo;
    arquivo = fopen("aprovados.txt", "w");

    for (int i = 0; i < n; i++)
    {
        result = strcmp(aluno[i].statusAluno, "Aprovado");
        if (result == 0)
        {
            fprintf(arquivo, "%s %s %5.1f\n", aluno[i].nome, aluno[i].rga, aluno[i].mf);
            count++;
        }
    }
    fprintf(arquivo, "Total: %d\n", count);
    fclose(arquivo);
}

void gerarListaRep(Alunos *aluno, int n)
{
    ordenarAlunos(aluno, n);
    int result, count = 0;

    FILE *arquivo;
    arquivo = fopen("reprovados.txt", "w");

    for (int i = 0; i < n; i++)
    {
        result = strcmp(aluno[i].statusAluno, "Reprovado");
        if (result == 0)
        {
            fprintf(arquivo, "%s %s %.1f\n", aluno[i].nome, aluno[i].rga, aluno[i].mf);
            count++;
        }
    }
    fprintf(arquivo, "Total: %d\n", count);
    fclose(arquivo);
}