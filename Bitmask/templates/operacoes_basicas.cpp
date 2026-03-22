#include <iostream>
#include <bitset> // Necessário para imprimir em binário

using namespace std;

int main() {
    // Definindo valores de exemplo para as operações bit a bit
    int element = 46; // 00101110
    int mask = 170; // 10101010
    int shift = 3; // 00000011

    // No C++, bitset<8> converte o número para uma string binária de 8 bits
    cout << "Elemento: " << bitset<8>(element) << " (" << element << ")" << endl;
    cout << "Mascara:  " << bitset<8>(mask) << " (" << mask << ")" << endl;
    cout << "Shift:    " << bitset<8>(shift) << " (" << shift << ")" << endl;

    // OPERAÇÃO AND (&) - Resulta 1 apenas se AMBOS forem 1
    cout << "AND: " << bitset<8>(element & mask) << endl;

    // OPERAÇÃO OR (|) - Resulta 1 se PELO MENOS UM for 1
    cout << "OR:  " << bitset<8>(element | mask) << endl;

    // OPERAÇÃO XOR (^) - Resulta 1 se forem DIFERENTES
    cout << "XOR: " << bitset<8>(element ^ mask) << endl;

    // OPERAÇÃO NOT (~) - Inverte todos os bits
    // Cuidado: em inteiros com sinal, isso envolve o complemento de dois
    cout << "NOT: " << bitset<8>(~element) << endl;

    // SHIFT LEFT (<<) - Desloca os bits para a esquerda (equivale a multiplicar por 2^shift)
    cout << "L-Shift: " << bitset<8>(element << shift) << " (valor: " << (element << shift) << ")" << endl;

    // SHIFT RIGHT (>>) - Desloca os bits para a direita (equivale a dividir por 2^shift)
    cout << "R-Shift: " << bitset<8>(element >> shift) << " (valor: " << (element >> shift) << ")" << endl;

    return 0;
}