struct Alunos
{
    char nome[30];
    char rga[15];
    double p1, p2, po, trab, mf, auxp1, auxp2;
    char statusAluno[15];
};

void ordenarAlunos(Alunos *aluno, int n);

void calcularNota(Alunos *aluno, int n);

void cadastrarAluno(Alunos *aluno, int i);

// void buscarAluno(Alunos *alunos, int i);

int lerArquivo(Alunos *aluno, int n);

void gerarListaAp(Alunos *aluno, int n);

void gerarListaRep(Alunos *aluno, int n);

void fecharPrograma(Alunos *aluno, int n);