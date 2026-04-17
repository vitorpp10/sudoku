Arquitetura das pastas:
```
sudoku
    app/
    assets/
    documentacao/
``` 

Para compilar programa: 
`g++ main.cpp -o sudoku -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -std=c++17`

Para importar bibliotecas:
`#include<SMFL/Graphics.hpp>`
`#include<SMFL/Audio.hpp`

Criar janela:
```
void Janela() {
    sf::Window window(sf::VideoMode({largura, altura}), "nome_janela");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) 
                window.close();
        }
    }
}
```

Escrever texto:
```
void Janela() {
    //window aqui...

    const sf::Font font("/caminho_da_fonte_aqui");
    sf::Text text(font);

    text.setString("texto_aqui");
    text.setFillColor(sf::Color::cor_aqui);
    text.setCharacterSize(tamanho_texto_aqui);
    text.setStyle(sf::Text::estilo_aqui | sf::Text::outro_estilo_aqui);

    while (windows.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) 
                window.close();
        }
        
        window.clear();
        window.draw(text);
        window.display();
    }
}
```

Tocar música:
```
void Janela() {
    //window aqui... 
    
    //fonte aqui... 
    
    sf::Music music("caminho_da_musica_aqui");
    if (!music.openFromFile("caminho_da_musica_aqui"))
        return 1

    music.play();

    //while e condições de loop aqui
}
```

Pegar altura e largura + mudar posição de textos:
```
void Janela() { 
    //window aqui

    sf::Font font("caminho_da_fonte_aqui");
    sf::Text text(font);

    //outras configurações texto aqui... 
    
    sf::FloatRect bounds = titulo.getLocalBounds();
    titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f}); 
}
```

Animação de pulsar: 
```
void Janela() {
    //window aqui  
    
    sf::Font font(...);
    sf::Text titulo(font);

    sf::Clock clock; 

    while (window.isOpen()) { 
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            float tempo = clock.getElapsedTime().asSeconds();

            float escala = 1.0f + std::sin(tempo * 5.0f) * 0.1f;
            titulo.setScale({escala, escala});

            titulo.setPosition({window.getSize().x / 2.0f, 60.f});
        
            window.clear(sf::Color::White);
            window.draw(titulo);
            window.display();
        } 
    }
}
```

Botão jogar + verificar se mouse clicou dentro da sua área demarcada:
```
void Janela() {
    //criação do retângulo + texto + área na janela 
    
    //enum básico para simular troca de telas 
    enum class Tela { Menu, Jogo }; 
    Tela tela_atual = Tela::Menu;

    sf::RectangleShape botao_jogar({200.f, 60.f});
    botao_jogar.setFillColor(sf::Color::White);
    botao_jogar.setOutlineThickness(2);
    botao_jogar.setOutlineColor(purple);
    botao_jogar.setOrigin({100.f, 30.f});
    botao_jogar.setPosition({window.getSize().x / 2.0f, 300.f});

    sf::Text label_jogar(font);
    label_jogar.setString("Jogar");
    label_jogar.setCharacterSize(35);
    label_jogar.setFillColor(purple);

    sf::FloatRect lb = label_jogar.getLocalBounds();
    label_jogar.setOrigin({lb.size.x / 2.0f, lb.size.y / 2.0f});
    label_jogar.setPosition(botao_jogar.getPosition());

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    //dentro do while...

    if (event->is<sf::Event::MouseButtonPressed>()) {
        
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
     
        if (event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
            if (botao_jogar.getGlobalBounds().contains(mousePosF)) {
                tela_atual = Tela::Jogo; // TROCOU A TELA!
            }
        }
    }
} 
```

Variável para trocar de telas: 
```
void Janela() {
    enum class Tela { Menu, Jogo }
    Tela tela_atual = Tela::Menu;

    //outros códigos aqui 
    
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            window.clear(sf::Color::White);

            if (tela_atual == Tela::Menu) {
                window.draw(titulo);
                window.draw(botao_jogar);
                window.draw(label_jogar);
            } else if (tela_atual == Tela::Jogo) {
                ... //troca de telas ocorre aqui
            }
        }
    }
} 
```
