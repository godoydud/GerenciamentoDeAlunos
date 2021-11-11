struct Alunos
{
    char nome[30];
    char rga[10];
    double p1, p2, po, trab, mf, auxp1, auxp2;
    char statusAluno[15];
};

void ordenarAlunos(Alunos *aluno, int n);

void calcularNota(Alunos &aluno);

void cadastrarAluno(Alunos *aluno, int i);

// void buscarAluno(Alunos *alunos, int i);

int lerArquivo(Alunos *aluno, int n);

// void gerarListaAp(Alunos *alunos, int i);

// void gerarListaRep(Aluno *alunos, int i);

// void sair(Alunos *alunos, int i);