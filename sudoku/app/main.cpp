#include<cmath>
#include<iostream>
#include<cstdlib>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>

void MenuPrincipal() {
  //janela 
  sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Sudoku");
  
  //titulo janela 
  const sf::Font font("../assets/PressStart2P-Regular.ttf");
  sf::Text titulo(font);
  
  titulo.setString("Sudoku da Fernanda");
  titulo.setCharacterSize(45);
  
  sf::Color purple(128, 0, 128);
  titulo.setFillColor(purple);

  sf::FloatRect bounds = titulo.getLocalBounds();
  titulo.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f});

  //tempo 
  sf::Clock clock;

  //musica 
  sf::Music music("../assets/beyonce_fernanda.ogg");
  if (!music.openFromFile("../assets/beyonce_fernanda.ogg")) {
    perror("erro na musica da fernanda");
    exit(EXIT_FAILURE);
  }
  music.play();
  
  //enum para simular troca de telas
  enum class Tela { Menu, Jogo }; 
  Tela tela_atual = Tela::Menu;

  //botao jogar 
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

  //loop infinito na janela
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) { window.close(); }      
      
      //pega clique do mouse
      if (event->is<sf::Event::MouseButtonPressed>()) {

        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));


        if (event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
          if (botao_jogar.getGlobalBounds().contains(mousePosF)) { tela_atual = Tela::Jogo; }
        } 
      }
    } 

      if (tela_atual == Tela::Menu) {
        
        float tempo = clock.getElapsedTime().asSeconds();
        float escala = 1.0f + std::sin(tempo * 5.0f) * 0.1f;
        
        titulo.setScale({escala, escala});
        titulo.setPosition({window.getSize().x / 2.0f, 60.f});
        
        window.clear(sf::Color::White);
        window.draw(titulo);
        window.draw(botao_jogar);
        window.draw(label_jogar);

      } else if (tela_atual == Tela::Jogo) {
        window.clear(sf::Color::White);
      }
      
      window.display();
  }  
}

int main() {
  MenuPrincipal();

  return EXIT_SUCCESS;
}
