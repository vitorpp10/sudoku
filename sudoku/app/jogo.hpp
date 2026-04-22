#pragma once
#include<SFML/Graphics.hpp>
#include"def.hpp"
#include<optional>

class Jogo {
  private:
    bool jogo_iniciado = false; 
    Dificuldade dificuldade_selecionada = Dificuldade::Nenhum;
    int count_erros = 0;
    sf::Font font;
    sf::Text titulo;
      sf::Text texto_numero;
    sf::Text label_facil, label_medio, label_dificil, label_voltar, label_erro, label_voltar_jogo;
    sf::RectangleShape botao_facil, botao_medio, botao_dificil, botao_voltar, botao_voltar_jogo;
    sf::Clock clock;
    //medidas tabuleiro 
    const float TAM_CELULA = 80.f;
    sf::Vector2f OFFSET = {100.f, 150.f};
    sf::Color purple = sf::Color(128, 0, 128);
    int grade[9][9] = {0};
  public:
    void registrarErros(int n) {
      count_erros += n;
    }

    int getErros() const {
      return count_erros;
    } 

    void resetErros() {
      count_erros = 0;
    }

    Jogo(const sf::Vector2u& windowSize);

    void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
    void atualizar();
    void desenhar(sf::RenderWindow& window);
};
