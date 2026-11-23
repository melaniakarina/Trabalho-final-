#include "jogo.h"
#include <string.h>

void Movimentar(Jogo *jogo, int dLin, int dCol) {

    int novaLin = (*jogo).lin + dLin;
    int novaCol = (*jogo).col + dCol;

    // verificação dos limites do mapa
    if (novaLin < 0 || novaLin >= (*jogo).mapa.linhas || novaCol < 0 || novaCol >= (*jogo).mapa.colunas) {
        strcpy((*jogo).mensagem, "Movimento bloqueado: limite do mapa!");
        return;
    }

    // verificação obstáculos
    if (ObterCelula(jogo, novaLin, novaCol) == '#') {
        strcpy((*jogo).mensagem, "Movimento bloqueado: há um obstaculo!");
        return;
    }

    // movimento válido
    (*jogo).lin = novaLin;
    (*jogo).col = novaCol;

    strcpy((*jogo).mensagem, "Movimento realizado.");

    ProcessarCelula(jogo);
}


void AtualizarJogo(Jogo *jogo) {

    if ((*jogo).tela == ESTADO_JOGANDO) {

        (*jogo).tempoDecorrido += GetFrameTime();

        // movimentação com teclado usando funções da raylib
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            Movimentar(jogo, -1, 0);

        } else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            Movimentar(jogo, 1, 0);

        } else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
            Movimentar(jogo, 0, -1);

        } else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
            Movimentar(jogo, 0, 1);
        }
    }

    // tela final opção para reiniciar o jogo, tem que mudar o mapa!!!
    else if ((*jogo).tela == ESTADO_FIM) {
        if (IsKeyPressed(KEY_R)) {
            if (!InicializarJogo(jogo, "mapa.txt")) {
                (*jogo).sair = 1;
            }
    }
}