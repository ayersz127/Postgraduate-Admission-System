#ifndef PPTAS_OBJ_H
#define PPTAS_OBJ_H

#include "../cur/keyList.h"
#include "info.h"

#include <iostream>

class Obj {
protected:
  KeyList<std::string, StudInfo> studInfo;
  List<std::string> workOrder;
  List<std::string> annouce;
  
public:
  Obj();
  ~Obj();
  virtual void mainPage() = 0;
  virtual bool login() = 0;
  virtual void success() = 0;
  virtual void displayInfo() = 0;
};

#endif