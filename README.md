# 🚢 Batalha Naval em C

Projeto desenvolvido em linguagem C, baseado no clássico jogo **Batalha Naval**. A implementação é dividida em três fases: **Novato**, **Aventureiro** e **Mestre**, permitindo o aprendizado incremental de estruturas de dados, lógica de programação, e manipulação de matrizes.

---

## 🧠 Objetivo

Simular um jogo de Batalha Naval por etapas, construindo o tabuleiro, posicionando navios e aplicando habilidades especiais com áreas de efeito.

---

## 📚 Fases do Projeto

### 🧩 Fase 1: Novato

- Criação de um tabuleiro `10x10` (matriz bidimensional).
- Posicionamento fixo de **dois navios**:
  - 1 navio horizontal (tamanho 3).
  - 1 navio vertical (tamanho 3).
- Representação:
  - `0` → Água.
  - `3` → Parte do navio.

### ⚔️ Fase 2: Aventureiro

- Adição de **dois navios diagonais**:
  - 1 em diagonal principal (`↘`).
  - 1 em diagonal secundária (`↙`).
- Validação de limites e sobreposição.
- Visualização clara do tabuleiro atualizado.

### 🧙‍♂️ Fase 3: Mestre

- Implementação de **habilidades especiais** com **áreas de efeito**:
  - **Cone** (↧)
  - **Cruz** (+)
  - **Octaedro** (⧫)
- Cada habilidade tem uma **matriz 5x5** com `1` representando células afetadas.
- Aplicação das habilidades sobre o tabuleiro, marcando com:
  - `5` → Área afetada por habilidade.

---

 ## 🧠 Aprendizados Envolvidos
- Matrizes bidimensionais (tabuleiro[10][10])

- Vetores para coordenadas

- Estruturas de repetição e condicionais

- Modularização com funções

- Sobreposição de matrizes em pontos centrais

---

## 🧪 Execução

### 🛠️ Compilação

Use um compilador C como `gcc`:

```bash
gcc batalhaNaval.c -o batalhaNaval

