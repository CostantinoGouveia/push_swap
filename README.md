# Push Swap

## Descrição

O **Push Swap** é um projeto da 42 School cujo objetivo é ordenar uma lista de números inteiros com o menor número possível de operações. O projeto utiliza duas pilhas, denominadas `A` e `B`, e permite apenas um conjunto limitado de operações para realizar a ordenação. A complexidade reside em encontrar a sequência de operações mais eficiente para ordenar a pilha `A`.

## Objetivo

Ordenar os elementos da pilha `A` em ordem crescente, utilizando a pilha `B` como auxiliar. O número de operações deve ser o menor possível.

## Estrutura do Projeto

O **Push Swap** utiliza duas pilhas:

- **Pilha A**: Contém os números inteiros fornecidos inicialmente.
- **Pilha B**: Pilha auxiliar utilizada nas operações de movimentação.

## Operações Permitidas

As operações que podem ser realizadas no **Push Swap** são:

- `sa` (swap a): Troca os dois primeiros elementos da pilha `A`.
- `sb` (swap b): Troca os dois primeiros elementos da pilha `B`.
- `ss` (swap both): Troca os dois primeiros elementos de ambas as pilhas.
- `pa` (push a): Move o elemento do topo da pilha `B` para o topo da pilha `A`.
- `pb` (push b): Move o elemento do topo da pilha `A` para o topo da pilha `B`.
- `ra` (rotate a): Roda todos os elementos da pilha `A` uma posição para cima (o primeiro elemento vai para o fim).
- `rb` (rotate b): Roda todos os elementos da pilha `B` uma posição para cima.
- `rr` (rotate both): Roda as duas pilhas ao mesmo tempo.
- `rra` (reverse rotate a): Roda todos os elementos da pilha `A` uma posição para baixo (o último elemento vai para o topo).
- `rrb` (reverse rotate b): Roda todos os elementos da pilha `B` uma posição para baixo.
- `rrr` (reverse rotate both): Roda as duas pilhas ao mesmo tempo para baixo.

## Algoritmo

O algoritmo básico consiste em:

1. Identificar o menor elemento da pilha `A`.
2. Empurrá-lo para a pilha `B` com a operação `pb`.
3. Repetir até que todos os elementos estejam na pilha `B`.
4. Empurrar os elementos de volta para a pilha `A` em ordem crescente com a operação `pa`.

Este é apenas o funcionamento básico. Estratégias mais avançadas e otimizações são necessárias para minimizar o número de operações.

## Otimizações

Para obter o menor número de operações, é fundamental aplicar heurísticas, como dividir a pilha em blocos menores, identificar padrões repetitivos e otimizar o uso de operações combinadas (`ss`, `rr`, `rrr`). O principal desafio é realizar o ordenamento com o menor número de movimentos possível.

## Regras

- O projeto só permite utilizar as operações descritas acima.
- Não é permitido o uso de funções de ordenação embutidas como `qsort`, nem bibliotecas externas.

## Como Usar

Após a compilação, você pode testar o **Push Swap** executando o programa com uma sequência de números inteiros:

```bash
./push_swap 4 3 2 1

