#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "arquivo.h"

void cadastrarAluno(Alunos *aluno, int n)
{
    printf("\nInsira nome do aluno: ");
    scanf(" %[^\n]", aluno[n].nome);

    printf("Insira RGA do aluno: ");
    scanf(" %[^\n]", aluno[n].rga);

    printf("Insira nota PROVA 01: ");
    scanf("%lf", &aluno[n].p1);

    printf("Insira nota PROVA 02: ");
    scanf("%lf", &aluno[n].p2);

    printf("Insira nota TRABALHO: ");
    scanf("%lf", &aluno[n].trab);

    printf("Insira nota PROVA OPTATIVA: ");
    scanf("%lf\n", &aluno[n].po);

    if (aluno[n].p1 < aluno[n].po && aluno[n].p1 < aluno[n].p2)
    {
        aluno[n].auxp1 = aluno[n].p1;
        aluno[n].p1 = aluno[n].po;
    }
    else if (aluno[n].p2 < aluno[n].po && aluno[n].p2 < aluno[n].p1)
    {
        aluno[n].auxp2 = aluno[n].p2;
        aluno[n].p2 = aluno[n].po;
    }
    aluno[n].mf = (0.35 * aluno[n].p1) + (0.35 * aluno[n].p2) + (0.3 * aluno[n].trab);

    if (aluno[n].mf >= 6)
    {
        strcpy(aluno[n].statusAluno, "Aprovado");
    }
    else
    {
        strcpy(aluno[n].statusAluno, "Reprovado");
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
            else if(strcmp(aluno[min].nome, aluno[j].nome) == 0){
                if(aluno[min].rga < aluno[j].rga){
                    min = j;
                }
            }
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

char* tornarMin(char* c)
{
    for (int i = 0; i < strlen(c); i++)
        c[i] = tolower(c[i]);
    
    return c;
}

void buscarAluno(Alunos *aluno, int n, char* procurado){
    int count = 0;
    Alunos alunoAux[100];
    igualar(aluno, alunoAux, n);

    for (int i = 0; i < n; i++){
        char* nomeMin = tornarMin(alunoAux[i].nome);
        char* procuradoMin = tornarMin(procurado);

        if(strstr(nomeMin, procuradoMin) != 0){
            printf("%s %.1f %s\n",aluno[i].nome, aluno[i].mf, aluno[i].statusAluno);
            count++;
        }
    }
    if(count != 0){
        printf("Alunos encontrados: %d\n", count);
    } else{
        printf("Nenhum aluno encontrado.\n");
    }
}

void igualar(Alunos *aluno, Alunos *alunoAux, int n){
    for(int i=0; i<n; i++){
        alunoAux[i] = aluno[i]; 
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
            fprintf(arquivo, "%-30s %-15s %5.1f\n", aluno[i].nome, aluno[i].rga, aluno[i].mf);
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
            fprintf(arquivo, "%-30s %-15s %5.1f\n", aluno[i].nome, aluno[i].rga, aluno[i].mf);
            count++;
        }
    }
    fprintf(arquivo, "Total: %d\n", count);
    fclose(arquivo);
}