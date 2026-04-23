#include<iostream>
#include"jogo.hpp"
#include<cmath>
#include<cstdlib>
#include<string>

Jogo::Jogo(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
      titulo(font), 
      texto_numero(font),
      label_facil(font),
      label_medio(font),
      label_dificil(font),
      label_voltar(font),
      label_voltar_jogo(font),
      label_erro(font),
      label_volume_jogo(font),
      label_musica_jogo(font),
      label_musica_trocar(font),
      label_esconder(font)
{

  //configura o titulo
  titulo.setString("Sudoku da Fernanda");
  titulo.setCharacterSize(55);
  titulo.setFillColor(purple);
  sf::FloatRect bounds = titulo.getLocalBounds();
  titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

  //botao facil
  botao_facil.setSize({400.f, 80.f});
  botao_facil.setFillColor(sf::Color::White);
  botao_facil.setOutlineThickness(2);
  botao_facil.setOutlineColor(purple);
  botao_facil.setOrigin({200.f, 40.f});
  botao_facil.setPosition({windowSize.x / 2.0f, 300.f});

  label_facil.setString("Facil");
  label_facil.setCharacterSize(40);
  label_facil.setFillColor(purple);
  sf::FloatRect lb_f = label_facil.getLocalBounds();
  label_facil.setOrigin({lb_f.size.x / 2.0f, lb_f.size.y / 2.0f});
  label_facil.setPosition(botao_facil.getPosition());

  //botao medio
  botao_medio.setSize({400.f, 80.f});
  botao_medio.setFillColor(sf::Color::White);
  botao_medio.setOutlineThickness(2);
  botao_medio.setOutlineColor(purple);
  botao_medio.setOrigin({200.f, 40.f});
  botao_medio.setPosition({windowSize.x / 2.0f, 400.f});

  label_medio.setString("Medio");
  label_medio.setCharacterSize(40);
  label_medio.setFillColor(purple);
  sf::FloatRect lb_m = label_medio.getLocalBounds();
  label_medio.setOrigin({lb_m.size.x / 2.0f, lb_m.size.y / 2.0f});
  label_medio.setPosition(botao_medio.getPosition());

  //botao dificil
  botao_dificil.setSize({400.f, 80.f});
  botao_dificil.setFillColor(sf::Color::White);
  botao_dificil.setOutlineThickness(2);
  botao_dificil.setOutlineColor(purple);
  botao_dificil.setOrigin({200.f, 40.f});
  botao_dificil.setPosition({windowSize.x / 2.0f, 500.f});

  label_dificil.setString("Dificil");
  label_dificil.setCharacterSize(40);
  label_dificil.setFillColor(purple);
  sf::FloatRect lb_d = label_dificil.getLocalBounds();
  label_dificil.setOrigin({lb_d.size.x / 2.0f, lb_d.size.y / 2.0f});
  label_dificil.setPosition(botao_dificil.getPosition());

  //botao voltar
  botao_voltar.setSize({300.f, 65.f});
  botao_voltar.setFillColor(sf::Color::White);
  botao_voltar.setOutlineThickness(2);
  botao_voltar.setOutlineColor(purple);
  botao_voltar.setOrigin({150.f, 32.5f});
  botao_voltar.setPosition({windowSize.x / 2.0f, 650.f});

  label_voltar.setString("Voltar");
  label_voltar.setCharacterSize(35);
  label_voltar.setFillColor(purple);
  sf::FloatRect lb_v = label_voltar.getLocalBounds();
  label_voltar.setOrigin({lb_v.size.x / 2.0f, lb_v.size.y / 2.0f});
  label_voltar.setPosition(botao_voltar.getPosition());

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

  //botao esconder botoes
  botao_esconder.setSize({300.f, 65.f});
  botao_esconder.setFillColor(sf::Color::White);
  botao_esconder.setOutlineThickness(2);
  botao_esconder.setOutlineColor(purple);
  botao_esconder.setOrigin({0.f, 0.f});
  botao_esconder.setPosition({50.f, OFFSET.y + 300.f});

  label_esconder.setString("Esconder");
  label_esconder.setCharacterSize(30);
  label_esconder.setFillColor(purple);

  sf::FloatRect lb_es = label_esconder.getLocalBounds();
  label_esconder.setOrigin({lb_es.size.x / 2.0f, lb_es.size.y / 2.0f});
  label_esconder.setPosition({200.f, OFFSET.y + 332.5f});
 
  //botao voltar jogo
  botao_voltar_jogo.setSize({300.f, 65.f});
  botao_voltar_jogo.setFillColor(sf::Color::White);
  botao_voltar_jogo.setOutlineThickness(2);
  botao_voltar_jogo.setOutlineColor(purple);
  botao_voltar_jogo.setOrigin({0.f, 0.f}); 
  botao_voltar_jogo.setPosition({50.f, OFFSET.y + 650.f});
  label_voltar_jogo.setString("Sair");
  label_voltar_jogo.setCharacterSize(30);
  label_voltar_jogo.setFillColor(purple);

  sf::FloatRect lb_vj = label_voltar_jogo.getLocalBounds();
  label_voltar_jogo.setOrigin({lb_vj.size.x / 2.0f, lb_vj.size.y / 2.0f});
  label_voltar_jogo.setPosition({200.f, OFFSET.y + 682.5f});
  
  //botao erro
  float tamanho_sudoku = 9 * TAM_CELULA;

  OFFSET.x = (1920.f - tamanho_sudoku) / 2.f; 
  OFFSET.y = (1080.f - tamanho_sudoku) / 2.f;

  label_erro.setCharacterSize(25);
  label_erro.setFillColor(sf::Color::Red);
  label_erro.setOrigin({0.f, 0.f});
  label_erro.setPosition({50.f, OFFSET.y});
} 

//tratar eventos 
void Jogo::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
  if (event.is<sf::Event::MouseButtonPressed>()) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

    if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
      if (!jogo_iniciado) {
        if (botao_facil.getGlobalBounds().contains(mousePosF)) {
          dificuldade_selecionada = Dificuldade::Facil;
          jogo_iniciado = true;     
        } else if (botao_medio.getGlobalBounds().contains(mousePosF)) {
          dificuldade_selecionada = Dificuldade::Medio;
          jogo_iniciado = true;
        } else if (botao_dificil.getGlobalBounds().contains(mousePosF)) {
          dificuldade_selecionada = Dificuldade::Dificil;
          jogo_iniciado = true;
        } else if (botao_voltar.getGlobalBounds().contains(mousePosF)) {
          tela_atual = Tela::Menu;
        } 
      } else if (jogo_iniciado && parar_funcionar == false) { 
        if (dificuldade_selecionada == Dificuldade::Facil) {
          if (botao_voltar_jogo.getGlobalBounds().contains(mousePosF)) {
            // POR ENQUANTO DEPOIS COLOCAR NOS 3 AQUI, LOGICA PARA POP UP CONFIRMANDO SE QUER SAIR
            tela_atual = Tela::Menu;
            dificuldade_selecionada = Dificuldade::Nenhum;
            jogo_iniciado = false;
          }
        } else if (dificuldade_selecionada == Dificuldade::Medio) {
          if (botao_voltar_jogo.getGlobalBounds().contains(mousePosF)) {
            tela_atual = Tela::Menu;
            dificuldade_selecionada = Dificuldade::Nenhum;
            jogo_iniciado = false;
          } 
        } else if (dificuldade_selecionada == Dificuldade::Dificil) {
          if (botao_voltar_jogo.getGlobalBounds().contains(mousePosF)) {
            tela_atual = Tela::Menu;
            dificuldade_selecionada = Dificuldade::Nenhum;
            jogo_iniciado = false;
          } 
        }
        
        if (botao_volume_jogo.getGlobalBounds().contains(mousePosF)) {
          volume_idx = (volume_idx + 1) % 5;
          musicaGlobal.setVolume(niveis_volume[volume_idx]);

          if (niveis_volume[volume_idx] == 0) {
            label_volume_jogo.setString("Mudo");
          } else {
            label_volume_jogo.setString(std::to_string((int)niveis_volume[volume_idx]) + "%");
          }

          sf::FloatRect lb_vvj = label_volume_jogo.getLocalBounds();
          label_volume_jogo.setOrigin({lb_vvj.size.x / 2.0f, lb_vvj.size.y / 2.0f});
        }

        if (botao_musica_jogo.getGlobalBounds().contains(mousePosF)) {
          musicaGlobal.stop();
          label_musica_jogo.setString("");

          musicaAtual = (musicaAtual + 1) % listaMusicas.size();

          std::string caminho = "../assets/" + listaMusicas[musicaAtual];

          if (musicaGlobal.openFromFile(caminho)) {
            musicaGlobal.play();
            
            if (listaMusicas[musicaAtual] == "musica0.ogg") { 
              label_musica_trocar.setString("1");
            } else if (listaMusicas[musicaAtual] == "musica1.ogg") {
              label_musica_trocar.setString("2");
            } else if (listaMusicas[musicaAtual] == "musica2.ogg") {
              label_musica_trocar.setString("3");
            }
          }
        }

        if (botao_esconder.getGlobalBounds().contains(mousePosF)) {
          parar_funcionar = true;
          escondeu = true;
        }
      }
    }
  }
}

