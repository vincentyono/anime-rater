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

bool Anime::operator<(const Anime &other) {
  for (int i = 0; i < std::min(this->title.length(), other.title.length());
       i++) {
    if (this->title[i] < other.title[i]) {
      return true;
    } else if (this->title[i] > other.title[i]) {
      return false;
    }
  }
  return false;
}

bool Anime::operator<=(const Anime &other) {
  if (this->title == other.title) {
    return true;
  }

  for (int i = 0; i < std::min(this->title.length(), other.title.length());
       i++) {
    if (this->title[i] < other.title[i]) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

bool Anime::operator>(const Anime &other) {
  for (int i = 0; i < std::min(this->title.length(), other.title.length());
       i++) {
    if (this->title[i] > other.title[i]) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

bool Anime::operator>=(const Anime &other) {
  if (this->title == other.title) {
    return true;
  }

  for (int i = 0; i < std::min(this->title.length(), other.title.length());
       i++) {
    if (this->title[i] > other.title[i]) {
      return true;
    } else if (this->title[i] < other.title[i]) {
      return false;
    }
  }
  return false;
}

std::string Anime::toString(Anime anime) {
  std::string rating = std::to_string(anime.rating);
  std::string str = anime.title + "*" + rating + ",";
  return str;
}
