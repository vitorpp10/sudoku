#include<cmath>
#include"como_jogar.hpp"
#include<SFML/Window/Mouse.hpp>

ComoJogar::ComoJogar(const sf::Vector2u& windowSize) 
    : font("../assets/PressStart2P-Regular.ttf"), 
    titulo(font), 
    label_tutorial(font),
    label_voltar(font)
{
    titulo.setString("Sudoku da Fernanda");
    titulo.setCharacterSize(55);
    titulo.setFillColor(purple);
    sf::FloatRect bounds = titulo.getLocalBounds();
    titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

    //botao caixa
    caixa_tutorial.setSize({1200.f, 700.f});
    caixa_tutorial.setFillColor(sf::Color::White);
    caixa_tutorial.setOutlineThickness(3);
    caixa_tutorial.setOutlineColor(purple);
    caixa_tutorial.setOrigin({600.f, 350.f});
    caixa_tutorial.setPosition({windowSize.x / 2.0f, 520.f});

    label_tutorial.setString(
        "Seu objetivo e preencher a grade 9x9\n"
        "para que cada coluna, cada linha\n" 
        "e cada um dos nove blocos 3x3 contenham\n"
        "todos os digitos de 1 a 9.\n\n\n"
        "1. Use o painel numerico para inserir\n" 
        "valores.\n\n"
        "2. Nao e permitido repetir numeros em uma\n" 
        "mesma linha ou coluna.\n\n"
        "3. Nao e permitido repetir numeros no\n" 
        "mesmo bloco 3x3.\n\n"
        "4. O jogo termina ao preencher todos os\n" 
        "espacos corretamente!"
    );
    label_tutorial.setCharacterSize(27);
    label_tutorial.setFillColor(purple); 
    label_tutorial.setLineSpacing(1.2f);
    sf::FloatRect lb_t = label_tutorial.getLocalBounds();
    label_tutorial.setOrigin({0, 0});
    sf::Vector2f canto_da_tela = { caixa_tutorial.getPosition().x - 550.f, caixa_tutorial.getPosition().y - 300.f };
    label_tutorial.setPosition(canto_da_tela);

    botao_voltar.setSize({400.f, 80.f});
    botao_voltar.setFillColor(sf::Color::White);
    botao_voltar.setOutlineThickness(2);
    botao_voltar.setOutlineColor(purple);
    botao_voltar.setOrigin({200.f, 40.f});
    botao_voltar.setPosition({windowSize.x / 2.0f, 960.f}); 

    label_voltar.setString("Voltar");
    label_voltar.setCharacterSize(40);
    label_voltar.setFillColor(purple);
    sf::FloatRect lb_v = label_voltar.getLocalBounds();
    label_voltar.setOrigin({lb_v.size.x / 2.0f, lb_v.size.y / 2.0f});
    label_voltar.setPosition(botao_voltar.getPosition());
}

void ComoJogar::tratarEventos(const sf::Event& event, const sf::RenderWindow& window, Tela& tela_atual) {
    if (event.is<sf::Event::MouseButtonPressed>()) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

        if (event.getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
            if (botao_voltar.getGlobalBounds().contains(mousePosF)) {
                ativarClique();
                tela_atual = Tela::Modo;
            }
        }
    }
}

void ComoJogar::atualizarHoverComoJogar(const sf::RenderWindow& window, Tela& tela_atual) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (tela_atual == Tela::ComoJogar) {
        if (botao_voltar.getGlobalBounds().contains(mousePos)) {
            botao_voltar.setFillColor(purple);
            label_voltar.setFillColor(sf::Color::White);
        } else {
            botao_voltar.setFillColor(sf::Color::White);
            label_voltar.setFillColor(purple);
        }
    }
}

void ComoJogar::atualizar() {
    float tempo = clock.getElapsedTime().asSeconds();
    float escala = 1.0f + std::sin(tempo * 5.0f) * 0.1f;
    titulo.setScale({escala, escala});
    titulo.setPosition({1920 / 2.0f, 60.f});
}

void ComoJogar::desenhar(sf::RenderWindow& window) {
    window.draw(titulo);
    window.draw(caixa_tutorial);
    window.draw(label_tutorial);
    window.draw(botao_voltar);
    window.draw(label_voltar);
    window.display();
}