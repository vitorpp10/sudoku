#include<cmath>
#include"modo.hpp"
#include<SFML/Window/Mouse.hpp>

Modo::Modo(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
    titulo(font), 
    label_facil(font),
    label_medio(font),
    label_dificil(font),
    label_voltar(font),
    label_como_jogar(font)
{
    titulo.setString("Sudoku da Fernanda");
    titulo.setCharacterSize(55);
    titulo.setFillColor(purple);
    sf::FloatRect bounds = titulo.getLocalBounds();
    titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

    //botao facil
    botao_facil.setSize({400.f, 80.f});
    botao_facil.setFillColor(sf::Color::White);
    botao_facil.setOutlineThickness(2);
    botao_facil.setOutlineColor(purple);
    botao_facil.setOrigin({200.f, 40.f});
    botao_facil.setPosition({windowSize.x / 2.0f, 300.f});

    label_facil.setString("Facil");
    label_facil.setCharacterSize(40);
    label_facil.setFillColor(purple);
    sf::FloatRect lb_f = label_facil.getLocalBounds();
    label_facil.setOrigin({lb_f.size.x / 2.0f, lb_f.size.y / 2.0f});
    label_facil.setPosition(botao_facil.getPosition());

    //botao medio
    botao_medio.setSize({400.f, 80.f});
    botao_medio.setFillColor(sf::Color::White);
    botao_medio.setOutlineThickness(2);
    botao_medio.setOutlineColor(purple);
    botao_medio.setOrigin({200.f, 40.f});
    botao_medio.setPosition({windowSize.x / 2.0f, 400.f});

    label_medio.setString("Medio");
    label_medio.setCharacterSize(40);
    label_medio.setFillColor(purple);
    sf::FloatRect lb_m = label_medio.getLocalBounds();
    label_medio.setOrigin({lb_m.size.x / 2.0f, lb_m.size.y / 2.0f});
    label_medio.setPosition(botao_medio.getPosition());

    //botao dificil
    botao_dificil.setSize({400.f, 80.f});
    botao_dificil.setFillColor(sf::Color::White);
    botao_dificil.setOutlineThickness(2);
    botao_dificil.setOutlineColor(purple);
    botao_dificil.setOrigin({200.f, 40.f});
    botao_dificil.setPosition({windowSize.x / 2.0f, 500.f});

    label_dificil.setString("Dificil");
    label_dificil.setCharacterSize(40);
    label_dificil.setFillColor(purple);
    sf::FloatRect lb_d = label_dificil.getLocalBounds();
    label_dificil.setOrigin({lb_d.size.x / 2.0f, lb_d.size.y / 2.0f});
    label_dificil.setPosition(botao_dificil.getPosition());

    //botao como jogar
    botao_como_jogar.setSize({400.f, 80.f});
    botao_como_jogar.setFillColor(sf::Color::White);
    botao_como_jogar.setOutlineThickness(2);
    botao_como_jogar.setOutlineColor(purple);
    botao_como_jogar.setOrigin({200.f, 40.f});
    botao_como_jogar.setPosition({windowSize.x / 2.0f, 600.f});

    label_como_jogar.setString("Tutorial");
    label_como_jogar.setCharacterSize(40);
    label_como_jogar.setFillColor(purple);
    sf::FloatRect lb_cm = label_como_jogar.getLocalBounds();
    label_como_jogar.setOrigin({lb_cm.size.x / 2.0f, lb_cm.size.y / 2.0f});
    label_como_jogar.setPosition(botao_como_jogar.getPosition());
    
    //botao voltar
    botao_voltar.setSize({300.f, 65.f});
    botao_voltar.setFillColor(sf::Color::White);
    botao_voltar.setOutlineThickness(2);
    botao_voltar.setOutlineColor(purple);
    botao_voltar.setOrigin({150.f, 32.5f});
    botao_voltar.setPosition({windowSize.x / 2.0f, 750.f});

    label_voltar.setString("Voltar");
    label_voltar.setCharacterSize(35);
    label_voltar.setFillColor(purple);
    sf::FloatRect lb_v = label_voltar.getLocalBounds();
    label_voltar.setOrigin({lb_v.size.x / 2.0f, lb_v.size.y / 2.0f});
    label_voltar.setPosition(botao_voltar.getPosition());
}

void Modo::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
    if (event.is<sf::Event::MouseButtonPressed>()) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

        if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
            if (botao_facil.getGlobalBounds().contains(mousePosF)) {
                ativarClique();
                dificuldade_selecionada = Dificuldade::Facil;
                dificuldade_jogo = DificuldadeJogo::facil;
                gerar_fixos = true;
                tela_atual = Tela::Carregando;
            } else if (botao_medio.getGlobalBounds().contains(mousePosF)) {
                ativarClique();
                dificuldade_selecionada = Dificuldade::Medio; 
                dificuldade_jogo = DificuldadeJogo::medio;
                gerar_fixos = true;
                tela_atual = Tela::Carregando;     
            } else if (botao_dificil.getGlobalBounds().contains(mousePosF)) {
                ativarClique();
                dificuldade_selecionada = Dificuldade::Dificil;
                dificuldade_jogo = DificuldadeJogo::dificil;
                gerar_fixos = true;
                tela_atual = Tela::Carregando;
            } else if (botao_voltar.getGlobalBounds().contains(mousePosF)) {
                ativarClique();
                tela_atual = Tela::Menu;
            } else if (botao_como_jogar.getGlobalBounds().contains(mousePosF)) {
                ativarClique();
                tela_atual = Tela::ComoJogar;
            }
        }
    }
}

