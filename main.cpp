#include "AnimeRater.h"
// #include "Array.h"
// #include "LinkedList.h"
// #include "User.h"
#include <fstream>
#include <iostream>

enum DSType { DSArray, DSLinkedList };

int main() {
  DSType Array = DSArray;
  DSType LinkedList = DSLinkedList;
  AnimeRater("user_list.csv", DSLinkedList).runAnimeRater();
  return 0;
}