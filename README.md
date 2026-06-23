**Bandeira: Brasil (Português)**

Descrição
- **Projeto**: Sudoku (versão desktop em C++ com SFML).
- **Objetivo**: Jogo de Sudoku com níveis de dificuldade, sistema de erros, contagem de streaks, e interface gráfica construída com SFML.

Pré-requisitos
- **Sistema operacional**: Linux (testado). Outros sistemas podem precisar de ajustes.
- **Dependências**: SFML (graphics, window, audio). Instale via gerenciador de pacotes (por exemplo, `sudo apt install libsfml-dev`) ou compile a partir da fonte.
- **Fonts e assets**: a pasta `assets/` contém fontes, sons e imagens necessários para rodar o jogo.

Como compilar e executar
- **Compilação (exemplo com g++)**: ajustar conforme seu Makefile ou projeto.
  - Instale SFML e dependências.
  - Compile todos os arquivos `.cpp` em `app/` e link com SFML (graphics, window, system, audio).
- **Execução**: execute o binário gerado a partir do diretório do projeto. Certifique-se de que o diretório `assets/` esteja acessível pelo binário (o código usa caminhos relativos `../assets/`).

Estrutura do repositório
- **app/**: código-fonte principal em C++.
  - [app/main.cpp](app/main.cpp): ponto de entrada da aplicação.
  - [app/jogo.cpp](app/jogo.cpp) e [app/jogo.hpp](app/jogo.hpp): lógica principal do jogo, geração de tabuleiro, detecção de erros, desenho da interface e eventos.
  - [app/menu.cpp](app/menu.cpp) e [app/menu.hpp](app/menu.hpp): telas de menu (início, seleção de dificuldade, etc.).
  - [app/modo.cpp](app/modo.cpp) e [app/modo.hpp](app/modo.hpp): gerenciamento de modos ou sub-telas.
  - [app/opcoes.cpp](app/opcoes.cpp) e [app/opcoes.hpp](app/opcoes.hpp): opções do jogo (música, volume, etc.).
  - [app/estatisticas.cpp](app/estatisticas.cpp) e [app/estatisticas.hpp](app/estatisticas.hpp): persistência/visualização de estatísticas (vitórias, derrotas, streaks).
  - [app/como_jogar.cpp](app/como_jogar.cpp) e [app/como_jogar.hpp](app/como_jogar.hpp): instruções de jogo.
  - [app/carregando.cpp](app/carregando.cpp) e [app/carregando.hpp](app/carregando.hpp): tela de carregamento/recursos.
  - [app/def.hpp](app/def.hpp): definições globais (tamanhos, cores, constantes como `TAM_CELULA`).
  - [app/sudoku](app/sudoku): (possível arquivo/binário ou recurso relacionado ao jogo — verificar conteúdo localmente).

- **assets/**: recursos estáticos usados pelo jogo.
  - [assets/PressStart2P-Regular.ttf](assets/PressStart2P-Regular.ttf): fonte utilizada na interface.
  - [assets/musica0.ogg](assets/musica0.ogg), [assets/musica1.ogg](assets/musica1.ogg), [assets/musica2.ogg](assets/musica2.ogg): faixas de música para o jogo.
  - [assets/erro.ogg](assets/erro.ogg), [assets/clique.ogg](assets/clique.ogg): efeitos sonoros.
  - [assets/cute_image.jpg](assets/cute_image.jpg): imagem usada em alguma tela (ex.: menu ou fundo).
  - [assets/OFL.txt](assets/OFL.txt): texto de licença da fonte incluída.

- **documentacao/**: notas e documentação em Markdown.
  - [documentacao/docs.md](documentacao/docs.md): documentação do projeto.
  - [documentacao/sobre.md](documentacao/sobre.md): informações do autor/projeto.
  - [documentacao/anotar.md](documentacao/anotar.md): anotações diversas.

Como jogar (fluxo e controles)
- **Objetivo**: preencher o tabuleiro 9x9 com números de 1 a 9, sem repetir números por linha, coluna ou bloco 3x3.
- **Seleção**: clique com o mouse sobre uma célula para selecioná-la.
- **Inserir número**: clique em um dos botões do painel (1–9) para inserir o número na célula selecionada. Há também um botão "X" para apagar.
- **Erros**: o jogo marca entradas incorretas; em níveis médios/ difíceis há limite de erros que leva à derrota.
- **Menus**: opções para ajustar volume, trocar música e sair (com confirmação em pop-up).

Detalhes de geração do tabuleiro
- O tabuleiro completo (gabarito) é gerado preenchendo recursivamente a grade validar números (`preencher_tabuleiro()` em [app/jogo.cpp](app/jogo.cpp)).
- Em seguida, o programa remove células aleatoriamente (quantidade dependente da dificuldade) para criar o quebra-cabeça jogável.

Personalização e assets
- Para adicionar músicas ou sons, coloque os arquivos em `assets/` e atualize a lista de nomes usada no código (procure por `listaMusicas` em [app/jogo.cpp](app/jogo.cpp)).
- A fonte principal está em `assets/PressStart2P-Regular.ttf`. Respeite a licença indicada em `assets/OFL.txt`.

Boas práticas e notas
- Mantenha o diretório `assets/` no caminho esperado relativo ao binário; o código usa `../assets/` em alguns pontos, então execute o binário a partir de `app/` ou ajuste caminhos se necessário.
- Recomenda-se compilar com otimizações para melhor desempenho gráfico.

Contribuições
- Sugestões de correções e melhorias são bem-vindas. Abra issues ou envie pull requests contendo descrições das mudanças e razões.

**Flag: United States (English)**

Description
- **Project**: Sudoku (desktop C++ version using SFML).
- **Purpose**: Sudoku game with difficulty levels, error system, streak counting, and a graphical interface built with SFML.

Prerequisites
- **OS**: Linux (tested). Other OSes may require adjustments.
- **Dependencies**: SFML (graphics, window, audio). Install via package manager (e.g., `sudo apt install libsfml-dev`) or build from source.
- **Fonts and assets**: the `assets/` folder contains fonts, sounds and images required to run the game.

Build and run
- **Build (example using g++)**: adjust to your own build setup or Makefile.
  - Install SFML and required packages.
  - Compile all `.cpp` files in `app/` and link against SFML (graphics, window, system, audio).
- **Run**: execute the produced binary from the project directory. Ensure the `assets/` directory is reachable by the binary (code references assets using relative paths such as `../assets/`).

Repository structure
- **app/**: main C++ source code.
  - [app/main.cpp](app/main.cpp): application entry point.
  - [app/jogo.cpp](app/jogo.cpp) and [app/jogo.hpp](app/jogo.hpp): main game logic, board generation, error detection, rendering and event handling.
  - [app/menu.cpp](app/menu.cpp) and [app/menu.hpp](app/menu.hpp): menu screens (start, difficulty selection, etc.).
  - [app/modo.cpp](app/modo.cpp) and [app/modo.hpp](app/modo.hpp): mode or sub-screen management.
  - [app/opcoes.cpp](app/opcoes.cpp) and [app/opcoes.hpp](app/opcoes.hpp): game options (music, volume, etc.).
  - [app/estatisticas.cpp](app/estatisticas.cpp) and [app/estatisticas.hpp](app/estatisticas.hpp): stats handling (wins, losses, streaks).
  - [app/como_jogar.cpp](app/como_jogar.cpp) and [app/como_jogar.hpp](app/como_jogar.hpp): instructions screen.
  - [app/carregando.cpp](app/carregando.cpp) and [app/carregando.hpp](app/carregando.hpp): loading screen/resources.
  - [app/def.hpp](app/def.hpp): global definitions (sizes, colors, constants like `TAM_CELULA`).
  - [app/sudoku](app/sudoku): (possible file/binary or resource; check local content).

- **assets/**: static resources used by the game.
  - [assets/PressStart2P-Regular.ttf](assets/PressStart2P-Regular.ttf): font used in the UI.
  - [assets/musica0.ogg](assets/musica0.ogg), [assets/musica1.ogg](assets/musica1.ogg), [assets/musica2.ogg](assets/musica2.ogg): music tracks.
  - [assets/erro.ogg](assets/erro.ogg), [assets/clique.ogg](assets/clique.ogg): sound effects.
  - [assets/cute_image.jpg](assets/cute_image.jpg): image used on a screen (e.g., menu or background).
  - [assets/OFL.txt](assets/OFL.txt): license text for the included font.

How to play (controls and flow)
- **Goal**: fill the 9x9 board with numbers 1 to 9, without repeating numbers in any row, column, or 3x3 block.
- **Select**: click a cell with the mouse to select it.
- **Insert number**: click a number button (1–9) on the panel to place it in the selected cell. Use the "X" button to erase.
- **Errors**: incorrect entries are flagged; on medium/hard difficulty there is a limited number of errors which can cause defeat.
- **Menus**: there are controls to change volume, switch music, and exit (with a confirmation pop-up).

Board generation details
- The full solution is generated by a recursive fill-and-backtrack algorithm (`preencher_tabuleiro()` in [app/jogo.cpp](app/jogo.cpp)).
- After generating a complete board, the program removes cells randomly (count depends on difficulty) to create the playable puzzle.

Customization and assets
- To add music or sound, place files in `assets/` and update the list of names used in the code (search for `listaMusicas` in [app/jogo.cpp](app/jogo.cpp)).
- The primary font is `assets/PressStart2P-Regular.ttf`. Respect the licensing indicated in `assets/OFL.txt`.

Notes and recommendations
- Keep `assets/` accessible by the binary; the source uses relative paths like `../assets/`, so run the binary from `app/` or adjust paths as needed.
- Compile with optimizations for better graphical performance.

Contributing
- Contributions are welcome. Open issues or submit pull requests with clear descriptions of changes and motivations.
