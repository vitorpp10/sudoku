#include"jogo.hpp"
#include <SFML/Window/Mouse.hpp>
#include<cmath>
#include<string>

Jogo::Jogo(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
      titulo(font), 
      texto_numero(font),
      label_voltar_jogo(font),
      label_erro(font),
      label_volume_jogo(font),
      label_musica_jogo(font),
      label_musica_trocar(font),
      label_pop_up(font),
      label_sim_pop_up(font),
      label_nao_pop_up(font),
      label_pop_detalhe(font), 
      label_apagar(font)
{
  //configura o titulo
  titulo.setString("Sudoku da Fernanda");
  titulo.setCharacterSize(55);
  titulo.setFillColor(purple);
  sf::FloatRect bounds = titulo.getLocalBounds();
  titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

  //botao volume 
  botao_volume_jogo.setSize({300.f, 65.f});
  botao_volume_jogo.setFillColor(sf::Color::White);
  botao_volume_jogo.setOutlineThickness(2);
  botao_volume_jogo.setOutlineColor(purple);
  botao_volume_jogo.setOrigin({0.f, 0.f}); 
  botao_volume_jogo.setPosition({50.f, OFFSET.y + 100.f});

  label_volume_jogo.setString("Volume");
  label_volume_jogo.setCharacterSize(30);
  label_volume_jogo.setFillColor(purple);

  sf::FloatRect lb_vvj = label_volume_jogo.getLocalBounds();
  label_volume_jogo.setOrigin({lb_vvj.size.x / 2.0f, lb_vvj.size.y / 2.0f});
  label_volume_jogo.setPosition({200.f, OFFSET.y + 132.5f});

  //botao trocar musica 
  botao_musica_jogo.setSize({300.f, 65.f});
  botao_musica_jogo.setFillColor(sf::Color::White);
  botao_musica_jogo.setOutlineThickness(2);
  botao_musica_jogo.setOutlineColor(purple);
  botao_musica_jogo.setOrigin({0.f, 0.f}); 
  botao_musica_jogo.setPosition({50.f, OFFSET.y + 200.f});

  label_musica_jogo.setString("Musica");
  label_musica_jogo.setCharacterSize(30);
  label_musica_jogo.setFillColor(purple);

  sf::FloatRect lb_mj = label_musica_jogo.getLocalBounds();
  label_musica_jogo.setOrigin({lb_mj.size.x / 2.0f, lb_mj.size.y / 2.0f});
  label_musica_jogo.setPosition({200.f, OFFSET.y + 232.5f});
  
  //botoes 1,2,3 trocar musica
  label_musica_trocar.setCharacterSize(30);
  label_musica_trocar.setFillColor(purple);

  label_musica_trocar.setOrigin({lb_mj.size.x / 2.0f, lb_mj.size.y / 2.0f});
  label_musica_trocar.setPosition({272.f, OFFSET.y + 232.5f});
  
  //botao voltar jogo
  botao_voltar_jogo.setSize({300.f, 65.f});
  botao_voltar_jogo.setFillColor(sf::Color::White);
  botao_voltar_jogo.setOutlineThickness(2);
  botao_voltar_jogo.setOutlineColor(purple);
  botao_voltar_jogo.setOrigin({0.f, 0.f}); 
  botao_voltar_jogo.setPosition({50.f, OFFSET.y + 671.f});
  
  label_voltar_jogo.setString("Sair");
  label_voltar_jogo.setCharacterSize(30);
  label_voltar_jogo.setFillColor(purple);

  sf::FloatRect lb_vj = label_voltar_jogo.getLocalBounds();
  label_voltar_jogo.setOrigin({lb_vj.size.x / 2.0f, lb_vj.size.y / 2.0f});
  label_voltar_jogo.setPosition({200.f, OFFSET.y + 671.f + 32.5f});
  
  float centroX = 1920.f / 2.f; 
  float centroY = 1080.f / 2.f;

  //efeito de transparencia quando o botao pop up for ativado 
  botao_fundo_escuro.setSize({1920.f, 1080.f});
  // O quarto número (150) é a transparência (0 a 255)
  botao_fundo_escuro.setFillColor(sf::Color(0, 0, 0, 150));
  
  //botao pop up
  botao_pop_up.setSize({800.f, 450.f});
  botao_pop_up.setOrigin({400.f, 225.f});
  botao_pop_up.setPosition({centroX, centroY});
  botao_pop_up.setFillColor(sf::Color::White);
  botao_pop_up.setOutlineThickness(4);
  botao_pop_up.setOutlineColor(purple);

  label_pop_up.setString("Tem certeza que deseja sair?");
  label_pop_up.setCharacterSize(27);
  label_pop_up.setFillColor(purple);
  sf::FloatRect bounds_pu = label_pop_up.getLocalBounds();
  label_pop_up.setOrigin({bounds_pu.position.x + bounds_pu.size.x / 2.f, bounds_pu.position.y + bounds_pu.size.y / 2.f});
  label_pop_up.setPosition({centroX, centroY - 120.f});

  //label detalhe
  label_pop_detalhe.setString("Esse jogo nao vai ser registrado");
  label_pop_detalhe.setCharacterSize(18);
  label_pop_detalhe.setFillColor(purple);
  sf::FloatRect bounds_pd = label_pop_detalhe.getLocalBounds();
  label_pop_detalhe.setOrigin({bounds_pd.position.x + bounds_pd.size.x / 2.f, bounds_pd.position.y + bounds_pd.size.y / 2.f});
  label_pop_detalhe.setPosition({centroX, centroY - 85.f});

  //botao sim
  botao_sim_pop_up.setSize({200.f, 60.f});
  botao_sim_pop_up.setOrigin({100.f, 30.f});
  botao_sim_pop_up.setPosition({centroX - 150.f, centroY + 120.f});
  botao_sim_pop_up.setOutlineThickness(2);
  botao_sim_pop_up.setOutlineColor(purple);

  label_sim_pop_up.setString("Sim");
  sf::FloatRect bounds_s = label_sim_pop_up.getLocalBounds();
  label_sim_pop_up.setOrigin({bounds_s.position.x + bounds_s.size.x / 2.f, bounds_s.position.y + bounds_s.size.y / 2.f});
  label_sim_pop_up.setPosition(botao_sim_pop_up.getPosition());
  label_sim_pop_up.setFillColor(purple);

  //botao nao
  botao_nao_pop_up.setSize({200.f, 60.f});
  botao_nao_pop_up.setOrigin({100.f, 30.f});
  botao_nao_pop_up.setPosition({centroX + 150.f, centroY + 120.f});
  botao_nao_pop_up.setOutlineThickness(2);
  botao_nao_pop_up.setOutlineColor(purple);

  label_nao_pop_up.setString("Nao");
  sf::FloatRect bounds_n = label_nao_pop_up.getLocalBounds();
  label_nao_pop_up.setOrigin({bounds_n.position.x + bounds_n.size.x / 2.f, bounds_n.position.y + bounds_n.size.y / 2.f});
  label_nao_pop_up.setPosition(botao_nao_pop_up.getPosition());
  label_nao_pop_up.setFillColor(purple);

  //botao erro
  float tamanho_sudoku = 9 * TAM_CELULA;

  OFFSET.x = (1920.f - tamanho_sudoku) / 2.f; 
  OFFSET.y = (1080.f - tamanho_sudoku) / 2.f;

  label_erro.setCharacterSize(25);
  label_erro.setFillColor(sf::Color::Red);
  label_erro.setOrigin({0.f, 0.f});
  label_erro.setPosition({50.f, OFFSET.y});

  //botoes painel
  for (int i = 0; i < 9; i++) {
    int linha = i / 3;
    int coluna = i % 3;

    float posX = OFFSET_PAINEL.x + (coluna *(TAM_BOTAO + ESPACAMENTO));
    float posY = OFFSET_PAINEL.y + (linha *(TAM_BOTAO + ESPACAMENTO));

    sf::RectangleShape botao;
    botao.setSize({TAM_BOTAO, TAM_BOTAO});
    botao.setPosition({posX, posY});
    botao.setFillColor(sf::Color::Transparent);
    botao.setOutlineColor(purple);
    botao.setOutlineThickness(2.f);

    botoes_painel.push_back(botao);

    sf::Text label(font);
    label.setString(std::to_string(i + 1));
    label.setCharacterSize(40);
    label.setFillColor(purple);

    sf::FloatRect bounds = label.getLocalBounds();
    label.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
    });

    label.setPosition({
        posX + (TAM_BOTAO / 2.f),
        posY + (TAM_BOTAO / 2.f)
    });

    labeis_painel.push_back(label);
  }

  //botao apagar
  botao_apagar.setSize({TAM_BOTAO * 3 + (ESPACAMENTO * 2), 60.f});
  botao_apagar.setPosition({OFFSET_PAINEL.x, OFFSET_PAINEL.y + (3 * (TAM_BOTAO + ESPACAMENTO))});
  botao_apagar.setFillColor(sf::Color::Transparent);
  botao_apagar.setOutlineColor(purple);
  botao_apagar.setOutlineThickness(2.f);

  label_apagar.setString("X");
  label_apagar.setCharacterSize(40);
  label_apagar.setFillColor(purple);

  sf::FloatRect bounds_apagar = label_apagar.getLocalBounds();
  label_apagar.setOrigin({
    bounds_apagar.position.x + bounds_apagar.size.x / 2.f,
    bounds_apagar.position.y + bounds_apagar.size.y / 2.f
  });

  label_apagar.setPosition({
    OFFSET_PAINEL.x + (botao_apagar.getSize().x / 2.f),
    botao_apagar.getPosition().y + (botao_apagar.getSize().y / 2.f)
  });
} 

