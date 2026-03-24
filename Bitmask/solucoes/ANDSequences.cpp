/* Conhecimentos necessários: análise combinatória (arranjo/permutação) e aritmética modular (devido ao limite de memória)

Fórmula final: Resultado = qtd * (qtd - 1) * (n - 2)! (arranjo nas pontas e permutação no meio)
Motivo: com qtd números que satisfazem a condição de serem iguais ao and_total, dois deles serão as pontas (início e fim); 
a ordem importa, então usamos arranjo: A(qtd, 2) = qtd * (qtd - 1)
Permutação no meio: os (n - 2) números restantes não precisam estar em ordem, pois as pontas já travam o valor do AND. 
O número de arranjos possíveis para o meio então é (n - 2)! */

#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);           

    int t;
    cin >> t; // número de casos de teste

    while (t--) { 
        int n;
        cin >> n; // tamanho do array

        vector<int> a(n); 
        
        int and_total = -1; // começa com 1111... 
        // porque usando and_total = 0, 0 & qualquer valor = 0 
        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (i == 0) and_total = a[i]; // impede and_total de realizar AND com 0
            else and_total &= a[i]; // armazena o AND total de todos os números do array
        }

        long long qtd = 0; // long long para evitar estouro de int 
        for (int i = 0; i < n; i++) {
            if (a[i] == and_total){
                qtd++; // contagem de quantos números são iguais ao and_total
            }
        } 

        /* para a sequência ser "boa", o primeiro número a1 e o último aN precisam ser iguais ao and_total, então 
        pelo menos 2 números devem ser iguais a ele, senão é impossível colocar um no início e outro no fim */
        if (qtd < 2)
            cout << 0 << "\n";
        else {
            long long MOD = 1e9 + 7; // para garantir que o resultado caiba na memória
            long long resultado = (qtd * (qtd - 1)) % MOD; // cálculo das pontas -> qtd * (qtd - 1)

            // cálculo do fatorial do meio: (n - 2)!
            for (int i = 1; i <= (n - 2); i++) {
                resultado = (resultado * i) % MOD; // multiplica o resultado atual pelos números de 1 até (n-2)
            }
            cout << resultado << endl; 
        }
        /* Exemplo: 0 2 0 3 0 (n = 5)
        AND de todos: 0
        Contagem (qtd): 3
        Cálculo: 3 * (3 - 1) * (5 - 2)!
        3 * 2 * 3! -> 6 * (3 * 2 * 1) -> 6 * 6 = 36 */
    }

    return 0; 
}