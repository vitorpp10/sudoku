#include<iostream>
#include<cstdlib>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>

void JanelaSudoku() {
  sf::Window window(sf::VideoMode({800, 600}), "Sudoku");
  
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) 
        window.close();
    }
  }  
}

int main() {
  JanelaSudoku();

  return EXIT_SUCCESS;
}
