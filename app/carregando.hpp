#pragma once
#include<SFML/Graphics.hpp>
#include"def.hpp"
#include<vector>

class Carregando {
    private:
        sf::Font font;
        std::vector<sf::RectangleShape> barra_progresso;
        sf::Text label_carregando, label_cancelar;
        sf::RectangleShape botao_cancelar;
        sf::Color purple = sf::Color(128, 0, 128);
        sf::Clock clock, clock_progresso;
        int bloco_atual = 0;
        float tempo_proximo_bloco = (std::rand() % 8 + 1) / 10.0f;
    public:
        Carregando(const sf::Vector2u& windowSize);
        
        void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
        void atualizar(Tela& tela_atual);
        void atualizarHoverCarregando(const sf::RenderWindow& window, Tela& tela_atual);
        void desenhar(sf::RenderWindow& window);
};