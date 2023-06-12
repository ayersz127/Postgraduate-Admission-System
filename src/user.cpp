#include "..\include\user.h"

#include <iostream>
#include <fstream>

#include "..\include\show.h"

User::User() : Obj() {}

User::~User() {
  std::ofstream ofs;
  ofs.open("../data/workOrder.txt");
  auto vec = workOrder.port();
  for (int i = 0; i < vec.size(); i++) {
    ofs << vec[i] << std::endl;
  }
  ofs.close();

  studInfo.clear();
  workOrder.clear();
  annouce.clear();
}

void User::displayInfo() {
  flush(), showTitle();
  std::cout << "你的考号为：" << id << std::endl;
  auto p = studInfo.find(id)->getData().getInfo();
  std::cout << "你的姓名为：" << p.getName() << std::endl;
  std::cout << "你的专业为：" << p.getMajor() << std::endl;
  std::cout << "你的是否为应届生：" << (p.getIsF() ? "是" : "否") << std::endl;
  std::cout << "你的数学成绩为：" << p.getScore().getMathScore() << std::endl;
  std::cout << "你的外语成绩为：" << p.getScore().getLanguageScore() << std::endl;
  std::cout << "你的政治成绩为：" << p.getScore().getPoliticsScore() << std::endl;
  std::cout << "你的专业成绩为：" << p.getScore().getMajorScore()<< std::endl;
  std::cout << "你的总成绩为：" << p.getScore().getTotalScore() << std::endl;
  system("pause");
}

void User::uploadWorkOrder() {
  flush(), showTitle();
  std::cout << "你是否要提交分数审核工单？(1/0)" << std::endl;
  int x;
  std::cin >> x;
  if (x == 1) {
    workOrder.insert(id);
    std::cout << "提交成功" << std::endl;
  } else {
    std::cout << "取消提交" << std::endl;
  }
  system("pause");
}

void User::displayAnnouce() {
  flush(), showTitle();
  std::cout << "你的审核申请结果如下：" << std::endl;
  
  bool flag1 = false, flag2 = false;
  auto vec = annouce.port();
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i].find(id) != std::string::npos) {
      flag1 = true;
      if (vec[i].find("true") != std::string::npos) {
        flag2 = true;
      } else {
        flag2 = false;
      }
    }
  }
  if (flag1) {
    if (flag2) {
      std::cout << "你的审核申请已通过，请去查询页面查看分数" << std::endl;
    } else {
      std::cout << "你的分数没有错误" << std::endl;
    }
  } else {
    std::cout << "你的审核申请正在审核中或未提交成功" << std::endl;
  }
  system("pause");
}

bool User::login() {
  flush(), showTitle();

  std::cout << "请输入您的考号：";
  std::cin >> id;
  if (studInfo.find(id) == nullptr) {
    std::cout << "考号不存在" << std::endl;
    system("pause");
    return false;
  }
  std::cout << "登录成功" << std::endl;
  system("pause");
  return true;
}

void User::success() {
  while (true) {
    flush();
    showTitle();
    std::cout << "已成功进入研究生初试成绩管理系统考生用户界面" << std::endl;
    showUser();
    int x;
    std::cin >> x;
    switch (x) {
      case 1 : displayInfo(); break;
      case 2 : uploadWorkOrder(); break;
      case 3 : displayAnnouce(); break;
      default : return;
    }
  }

  system("pause");
}

void User::mainPage() {
  flush(), showTitle();
  std::cout << "欢迎进入研究生初试成绩管理系统考生用户登录界面" << std::endl;

  while (!login()) {
    std::cout << "请重新登录（如果需要退出请键入1，否则请键入2）" << std::endl;
    int x;
    std::cin >> x;
    if (x == 1) {
      return;
    }
  }
  success();
  system("pause");
}

void USER::mainPage() {
  User user;
  user.mainPage();
}