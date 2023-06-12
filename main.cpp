
#include <iostream>
#include <iomanip>
#include <ctime>
#include <synchapi.h>

void timer(int min, int sec) {
  while (true) {
    std::time_t t = std::time(nullptr);
    std::tm *local = std::localtime(&t);
    if (min == 0 && sec == 0)
      break;
    if (sec == 0) {
      sec = 60;
      min--;
    }
    std::cout << "Current time: " << std::put_time(local, "%M:%S")
              << "  Time left: " << min << ":" << sec << std::endl;
    Sleep(1000);
    sec--;
  }
}

int main() {
  int sec = 0;
  int min = 0;
  struct std::tm when{};
  std::cout << "Please, enter the time <mm:ss>: ";
  std::cin >> std::get_time(&when, "%M:%S");
  if (std::cin.fail()) std::cout << "Error reading time\n";
  else {
    sec = when.tm_sec;
    min = when.tm_min;
    int secAll = sec + min * 60;
    std::cout << "The time entered is: ";
    std::cout << when.tm_min << " minutes and " << when.tm_sec << " seconds\n";
    std::time_t start = std::time(nullptr);
    std::time_t finish = start + secAll;
    std::tm *local = std::localtime(&start);
    std::cout << "Time start: " << asctime(local);
    std::tm *local_future = std::localtime(&finish);
    std::cout << "Time finish: " << asctime(local_future) << std::endl;
    timer(min, sec);
    for (int i = 0; i < 3; ++i) {
      std::cout<<"DING!"<<" ";
    }
  }

  return 0;
}