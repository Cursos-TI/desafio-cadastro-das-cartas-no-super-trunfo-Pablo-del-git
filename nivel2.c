#include <stdio.h>

typedef struct {
    char codigo[4];
    char nome[50];  
    int populacao;  
    float area;     
    float pib;      
    int pontos_turisticos; 
    float densidade_populacional; 
    float pib_per_capita;         
} Cidade;

void calcularAtributos(Cidade *cidade) {
    if (cidade->area > 0) {
        cidade->densidade_populacional = cidade->populacao / cidade->area;
    } else {
        cidade->densidade_populacional = 0; 
    }
    
    if (cidade->populacao > 0) {
        cidade->pib_per_capita = cidade->pib / cidade->populacao;
    } else {
        cidade->pib_per_capita = 0; 
    }
}

int main() {
    Cidade cidade1, cidade2;

    printf("Cadastro da primeira cidade:\n");
    printf("Digite o código da cidade (ex: A01): ");
    scanf("%s", cidade1.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %s[^\n]", cidade1.nome);
    printf("Digite a população: ");
    scanf("%d", &cidade1.populacao);
    printf("Digite a área: ");
    scanf("%f", &cidade1.area);
    printf("Digite o PIB: ");
    scanf("%f", &cidade1.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade1.pontos_turisticos);

    
    calcularAtributos(&cidade1);

    printf("\nCadastro da segunda cidade:\n");
    printf("Digite o código da cidade (ex: B02): ");
    scanf("%s", cidade2.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %s[^\n]", cidade2.nome);
    printf("Digite a população: ");
    scanf("%d", &cidade2.populacao);
    printf("Digite a área: ");
    scanf("%f", &cidade2.area);
    printf("Digite o PIB: ");
    scanf("%f", &cidade2.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade2.pontos_turisticos);

    
    calcularAtributos(&cidade2);

    printf("\nDados da primeira cidade:\n");
    printf("Código: %s\n", cidade1.codigo);
    printf("Nome: %s\n", cidade1.nome);
    printf("População: %d\n", cidade1.populacao);
    printf("Área: %.2f\n", cidade1.area);
    printf("PIB: %.2f\n", cidade1.pib);
    printf("Pontos turísticos: %d\n", cidade1.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", cidade1.densidade_populacional);
    printf("PIB per Capita: %.2f\n", cidade1.pib_per_capita);

    printf("\nDados da segunda cidade:\n");
    printf("Código: %s\n", cidade2.codigo);
    printf("Nome: %s\n", cidade2.nome);
    printf("População: %d\n", cidade2.populacao);
    printf("Área: %.2f\n", cidade2.area);
    printf("PIB: %.2f\n", cidade2.pib);
    printf("Pontos turísticos: %d\n", cidade2.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", cidade2.densidade_populacional);
    printf("PIB per Capita: %.2f\n", cidade2.pib_per_capita);

    return 0;
}