//tratar eventos 
void Jogo::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
  if (event.is<sf::Event::MouseButtonPressed>()) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)); 
    sf::FloatRect area_tabuleiro({OFFSET.x, OFFSET.y}, {9 * TAM_CELULA, 9 * TAM_CELULA});
    sf::FloatRect area_painel({OFFSET_PAINEL.x, OFFSET_PAINEL.y,}, {3 * TAM_BOTAO, 3 * TAM_BOTAO});
    auto mousePosT = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    auto mousePosP = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
      if (tela_atual == Tela::Jogo) {
        if (area_tabuleiro.contains(mousePosT) && desativar_tudo == false) {
          int coluna = static_cast<int>((mousePosT.x - OFFSET.x) / TAM_CELULA);
          int linha = static_cast<int>((mousePosT.y - OFFSET.y) / TAM_CELULA);

          selecionada_tabuleiro = {linha, coluna};
          ativarClique();
        } else { selecionada_tabuleiro = {-1, -1}; }

        if (area_painel.contains(mousePosP) && desativar_tudo == false) {
          int coluna = static_cast<int>((mousePosP.x - OFFSET_PAINEL.x) / TAM_BOTAO);
          int linha = static_cast<int>((mousePosP.y - OFFSET_PAINEL.y) / TAM_BOTAO);

          selecionada_painel = {linha, coluna};
          ativarClique();
        } else { selecionada_painel = {-1, -1}; }

        if (botao_apagar.getGlobalBounds().contains(mousePosF)) {
          ativarClique();          
        }

        if (botao_voltar_jogo.getGlobalBounds().contains(mousePosF)) {
            ativarClique();
            popup = true;
            desativar_tudo = true; 
            desativar_pop_up = false;
        }
        
        if (desativar_pop_up == false) {
          if (botao_pop_up.getGlobalBounds().contains(mousePosF)) {
            if (botao_sim_pop_up.getGlobalBounds().contains(mousePosF)) {
              ativarClique();
              //resetar musica assim que sair da tela jogo
              musicaJogo.stop();
              musicaAtualJogo = 0;
              musicaGlobal.play();

              //resetar volume assim que sair da tela jogo 
              musicaGlobal.setVolume(niveis_volume[4]);
              musicaJogo.setVolume(niveis_volume[4]);

              tela_atual = Tela::Menu;
              popup = false;
              desativar_tudo = false;
              desativar_pop_up = true;
            } else if (botao_nao_pop_up.getGlobalBounds().contains(mousePosF)) {
              ativarClique();
              desativar_tudo = false;
              popup = false;
              desativar_pop_up = true;
            }
          }
        }

        if (botao_volume_jogo.getGlobalBounds().contains(mousePosF) && desativar_tudo == false) {
          ativarClique();
          volume_idx = (volume_idx + 1) % 5;
          musicaJogo.setVolume(niveis_volume[volume_idx]);

          if (niveis_volume[volume_idx] == 0) {
            label_volume_jogo.setString("Mudo");  
          } else {
            label_volume_jogo.setString(std::to_string((int)niveis_volume[volume_idx]) + "%"); 
          }

          sf::FloatRect lb_vvj = label_volume_jogo.getLocalBounds();
          label_volume_jogo.setOrigin({lb_vvj.size.x / 2.0f, lb_vvj.size.y / 2.0f});
        }

        if (botao_musica_jogo.getGlobalBounds().contains(mousePosF) && desativar_tudo == false) {
          ativarClique();
          musicaJogo.stop();
          label_musica_jogo.setString("");

          musicaAtualJogo = (musicaAtualJogo + 1) % listaMusicas.size();
          
          std::string caminho = "../assets/" + listaMusicas[musicaAtualJogo];

          if (musicaJogo.openFromFile(caminho)) {
            musicaJogo.play();
            
            if (listaMusicas[musicaAtualJogo] == "musica0.ogg") { 
              label_musica_trocar.setString("1");
            } else if (listaMusicas[musicaAtualJogo] == "musica1.ogg") {
              label_musica_trocar.setString("2");
            } else if (listaMusicas[musicaAtualJogo] == "musica2.ogg") {
              label_musica_trocar.setString("3");
            } 
          }
        } 
      }
    }
  }
}
void Jogo::atualizarHoverJogo(const sf::RenderWindow& window, Tela& tela_atual) {
  sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
  if (tela_atual == Tela::Jogo && popup == false && desativar_tudo == false) {
    if (botao_apagar.getGlobalBounds().contains(mousePos)) {
      botao_apagar.setFillColor(purple);
      label_apagar.setFillColor(sf::Color::White);
    } else {
      botao_apagar.setFillColor(sf::Color::White);
      label_apagar.setFillColor(purple);
    }
    
    if (botao_voltar_jogo.getGlobalBounds().contains(mousePos)) {
      botao_voltar_jogo.setFillColor(purple);
      label_voltar_jogo.setFillColor(sf::Color::White);
    } else {
      botao_voltar_jogo.setFillColor(sf::Color::White);
      label_voltar_jogo.setFillColor(purple);
    } 
    
    if (botao_musica_jogo.getGlobalBounds().contains(mousePos)) {
      botao_musica_jogo.setFillColor(purple);
      label_musica_jogo.setFillColor(sf::Color::White);
      label_musica_trocar.setFillColor(sf::Color::White);
    } else {
      botao_musica_jogo.setFillColor(sf::Color::White);
      label_musica_jogo.setFillColor(purple);
      label_musica_trocar.setFillColor(purple);
    } 
    
    if (botao_volume_jogo.getGlobalBounds().contains(mousePos)) {
      botao_volume_jogo.setFillColor(purple);
      label_volume_jogo.setFillColor(sf::Color::White);
    } else {
      botao_volume_jogo.setFillColor(sf::Color::White);
      label_volume_jogo.setFillColor(purple);
    }
  }
    if (botao_sim_pop_up.getGlobalBounds().contains(mousePos)) {
      botao_sim_pop_up.setFillColor(purple);
      label_sim_pop_up.setFillColor(sf::Color::White);
    } else {
      botao_sim_pop_up.setFillColor(sf::Color::White);
      label_sim_pop_up.setFillColor(purple);
    } 
    
    if (botao_nao_pop_up.getGlobalBounds().contains(mousePos)) {
      botao_nao_pop_up.setFillColor(purple);
      label_nao_pop_up.setFillColor(sf::Color::White);
    } else {
      botao_nao_pop_up.setFillColor(sf::Color::White);
      label_nao_pop_up.setFillColor(purple);
    }

    if (popup) {
      botao_voltar_jogo.setFillColor(sf::Color::White);
      label_voltar_jogo.setFillColor(purple);
    }
}

