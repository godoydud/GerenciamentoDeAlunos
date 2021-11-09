#include <stdio.h>

struct Aluno{
    char nome[30];
    char rga[10];
    double p1, p2, po, trab, mf;
    char statusAluno[15];
};

void cadastrarAluno(Aluno alunos){
    printf("Insira nome do aluno: ")
    scanf("%[^\n]", &alunos[i].nome);

    printf("Insira RGA do aluno: ");
    scanf("%[^\n]", &alunos[i].rga);

    printf("Insira nota PROVA 01: ");
    scanf("%lf\n", &alunos[i].p1);

    printf("Insira nota PROVA 02: ");
    scanf("%lf\n", &alunos[i].p2);

    printf("Insira nota PROVA OPTATIVA: ");
    scanf("%lf\n", &alunos[i].po);

    printf("Insira nota TRABALHO: ");
    scanf("%lf\n", &alunos[i].trab);
}

void calcularNota(){

}

void ordenarAlunos(){

}

void buscarAluno(){

}

void gerarListaAp(){

}

void gerarListaRep(){

}