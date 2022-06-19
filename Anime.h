#ifndef ANIME_H
#define ANIME_H

#include <iostream>

class Anime {
private:
  std::string title;
  int rating;

public:
  Anime(std::string title, int rating);
  std::string getTitle() const;
  int getRating() const;
};

#include "Anime.cpp"

#endif