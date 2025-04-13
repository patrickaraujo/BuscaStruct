#include <stdio.h>
#include <string.h>

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

// Busca Linear em vetor de inteiros
int buscaLinear(int *V, int N, int elem) {
    for (int i = 0; i < N; i++) {
        if (elem == V[i])
            return i;
    }
    return -1;
}

// Busca Linear por matrícula
int buscaLinearMatricula(struct aluno *V, int N, int elem) {
    for (int i = 0; i < N; i++) {
        if (elem == V[i].matricula)
            return i;
    }
    return -1;
}

// Busca Linear por nome
int buscaLinearNome(struct aluno *V, int N, char *elem) {
    for (int i = 0; i < N; i++) {
        if (strcmp(elem, V[i].nome) == 0)
            return i;
    }
    return -1;
}

// Ordenação por matrícula (Selection Sort)
void ordenaPorMatricula(struct aluno *V, int N) {
    int i, j, menor;
    struct aluno troca;

    for (i = 0; i < N - 1; i++) {
        menor = i;
        for (j = i + 1; j < N; j++) {
            if (V[j].matricula < V[menor].matricula)
                menor = j;
        }
        if (i != menor) {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

// Ordenação por nome (Selection Sort)
void ordenaPorNome(struct aluno *V, int N) {
    int i, j, menor;
    struct aluno troca;

    for (i = 0; i < N - 1; i++) {
        menor = i;
        for (j = i + 1; j < N; j++) {
            if (strcmp(V[j].nome, V[menor].nome) < 0)
                menor = j;
        }
        if (i != menor) {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

// Busca Binária por matrícula
int buscaBinariaMatricula(struct aluno *V, int N, int elem) {
    int ini = 0, fim = N - 1, meio;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (elem == V[meio].matricula)
            return meio;
        else if (elem < V[meio].matricula)
            fim = meio - 1;
        else
            ini = meio + 1;
    }
    return -1;
}

// Busca Binária por nome
int buscaBinariaNome(struct aluno *V, int N, char *elem) {
    int ini = 0, fim = N - 1, meio;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        int cmp = strcmp(elem, V[meio].nome);
        if (cmp == 0)
            return meio;
        else if (cmp < 0)
            fim = meio - 1;
        else
            ini = meio + 1;
    }
    return -1;
}

// Exemplo de uso
int main() {
    struct aluno turma[3] = {
        {456, "Bruno", 6.0, 5.5, 7.0},
        {123, "Ana", 7.5, 8.0, 9.0},
        {789, "Carlos", 8.0, 7.5, 6.5}
    };

    int pos;

    // Ordena por matrícula e realiza busca binária
    ordenaPorMatricula(turma, 3);
    pos = buscaBinariaMatricula(turma, 3, 123);
    if (pos != -1)
        printf("Aluno com matricula 123 encontrado: %s\n", turma[pos].nome);
    else
        printf("Aluno com matricula 123 não encontrado.\n");

    // Ordena por nome e realiza busca binária
    ordenaPorNome(turma, 3);
    pos = buscaBinariaNome(turma, 3, "Carlos");
    if (pos != -1)
        printf("Aluno chamado Carlos encontrado: %d\n", turma[pos].matricula);
    else
        printf("Aluno chamado Carlos não encontrado.\n");

    return 0;
}
