#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno *esquerdo;
    struct Aluno *direito;
} Aluno;

Aluno* criarAluno(const char* nome, int matricula, float nota) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    if (novoAluno == NULL) {
        printf("Falha na alocacao de memoria para Aluno.\n");
        return NULL;
    }
    strcpy(novoAluno->nome, nome);
    novoAluno->matricula = matricula;
    novoAluno->nota = nota;
    novoAluno->esquerdo = NULL;
    novoAluno->direito = NULL;
    return novoAluno;
}

Aluno* inserirAluno(Aluno* raiz, const char* nome, int matricula, float nota) {
    if (raiz == NULL) {
        return criarAluno(nome, matricula, nota);
    }
    if (matricula < raiz->matricula) {
        raiz->esquerdo = inserirAluno(raiz->esquerdo, nome, matricula, nota);
    } else if (matricula > raiz->matricula) {
        raiz->direito = inserirAluno(raiz->direito, nome, matricula, nota);
    } else {
        printf("Matricula %d (Aluno %s) ja existe na arvore. Nao sera inserido novamente.\n", matricula, nome);
    }
    return raiz;
}

Aluno* buscarAlunoPorNome(Aluno* raiz, const char* nomeBuscado) {
    if (raiz == NULL) {
        return NULL;
    }
    if (strcmp(raiz->nome, nomeBuscado) == 0) {
        return raiz;
    }
    Aluno* encontradoEsquerda = buscarAlunoPorNome(raiz->esquerdo, nomeBuscado);
    if (encontradoEsquerda != NULL) {
        return encontradoEsquerda;
    }
    Aluno* encontradoDireita = buscarAlunoPorNome(raiz->direito, nomeBuscado);
    if (encontradoDireita != NULL) {
        return encontradoDireita;
    }
    return NULL;
}

int contarAlunos(Aluno* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + contarAlunos(raiz->esquerdo) + contarAlunos(raiz->direito);
    }
}


float somarNotasAlunos(Aluno* raiz) {
    if (raiz == NULL) {
        return 0.0f;
    } else {
        return raiz->nota + somarNotasAlunos(raiz->esquerdo) + somarNotasAlunos(raiz->direito);
    }
}

float calcularMediaNotas(Aluno* raiz) {
    float somaTotalNotas = somarNotasAlunos(raiz);
    int totalAlunos = contarAlunos(raiz);
    if (totalAlunos == 0) {
        return 0.0f;
    } else {
        return somaTotalNotas / totalAlunos;
    }
}







int main() {
    Aluno* arvoreAlunos = NULL;

    arvoreAlunos = inserirAluno(arvoreAlunos, "Joao Silva", 101, 7.5);
    arvoreAlunos = inserirAluno(arvoreAlunos, "Maria Souza", 105, 9.0);
    arvoreAlunos = inserirAluno(arvoreAlunos, "Carlos Lima", 103, 6.0);
    arvoreAlunos = inserirAluno(arvoreAlunos, "Ana Paula", 100, 8.5);
    arvoreAlunos = inserirAluno(arvoreAlunos, "Pedro Gomes", 102, 7.0);
    arvoreAlunos = inserirAluno(arvoreAlunos, "Laura Santos", 104, 9.5);
    arvoreAlunos = inserirAluno(arvoreAlunos, "Fernando Alves", 106, 5.0);


    return 0;
}





    

