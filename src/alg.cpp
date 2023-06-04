// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::string("Unable to open file!");
  }
  std::string word = "";
  BST<std::string> bst;
  while (!file.eof()) {
    word = "";
    while (1) {
      char symbol = file.get();
      if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122)) {
        word += tolower(symbol);
      } else {
        break;
      }
    }
    bst.AddValue(word);
  }
  return bst;
}