void Modo::atualizarHoverModo(const sf::RenderWindow& window, Tela& tela_atual) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (tela_atual == Tela::Modo) {
        if (botao_facil.getGlobalBounds().contains(mousePos)) {
            botao_facil.setFillColor(purple);
            label_facil.setFillColor(sf::Color::White);
        } else {
            botao_facil.setFillColor(sf::Color::White);
            label_facil.setFillColor(purple);
        }
        
        if (botao_medio.getGlobalBounds().contains(mousePos)) {
            botao_medio.setFillColor(purple);
            label_medio.setFillColor(sf::Color::White);
        } else {
            botao_medio.setFillColor(sf::Color::White);
            label_medio.setFillColor(purple);
        }

        if (botao_dificil.getGlobalBounds().contains(mousePos)) {
            botao_dificil.setFillColor(purple);
            label_dificil.setFillColor(sf::Color::White);
        } else {
            botao_dificil.setFillColor(sf::Color::White);
            label_dificil.setFillColor(purple);
        }
    
        if (botao_voltar.getGlobalBounds().contains(mousePos)) {
            botao_voltar.setFillColor(purple);
            label_voltar.setFillColor(sf::Color::White);
        } else {
            botao_voltar.setFillColor(sf::Color::White);
            label_voltar.setFillColor(purple);
        }

        if (botao_como_jogar.getGlobalBounds().contains(mousePos)) {
            botao_como_jogar.setFillColor(purple);
            label_como_jogar.setFillColor(sf::Color::White);
        } else {
            botao_como_jogar.setFillColor(sf::Color::White);
            label_como_jogar.setFillColor(purple);
        }
    }
}

void Modo::atualizar() {
    float tempo = clock.getElapsedTime().asSeconds();
    float escala = 1.0f + std::sin(tempo * 5.0f) * 0.1f;
    titulo.setScale({escala, escala});
    titulo.setPosition({1920 / 2.0f, 60.f});
}

void Modo::desenhar(sf::RenderWindow& window) {
    window.draw(titulo);
    window.draw(botao_facil);
    window.draw(botao_medio);
    window.draw(botao_dificil);
    window.draw(botao_voltar);
    window.draw(botao_como_jogar);

    window.draw(label_como_jogar);
    window.draw(label_facil);
    window.draw(label_medio);
    window.draw(label_dificil);
    window.draw(label_voltar);

    window.display();
}