#pragma once
#include<SFML/Audio.hpp>

enum class Dificuldade { Nenhum, Facil, Medio, Dificil };
enum class Tela { Menu, Jogo, Opcoes, Estatisticas, Carregando, Modo};
extern int musicaAtual, musicaAtualJogo;
extern sf::Music musicaGlobal, musicaJogo;
