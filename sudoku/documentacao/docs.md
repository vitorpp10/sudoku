Para compilar programa:
`g++ teste.cpp -o programa -lsfml-graphics -lsfml-window -lsfml-system -std=c++17`

Para importar bibliotecas:
`#include<SMFL/Graphics.hpp>`
`#include<SMFL/Audio.hpp`

Criar primeira janela:
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
