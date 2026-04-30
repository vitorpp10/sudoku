#pragma once
#include<SFML/Audio.hpp>

enum class Dificuldade { Nenhum, Facil, Medio, Dificil };
enum class Tela { Menu, Jogo, Opcoes, Estatisticas };
extern int musicaAtual, musicaAtualJogo;
extern sf::Music musicaGlobal, musicaJogo;
