#include <iostream>

#include "..\include\show.h"

#include "..\include\admin.h"
#include "..\include\user.h"

int main() {
  system("chcp 65001");

  while (true) {
    flush();
    showTitle();
    showChoose();
    int pageType;
    std::cin >> pageType;

    switch (pageType) {
      case 1 : ADMIN::mainPage(); break;
      case 2 : USER::mainPage(); break;
      case 3 : return 0;
      default : {
        std::cout << "输入格式有误，请重新输入" << std::endl;
      }
    }
  }
  system("pause");
  return 0;
}