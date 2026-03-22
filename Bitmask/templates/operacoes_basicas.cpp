#include <iostream>
#include <bitset> 

using namespace std;

int main() {
    // Valores base para testes
    int elemento = 46; // 00101110
    int mascara = 170; // 10101010
    int desloc = 3; // O quanto vamos pular

    cout << "--- OPERACOES BASICAS ---" << endl;
    cout << "Elemento: " << bitset<8>(elemento) << " (" << elemento << ")" << endl;
    cout << "Mascara: " << bitset<8>(mascara) << " (" << mascara << ")" << endl;

    // OPERACOES LOGICAS PADRAO
    cout << "AND (&): " << bitset<8>(elemento & mascara) << " (Intersection)" << endl;
    cout << "OR  (|): " << bitset<8>(elemento | mascara) << " (Union)" << endl;
    cout << "XOR (^): " << bitset<8>(elemento ^ mascara) << " (Difference/Flip)" << endl;
    cout << "NOT (~): " << bitset<8>(~elemento) << " (Invert)" << endl;

    cout << "\n--- DESLOCAMENTOS (POTENCIAS DE 2) ---" << endl;
    // SHIFT LEFT (<<) - Multiplica por 2^n
    cout << "L-Shift: " << bitset<8>(elemento << desloc) << " (Valor: " << (elemento << desloc) << ")" << endl;
    // SHIFT RIGHT (>>) - Divide por 2^n (inteira)
    cout << "R-Shift: " << bitset<8>(elemento >> desloc) << " (Valor: " << (elemento >> desloc) << ")" << endl;

    cout << "\n--- AS SACADAS DA MARATONA (BITMASK) ---" << endl;
    
    // 1. GERAR POTENCIA DE 2 (Usado no total_caminhos do Petr)
    int n = 5;
    cout << "Gerar 2^" << n << ": " << (1 << n) << " (Usando 1 << n)" << endl;

    // 2. EXTRAIR UM BIT ESPECIFICO (O "leitor de interruptor" do Petr)
    // Queremos saber se o bit na posicao 3 do 'elemento' e 0 ou 1
    int posicao = 3;
    int bit = (elemento >> posicao) & 1;
    cout << "Bit na pos " << posicao << " do elemento: " << bit << endl;

    // 3. PROPRIEDADE XOR (A base do XOR Mixup)
    cout << "Prova XOR: " << (elemento ^ elemento) << " (Sempre zero se iguais)" << endl;

    return 0;
}