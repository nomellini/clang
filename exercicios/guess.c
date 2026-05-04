#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int secreto = rand() % 1000 + 1;
    int tentativa, chute;

    printf("=== Adivinhe o numero (1 a 1000) ===\n");
    printf("Voce tem 10 tentativas.\n\n");

    for (tentativa = 1; tentativa <= 10; tentativa++) {
        printf("Tentativa %d/10: ", tentativa);
        if (scanf("%d", &chute) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }

        if (chute < 1 || chute > 1000) {
            printf("Digite um numero entre 1 e 1000.\n");
            tentativa--;
            continue;
        }

        if (chute == secreto) {
            printf("Parabens! Voce acertou em %d tentativa(s)!\n", tentativa);
            return 0;
        } else if (chute < secreto) {
            printf("Muito baixo!\n");
        } else {
            printf("Muito alto!\n");
        }
    }

    printf("Fim de jogo! O numero era %d.\n", secreto);
    return 0;
}
