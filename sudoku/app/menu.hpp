#pragma once //para o compilador nao executar duas vezes
#include<SFML/Graphics.hpp> 
#include"def.hpp"
#include<optional> // encapsular coisas de outros arquivos 

class Menu {
  private:
    sf::Font font;
    sf::Text titulo;
    sf::Text label_jogar, label_opcoes;
    sf::RectangleShape botao_jogar, botao_opcoes;
    sf::Clock clock;
  public:
    Menu(const sf::Vector2u& windowSize);

    void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
    void atualizar();
    void desenhar(sf::RenderWindow& window);
};  
