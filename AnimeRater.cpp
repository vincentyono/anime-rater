#include "AnimeRater.h"

AnimeRater::AnimeRater(std::string file, int dsType) {
  if (dsType == 0) {
    this->list = new Array<User, std::string>();
  } else if (dsType == 1) {
    this->list = new LinkedList<User, std::string>();
  }

  std::fstream userList;

  userList.open(file);
  if (userList.is_open()) {
    std::string line;
    while (getline(userList, line)) {
      this->textToUser(line);
    }
  }
}

void AnimeRater::textToUser(std::string text) {
  size_t pos = 0;
  std::string token;
  User *user = new User();
  while ((pos = text.find(",")) != std::string::npos) {
    token = text.substr(0, pos);
    if (token.find(":") == std::string::npos) { // if username mark
      user->setUsername(token.substr(0, std::string::npos));
    }
    if (token.find(":") != std::string::npos) {
      user->appendAnime(*(new Anime(
          token.substr(0, token.find(":")),
          std::stoi(token.substr(token.find(":") + 1, std::string::npos)))));
    }
    text.erase(0, pos + 1);
  }
  this->list->append(*user);
}

void AnimeRater::printMainMenu() {
  std::cout << "1. login \n2. exit \n\n"
               "Enter command [1 - 2]: ";
}

void AnimeRater::printUserMenu() {
  std::cout << "1. status \n2. list all anime \n3. add new anime \n4. "
               "change anime rating \n5. remove anime \n6. exit \n\n"
               "Enter command [1 - 6]: ";
}

void AnimeRater::runMainMenu() {
  bool running = true;
  std::string userInput;
  std::string username;
  while (running) {
    this->printMainMenu();
    std::cin >> userInput;
    if (userInput == "1") { // login
      std::cout << "Enter username: ";
      std::cin >> username;
      this->login(username);
      running = false;
    } else if (userInput == "2") { // exit
      running = false;
    }
  }
}

void AnimeRater::runUserMenu() {
  bool running = true;
  std::string userInput;
  while (running) {
    this->printUserMenu();
    std::cin >> userInput;
    if (userInput == "1") { // status
      std::cout << "currently logged in as " << this->currentUser->getUsername()
                << "\n";

    } else if (userInput == "2") { // list all anime
      this->currentUser->printAnimeList();

    } else if (userInput == "3") { // add new anime
      std::string animeTitle;
      std::string rating;
      std::cout << "Enter anime title: ";
      std::cin >> animeTitle;
      std::cout << "Enter rating [1 - 5]: ";
      std::cin >> rating;

      this->currentUser->appendAnime(
          *(new Anime(animeTitle, std::stoi(rating))));

    } else if (userInput == "5") { // remove anime
      std::string animeTitle;
      this->currentUser->printAnimeList();
      std::cout << "Enter anime title: ";
      std::cin >> animeTitle;
      this->currentUser->removeAnime(animeTitle);

    } else if (userInput == "6") { // exit
      running = false;
    }
  }
}

void AnimeRater::login(std::string username) {
  User *user = this->list->search(username);
  std::cout << user << std::endl;
  if (user != nullptr) {
    this->currentUser = user;
    std::cout << "log in as " << this->currentUser->getUsername() << "\n";
  } else {
    std::cout << "User not found!\n";
    std::cout << "Create new user\n";
    this->currentUser = new User(username);
  }
}

void AnimeRater::runAnimeRater() {
  this->runMainMenu();
  this->runUserMenu();
}