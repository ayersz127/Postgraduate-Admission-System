#include "..\include\admin.h"
#include "..\include\show.h"

#include <fstream>
#include <algorithm>

zvector<StudInfo> Admin::getAccessInfo() const {
  zvector<StudInfo> res;
  auto arr = studInfo.port();
  for (int i = 0; i < arr.size(); i++) {
    auto item = arr[i];
    if (item.getInfo().isAccess(scoreLine)) {
      res.push_back(item.getInfo());
    }
  }
  std::sort(res.begin(), res.end(), [](const StudInfo& a, const StudInfo& b) {
    if (a.getScore().getTotalScore() == b.getScore().getTotalScore()) {
      return a.getId() < b.getId();
    }
    return a.getScore().getTotalScore() > b.getScore().getTotalScore();
  });
  return res;
}

Admin::Admin() : Obj() {
  std::ifstream ifs;
  ifs.open("../data/adminInfo.txt");
  adminInfo.clear();

  std::string a, b;
  while (ifs >> a >> b) {
    adminInfo.insert(a, b);
  }
  ifs.close();
}

Admin::~Admin() {
  std::ofstream ofs;
  ofs.open("../data/annouce.txt");
  auto vec = annouce.port();
  for (int i = 0; i < vec.size(); i++) {
    ofs << vec[i] << std::endl;
  }
  ofs.close();

  ofs.open("../data/studInfo.txt");
  auto vec2 = studInfo.port();
  for (int i = 0; i < vec2.size(); i++) {
    auto item = vec2[i];
    ofs << item.getInfo() << std::endl;
  }
  ofs.close();

  ofs.open("../data/workOrder.txt");
  auto vec3 = workOrder.port();
  for (int i = 0; i < vec3.size(); i++) {
    std::cerr << "add one insert\n";
    ofs << vec3[i] << std::endl;
  }
  ofs.close();
}

void Admin::setScoreLine() {
  flush(), showTitle();
  int x;
  std::cout << "请输入数学分数线:";
  std::cin >> x;
  scoreLine.setMathScore(x);
  std::cout << "请输入外语分数线:";
  std::cin >> x;
  scoreLine.setLanguageScore(x);
  std::cout << "请输入政治分数线:";
  std::cin >> x;
  scoreLine.setPoliticsScore(x);
  std::cout << "请输入专业课分数线:";
  std::cin >> x;
  scoreLine.setMajorScore(x);
  std::cout << "请输入总分分数线:";
  std::cin >> x;
  scoreLine.setTotalScore(x);
  std::cout << "设置成功" << std::endl;
  system("pause");
}

void Admin::checkScoreLine() {
  flush(), showTitle();
  if (scoreLine.getTotalScore() == 0) {
    std::cout << "未设置分数线" << std::endl;
    system("pause");
    return;
  }
  std::cout << "总分分数线:" << scoreLine.getTotalScore() << std::endl;
  std::cout << "数学分数线:" << scoreLine.getMathScore() << std::endl;
  std::cout << "外语分数线:" << scoreLine.getLanguageScore() << std::endl;
  std::cout << "政治分数线:" << scoreLine.getPoliticsScore() << std::endl;
  std::cout << "专业课分数线:" << scoreLine.getMajorScore() << std::endl;
  system("pause");
}

void Admin::importInfo() {
  flush(), showTitle();
  std::cout << "请输入要导入的考生信息文件的路径（请输入绝对路径，例如 D:/data/data.txt）:";
  std::string path;
  std::cin >> path;

  std::ifstream ifs;
  ifs.open(path);
  if (!ifs.is_open()) {
    std::cout << "文件打开失败" << std::endl;
    system("pause");
    return;
  }
  std::cout << "文件打开成功" << std::endl;
  std::string name, id, major, isF;
  int mathScore, languageScore, politicsScore, majorScore;
  while (ifs >> name >> id >> major >> isF >> mathScore >> languageScore >> politicsScore >> majorScore) {
    studInfo.insert(id, StudInfo(name, id, major, isF == "true", Score(mathScore, languageScore, politicsScore, majorScore)));
  }
  ifs.close();
  std::cout << "导入成功" << std::endl;
  system("pause");
}

