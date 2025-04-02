/*

  Autor: Nicolas Alexandre Torres Dias
  Matricula: 885506

*/

#include <stdio.h>
// funcao pra calcular 2^exp
int potencia(int exp) {
    int result = 1; // inicializa o resultado como 1
    for (int i = 0; i < exp; i++) { // loop para multiplicar 2 exp vezes
        result *= 2; // multiplica result por 2 em cada iteracao
    }
    return result; // retorna 2^exp
}

// funcao recursiva para converter um numero binario para decimal
int toDecimal(int n, int power) {
    if (n == 0) return 0; // se nao houver mais digitos, retorna 0
    
    int lD = n % 10; // pega o ultimo digito do numero (0 ou 1)
    int rest = n / 10; // remove o ultimo digito para processar o restante

    // multiplica o ultimo digito pela potencia correta de 2 e chama a funcao recursivamente
    return lD * potencia(power) + toDecimal(rest, power + 1);
}

int main() {
    int n; // armazena o numero binario digitado
    scanf("%d", &n); // le o numero binario como um inteiro
    
    int ans = toDecimal(n, 0); // chama a funcao para converter para decimal
    printf("%d", ans); // imprime o resultado convertido

    return 0;
}
