#pragma once
#include"def.hpp"
#include<SFML/Graphics.hpp>

class ComoJogar {
    private:
    sf::Text titulo;
    sf::Text label_tutorial, label_voltar;
    sf::Font font;
    sf::Clock clock;
    sf::Color purple = sf::Color(128, 0, 128);  
    sf::RectangleShape caixa_tutorial, botao_voltar;
    public: 
    ComoJogar(const sf::Vector2u& windowSize);
    void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
    void atualizar();
    void atualizarHoverComoJogar(const sf::RenderWindow& window, Tela& tela_atual);
    void desenhar(sf::RenderWindow& window);
};