void Admin::updateInfo() {
  flush(), showTitle();
  std::cout << "请输入要修改的考生的准考证号:";
  std::string id;
  std::cin >> id;
  if (studInfo.find(id) == nullptr) {
    std::cout << "不存在该准考证号的考生" << std::endl;
    system("pause");
    return;
  }
  
  auto p = studInfo.find(id)->getData().getInfo();
  
  int opt;
  std::cout << "是否需要修改考生的姓名（1/0）:";
  std::cin >> opt;
  if (opt == 1) {
    std::cout << "请输入考生的新姓名:";
    std::string name;
    std::cin >> name;
    p.setName(name);
    studInfo.update(id, p);
  }
  
  std::cout << "是否需要修改考生的专业（1/0）:";
  std::cin >> opt;
  if (opt == 1) {
    std::cout << "请输入考生的新专业:";
    std::string major;
    std::cin >> major;
    p.setMajor(major);
    studInfo.update(id, p);
  }
  
  std::cout << "是否需要修改考生的是否为应届生（1/0）:";
  std::cin >> opt;
  if (opt == 1) {
    std::cout << "请输入考生的新是否为应届生:";
    std::string isF;
    std::cin >> isF;
    p.setIsF(isF == "true");
    studInfo.update(id, p);
  }
  
  std::cout << "是否需要修改考生的数学成绩（1/0）:";
  std::cin >> opt;
  if (opt == 1) {
    std::cout << "请输入考生的新数学成绩:";
    int mathScore;
    std::cin >> mathScore;
    try {
      p.setScore("math", mathScore);
      studInfo.update(id, p);
    } catch (const char *e) {
      std::cout << e << std::endl;
      system("pause");
      return;
    }
  }
  
  std::cout << "是否需要修改考生的外语成绩（1/0）:";
  std::cin >> opt;
  if (opt == 1) {
    std::cout << "请输入考生的新外语成绩:";
    int languageScore;
    std::cin >> languageScore;
    try {
      p.setScore("language", languageScore);
      studInfo.update(id, p);
    } catch (const char *e) {
      std::cout << e << std::endl;
      system("pause");
      return;
    }
  }

  std::cout << "是否需要修改考生的政治成绩（1/0）:";
  std::cin >> opt;
  if (opt == 1) {
    std::cout << "请输入考生的新政治成绩:";
    int politicsScore;
    std::cin >> politicsScore;
    try {
      p.setScore("politics", politicsScore);
      studInfo.update(id, p);
    } catch (const char *e) {
      std::cout << e << std::endl;
      system("pause");
      return;
    }
  }

  std::cout << "是否需要修改考生的专业课成绩（1/0）:";
  std::cin >> opt;
  if (opt == 1) {
    std::cout << "请输入考生的新专业课成绩:";
    int majorScore;
    std::cin >> majorScore;
    try {
      p.setScore("major", majorScore);
      studInfo.update(id, p);
    } catch (const char *e) {
      std::cout << e << std::endl;
      system("pause");
      return;
    }
  }

  std::cout << "修改成功" << std::endl;
  system("pause");
}

void Admin::deleteInfo() {
  flush(), showTitle();
  std::cout << "请输入要删除的考生的准考证号:";
  std::string id;
  std::cin >> id;
  if (studInfo.find(id) == nullptr) {
    std::cout << "不存在该准考证号的考生" << std::endl;
    system("pause");
    return;
  }
  studInfo.erase(id);
  std::cout << "删除成功" << std::endl;
  system("pause");
}

