#pragma once
#include<string>
#include<SFML/Audio.hpp>

enum class Dificuldade { Nenhum, Facil, Medio, Dificil };
enum class DificuldadeJogo { nenhum, facil, medio, dificil };
enum class Tela { Menu, Jogo, Opcoes, Estatisticas, Carregando, Modo, ComoJogar };
extern int musicaAtual, musicaAtualJogo;
extern bool gerar_fixos;
extern sf::Music musicaGlobal, musicaJogo, toqueGlobal;
extern std::string caminhoToque;
extern Dificuldade dificuldade_selecionada;
extern DificuldadeJogo dificuldade_jogo;
void ativarClique();