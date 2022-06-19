#include "User.h"
#include "Anime.h"

User::User(Datastructure<Anime> *datastructure, std::string username) {
  this->username = username;
  this->animeList = datastructure;
}

void User::printAnimeList() const { this->animeList->printList(); }

bool User::appendAnime(Anime anime) { return this->animeList->append(anime); }

Anime User::searchAnime(std::string animeTitle) {
  return this->animeList->search(animeTitle);
}