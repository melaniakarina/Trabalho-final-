#include "jogo.h"

int main() {
    InitWindow(1000, 1000, "Jogo");
    SetTargetFPS(60);

    SetExitKey(KEY_NULL);

    Jogo jogo;

    InicializarJogo(&jogo);

    while (!WindowShouldClose()) {
        AtualizarJogo(&jogo);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (jogo.tela == ESTADO_JOGANDO) {
            DesenharMapa();
        } else {
            DesenharTelaFinal(&jogo);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
