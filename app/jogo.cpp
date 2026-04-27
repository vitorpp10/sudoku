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
      label_pop_up(font),
      label_sim_pop_up(font),
      label_nao_pop_up(font),
      label_pop_detalhe(font)
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
          musicaGlobal.stop();
          musicaJogo.play();
        } else if (botao_medio.getGlobalBounds().contains(mousePosF)) {
          dificuldade_selecionada = Dificuldade::Medio;
          jogo_iniciado = true;
          musicaGlobal.stop();
          musicaJogo.play();
        } else if (botao_dificil.getGlobalBounds().contains(mousePosF)) {
          dificuldade_selecionada = Dificuldade::Dificil;
          jogo_iniciado = true;
          musicaGlobal.stop();
          musicaJogo.play();
        } else if (botao_voltar.getGlobalBounds().contains(mousePosF)) {
          tela_atual = Tela::Menu;
        } 
      } else if (jogo_iniciado) {
        if (botao_voltar_jogo.getGlobalBounds().contains(mousePosF)) {
            popup = true;
            desativar_tudo = true; 
        }
        
        if (botao_pop_up.getGlobalBounds().contains(mousePosF)) {
          if (botao_sim_pop_up.getGlobalBounds().contains(mousePosF)) {
            //resetar musica assim que sair da tela jogo
            musicaJogo.stop();
            musicaAtualJogo = 0;
            musicaGlobal.play();

            //resetar volume assim que sair da tela jogo 
            musicaGlobal.setVolume(niveis_volume[4]);
            musicaJogo.setVolume(niveis_volume[4]);

            tela_atual = Tela::Menu;
            dificuldade_selecionada = Dificuldade::Nenhum;
            jogo_iniciado = false;
            popup = false;
            desativar_tudo = false;
          } else if (botao_nao_pop_up.getGlobalBounds().contains(mousePosF)) {
            desativar_tudo = false;
            popup = false;
          }
        }

        if (botao_volume_jogo.getGlobalBounds().contains(mousePosF) && desativar_tudo == false) {
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

    window.draw(botao_musica_jogo);
    window.draw(botao_volume_jogo);
    window.draw(botao_voltar_jogo);
    window.draw(label_erro);
    window.draw(label_volume_jogo);
    window.draw(label_musica_jogo);
    window.draw(label_musica_trocar);
    window.draw(label_voltar_jogo);

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

  }
  window.display(); 
}  
