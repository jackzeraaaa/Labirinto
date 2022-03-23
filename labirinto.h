#ifndef LABIRINTO_H
#define LABIRINTO_H

#include <fstream>
#include <iostream>
#include <vector>
#include "ponto.h"

class Labirinto{
    public:
        int n;
        char** maze;
        Ponto destino;
        //Construtores e Destrutores
        Labirinto(int n);
        ~Labirinto();
        //Funções para ler e imprimir matriz
        void leMatriz();
        void imprimeLabirinto();
        //Função que retorna o ponto da saída do labirinto
        Ponto encontraPontoDestino();
        //Verifica se é possível sair do labirinto
        bool verificaSaidaLabirinto(int atualX, int atualY, Ponto Destino);
        //Verifica se a posição atual é válida
        bool isEmpty(int atualX, int atualY);
};

#endif