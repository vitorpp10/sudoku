#include"menu.hpp"
#include<cmath>
#include<iostream>
#include"def.hpp"
#include<cstdlib>

Menu::Menu(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
      titulo(font), 
      label_jogar(font), 
      label_opcoes(font)
{
    // configura o título
    titulo.setString("Sudoku da Fernanda");
    titulo.setCharacterSize(55);
    sf::Color purple(128, 0, 128);
    titulo.setFillColor(purple);
    sf::FloatRect bounds = titulo.getLocalBounds();
    titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

    // configura a música
    if (!musicaGlobal.openFromFile("../assets/musica0.ogg")) {
        perror("erro na musica da fernanda");
        exit(EXIT_FAILURE);
    }
    musicaGlobal.play();

    //botao jogar
    botao_jogar.setSize({400.f, 80.f});
    botao_jogar.setFillColor(sf::Color::White);
    botao_jogar.setOutlineThickness(2);
    botao_jogar.setOutlineColor(purple);
    botao_jogar.setOrigin({200.f, 40.f});
    botao_jogar.setPosition({windowSize.x / 2.0f, 300.f});

    label_jogar.setString("Jogar");
    label_jogar.setCharacterSize(40);
    label_jogar.setFillColor(purple);
    sf::FloatRect lb = label_jogar.getLocalBounds();
    label_jogar.setOrigin({lb.size.x / 2.0f, lb.size.y / 2.0f});
    label_jogar.setPosition(botao_jogar.getPosition());

    //botao opcoes
    botao_opcoes.setSize({400.f, 80.f});
    botao_opcoes.setFillColor(sf::Color::White);
    botao_opcoes.setOutlineThickness(2);
    botao_opcoes.setOutlineColor(purple);
    botao_opcoes.setOrigin({200.f, 40.f});
    botao_opcoes.setPosition({windowSize.x / 2.0f, 400.f});

    label_opcoes.setString("Opcoes");
    label_opcoes.setCharacterSize(35);
    label_opcoes.setFillColor(purple);
    sf::FloatRect lb_o = label_opcoes.getLocalBounds();
    label_opcoes.setOrigin({lb_o.size.x / 2.0f, lb_o.size.y / 2.0f});
    label_opcoes.setPosition(botao_opcoes.getPosition());
}

//tratar eventos
void Menu::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
    // pega clique do mouse
    if (event.is<sf::Event::MouseButtonPressed>()) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

        if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
            // se clicou no botão, altera a tela que foi passada por referência
            if (botao_jogar.getGlobalBounds().contains(mousePosF)) { 
                tela_atual = Tela::Jogo; 
            } else if (botao_opcoes.getGlobalBounds().contains(mousePosF)) {
              tela_atual = Tela::Opcoes;
            }
        }
    }
}

//animacoes
void Menu::atualizar() {
    // lógica do pulsar
    float tempo = clock.getElapsedTime().asSeconds();
    float escala = 1.0f + std::sin(tempo * 5.0f) * 0.1f;
    titulo.setScale({escala, escala});
    
    // reposiciona o título sempre no meio-topo
    titulo.setPosition({1920 / 2.0f, 60.f}); 
}

void Menu::desenhar(sf::RenderWindow& window) {
    window.draw(titulo);
    window.draw(botao_jogar);
    window.draw(label_jogar);
    window.draw(botao_opcoes);
    window.draw(label_opcoes);
}