//animacoes
void Jogo::atualizar() {}

//mostrar na tela 
void Jogo::desenhar(sf::RenderWindow& window) {
    
    //cores sudoku
    sf::RectangleShape celula({TAM_CELULA, TAM_CELULA});
    celula.setFillColor(sf::Color::Transparent);
    celula.setOutlineColor(purple);
    celula.setOutlineThickness(1.f); 

    //desenho quadrado do sudoku
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        celula.setPosition({OFFSET.x + (j * TAM_CELULA), OFFSET.y + (i * TAM_CELULA)});
        
        if (selecionada_tabuleiro.x == i && selecionada_tabuleiro.y == j) {
          celula.setFillColor(transparent_purple);
        } else {
          celula.setFillColor(sf::Color::Transparent);
        }
        window.draw(celula);

        if (grade[i][j] != 0) {
        texto_numero.setString(std::to_string(grade[i][j]));

        sf::FloatRect bounds = texto_numero.getLocalBounds();
        texto_numero.setOrigin({
            bounds.position.x + bounds.size.x / 2.f,
            bounds.position.y + bounds.size.y / 2.f
        });

        texto_numero.setPosition({ 
            OFFSET.x + (j * TAM_CELULA) + (TAM_CELULA / 2.f),
            OFFSET.y + (i * TAM_CELULA) + (TAM_CELULA / 2.f)
        });

        window.draw(texto_numero);
        } 
      }
    }
    
    //linhas verticas e horizontais desenho
    for (int i = 0; i <= 9; i += 3) {
      sf::RectangleShape linhaV(sf::Vector2f(4.f, TAM_CELULA * 9.f)); 
      linhaV.setFillColor(purple);
      linhaV.setPosition({OFFSET.x + (i * TAM_CELULA) - 2.f, OFFSET.y});
      window.draw(linhaV);

      sf::RectangleShape linhaH(sf::Vector2f(TAM_CELULA * 9.f, 4.f));
      linhaH.setFillColor(purple);
      linhaH.setPosition({OFFSET.x, OFFSET.y + (i * TAM_CELULA) - 2.f});
      window.draw(linhaH);
    }

    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    for (int i = 0; i < 9; i++) {

      if (popup == false && desativar_tudo == false) {
        if (botoes_painel[i].getGlobalBounds().contains(mousePos)) {
          botoes_painel[i].setFillColor(purple);
          labeis_painel[i].setFillColor(sf::Color::White);
        } else {
          botoes_painel[i].setFillColor(sf::Color::White);
          labeis_painel[i].setFillColor(purple);
        }
      }

      window.draw(botoes_painel[i]);
      window.draw(labeis_painel[i]);
    }  

    if (dificuldade_selecionada == Dificuldade::Facil) {
      count_erros = 0;
      label_erro.setString("Erros: Ilimitados");
    } else if (dificuldade_selecionada == Dificuldade::Medio) {
      count_erros = 0;
      registrarErros(4);
      label_erro.setString("Erros: " + std::to_string(count_erros) + "/5");
    } else if (dificuldade_selecionada == Dificuldade::Dificil) {
      count_erros = 0;
      registrarErros(2);
      label_erro.setString("Erros: " + std::to_string(count_erros) + "/3");      
    } 

    window.draw(botao_musica_jogo);
    window.draw(botao_volume_jogo);
    window.draw(botao_voltar_jogo);
    window.draw(botao_apagar);

    window.draw(label_erro);
    window.draw(label_volume_jogo);
    window.draw(label_musica_jogo);
    window.draw(label_musica_trocar);
    window.draw(label_voltar_jogo);
    window.draw(label_apagar);

    if (popup) {
      window.draw(botao_fundo_escuro);
      window.draw(botao_pop_up);
      window.draw(label_pop_up);
      window.draw(label_pop_detalhe);

      window.draw(botao_sim_pop_up);
      window.draw(label_sim_pop_up);
      window.draw(botao_nao_pop_up);
      window.draw(label_nao_pop_up);
    } 
    window.display(); 
}