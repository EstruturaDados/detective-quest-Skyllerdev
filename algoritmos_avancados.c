#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

#define MAX 50

typedef struct salas {
    char nome[MAX];
    struct salas* esquerda;
    struct salas* direita;
} salas;

salas* criarSala(const char* nome) {
    salas* nova = malloc(sizeof(salas));
    if (!nova) {
        printf("Erro ao alocar sala!\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

salas* conectarSalas() {
    salas* entrada = criarSala("Entrada");
    salas* quarto = criarSala("Quarto");
    salas* banheiro = criarSala("Banheiro");
    salas* sala = criarSala("Sala");
    salas* jardim = criarSala("Jardim");
    salas* cozinha = criarSala("Cozinha");
    salas* escritorio = criarSala("Escritorio");

    entrada->esquerda = sala;
    entrada->direita = escritorio;

    sala->esquerda = quarto;
    sala->direita = cozinha;

    escritorio->esquerda = banheiro;
    escritorio->direita = jardim;

    //Raiz da arvore
    return entrada;
}

void explorarSalas(salas* atual) {
    char opcao;
    while (1) {

        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Acabou as salas.\n");
            printf("Última sala: %s\n", atual->nome);
            return;
        }

        printf("Você está no cômodo: %s\n", atual->nome);
        printf("Você pode ir para a Esquerda (E), Direita (D) ou Sair (S)!\n");
        printf("Opção: ");
        scanf(" %c", &opcao);
        opcao = tolower(opcao);
        salas* proxima = NULL;
        switch(opcao){
            case 's': printf("Saindo do programa...\n"); return;
            case 'e': proxima = atual->esquerda; break;
            case 'd': proxima = atual->direita; break;
            default: printf("Opção inválida.\n"); continue;
        }
        if (proxima)
            atual = proxima;
        else
            printf("Caminho inexistente.\n");
    }
}

int main() {

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    salas* mapa = conectarSalas();
    explorarSalas(mapa);

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

    return 0;
}

