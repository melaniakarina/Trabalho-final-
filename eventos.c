#include "jogo.h"
#include <string.h>

void ProcessarCelula(Jogo *jogo) {
    char celula = ObterCelula((*jogo).lin, (*jogo).col);
    if (celula == 'S') {
        // falta verificar cristais(se obteu o minimo e indicar a vitoria)
        (*jogo).resultado = RES_VITORIA;
        (*jogo).tela = ESTADO_FIM;
            return;
        }
    }
}