void Admin::insertInfo() {
  flush(), showTitle();
  std::cout << "请输入要添加的考生的姓名:";
  std::string name;
  std::cin >> name;
  std::cout << "请输入要添加的考生的准考证号:";
  std::string id;
  std::cin >> id;
  if (studInfo.find(id) != nullptr) {
    std::cout << "已存在该准考证号的考生" << std::endl;
    return;
  }
  std::cout << "请输入要添加的考生的专业:";
  std::string major;
  std::cin >> major;
  std::cout << "请输入要添加的考生的是否为应届生:";
  std::string isF;
  std::cin >> isF;

  Score p;
  std::cout << "请输入要添加的考生的数学成绩:";
  int mathScore;
  std::cin >> mathScore;
  try {
    p.setMathScore(mathScore);
  } catch (const char *e) {
    std::cout << e << std::endl;
    system("pause");
    return;
  }

  std::cout << "请输入要添加的考生的外语成绩:";
  int languageScore;
  std::cin >> languageScore;
  try {
    p.setLanguageScore(languageScore);
  } catch (const char *e) {
    std::cout << e << std::endl;
    system("pause");
    return;
  }
  std::cout << "请输入要添加的考生的政治成绩:";
  int politicsScore;
  std::cin >> politicsScore;
  try {
    p.setPoliticsScore(politicsScore);
  } catch (const char *e) {
    std::cout << e << std::endl;
    system("pause");
    return;
  }
  std::cout << "请输入要添加的考生的专业课成绩:";
  int majorScore;
  std::cin >> majorScore;
  try {
    p.setMajorScore(majorScore);
  } catch (const char *e) {
    std::cout << e << std::endl;
    system("pause");
    return;
  }
  studInfo.insert(id, StudInfo(name, id, major, isF == "true", p));
  std::cout << "添加成功" << std::endl;
  system("pause");
}

void Admin::displayInfo() {
  flush(), showTitle();
  std::cout << "请输入要查询的考生信息的准考证号:";
  std::string id;
  std::cin >> id;
  if (studInfo.find(id) == nullptr) {
    std::cout << "不存在该准考证号的考生" << std::endl;
    system("pause");
    return;
  }
  auto p = *studInfo.find(id);
  std::cout << "该考生的信息为：" << std::endl;
  std::cout << p.getData().getInfo() << " " << p.getData().getInfo().getScore().getTotalScore() << std::endl;
  system("pause");
}

void Admin::showAccessInfo() {
  flush(), showTitle();
  if (scoreLine.getTotalScore() == 0) {
    std::cout << "请先设置录取分数线" << std::endl;
    system("pause");
    return;
  }
  std::cout << "录取名单" << std::endl;
  std::cout << "录取分数线：" << scoreLine.getTotalScore() << std::endl;
  auto arr = getAccessInfo();
  std::cout << "录取人数：" << arr.size() << std::endl;
  std::cout << "录取名单：" << std::endl;
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " " << arr[i].getScore().getTotalScore() << std::endl;
  }
  system("pause");
  
}

void Admin::exportAccessInfo() {
  flush(), showTitle();
  if (scoreLine.getTotalScore() == 0) {
    std::cout << "请先设置录取分数线" << std::endl;
    system("pause");
    return;
  }
  std::cout << "正在导出数据..." << std::endl;
  std::ofstream ofs("accessList.txt", std::ios::out);
  ofs << "录取名单" << std::endl;
  ofs << "录取分数线：" << scoreLine.getTotalScore() << std::endl;
  auto arr = getAccessInfo();
  ofs << "录取人数：" << arr.size() << std::endl;
  ofs << "录取名单：" << std::endl;
  for (int i = 0; i < arr.size(); i++) {
    ofs << arr[i] << " " << arr[i].getScore().getTotalScore() << std::endl;
  }
  std::cout << "导出成功" << std::endl;
  ofs.close();
  system("pause");
}

