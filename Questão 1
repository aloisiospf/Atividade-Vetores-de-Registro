#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 26

typedef struct {
    char nome[30];
    int veiculos;
    int acidentes;
} Estado;

// (a) Coleta de dados
void coletarDados(Estado estados[]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        printf("Estado %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", estados[i].nome);
        printf("Número de veículos: ");
        scanf("%d", &estados[i].veiculos);
        printf("Número de acidentes: ");
        scanf("%d", &estados[i].acidentes);
    }
}

// (b) Maior e menor número de acidentes
void encontrarExtremos(Estado estados[], int *maior, int *menor) {
    *maior = *menor = 0;
    for (int i = 1; i < NUM_ESTADOS; i++) {
        if (estados[i].acidentes > estados[*maior].acidentes)
            *maior = i;
        if (estados[i].acidentes < estados[*menor].acidentes)
            *menor = i;
    }
}

// (c) Percentual de veículos envolvidos em acidentes
float percentualAcidentes(Estado estados[], int indice) {
    if (estados[indice].veiculos == 0) return 0.0;
    return (float)estados[indice].acidentes / estados[indice].veiculos * 100;
}

// (d) Média de acidentes no país
float mediaAcidentes(Estado estados[]) {
    int total = 0;
    for (int i = 0; i < NUM_ESTADOS; i++)
        total += estados[i].acidentes;
    return (float)total / NUM_ESTADOS;
}

// (e) Estados acima da média
void estadosAcimaMedia(Estado estados[], float media) {
    printf("Estados acima da média de acidentes:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        if (estados[i].acidentes > media)
            printf("%s\n", estados[i].nome);
    }
}

// Programa principal
int main() {
    Estado estados[NUM_ESTADOS];
    int maior, menor;

    coletarDados(estados);
    encontrarExtremos(estados, &maior, &menor);

    printf("\nMaior número de acidentes: %d (%s)\n", estados[maior].acidentes, estados[maior].nome);
    printf("Menor número de acidentes: %d (%s)\n", estados[menor].acidentes, estados[menor].nome);

    for (int i = 0; i < NUM_ESTADOS; i++) {
        float perc = percentualAcidentes(estados, i);
        printf("Percentual de acidentes em %s: %.2f%%\n", estados[i].nome, perc);
    }

    float media = mediaAcidentes(estados);
    printf("\nMédia de acidentes no país: %.2f\n", media);
    estadosAcimaMedia(estados, media);

    return 0;
}
