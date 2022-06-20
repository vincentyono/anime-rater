#ifndef USER_H
#define USER_H

#include "Anime.h"
#include "Datastructure.h"
#include <iostream>

class User {
private:
  std::string username;
  Datastructure<Anime> *animeList; // pointer to Anime Array

public:
  User();
  User(std::string username);
  std::string getUsername() const;
  void setUsername(std::string username);
  void printAnimeList() const; // print animeList to console
  void removeAnime(std::string animeTitle);
  void appendAnime(Anime anime); // add new Anime to animeList
  Anime *
  searchAnime(std::string animeTitle) const; // search for anime in animeList
  bool operator==(const User &other);
  User &operator=(const User &other);
};

#include "User.cpp"

#endif