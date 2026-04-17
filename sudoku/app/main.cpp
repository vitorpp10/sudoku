#include<iostream>
#include<cstdlib>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>

void Sudoku() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Sudoku");
  
  const sf::Font font("../assets/PressStart2P-Regular.ttf");
  sf::Text text(font, "Teste", 50);

  sf::Music music("../assets/beyonce_fernanda.ogg");
  if (!music.openFromFile("../assets/beyonce_fernanda.ogg")) {
    perror("erro na musica da fernanda");
    exit(EXIT_FAILURE);
  }
  music.play();

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) 
        window.close();
    }
    
    window.clear();
    window.draw(text);
    window.display();
  }  
}

int main() {
  Sudoku();

  return EXIT_SUCCESS;
}
