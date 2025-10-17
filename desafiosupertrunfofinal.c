#include <stdio.h>
#include <string.h>

struct Carta {
    char estado;               // Apenas uma letra (A-H)
    char codigo[5];            // Ex: "A01"
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para cadastrar os dados de uma carta
void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);  // espaço antes de %c ignora o Enter anterior

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->cidade); // lê nomes com espaços

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área em km²: ");
    scanf("%f", &carta->area);

    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para mostrar os dados de uma carta
void mostrarCarta(struct Carta carta, int numero) {
    printf("\n=== Dados da Carta %d ===\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
}

// Função para calcular densidade populacional
float densidade(struct Carta carta) {
    if (carta.area == 0) return 0; // evita divisão por zero ✅
    return carta.populacao / carta.area;
}

// Função para comparar cartas baseado em um atributo escolhido
void comparar(struct Carta c1, struct Carta c2, int opcao) {
    printf("\n=== Comparação de Cartas ===\n");
    printf("Cidade 1: %s\n", c1.cidade);
    printf("Cidade 2: %s\n", c2.cidade);

    switch (opcao) {
        case 1: // População
            printf("\nAtributo: População\n");
            printf("%s: %d\n", c1.cidade, c1.populacao);
            printf("%s: %d\n", c2.cidade, c2.populacao);
            if (c1.populacao > c2.populacao) printf("Vencedor: %s\n", c1.cidade);
            else if (c1.populacao < c2.populacao) printf("Vencedor: %s\n", c2.cidade);
            else printf("Empate!\n");
            break;

        case 2: // Área
            printf("\nAtributo: Área\n");
            printf("%s: %.2f km²\n", c1.cidade, c1.area);
            printf("%s: %.2f km²\n", c2.cidade, c2.area);
            if (c1.area > c2.area) printf("Vencedor: %s\n", c1.cidade);
            else if (c1.area < c2.area) printf("Vencedor: %s\n", c2.cidade);
            else printf("Empate!\n");
            break;

        case 3: // PIB
            printf("\nAtributo: PIB\n");
            printf("%s: %.2f\n", c1.cidade, c1.pib);
            printf("%s: %.2f\n", c2.cidade, c2.pib);
            if (c1.pib > c2.pib) printf("Vencedor: %s\n", c1.cidade);
            else if (c1.pib < c2.pib) printf("Vencedor: %s\n", c2.cidade);
            else printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("\nAtributo: Pontos Turísticos\n");
            printf("%s: %d\n", c1.cidade, c1.pontosTuristicos);
            printf("%s: %d\n", c2.cidade, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos) printf("Vencedor: %s\n", c1.cidade);
            else if (c1.pontosTuristicos < c2.pontosTuristicos) printf("Vencedor: %s\n", c2.cidade);
            else printf("Empate!\n");
            break;

        case 5: { // Densidade demográfica
            float d1 = densidade(c1);
            float d2 = densidade(c2);
            printf("\nAtributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", c1.cidade, d1);
            printf("%s: %.2f hab/km²\n", c2.cidade, d2);

            // ✅ corrigido: a comparação estava invertida
            if (d1 < d2)
                printf("Vencedor: %s (menor densidade)\n", c1.cidade);
            else if (d1 > d2)
                printf("Vencedor: %s (menor densidade)\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        }

        default:
            printf("\nOpção inválida!\n");
    }
}

int main() {
    struct Carta carta1, carta2;
    int opcao;

    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Mostrar cartas
    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    // Menu interativo
    do {
        printf("\n=== MENU DE COMPARAÇÃO ===\n");
        printf("1 - Comparar População\n");
        printf("2 - Comparar Área\n");
        printf("3 - Comparar PIB\n");
        printf("4 - Comparar Pontos Turísticos\n");
        printf("5 - Comparar Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao != 0) {
            comparar(carta1, carta2, opcao);
        }

    } while (opcao != 0);

    printf("\nObrigado por jogar!\n");
    return 0;
}
