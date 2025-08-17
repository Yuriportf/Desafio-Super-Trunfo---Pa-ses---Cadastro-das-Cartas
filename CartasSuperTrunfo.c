#include <stdio.h>

typedef struct {
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_pop;
    float pib_per_capita;
    float super_poder;
} Cidade;

void cadastrarCidade(Cidade *c) {
    printf("Código da carta (ex: A01): ");
    scanf("%s", c->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c->nome);
    printf("População: ");
    scanf("%d", &c->populacao);
    printf("Área (km²): ");
    scanf("%f", &c->area);
    printf("PIB (em bilhões): ");
    scanf("%f", &c->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);

    c->densidade_pop = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
    c->super_poder = c->populacao + c->area + c->pib + c->pontos_turisticos + c->pib_per_capita + (1/c->densidade_pop);
}

void exibirCidade(Cidade c) {
    printf("\n===== Carta %s =====\n", c.codigo);
    printf("Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade_pop);
    printf("PIB per capita: %.2f\n", c.pib_per_capita);
    printf("Super Poder: %.2f\n", c.super_poder);
}

void compararCartas(Cidade c1, Cidade c2) {
    printf("\n===== Comparação =====\n");

    printf("População: %s venceu\n", c1.populacao > c2.populacao ? c1.nome : c2.nome);
    printf("Área: %s venceu\n", c1.area > c2.area ? c1.nome : c2.nome);
    printf("PIB: %s venceu\n", c1.pib > c2.pib ? c1.nome : c2.nome);
    printf("Pontos Turísticos: %s venceu\n", c1.pontos_turisticos > c2.pontos_turisticos ? c1.nome : c2.nome);
    printf("Densidade Populacional: %s venceu\n", c1.densidade_pop < c2.densidade_pop ? c1.nome : c2.nome);
    printf("PIB per capita: %s venceu\n", c1.pib_per_capita > c2.pib_per_capita ? c1.nome : c2.nome);
    printf("Super Poder: %s venceu\n", c1.super_poder > c2.super_poder ? c1.nome : c2.nome);
}

int main() {
    Cidade c1, c2;

    printf("Cadastro da primeira carta:\n");
    cadastrarCidade(&c1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCidade(&c2);

    printf("\n===== Cartas Cadastradas =====\n");
    exibirCidade(c1);
    exibirCidade(c2);

    compararCartas(c1, c2);

    return 0;
}