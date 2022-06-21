#ifndef ANIMERATER_H
#define ANIMERATER_H

#include "Anime.h"
#include "User.h"
#include <fstream>
#include <iostream>

template <typename T1, typename T2> class Datastructure;

template <typename T1, typename T2> class LinkedList;

class AnimeRater {
private:
  std::string datastructureType;
  Datastructure<User, std::string> *list;
  User *currentUser;
  void login(std::string username); // login as a user
  bool isLoggedIn() const;          // check if user is logged in
  void addUser();                   // create a new user
  void removeUser();                // remove user
  void save();                      // save list to csv file
  void printMainMenu();             // print main menu to console
  void printUserMenu();             // print user's menu to console
  void runMainMenu();
  void runUserMenu();

  // text manipulation
  void textToUser(std::string text);

public:
  AnimeRater(std::string file, int DSType);
  void runAnimeRater();
};

#include "AnimeRater.cpp"

#endif