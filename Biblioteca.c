#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 1000
#define MAX_USUARIOS 1000
#define MAX_EMPRESTIMOS 1000

typedef struct {
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
} Livro;

typedef struct {
    int id;
    char nome[100];
    char cpf[20];
} Usuario;

typedef struct {
    int idEmprestimo;
    int idUsuario;
    int codigoLivro;
    int devolvido;
} Emprestimo;

Livro livros[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];
Emprestimo emprestimos[MAX_EMPRESTIMOS];

int totalLivros = 0;
int totalUsuarios = 0;
int totalEmprestimos = 0;
int contadorEmprestimos = 1;

void salvarLivros() {
    FILE *f = fopen("livros.txt", "w");
    for (int i = 0; i < totalLivros; i++) {
        fprintf(f, "%d;%s;%s;%d\n", livros[i].codigo, livros[i].titulo, livros[i].autor, livros[i].ano);
    }
    fclose(f);
}

void salvarUsuarios() {
    FILE *f = fopen("usuarios.txt", "w");
    for (int i = 0; i < totalUsuarios; i++) {
        fprintf(f, "%d;%s;%s\n", usuarios[i].id, usuarios[i].nome, usuarios[i].cpf);
    }
    fclose(f);
}

void salvarEmprestimos() {
    FILE *f = fopen("emprestimos.txt", "w");
    for (int i = 0; i < totalEmprestimos; i++) {
        fprintf(f, "%d;%d;%d;%d\n", emprestimos[i].idEmprestimo, emprestimos[i].idUsuario, emprestimos[i].codigoLivro, emprestimos[i].devolvido);
    }
    fclose(f);
}

void carregarLivros() {
    FILE *f = fopen("livros.txt", "r");
    if (f == NULL) return;
    while (fscanf(f, "%d;%99[^;];%99[^;];%d\n", &livros[totalLivros].codigo, livros[totalLivros].titulo, livros[totalLivros].autor, &livros[totalLivros].ano) != EOF) {
        totalLivros++;
    }
    fclose(f);
}

void carregarUsuarios() {
    FILE *f = fopen("usuarios.txt", "r");
    if (f == NULL) return;
    while (fscanf(f, "%d;%99[^;];%19[^\n]\n", &usuarios[totalUsuarios].id, usuarios[totalUsuarios].nome, usuarios[totalUsuarios].cpf) != EOF) {
        totalUsuarios++;
    }
    fclose(f);
}

void carregarEmprestimos() {
    FILE *f = fopen("emprestimos.txt", "r");
    if (f == NULL) return;
    while (fscanf(f, "%d;%d;%d;%d\n", &emprestimos[totalEmprestimos].idEmprestimo, &emprestimos[totalEmprestimos].idUsuario, &emprestimos[totalEmprestimos].codigoLivro, &emprestimos[totalEmprestimos].devolvido) != EOF) {
        totalEmprestimos++;
    }
    fclose(f);
}

void cadastrarLivro() {
    printf("Codigo do livro: ");
    scanf("%d", &livros[totalLivros].codigo);
    printf("Titulo: ");
    getchar();
    fgets(livros[totalLivros].titulo, 100, stdin);
    strtok(livros[totalLivros].titulo, "\n");
    printf("Autor: ");
    fgets(livros[totalLivros].autor, 100, stdin);
    strtok(livros[totalLivros].autor, "\n");
    printf("Ano: ");
    scanf("%d", &livros[totalLivros].ano);
    totalLivros++;
    salvarLivros();
    printf("Livro cadastrado!\n");
}

void listarLivros() {
    printf("\n=== LISTA DE LIVROS ===\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("Codigo: %d | Titulo: %s | Autor: %s | Ano: %d\n",
               livros[i].codigo, livros[i].titulo, livros[i].autor, livros[i].ano);
    }
}

void cadastrarUsuario() {
    printf("ID do usuario: ");
    scanf("%d", &usuarios[totalUsuarios].id);
    printf("Nome: ");
    getchar();
    fgets(usuarios[totalUsuarios].nome, 100, stdin);
    strtok(usuarios[totalUsuarios].nome, "\n");
    printf("CPF: ");
    fgets(usuarios[totalUsuarios].cpf, 20, stdin);
    strtok(usuarios[totalUsuarios].cpf, "\n");
    totalUsuarios++;
    salvarUsuarios();
    printf("Usuario cadastrado!\n");
}

void listarUsuarios() {
    printf("\n=== LISTA DE USUARIOS ===\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d | Nome: %s | CPF: %s\n",
               usuarios[i].id, usuarios[i].nome, usuarios[i].cpf);
    }
}

void emprestarLivro() {
    int idUsuario, codigoLivro, encontradoLivro = 0, encontradoUsuario = 0;
    printf("ID do usuario: ");
    scanf("%d", &idUsuario);
    printf("Codigo do livro: ");
    scanf("%d", &codigoLivro);

    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == idUsuario) {
            encontradoUsuario = 1;
            break;
        }
    }

    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].codigo == codigoLivro) {
            encontradoLivro = 1;
            break;
        }
    }

    if (encontradoLivro && encontradoUsuario) {
        emprestimos[totalEmprestimos].idEmprestimo = contadorEmprestimos++;
        emprestimos[totalEmprestimos].idUsuario = idUsuario;
        emprestimos[totalEmprestimos].codigoLivro = codigoLivro;
        emprestimos[totalEmprestimos].devolvido = 0;
        totalEmprestimos++;
        salvarEmprestimos();
        printf("Emprestimo realizado!\n");
    } else {
        printf("Usuario ou livro nao encontrado.\n");
    }
}

void devolverLivro() {
    int idEmprestimo;
    printf("ID do emprestimo: ");
    scanf("%d", &idEmprestimo);

    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].idEmprestimo == idEmprestimo && emprestimos[i].devolvido == 0) {
            emprestimos[i].devolvido = 1;
            salvarEmprestimos();
            printf("Livro devolvido com sucesso!\n");
            return;
        }
    }
    printf("Emprestimo nao encontrado ou ja devolvido.\n");
}

void listarEmprestimos() {
    printf("\n=== LISTA DE EMPRESTIMOS ===\n");
    for (int i = 0; i < totalEmprestimos; i++) {
        printf("ID Emprestimo: %d | ID Usuario: %d | Codigo Livro: %d | Devolvido: %s\n",
               emprestimos[i].idEmprestimo, emprestimos[i].idUsuario,
               emprestimos[i].codigoLivro, emprestimos[i].devolvido ? "Sim" : "Nao");
    }
}

int main() {
    carregarLivros();
    carregarUsuarios();
    carregarEmprestimos();

    int opcao;

    do {
        printf("\n=== MENU BIBLIOTECA ===\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Cadastrar usuario\n");
        printf("4 - Listar usuarios\n");
        printf("5 - Realizar emprestimo\n");
        printf("6 - Devolver livro\n");
        printf("7 - Listar emprestimos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarLivro(); break;
            case 2: listarLivros(); break;
            case 3: cadastrarUsuario(); break;
            case 4: listarUsuarios(); break;
            case 5: emprestarLivro(); break;
            case 6: devolverLivro(); break;
            case 7: listarEmprestimos(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
