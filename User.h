#ifndef USER_H
#define USER_H

#include "Array.h"
#include "Datastructure.h"
#include "LinkedList.h"
#include "User.h"
#include <iostream>

class User {
private:
  std::string username;
  Datastructure<Anime, std::string> *animeList; // pointer to Anime Array

public:
  User();
  User(std::string username);
  std::string getUsername() const;
  void setUsername(std::string username);
  void printAnimeList() const; // print animeList to console
  void removeAnime(std::string animeTitle);
  void appendAnime(Anime anime); // add new Anime to animeList
  Anime
  searchAnime(std::string animeTitle) const; // search for anime in animeList
  bool operator==(std::string username);
  User &operator=(const User &other);
  friend std::ostream &operator<<(std::ostream &os, const User &user);
  bool operator<(const User &other);
  bool operator>(const User &other);
};

#include "User.cpp"

#endif