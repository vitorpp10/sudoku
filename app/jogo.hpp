#pragma once
#include<SFML/Graphics.hpp>
#include"def.hpp"
#include<vector>

class Jogo {
  private:
    std::vector<std::string> listaMusicas = {
      "musica0.ogg",
      "musica1.ogg",
      "musica2.ogg"
    };
    bool ganhou = false; 
    bool perdeu = false;
    int streak = 0;
    int vitorias = 0;
    int derrotas = 0;
    int gabarito[9][9];
    bool errou[9][9];
    int count_erros;
    sf::Music musicaErro;
    std::string caminho_erro = "../assets/erro.ogg";
    int musicaAtual = 0;
    bool popup = false;
    bool desativar_tudo = false;
    bool desativar_pop_up = true;
    bool desativar_pop_up_derrota = false;
    bool desativar_pop_up_vitoria = false;
    int volume_idx = 4;
    float niveis_volume[5] = {0.f, 25.f, 50.f, 75.f, 100.f};
    sf::Font font;
    sf::Text titulo;
    sf::Text texto_numero;    
    
    sf::Text label_erro, label_voltar_jogo, label_volume_jogo, label_musica_jogo, label_musica_trocar, label_pop_up, label_sim_pop_up, label_nao_pop_up, label_pop_detalhe, label_apagar, label_derrota, label_vitoria, label_continuar, label_derrota_detalhe, label_vitoria_detalhe;

    sf::RectangleShape botao_voltar_jogo, botao_volume_jogo, botao_musica_jogo, botao_pop_up, botao_sim_pop_up, botao_nao_pop_up, botao_fundo_escuro, botao_apagar, botao_derrota, botao_vitoria, botao_continuar;

    std::vector<sf::RectangleShape> botoes_painel;
    std::vector<sf::Text> labeis_painel;

    sf::Clock clock;

    //medidas tabuleiro e input 
    int grade_input[9][9];
    sf::Vector2i selecionada_tabuleiro = {-1, -1}; 
    sf::Vector2i selecionada_painel = {-1, -1};
    const float TAM_CELULA = 80.f;
    sf::Vector2f OFFSET = {100.f, 150.f};
    sf::Vector2f OFFSET_PAINEL = {70.f, 450.f};
    const float ESPACAMENTO = 10.f;
    const float TAM_BOTAO = 80.f;
    sf::Color purple = sf::Color(128, 0, 128);
    sf::Color transparent_purple = sf::Color(128, 0, 128, 100);
    
    int grade[9][9] = {0};
    bool numero_fixo[9][9] = {0};
    bool numero_valido(int linha, int coluna, int num);
    bool preencher_tabuleiro();
  public:
    void registrarJogada(int linha, int coluna, int num);

    bool checarVitoria();
    
    void gerarNovoJogo(DificuldadeJogo x);
    
    Jogo(const sf::Vector2u& windowSize);

    void tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual);
    void atualizar();
    void atualizarHoverJogo(const sf::RenderWindow& window, Tela& tela_atual);
    void desenhar(sf::RenderWindow& window);
};
