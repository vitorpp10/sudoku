#pragma once //para o compilador nao executar duas vezes
#include<SFML/Graphics.hpp> 
#include <SFML/Graphics/RenderWindow.hpp>
#include"def.hpp"

class Menu {
  private:
    sf::Font font;
    sf::Text titulo;
    sf::Text label_jogar, label_opcoes;
    sf::RectangleShape botao_jogar, botao_opcoes;
    sf::Color purple = sf::Color(128, 0, 128);
    sf::Clock clock;
  public:
    Menu(const sf::Vector2u& windowSize);

    void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
    void atualizar();
    void atualizarHoverMenu(const sf::RenderWindow& window, Tela& tela_atual);
    void desenhar(sf::RenderWindow& window);
};  
