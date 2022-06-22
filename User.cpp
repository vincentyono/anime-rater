#include "User.h"

User::User() {
  this->username = "";
  this->animeList = new Array<Anime, std::string>();
}

User::User(std::string username) {
  this->username = username;
  this->animeList = new Array<Anime, std::string>();
}

void User::printAnimeList() const { this->animeList->printList(); }

void User::appendAnime(Anime anime) { this->animeList->append(anime); }

Anime User::searchAnime(std::string animeTitle) const {
  return *this->animeList->search(animeTitle);
}

std::string User::getUsername() const { return this->username; }

bool User::operator==(std::string username) {
  return this->username == username;
}

void User::setUsername(std::string username) { this->username = username; }

User &User::operator=(const User &other) {
  this->username = other.username;
  this->animeList = other.animeList;
  return *this;
}

void User::removeAnime(std::string animeTitle) {
  this->animeList->remove(animeTitle);
}

std::ostream &operator<<(std::ostream &os, const User &user) {
  os << user.getUsername();
  return os;
}

bool User::operator>(const User &other) {
  for (int i = 0;
       i < std::min(this->getUsername().length(),
                    other.getUsername()
                        .length()); // min length between lhs username and rhs
       i++) {
    if (this->getUsername()[i] > other.getUsername()[i]) {
      return true;
    } else if (this->getUsername()[i] < other.getUsername()[i]) {
      return false;
    }
  }
  return false;
}

bool User::operator<(const User &other) {
  for (int i = 0;
       i < std::min(this->getUsername().length(),
                    other.getUsername()
                        .length()); // min length between lhs username and rhs
       i++) {
    if (this->getUsername()[i] < other.getUsername()[i]) {
      return true;
    } else if (this->getUsername()[i] > other.getUsername()[i]) {
      return false;
    }
  }
  return false;
}

bool User::operator<=(const User &other) {
  if (this->getUsername() == other.getUsername()) {
    return true;
  }

  for (int i = 0;
       i < std::min(this->getUsername().length(), other.getUsername().length());
       i++) {
    if (this->getUsername()[i] < other.getUsername()[i]) {
      return true;
    } else if (this->getUsername()[i] > other.getUsername()[i]) {
      return false;
    }
  }

  return false;
}

bool User::operator>=(const User &other) {
  if (this->getUsername() == other.getUsername()) {
    return true;
  }

  for (int i = 0;
       i < std::min(this->getUsername().length(), other.getUsername().length());
       i++) {
    if (this->getUsername()[i] > other.getUsername()[i]) {
      return true;
    } else if (this->getUsername()[i] < other.getUsername()[i]) {
      return false;
    }
  }

  return false;
}

std::string User::toString() {
  std::string str;
  str += this->getUsername() + ",";
  str += this->animeList->toString(Anime::toString) + "\n";
  return str;
}