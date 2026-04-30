#include<cmath>
#include"estatisticas.hpp"
#include<SFML/Window/Mouse.hpp>

Estatisticas::Estatisticas(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
        titulo(font),
        label_caixa(font),
        label_derrota(font),
        label_perfil(font),
        label_streak(font),
        label_vitoria(font),
        label_voltar(font)
{
    titulo.setString("Sudoku da Fernanda");
    titulo.setCharacterSize(55);
    titulo.setFillColor(purple);
    sf::FloatRect bounds = titulo.getLocalBounds();
    titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

    //botao caixa
    botao_caixa.setSize({550.f, 500.f});
    botao_caixa.setFillColor(sf::Color::White); 
    botao_caixa.setOutlineThickness(3);
    botao_caixa.setOutlineColor(purple);
    botao_caixa.setOrigin({275.f, 250.f}); 
    botao_caixa.setPosition({windowSize.x / 2.0f, 470.f});

    /* label_caixa.setString("Estatisticas Gerais");
    label_caixa.setCharacterSize(36);   
    label_caixa.setFillColor(purple);
    sf::FloatRect lb_c = label_caixa.getLocalBounds();
    label_caixa.setOrigin({lb_c.position.x + lb_c.size.x / 2.f, lb_c.position.y + lb_c.size.y / 2.f});
    label_caixa.setPosition({windowSize.x / 2.0f, 230.f}); */

    //botao perfil
    botao_perfil.setSize({450.f, 80.f});
    botao_perfil.setFillColor(sf::Color::White);
    botao_perfil.setOutlineThickness(2);
    botao_perfil.setOutlineColor(purple);
    botao_perfil.setOrigin({225.f, 40.f});
    botao_perfil.setPosition({windowSize.x / 2.0f, 310.f});

    label_perfil.setString("Perfil");
    label_perfil.setCharacterSize(35);
    label_perfil.setFillColor(purple);
    sf::FloatRect lb_p = label_perfil.getLocalBounds();
    label_perfil.setOrigin({lb_p.position.x + lb_p.size.x / 2.f, lb_p.position.y + lb_p.size.y / 2.f});
    label_perfil.setPosition(botao_perfil.getPosition());

    //botao vitoria
    botao_vitoria.setSize({450.f, 80.f});
    botao_vitoria.setFillColor(sf::Color::White);
    botao_vitoria.setOutlineThickness(2);
    botao_vitoria.setOutlineColor(purple);
    botao_vitoria.setOrigin({225.f, 40.f});
    botao_vitoria.setPosition({windowSize.x / 2.0f, 450.f});

    label_vitoria.setString("Vitorias: 0");
    label_vitoria.setCharacterSize(35);
    label_vitoria.setFillColor(purple);
    sf::FloatRect lb_v = label_vitoria.getLocalBounds();
    label_vitoria.setOrigin({lb_v.position.x + lb_v.size.x / 2.f, lb_v.position.y + lb_v.size.y / 2.f});
    label_vitoria.setPosition(botao_vitoria.getPosition());

    //botao derrota
    botao_derrota.setSize({450.f, 80.f});
    botao_derrota.setFillColor(sf::Color::White);
    botao_derrota.setOutlineThickness(2);
    botao_derrota.setOutlineColor(purple);
    botao_derrota.setOrigin({225.f, 40.f});
    botao_derrota.setPosition({windowSize.x / 2.0f, 550.f});

    label_derrota.setString("Derrotas: 0");
    label_derrota.setCharacterSize(35);
    label_derrota.setFillColor(purple);
    sf::FloatRect lb_d = label_derrota.getLocalBounds();
    label_derrota.setOrigin({lb_d.position.x + lb_d.size.x / 2.f, lb_d.position.y + lb_d.size.y / 2.f});
    label_derrota.setPosition(botao_derrota.getPosition());

    //botao streak
    botao_streak.setSize({450.f, 80.f});
    botao_streak.setFillColor(sf::Color::White);
    botao_streak.setOutlineThickness(2);
    botao_streak.setOutlineColor(purple);
    botao_streak.setOrigin({225.f, 40.f});
    botao_streak.setPosition({windowSize.x / 2.0f, 650.f});

    label_streak.setString("Streak: 0");
    label_streak.setCharacterSize(35);
    label_streak.setFillColor(purple);
    sf::FloatRect lb_s = label_streak.getLocalBounds();
    label_streak.setOrigin({lb_s.position.x + lb_s.size.x / 2.f, lb_s.position.y + lb_s.size.y / 2.f});
    label_streak.setPosition(botao_streak.getPosition());

    //botao_voltar
    botao_voltar.setSize({300.f, 65.f});
    botao_voltar.setFillColor(sf::Color::White);
    botao_voltar.setOutlineThickness(2);
    botao_voltar.setOutlineColor(purple);
    botao_voltar.setOrigin({150.f, 32.5f});
    botao_voltar.setPosition({windowSize.x / 2.0f, 850.f});

    label_voltar.setString("Voltar");
    label_voltar.setCharacterSize(35);
    label_voltar.setFillColor(purple);
    sf::FloatRect lb_vv = label_voltar.getLocalBounds();
    label_voltar.setOrigin({lb_vv.position.x + lb_vv.size.x / 2.f, lb_vv.position.y + lb_vv.size.y / 2.f});
    label_voltar.setPosition(botao_voltar.getPosition());
}

void Estatisticas::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
    if (event.is<sf::Event::MouseButtonPressed>()) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

        if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
            if (botao_voltar.getGlobalBounds().contains(mousePosF)) {
                tela_atual = Tela::Opcoes;
            }           
        }   
    }      
}

void Estatisticas::atualizarHoverEstatisticas(const sf::RenderWindow& window, Tela& tela_atual) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (tela_atual == Tela::Estatisticas) {
        if (botao_voltar.getGlobalBounds().contains(mousePos)) {
            botao_voltar.setFillColor(purple);
            label_voltar.setFillColor(sf::Color::White);
        } else {
            botao_voltar.setFillColor(sf::Color::White);
            label_voltar.setFillColor(purple);
        }
    }
}

//animacoes
void Estatisticas::atualizar() {
    float tempo = clock.getElapsedTime().asSeconds();
    float escala = 1.0f + std::sin(tempo * 5.0f) * 0.1f;
    titulo.setScale({escala, escala});
    titulo.setPosition({1920 / 2.0f, 60.f});
}

//mostrar na tela 
void Estatisticas::desenhar(sf::RenderWindow& window) {
    window.draw(titulo);
    
    window.draw(botao_caixa);
    window.draw(label_caixa);

    window.draw(botao_perfil);
    window.draw(botao_vitoria);
    window.draw(botao_derrota);
    window.draw(botao_streak);
    window.draw(botao_voltar);

    window.draw(label_perfil);
    window.draw(label_vitoria);
    window.draw(label_derrota);
    window.draw(label_streak);
    window.draw(label_voltar);

    window.display();
}
