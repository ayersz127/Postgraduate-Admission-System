#ifndef PPTAS_ADMIN_H
#define PPTAS_ADMIN_H

#include "../cur/keyList.h"
#include "info.h"
#include "obj.h"

#include <iostream>

class Admin : public Obj {
private:
  KeyList<std::string, std::string> adminInfo;
  Score scoreLine;
  zvector<StudInfo> getAccessInfo() const;
    
public:
  Admin();
  ~Admin();
  
  void setScoreLine(); // 设置分数线
  void checkScoreLine(); // 查看分数线
  void importInfo(); // 导入信息
  void updateInfo(); // 更新信息
  void deleteInfo(); // 删除信息
  void insertInfo(); // 插入信息
  void displayInfo(); // 查找信息
  void showAccessInfo(); // 显示信息
  void exportAccessInfo(); // 导出信息

  void solveWorkOrder(); // 处理申诉查分工单

  bool login();
  void success();
  void mainPage();
};

namespace ADMIN {
  void mainPage();
}
#endif