#include <iostream>
#include <stack>

using namespace std;

struct Tree {
  int data;
  Tree* right;
  Tree* left;
};

void printPostOrder(Tree * tree) {
  stack<Tree*> movement;
  stack<int> toPrint;
  Tree * actual = tree;
  movement.push(actual);
  while (!movement.empty()) {
    actual = movement.top();
    movement.pop();
    toPrint.push(actual->data);
    if (actual->left != NULL) {
      movement.push(actual->left);
    }
    if (actual->right != NULL) {
      movement.push(actual->right);
    }
  }
  while (!toPrint.empty()){
    cout << toPrint.top() << " ";
    toPrint.pop();
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
  cout << "POST ORDER" << endl;
  printPostOrder(tree);
  delete array;
}
