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

// Selection Sort por matrícula
void selectionSortMatricula(struct aluno *V, int N) {
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

// Selection Sort por nome
void selectionSortNome(struct aluno *V, int N) {
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

// Bubble Sort por matrícula
void bubbleSortMatricula(struct aluno *V, int N) {
    int i, j;
    struct aluno temp;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1 - i; j++) {
            if (V[j].matricula > V[j + 1].matricula) {
                temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }
}

// Bubble Sort por nome
void bubbleSortNome(struct aluno *V, int N) {
    int i, j;
    struct aluno temp;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1 - i; j++) {
            if (strcmp(V[j].nome, V[j + 1].nome) > 0) {
                temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }
}

void insertionSortMatricula(struct aluno *V, int N) {
	int i, j;
	struct aluno aux;
	for(i = 1; i < N; i++) {
		aux = V[i];
		for(j = i; (j > 0) && (aux.matricula < V[j - 1].matricula); j--)
			V[j] = V[j - 1]; V[j] = aux;
	}
}

void insertionSortNome(struct aluno *V, int N) {
    int i, j;
    struct aluno aux;
    for(i = 1; i < N; i++) {
        aux = V[i];
        for(j = i; (j > 0) && (strcmp(aux.nome, V[j - 1].nome) < 0); j--)
            V[j] = V[j - 1];
        V[j] = aux;
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

// Função main com exemplos
int main() {
    struct aluno turma[3] = {
        {456, "Bruno", 6.0, 5.5, 7.0},
        {123, "Ana", 7.5, 8.0, 9.0},
        {789, "Carlos", 8.0, 7.5, 6.5}
    };

    int pos;

    // Exemplo: ordenando com bubble sort por matrícula e buscando
    bubbleSortMatricula(turma, 3);
    pos = buscaBinariaMatricula(turma, 3, 123);
    if (pos != -1)
        printf("Aluno com matrícula 123 encontrado: %s\n", turma[pos].nome);
    else
        printf("Aluno com matrícula 123 não encontrado.\n");

    // Exemplo: ordenando com bubble sort por nome e buscando
    bubbleSortNome(turma, 3);
    pos = buscaBinariaNome(turma, 3, "Carlos");
    if (pos != -1)
        printf("Aluno chamado Carlos encontrado: %d\n", turma[pos].matricula);
    else
        printf("Aluno chamado Carlos não encontrado.\n");

    return 0;
}
