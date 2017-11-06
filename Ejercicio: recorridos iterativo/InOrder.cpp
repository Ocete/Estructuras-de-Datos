#include <iostream>
#include <stack>

using namespace std;

struct Tree {
  int data;
  Tree* right;
  Tree* left;
};

void printInOrder(Tree * tree) {
  stack<Tree*> movement;

  // Para la primera iteración del while
  Tree * actual = tree;
  movement.push(actual);
  Tree * anterior = new Tree;
  anterior->right = actual;

  while (!movement.empty()) {
    actual = movement.top();
    movement.pop();
    if (actual == anterior->right) {
      while (actual->left != NULL) {
        movement.push(actual);
        actual = actual->left;
      }
    }
    cout << actual->data << ' ';
    anterior = actual;
    if (actual->right != NULL) {
      movement.push(actual->right);
    }
  }
  cout << endl;
}

void createMinimalTree(int * array, int nums, Tree * &tree) {
  int mid = nums/2;
  tree->data = array[mid];
  if (nums == 1) {
    tree->left = NULL;
    tree->right = NULL;
  } else {
    tree->left = new Tree;
    createMinimalTree(array, mid, tree->left);
    if (nums == 2) {
      tree->right = NULL;
    } else {
      tree->right = new Tree;
      createMinimalTree(array+mid+1,
          nums%2 == 0 ? mid-1 : mid, tree->right);
    }
  }
}

void printTreeInOrder(Tree * tree) {
  if (tree != NULL) {
    printTreeInOrder(tree->left);
    cout << tree->data << endl;
    printTreeInOrder(tree->right);
  }
}

int main() {
  Tree* tree = new Tree;
  int * array = new int [15];
  for (int i=0; i<15; i++) array[i] = i;
  // Creamos un arbol completo de altura 3
  createMinimalTree(array, 15, tree);
  cout << "IN ORDER" << endl;
  printTreeInOrder(tree);
  cout << "ITERATIVE IN ORDER" << endl;
  printInOrder(tree);
  delete array;
}
