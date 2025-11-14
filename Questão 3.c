#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100

typedef struct {
    int numero;
    char nome[50];
    char cpf[15];
    char telefone[15];
    float saldo;
} Conta;

// (a) Função de busca
int buscarConta(Conta contas[], int total, int numero) {
    if (total == 0) return -1;
    for (int i = 0; i < total; i++) {
        if (contas[i].numero == numero)
            return i;
    }
    return -2;
}

// (b) Cadastrar nova conta
void cadastrarConta(Conta contas[], int *total, int numero) {
    int pos = buscarConta(contas, *total, numero);
    if (pos >= 0) {
        printf("Conta já cadastrada.\n");
        return;
    }

    if (*total >= MAX_CONTAS) {
        printf("Limite de contas atingido.\n");
        return;
    }

    contas[*total].numero = numero;
    printf("Nome: ");
    scanf(" %[^\n]", contas[*total].nome);
    printf("CPF: ");
    scanf(" %[^\n]", contas[*total].cpf);
    printf("Telefone: ");
    scanf(" %[^\n]", contas[*total].telefone);
    printf("Saldo inicial: ");
    scanf("%f", &contas[*total].saldo);
    (*total)++;
}

// (c) Consultar saldo
void consultarSaldo(Conta contas[], int total, int numero) {
    int pos = buscarConta(contas, total, numero);
    if (pos >= 0)
        printf("Saldo da conta %d: R$ %.2f\n", numero, contas[pos].saldo);
    else
        printf("Conta não encontrada.\n");
}

// (d) Fazer depósito
void depositar(Conta contas[], int total, int numero) {
    int pos = buscarConta(contas, total, numero);
    if (pos >= 0) {
        float valor;
        printf("Valor do depósito: ");
        scanf("%f", &valor);
        contas[pos].saldo += valor;
    } else {
        printf("Conta não encontrada.\n");
    }
}

// (e) Fazer saque
void sacar(Conta contas[], int total, int numero) {
    int pos = buscarConta(contas, total, numero);
    if (pos >= 0) {
        float valor;
        printf("Valor do saque: ");
        scanf("%f", &valor);
        if (valor <= contas[pos].saldo) {
            contas[pos].saldo -= valor;
        } else {
            printf("Saldo insuficiente.\n");
        }
    } else {
        printf("Conta não encontrada.\n");
    }
}

// (f) Exibir todas as contas
void exibirContas(Conta contas[], int total) {
    for (int i = 0; i < total; i++) {
        printf("Conta: %d | Nome: %s | Telefone: %s\n", contas[i].numero, contas[i].nome, contas[i].telefone);
    }
}

// Programa principal
int main() {
    Conta contas[MAX_CONTAS];
    int total = 0;

    // Exemplo de uso
    cadastrarConta(contas, &total, 1001);
    cadastrarConta(contas, &total, 1002);
    consultarSaldo(contas, total, 1001);
    depositar(contas, total, 1001);
    sacar(contas, total, 1002);
    exibirContas(contas, total);

    return 0;
}