//animacoes
void Jogo::atualizar() {
  float tempo = clock.getElapsedTime().asSeconds();
  float escala = 1.0f + std::sin(tempo * 5.0f) * 0.1f;
  titulo.setScale({escala, escala});

  titulo.setPosition({1920 / 2.0f, 60.f});
}

//mostrar na tela 
void Jogo::desenhar(sf::RenderWindow& window) {
  window.clear(sf::Color::White);

  if (!jogo_iniciado) 
  {
    window.draw(titulo);
    window.draw(botao_facil);
    window.draw(label_facil);
    window.draw(botao_medio);
    window.draw(label_medio);
    window.draw(botao_dificil);
    window.draw(label_dificil);
    window.draw(botao_voltar);
    window.draw(label_voltar);
  } 
  else 
  {
    //cores sudoku
    sf::RectangleShape celula({TAM_CELULA, TAM_CELULA});
    celula.setFillColor(sf::Color::Transparent);
    celula.setOutlineColor(purple);
    celula.setOutlineThickness(1.f); 

    //desenho quadrado do sudoku
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        celula.setPosition({OFFSET.x + (j * TAM_CELULA), OFFSET.y + (i * TAM_CELULA)});
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

    if (!escondeu) {
      window.draw(botao_musica_jogo);
      window.draw(botao_volume_jogo);
      window.draw(botao_voltar_jogo);
      window.draw(botao_esconder);
      window.draw(label_erro);
      window.draw(label_volume_jogo);
      window.draw(label_musica_jogo);
      window.draw(label_musica_trocar);
      window.draw(label_voltar_jogo);
      window.draw(label_esconder);
    } else if (escondeu) {
      window.clear(sf::Color::White);
      
      //redesenha quadrado aqui:
      
      //cores sudoku
      sf::RectangleShape celula({TAM_CELULA, TAM_CELULA});
      celula.setFillColor(sf::Color::Transparent);
      celula.setOutlineColor(purple);
      celula.setOutlineThickness(1.f); 

      //desenho quadrado do sudoku
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          celula.setPosition({OFFSET.x + (j * TAM_CELULA), OFFSET.y + (i * TAM_CELULA)});
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

      window.draw(label_erro);
      
      window.display(); 
    }
  }
}  


