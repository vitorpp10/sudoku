# Sudoku em c++

--- 

## Stacks:

```
C++
SMFL (Janela gráfica)
```

## Como funciona:

So pode colocar x número se ele não existir na mesma coluna ou linha ou quadrante onde ele vai ser colocado, exemplo:

```
1 2 3  | 4 8 6 | 5 7 9
4 5 9  | 1 2 7 | 3 6 8
7 8 x  | 3 9 5 | 1 2 4
----------------------
8 6 1 
5 9 2 
3 7 4 
-----------------------
6 1 7 
9 3 8 
2 4 5
```

Como pode ver nenhum número se repete, ou seja basta ver oque tem na fileira, coluna e quadrante do x:

```
na fileira: 7, 8, 3, 9, 5, 1, 2, 4 
na coluna: 3, 9, 1, 2, 4, 7, 8, 5 
no quadrante: 1, 2, 3, 4, 5, 9, 7, 8 
```

Nesse caso, o número 6 nao está em nenhuma das três regras exigidas, então ele deve ser colocado naquele posto.

O jogo é basicamente isso, preencher sem o número estar na fileira, coluna ou quadrante.

## Oque vai ter:

#### *v.1.0:*
**Níveis de dificuldade**:
- O usuário vai poder escolher entre `fácil | médio | difícil`

**Erros limitados**:
`fácil: Erros ilimitados | médio: Até 3 erros | difícil: 1 erro`

---
