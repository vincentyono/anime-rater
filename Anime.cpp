#include "Anime.h"

Anime::Anime() {
  this->title = "No title";
  int rating = 0;
}

Anime::Anime(std::string title, int rating) {
  this->title = title;
  this->rating = rating;
}

std::string Anime::getTitle() const { return this->title; }

int Anime::getRating() const { return this->rating; }

void Anime::setTitle(std::string title) { this->title = title; }

void Anime::setRating(int rating) { this->rating = rating; }

bool Anime::operator==(std::string animeTitle) {
  return this->title == animeTitle;
}

Anime &Anime::operator=(const Anime &other) {
  if (this != &other) {
    title = other.title;
    rating = other.rating;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Anime &anime) {
  os << "title: " << anime.getTitle() << ", rating: " << anime.getRating();
  return os;
}