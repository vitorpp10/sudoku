#include<cmath>
#include<ctime>
#include"carregando.hpp"
#include<SFML/Window/Mouse.hpp>
#define tamanho_barra_progresso 9

Carregando::Carregando(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
        label_carregando(font),
        label_cancelar(font)
{
    
    //carregar
    label_carregando.setString("Gerando tabuleiro...");
    label_carregando.setCharacterSize(53);
    label_carregando.setFillColor(purple);
    sf::FloatRect lb_c = label_carregando.getLocalBounds();
    label_carregando.setOrigin({lb_c.position.x + lb_c.size.x / 2.f, lb_c.position.y + lb_c.size.y / 2.f});
    label_carregando.setPosition({1920.f / 2.0f, 450.f});

    //botao cancelar
    botao_cancelar.setSize({300.f, 65.f});
    botao_cancelar.setFillColor(sf::Color::White);
    botao_cancelar.setOutlineThickness(2);
    botao_cancelar.setOutlineColor(purple);
    botao_cancelar.setOrigin({150.f, 32.5f});
    botao_cancelar.setPosition({windowSize.x / 2.0f, 850.f});

    label_cancelar.setString("Cancelar");
    label_cancelar.setCharacterSize(35);
    label_cancelar.setFillColor(purple);
    sf::FloatRect lb_cc = label_cancelar.getLocalBounds();
    label_cancelar.setOrigin({lb_cc.position.x + lb_cc.size.x / 2.f, lb_cc.position.y + lb_cc.size.y / 2.f});
    label_cancelar.setPosition(botao_cancelar.getPosition());
    
    //barra progresso
    float largura = 100.f;
    float altura = 50.f;
    float startX = (1920.f / 2.0f) - 400.f;
    float posY = 540.f;

    barra_progresso.resize(tamanho_barra_progresso); // prepara vector para 9 blocos

    for (int i = 0; i < tamanho_barra_progresso; i++) {
        barra_progresso[i].setSize({largura, altura});
        barra_progresso[i].setOrigin({largura / 2.0f, altura / 2.0f});
        barra_progresso[i].setPosition({startX + (i * largura), posY});
        barra_progresso[i].setFillColor(sf::Color::White);
        barra_progresso[i].setOutlineColor(purple);
    }
}

void Carregando::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
    if (event.is<sf::Event::MouseButtonPressed>()) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

        if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
            if (botao_cancelar.getGlobalBounds().contains(mousePosF)) {
                ativarClique();
                tela_atual = Tela::Menu;
            }           
        }   
    }      
}

void Carregando::atualizarHoverCarregando(const sf::RenderWindow& window, Tela& tela_atual) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (tela_atual == Tela::Carregando) {
        if (botao_cancelar.getGlobalBounds().contains(mousePos)) {
            botao_cancelar.setFillColor(purple);
            label_cancelar.setFillColor(sf::Color::White);
        } else {
            botao_cancelar.setFillColor(sf::Color::White);
            label_cancelar.setFillColor(purple);
        }
    }
}

//animacoes
void Carregando::atualizar(Tela& tela_atual) {
    if (bloco_atual < 9) {
        if (clock_progresso.getElapsedTime().asSeconds() >= tempo_proximo_bloco) {
        barra_progresso[bloco_atual].setFillColor(purple);
        bloco_atual++;
        
        clock_progresso.restart();
        tempo_proximo_bloco = (std::rand() % 8 + 1) / 10.0f;
        }
    } else {
        bloco_atual = 0;

        for (int i = 0; i < 9; i++) {
            barra_progresso[i].setFillColor(sf::Color::White);
        }

        tela_atual = Tela::Jogo;
        musicaGlobal.stop();
        musicaJogo.play();
    }
}

//mostrar na tela 
void Carregando::desenhar(sf::RenderWindow& window) {
    window.draw(label_carregando);
    window.draw(botao_cancelar);
    window.draw(label_cancelar);

    for (int i = 0; i < 9; i++) {
        window.draw(barra_progresso[i]);
    }
    window.display();
}