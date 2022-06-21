#include "AnimeRater.h"
#include <iostream>

enum DSType { DSArray, DSLinkedList };

int main() {
  DSType Array = DSArray;
  AnimeRater("user_list.csv", DSArray).runAnimeRater();
  return 0;
}