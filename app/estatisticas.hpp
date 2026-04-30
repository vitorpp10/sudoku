#pragma once
#include<SFML/Graphics.hpp>
#include"def.hpp"

class Estatisticas {
    private:
        sf::Font font;
        sf::Text titulo;
        sf::Text label_caixa, label_perfil, label_vitoria, label_derrota, label_streak, label_voltar;
        sf::RectangleShape botao_caixa, botao_perfil, botao_vitoria, botao_derrota, botao_streak, botao_voltar;
        sf::Color purple = sf::Color(128, 0, 128);
        sf::Clock clock;
    public:
        Estatisticas(const sf::Vector2u& windowSize);

        void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
        void atualizar();
        void atualizarHoverEstatisticas(const sf::RenderWindow& window, Tela& tela_atual);
        void desenhar(sf::RenderWindow& window);
};