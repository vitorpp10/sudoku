#include"menu.hpp"
#include<cmath>
#include<iostream>
#include<cstdlib>

Menu::Menu(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
      titulo(font), 
      label_jogar(font) 
{
    // configura o título
    titulo.setString("Sudoku da Fernanda");
    titulo.setCharacterSize(45);
    sf::Color purple(128, 0, 128);
    titulo.setFillColor(purple);
    sf::FloatRect bounds = titulo.getLocalBounds();
    titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

    // configura a música
    if (!music.openFromFile("../assets/beyonce_fernanda.ogg")) {
        perror("erro na musica da fernanda");
        exit(EXIT_FAILURE);
    }
    music.play();

    // configura o botão jogar
    botao_jogar.setSize({200.f, 60.f});
    botao_jogar.setFillColor(sf::Color::White);
    botao_jogar.setOutlineThickness(2);
    botao_jogar.setOutlineColor(purple);
    botao_jogar.setOrigin({100.f, 30.f});
    botao_jogar.setPosition({windowSize.x / 2.0f, 300.f});

    // configura a label do botão
    label_jogar.setString("Jogar");
    label_jogar.setCharacterSize(35);
    label_jogar.setFillColor(purple);
    sf::FloatRect lb = label_jogar.getLocalBounds();
    label_jogar.setOrigin({lb.size.x / 2.0f, lb.size.y / 2.0f});
    label_jogar.setPosition(botao_jogar.getPosition());
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
}
