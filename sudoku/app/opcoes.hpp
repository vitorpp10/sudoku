#pragma once
#include<SFML/Graphics.hpp>
#include<optional>
#include"def.hpp"
#include<vector>
#include<string>

class Opcoes {
  private:
    std::vector<std::string> listaMusicas = {
      "musica0.ogg",
      "musica1.ogg",
      "musica2.ogg"
    };
    int musicaAtual = 0;
    int volume_idx = 4;
    float niveis_volume[5] = {0.f, 25.f, 50.f, 75.f, 100.f};
    sf::Font font;
    sf::Text titulo;
    sf::Text label_volume, label_voltar, label_musica;
    sf::RectangleShape botao_volume, botao_voltar, botao_musica;
    sf::Clock clock;
  public:
    Opcoes(const sf::Vector2u& windowSize);

    void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
    void atualizar();
    void desenhar(sf::RenderWindow& window);
};
