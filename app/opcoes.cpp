#include<iostream>
#include"opcoes.hpp"
#include"def.hpp"
#include<cmath>
#include<cstdlib>
#include<string>

Opcoes::Opcoes(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
      titulo(font), 
      label_volume(font),
      label_voltar(font),
      label_musica(font)
{

  //configura o titulo
  titulo.setString("Sudoku da Fernanda");
  titulo.setCharacterSize(55);
  sf::Color purple(128, 0, 128);
  titulo.setFillColor(purple);
  sf::FloatRect bounds = titulo.getLocalBounds();
  titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});


  // configura a música
  if (!musicaGlobal.openFromFile("../assets/musica0.ogg")) {
      perror("erro na musica da fernanda");
      exit(EXIT_FAILURE);
  }
  musicaGlobal.play();

  //botao volume
  botao_volume.setSize({450.f, 80.f});
  botao_volume.setFillColor(sf::Color::White);
  botao_volume.setOutlineThickness(2);
  botao_volume.setOutlineColor(purple);
  botao_volume.setOrigin({225.f, 40.f});
  botao_volume.setPosition({windowSize.x / 2.0f, 300.f});

  label_volume.setString("Volume");
  label_volume.setCharacterSize(35);
  label_volume.setFillColor(purple);
  sf::FloatRect lb_v = label_volume.getLocalBounds();
  label_volume.setOrigin({lb_v.size.x / 2.0f, lb_v.size.y / 2.0f});
  label_volume.setPosition(botao_volume.getPosition());

  //centralizar na caixa
  sf::FloatRect boundsVol = label_volume.getLocalBounds();
  label_volume.setOrigin({boundsVol.position.x + boundsVol.size.x / 2.f, 
                        boundsVol.position.y + boundsVol.size.y / 2.f});
  label_volume.setPosition(botao_volume.getPosition());
  
  botao_musica.setSize({450.f, 80.f});
  botao_musica.setFillColor(sf::Color::White);
  botao_musica.setOutlineThickness(2);
  botao_musica.setOutlineColor(purple);
  botao_musica.setOrigin({225.f, 40.f});
  botao_musica.setPosition({windowSize.x / 2.0f, 400.f});

  label_musica.setString("Mudar musica");
  label_musica.setCharacterSize(35);
  label_musica.setFillColor(purple);
  sf::FloatRect lb_m = label_musica.getLocalBounds();
  label_musica.setOrigin({lb_m.size.x / 2.0f, lb_m.size.y / 2.0f});
  label_musica.setPosition(botao_musica.getPosition());

  sf::FloatRect boundsMus = label_musica.getLocalBounds();
  label_musica.setOrigin({boundsMus.position.x + boundsMus.size.x / 2.f, 
                        boundsMus.position.y + boundsMus.size.y / 2.f});
  label_musica.setPosition(botao_musica.getPosition());

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
  sf::FloatRect lb_vv = label_voltar.getLocalBounds();
  label_voltar.setOrigin({lb_vv.size.x / 2.0f, lb_vv.size.y / 2.0f});
  label_voltar.setPosition(botao_voltar.getPosition());

  sf::FloatRect boundsVlt = label_voltar.getLocalBounds();
  label_voltar.setOrigin({boundsVlt.position.x + boundsVlt.size.x / 2.f, 
                        boundsVlt.position.y + boundsVlt.size.y / 2.f});
  label_voltar.setPosition(botao_voltar.getPosition());
} 

//tratar eventos 
void Opcoes::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
  if (event.is<sf::Event::MouseButtonPressed>()) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

    if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
      if (botao_volume.getGlobalBounds().contains(mousePosF)) {
        volume_idx = (volume_idx + 1) % 5;

        musicaGlobal.setVolume(niveis_volume[volume_idx]);

        if (niveis_volume[volume_idx] == 0) {
          label_volume.setString("Volume: Mudo");
        } else {
          label_volume.setString("Volume: " + std::to_string((int)niveis_volume[volume_idx]) + "%");
        }

        sf::FloatRect lb = label_volume.getLocalBounds();
        label_volume.setOrigin({lb.size.x / 2.0f, lb.size.y / 2.0f});
      } else if (botao_voltar.getGlobalBounds().contains(mousePosF)) {
        tela_atual = Tela::Menu;
      } else if (botao_musica.getGlobalBounds().contains(mousePosF)) {
        musicaGlobal.stop();

        musicaAtual = (musicaAtual + 1) % listaMusicas.size();

        std::string caminho = "../assets/" + listaMusicas[musicaAtual];

        if (musicaGlobal.openFromFile(caminho)) {
          musicaGlobal.play();

          if (listaMusicas[musicaAtual] == "musica0.ogg") {
            label_musica.setString("Rihanna 1");
            sf::FloatRect bounds = label_musica.getLocalBounds();
            label_musica.setOrigin({
              bounds.position.x + bounds.size.x / 2.f, 
              bounds.position.y + bounds.size.y / 2.f
            });
            label_musica.setPosition(botao_musica.getPosition());
          } else if (listaMusicas[musicaAtual] == "musica1.ogg") { 
            label_musica.setString("Rihanna 2");
            sf::FloatRect bounds = label_musica.getLocalBounds();
            label_musica.setOrigin({
              bounds.position.x + bounds.size.x / 2.f, 
              bounds.position.y + bounds.size.y / 2.f
            });
          } else if (listaMusicas[musicaAtual] == "musica2.ogg") {
            label_musica.setString("Shakira");
            sf::FloatRect bounds = label_musica.getLocalBounds();
            label_musica.setOrigin({
              bounds.position.x + bounds.size.x / 2.f, 
              bounds.position.y + bounds.size.y / 2.f
            });
          }
        }
      } 
    }
  }
}

//animacoes
void Opcoes::atualizar() {
  float tempo = clock.getElapsedTime().asSeconds();
  float escala = 1.0f + std::sin(tempo * 5.0f) * 0.1f;
  titulo.setScale({escala, escala});

  titulo.setPosition({1920 / 2.0f, 60.f});
}

//mostrar na tela 
void Opcoes::desenhar(sf::RenderWindow& window) {
  window.draw(titulo);
  window.draw(botao_volume);
  window.draw(label_volume);
  window.draw(botao_voltar);
  window.draw(label_voltar);
  window.draw(botao_musica);
  window.draw(label_musica);
}
