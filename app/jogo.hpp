#pragma once
#include<SFML/Graphics.hpp>
#include"def.hpp"

class Jogo {
  private:
    std::vector<std::string> listaMusicas = {
      "musica0.ogg",
      "musica1.ogg",
      "musica2.ogg"
    };
    int musicaAtual = 0;
    bool popup = false;
    bool desativar_tudo = false;
    bool desativar_pop_up = true;
    int volume_idx = 4;
    float niveis_volume[5] = {0.f, 25.f, 50.f, 75.f, 100.f};
    int count_erros = 0;
    sf::Font font;
    sf::Text titulo;
    sf::Text texto_numero;    
    
    sf::Text label_erro, label_voltar_jogo, label_volume_jogo, label_musica_jogo, label_musica_trocar, label_pop_up, label_sim_pop_up, label_nao_pop_up, label_pop_detalhe;

    sf::RectangleShape botao_voltar_jogo, botao_volume_jogo, botao_musica_jogo, botao_pop_up, botao_sim_pop_up, botao_nao_pop_up, botao_fundo_escuro;
    
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
    void atualizarHoverJogo(const sf::RenderWindow& window, Tela& tela_atual);
    void desenhar(sf::RenderWindow& window);
};
