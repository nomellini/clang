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
 * Remove um valor da árvore binária de busca.
 * Retorna a nova raiz da árvore após a remoção.
 */
Node *removeNode(Node *root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        /* Nó encontrado - três casos possíveis */

        /* Caso 1: nó folha (sem filhos) */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        /* Caso 2: nó com apenas um filho */
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        /* Caso 3: nó com dois filhos */
        /* Encontra o sucessor (menor valor na subárvore direita) */
        Node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        /* Copia o valor do sucessor para este nó */
        root->value = temp->value;
        /* Remove o sucessor da subárvore direita */
        root->right = removeNode(root->right, temp->value);
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

Node *search(Node *root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}



int main(void) {
    Node *root = NULL;
    int valores[] = {70,85,70,90,66, 7,42,18,5,41, 47,27,26,23,63, 58,4,67,33,91};
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

    int valorBusca = 403;
    printf("\nBuscando valor %d na árvore...\n", valorBusca);
    Node *resultadoBusca = search(root, valorBusca);
    if (resultadoBusca != NULL) {
        printf("Valor %d encontrado na árvore.\n", resultadoBusca->value);
    } else {
        printf("Valor %d não encontrado na árvore.\n", valorBusca);
    }

    printf("\nRemovendo valor 30 da árvore...\n");
    root = removeNode(root, 30);
    printf("Valores em ordem após remoção:\n");
    inorderTraversal(root); 
    printf("\n");

    freeTree(root);
    return 0;
}

