/*
 *  Тестовый файл для функций работы с деревом.
 *  (Программирование, 2 поток)
 *
 *  Необходимые файлы:
 *     tree.h  tmain.cpp  myfun.cpp  tree.o  tree.dat
 *
 *  Заполняем дерево числами из файла tree.dat
 *  и распечатываем его на экран и в файл tree.res.
 *  Описание прилагаемых функций см. в файле tree.h
 *
 *  Функции, необходимые Вам для решения задачи, можно
 *  собрать в отдельном файле (скажем, myfun.cpp).
 *  Не забудьте прописать прототипы функций в tmain.cpp.
 *  В этом случае компиляцию и сборку программы можно
 *  произвести командой make (необходимый makefile прилагается),
 *  либо компилировать и собрать непосредственно из командной строки:
 *
 *    g++  tmain.cpp myfun.cpp tree.o
 *
 */
#include <iostream>

#include "tree.h"
void Balance(Tree& tree);

TreeNode* removeNodesWithBalance(TreeNode* node, int X);

int main(void) {
  FILE *fin, *fout;

  // открываем и проверяем файлы
  if (!(fout = fopen("tree.res", "w"))) {
    printf("\n Cannot open file tree.res\n");
    return -1;
  }
  if (!(fin = fopen("tree.dat", "r"))) {
    printf("\n Cannot open file tree.dat\n");
    return -1;
  }

  // заполняем дерево числами из файла
  Tree tr(fin);
  fclose(fin);

  // распечатаем исходное дерево
  printf("\nThe tree is :\n");
  T_Print(stdout, tr.root);
  T_Print(fout, tr.root);

  // сюда следует вставить вызовы Ваших функций
  Balance(tr);
  T_Print(stdout, tr.root);
  T_Print(fout, tr.root);
  std::cout << "введите X";
  int X;
  std::cin >> X;
  removeNodesWithBalance(tr.root, X);
  T_Print(stdout, tr.root);
  T_Print(fout, tr.root);
  // для решения поставленной задачи
  // закрываем файл результата
  fclose(fout);
  return 0;
}
