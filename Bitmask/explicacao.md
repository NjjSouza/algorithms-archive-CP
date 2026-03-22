### ✿ Bitmask

Bitmask (ou manipulação de bits) é uma técnica que usa números inteiros para representar conjuntos. Com `n` elementos, um inteiro de `n` bits pode representar qualquer subconjunto desses elementos (totalizando $2^n$ possibilidades). 

---

###### ▸ Fundamentos e Eletrônica Digital ✿

A conexão com o que vemos em circuitos lógicos é direta. Operar com Bitmask é como manipular registradores em hardware.

| Eletrônica Digital | Bitmask em C++ |
| :--- | :--- |
| Portas AND, OR, NOT, XOR | Operadores `&`, `|`, `~`, `^` |
| Flip-flop (0 ou 1) | Cada bit do inteiro |
| Registradores de n bits | `int` (32 bits) ou `long long` (64 bits) |

> **Visualização de Operadores e Expressões**
> Abaixo, a tabela verdade que dita o comportamento de cada bit e um exemplo de como expressões bitwise são avaliadas:
>
> ![BitwiseOperators](BitwiseOperators.png)
> ![Representation](Representation.png)

---

###### ▸ Como reconhecer problemas de Bitmask ✿

* **Conjunto minúsculo:** Tipicamente $n \le 20$ (limite clássico para $2^{20} \approx 10^6$).
* **Decisões Binárias:** "Incluir ou não incluir?", "Ligado ou desligado?".
* **Problemas de Seleção:** "Menor custo para visitar todos os nós" (TSP) ou "Quantas formas de escolher subconjuntos?".
* **Estados de Visitação:** Quando você precisa saber exatamente quais itens já foram processados.

---

###### ▸ Operações Essenciais (Snippets) ✿

Padrões de código mais usados:

```cpp
// 1. Checar se o i-ésimo bit está ligado
if (mask & (1 << i)) { ... }

// 2. Ligar o i-ésimo bit
mask |= (1 << i);

// 3. Desligar o i-ésimo bit
mask &= ~(1 << i);

// 4. Inverter o i-ésimo bit
mask ^= (1 << i);

// 5. Contar quantos bits estão ligados (popcount)
int ativos = __builtin_popcount(mask);