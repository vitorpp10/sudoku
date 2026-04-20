#pragma once
#include<SFML/Graphics.hpp>
#include<optional>
#include"def.hpp"

class Jogo {
  private:
    sf::Font font;
    sf::Text titulo;
    sf::Text label_facil;
    sf::RectangleShape botao_facil;
    sf::Clock clock;
  public:
    Jogo(const sf::Vector2u& windowSize);

    void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
    void atualizar();
    void desenhar(sf::RenderWindow& window);
};
