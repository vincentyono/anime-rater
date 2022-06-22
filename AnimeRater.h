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
  std::string file;
  Datastructure<User, std::string> *list;
  int userCount; // number of user
  int LIST_SIZE; // size of list
  User *currentUser;
  void login(std::string username); // login as a user
  bool isLoggedIn() const;          // check if user is logged in
  void addUser();                   // create a new user
  void removeUser();                // remove user
  void save();                      // save list to csv file
  void printUserMenu();             // print user's menu to console
  void welcomeScreen();
  void userMenu();

  // text manipulation
  void textToUser(std::string text);
  std::string userToText();

public:
  AnimeRater(std::string file, int DSType);
  void runAnimeRater();
};

#include "AnimeRater.cpp"

#endif