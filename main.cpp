#include "labirinto.h"
#include <fstream>

int main(){
    int n;
    std::cout << "Digite o tamanho do labirinto: ";
    std::cin >> n; 

    //Declara o labirinto com N lados e N colunas
    Labirinto lab(n);
    //Instancia o ponto de destino e cria a posição de início.
    Ponto destino;
    int atualX = 1, atualY = 0;

    //Chama as funções para lerMatriz e imprimí-la
    lab.leMatriz();
    lab.imprimeLabirinto();
    //Armazena um ponto na variável Destino
    destino = lab.encontraPontoDestino();
    std::cout << "A saída se encontra respectivamente na linha e coluna: " << destino.x << " " << destino.y << "." <<  std::endl;

    if(lab.verificaSaidaLabirinto(atualX, atualY, destino))
        std::cout << "-> Existe uma saída!\n";
    else
        std::cout << "-> Não existe uma saída! :(\n";

    return 0;
}