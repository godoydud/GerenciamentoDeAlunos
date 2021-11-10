#include <stdio.h>
#include <string.h>

struct Alunos{
    char nome[30];
    char rga[10];
    double p1, p2, po, trab, mf, auxp1, auxp2;
    char statusAluno[15];
};

void cadastrarAluno(Alunos aluno){
    printf("Insira nome do aluno: ")
    scanf("%[^\n]", &aluno[i].nome);

    printf("Insira RGA do aluno: ");
    scanf("%[^\n]", &aluno[i].rga);

    printf("Insira nota PROVA 01: ");
    scanf("%lf\n", &aluno[i].p1);

    printf("Insira nota PROVA 02: ");
    scanf("%lf\n", &aluno[i].p2);

    printf("Insira nota PROVA OPTATIVA: ");
    scanf("%lf\n", &aluno[i].po);

    printf("Insira nota TRABALHO: ");
    scanf("%lf\n", &aluno[i].trab);

    calcularNota(aluno[i]);
}

void calcularNota(Alunos &aluno){
    if(aluno.p1 < aluno.po && aluno.p1 < aluno.p2){    
        aluno.auxp1 = aluno.p1;
        aluno.p1 = aluno.po;
    } else if(aluno.p2 < aluno.po && aluno.p2 < aluno.p1){
        aluno.auxp2 = aluno.p2;
        aluno.p2 = aluno.po;
    }
     aluno.mf = (0.35 * aluno.p1) + (0.35 * aluno.p2) + (0.3 * aluno.trab);

    if(aluno.mf >= 6){
        // aluno aprovado
        strcpy(aluno.status, "Aprovado");
    } else {
        //aluno reprovado
        strcpy(aluno.status, "Reprovado");
    }
}

void ordenarAlunos(){

}

void buscarAluno(){

}

void gerarListaAp(){

}

void gerarListaRep(){

}