#include "AnimeRater.h"

AnimeRater::AnimeRater(std::string file, int dsType) {
  this->file = file;
  this->userCount = 0;
  std::fstream userList;
  userList.open(this->file);
  if (userList.is_open()) {
    std::string line;
    while (getline(userList, line)) {
      this->userCount++;
    }
    userList.close();
  }

  this->LIST_SIZE = this->userCount * 2;

  if (dsType == 0) {
    this->list = new Array<User, std::string>(this->LIST_SIZE);
  } else if (dsType == 1) {
    this->list = new LinkedList<User, std::string>();
  }

  userList.open(this->file);
  if (userList.is_open()) {
    std::string line;
    while (getline(userList, line)) {
      this->textToUser(line);
    }
    userList.close();
  }
}

void AnimeRater::textToUser(std::string text) {
  size_t pos = 0;
  std::string token;
  User *user = new User();
  while ((pos = text.find(",")) != std::string::npos) {
    token = text.substr(0, pos);
    if (token.find("*") == std::string::npos) { // if username mark
      user->setUsername(token.substr(0, std::string::npos));
    }
    if (token.find("*") != std::string::npos) {
      user->appendAnime(*(new Anime(
          token.substr(0, token.find("*")),
          std::stoi(token.substr(token.find("*") + 1, std::string::npos)))));
    }
    text.erase(0, pos + 1);
  }
  this->list->append(*user);
}

std::string AnimeRater::userToText() {
  std::string text;

  return text;
}

void AnimeRater::printUserMenu() {
  std::cout << "1. list all anime\n2. add new anime "
               "\n3. remove anime from list\n4. change username\n5. "
               "exit\n\n\n\nEnter command [1 - 5]: ";
}

void AnimeRater::welcomeScreen() {
  std::string username;
  std::cout << // clang-format off
"     _          _                  ____       _                 \n"
"    / \\   _ __ (_)_ __ ___   ___  |  _ \\ __ _| |_ ___ _ __      \n"
"   / _ \\ | '_ \\| | '_ ` _ \\ / _ \\ | |_) / _` | __/ _\\ '__|   \n"
"  / ___ \\| | | | | | | | | |  __/ |  _ < (_| | ||  __/ |         \n"   
" /_/   \\_\\_| |_|_|_| |_| |_|\\___| |_| \\_\\__,_|\\__\\___|_|  \n\n";

  // clang-format on
  std::cout << "Enter username: ";
  std::cin >> username;
  this->login(username);
}

void AnimeRater::login(std::string username) {
  User *user = this->list->search(username);
  if (user == nullptr) {
    std::cout << "\n\n\n\n\nNew user created, logged in as " << username
              << "\n\n";
    this->currentUser = new User(username);
    this->list->append(*(this->currentUser));
    this->userCount++;
  } else {
    this->currentUser = user;
    std::cout << "\n\n\n\n\nLogged in successful, logged in as " << username
              << "\n\n";
  }
}

void AnimeRater::userMenu() {
  bool running = true;
  std::string userCommand;
  while (running) {
    this->printUserMenu();
    std::cin >> userCommand;
    if (userCommand == "1") { // list all anime
      std::cout << "\n\n\n\n";
      std::string temp;
      this->currentUser->printAnimeList();
      std::cout << "\n\nPress enter to continue...\n";
      std::cin.ignore();
      std::getline(std::cin, temp);
      std::cout << "\n\n\n";
    } else if (userCommand == "2") { // add new anime
      std::string title;
      std::string rating;
      std::cout << "Enter anime title: ";
      std::cin.ignore();
      std::getline(std::cin, title);
      std::cout << "Enter anime rating: ";
      std::cin >> rating;
      this->currentUser->appendAnime(*(new Anime(title, std::stoi(rating))));
    } else if (userCommand == "3") { // remove anime from list
      this->currentUser->printAnimeList();
      std::string title;
      std::cout << "\n\n\nEnter anime title: ";
      std::cin.ignore();
      std::getline(std::cin, title);
      this->currentUser->removeAnime(title);
    } else if (userCommand == "4") { // change username
      std::string newUsername;
      std::cout << "Enter new username: ";
      std::cin >> newUsername;
      std::cout << "Username is changed from "
                << this->currentUser->getUsername() << " to " << newUsername
                << "\n";
      this->currentUser->setUsername(newUsername);
    } else if (userCommand == "5") { // exit
      this->save();
      std::cout << "Exiting program!"
                << "\n";
      running = false;
    } else { // invalid input
      std::cout << "Invalid command!\n\n\n\n\n";
    }
  }
}

void AnimeRater::save() {
  std::fstream userList;
  userList.open(this->file, std::ios::out);
  if (userList.is_open()) {
    for (int i = 0; i < this->userCount; i++) {
      userList << this->list->iterate(i).toString();
    }
    userList.close();
  }
  std::cout << "Successfully saved!\n";
}

void AnimeRater::runAnimeRater() {
  this->welcomeScreen();
  this->userMenu();
}