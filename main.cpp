#include "AnimeRater.h"
// #include <iostream>
enum DSType { DSArray, DSLinkedList };

int main() {
  DSType Array = DSArray;
  DSType LinkedList = DSLinkedList;
  AnimeRater("user_list.csv", DSArray).runAnimeRater();

  return 0;
}