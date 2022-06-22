#include "AnimeRater.h"
enum DSType { DSArray, DSLinkedList };

#include <chrono>
#include <iostream>
#include <thread>
int main() {
  DSType Array = DSArray;
  DSType LinkedList = DSLinkedList;
  AnimeRater("user_list.csv", DSArray).runAnimeRater();

  // SpeedTest

  // AnimeRater *ar = new AnimeRater("user_list.csv", DSLinkedList);
  // std::fstream file;
  // file.open("speedtest_linkedlist.txt");
  // if (file.is_open()) {
  //   // searching front
  //   std::string username = "bbagnall1w";
  //   auto start1 = std::chrono::system_clock::now();
  //   ar->searchSpeedTest(username);
  //   auto end1 = std::chrono::system_clock::now();
  //   auto duration1 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
  //   file << "searching front (" << username << ") " << duration1.count()
  //        << " nanoseconds" << std::endl;

  //   username = "aferbrache39";
  //   auto start2 = std::chrono::system_clock::now();
  //   ar->searchSpeedTest(username);
  //   auto end2 = std::chrono::system_clock::now();
  //   auto duration2 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
  //   file << "searching front (" << username << ") " << duration2.count()
  //        << " nanoseconds" << std::endl;

  //   username = "awoodrow6g";
  //   auto start3 = std::chrono::system_clock::now();
  //   ar->searchSpeedTest(username);
  //   auto end3 = std::chrono::system_clock::now();
  //   auto duration3 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3);
  //   file << "searching front (" << username << ") " << duration3.count()
  //        << " nanoseconds" << std::endl;

  //   // search middle
  //   username = "jtwinejj";
  //   auto start4 = std::chrono::system_clock::now();
  //   ar->searchSpeedTest(username);
  //   auto end4 = std::chrono::system_clock::now();
  //   auto duration4 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - start4);
  //   file << "searching middle (" << username << ") " << duration4.count()
  //        << " nanoseconds" << std::endl;

  //   username = "lmunn3s";
  //   auto start5 = std::chrono::system_clock::now();
  //   ar->searchSpeedTest(username);
  //   auto end5 = std::chrono::system_clock::now();
  //   auto duration5 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end5 - start5);
  //   file << "searching middle (" << username << ") " << duration5.count()
  //        << " nanoseconds" << std::endl;

  //   username = "mlongfutjo";
  //   auto start6 = std::chrono::system_clock::now();
  //   ar->searchSpeedTest(username);
  //   auto end6 = std::chrono::system_clock::now();
  //   auto duration6 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end6 - start6);
  //   file << "searching middle (" << username << ") " << duration6.count()
  //        << " nanoseconds" << std::endl;

  //   // search back
  //   username = "jtwinejj";
  //   auto start7 = std::chrono::system_clock::now();
  //   ar->searchSpeedTest(username);
  //   auto end7 = std::chrono::system_clock::now();
  //   auto duration7 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end7 - start7);
  //   file << "searching back (" << username << ") " << duration7.count()
  //        << " nanoseconds" << std::endl;

  //   username = "lmunn3s";
  //   auto start8 = std::chrono::system_clock::now();
  //   ar->searchSpeedTest(username);
  //   auto end8 = std::chrono::system_clock::now();
  //   auto duration8 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end8 - start8);
  //   file << "searching back (" << username << ") " << duration8.count()
  //        << " nanoseconds" << std::endl;

  //   username = "mlongfutjo";
  //   auto start9 = std::chrono::system_clock::now();
  //   ar->searchSpeedTest(username);
  //   auto end9 = std::chrono::system_clock::now();
  //   auto duration9 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end9 - start9);
  //   file << "searching back (" << username << ") " << duration5.count()
  //        << " nanoseconds" << std::endl;

  //   // adding front
  //   username = "claire80";
  //   auto start10 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end10 = std::chrono::system_clock::now();
  //   auto duration10 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end10 -
  //       start10);
  //   file << "adding front (" << username << ") " << duration10.count()
  //        << " nanoseconds" << std::endl;

  //   username = "apple30";
  //   auto start11 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end11 = std::chrono::system_clock::now();
  //   auto duration11 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end11 -
  //       start11);
  //   file << "adding front (" << username << ") " << duration11.count()
  //        << " nanoseconds" << std::endl;

  //   username = "cat88";
  //   auto start12 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end12 = std::chrono::system_clock::now();
  //   auto duration12 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end12 -
  //       start12);
  //   file << "adding front (" << username << ") " << duration12.count()
  //        << " nanoseconds" << std::endl;

  //   // adding middle
  //   username = "jade202";
  //   auto start13 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end13 = std::chrono::system_clock::now();
  //   auto duration13 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end13 -
  //       start13);
  //   file << "adding middle (" << username << ") " << duration13.count()
  //        << " nanoseconds" << std::endl;

  //   username = "markov90";
  //   auto start14 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end14 = std::chrono::system_clock::now();
  //   auto duration14 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end14 -
  //       start14);
  //   file << "adding middle (" << username << ") " << duration14.count()
  //        << " nanoseconds" << std::endl;

  //   username = "mini60";
  //   auto start15 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end15 = std::chrono::system_clock::now();
  //   auto duration15 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end15 -
  //       start15);
  //   file << "adding middle (" << username << ") " << duration15.count()
  //        << " nanoseconds" << std::endl;

  //   // adding back
  //   username = "zeke12";
  //   auto start16 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end16 = std::chrono::system_clock::now();
  //   auto duration16 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end16 -
  //       start16);
  //   file << "adding back (" << username << ") " << duration16.count()
  //        << " nanoseconds" << std::endl;

  //   username = "yoyoman12";
  //   auto start17 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end17 = std::chrono::system_clock::now();
  //   auto duration17 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end17 -
  //       start17);
  //   file << "adding back (" << username << ") " << duration17.count()
  //        << " nanoseconds" << std::endl;

  //   username = "rabbit8";
  //   auto start18 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end18 = std::chrono::system_clock::now();
  //   auto duration18 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end18 -
  //       start18);
  //   file << "adding back (" << username << ") " << duration18.count()
  //        << " nanoseconds" << std::endl;

  //   // removing front
  //   username = "claire80";
  //   auto start19 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end19 = std::chrono::system_clock::now();
  //   auto duration19 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end19 -
  //       start19);
  //   file << "removing front (" << username << ") " << duration19.count()
  //        << " nanoseconds" << std::endl;

  //   username = "apple30";
  //   auto start20 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end20 = std::chrono::system_clock::now();
  //   auto duration20 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end20 -
  //       start20);
  //   file << "removing front (" << username << ") " << duration20.count()
  //        << " nanoseconds" << std::endl;

  //   username = "cat88";
  //   auto start21 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end21 = std::chrono::system_clock::now();
  //   auto duration21 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end21 -
  //       start21);
  //   file << "removing front (" << username << ") " << duration21.count()
  //        << " nanoseconds" << std::endl;

  //   // removing middle
  //   username = "jade202";
  //   auto start22 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end22 = std::chrono::system_clock::now();
  //   auto duration22 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end22 -
  //       start22);
  //   file << "removing middle (" << username << ") " << duration22.count()
  //        << " nanoseconds" << std::endl;

  //   username = "markov90";
  //   auto start23 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end23 = std::chrono::system_clock::now();
  //   auto duration23 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end23 -
  //       start23);
  //   file << "removing middle (" << username << ") " << duration23.count()
  //        << " nanoseconds" << std::endl;

  //   username = "mini60";
  //   auto start24 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end24 = std::chrono::system_clock::now();
  //   auto duration24 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end24 -
  //       start24);
  //   file << "removing middle (" << username << ") " << duration24.count()
  //        << " nanoseconds" << std::endl;

  //   // removing back
  //   username = "zeke12";
  //   auto start25 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end25 = std::chrono::system_clock::now();
  //   auto duration25 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end25 -
  //       start25);
  //   file << "removing back (" << username << ") " << duration25.count()
  //        << " nanoseconds" << std::endl;

  //   username = "yoyoman12";
  //   auto start26 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end26 = std::chrono::system_clock::now();
  //   auto duration26 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end26 -
  //       start26);
  //   file << "removing back (" << username << ") " << duration26.count()
  //        << " nanoseconds" << std::endl;

  //   username = "rabbit8";
  //   auto start27 = std::chrono::system_clock::now();
  //   ar->addUserSpeedTest(*(new User(username)));
  //   auto end27 = std::chrono::system_clock::now();
  //   auto duration27 =
  //       std::chrono::duration_cast<std::chrono::nanoseconds>(end27 -
  //       start27);
  //   file << "removing back (" << username << ") " << duration27.count()
  //        << " nanoseconds" << std::endl;
  //   file.close();
  // }
  return 0;
}