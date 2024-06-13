#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int farinha, ovos, oleo, acucar, chocolate;
} Receita;

void cadastrar(Receita **receitas, int *num) {
    Receita novaReceita;
    scanf("%19s %d %d %d %d %d", novaReceita.nome, &novaReceita.farinha, &novaReceita.ovos, &novaReceita.oleo, &novaReceita.acucar, &novaReceita.chocolate);
    *receitas = realloc(*receitas, (*num + 1) * sizeof(Receita));
    (*receitas)[*num] = novaReceita;
    (*num)++;
}

void comprar(int *estoque) {
    int farinha, ovos, oleo, acucar, chocolate;
    scanf("%d %d %d %d %d", &farinha, &ovos, &oleo, &acucar, &chocolate);
    estoque[0] += farinha;
    estoque[1] += ovos;
    estoque[2] += oleo;
    estoque[3] += acucar;
    estoque[4] += chocolate;
}

void fazer(Receita *receitas, int num, int *estoque) {
    int numR;
    scanf("%d", &numR);
    if (numR < 0 || numR >= num) {
        printf("Receita nao encontrada!\n");
        return;
    }
    Receita r = receitas[numR];
    if (estoque[0] < r.farinha) {
        printf("Farinha insuficiente\n");
    } else if (estoque[1] < r.ovos) {
        printf("Ovos insuficientes\n");
    } else if (estoque[2] < r.oleo) {
        printf("Oleo insuficiente\n");
    } else if (estoque[3] < r.acucar) {
        printf("Acucar insuficiente\n");
    } else if (estoque[4] < r.chocolate) {
        printf("Chocolate insuficiente\n");
    } else {
        estoque[0] -= r.farinha;
        estoque[1] -= r.ovos;
        estoque[2] -= r.oleo;
        estoque[3] -= r.acucar;
        estoque[4] -= r.chocolate;
        printf("%s feita com sucesso!\n", r.nome);
    }
}

void imprimirEstoque(int *estoque, int num) {
    printf("Quantidade no estoque:\n");
    printf("Acucar: %d\n", estoque[3]);
    printf("Chocolate: %d\n", estoque[4]);
    printf("Farinha: %d\n", estoque[0]);
    printf("Oleo: %d\n", estoque[2]);
    printf("Ovos: %d\n", estoque[1]);
    printf("Receitas cadastradas: %d\n", num);
}

int main(void) {
    Receita *receitas = NULL;
    char comando;
    int num = 0;
    int estoque[5] = {0, 0, 0, 0, 0};
    while (1) {
        scanf(" %c", &comando);

        if (comando == 'R') {
            cadastrar(&receitas, &num);
        } else if (comando == 'C') {
            comprar(estoque);
        } else if (comando == 'F') {
            fazer(receitas, num, estoque);
        } else if (comando == 'S') {
            imprimirEstoque(estoque, num);
            free(receitas);
            return 0;
        } else {
            printf("Codigo invalido\n");
        }
    }
}

