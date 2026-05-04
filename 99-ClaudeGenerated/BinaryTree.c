#include <stdio.h>
#include <stdlib.h>

/*
 * Estrutura de nó da árvore binária de busca.
 * Cada nó guarda um valor inteiro e ponteiros para os filhos esquerdo e direito.
 */
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

/* Cria um novo nó com o valor informado. */
Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        perror("Erro ao alocar nó");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*
 * Insere um valor na árvore binária de busca.
 * Se o valor for menor, vai para a subárvore esquerda;
 * se for maior, vai para a subárvore direita.
 */
Node *insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    } else {
        /* Valor igual: não inserimos duplicatas nesta versão simples. */
    }
    return root;
}

/*
 * Impressão em ordem (left, root, right).
 * Para uma árvore binária de busca, este método exibe os valores ordenados.
 */
void inorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}

void reverseorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    reverseorderTraversal(root->right);
    printf("%d ", root->value);
    reverseorderTraversal(root->left);
}

/* Libera a memória de todos os nós da árvore. */
void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    Node *root = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 1, 25, 35, 45, 55, 65, 75, 85, 2};
    int quantidade = sizeof(valores) / sizeof(valores[0]);

    printf("Inserindo valores na árvore binária de busca:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", valores[i]);
        root = insert(root, valores[i]);
    }
    printf("\n\n");

    printf("Valores em ordem (in-order traversal):\n");
    inorderTraversal(root);
    printf("\n");

    printf("Valores em ordem reversa (reverse-order traversal):\n");
    reverseorderTraversal(root);
    printf("\n");

    freeTree(root);
    return 0;
}

