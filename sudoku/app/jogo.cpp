#include<iostream>
#include"jogo.hpp"
#include<cmath>
#include<cstdlib>

Jogo::Jogo(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
      titulo(font), 
      label_facil(font) 
{

  //configura o titulo
  titulo.setString("Sudoku da Fernanda");
  titulo.setCharacterSize(45);
  sf::Color purple(128, 0, 128);
  titulo.setFillColor(purple);
  sf::FloatRect bounds = titulo.getLocalBounds();
  titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

  //configura botoes facil, medio, dificil
  botao_facil.setSize({200.f, 60.f});
  botao_facil.setFillColor(sf::Color::White);
  botao_facil.setOutlineThickness(2);
  botao_facil.setOutlineColor(purple);
  botao_facil.setOrigin({100.f, 30.f});
  botao_facil.setPosition({windowSize.x / 2.0f, 300.f});

  label_facil.setString("Facil");
  label_facil.setCharacterSize(35);
  label_facil.setFillColor(purple);
  sf::FloatRect lb_f = label_facil.getLocalBounds();
  label_facil.setOrigin({lb_f.size.x / 2.0f, lb_f.size.y / 2.0f});
  label_facil.setPosition(botao_facil.getPosition());
}

//tratar eventos 
void Jogo::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
  if (event.is<sf::Event::MouseButtonPressed>()) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

    if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
      if (botao_facil.getGlobalBounds().contains(mousePosF)) {
        //tela_atual = Tela::Sudoku;
     // } else if (botao_medio.getGlobalBounds.contains(mousePosF)) {
        //tela_atual = Tela::Sudoku;
      //} else if (botao_dificil.getGlobalBounds.contains(mousePosF)){
        //tela_atual = Tela::Sudoku;
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
}
