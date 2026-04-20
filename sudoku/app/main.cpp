#include<SFML/Graphics.hpp>
#include<cstdlib>
#include"menu.hpp" // incluimos menu hpp aqui
#include"jogo.hpp" 

int main() {
    // cria a janela
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Sudoku");
    
    // estado inicial do jogo
    Tela tela_atual = Tela::Menu;

    // criamos o nosso menu
    Menu menuPrincipal(window.getSize());
    Jogo jogo(window.getSize());

    // loop infinito da janela
    while (window.isOpen()) {
        
        // tratamento de eventos
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close(); 
            }      
            
            // se estivermos no menu, passamos os eventos para ele tratar
            if (tela_atual == Tela::Menu) {
                menuPrincipal.tratarEventos(*event, window, tela_atual);
            } else if (tela_atual == Tela::Jogo) {
              jogo.tratarEventos(*event, window, tela_atual);
            }
        } 

        // limpa a tela
        window.clear(sf::Color::White);

        // atualização e Desenho dependendo da tela
        if (tela_atual == Tela::Menu) {
            menuPrincipal.atualizar();
            menuPrincipal.desenhar(window);
        } 
        else if (tela_atual == Tela::Jogo) {
          jogo.atualizar();
          jogo.desenhar(window);
        }
        
        window.display();
    }  
    return EXIT_SUCCESS;
}
