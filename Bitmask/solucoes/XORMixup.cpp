/* Explicando uma forma de resolver logicamente o problema (sem cálculos):
É fornecida na entrada uma quantidade de elementos. 
Esses elementos são armazenados num array junto com um valor X. 
Esse X é o xor de todos os outros elementos.
Xor nada mais é do que uma operação bit a bit que resulta em 1 apenas 
quando os bits comparados são diferentes, ou seja: só se for um 1 e 0 ou um 0 e 1. 
O array da questão é composto por: (a1 xor a2 xor aN) e pelo X. 
Se (a1 xor a2 xor aN) = X, então podemos perceber a oportunidade de usar uma propriedade: 
X xor X = 0. Se o xor de todos os números desse array é igual a 0, então 
imprimindo qualquer um dos elementos desse array (por exemplo, A1), 
o que eu vou ter é o uso de outra propriedade: 0 xor A1 = A1. 
Então independentemente do que eu imprimir, será sempre X, porque 
qualquer número retirado e impresso do array será igual ao xor dos demais. */

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
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << a[0] << "\n"; // imprime o primeiro elemento, mas poderia ser qualquer outro
    }

    /* Exemplo simples:
    Entrada: 3, 5, 6.
    Num mesmo array, junto com o xor desses elementos, está o X.
    X é igual ao xor deles (3, 5 e 6), ficando X xor X, que é igual a 0.
    0 então é o valor do xor de todos os elementos do array incluindo o X.
    Ao imprimir qualquer um, qualquer elemento xor 0 resultará nele mesmo. 
    Então qualquer elemento impresso será o xor dos demais. 
    Prova: 3 xor 5 = 6; 3 xor 6 = 5; 5 xor 6 = 3. */

    return 0; 
}