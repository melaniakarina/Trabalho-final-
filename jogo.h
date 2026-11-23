#include "raylib.h"

#define MAX_LINHAS 30
#define MAX_COLUNAS 30

typedef enum {
    ESTADO_JOGANDO,
    ESTADO_FIM
} EstadoTela;

typedef enum {
    NENHUM,
    VITORIA,
    PERDA,
    DESISTENCIA
} ResultadoPartida;

typedef struct {
    int linhas;
    int colunas;
    char matriz[MAX_LINHAS][MAX_COLUNAS + 1];
} DadosMapa;

typedef struct {
    DadosMapa mapa;
    int lin;
    int col;
    int energia;
    int cristais;
    int turnos;
    float tempoDecorrido;
    EstadoTela tela;
    ResultadoPartida resultado;
    int sair;
    char mensagem[128];
} Jogo;


// funções do mapa

int InicializarJogo(Jogo *jogo, char *arquivo);

int CarregarMapa(Jogo *jogo, char *arquivo);

int ValidarMapa(Jogo *jogo);

char ObterCelula(Jogo *jogo, int lin, int col);

void AlterarCelula(Jogo *jogo, int lin, int col, char simbolo);

void DesenharMapa(Jogo *jogo);


// funções do jogador, falta algumas

void AtualizarJogo(Jogo *jogo);

void Movimentar(Jogo *jogo, int dLin, int dCol);


// falta adicionar outras funções de eventos

void ProcessarCelula(Jogo *jogo);

void DesenharTelaFinal(Jogo *jogo);
