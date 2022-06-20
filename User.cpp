#include "User.h"
#include "Anime.h"
#include "Array.h"
#include "Datastructure.h"

User::User() {
  this->username = "Username";
  this->animeList = new Array<Anime>();
}

User::User(std::string username) {
  this->username = username;
  this->animeList = new Array<Anime>();
}

void User::printAnimeList() const { this->animeList->printList(); }

void User::appendAnime(Anime anime) { this->animeList->append(anime); }

Anime *User::searchAnime(std::string animeTitle) const {
  return this->animeList->search(*(new Anime(animeTitle, 0)));
}

std::string User::getUsername() const { return this->username; }

bool User::operator==(const User &other) {
  return this->username == other.username;
}

void User::setUsername(std::string username) { this->username = username; }

User &User::operator=(const User &other) {
  this->username = other.username;
  this->animeList = other.animeList;
  return *this;
}

void User::removeAnime(std::string animeTitle) {
  this->animeList->remove(*(new Anime(animeTitle, 0)));
}