void Admin::solveWorkOrder() {
  flush(), showTitle();

  if (workOrder.empty()) {
    std::cout << "暂无申请查分工单" << std::endl;
  } else {
    while (true) {
      flush(), showTitle();
      std::cout << "有以下考号的学生需要查分：" << std::endl;
      std::cout << "==============" << std::endl;
      auto ver = workOrder.port();
      for (int i = 0; i < ver.size(); i++) {
        std::cout << ver[i] << std::endl;
      }
      std::cout << "==============" << std::endl;
      std::cout << "请输入要处理的考号(输入-1退出):";
      std::string num;
      std::cin >> num;
      if (num == "-1") {
        break;
      }
      if (workOrder.find(num) == nullptr) {
        std::cout << "请输入正确的考号" << std::endl;
        system("pause");
        continue;
      }
      if (num == "-1") {
        break;
      }
      std::cout << "如果成绩有误请输入1，否则请输入0:";
      int flag;
      std::cin >> flag;
      if (flag == 1) {
        Score sc;
        int mathScore, languageScore, politicsScore, majorScore;
        std::cout << "请输入该考生的数学成绩:";
        std::cin >> mathScore;
        try {
          sc.setMathScore(mathScore);
        } catch (const char *e) {
          std::cout << e << std::endl;
          system("pause");
          continue;
        }
        std::cout << "请输入该考生的外语成绩:";
        std::cin >> languageScore;
        try {
          sc.setLanguageScore(languageScore);
        } catch (const char *e) {
          std::cout << e << std::endl;
          system("pause");
          continue;
        }
        std::cout << "请输入该考生的政治成绩:";
        std::cin >> politicsScore;
        try {
          sc.setPoliticsScore(politicsScore);
        } catch (const char *e) {
          std::cout << e << std::endl;
          system("pause");
          continue;
        }
        std::cout << "请输入该考生的专业课成绩:";
        std::cin >> majorScore;
        try {
          sc.setMajorScore(majorScore);
        } catch (const char *e) {
          std::cout << e << std::endl;
          system("pause");
          continue;
        }
        auto p = *studInfo.find(num);
        auto name = p.getData().getInfo().getName();
        auto id = p.getData().getInfo().getId();
        auto major = p.getData().getInfo().getMajor();
        auto isF = p.getData().getInfo().getIsF();

        studInfo.update(id, StudInfo(name, id, major, isF, sc));
        
        workOrder.erase(num);
        annouce.insert(num + " true");
      } else {
        workOrder.erase(num);
        annouce.insert(num + " false");
      }
      std::cout << "处理成功" << std::endl;
      system("pause");
    }
  }
  system("pause");
}

bool Admin::login() {
  flush(), showTitle();
  std::cout << "请输入登录管理员的用户名:";
  std::string userName;
  std::cin >> userName;

  if (adminInfo.find(userName) == nullptr) {
    std::cout << "用户名不存在" << std::endl;
    system("pause");
    return false;
  }
  std::string password;
  std::cout << "请输入登录管理员的密码:";
  std::cin >> password;
  if (adminInfo.getInfo(userName) != password) {
    std::cout << "密码错误" << std::endl;
    system("pause");
    return false;
  }

  std::cout << "登录成功" << std::endl;
  system("pause");
  return true;
}

void Admin::success() {
  while (true) {
    flush();
    showTitle();
    std::cout << "已成功进入研究生初试成绩管理系统管理员界面" << std::endl;
    showAdmin();
    int x;
    std::cin >> x;
    switch (x) {
      case 1 : setScoreLine(); break;
      case 2 : checkScoreLine(); break;
      case 3 : importInfo(); break;
      case 4 : updateInfo(); break;
      case 5 : deleteInfo(); break;
      case 6 : insertInfo(); break;
      case 7 : displayInfo(); break;
      case 8 : showAccessInfo(); break;
      case 9 : exportAccessInfo(); break;
      case 10 : solveWorkOrder(); break;
      default : return;
    }
  }
}

void Admin::mainPage() {
  flush();
  showTitle();
  std::cout << "欢迎进入研究生初试成绩管理系统管理员登录界面" << std::endl;

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

void ADMIN::mainPage() {
  Admin admin;
  admin.mainPage();
}