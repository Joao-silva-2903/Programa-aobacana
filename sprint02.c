#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_PT.UTF-8");

    char linha[100];
    char extra;
    int valor;
    float temp;

    while (1) {
        printf("Digite um valor inteiro entre 0 e 1023: ");

        // sizeof(entrada) garante que nunca escreve mais de 100 caracteres
        // O fgets devolve NULL quando não conseguiu ler nenhum caractere e
        // dá se return 1 para interromper o programa, pois não há nada para ler

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            return 1;  // fim da entrada
        }
        
        int chave = sscanf(linha, "%d %c", &valor, &extra);

        // chave == EOF -> a string é inválida, não há nada para ler
        // chave == 0 -> leu algum caractere primeiro que um número
        // chave == 1 -> só leu um número (espaços finais são ignorados)
        // chave == 2 -> havia mais algum caractere inválido depois do número

        if (chave == 1 && valor >= 0 && valor <= 1023) {
            break;
        }

        printf("Valor inválido.\n");
    }

    temp = 260.0*valor/1023.0 - 20.0;

    if ( temp < -10 || temp > 190 ) {
        printf("Valor fora de gama, a temperatura está fora do intervalo [-10, 190]°C.");
    } else {
        printf("Após a leitura do valor %d, a temperatura final é de %.2f .°C.", valor, temp);
    return 0;
    }
}
