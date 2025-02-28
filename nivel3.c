#include <stdio.h>

typedef struct {
    char codigo[4];
    char nome[50];  
    unsigned long int populacao;  
    float area;     
    float pib;      
    int pontos_turisticos; 
    float densidade_populacional; 
    float pib_per_capita;         
} Cidade;

void calcularAtributos(Cidade *cidade) {
    cidade->densidade_populacional = (cidade->area > 0) ? (cidade->populacao / cidade->area) : 0;
    cidade->pib_per_capita = (cidade->populacao > 0) ? (cidade->pib / cidade->populacao) : 0;
}

void compararCidades(Cidade cidade1, Cidade cidade2) {
    printf("\nComparação de Atributos:\n");
    printf("Densidade Populacional: %s vence (%.2f < %.2f)\n", 
           (cidade1.densidade_populacional < cidade2.densidade_populacional) ? "Cidade 1" : "Cidade 2", 
           cidade1.densidade_populacional, cidade2.densidade_populacional);
    printf("População: %s vence (%lu > %lu)\n", 
           (cidade1.populacao > cidade2.populacao) ? "Cidade 1" : "Cidade 2", 
           cidade1.populacao, cidade2.populacao);
    printf("Área: %s vence (%.2f > %.2f)\n", 
           (cidade1.area > cidade2.area) ? "Cidade 1" : "Cidade 2", 
           cidade1.area, cidade2.area);
    printf("PIB: %s vence (%.2f > %.2f)\n", 
           (cidade1.pib > cidade2.pib) ? "Cidade 1" : "Cidade 2", 
           cidade1.pib, cidade2.pib);
    printf("Pontos Turísticos: %s vence (%d > %d)\n", 
           (cidade1.pontos_turisticos > cidade2.pontos_turisticos) ? "Cidade 1" : "Cidade 2", 
           cidade1.pontos_turisticos, cidade2.pontos_turisticos);
}

float calcularSuperPoder(Cidade cidade) {
    float densidade_invertida = (cidade.densidade_populacional > 0) ? (1.0 / cidade.densidade_populacional) : 0;
    return cidade.populacao + cidade.area + cidade.pib + cidade.pontos_turisticos + densidade_invertida + cidade.pib_per_capita;
}

int main() {
    Cidade cidade1, cidade2;

    // Cadastro da primeira cidade
    printf("Cadastro da primeira cidade:\n");
    printf("Digite o código da cidade: ");
    scanf("%s", cidade1.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %s[^\n]", cidade1.nome);
    printf("Digite a população: ");
    scanf("%lu", &cidade1.populacao);
    printf("Digite a área: ");
    scanf("%f", &cidade1.area);
    printf("Digite o PIB: ");
    scanf("%f", &cidade1.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade1.pontos_turisticos);
    calcularAtributos(&cidade1);

    // Cadastro da segunda cidade
    printf("\nCadastro da segunda cidade:\n");
    printf("Digite o código da cidade: ");
    scanf("%s", cidade2.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %s[^\n]", cidade2.nome);
    printf("Digite a população: ");
    scanf("%lu", &cidade2.populacao);
    printf("Digite a área: ");
    scanf("%f", &cidade2.area);
    printf("Digite o PIB: ");
    scanf("%f", &cidade2.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade2.pontos_turisticos);
    calcularAtributos(&cidade2);

    // Comparação e Super Poder
    compararCidades(cidade1, cidade2);
    printf("\nSuper Poder Cidade 1: %.2f\n", calcularSuperPoder(cidade1));
    printf("Super Poder Cidade 2: %.2f\n", calcularSuperPoder(cidade2));

    return 0;
}