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
  User(Datastructure<Anime> *datastructure, std::string username);
  void printAnimeList() const;               // print animeList to console
  bool appendAnime(Anime anime);             // add new Anime to animeList
  Anime searchAnime(std::string animeTitle); // search for anime in animeList
};

#include "Anime.cpp"
#include "User.cpp"

#endif