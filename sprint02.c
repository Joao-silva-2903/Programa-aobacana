#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_PT.UTF-8");

    int valor;
    float temp;

    do {

        printf("Digite um valor inteiro entre 0 e 1023: ");

        if ( scanf("%d", &valor) != 1 || valor < 0 || valor > 1023 ) {
            printf("Valor inválido. Por favor, insira um valor entre 0 e 1023. ");
            
            while (getchar() != '\n');

        } else {
            break;
        }

    } while (1);

    temp = 260.0*valor/1023.0 - 20.0;

    if ( temp < -10 || temp > 190 ) {
        printf("Valor fora da gama.");
    } else {
        printf("Após a leitura do valor %d, a temperatura final é de %.2f°C.", valor, temp);
        return 0;
    }

}
