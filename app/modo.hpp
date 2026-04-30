#pragma once
#include"def.hpp"
#include<SFML/Graphics.hpp>

class Modo {
    private:
        sf::Font font;
        sf::Text titulo;
        sf::Text label_facil, label_medio, label_dificil, label_voltar;
        sf::RectangleShape botao_facil, botao_medio, botao_dificil, botao_voltar;
        sf::Clock clock;
        sf::Color purple = sf::Color(128, 0, 128);
        Dificuldade dificuldade_selecionada = Dificuldade::Nenhum;
    public: 
        Modo(const sf::Vector2u& windowSize);

        void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
        void atualizar();
        void atualizarHoverModo(const sf::RenderWindow& window, Tela& tela_atual);
        void desenhar(sf::RenderWindow& window);
};