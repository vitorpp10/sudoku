#include<iostream>
#include"jogo.hpp"
#include<cmath>
#include<cstdlib>

Jogo::Jogo(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
      titulo(font), 
      label_facil(font),
      label_medio(font),
      label_dificil(font),
      label_voltar(font)
{

  //configura o titulo
  titulo.setString("Sudoku da Fernanda");
  titulo.setCharacterSize(55);
  sf::Color purple(128, 0, 128);
  titulo.setFillColor(purple);
  sf::FloatRect bounds = titulo.getLocalBounds();
  titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

  //botao facil
  botao_facil.setSize({300.f, 60.f});
  botao_facil.setFillColor(sf::Color::White);
  botao_facil.setOutlineThickness(2);
  botao_facil.setOutlineColor(purple);
  botao_facil.setOrigin({150.f, 30.f});
  botao_facil.setPosition({windowSize.x / 2.0f, 300.f});

  label_facil.setString("Facil");
  label_facil.setCharacterSize(35);
  label_facil.setFillColor(purple);
  sf::FloatRect lb_f = label_facil.getLocalBounds();
  label_facil.setOrigin({lb_f.size.x / 2.0f, lb_f.size.y / 2.0f});
  label_facil.setPosition(botao_facil.getPosition());

  //botao medio
  botao_medio.setSize({300.f, 60.f});
  botao_medio.setFillColor(sf::Color::White);
  botao_medio.setOutlineThickness(2);
  botao_medio.setOutlineColor(purple);
  botao_medio.setOrigin({150.f, 30.f});
  botao_medio.setPosition({windowSize.x / 2.0f, 400.f});

  label_medio.setString("Medio");
  label_medio.setCharacterSize(35);
  label_medio.setFillColor(purple);
  sf::FloatRect lb_m = label_medio.getLocalBounds();
  label_medio.setOrigin({lb_m.size.x / 2.0f, lb_m.size.y / 2.0f});
  label_medio.setPosition(botao_medio.getPosition());

  //botao dificil
  botao_dificil.setSize({300.f, 60.f});
  botao_dificil.setFillColor(sf::Color::White);
  botao_dificil.setOutlineThickness(2);
  botao_dificil.setOutlineColor(purple);
  botao_dificil.setOrigin({150.f, 30.f});
  botao_dificil.setPosition({windowSize.x / 2.0f, 500.f});

  label_dificil.setString("Dificil");
  label_dificil.setCharacterSize(35);
  label_dificil.setFillColor(purple);
  sf::FloatRect lb_d = label_dificil.getLocalBounds();
  label_dificil.setOrigin({lb_d.size.x / 2.0f, lb_d.size.y / 2.0f});
  label_dificil.setPosition(botao_dificil.getPosition());

  //botao voltar
  botao_voltar.setSize({220.f, 55.f});
  botao_voltar.setFillColor(sf::Color::White);
  botao_voltar.setOutlineThickness(2);
  botao_voltar.setOutlineColor(purple);
  botao_voltar.setOrigin({90.f, 27.5f});
  botao_voltar.setPosition({windowSize.x / 2.0f, 650.f});

  label_voltar.setString("Voltar");
  label_voltar.setCharacterSize(35);
  label_voltar.setFillColor(purple);
  sf::FloatRect lb_v = label_voltar.getLocalBounds();
  label_voltar.setOrigin({lb_v.size.x / 2.0f, lb_v.size.y / 2.0f});
  label_voltar.setPosition(botao_voltar.getPosition());
}

//tratar eventos 
void Jogo::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
  if (event.is<sf::Event::MouseButtonPressed>()) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

    if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
      if (botao_facil.getGlobalBounds().contains(mousePosF)) {
      } else if (botao_voltar.getGlobalBounds().contains(mousePosF)) {
        tela_atual = Tela::Menu;
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
