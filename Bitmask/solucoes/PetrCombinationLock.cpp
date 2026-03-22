#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; // numero de giros 

    vector<int> giros(n);
    for (int i = 0; i < n; i++) {
        cin >> giros[i];
    }

    // como n <= 15, e há duas opções de escolha, há 2^15 combinações possíveis
    int total_caminhos = (1 << n); // mesmo que 2^n
    /* isso porque: 00000001 (1) empurrado 0 uma casa para a esquerda, 
    por exemplo, fica 00000010 (2) (mesmo que 2 elevado a 1)
    e 00000010 (2) << mais uma casa, fica 00000100 (4) (mesmo que 2 elevado a 2) */
    bool deu_zero = false;

    for (int tentativa = 0; tentativa < total_caminhos; tentativa++) {
        int graus = 0;

        for (int i = 0; i < n; i++) {
            // empurra para a direita os bits de tentativa i vezes, fazendo depois uma operação AND com o número 1 (00000001):
            int escolha_direcao = (tentativa >> i) & 1;
            /* exemplo: 00000011 (3) >> 0 = 00000011 (3), & 00000001 = 00000001 (1) (1 = sentido horário)
            00000011 (3) >> 1 = 00000001 (1), & 00000001 = 00000001 (1) (1 = sentido horário)
            00000011 (3) >> 2 = 00000000 (0), & 00000001 = 00000000 (0) (0 = sentido anti-horário) */

            if (escolha_direcao == 1) {
                graus += giros[i]; // retornar 1 significa sentido horário (+)
            } else {
                graus -= giros[i]; // retornar 0 significa anti-horário (-)
            }

            // ps: para o computador, todos os números já estão compreendidos entre 0 e 1
        }

        if (graus % 360 == 0) { // se for um múltiplo de 360, é possível retornar ao ponto 0
            deu_zero = true;
            break; 
        }
    }

    if (deu_zero) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return 0;
}