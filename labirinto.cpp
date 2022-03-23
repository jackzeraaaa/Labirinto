#include "labirinto.h"

Labirinto::Labirinto(int n){
    maze = new char*[n];
    for(int i=0; i<n; i++){
        maze[i] = new char[n];
    }
    this->n = n;
}

Labirinto::~Labirinto(){
    for(int i=0; i<n; i++){
        delete[] maze[i];
    }
    delete maze;
}

Ponto Labirinto::encontraPontoDestino(){
    //Verifica se algum dos pontos armazena o char '7', se sim, atribuiremos a variável destino sua posição em cada eixo
    for(int l = 0; l < n; l++){
        for(int c = 0; c < n; c++){
            if(maze[l][c] == '7'){
                destino.x = l;
                destino.y = c;
            }
        }
    }
    return destino;
}

bool Labirinto::isEmpty(int atualX, int atualY){
    //Checa se a posição atual está nos limites da matriz e retorna true caso verdade
    if(atualX>=0 && atualY>=0 && atualX<n && atualY<n){
        if(maze[atualX][atualY]=='0'){
            return true;
        }
    }
    //Caso contrário, retorna false
    return false;
}

void Labirinto::leMatriz(){
    std::cout << "Agora insira o labirinto em forma de matriz:\n";
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            std::cin >> maze[i][j];
        }
    }
}

void Labirinto::imprimeLabirinto(){
    std::cout << "------------------------------\n";
    std::cout << "Imprimindo labirinto...\n";
    std::cout << "------------------------------\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Labirinto::verificaSaidaLabirinto(int atualX, int atualY, Ponto Destino){
    //Se o ponto atual que estamos a percorrer for igual ao nosso destino, a função retornará true
    //pois assim teremos chegado a nossa saída.
    if(atualX==destino.x && atualY==destino.y){
        return true;
    }
    //Se o ponto que estamos for vazio já vamos evitar dor de cabeça e retornar falso rs
    if(!isEmpty(atualX, atualY)){
        return false;
    }

    //Agora marcamos na matriz o caminho que nós já percorremos
    maze[atualX][atualY] = '1';
    //Nossa chamada recursiva, caso verificaSaidaLabirinto() retornar true em alguma das possiveis possições para qual podemos nos movimentar, retornaremos true também
    if(verificaSaidaLabirinto(atualX + 1, atualY, destino) || verificaSaidaLabirinto(atualX - 1, atualY, destino) || 
    verificaSaidaLabirinto(atualX, atualY + 1, destino) || verificaSaidaLabirinto(atualX, atualY - 1, destino)){
        return true;
    }
    //Caso contrário, apagaremos nosso caminho já feito e retornaremos falso
    else{
        maze[atualX][atualY] = '0';
        return false;
    }

    return false;
}