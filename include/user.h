#ifndef PPTAS_USER_H
#define PPTAS_USER_H

#include "../cur/keyList.h"
#include "info.h"
#include "obj.h"

#include <iostream>

class User : public Obj {
protected:
  std::string id;

public:
  User();
  ~User();
  void mainPage();
  bool login();
  void success();

  void displayInfo();
  void uploadWorkOrder();
  void displayAnnouce();
};

namespace USER {
  void mainPage();
}

#endif