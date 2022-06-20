#ifndef ANIME_H
#define ANIME_H

#include <iostream>

class Anime {
private:
  std::string title;
  int rating;

public:
  Anime();
  Anime(std::string title, int rating);
  void setTitle(std::string animeTitle);
  void setRating(int rating);
  std::string getTitle() const;
  int getRating() const;
  bool operator==(const Anime &other);
  Anime &operator=(const Anime &other);
  // friend ostream &operator<<(ostream &os, const Anime &anime);
};

#include "Anime.cpp"

#endif