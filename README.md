# Computação Gráfica – Transformada DCT

Trabalho da disciplina de **Computação Gráfica**: uma aplicação em C++ com OpenGL/GLUT que mostra, em um
gráfico, o efeito da **Transformada Discreta de Cosseno (DCT)** e da sua inversa (**IDCT**) sobre um vetor
de amostras.

## Como funciona

1. **Carregar**: lê as amostras do arquivo binário [`samples.dct`](samples.dct) e desenha os valores no
   gráfico.
2. **Aplicar**: aplica a DCT e, em seguida, a IDCT sobre as amostras. Os coeficientes são guardados como
   inteiros (`short`), então os valores reconstruídos têm pequenas diferenças em relação aos originais.
3. O gráfico mostra, em cores diferentes:
   - 🔴 os valores **originais**;
   - 🟡 os valores **reconstruídos** depois da DCT + IDCT;
   - 🟢 a **diferença** entre os dois.
4. As caixas de seleção **Originais**, **Reconstruídos** e **Diferenças** ligam e desligam cada curva na hora.
5. **Salvar**: grava os valores reconstruídos por cima do arquivo de entrada.

O gráfico se ajusta sozinho ao tamanho da janela e à faixa de valores das amostras.

### Formato do `samples.dct`

Arquivo binário com um `int` (quantidade de amostras) seguido das amostras, cada uma um `signed short`.

## Requisitos do trabalho

- Gráfico de no mínimo 600 × 400 pixels com os valores originais, reconstruídos e a diferença.
- Área de plotagem e escala que se ajustam aos valores e ao tamanho da tela.
- Botões **Carregar**, **Salvar** e **Aplicar**.
- Caixas de seleção para mostrar ou esconder cada tipo de valor.
- Tudo em tempo real, com interface simples, organizada e didática (botões e caixas de seleção próprios).

## Estrutura do projeto

| Caminho | Descrição |
|---|---|
| `src/Main.cpp` | Ponto de entrada: janela, botões, caixas de seleção e eventos de mouse |
| `src/DCT.cpp` | Funções da DCT e da IDCT |
| `src/Grafico.cpp` | Desenho do gráfico, escala e curvas |
| `src/Arquivo.cpp` | Leitura e gravação do arquivo de amostras |
| `src/Botao.cpp` / `src/Checkbox.cpp` | Componentes de interface desenhados na tela |
| `src/gl_canvas2d.cpp` | Camada de desenho 2D sobre OpenGL/GLUT |
| `dct.cbp` | Projeto do Code::Blocks |

## Como compilar

Projeto do **Code::Blocks** com GCC (C++11). Ele espera as bibliotecas da **freeglut**, `opengl32` e `glu32`
em `../lib` e os headers do GLUT em `include/GL` (não estão no repositório). Com o ambiente pronto, abra o
`dct.cbp` no Code::Blocks e compile. Rode o programa a partir da pasta que contém o `samples.dct`.

## Tecnologias

- C++11
- OpenGL + freeglut
- Code::Blocks
