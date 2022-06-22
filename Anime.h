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
  bool operator==(std::string animeTitle);
  Anime &operator=(const Anime &other);
  friend std::ostream &operator<<(std::ostream &os, const Anime &anime);
  bool operator<=(const Anime &other);
  bool operator<(const Anime &other);
  bool operator>(const Anime &other);
  bool operator>=(const Anime &other);
  static std::string toString(Anime anime);
};

#include "Anime.cpp"

#endif