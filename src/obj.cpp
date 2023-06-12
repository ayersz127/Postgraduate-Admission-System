#include "..\include\obj.h"

#include <iostream>
#include <fstream>
#include <cstring>

Obj::Obj() {
  std::ifstream ifs;
  ifs.open("../data/studInfo.txt");
  studInfo.clear();
  std::string name, id, major, isF;
  int mathScore, languageScore, politicsScore, majorScore;
  while (!ifs.eof()) {
    ifs >> name >> id >> major >> isF >> mathScore >> languageScore >> politicsScore >> majorScore;
    studInfo.insert(id, StudInfo(name, id, major, isF == "true", Score(mathScore, languageScore, politicsScore, majorScore)));
  }
  ifs.close();

  ifs.open("../data/workOrder.txt");
  workOrder.clear();
  std::string order;
  while (ifs >> order) {
    workOrder.insert(order);
  }
  ifs.close();

  ifs.open("../data/annouce.txt");
  annouce.clear();
  std::string ann;
  while (std::getline(ifs, ann)) {
    annouce.insert(ann);
  }
  ifs.close();
}

Obj::~Obj() {
  std::cerr << "ard\n";
  annouce.clear();
  studInfo.clear();
  workOrder.clear();
}